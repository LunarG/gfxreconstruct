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
** This file is generated from dx12_enum_to_string_body_generator.py.
**
*/

#if defined(D3D12_SUPPORT) || defined(ENABLE_OPENXR_SUPPORT)

#include "generated_dx12_enum_to_string.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

std::string ToString(const DXGI_RESIDENCY value)
{
    const char* ret = "Unhandled DXGI_RESIDENCY";
    switch (value) {
        case DXGI_RESIDENCY_FULLY_RESIDENT: ret = "DXGI_RESIDENCY_FULLY_RESIDENT"; break;
        case DXGI_RESIDENCY_RESIDENT_IN_SHARED_MEMORY: ret = "DXGI_RESIDENCY_RESIDENT_IN_SHARED_MEMORY"; break;
        case DXGI_RESIDENCY_EVICTED_TO_DISK: ret = "DXGI_RESIDENCY_EVICTED_TO_DISK"; break;
    }
    return ret;
}

std::string ToString(const DXGI_SWAP_EFFECT value)
{
    const char* ret = "Unhandled DXGI_SWAP_EFFECT";
    switch (value) {
        case DXGI_SWAP_EFFECT_DISCARD: ret = "DXGI_SWAP_EFFECT_DISCARD"; break;
        case DXGI_SWAP_EFFECT_SEQUENTIAL: ret = "DXGI_SWAP_EFFECT_SEQUENTIAL"; break;
        case DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL: ret = "DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL"; break;
        case DXGI_SWAP_EFFECT_FLIP_DISCARD: ret = "DXGI_SWAP_EFFECT_FLIP_DISCARD"; break;
    }
    return ret;
}

std::string ToString(const DXGI_SWAP_CHAIN_FLAG value)
{
    const char* ret = "Unhandled DXGI_SWAP_CHAIN_FLAG";
    switch (value) {
        case DXGI_SWAP_CHAIN_FLAG_NONPREROTATED: ret = "DXGI_SWAP_CHAIN_FLAG_NONPREROTATED"; break;
        case DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH: ret = "DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH"; break;
        case DXGI_SWAP_CHAIN_FLAG_GDI_COMPATIBLE: ret = "DXGI_SWAP_CHAIN_FLAG_GDI_COMPATIBLE"; break;
        case DXGI_SWAP_CHAIN_FLAG_RESTRICTED_CONTENT: ret = "DXGI_SWAP_CHAIN_FLAG_RESTRICTED_CONTENT"; break;
        case DXGI_SWAP_CHAIN_FLAG_RESTRICT_SHARED_RESOURCE_DRIVER: ret = "DXGI_SWAP_CHAIN_FLAG_RESTRICT_SHARED_RESOURCE_DRIVER"; break;
        case DXGI_SWAP_CHAIN_FLAG_DISPLAY_ONLY: ret = "DXGI_SWAP_CHAIN_FLAG_DISPLAY_ONLY"; break;
        case DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT: ret = "DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT"; break;
        case DXGI_SWAP_CHAIN_FLAG_FOREGROUND_LAYER: ret = "DXGI_SWAP_CHAIN_FLAG_FOREGROUND_LAYER"; break;
        case DXGI_SWAP_CHAIN_FLAG_FULLSCREEN_VIDEO: ret = "DXGI_SWAP_CHAIN_FLAG_FULLSCREEN_VIDEO"; break;
        case DXGI_SWAP_CHAIN_FLAG_YUV_VIDEO: ret = "DXGI_SWAP_CHAIN_FLAG_YUV_VIDEO"; break;
        case DXGI_SWAP_CHAIN_FLAG_HW_PROTECTED: ret = "DXGI_SWAP_CHAIN_FLAG_HW_PROTECTED"; break;
        case DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING: ret = "DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING"; break;
        case DXGI_SWAP_CHAIN_FLAG_RESTRICTED_TO_ALL_HOLOGRAPHIC_DISPLAYS: ret = "DXGI_SWAP_CHAIN_FLAG_RESTRICTED_TO_ALL_HOLOGRAPHIC_DISPLAYS"; break;
    }
    return ret;
}

std::string ToString(const DXGI_ADAPTER_FLAG value)
{
    const char* ret = "Unhandled DXGI_ADAPTER_FLAG";
    switch (value) {
        case DXGI_ADAPTER_FLAG_NONE: ret = "DXGI_ADAPTER_FLAG_NONE"; break;
        case DXGI_ADAPTER_FLAG_REMOTE: ret = "DXGI_ADAPTER_FLAG_REMOTE"; break;
        case DXGI_ADAPTER_FLAG_SOFTWARE: ret = "DXGI_ADAPTER_FLAG_SOFTWARE"; break;
        case DXGI_ADAPTER_FLAG_FORCE_DWORD: ret = "DXGI_ADAPTER_FLAG_FORCE_DWORD"; break;
    }
    return ret;
}

std::string ToString(const DXGI_OUTDUPL_POINTER_SHAPE_TYPE value)
{
    const char* ret = "Unhandled DXGI_OUTDUPL_POINTER_SHAPE_TYPE";
    switch (value) {
        case DXGI_OUTDUPL_POINTER_SHAPE_TYPE_MONOCHROME: ret = "DXGI_OUTDUPL_POINTER_SHAPE_TYPE_MONOCHROME"; break;
        case DXGI_OUTDUPL_POINTER_SHAPE_TYPE_COLOR: ret = "DXGI_OUTDUPL_POINTER_SHAPE_TYPE_COLOR"; break;
        case DXGI_OUTDUPL_POINTER_SHAPE_TYPE_MASKED_COLOR: ret = "DXGI_OUTDUPL_POINTER_SHAPE_TYPE_MASKED_COLOR"; break;
    }
    return ret;
}

std::string ToString(const DXGI_ALPHA_MODE value)
{
    const char* ret = "Unhandled DXGI_ALPHA_MODE";
    switch (value) {
        case DXGI_ALPHA_MODE_UNSPECIFIED: ret = "DXGI_ALPHA_MODE_UNSPECIFIED"; break;
        case DXGI_ALPHA_MODE_PREMULTIPLIED: ret = "DXGI_ALPHA_MODE_PREMULTIPLIED"; break;
        case DXGI_ALPHA_MODE_STRAIGHT: ret = "DXGI_ALPHA_MODE_STRAIGHT"; break;
        case DXGI_ALPHA_MODE_IGNORE: ret = "DXGI_ALPHA_MODE_IGNORE"; break;
        case DXGI_ALPHA_MODE_FORCE_DWORD: ret = "DXGI_ALPHA_MODE_FORCE_DWORD"; break;
    }
    return ret;
}

std::string ToString(const DXGI_OFFER_RESOURCE_PRIORITY value)
{
    const char* ret = "Unhandled DXGI_OFFER_RESOURCE_PRIORITY";
    switch (value) {
        case DXGI_OFFER_RESOURCE_PRIORITY_LOW: ret = "DXGI_OFFER_RESOURCE_PRIORITY_LOW"; break;
        case DXGI_OFFER_RESOURCE_PRIORITY_NORMAL: ret = "DXGI_OFFER_RESOURCE_PRIORITY_NORMAL"; break;
        case DXGI_OFFER_RESOURCE_PRIORITY_HIGH: ret = "DXGI_OFFER_RESOURCE_PRIORITY_HIGH"; break;
    }
    return ret;
}

std::string ToString(const DXGI_SCALING value)
{
    const char* ret = "Unhandled DXGI_SCALING";
    switch (value) {
        case DXGI_SCALING_STRETCH: ret = "DXGI_SCALING_STRETCH"; break;
        case DXGI_SCALING_NONE: ret = "DXGI_SCALING_NONE"; break;
        case DXGI_SCALING_ASPECT_RATIO_STRETCH: ret = "DXGI_SCALING_ASPECT_RATIO_STRETCH"; break;
    }
    return ret;
}

std::string ToString(const DXGI_GRAPHICS_PREEMPTION_GRANULARITY value)
{
    const char* ret = "Unhandled DXGI_GRAPHICS_PREEMPTION_GRANULARITY";
    switch (value) {
        case DXGI_GRAPHICS_PREEMPTION_DMA_BUFFER_BOUNDARY: ret = "DXGI_GRAPHICS_PREEMPTION_DMA_BUFFER_BOUNDARY"; break;
        case DXGI_GRAPHICS_PREEMPTION_PRIMITIVE_BOUNDARY: ret = "DXGI_GRAPHICS_PREEMPTION_PRIMITIVE_BOUNDARY"; break;
        case DXGI_GRAPHICS_PREEMPTION_TRIANGLE_BOUNDARY: ret = "DXGI_GRAPHICS_PREEMPTION_TRIANGLE_BOUNDARY"; break;
        case DXGI_GRAPHICS_PREEMPTION_PIXEL_BOUNDARY: ret = "DXGI_GRAPHICS_PREEMPTION_PIXEL_BOUNDARY"; break;
        case DXGI_GRAPHICS_PREEMPTION_INSTRUCTION_BOUNDARY: ret = "DXGI_GRAPHICS_PREEMPTION_INSTRUCTION_BOUNDARY"; break;
    }
    return ret;
}

std::string ToString(const DXGI_COMPUTE_PREEMPTION_GRANULARITY value)
{
    const char* ret = "Unhandled DXGI_COMPUTE_PREEMPTION_GRANULARITY";
    switch (value) {
        case DXGI_COMPUTE_PREEMPTION_DMA_BUFFER_BOUNDARY: ret = "DXGI_COMPUTE_PREEMPTION_DMA_BUFFER_BOUNDARY"; break;
        case DXGI_COMPUTE_PREEMPTION_DISPATCH_BOUNDARY: ret = "DXGI_COMPUTE_PREEMPTION_DISPATCH_BOUNDARY"; break;
        case DXGI_COMPUTE_PREEMPTION_THREAD_GROUP_BOUNDARY: ret = "DXGI_COMPUTE_PREEMPTION_THREAD_GROUP_BOUNDARY"; break;
        case DXGI_COMPUTE_PREEMPTION_THREAD_BOUNDARY: ret = "DXGI_COMPUTE_PREEMPTION_THREAD_BOUNDARY"; break;
        case DXGI_COMPUTE_PREEMPTION_INSTRUCTION_BOUNDARY: ret = "DXGI_COMPUTE_PREEMPTION_INSTRUCTION_BOUNDARY"; break;
    }
    return ret;
}

std::string ToString(const DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS value)
{
    const char* ret = "Unhandled DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS";
    switch (value) {
        case DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAG_NOMINAL_RANGE: ret = "DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAG_NOMINAL_RANGE"; break;
        case DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAG_BT709: ret = "DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAG_BT709"; break;
        case DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAG_xvYCC: ret = "DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAG_xvYCC"; break;
    }
    return ret;
}

std::string ToString_DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS(const uint32_t flags)
{
    return BitmaskToString<DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS>(flags);
}

std::string ToString(const DXGI_FRAME_PRESENTATION_MODE value)
{
    const char* ret = "Unhandled DXGI_FRAME_PRESENTATION_MODE";
    switch (value) {
        case DXGI_FRAME_PRESENTATION_MODE_COMPOSED: ret = "DXGI_FRAME_PRESENTATION_MODE_COMPOSED"; break;
        case DXGI_FRAME_PRESENTATION_MODE_OVERLAY: ret = "DXGI_FRAME_PRESENTATION_MODE_OVERLAY"; break;
        case DXGI_FRAME_PRESENTATION_MODE_NONE: ret = "DXGI_FRAME_PRESENTATION_MODE_NONE"; break;
        case DXGI_FRAME_PRESENTATION_MODE_COMPOSITION_FAILURE: ret = "DXGI_FRAME_PRESENTATION_MODE_COMPOSITION_FAILURE"; break;
    }
    return ret;
}

std::string ToString(const DXGI_OVERLAY_SUPPORT_FLAG value)
{
    const char* ret = "Unhandled DXGI_OVERLAY_SUPPORT_FLAG";
    switch (value) {
        case DXGI_OVERLAY_SUPPORT_FLAG_DIRECT: ret = "DXGI_OVERLAY_SUPPORT_FLAG_DIRECT"; break;
        case DXGI_OVERLAY_SUPPORT_FLAG_SCALING: ret = "DXGI_OVERLAY_SUPPORT_FLAG_SCALING"; break;
    }
    return ret;
}

std::string ToString(const DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG value)
{
    const char* ret = "Unhandled DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG";
    switch (value) {
        case DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG_PRESENT: ret = "DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG_PRESENT"; break;
        case DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG_OVERLAY_PRESENT: ret = "DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG_OVERLAY_PRESENT"; break;
    }
    return ret;
}

std::string ToString(const DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAG value)
{
    const char* ret = "Unhandled DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAG";
    switch (value) {
        case DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAG_PRESENT: ret = "DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAG_PRESENT"; break;
    }
    return ret;
}

std::string ToString(const DXGI_MEMORY_SEGMENT_GROUP value)
{
    const char* ret = "Unhandled DXGI_MEMORY_SEGMENT_GROUP";
    switch (value) {
        case DXGI_MEMORY_SEGMENT_GROUP_LOCAL: ret = "DXGI_MEMORY_SEGMENT_GROUP_LOCAL"; break;
        case DXGI_MEMORY_SEGMENT_GROUP_NON_LOCAL: ret = "DXGI_MEMORY_SEGMENT_GROUP_NON_LOCAL"; break;
    }
    return ret;
}

std::string ToString(const DXGI_OUTDUPL_FLAG value)
{
    const char* ret = "Unhandled DXGI_OUTDUPL_FLAG";
    switch (value) {
        case DXGI_OUTDUPL_COMPOSITED_UI_CAPTURE_ONLY: ret = "DXGI_OUTDUPL_COMPOSITED_UI_CAPTURE_ONLY"; break;
    }
    return ret;
}

std::string ToString(const DXGI_HDR_METADATA_TYPE value)
{
    const char* ret = "Unhandled DXGI_HDR_METADATA_TYPE";
    switch (value) {
        case DXGI_HDR_METADATA_TYPE_NONE: ret = "DXGI_HDR_METADATA_TYPE_NONE"; break;
        case DXGI_HDR_METADATA_TYPE_HDR10: ret = "DXGI_HDR_METADATA_TYPE_HDR10"; break;
        case DXGI_HDR_METADATA_TYPE_HDR10PLUS: ret = "DXGI_HDR_METADATA_TYPE_HDR10PLUS"; break;
    }
    return ret;
}

std::string ToString(const DXGI_OFFER_RESOURCE_FLAGS value)
{
    const char* ret = "Unhandled DXGI_OFFER_RESOURCE_FLAGS";
    switch (value) {
        case DXGI_OFFER_RESOURCE_FLAG_ALLOW_DECOMMIT: ret = "DXGI_OFFER_RESOURCE_FLAG_ALLOW_DECOMMIT"; break;
    }
    return ret;
}

std::string ToString_DXGI_OFFER_RESOURCE_FLAGS(const uint32_t flags)
{
    return BitmaskToString<DXGI_OFFER_RESOURCE_FLAGS>(flags);
}

std::string ToString(const DXGI_RECLAIM_RESOURCE_RESULTS value)
{
    const char* ret = "Unhandled DXGI_RECLAIM_RESOURCE_RESULTS";
    switch (value) {
        case DXGI_RECLAIM_RESOURCE_RESULT_OK: ret = "DXGI_RECLAIM_RESOURCE_RESULT_OK"; break;
        case DXGI_RECLAIM_RESOURCE_RESULT_DISCARDED: ret = "DXGI_RECLAIM_RESOURCE_RESULT_DISCARDED"; break;
        case DXGI_RECLAIM_RESOURCE_RESULT_NOT_COMMITTED: ret = "DXGI_RECLAIM_RESOURCE_RESULT_NOT_COMMITTED"; break;
    }
    return ret;
}

std::string ToString(const DXGI_FEATURE value)
{
    const char* ret = "Unhandled DXGI_FEATURE";
    switch (value) {
        case DXGI_FEATURE_PRESENT_ALLOW_TEARING: ret = "DXGI_FEATURE_PRESENT_ALLOW_TEARING"; break;
    }
    return ret;
}

std::string ToString(const DXGI_ADAPTER_FLAG3 value)
{
    const char* ret = "Unhandled DXGI_ADAPTER_FLAG3";
    switch (value) {
        case DXGI_ADAPTER_FLAG3_NONE: ret = "DXGI_ADAPTER_FLAG3_NONE"; break;
        case DXGI_ADAPTER_FLAG3_REMOTE: ret = "DXGI_ADAPTER_FLAG3_REMOTE"; break;
        case DXGI_ADAPTER_FLAG3_SOFTWARE: ret = "DXGI_ADAPTER_FLAG3_SOFTWARE"; break;
        case DXGI_ADAPTER_FLAG3_ACG_COMPATIBLE: ret = "DXGI_ADAPTER_FLAG3_ACG_COMPATIBLE"; break;
        case DXGI_ADAPTER_FLAG3_SUPPORT_MONITORED_FENCES: ret = "DXGI_ADAPTER_FLAG3_SUPPORT_MONITORED_FENCES"; break;
        case DXGI_ADAPTER_FLAG3_SUPPORT_NON_MONITORED_FENCES: ret = "DXGI_ADAPTER_FLAG3_SUPPORT_NON_MONITORED_FENCES"; break;
        case DXGI_ADAPTER_FLAG3_KEYED_MUTEX_CONFORMANCE: ret = "DXGI_ADAPTER_FLAG3_KEYED_MUTEX_CONFORMANCE"; break;
        case DXGI_ADAPTER_FLAG3_FORCE_DWORD: ret = "DXGI_ADAPTER_FLAG3_FORCE_DWORD"; break;
    }
    return ret;
}

std::string ToString(const DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAGS value)
{
    const char* ret = "Unhandled DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAGS";
    switch (value) {
        case DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAG_FULLSCREEN: ret = "DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAG_FULLSCREEN"; break;
        case DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAG_WINDOWED: ret = "DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAG_WINDOWED"; break;
        case DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAG_CURSOR_STRETCHED: ret = "DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAG_CURSOR_STRETCHED"; break;
    }
    return ret;
}

std::string ToString_DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAGS(const uint32_t flags)
{
    return BitmaskToString<DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAGS>(flags);
}

std::string ToString(const DXGI_GPU_PREFERENCE value)
{
    const char* ret = "Unhandled DXGI_GPU_PREFERENCE";
    switch (value) {
        case DXGI_GPU_PREFERENCE_UNSPECIFIED: ret = "DXGI_GPU_PREFERENCE_UNSPECIFIED"; break;
        case DXGI_GPU_PREFERENCE_MINIMUM_POWER: ret = "DXGI_GPU_PREFERENCE_MINIMUM_POWER"; break;
        case DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE: ret = "DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE"; break;
    }
    return ret;
}

std::string ToString(const DXGI_COLOR_SPACE_TYPE value)
{
    const char* ret = "Unhandled DXGI_COLOR_SPACE_TYPE";
    switch (value) {
        case DXGI_COLOR_SPACE_RGB_FULL_G22_NONE_P709: ret = "DXGI_COLOR_SPACE_RGB_FULL_G22_NONE_P709"; break;
        case DXGI_COLOR_SPACE_RGB_FULL_G10_NONE_P709: ret = "DXGI_COLOR_SPACE_RGB_FULL_G10_NONE_P709"; break;
        case DXGI_COLOR_SPACE_RGB_STUDIO_G22_NONE_P709: ret = "DXGI_COLOR_SPACE_RGB_STUDIO_G22_NONE_P709"; break;
        case DXGI_COLOR_SPACE_RGB_STUDIO_G22_NONE_P2020: ret = "DXGI_COLOR_SPACE_RGB_STUDIO_G22_NONE_P2020"; break;
        case DXGI_COLOR_SPACE_RESERVED: ret = "DXGI_COLOR_SPACE_RESERVED"; break;
        case DXGI_COLOR_SPACE_YCBCR_FULL_G22_NONE_P709_X601: ret = "DXGI_COLOR_SPACE_YCBCR_FULL_G22_NONE_P709_X601"; break;
        case DXGI_COLOR_SPACE_YCBCR_STUDIO_G22_LEFT_P601: ret = "DXGI_COLOR_SPACE_YCBCR_STUDIO_G22_LEFT_P601"; break;
        case DXGI_COLOR_SPACE_YCBCR_FULL_G22_LEFT_P601: ret = "DXGI_COLOR_SPACE_YCBCR_FULL_G22_LEFT_P601"; break;
        case DXGI_COLOR_SPACE_YCBCR_STUDIO_G22_LEFT_P709: ret = "DXGI_COLOR_SPACE_YCBCR_STUDIO_G22_LEFT_P709"; break;
        case DXGI_COLOR_SPACE_YCBCR_FULL_G22_LEFT_P709: ret = "DXGI_COLOR_SPACE_YCBCR_FULL_G22_LEFT_P709"; break;
        case DXGI_COLOR_SPACE_YCBCR_STUDIO_G22_LEFT_P2020: ret = "DXGI_COLOR_SPACE_YCBCR_STUDIO_G22_LEFT_P2020"; break;
        case DXGI_COLOR_SPACE_YCBCR_FULL_G22_LEFT_P2020: ret = "DXGI_COLOR_SPACE_YCBCR_FULL_G22_LEFT_P2020"; break;
        case DXGI_COLOR_SPACE_RGB_FULL_G2084_NONE_P2020: ret = "DXGI_COLOR_SPACE_RGB_FULL_G2084_NONE_P2020"; break;
        case DXGI_COLOR_SPACE_YCBCR_STUDIO_G2084_LEFT_P2020: ret = "DXGI_COLOR_SPACE_YCBCR_STUDIO_G2084_LEFT_P2020"; break;
        case DXGI_COLOR_SPACE_RGB_STUDIO_G2084_NONE_P2020: ret = "DXGI_COLOR_SPACE_RGB_STUDIO_G2084_NONE_P2020"; break;
        case DXGI_COLOR_SPACE_YCBCR_STUDIO_G22_TOPLEFT_P2020: ret = "DXGI_COLOR_SPACE_YCBCR_STUDIO_G22_TOPLEFT_P2020"; break;
        case DXGI_COLOR_SPACE_YCBCR_STUDIO_G2084_TOPLEFT_P2020: ret = "DXGI_COLOR_SPACE_YCBCR_STUDIO_G2084_TOPLEFT_P2020"; break;
        case DXGI_COLOR_SPACE_RGB_FULL_G22_NONE_P2020: ret = "DXGI_COLOR_SPACE_RGB_FULL_G22_NONE_P2020"; break;
        case DXGI_COLOR_SPACE_YCBCR_STUDIO_GHLG_TOPLEFT_P2020: ret = "DXGI_COLOR_SPACE_YCBCR_STUDIO_GHLG_TOPLEFT_P2020"; break;
        case DXGI_COLOR_SPACE_YCBCR_FULL_GHLG_TOPLEFT_P2020: ret = "DXGI_COLOR_SPACE_YCBCR_FULL_GHLG_TOPLEFT_P2020"; break;
        case DXGI_COLOR_SPACE_RGB_STUDIO_G24_NONE_P709: ret = "DXGI_COLOR_SPACE_RGB_STUDIO_G24_NONE_P709"; break;
        case DXGI_COLOR_SPACE_RGB_STUDIO_G24_NONE_P2020: ret = "DXGI_COLOR_SPACE_RGB_STUDIO_G24_NONE_P2020"; break;
        case DXGI_COLOR_SPACE_YCBCR_STUDIO_G24_LEFT_P709: ret = "DXGI_COLOR_SPACE_YCBCR_STUDIO_G24_LEFT_P709"; break;
        case DXGI_COLOR_SPACE_YCBCR_STUDIO_G24_LEFT_P2020: ret = "DXGI_COLOR_SPACE_YCBCR_STUDIO_G24_LEFT_P2020"; break;
        case DXGI_COLOR_SPACE_YCBCR_STUDIO_G24_TOPLEFT_P2020: ret = "DXGI_COLOR_SPACE_YCBCR_STUDIO_G24_TOPLEFT_P2020"; break;
        case DXGI_COLOR_SPACE_CUSTOM: ret = "DXGI_COLOR_SPACE_CUSTOM"; break;
    }
    return ret;
}

std::string ToString(const DXGI_FORMAT value)
{
    const char* ret = "Unhandled DXGI_FORMAT";
    switch (value) {
        case DXGI_FORMAT_UNKNOWN: ret = "DXGI_FORMAT_UNKNOWN"; break;
        case DXGI_FORMAT_R32G32B32A32_TYPELESS: ret = "DXGI_FORMAT_R32G32B32A32_TYPELESS"; break;
        case DXGI_FORMAT_R32G32B32A32_FLOAT: ret = "DXGI_FORMAT_R32G32B32A32_FLOAT"; break;
        case DXGI_FORMAT_R32G32B32A32_UINT: ret = "DXGI_FORMAT_R32G32B32A32_UINT"; break;
        case DXGI_FORMAT_R32G32B32A32_SINT: ret = "DXGI_FORMAT_R32G32B32A32_SINT"; break;
        case DXGI_FORMAT_R32G32B32_TYPELESS: ret = "DXGI_FORMAT_R32G32B32_TYPELESS"; break;
        case DXGI_FORMAT_R32G32B32_FLOAT: ret = "DXGI_FORMAT_R32G32B32_FLOAT"; break;
        case DXGI_FORMAT_R32G32B32_UINT: ret = "DXGI_FORMAT_R32G32B32_UINT"; break;
        case DXGI_FORMAT_R32G32B32_SINT: ret = "DXGI_FORMAT_R32G32B32_SINT"; break;
        case DXGI_FORMAT_R16G16B16A16_TYPELESS: ret = "DXGI_FORMAT_R16G16B16A16_TYPELESS"; break;
        case DXGI_FORMAT_R16G16B16A16_FLOAT: ret = "DXGI_FORMAT_R16G16B16A16_FLOAT"; break;
        case DXGI_FORMAT_R16G16B16A16_UNORM: ret = "DXGI_FORMAT_R16G16B16A16_UNORM"; break;
        case DXGI_FORMAT_R16G16B16A16_UINT: ret = "DXGI_FORMAT_R16G16B16A16_UINT"; break;
        case DXGI_FORMAT_R16G16B16A16_SNORM: ret = "DXGI_FORMAT_R16G16B16A16_SNORM"; break;
        case DXGI_FORMAT_R16G16B16A16_SINT: ret = "DXGI_FORMAT_R16G16B16A16_SINT"; break;
        case DXGI_FORMAT_R32G32_TYPELESS: ret = "DXGI_FORMAT_R32G32_TYPELESS"; break;
        case DXGI_FORMAT_R32G32_FLOAT: ret = "DXGI_FORMAT_R32G32_FLOAT"; break;
        case DXGI_FORMAT_R32G32_UINT: ret = "DXGI_FORMAT_R32G32_UINT"; break;
        case DXGI_FORMAT_R32G32_SINT: ret = "DXGI_FORMAT_R32G32_SINT"; break;
        case DXGI_FORMAT_R32G8X24_TYPELESS: ret = "DXGI_FORMAT_R32G8X24_TYPELESS"; break;
        case DXGI_FORMAT_D32_FLOAT_S8X24_UINT: ret = "DXGI_FORMAT_D32_FLOAT_S8X24_UINT"; break;
        case DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS: ret = "DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS"; break;
        case DXGI_FORMAT_X32_TYPELESS_G8X24_UINT: ret = "DXGI_FORMAT_X32_TYPELESS_G8X24_UINT"; break;
        case DXGI_FORMAT_R10G10B10A2_TYPELESS: ret = "DXGI_FORMAT_R10G10B10A2_TYPELESS"; break;
        case DXGI_FORMAT_R10G10B10A2_UNORM: ret = "DXGI_FORMAT_R10G10B10A2_UNORM"; break;
        case DXGI_FORMAT_R10G10B10A2_UINT: ret = "DXGI_FORMAT_R10G10B10A2_UINT"; break;
        case DXGI_FORMAT_R11G11B10_FLOAT: ret = "DXGI_FORMAT_R11G11B10_FLOAT"; break;
        case DXGI_FORMAT_R8G8B8A8_TYPELESS: ret = "DXGI_FORMAT_R8G8B8A8_TYPELESS"; break;
        case DXGI_FORMAT_R8G8B8A8_UNORM: ret = "DXGI_FORMAT_R8G8B8A8_UNORM"; break;
        case DXGI_FORMAT_R8G8B8A8_UNORM_SRGB: ret = "DXGI_FORMAT_R8G8B8A8_UNORM_SRGB"; break;
        case DXGI_FORMAT_R8G8B8A8_UINT: ret = "DXGI_FORMAT_R8G8B8A8_UINT"; break;
        case DXGI_FORMAT_R8G8B8A8_SNORM: ret = "DXGI_FORMAT_R8G8B8A8_SNORM"; break;
        case DXGI_FORMAT_R8G8B8A8_SINT: ret = "DXGI_FORMAT_R8G8B8A8_SINT"; break;
        case DXGI_FORMAT_R16G16_TYPELESS: ret = "DXGI_FORMAT_R16G16_TYPELESS"; break;
        case DXGI_FORMAT_R16G16_FLOAT: ret = "DXGI_FORMAT_R16G16_FLOAT"; break;
        case DXGI_FORMAT_R16G16_UNORM: ret = "DXGI_FORMAT_R16G16_UNORM"; break;
        case DXGI_FORMAT_R16G16_UINT: ret = "DXGI_FORMAT_R16G16_UINT"; break;
        case DXGI_FORMAT_R16G16_SNORM: ret = "DXGI_FORMAT_R16G16_SNORM"; break;
        case DXGI_FORMAT_R16G16_SINT: ret = "DXGI_FORMAT_R16G16_SINT"; break;
        case DXGI_FORMAT_R32_TYPELESS: ret = "DXGI_FORMAT_R32_TYPELESS"; break;
        case DXGI_FORMAT_D32_FLOAT: ret = "DXGI_FORMAT_D32_FLOAT"; break;
        case DXGI_FORMAT_R32_FLOAT: ret = "DXGI_FORMAT_R32_FLOAT"; break;
        case DXGI_FORMAT_R32_UINT: ret = "DXGI_FORMAT_R32_UINT"; break;
        case DXGI_FORMAT_R32_SINT: ret = "DXGI_FORMAT_R32_SINT"; break;
        case DXGI_FORMAT_R24G8_TYPELESS: ret = "DXGI_FORMAT_R24G8_TYPELESS"; break;
        case DXGI_FORMAT_D24_UNORM_S8_UINT: ret = "DXGI_FORMAT_D24_UNORM_S8_UINT"; break;
        case DXGI_FORMAT_R24_UNORM_X8_TYPELESS: ret = "DXGI_FORMAT_R24_UNORM_X8_TYPELESS"; break;
        case DXGI_FORMAT_X24_TYPELESS_G8_UINT: ret = "DXGI_FORMAT_X24_TYPELESS_G8_UINT"; break;
        case DXGI_FORMAT_R8G8_TYPELESS: ret = "DXGI_FORMAT_R8G8_TYPELESS"; break;
        case DXGI_FORMAT_R8G8_UNORM: ret = "DXGI_FORMAT_R8G8_UNORM"; break;
        case DXGI_FORMAT_R8G8_UINT: ret = "DXGI_FORMAT_R8G8_UINT"; break;
        case DXGI_FORMAT_R8G8_SNORM: ret = "DXGI_FORMAT_R8G8_SNORM"; break;
        case DXGI_FORMAT_R8G8_SINT: ret = "DXGI_FORMAT_R8G8_SINT"; break;
        case DXGI_FORMAT_R16_TYPELESS: ret = "DXGI_FORMAT_R16_TYPELESS"; break;
        case DXGI_FORMAT_R16_FLOAT: ret = "DXGI_FORMAT_R16_FLOAT"; break;
        case DXGI_FORMAT_D16_UNORM: ret = "DXGI_FORMAT_D16_UNORM"; break;
        case DXGI_FORMAT_R16_UNORM: ret = "DXGI_FORMAT_R16_UNORM"; break;
        case DXGI_FORMAT_R16_UINT: ret = "DXGI_FORMAT_R16_UINT"; break;
        case DXGI_FORMAT_R16_SNORM: ret = "DXGI_FORMAT_R16_SNORM"; break;
        case DXGI_FORMAT_R16_SINT: ret = "DXGI_FORMAT_R16_SINT"; break;
        case DXGI_FORMAT_R8_TYPELESS: ret = "DXGI_FORMAT_R8_TYPELESS"; break;
        case DXGI_FORMAT_R8_UNORM: ret = "DXGI_FORMAT_R8_UNORM"; break;
        case DXGI_FORMAT_R8_UINT: ret = "DXGI_FORMAT_R8_UINT"; break;
        case DXGI_FORMAT_R8_SNORM: ret = "DXGI_FORMAT_R8_SNORM"; break;
        case DXGI_FORMAT_R8_SINT: ret = "DXGI_FORMAT_R8_SINT"; break;
        case DXGI_FORMAT_A8_UNORM: ret = "DXGI_FORMAT_A8_UNORM"; break;
        case DXGI_FORMAT_R1_UNORM: ret = "DXGI_FORMAT_R1_UNORM"; break;
        case DXGI_FORMAT_R9G9B9E5_SHAREDEXP: ret = "DXGI_FORMAT_R9G9B9E5_SHAREDEXP"; break;
        case DXGI_FORMAT_R8G8_B8G8_UNORM: ret = "DXGI_FORMAT_R8G8_B8G8_UNORM"; break;
        case DXGI_FORMAT_G8R8_G8B8_UNORM: ret = "DXGI_FORMAT_G8R8_G8B8_UNORM"; break;
        case DXGI_FORMAT_BC1_TYPELESS: ret = "DXGI_FORMAT_BC1_TYPELESS"; break;
        case DXGI_FORMAT_BC1_UNORM: ret = "DXGI_FORMAT_BC1_UNORM"; break;
        case DXGI_FORMAT_BC1_UNORM_SRGB: ret = "DXGI_FORMAT_BC1_UNORM_SRGB"; break;
        case DXGI_FORMAT_BC2_TYPELESS: ret = "DXGI_FORMAT_BC2_TYPELESS"; break;
        case DXGI_FORMAT_BC2_UNORM: ret = "DXGI_FORMAT_BC2_UNORM"; break;
        case DXGI_FORMAT_BC2_UNORM_SRGB: ret = "DXGI_FORMAT_BC2_UNORM_SRGB"; break;
        case DXGI_FORMAT_BC3_TYPELESS: ret = "DXGI_FORMAT_BC3_TYPELESS"; break;
        case DXGI_FORMAT_BC3_UNORM: ret = "DXGI_FORMAT_BC3_UNORM"; break;
        case DXGI_FORMAT_BC3_UNORM_SRGB: ret = "DXGI_FORMAT_BC3_UNORM_SRGB"; break;
        case DXGI_FORMAT_BC4_TYPELESS: ret = "DXGI_FORMAT_BC4_TYPELESS"; break;
        case DXGI_FORMAT_BC4_UNORM: ret = "DXGI_FORMAT_BC4_UNORM"; break;
        case DXGI_FORMAT_BC4_SNORM: ret = "DXGI_FORMAT_BC4_SNORM"; break;
        case DXGI_FORMAT_BC5_TYPELESS: ret = "DXGI_FORMAT_BC5_TYPELESS"; break;
        case DXGI_FORMAT_BC5_UNORM: ret = "DXGI_FORMAT_BC5_UNORM"; break;
        case DXGI_FORMAT_BC5_SNORM: ret = "DXGI_FORMAT_BC5_SNORM"; break;
        case DXGI_FORMAT_B5G6R5_UNORM: ret = "DXGI_FORMAT_B5G6R5_UNORM"; break;
        case DXGI_FORMAT_B5G5R5A1_UNORM: ret = "DXGI_FORMAT_B5G5R5A1_UNORM"; break;
        case DXGI_FORMAT_B8G8R8A8_UNORM: ret = "DXGI_FORMAT_B8G8R8A8_UNORM"; break;
        case DXGI_FORMAT_B8G8R8X8_UNORM: ret = "DXGI_FORMAT_B8G8R8X8_UNORM"; break;
        case DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM: ret = "DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM"; break;
        case DXGI_FORMAT_B8G8R8A8_TYPELESS: ret = "DXGI_FORMAT_B8G8R8A8_TYPELESS"; break;
        case DXGI_FORMAT_B8G8R8A8_UNORM_SRGB: ret = "DXGI_FORMAT_B8G8R8A8_UNORM_SRGB"; break;
        case DXGI_FORMAT_B8G8R8X8_TYPELESS: ret = "DXGI_FORMAT_B8G8R8X8_TYPELESS"; break;
        case DXGI_FORMAT_B8G8R8X8_UNORM_SRGB: ret = "DXGI_FORMAT_B8G8R8X8_UNORM_SRGB"; break;
        case DXGI_FORMAT_BC6H_TYPELESS: ret = "DXGI_FORMAT_BC6H_TYPELESS"; break;
        case DXGI_FORMAT_BC6H_UF16: ret = "DXGI_FORMAT_BC6H_UF16"; break;
        case DXGI_FORMAT_BC6H_SF16: ret = "DXGI_FORMAT_BC6H_SF16"; break;
        case DXGI_FORMAT_BC7_TYPELESS: ret = "DXGI_FORMAT_BC7_TYPELESS"; break;
        case DXGI_FORMAT_BC7_UNORM: ret = "DXGI_FORMAT_BC7_UNORM"; break;
        case DXGI_FORMAT_BC7_UNORM_SRGB: ret = "DXGI_FORMAT_BC7_UNORM_SRGB"; break;
        case DXGI_FORMAT_AYUV: ret = "DXGI_FORMAT_AYUV"; break;
        case DXGI_FORMAT_Y410: ret = "DXGI_FORMAT_Y410"; break;
        case DXGI_FORMAT_Y416: ret = "DXGI_FORMAT_Y416"; break;
        case DXGI_FORMAT_NV12: ret = "DXGI_FORMAT_NV12"; break;
        case DXGI_FORMAT_P010: ret = "DXGI_FORMAT_P010"; break;
        case DXGI_FORMAT_P016: ret = "DXGI_FORMAT_P016"; break;
        case DXGI_FORMAT_420_OPAQUE: ret = "DXGI_FORMAT_420_OPAQUE"; break;
        case DXGI_FORMAT_YUY2: ret = "DXGI_FORMAT_YUY2"; break;
        case DXGI_FORMAT_Y210: ret = "DXGI_FORMAT_Y210"; break;
        case DXGI_FORMAT_Y216: ret = "DXGI_FORMAT_Y216"; break;
        case DXGI_FORMAT_NV11: ret = "DXGI_FORMAT_NV11"; break;
        case DXGI_FORMAT_AI44: ret = "DXGI_FORMAT_AI44"; break;
        case DXGI_FORMAT_IA44: ret = "DXGI_FORMAT_IA44"; break;
        case DXGI_FORMAT_P8: ret = "DXGI_FORMAT_P8"; break;
        case DXGI_FORMAT_A8P8: ret = "DXGI_FORMAT_A8P8"; break;
        case DXGI_FORMAT_B4G4R4A4_UNORM: ret = "DXGI_FORMAT_B4G4R4A4_UNORM"; break;
        case DXGI_FORMAT_P208: ret = "DXGI_FORMAT_P208"; break;
        case DXGI_FORMAT_V208: ret = "DXGI_FORMAT_V208"; break;
        case DXGI_FORMAT_V408: ret = "DXGI_FORMAT_V408"; break;
        case DXGI_FORMAT_SAMPLER_FEEDBACK_MIN_MIP_OPAQUE: ret = "DXGI_FORMAT_SAMPLER_FEEDBACK_MIN_MIP_OPAQUE"; break;
        case DXGI_FORMAT_SAMPLER_FEEDBACK_MIP_REGION_USED_OPAQUE: ret = "DXGI_FORMAT_SAMPLER_FEEDBACK_MIP_REGION_USED_OPAQUE"; break;
        case DXGI_FORMAT_FORCE_UINT: ret = "DXGI_FORMAT_FORCE_UINT"; break;
    }
    return ret;
}

std::string ToString(const DXGI_MODE_SCANLINE_ORDER value)
{
    const char* ret = "Unhandled DXGI_MODE_SCANLINE_ORDER";
    switch (value) {
        case DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED: ret = "DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED"; break;
        case DXGI_MODE_SCANLINE_ORDER_PROGRESSIVE: ret = "DXGI_MODE_SCANLINE_ORDER_PROGRESSIVE"; break;
        case DXGI_MODE_SCANLINE_ORDER_UPPER_FIELD_FIRST: ret = "DXGI_MODE_SCANLINE_ORDER_UPPER_FIELD_FIRST"; break;
        case DXGI_MODE_SCANLINE_ORDER_LOWER_FIELD_FIRST: ret = "DXGI_MODE_SCANLINE_ORDER_LOWER_FIELD_FIRST"; break;
    }
    return ret;
}

std::string ToString(const DXGI_MODE_SCALING value)
{
    const char* ret = "Unhandled DXGI_MODE_SCALING";
    switch (value) {
        case DXGI_MODE_SCALING_UNSPECIFIED: ret = "DXGI_MODE_SCALING_UNSPECIFIED"; break;
        case DXGI_MODE_SCALING_CENTERED: ret = "DXGI_MODE_SCALING_CENTERED"; break;
        case DXGI_MODE_SCALING_STRETCHED: ret = "DXGI_MODE_SCALING_STRETCHED"; break;
    }
    return ret;
}

std::string ToString(const DXGI_MODE_ROTATION value)
{
    const char* ret = "Unhandled DXGI_MODE_ROTATION";
    switch (value) {
        case DXGI_MODE_ROTATION_UNSPECIFIED: ret = "DXGI_MODE_ROTATION_UNSPECIFIED"; break;
        case DXGI_MODE_ROTATION_IDENTITY: ret = "DXGI_MODE_ROTATION_IDENTITY"; break;
        case DXGI_MODE_ROTATION_ROTATE90: ret = "DXGI_MODE_ROTATION_ROTATE90"; break;
        case DXGI_MODE_ROTATION_ROTATE180: ret = "DXGI_MODE_ROTATION_ROTATE180"; break;
        case DXGI_MODE_ROTATION_ROTATE270: ret = "DXGI_MODE_ROTATION_ROTATE270"; break;
    }
    return ret;
}

std::string ToString(const D3D12_COMMAND_LIST_TYPE value)
{
    const char* ret = "Unhandled D3D12_COMMAND_LIST_TYPE";
    switch (value) {
        case D3D12_COMMAND_LIST_TYPE_DIRECT: ret = "D3D12_COMMAND_LIST_TYPE_DIRECT"; break;
        case D3D12_COMMAND_LIST_TYPE_BUNDLE: ret = "D3D12_COMMAND_LIST_TYPE_BUNDLE"; break;
        case D3D12_COMMAND_LIST_TYPE_COMPUTE: ret = "D3D12_COMMAND_LIST_TYPE_COMPUTE"; break;
        case D3D12_COMMAND_LIST_TYPE_COPY: ret = "D3D12_COMMAND_LIST_TYPE_COPY"; break;
        case D3D12_COMMAND_LIST_TYPE_VIDEO_DECODE: ret = "D3D12_COMMAND_LIST_TYPE_VIDEO_DECODE"; break;
        case D3D12_COMMAND_LIST_TYPE_VIDEO_PROCESS: ret = "D3D12_COMMAND_LIST_TYPE_VIDEO_PROCESS"; break;
        case D3D12_COMMAND_LIST_TYPE_VIDEO_ENCODE: ret = "D3D12_COMMAND_LIST_TYPE_VIDEO_ENCODE"; break;
        case D3D12_COMMAND_LIST_TYPE_NONE: ret = "D3D12_COMMAND_LIST_TYPE_NONE"; break;
    }
    return ret;
}

std::string ToString(const D3D12_COMMAND_QUEUE_FLAGS value)
{
    const char* ret = "Unhandled D3D12_COMMAND_QUEUE_FLAGS";
    switch (value) {
        case D3D12_COMMAND_QUEUE_FLAG_NONE: ret = "D3D12_COMMAND_QUEUE_FLAG_NONE"; break;
        case D3D12_COMMAND_QUEUE_FLAG_DISABLE_GPU_TIMEOUT: ret = "D3D12_COMMAND_QUEUE_FLAG_DISABLE_GPU_TIMEOUT"; break;
    }
    return ret;
}

std::string ToString_D3D12_COMMAND_QUEUE_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_COMMAND_QUEUE_FLAGS>(flags);
}

std::string ToString(const D3D12_COMMAND_QUEUE_PRIORITY value)
{
    const char* ret = "Unhandled D3D12_COMMAND_QUEUE_PRIORITY";
    switch (value) {
        case D3D12_COMMAND_QUEUE_PRIORITY_NORMAL: ret = "D3D12_COMMAND_QUEUE_PRIORITY_NORMAL"; break;
        case D3D12_COMMAND_QUEUE_PRIORITY_HIGH: ret = "D3D12_COMMAND_QUEUE_PRIORITY_HIGH"; break;
        case D3D12_COMMAND_QUEUE_PRIORITY_GLOBAL_REALTIME: ret = "D3D12_COMMAND_QUEUE_PRIORITY_GLOBAL_REALTIME"; break;
    }
    return ret;
}

std::string ToString(const D3D12_PRIMITIVE_TOPOLOGY_TYPE value)
{
    const char* ret = "Unhandled D3D12_PRIMITIVE_TOPOLOGY_TYPE";
    switch (value) {
        case D3D12_PRIMITIVE_TOPOLOGY_TYPE_UNDEFINED: ret = "D3D12_PRIMITIVE_TOPOLOGY_TYPE_UNDEFINED"; break;
        case D3D12_PRIMITIVE_TOPOLOGY_TYPE_POINT: ret = "D3D12_PRIMITIVE_TOPOLOGY_TYPE_POINT"; break;
        case D3D12_PRIMITIVE_TOPOLOGY_TYPE_LINE: ret = "D3D12_PRIMITIVE_TOPOLOGY_TYPE_LINE"; break;
        case D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE: ret = "D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE"; break;
        case D3D12_PRIMITIVE_TOPOLOGY_TYPE_PATCH: ret = "D3D12_PRIMITIVE_TOPOLOGY_TYPE_PATCH"; break;
    }
    return ret;
}

std::string ToString(const D3D12_INPUT_CLASSIFICATION value)
{
    const char* ret = "Unhandled D3D12_INPUT_CLASSIFICATION";
    switch (value) {
        case D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA: ret = "D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA"; break;
        case D3D12_INPUT_CLASSIFICATION_PER_INSTANCE_DATA: ret = "D3D12_INPUT_CLASSIFICATION_PER_INSTANCE_DATA"; break;
    }
    return ret;
}

std::string ToString(const D3D12_FILL_MODE value)
{
    const char* ret = "Unhandled D3D12_FILL_MODE";
    switch (value) {
        case D3D12_FILL_MODE_WIREFRAME: ret = "D3D12_FILL_MODE_WIREFRAME"; break;
        case D3D12_FILL_MODE_SOLID: ret = "D3D12_FILL_MODE_SOLID"; break;
    }
    return ret;
}

std::string ToString(const D3D12_CULL_MODE value)
{
    const char* ret = "Unhandled D3D12_CULL_MODE";
    switch (value) {
        case D3D12_CULL_MODE_NONE: ret = "D3D12_CULL_MODE_NONE"; break;
        case D3D12_CULL_MODE_FRONT: ret = "D3D12_CULL_MODE_FRONT"; break;
        case D3D12_CULL_MODE_BACK: ret = "D3D12_CULL_MODE_BACK"; break;
    }
    return ret;
}

std::string ToString(const D3D12_COMPARISON_FUNC value)
{
    const char* ret = "Unhandled D3D12_COMPARISON_FUNC";
    switch (value) {
        case D3D12_COMPARISON_FUNC_NONE: ret = "D3D12_COMPARISON_FUNC_NONE"; break;
        case D3D12_COMPARISON_FUNC_NEVER: ret = "D3D12_COMPARISON_FUNC_NEVER"; break;
        case D3D12_COMPARISON_FUNC_LESS: ret = "D3D12_COMPARISON_FUNC_LESS"; break;
        case D3D12_COMPARISON_FUNC_EQUAL: ret = "D3D12_COMPARISON_FUNC_EQUAL"; break;
        case D3D12_COMPARISON_FUNC_LESS_EQUAL: ret = "D3D12_COMPARISON_FUNC_LESS_EQUAL"; break;
        case D3D12_COMPARISON_FUNC_GREATER: ret = "D3D12_COMPARISON_FUNC_GREATER"; break;
        case D3D12_COMPARISON_FUNC_NOT_EQUAL: ret = "D3D12_COMPARISON_FUNC_NOT_EQUAL"; break;
        case D3D12_COMPARISON_FUNC_GREATER_EQUAL: ret = "D3D12_COMPARISON_FUNC_GREATER_EQUAL"; break;
        case D3D12_COMPARISON_FUNC_ALWAYS: ret = "D3D12_COMPARISON_FUNC_ALWAYS"; break;
    }
    return ret;
}

std::string ToString(const D3D12_DEPTH_WRITE_MASK value)
{
    const char* ret = "Unhandled D3D12_DEPTH_WRITE_MASK";
    switch (value) {
        case D3D12_DEPTH_WRITE_MASK_ZERO: ret = "D3D12_DEPTH_WRITE_MASK_ZERO"; break;
        case D3D12_DEPTH_WRITE_MASK_ALL: ret = "D3D12_DEPTH_WRITE_MASK_ALL"; break;
    }
    return ret;
}

std::string ToString(const D3D12_STENCIL_OP value)
{
    const char* ret = "Unhandled D3D12_STENCIL_OP";
    switch (value) {
        case D3D12_STENCIL_OP_KEEP: ret = "D3D12_STENCIL_OP_KEEP"; break;
        case D3D12_STENCIL_OP_ZERO: ret = "D3D12_STENCIL_OP_ZERO"; break;
        case D3D12_STENCIL_OP_REPLACE: ret = "D3D12_STENCIL_OP_REPLACE"; break;
        case D3D12_STENCIL_OP_INCR_SAT: ret = "D3D12_STENCIL_OP_INCR_SAT"; break;
        case D3D12_STENCIL_OP_DECR_SAT: ret = "D3D12_STENCIL_OP_DECR_SAT"; break;
        case D3D12_STENCIL_OP_INVERT: ret = "D3D12_STENCIL_OP_INVERT"; break;
        case D3D12_STENCIL_OP_INCR: ret = "D3D12_STENCIL_OP_INCR"; break;
        case D3D12_STENCIL_OP_DECR: ret = "D3D12_STENCIL_OP_DECR"; break;
    }
    return ret;
}

std::string ToString(const D3D12_BLEND value)
{
    const char* ret = "Unhandled D3D12_BLEND";
    switch (value) {
        case D3D12_BLEND_ZERO: ret = "D3D12_BLEND_ZERO"; break;
        case D3D12_BLEND_ONE: ret = "D3D12_BLEND_ONE"; break;
        case D3D12_BLEND_SRC_COLOR: ret = "D3D12_BLEND_SRC_COLOR"; break;
        case D3D12_BLEND_INV_SRC_COLOR: ret = "D3D12_BLEND_INV_SRC_COLOR"; break;
        case D3D12_BLEND_SRC_ALPHA: ret = "D3D12_BLEND_SRC_ALPHA"; break;
        case D3D12_BLEND_INV_SRC_ALPHA: ret = "D3D12_BLEND_INV_SRC_ALPHA"; break;
        case D3D12_BLEND_DEST_ALPHA: ret = "D3D12_BLEND_DEST_ALPHA"; break;
        case D3D12_BLEND_INV_DEST_ALPHA: ret = "D3D12_BLEND_INV_DEST_ALPHA"; break;
        case D3D12_BLEND_DEST_COLOR: ret = "D3D12_BLEND_DEST_COLOR"; break;
        case D3D12_BLEND_INV_DEST_COLOR: ret = "D3D12_BLEND_INV_DEST_COLOR"; break;
        case D3D12_BLEND_SRC_ALPHA_SAT: ret = "D3D12_BLEND_SRC_ALPHA_SAT"; break;
        case D3D12_BLEND_BLEND_FACTOR: ret = "D3D12_BLEND_BLEND_FACTOR"; break;
        case D3D12_BLEND_INV_BLEND_FACTOR: ret = "D3D12_BLEND_INV_BLEND_FACTOR"; break;
        case D3D12_BLEND_SRC1_COLOR: ret = "D3D12_BLEND_SRC1_COLOR"; break;
        case D3D12_BLEND_INV_SRC1_COLOR: ret = "D3D12_BLEND_INV_SRC1_COLOR"; break;
        case D3D12_BLEND_SRC1_ALPHA: ret = "D3D12_BLEND_SRC1_ALPHA"; break;
        case D3D12_BLEND_INV_SRC1_ALPHA: ret = "D3D12_BLEND_INV_SRC1_ALPHA"; break;
        case D3D12_BLEND_ALPHA_FACTOR: ret = "D3D12_BLEND_ALPHA_FACTOR"; break;
        case D3D12_BLEND_INV_ALPHA_FACTOR: ret = "D3D12_BLEND_INV_ALPHA_FACTOR"; break;
    }
    return ret;
}

std::string ToString(const D3D12_BLEND_OP value)
{
    const char* ret = "Unhandled D3D12_BLEND_OP";
    switch (value) {
        case D3D12_BLEND_OP_ADD: ret = "D3D12_BLEND_OP_ADD"; break;
        case D3D12_BLEND_OP_SUBTRACT: ret = "D3D12_BLEND_OP_SUBTRACT"; break;
        case D3D12_BLEND_OP_REV_SUBTRACT: ret = "D3D12_BLEND_OP_REV_SUBTRACT"; break;
        case D3D12_BLEND_OP_MIN: ret = "D3D12_BLEND_OP_MIN"; break;
        case D3D12_BLEND_OP_MAX: ret = "D3D12_BLEND_OP_MAX"; break;
    }
    return ret;
}

std::string ToString(const D3D12_COLOR_WRITE_ENABLE value)
{
    const char* ret = "Unhandled D3D12_COLOR_WRITE_ENABLE";
    switch (value) {
        case D3D12_COLOR_WRITE_ENABLE_RED: ret = "D3D12_COLOR_WRITE_ENABLE_RED"; break;
        case D3D12_COLOR_WRITE_ENABLE_GREEN: ret = "D3D12_COLOR_WRITE_ENABLE_GREEN"; break;
        case D3D12_COLOR_WRITE_ENABLE_BLUE: ret = "D3D12_COLOR_WRITE_ENABLE_BLUE"; break;
        case D3D12_COLOR_WRITE_ENABLE_ALPHA: ret = "D3D12_COLOR_WRITE_ENABLE_ALPHA"; break;
        case D3D12_COLOR_WRITE_ENABLE_ALL: ret = "D3D12_COLOR_WRITE_ENABLE_ALL"; break;
    }
    return ret;
}

std::string ToString(const D3D12_LOGIC_OP value)
{
    const char* ret = "Unhandled D3D12_LOGIC_OP";
    switch (value) {
        case D3D12_LOGIC_OP_CLEAR: ret = "D3D12_LOGIC_OP_CLEAR"; break;
        case D3D12_LOGIC_OP_SET: ret = "D3D12_LOGIC_OP_SET"; break;
        case D3D12_LOGIC_OP_COPY: ret = "D3D12_LOGIC_OP_COPY"; break;
        case D3D12_LOGIC_OP_COPY_INVERTED: ret = "D3D12_LOGIC_OP_COPY_INVERTED"; break;
        case D3D12_LOGIC_OP_NOOP: ret = "D3D12_LOGIC_OP_NOOP"; break;
        case D3D12_LOGIC_OP_INVERT: ret = "D3D12_LOGIC_OP_INVERT"; break;
        case D3D12_LOGIC_OP_AND: ret = "D3D12_LOGIC_OP_AND"; break;
        case D3D12_LOGIC_OP_NAND: ret = "D3D12_LOGIC_OP_NAND"; break;
        case D3D12_LOGIC_OP_OR: ret = "D3D12_LOGIC_OP_OR"; break;
        case D3D12_LOGIC_OP_NOR: ret = "D3D12_LOGIC_OP_NOR"; break;
        case D3D12_LOGIC_OP_XOR: ret = "D3D12_LOGIC_OP_XOR"; break;
        case D3D12_LOGIC_OP_EQUIV: ret = "D3D12_LOGIC_OP_EQUIV"; break;
        case D3D12_LOGIC_OP_AND_REVERSE: ret = "D3D12_LOGIC_OP_AND_REVERSE"; break;
        case D3D12_LOGIC_OP_AND_INVERTED: ret = "D3D12_LOGIC_OP_AND_INVERTED"; break;
        case D3D12_LOGIC_OP_OR_REVERSE: ret = "D3D12_LOGIC_OP_OR_REVERSE"; break;
        case D3D12_LOGIC_OP_OR_INVERTED: ret = "D3D12_LOGIC_OP_OR_INVERTED"; break;
    }
    return ret;
}

std::string ToString(const D3D12_CONSERVATIVE_RASTERIZATION_MODE value)
{
    const char* ret = "Unhandled D3D12_CONSERVATIVE_RASTERIZATION_MODE";
    switch (value) {
        case D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF: ret = "D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF"; break;
        case D3D12_CONSERVATIVE_RASTERIZATION_MODE_ON: ret = "D3D12_CONSERVATIVE_RASTERIZATION_MODE_ON"; break;
    }
    return ret;
}

std::string ToString(const D3D12_LINE_RASTERIZATION_MODE value)
{
    const char* ret = "Unhandled D3D12_LINE_RASTERIZATION_MODE";
    switch (value) {
        case D3D12_LINE_RASTERIZATION_MODE_ALIASED: ret = "D3D12_LINE_RASTERIZATION_MODE_ALIASED"; break;
        case D3D12_LINE_RASTERIZATION_MODE_ALPHA_ANTIALIASED: ret = "D3D12_LINE_RASTERIZATION_MODE_ALPHA_ANTIALIASED"; break;
        case D3D12_LINE_RASTERIZATION_MODE_QUADRILATERAL_WIDE: ret = "D3D12_LINE_RASTERIZATION_MODE_QUADRILATERAL_WIDE"; break;
        case D3D12_LINE_RASTERIZATION_MODE_QUADRILATERAL_NARROW: ret = "D3D12_LINE_RASTERIZATION_MODE_QUADRILATERAL_NARROW"; break;
    }
    return ret;
}

std::string ToString(const D3D12_INDEX_BUFFER_STRIP_CUT_VALUE value)
{
    const char* ret = "Unhandled D3D12_INDEX_BUFFER_STRIP_CUT_VALUE";
    switch (value) {
        case D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_DISABLED: ret = "D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_DISABLED"; break;
        case D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_0xFFFF: ret = "D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_0xFFFF"; break;
        case D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_0xFFFFFFFF: ret = "D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_0xFFFFFFFF"; break;
    }
    return ret;
}

std::string ToString(const D3D12_PIPELINE_STATE_FLAGS value)
{
    const char* ret = "Unhandled D3D12_PIPELINE_STATE_FLAGS";
    switch (value) {
        case D3D12_PIPELINE_STATE_FLAG_NONE: ret = "D3D12_PIPELINE_STATE_FLAG_NONE"; break;
        case D3D12_PIPELINE_STATE_FLAG_TOOL_DEBUG: ret = "D3D12_PIPELINE_STATE_FLAG_TOOL_DEBUG"; break;
        case D3D12_PIPELINE_STATE_FLAG_DYNAMIC_DEPTH_BIAS: ret = "D3D12_PIPELINE_STATE_FLAG_DYNAMIC_DEPTH_BIAS"; break;
        case D3D12_PIPELINE_STATE_FLAG_DYNAMIC_INDEX_BUFFER_STRIP_CUT: ret = "D3D12_PIPELINE_STATE_FLAG_DYNAMIC_INDEX_BUFFER_STRIP_CUT"; break;
    }
    return ret;
}

std::string ToString_D3D12_PIPELINE_STATE_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_PIPELINE_STATE_FLAGS>(flags);
}

std::string ToString(const D3D12_PIPELINE_STATE_SUBOBJECT_TYPE value)
{
    const char* ret = "Unhandled D3D12_PIPELINE_STATE_SUBOBJECT_TYPE";
    switch (value) {
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_ROOT_SIGNATURE: ret = "D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_ROOT_SIGNATURE"; break;
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_VS: ret = "D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_VS"; break;
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_PS: ret = "D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_PS"; break;
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DS: ret = "D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DS"; break;
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_HS: ret = "D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_HS"; break;
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_GS: ret = "D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_GS"; break;
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_CS: ret = "D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_CS"; break;
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_STREAM_OUTPUT: ret = "D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_STREAM_OUTPUT"; break;
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_BLEND: ret = "D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_BLEND"; break;
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_SAMPLE_MASK: ret = "D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_SAMPLE_MASK"; break;
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_RASTERIZER: ret = "D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_RASTERIZER"; break;
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL: ret = "D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL"; break;
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_INPUT_LAYOUT: ret = "D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_INPUT_LAYOUT"; break;
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_IB_STRIP_CUT_VALUE: ret = "D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_IB_STRIP_CUT_VALUE"; break;
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_PRIMITIVE_TOPOLOGY: ret = "D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_PRIMITIVE_TOPOLOGY"; break;
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_RENDER_TARGET_FORMATS: ret = "D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_RENDER_TARGET_FORMATS"; break;
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL_FORMAT: ret = "D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL_FORMAT"; break;
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_SAMPLE_DESC: ret = "D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_SAMPLE_DESC"; break;
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_NODE_MASK: ret = "D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_NODE_MASK"; break;
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_CACHED_PSO: ret = "D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_CACHED_PSO"; break;
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_FLAGS: ret = "D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_FLAGS"; break;
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL1: ret = "D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL1"; break;
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_VIEW_INSTANCING: ret = "D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_VIEW_INSTANCING"; break;
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_AS: ret = "D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_AS"; break;
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_MS: ret = "D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_MS"; break;
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL2: ret = "D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL2"; break;
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_RASTERIZER1: ret = "D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_RASTERIZER1"; break;
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_RASTERIZER2: ret = "D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_RASTERIZER2"; break;
        case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_MAX_VALID: ret = "D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_MAX_VALID"; break;
    }
    return ret;
}

std::string ToString(const D3D12_FEATURE value)
{
    const char* ret = "Unhandled D3D12_FEATURE";
    switch (value) {
        case D3D12_FEATURE_D3D12_OPTIONS: ret = "D3D12_FEATURE_D3D12_OPTIONS"; break;
        case D3D12_FEATURE_ARCHITECTURE: ret = "D3D12_FEATURE_ARCHITECTURE"; break;
        case D3D12_FEATURE_FEATURE_LEVELS: ret = "D3D12_FEATURE_FEATURE_LEVELS"; break;
        case D3D12_FEATURE_FORMAT_SUPPORT: ret = "D3D12_FEATURE_FORMAT_SUPPORT"; break;
        case D3D12_FEATURE_MULTISAMPLE_QUALITY_LEVELS: ret = "D3D12_FEATURE_MULTISAMPLE_QUALITY_LEVELS"; break;
        case D3D12_FEATURE_FORMAT_INFO: ret = "D3D12_FEATURE_FORMAT_INFO"; break;
        case D3D12_FEATURE_GPU_VIRTUAL_ADDRESS_SUPPORT: ret = "D3D12_FEATURE_GPU_VIRTUAL_ADDRESS_SUPPORT"; break;
        case D3D12_FEATURE_SHADER_MODEL: ret = "D3D12_FEATURE_SHADER_MODEL"; break;
        case D3D12_FEATURE_D3D12_OPTIONS1: ret = "D3D12_FEATURE_D3D12_OPTIONS1"; break;
        case D3D12_FEATURE_PROTECTED_RESOURCE_SESSION_SUPPORT: ret = "D3D12_FEATURE_PROTECTED_RESOURCE_SESSION_SUPPORT"; break;
        case D3D12_FEATURE_ROOT_SIGNATURE: ret = "D3D12_FEATURE_ROOT_SIGNATURE"; break;
        case D3D12_FEATURE_ARCHITECTURE1: ret = "D3D12_FEATURE_ARCHITECTURE1"; break;
        case D3D12_FEATURE_D3D12_OPTIONS2: ret = "D3D12_FEATURE_D3D12_OPTIONS2"; break;
        case D3D12_FEATURE_SHADER_CACHE: ret = "D3D12_FEATURE_SHADER_CACHE"; break;
        case D3D12_FEATURE_COMMAND_QUEUE_PRIORITY: ret = "D3D12_FEATURE_COMMAND_QUEUE_PRIORITY"; break;
        case D3D12_FEATURE_D3D12_OPTIONS3: ret = "D3D12_FEATURE_D3D12_OPTIONS3"; break;
        case D3D12_FEATURE_EXISTING_HEAPS: ret = "D3D12_FEATURE_EXISTING_HEAPS"; break;
        case D3D12_FEATURE_D3D12_OPTIONS4: ret = "D3D12_FEATURE_D3D12_OPTIONS4"; break;
        case D3D12_FEATURE_SERIALIZATION: ret = "D3D12_FEATURE_SERIALIZATION"; break;
        case D3D12_FEATURE_CROSS_NODE: ret = "D3D12_FEATURE_CROSS_NODE"; break;
        case D3D12_FEATURE_D3D12_OPTIONS5: ret = "D3D12_FEATURE_D3D12_OPTIONS5"; break;
        case D3D12_FEATURE_DISPLAYABLE: ret = "D3D12_FEATURE_DISPLAYABLE"; break;
        case D3D12_FEATURE_D3D12_OPTIONS6: ret = "D3D12_FEATURE_D3D12_OPTIONS6"; break;
        case D3D12_FEATURE_QUERY_META_COMMAND: ret = "D3D12_FEATURE_QUERY_META_COMMAND"; break;
        case D3D12_FEATURE_D3D12_OPTIONS7: ret = "D3D12_FEATURE_D3D12_OPTIONS7"; break;
        case D3D12_FEATURE_PROTECTED_RESOURCE_SESSION_TYPE_COUNT: ret = "D3D12_FEATURE_PROTECTED_RESOURCE_SESSION_TYPE_COUNT"; break;
        case D3D12_FEATURE_PROTECTED_RESOURCE_SESSION_TYPES: ret = "D3D12_FEATURE_PROTECTED_RESOURCE_SESSION_TYPES"; break;
        case D3D12_FEATURE_D3D12_OPTIONS8: ret = "D3D12_FEATURE_D3D12_OPTIONS8"; break;
        case D3D12_FEATURE_D3D12_OPTIONS9: ret = "D3D12_FEATURE_D3D12_OPTIONS9"; break;
        case D3D12_FEATURE_D3D12_OPTIONS10: ret = "D3D12_FEATURE_D3D12_OPTIONS10"; break;
        case D3D12_FEATURE_D3D12_OPTIONS11: ret = "D3D12_FEATURE_D3D12_OPTIONS11"; break;
        case D3D12_FEATURE_D3D12_OPTIONS12: ret = "D3D12_FEATURE_D3D12_OPTIONS12"; break;
        case D3D12_FEATURE_D3D12_OPTIONS13: ret = "D3D12_FEATURE_D3D12_OPTIONS13"; break;
        case D3D12_FEATURE_D3D12_OPTIONS14: ret = "D3D12_FEATURE_D3D12_OPTIONS14"; break;
        case D3D12_FEATURE_D3D12_OPTIONS15: ret = "D3D12_FEATURE_D3D12_OPTIONS15"; break;
        case D3D12_FEATURE_D3D12_OPTIONS16: ret = "D3D12_FEATURE_D3D12_OPTIONS16"; break;
        case D3D12_FEATURE_D3D12_OPTIONS17: ret = "D3D12_FEATURE_D3D12_OPTIONS17"; break;
        case D3D12_FEATURE_D3D12_OPTIONS18: ret = "D3D12_FEATURE_D3D12_OPTIONS18"; break;
        case D3D12_FEATURE_D3D12_OPTIONS19: ret = "D3D12_FEATURE_D3D12_OPTIONS19"; break;
    }
    return ret;
}

std::string ToString(const D3D12_SHADER_MIN_PRECISION_SUPPORT value)
{
    const char* ret = "Unhandled D3D12_SHADER_MIN_PRECISION_SUPPORT";
    switch (value) {
        case D3D12_SHADER_MIN_PRECISION_SUPPORT_NONE: ret = "D3D12_SHADER_MIN_PRECISION_SUPPORT_NONE"; break;
        case D3D12_SHADER_MIN_PRECISION_SUPPORT_10_BIT: ret = "D3D12_SHADER_MIN_PRECISION_SUPPORT_10_BIT"; break;
        case D3D12_SHADER_MIN_PRECISION_SUPPORT_16_BIT: ret = "D3D12_SHADER_MIN_PRECISION_SUPPORT_16_BIT"; break;
    }
    return ret;
}

std::string ToString_D3D12_SHADER_MIN_PRECISION_SUPPORT(const uint32_t flags)
{
    return BitmaskToString<D3D12_SHADER_MIN_PRECISION_SUPPORT>(flags);
}

std::string ToString(const D3D12_TILED_RESOURCES_TIER value)
{
    const char* ret = "Unhandled D3D12_TILED_RESOURCES_TIER";
    switch (value) {
        case D3D12_TILED_RESOURCES_TIER_NOT_SUPPORTED: ret = "D3D12_TILED_RESOURCES_TIER_NOT_SUPPORTED"; break;
        case D3D12_TILED_RESOURCES_TIER_1: ret = "D3D12_TILED_RESOURCES_TIER_1"; break;
        case D3D12_TILED_RESOURCES_TIER_2: ret = "D3D12_TILED_RESOURCES_TIER_2"; break;
        case D3D12_TILED_RESOURCES_TIER_3: ret = "D3D12_TILED_RESOURCES_TIER_3"; break;
        case D3D12_TILED_RESOURCES_TIER_4: ret = "D3D12_TILED_RESOURCES_TIER_4"; break;
    }
    return ret;
}

std::string ToString(const D3D12_RESOURCE_BINDING_TIER value)
{
    const char* ret = "Unhandled D3D12_RESOURCE_BINDING_TIER";
    switch (value) {
        case D3D12_RESOURCE_BINDING_TIER_1: ret = "D3D12_RESOURCE_BINDING_TIER_1"; break;
        case D3D12_RESOURCE_BINDING_TIER_2: ret = "D3D12_RESOURCE_BINDING_TIER_2"; break;
        case D3D12_RESOURCE_BINDING_TIER_3: ret = "D3D12_RESOURCE_BINDING_TIER_3"; break;
    }
    return ret;
}

std::string ToString(const D3D12_CONSERVATIVE_RASTERIZATION_TIER value)
{
    const char* ret = "Unhandled D3D12_CONSERVATIVE_RASTERIZATION_TIER";
    switch (value) {
        case D3D12_CONSERVATIVE_RASTERIZATION_TIER_NOT_SUPPORTED: ret = "D3D12_CONSERVATIVE_RASTERIZATION_TIER_NOT_SUPPORTED"; break;
        case D3D12_CONSERVATIVE_RASTERIZATION_TIER_1: ret = "D3D12_CONSERVATIVE_RASTERIZATION_TIER_1"; break;
        case D3D12_CONSERVATIVE_RASTERIZATION_TIER_2: ret = "D3D12_CONSERVATIVE_RASTERIZATION_TIER_2"; break;
        case D3D12_CONSERVATIVE_RASTERIZATION_TIER_3: ret = "D3D12_CONSERVATIVE_RASTERIZATION_TIER_3"; break;
    }
    return ret;
}

std::string ToString(const D3D12_FORMAT_SUPPORT1 value)
{
    const char* ret = "Unhandled D3D12_FORMAT_SUPPORT1";
    switch (value) {
        case D3D12_FORMAT_SUPPORT1_NONE: ret = "D3D12_FORMAT_SUPPORT1_NONE"; break;
        case D3D12_FORMAT_SUPPORT1_BUFFER: ret = "D3D12_FORMAT_SUPPORT1_BUFFER"; break;
        case D3D12_FORMAT_SUPPORT1_IA_VERTEX_BUFFER: ret = "D3D12_FORMAT_SUPPORT1_IA_VERTEX_BUFFER"; break;
        case D3D12_FORMAT_SUPPORT1_IA_INDEX_BUFFER: ret = "D3D12_FORMAT_SUPPORT1_IA_INDEX_BUFFER"; break;
        case D3D12_FORMAT_SUPPORT1_SO_BUFFER: ret = "D3D12_FORMAT_SUPPORT1_SO_BUFFER"; break;
        case D3D12_FORMAT_SUPPORT1_TEXTURE1D: ret = "D3D12_FORMAT_SUPPORT1_TEXTURE1D"; break;
        case D3D12_FORMAT_SUPPORT1_TEXTURE2D: ret = "D3D12_FORMAT_SUPPORT1_TEXTURE2D"; break;
        case D3D12_FORMAT_SUPPORT1_TEXTURE3D: ret = "D3D12_FORMAT_SUPPORT1_TEXTURE3D"; break;
        case D3D12_FORMAT_SUPPORT1_TEXTURECUBE: ret = "D3D12_FORMAT_SUPPORT1_TEXTURECUBE"; break;
        case D3D12_FORMAT_SUPPORT1_SHADER_LOAD: ret = "D3D12_FORMAT_SUPPORT1_SHADER_LOAD"; break;
        case D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE: ret = "D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE"; break;
        case D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE_COMPARISON: ret = "D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE_COMPARISON"; break;
        case D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE_MONO_TEXT: ret = "D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE_MONO_TEXT"; break;
        case D3D12_FORMAT_SUPPORT1_MIP: ret = "D3D12_FORMAT_SUPPORT1_MIP"; break;
        case D3D12_FORMAT_SUPPORT1_RENDER_TARGET: ret = "D3D12_FORMAT_SUPPORT1_RENDER_TARGET"; break;
        case D3D12_FORMAT_SUPPORT1_BLENDABLE: ret = "D3D12_FORMAT_SUPPORT1_BLENDABLE"; break;
        case D3D12_FORMAT_SUPPORT1_DEPTH_STENCIL: ret = "D3D12_FORMAT_SUPPORT1_DEPTH_STENCIL"; break;
        case D3D12_FORMAT_SUPPORT1_MULTISAMPLE_RESOLVE: ret = "D3D12_FORMAT_SUPPORT1_MULTISAMPLE_RESOLVE"; break;
        case D3D12_FORMAT_SUPPORT1_DISPLAY: ret = "D3D12_FORMAT_SUPPORT1_DISPLAY"; break;
        case D3D12_FORMAT_SUPPORT1_CAST_WITHIN_BIT_LAYOUT: ret = "D3D12_FORMAT_SUPPORT1_CAST_WITHIN_BIT_LAYOUT"; break;
        case D3D12_FORMAT_SUPPORT1_MULTISAMPLE_RENDERTARGET: ret = "D3D12_FORMAT_SUPPORT1_MULTISAMPLE_RENDERTARGET"; break;
        case D3D12_FORMAT_SUPPORT1_MULTISAMPLE_LOAD: ret = "D3D12_FORMAT_SUPPORT1_MULTISAMPLE_LOAD"; break;
        case D3D12_FORMAT_SUPPORT1_SHADER_GATHER: ret = "D3D12_FORMAT_SUPPORT1_SHADER_GATHER"; break;
        case D3D12_FORMAT_SUPPORT1_BACK_BUFFER_CAST: ret = "D3D12_FORMAT_SUPPORT1_BACK_BUFFER_CAST"; break;
        case D3D12_FORMAT_SUPPORT1_TYPED_UNORDERED_ACCESS_VIEW: ret = "D3D12_FORMAT_SUPPORT1_TYPED_UNORDERED_ACCESS_VIEW"; break;
        case D3D12_FORMAT_SUPPORT1_SHADER_GATHER_COMPARISON: ret = "D3D12_FORMAT_SUPPORT1_SHADER_GATHER_COMPARISON"; break;
        case D3D12_FORMAT_SUPPORT1_DECODER_OUTPUT: ret = "D3D12_FORMAT_SUPPORT1_DECODER_OUTPUT"; break;
        case D3D12_FORMAT_SUPPORT1_VIDEO_PROCESSOR_OUTPUT: ret = "D3D12_FORMAT_SUPPORT1_VIDEO_PROCESSOR_OUTPUT"; break;
        case D3D12_FORMAT_SUPPORT1_VIDEO_PROCESSOR_INPUT: ret = "D3D12_FORMAT_SUPPORT1_VIDEO_PROCESSOR_INPUT"; break;
        case D3D12_FORMAT_SUPPORT1_VIDEO_ENCODER: ret = "D3D12_FORMAT_SUPPORT1_VIDEO_ENCODER"; break;
    }
    return ret;
}

std::string ToString_D3D12_FORMAT_SUPPORT1(const uint32_t flags)
{
    return BitmaskToString<D3D12_FORMAT_SUPPORT1>(flags);
}

std::string ToString(const D3D12_FORMAT_SUPPORT2 value)
{
    const char* ret = "Unhandled D3D12_FORMAT_SUPPORT2";
    switch (value) {
        case D3D12_FORMAT_SUPPORT2_NONE: ret = "D3D12_FORMAT_SUPPORT2_NONE"; break;
        case D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_ADD: ret = "D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_ADD"; break;
        case D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_BITWISE_OPS: ret = "D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_BITWISE_OPS"; break;
        case D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_COMPARE_STORE_OR_COMPARE_EXCHANGE: ret = "D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_COMPARE_STORE_OR_COMPARE_EXCHANGE"; break;
        case D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_EXCHANGE: ret = "D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_EXCHANGE"; break;
        case D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_SIGNED_MIN_OR_MAX: ret = "D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_SIGNED_MIN_OR_MAX"; break;
        case D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_UNSIGNED_MIN_OR_MAX: ret = "D3D12_FORMAT_SUPPORT2_UAV_ATOMIC_UNSIGNED_MIN_OR_MAX"; break;
        case D3D12_FORMAT_SUPPORT2_UAV_TYPED_LOAD: ret = "D3D12_FORMAT_SUPPORT2_UAV_TYPED_LOAD"; break;
        case D3D12_FORMAT_SUPPORT2_UAV_TYPED_STORE: ret = "D3D12_FORMAT_SUPPORT2_UAV_TYPED_STORE"; break;
        case D3D12_FORMAT_SUPPORT2_OUTPUT_MERGER_LOGIC_OP: ret = "D3D12_FORMAT_SUPPORT2_OUTPUT_MERGER_LOGIC_OP"; break;
        case D3D12_FORMAT_SUPPORT2_TILED: ret = "D3D12_FORMAT_SUPPORT2_TILED"; break;
        case D3D12_FORMAT_SUPPORT2_MULTIPLANE_OVERLAY: ret = "D3D12_FORMAT_SUPPORT2_MULTIPLANE_OVERLAY"; break;
        case D3D12_FORMAT_SUPPORT2_SAMPLER_FEEDBACK: ret = "D3D12_FORMAT_SUPPORT2_SAMPLER_FEEDBACK"; break;
    }
    return ret;
}

std::string ToString_D3D12_FORMAT_SUPPORT2(const uint32_t flags)
{
    return BitmaskToString<D3D12_FORMAT_SUPPORT2>(flags);
}

std::string ToString(const D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS value)
{
    const char* ret = "Unhandled D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS";
    switch (value) {
        case D3D12_MULTISAMPLE_QUALITY_LEVELS_FLAG_NONE: ret = "D3D12_MULTISAMPLE_QUALITY_LEVELS_FLAG_NONE"; break;
        case D3D12_MULTISAMPLE_QUALITY_LEVELS_FLAG_TILED_RESOURCE: ret = "D3D12_MULTISAMPLE_QUALITY_LEVELS_FLAG_TILED_RESOURCE"; break;
    }
    return ret;
}

std::string ToString_D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS>(flags);
}

std::string ToString(const D3D12_CROSS_NODE_SHARING_TIER value)
{
    const char* ret = "Unhandled D3D12_CROSS_NODE_SHARING_TIER";
    switch (value) {
        case D3D12_CROSS_NODE_SHARING_TIER_NOT_SUPPORTED: ret = "D3D12_CROSS_NODE_SHARING_TIER_NOT_SUPPORTED"; break;
        case D3D12_CROSS_NODE_SHARING_TIER_1_EMULATED: ret = "D3D12_CROSS_NODE_SHARING_TIER_1_EMULATED"; break;
        case D3D12_CROSS_NODE_SHARING_TIER_1: ret = "D3D12_CROSS_NODE_SHARING_TIER_1"; break;
        case D3D12_CROSS_NODE_SHARING_TIER_2: ret = "D3D12_CROSS_NODE_SHARING_TIER_2"; break;
        case D3D12_CROSS_NODE_SHARING_TIER_3: ret = "D3D12_CROSS_NODE_SHARING_TIER_3"; break;
    }
    return ret;
}

std::string ToString(const D3D12_RESOURCE_HEAP_TIER value)
{
    const char* ret = "Unhandled D3D12_RESOURCE_HEAP_TIER";
    switch (value) {
        case D3D12_RESOURCE_HEAP_TIER_1: ret = "D3D12_RESOURCE_HEAP_TIER_1"; break;
        case D3D12_RESOURCE_HEAP_TIER_2: ret = "D3D12_RESOURCE_HEAP_TIER_2"; break;
    }
    return ret;
}

std::string ToString(const D3D12_PROGRAMMABLE_SAMPLE_POSITIONS_TIER value)
{
    const char* ret = "Unhandled D3D12_PROGRAMMABLE_SAMPLE_POSITIONS_TIER";
    switch (value) {
        case D3D12_PROGRAMMABLE_SAMPLE_POSITIONS_TIER_NOT_SUPPORTED: ret = "D3D12_PROGRAMMABLE_SAMPLE_POSITIONS_TIER_NOT_SUPPORTED"; break;
        case D3D12_PROGRAMMABLE_SAMPLE_POSITIONS_TIER_1: ret = "D3D12_PROGRAMMABLE_SAMPLE_POSITIONS_TIER_1"; break;
        case D3D12_PROGRAMMABLE_SAMPLE_POSITIONS_TIER_2: ret = "D3D12_PROGRAMMABLE_SAMPLE_POSITIONS_TIER_2"; break;
    }
    return ret;
}

std::string ToString(const D3D12_VIEW_INSTANCING_TIER value)
{
    const char* ret = "Unhandled D3D12_VIEW_INSTANCING_TIER";
    switch (value) {
        case D3D12_VIEW_INSTANCING_TIER_NOT_SUPPORTED: ret = "D3D12_VIEW_INSTANCING_TIER_NOT_SUPPORTED"; break;
        case D3D12_VIEW_INSTANCING_TIER_1: ret = "D3D12_VIEW_INSTANCING_TIER_1"; break;
        case D3D12_VIEW_INSTANCING_TIER_2: ret = "D3D12_VIEW_INSTANCING_TIER_2"; break;
        case D3D12_VIEW_INSTANCING_TIER_3: ret = "D3D12_VIEW_INSTANCING_TIER_3"; break;
    }
    return ret;
}

std::string ToString(const D3D_ROOT_SIGNATURE_VERSION value)
{
    const char* ret = "Unhandled D3D_ROOT_SIGNATURE_VERSION";
    switch (value) {
        case D3D_ROOT_SIGNATURE_VERSION_1: ret = "D3D_ROOT_SIGNATURE_VERSION_1"; break;
        case D3D_ROOT_SIGNATURE_VERSION_1_1: ret = "D3D_ROOT_SIGNATURE_VERSION_1_1"; break;
        case D3D_ROOT_SIGNATURE_VERSION_1_2: ret = "D3D_ROOT_SIGNATURE_VERSION_1_2"; break;
    }
    return ret;
}

std::string ToString(const D3D_SHADER_MODEL value)
{
    const char* ret = "Unhandled D3D_SHADER_MODEL";
    switch (value) {
        case D3D_SHADER_MODEL_5_1: ret = "D3D_SHADER_MODEL_5_1"; break;
        case D3D_SHADER_MODEL_6_0: ret = "D3D_SHADER_MODEL_6_0"; break;
        case D3D_SHADER_MODEL_6_1: ret = "D3D_SHADER_MODEL_6_1"; break;
        case D3D_SHADER_MODEL_6_2: ret = "D3D_SHADER_MODEL_6_2"; break;
        case D3D_SHADER_MODEL_6_3: ret = "D3D_SHADER_MODEL_6_3"; break;
        case D3D_SHADER_MODEL_6_4: ret = "D3D_SHADER_MODEL_6_4"; break;
        case D3D_SHADER_MODEL_6_5: ret = "D3D_SHADER_MODEL_6_5"; break;
        case D3D_SHADER_MODEL_6_6: ret = "D3D_SHADER_MODEL_6_6"; break;
        case D3D_SHADER_MODEL_6_7: ret = "D3D_SHADER_MODEL_6_7"; break;
        case D3D_SHADER_MODEL_6_8: ret = "D3D_SHADER_MODEL_6_8"; break;
    }
    return ret;
}

std::string ToString(const D3D12_SHADER_CACHE_SUPPORT_FLAGS value)
{
    const char* ret = "Unhandled D3D12_SHADER_CACHE_SUPPORT_FLAGS";
    switch (value) {
        case D3D12_SHADER_CACHE_SUPPORT_NONE: ret = "D3D12_SHADER_CACHE_SUPPORT_NONE"; break;
        case D3D12_SHADER_CACHE_SUPPORT_SINGLE_PSO: ret = "D3D12_SHADER_CACHE_SUPPORT_SINGLE_PSO"; break;
        case D3D12_SHADER_CACHE_SUPPORT_LIBRARY: ret = "D3D12_SHADER_CACHE_SUPPORT_LIBRARY"; break;
        case D3D12_SHADER_CACHE_SUPPORT_AUTOMATIC_INPROC_CACHE: ret = "D3D12_SHADER_CACHE_SUPPORT_AUTOMATIC_INPROC_CACHE"; break;
        case D3D12_SHADER_CACHE_SUPPORT_AUTOMATIC_DISK_CACHE: ret = "D3D12_SHADER_CACHE_SUPPORT_AUTOMATIC_DISK_CACHE"; break;
        case D3D12_SHADER_CACHE_SUPPORT_DRIVER_MANAGED_CACHE: ret = "D3D12_SHADER_CACHE_SUPPORT_DRIVER_MANAGED_CACHE"; break;
        case D3D12_SHADER_CACHE_SUPPORT_SHADER_CONTROL_CLEAR: ret = "D3D12_SHADER_CACHE_SUPPORT_SHADER_CONTROL_CLEAR"; break;
        case D3D12_SHADER_CACHE_SUPPORT_SHADER_SESSION_DELETE: ret = "D3D12_SHADER_CACHE_SUPPORT_SHADER_SESSION_DELETE"; break;
    }
    return ret;
}

std::string ToString_D3D12_SHADER_CACHE_SUPPORT_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_SHADER_CACHE_SUPPORT_FLAGS>(flags);
}

std::string ToString(const D3D12_COMMAND_LIST_SUPPORT_FLAGS value)
{
    const char* ret = "Unhandled D3D12_COMMAND_LIST_SUPPORT_FLAGS";
    switch (value) {
        case D3D12_COMMAND_LIST_SUPPORT_FLAG_NONE: ret = "D3D12_COMMAND_LIST_SUPPORT_FLAG_NONE"; break;
        case D3D12_COMMAND_LIST_SUPPORT_FLAG_DIRECT: ret = "D3D12_COMMAND_LIST_SUPPORT_FLAG_DIRECT"; break;
        case D3D12_COMMAND_LIST_SUPPORT_FLAG_BUNDLE: ret = "D3D12_COMMAND_LIST_SUPPORT_FLAG_BUNDLE"; break;
        case D3D12_COMMAND_LIST_SUPPORT_FLAG_COMPUTE: ret = "D3D12_COMMAND_LIST_SUPPORT_FLAG_COMPUTE"; break;
        case D3D12_COMMAND_LIST_SUPPORT_FLAG_COPY: ret = "D3D12_COMMAND_LIST_SUPPORT_FLAG_COPY"; break;
        case D3D12_COMMAND_LIST_SUPPORT_FLAG_VIDEO_DECODE: ret = "D3D12_COMMAND_LIST_SUPPORT_FLAG_VIDEO_DECODE"; break;
        case D3D12_COMMAND_LIST_SUPPORT_FLAG_VIDEO_PROCESS: ret = "D3D12_COMMAND_LIST_SUPPORT_FLAG_VIDEO_PROCESS"; break;
        case D3D12_COMMAND_LIST_SUPPORT_FLAG_VIDEO_ENCODE: ret = "D3D12_COMMAND_LIST_SUPPORT_FLAG_VIDEO_ENCODE"; break;
    }
    return ret;
}

std::string ToString_D3D12_COMMAND_LIST_SUPPORT_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_COMMAND_LIST_SUPPORT_FLAGS>(flags);
}

std::string ToString(const D3D12_SHARED_RESOURCE_COMPATIBILITY_TIER value)
{
    const char* ret = "Unhandled D3D12_SHARED_RESOURCE_COMPATIBILITY_TIER";
    switch (value) {
        case D3D12_SHARED_RESOURCE_COMPATIBILITY_TIER_0: ret = "D3D12_SHARED_RESOURCE_COMPATIBILITY_TIER_0"; break;
        case D3D12_SHARED_RESOURCE_COMPATIBILITY_TIER_1: ret = "D3D12_SHARED_RESOURCE_COMPATIBILITY_TIER_1"; break;
        case D3D12_SHARED_RESOURCE_COMPATIBILITY_TIER_2: ret = "D3D12_SHARED_RESOURCE_COMPATIBILITY_TIER_2"; break;
    }
    return ret;
}

std::string ToString(const D3D12_HEAP_SERIALIZATION_TIER value)
{
    const char* ret = "Unhandled D3D12_HEAP_SERIALIZATION_TIER";
    switch (value) {
        case D3D12_HEAP_SERIALIZATION_TIER_0: ret = "D3D12_HEAP_SERIALIZATION_TIER_0"; break;
        case D3D12_HEAP_SERIALIZATION_TIER_10: ret = "D3D12_HEAP_SERIALIZATION_TIER_10"; break;
    }
    return ret;
}

std::string ToString(const D3D12_RENDER_PASS_TIER value)
{
    const char* ret = "Unhandled D3D12_RENDER_PASS_TIER";
    switch (value) {
        case D3D12_RENDER_PASS_TIER_0: ret = "D3D12_RENDER_PASS_TIER_0"; break;
        case D3D12_RENDER_PASS_TIER_1: ret = "D3D12_RENDER_PASS_TIER_1"; break;
        case D3D12_RENDER_PASS_TIER_2: ret = "D3D12_RENDER_PASS_TIER_2"; break;
    }
    return ret;
}

std::string ToString(const D3D12_RAYTRACING_TIER value)
{
    const char* ret = "Unhandled D3D12_RAYTRACING_TIER";
    switch (value) {
        case D3D12_RAYTRACING_TIER_NOT_SUPPORTED: ret = "D3D12_RAYTRACING_TIER_NOT_SUPPORTED"; break;
        case D3D12_RAYTRACING_TIER_1_0: ret = "D3D12_RAYTRACING_TIER_1_0"; break;
        case D3D12_RAYTRACING_TIER_1_1: ret = "D3D12_RAYTRACING_TIER_1_1"; break;
    }
    return ret;
}

std::string ToString(const D3D12_VARIABLE_SHADING_RATE_TIER value)
{
    const char* ret = "Unhandled D3D12_VARIABLE_SHADING_RATE_TIER";
    switch (value) {
        case D3D12_VARIABLE_SHADING_RATE_TIER_NOT_SUPPORTED: ret = "D3D12_VARIABLE_SHADING_RATE_TIER_NOT_SUPPORTED"; break;
        case D3D12_VARIABLE_SHADING_RATE_TIER_1: ret = "D3D12_VARIABLE_SHADING_RATE_TIER_1"; break;
        case D3D12_VARIABLE_SHADING_RATE_TIER_2: ret = "D3D12_VARIABLE_SHADING_RATE_TIER_2"; break;
    }
    return ret;
}

std::string ToString(const D3D12_MESH_SHADER_TIER value)
{
    const char* ret = "Unhandled D3D12_MESH_SHADER_TIER";
    switch (value) {
        case D3D12_MESH_SHADER_TIER_NOT_SUPPORTED: ret = "D3D12_MESH_SHADER_TIER_NOT_SUPPORTED"; break;
        case D3D12_MESH_SHADER_TIER_1: ret = "D3D12_MESH_SHADER_TIER_1"; break;
    }
    return ret;
}

std::string ToString(const D3D12_SAMPLER_FEEDBACK_TIER value)
{
    const char* ret = "Unhandled D3D12_SAMPLER_FEEDBACK_TIER";
    switch (value) {
        case D3D12_SAMPLER_FEEDBACK_TIER_NOT_SUPPORTED: ret = "D3D12_SAMPLER_FEEDBACK_TIER_NOT_SUPPORTED"; break;
        case D3D12_SAMPLER_FEEDBACK_TIER_0_9: ret = "D3D12_SAMPLER_FEEDBACK_TIER_0_9"; break;
        case D3D12_SAMPLER_FEEDBACK_TIER_1_0: ret = "D3D12_SAMPLER_FEEDBACK_TIER_1_0"; break;
    }
    return ret;
}

std::string ToString(const D3D12_WAVE_MMA_TIER value)
{
    const char* ret = "Unhandled D3D12_WAVE_MMA_TIER";
    switch (value) {
        case D3D12_WAVE_MMA_TIER_NOT_SUPPORTED: ret = "D3D12_WAVE_MMA_TIER_NOT_SUPPORTED"; break;
        case D3D12_WAVE_MMA_TIER_1_0: ret = "D3D12_WAVE_MMA_TIER_1_0"; break;
    }
    return ret;
}

std::string ToString(const D3D12_TRI_STATE value)
{
    const char* ret = "Unhandled D3D12_TRI_STATE";
    switch (value) {
        case D3D12_TRI_STATE_UNKNOWN: ret = "D3D12_TRI_STATE_UNKNOWN"; break;
        case D3D12_TRI_STATE_FALSE: ret = "D3D12_TRI_STATE_FALSE"; break;
        case D3D12_TRI_STATE_TRUE: ret = "D3D12_TRI_STATE_TRUE"; break;
    }
    return ret;
}

std::string ToString(const D3D12_HEAP_TYPE value)
{
    const char* ret = "Unhandled D3D12_HEAP_TYPE";
    switch (value) {
        case D3D12_HEAP_TYPE_DEFAULT: ret = "D3D12_HEAP_TYPE_DEFAULT"; break;
        case D3D12_HEAP_TYPE_UPLOAD: ret = "D3D12_HEAP_TYPE_UPLOAD"; break;
        case D3D12_HEAP_TYPE_READBACK: ret = "D3D12_HEAP_TYPE_READBACK"; break;
        case D3D12_HEAP_TYPE_CUSTOM: ret = "D3D12_HEAP_TYPE_CUSTOM"; break;
        case D3D12_HEAP_TYPE_GPU_UPLOAD: ret = "D3D12_HEAP_TYPE_GPU_UPLOAD"; break;
    }
    return ret;
}

std::string ToString(const D3D12_CPU_PAGE_PROPERTY value)
{
    const char* ret = "Unhandled D3D12_CPU_PAGE_PROPERTY";
    switch (value) {
        case D3D12_CPU_PAGE_PROPERTY_UNKNOWN: ret = "D3D12_CPU_PAGE_PROPERTY_UNKNOWN"; break;
        case D3D12_CPU_PAGE_PROPERTY_NOT_AVAILABLE: ret = "D3D12_CPU_PAGE_PROPERTY_NOT_AVAILABLE"; break;
        case D3D12_CPU_PAGE_PROPERTY_WRITE_COMBINE: ret = "D3D12_CPU_PAGE_PROPERTY_WRITE_COMBINE"; break;
        case D3D12_CPU_PAGE_PROPERTY_WRITE_BACK: ret = "D3D12_CPU_PAGE_PROPERTY_WRITE_BACK"; break;
    }
    return ret;
}

std::string ToString(const D3D12_MEMORY_POOL value)
{
    const char* ret = "Unhandled D3D12_MEMORY_POOL";
    switch (value) {
        case D3D12_MEMORY_POOL_UNKNOWN: ret = "D3D12_MEMORY_POOL_UNKNOWN"; break;
        case D3D12_MEMORY_POOL_L0: ret = "D3D12_MEMORY_POOL_L0"; break;
        case D3D12_MEMORY_POOL_L1: ret = "D3D12_MEMORY_POOL_L1"; break;
    }
    return ret;
}

std::string ToString(const D3D12_HEAP_FLAGS value)
{
    const char* ret = "Unhandled D3D12_HEAP_FLAGS";
    switch (value) {
        case D3D12_HEAP_FLAG_NONE: ret = "D3D12_HEAP_FLAG_NONE"; break;
        case D3D12_HEAP_FLAG_SHARED: ret = "D3D12_HEAP_FLAG_SHARED"; break;
        case D3D12_HEAP_FLAG_DENY_BUFFERS: ret = "D3D12_HEAP_FLAG_DENY_BUFFERS"; break;
        case D3D12_HEAP_FLAG_ALLOW_DISPLAY: ret = "D3D12_HEAP_FLAG_ALLOW_DISPLAY"; break;
        case D3D12_HEAP_FLAG_SHARED_CROSS_ADAPTER: ret = "D3D12_HEAP_FLAG_SHARED_CROSS_ADAPTER"; break;
        case D3D12_HEAP_FLAG_DENY_RT_DS_TEXTURES: ret = "D3D12_HEAP_FLAG_DENY_RT_DS_TEXTURES"; break;
        case D3D12_HEAP_FLAG_DENY_NON_RT_DS_TEXTURES: ret = "D3D12_HEAP_FLAG_DENY_NON_RT_DS_TEXTURES"; break;
        case D3D12_HEAP_FLAG_HARDWARE_PROTECTED: ret = "D3D12_HEAP_FLAG_HARDWARE_PROTECTED"; break;
        case D3D12_HEAP_FLAG_ALLOW_WRITE_WATCH: ret = "D3D12_HEAP_FLAG_ALLOW_WRITE_WATCH"; break;
        case D3D12_HEAP_FLAG_ALLOW_SHADER_ATOMICS: ret = "D3D12_HEAP_FLAG_ALLOW_SHADER_ATOMICS"; break;
        case D3D12_HEAP_FLAG_CREATE_NOT_RESIDENT: ret = "D3D12_HEAP_FLAG_CREATE_NOT_RESIDENT"; break;
        case D3D12_HEAP_FLAG_CREATE_NOT_ZEROED: ret = "D3D12_HEAP_FLAG_CREATE_NOT_ZEROED"; break;
        case D3D12_HEAP_FLAG_TOOLS_USE_MANUAL_WRITE_TRACKING: ret = "D3D12_HEAP_FLAG_TOOLS_USE_MANUAL_WRITE_TRACKING"; break;
        case D3D12_HEAP_FLAG_ALLOW_ONLY_BUFFERS: ret = "D3D12_HEAP_FLAG_ALLOW_ONLY_BUFFERS"; break;
        case D3D12_HEAP_FLAG_ALLOW_ONLY_NON_RT_DS_TEXTURES: ret = "D3D12_HEAP_FLAG_ALLOW_ONLY_NON_RT_DS_TEXTURES"; break;
        case D3D12_HEAP_FLAG_ALLOW_ONLY_RT_DS_TEXTURES: ret = "D3D12_HEAP_FLAG_ALLOW_ONLY_RT_DS_TEXTURES"; break;
    }
    return ret;
}

std::string ToString_D3D12_HEAP_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_HEAP_FLAGS>(flags);
}

std::string ToString(const D3D12_RESOURCE_DIMENSION value)
{
    const char* ret = "Unhandled D3D12_RESOURCE_DIMENSION";
    switch (value) {
        case D3D12_RESOURCE_DIMENSION_UNKNOWN: ret = "D3D12_RESOURCE_DIMENSION_UNKNOWN"; break;
        case D3D12_RESOURCE_DIMENSION_BUFFER: ret = "D3D12_RESOURCE_DIMENSION_BUFFER"; break;
        case D3D12_RESOURCE_DIMENSION_TEXTURE1D: ret = "D3D12_RESOURCE_DIMENSION_TEXTURE1D"; break;
        case D3D12_RESOURCE_DIMENSION_TEXTURE2D: ret = "D3D12_RESOURCE_DIMENSION_TEXTURE2D"; break;
        case D3D12_RESOURCE_DIMENSION_TEXTURE3D: ret = "D3D12_RESOURCE_DIMENSION_TEXTURE3D"; break;
    }
    return ret;
}

std::string ToString(const D3D12_TEXTURE_LAYOUT value)
{
    const char* ret = "Unhandled D3D12_TEXTURE_LAYOUT";
    switch (value) {
        case D3D12_TEXTURE_LAYOUT_UNKNOWN: ret = "D3D12_TEXTURE_LAYOUT_UNKNOWN"; break;
        case D3D12_TEXTURE_LAYOUT_ROW_MAJOR: ret = "D3D12_TEXTURE_LAYOUT_ROW_MAJOR"; break;
        case D3D12_TEXTURE_LAYOUT_64KB_UNDEFINED_SWIZZLE: ret = "D3D12_TEXTURE_LAYOUT_64KB_UNDEFINED_SWIZZLE"; break;
        case D3D12_TEXTURE_LAYOUT_64KB_STANDARD_SWIZZLE: ret = "D3D12_TEXTURE_LAYOUT_64KB_STANDARD_SWIZZLE"; break;
    }
    return ret;
}

std::string ToString(const D3D12_RESOURCE_FLAGS value)
{
    const char* ret = "Unhandled D3D12_RESOURCE_FLAGS";
    switch (value) {
        case D3D12_RESOURCE_FLAG_NONE: ret = "D3D12_RESOURCE_FLAG_NONE"; break;
        case D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET: ret = "D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET"; break;
        case D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL: ret = "D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL"; break;
        case D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS: ret = "D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS"; break;
        case D3D12_RESOURCE_FLAG_DENY_SHADER_RESOURCE: ret = "D3D12_RESOURCE_FLAG_DENY_SHADER_RESOURCE"; break;
        case D3D12_RESOURCE_FLAG_ALLOW_CROSS_ADAPTER: ret = "D3D12_RESOURCE_FLAG_ALLOW_CROSS_ADAPTER"; break;
        case D3D12_RESOURCE_FLAG_ALLOW_SIMULTANEOUS_ACCESS: ret = "D3D12_RESOURCE_FLAG_ALLOW_SIMULTANEOUS_ACCESS"; break;
        case D3D12_RESOURCE_FLAG_VIDEO_DECODE_REFERENCE_ONLY: ret = "D3D12_RESOURCE_FLAG_VIDEO_DECODE_REFERENCE_ONLY"; break;
        case D3D12_RESOURCE_FLAG_VIDEO_ENCODE_REFERENCE_ONLY: ret = "D3D12_RESOURCE_FLAG_VIDEO_ENCODE_REFERENCE_ONLY"; break;
        case D3D12_RESOURCE_FLAG_RAYTRACING_ACCELERATION_STRUCTURE: ret = "D3D12_RESOURCE_FLAG_RAYTRACING_ACCELERATION_STRUCTURE"; break;
    }
    return ret;
}

std::string ToString_D3D12_RESOURCE_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_RESOURCE_FLAGS>(flags);
}

std::string ToString(const D3D12_TILE_RANGE_FLAGS value)
{
    const char* ret = "Unhandled D3D12_TILE_RANGE_FLAGS";
    switch (value) {
        case D3D12_TILE_RANGE_FLAG_NONE: ret = "D3D12_TILE_RANGE_FLAG_NONE"; break;
        case D3D12_TILE_RANGE_FLAG_NULL: ret = "D3D12_TILE_RANGE_FLAG_NULL"; break;
        case D3D12_TILE_RANGE_FLAG_SKIP: ret = "D3D12_TILE_RANGE_FLAG_SKIP"; break;
        case D3D12_TILE_RANGE_FLAG_REUSE_SINGLE_TILE: ret = "D3D12_TILE_RANGE_FLAG_REUSE_SINGLE_TILE"; break;
    }
    return ret;
}

std::string ToString_D3D12_TILE_RANGE_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_TILE_RANGE_FLAGS>(flags);
}

std::string ToString(const D3D12_TILE_MAPPING_FLAGS value)
{
    const char* ret = "Unhandled D3D12_TILE_MAPPING_FLAGS";
    switch (value) {
        case D3D12_TILE_MAPPING_FLAG_NONE: ret = "D3D12_TILE_MAPPING_FLAG_NONE"; break;
        case D3D12_TILE_MAPPING_FLAG_NO_HAZARD: ret = "D3D12_TILE_MAPPING_FLAG_NO_HAZARD"; break;
    }
    return ret;
}

std::string ToString_D3D12_TILE_MAPPING_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_TILE_MAPPING_FLAGS>(flags);
}

std::string ToString(const D3D12_TILE_COPY_FLAGS value)
{
    const char* ret = "Unhandled D3D12_TILE_COPY_FLAGS";
    switch (value) {
        case D3D12_TILE_COPY_FLAG_NONE: ret = "D3D12_TILE_COPY_FLAG_NONE"; break;
        case D3D12_TILE_COPY_FLAG_NO_HAZARD: ret = "D3D12_TILE_COPY_FLAG_NO_HAZARD"; break;
        case D3D12_TILE_COPY_FLAG_LINEAR_BUFFER_TO_SWIZZLED_TILED_RESOURCE: ret = "D3D12_TILE_COPY_FLAG_LINEAR_BUFFER_TO_SWIZZLED_TILED_RESOURCE"; break;
        case D3D12_TILE_COPY_FLAG_SWIZZLED_TILED_RESOURCE_TO_LINEAR_BUFFER: ret = "D3D12_TILE_COPY_FLAG_SWIZZLED_TILED_RESOURCE_TO_LINEAR_BUFFER"; break;
    }
    return ret;
}

std::string ToString_D3D12_TILE_COPY_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_TILE_COPY_FLAGS>(flags);
}

std::string ToString(const D3D12_RESOURCE_STATES value)
{
    const char* ret = "Unhandled D3D12_RESOURCE_STATES";
    switch (value) {
        case D3D12_RESOURCE_STATE_COMMON: ret = "D3D12_RESOURCE_STATE_COMMON"; break;
        case D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER: ret = "D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER"; break;
        case D3D12_RESOURCE_STATE_INDEX_BUFFER: ret = "D3D12_RESOURCE_STATE_INDEX_BUFFER"; break;
        case D3D12_RESOURCE_STATE_RENDER_TARGET: ret = "D3D12_RESOURCE_STATE_RENDER_TARGET"; break;
        case D3D12_RESOURCE_STATE_UNORDERED_ACCESS: ret = "D3D12_RESOURCE_STATE_UNORDERED_ACCESS"; break;
        case D3D12_RESOURCE_STATE_DEPTH_WRITE: ret = "D3D12_RESOURCE_STATE_DEPTH_WRITE"; break;
        case D3D12_RESOURCE_STATE_DEPTH_READ: ret = "D3D12_RESOURCE_STATE_DEPTH_READ"; break;
        case D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE: ret = "D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE"; break;
        case D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE: ret = "D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE"; break;
        case D3D12_RESOURCE_STATE_STREAM_OUT: ret = "D3D12_RESOURCE_STATE_STREAM_OUT"; break;
        case D3D12_RESOURCE_STATE_INDIRECT_ARGUMENT: ret = "D3D12_RESOURCE_STATE_INDIRECT_ARGUMENT"; break;
        case D3D12_RESOURCE_STATE_COPY_DEST: ret = "D3D12_RESOURCE_STATE_COPY_DEST"; break;
        case D3D12_RESOURCE_STATE_COPY_SOURCE: ret = "D3D12_RESOURCE_STATE_COPY_SOURCE"; break;
        case D3D12_RESOURCE_STATE_RESOLVE_DEST: ret = "D3D12_RESOURCE_STATE_RESOLVE_DEST"; break;
        case D3D12_RESOURCE_STATE_RESOLVE_SOURCE: ret = "D3D12_RESOURCE_STATE_RESOLVE_SOURCE"; break;
        case D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE: ret = "D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE"; break;
        case D3D12_RESOURCE_STATE_SHADING_RATE_SOURCE: ret = "D3D12_RESOURCE_STATE_SHADING_RATE_SOURCE"; break;
        case D3D12_RESOURCE_STATE_GENERIC_READ: ret = "D3D12_RESOURCE_STATE_GENERIC_READ"; break;
        case D3D12_RESOURCE_STATE_ALL_SHADER_RESOURCE: ret = "D3D12_RESOURCE_STATE_ALL_SHADER_RESOURCE"; break;
        case D3D12_RESOURCE_STATE_VIDEO_DECODE_READ: ret = "D3D12_RESOURCE_STATE_VIDEO_DECODE_READ"; break;
        case D3D12_RESOURCE_STATE_VIDEO_DECODE_WRITE: ret = "D3D12_RESOURCE_STATE_VIDEO_DECODE_WRITE"; break;
        case D3D12_RESOURCE_STATE_VIDEO_PROCESS_READ: ret = "D3D12_RESOURCE_STATE_VIDEO_PROCESS_READ"; break;
        case D3D12_RESOURCE_STATE_VIDEO_PROCESS_WRITE: ret = "D3D12_RESOURCE_STATE_VIDEO_PROCESS_WRITE"; break;
        case D3D12_RESOURCE_STATE_VIDEO_ENCODE_READ: ret = "D3D12_RESOURCE_STATE_VIDEO_ENCODE_READ"; break;
        case D3D12_RESOURCE_STATE_VIDEO_ENCODE_WRITE: ret = "D3D12_RESOURCE_STATE_VIDEO_ENCODE_WRITE"; break;
    }
    return ret;
}

std::string ToString_D3D12_RESOURCE_STATES(const uint32_t flags)
{
    return BitmaskToString<D3D12_RESOURCE_STATES>(flags);
}

std::string ToString(const D3D12_RESOURCE_BARRIER_TYPE value)
{
    const char* ret = "Unhandled D3D12_RESOURCE_BARRIER_TYPE";
    switch (value) {
        case D3D12_RESOURCE_BARRIER_TYPE_TRANSITION: ret = "D3D12_RESOURCE_BARRIER_TYPE_TRANSITION"; break;
        case D3D12_RESOURCE_BARRIER_TYPE_ALIASING: ret = "D3D12_RESOURCE_BARRIER_TYPE_ALIASING"; break;
        case D3D12_RESOURCE_BARRIER_TYPE_UAV: ret = "D3D12_RESOURCE_BARRIER_TYPE_UAV"; break;
    }
    return ret;
}

std::string ToString(const D3D12_RESOURCE_BARRIER_FLAGS value)
{
    const char* ret = "Unhandled D3D12_RESOURCE_BARRIER_FLAGS";
    switch (value) {
        case D3D12_RESOURCE_BARRIER_FLAG_NONE: ret = "D3D12_RESOURCE_BARRIER_FLAG_NONE"; break;
        case D3D12_RESOURCE_BARRIER_FLAG_BEGIN_ONLY: ret = "D3D12_RESOURCE_BARRIER_FLAG_BEGIN_ONLY"; break;
        case D3D12_RESOURCE_BARRIER_FLAG_END_ONLY: ret = "D3D12_RESOURCE_BARRIER_FLAG_END_ONLY"; break;
    }
    return ret;
}

std::string ToString_D3D12_RESOURCE_BARRIER_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_RESOURCE_BARRIER_FLAGS>(flags);
}

std::string ToString(const D3D12_TEXTURE_COPY_TYPE value)
{
    const char* ret = "Unhandled D3D12_TEXTURE_COPY_TYPE";
    switch (value) {
        case D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX: ret = "D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX"; break;
        case D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT: ret = "D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT"; break;
    }
    return ret;
}

std::string ToString(const D3D12_RESOLVE_MODE value)
{
    const char* ret = "Unhandled D3D12_RESOLVE_MODE";
    switch (value) {
        case D3D12_RESOLVE_MODE_DECOMPRESS: ret = "D3D12_RESOLVE_MODE_DECOMPRESS"; break;
        case D3D12_RESOLVE_MODE_MIN: ret = "D3D12_RESOLVE_MODE_MIN"; break;
        case D3D12_RESOLVE_MODE_MAX: ret = "D3D12_RESOLVE_MODE_MAX"; break;
        case D3D12_RESOLVE_MODE_AVERAGE: ret = "D3D12_RESOLVE_MODE_AVERAGE"; break;
        case D3D12_RESOLVE_MODE_ENCODE_SAMPLER_FEEDBACK: ret = "D3D12_RESOLVE_MODE_ENCODE_SAMPLER_FEEDBACK"; break;
        case D3D12_RESOLVE_MODE_DECODE_SAMPLER_FEEDBACK: ret = "D3D12_RESOLVE_MODE_DECODE_SAMPLER_FEEDBACK"; break;
    }
    return ret;
}

std::string ToString(const D3D12_VIEW_INSTANCING_FLAGS value)
{
    const char* ret = "Unhandled D3D12_VIEW_INSTANCING_FLAGS";
    switch (value) {
        case D3D12_VIEW_INSTANCING_FLAG_NONE: ret = "D3D12_VIEW_INSTANCING_FLAG_NONE"; break;
        case D3D12_VIEW_INSTANCING_FLAG_ENABLE_VIEW_INSTANCE_MASKING: ret = "D3D12_VIEW_INSTANCING_FLAG_ENABLE_VIEW_INSTANCE_MASKING"; break;
    }
    return ret;
}

std::string ToString_D3D12_VIEW_INSTANCING_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_VIEW_INSTANCING_FLAGS>(flags);
}

std::string ToString(const D3D12_SHADER_COMPONENT_MAPPING value)
{
    const char* ret = "Unhandled D3D12_SHADER_COMPONENT_MAPPING";
    switch (value) {
        case D3D12_SHADER_COMPONENT_MAPPING_FROM_MEMORY_COMPONENT_0: ret = "D3D12_SHADER_COMPONENT_MAPPING_FROM_MEMORY_COMPONENT_0"; break;
        case D3D12_SHADER_COMPONENT_MAPPING_FROM_MEMORY_COMPONENT_1: ret = "D3D12_SHADER_COMPONENT_MAPPING_FROM_MEMORY_COMPONENT_1"; break;
        case D3D12_SHADER_COMPONENT_MAPPING_FROM_MEMORY_COMPONENT_2: ret = "D3D12_SHADER_COMPONENT_MAPPING_FROM_MEMORY_COMPONENT_2"; break;
        case D3D12_SHADER_COMPONENT_MAPPING_FROM_MEMORY_COMPONENT_3: ret = "D3D12_SHADER_COMPONENT_MAPPING_FROM_MEMORY_COMPONENT_3"; break;
        case D3D12_SHADER_COMPONENT_MAPPING_FORCE_VALUE_0: ret = "D3D12_SHADER_COMPONENT_MAPPING_FORCE_VALUE_0"; break;
        case D3D12_SHADER_COMPONENT_MAPPING_FORCE_VALUE_1: ret = "D3D12_SHADER_COMPONENT_MAPPING_FORCE_VALUE_1"; break;
    }
    return ret;
}

std::string ToString(const D3D12_BUFFER_SRV_FLAGS value)
{
    const char* ret = "Unhandled D3D12_BUFFER_SRV_FLAGS";
    switch (value) {
        case D3D12_BUFFER_SRV_FLAG_NONE: ret = "D3D12_BUFFER_SRV_FLAG_NONE"; break;
        case D3D12_BUFFER_SRV_FLAG_RAW: ret = "D3D12_BUFFER_SRV_FLAG_RAW"; break;
    }
    return ret;
}

std::string ToString_D3D12_BUFFER_SRV_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_BUFFER_SRV_FLAGS>(flags);
}

std::string ToString(const D3D12_SRV_DIMENSION value)
{
    const char* ret = "Unhandled D3D12_SRV_DIMENSION";
    switch (value) {
        case D3D12_SRV_DIMENSION_UNKNOWN: ret = "D3D12_SRV_DIMENSION_UNKNOWN"; break;
        case D3D12_SRV_DIMENSION_BUFFER: ret = "D3D12_SRV_DIMENSION_BUFFER"; break;
        case D3D12_SRV_DIMENSION_TEXTURE1D: ret = "D3D12_SRV_DIMENSION_TEXTURE1D"; break;
        case D3D12_SRV_DIMENSION_TEXTURE1DARRAY: ret = "D3D12_SRV_DIMENSION_TEXTURE1DARRAY"; break;
        case D3D12_SRV_DIMENSION_TEXTURE2D: ret = "D3D12_SRV_DIMENSION_TEXTURE2D"; break;
        case D3D12_SRV_DIMENSION_TEXTURE2DARRAY: ret = "D3D12_SRV_DIMENSION_TEXTURE2DARRAY"; break;
        case D3D12_SRV_DIMENSION_TEXTURE2DMS: ret = "D3D12_SRV_DIMENSION_TEXTURE2DMS"; break;
        case D3D12_SRV_DIMENSION_TEXTURE2DMSARRAY: ret = "D3D12_SRV_DIMENSION_TEXTURE2DMSARRAY"; break;
        case D3D12_SRV_DIMENSION_TEXTURE3D: ret = "D3D12_SRV_DIMENSION_TEXTURE3D"; break;
        case D3D12_SRV_DIMENSION_TEXTURECUBE: ret = "D3D12_SRV_DIMENSION_TEXTURECUBE"; break;
        case D3D12_SRV_DIMENSION_TEXTURECUBEARRAY: ret = "D3D12_SRV_DIMENSION_TEXTURECUBEARRAY"; break;
        case D3D12_SRV_DIMENSION_RAYTRACING_ACCELERATION_STRUCTURE: ret = "D3D12_SRV_DIMENSION_RAYTRACING_ACCELERATION_STRUCTURE"; break;
    }
    return ret;
}

std::string ToString(const D3D12_FILTER value)
{
    const char* ret = "Unhandled D3D12_FILTER";
    switch (value) {
        case D3D12_FILTER_MIN_MAG_MIP_POINT: ret = "D3D12_FILTER_MIN_MAG_MIP_POINT"; break;
        case D3D12_FILTER_MIN_MAG_POINT_MIP_LINEAR: ret = "D3D12_FILTER_MIN_MAG_POINT_MIP_LINEAR"; break;
        case D3D12_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT: ret = "D3D12_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT"; break;
        case D3D12_FILTER_MIN_POINT_MAG_MIP_LINEAR: ret = "D3D12_FILTER_MIN_POINT_MAG_MIP_LINEAR"; break;
        case D3D12_FILTER_MIN_LINEAR_MAG_MIP_POINT: ret = "D3D12_FILTER_MIN_LINEAR_MAG_MIP_POINT"; break;
        case D3D12_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR: ret = "D3D12_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR"; break;
        case D3D12_FILTER_MIN_MAG_LINEAR_MIP_POINT: ret = "D3D12_FILTER_MIN_MAG_LINEAR_MIP_POINT"; break;
        case D3D12_FILTER_MIN_MAG_MIP_LINEAR: ret = "D3D12_FILTER_MIN_MAG_MIP_LINEAR"; break;
        case D3D12_FILTER_MIN_MAG_ANISOTROPIC_MIP_POINT: ret = "D3D12_FILTER_MIN_MAG_ANISOTROPIC_MIP_POINT"; break;
        case D3D12_FILTER_ANISOTROPIC: ret = "D3D12_FILTER_ANISOTROPIC"; break;
        case D3D12_FILTER_COMPARISON_MIN_MAG_MIP_POINT: ret = "D3D12_FILTER_COMPARISON_MIN_MAG_MIP_POINT"; break;
        case D3D12_FILTER_COMPARISON_MIN_MAG_POINT_MIP_LINEAR: ret = "D3D12_FILTER_COMPARISON_MIN_MAG_POINT_MIP_LINEAR"; break;
        case D3D12_FILTER_COMPARISON_MIN_POINT_MAG_LINEAR_MIP_POINT: ret = "D3D12_FILTER_COMPARISON_MIN_POINT_MAG_LINEAR_MIP_POINT"; break;
        case D3D12_FILTER_COMPARISON_MIN_POINT_MAG_MIP_LINEAR: ret = "D3D12_FILTER_COMPARISON_MIN_POINT_MAG_MIP_LINEAR"; break;
        case D3D12_FILTER_COMPARISON_MIN_LINEAR_MAG_MIP_POINT: ret = "D3D12_FILTER_COMPARISON_MIN_LINEAR_MAG_MIP_POINT"; break;
        case D3D12_FILTER_COMPARISON_MIN_LINEAR_MAG_POINT_MIP_LINEAR: ret = "D3D12_FILTER_COMPARISON_MIN_LINEAR_MAG_POINT_MIP_LINEAR"; break;
        case D3D12_FILTER_COMPARISON_MIN_MAG_LINEAR_MIP_POINT: ret = "D3D12_FILTER_COMPARISON_MIN_MAG_LINEAR_MIP_POINT"; break;
        case D3D12_FILTER_COMPARISON_MIN_MAG_MIP_LINEAR: ret = "D3D12_FILTER_COMPARISON_MIN_MAG_MIP_LINEAR"; break;
        case D3D12_FILTER_COMPARISON_MIN_MAG_ANISOTROPIC_MIP_POINT: ret = "D3D12_FILTER_COMPARISON_MIN_MAG_ANISOTROPIC_MIP_POINT"; break;
        case D3D12_FILTER_COMPARISON_ANISOTROPIC: ret = "D3D12_FILTER_COMPARISON_ANISOTROPIC"; break;
        case D3D12_FILTER_MINIMUM_MIN_MAG_MIP_POINT: ret = "D3D12_FILTER_MINIMUM_MIN_MAG_MIP_POINT"; break;
        case D3D12_FILTER_MINIMUM_MIN_MAG_POINT_MIP_LINEAR: ret = "D3D12_FILTER_MINIMUM_MIN_MAG_POINT_MIP_LINEAR"; break;
        case D3D12_FILTER_MINIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT: ret = "D3D12_FILTER_MINIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT"; break;
        case D3D12_FILTER_MINIMUM_MIN_POINT_MAG_MIP_LINEAR: ret = "D3D12_FILTER_MINIMUM_MIN_POINT_MAG_MIP_LINEAR"; break;
        case D3D12_FILTER_MINIMUM_MIN_LINEAR_MAG_MIP_POINT: ret = "D3D12_FILTER_MINIMUM_MIN_LINEAR_MAG_MIP_POINT"; break;
        case D3D12_FILTER_MINIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR: ret = "D3D12_FILTER_MINIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR"; break;
        case D3D12_FILTER_MINIMUM_MIN_MAG_LINEAR_MIP_POINT: ret = "D3D12_FILTER_MINIMUM_MIN_MAG_LINEAR_MIP_POINT"; break;
        case D3D12_FILTER_MINIMUM_MIN_MAG_MIP_LINEAR: ret = "D3D12_FILTER_MINIMUM_MIN_MAG_MIP_LINEAR"; break;
        case D3D12_FILTER_MINIMUM_MIN_MAG_ANISOTROPIC_MIP_POINT: ret = "D3D12_FILTER_MINIMUM_MIN_MAG_ANISOTROPIC_MIP_POINT"; break;
        case D3D12_FILTER_MINIMUM_ANISOTROPIC: ret = "D3D12_FILTER_MINIMUM_ANISOTROPIC"; break;
        case D3D12_FILTER_MAXIMUM_MIN_MAG_MIP_POINT: ret = "D3D12_FILTER_MAXIMUM_MIN_MAG_MIP_POINT"; break;
        case D3D12_FILTER_MAXIMUM_MIN_MAG_POINT_MIP_LINEAR: ret = "D3D12_FILTER_MAXIMUM_MIN_MAG_POINT_MIP_LINEAR"; break;
        case D3D12_FILTER_MAXIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT: ret = "D3D12_FILTER_MAXIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT"; break;
        case D3D12_FILTER_MAXIMUM_MIN_POINT_MAG_MIP_LINEAR: ret = "D3D12_FILTER_MAXIMUM_MIN_POINT_MAG_MIP_LINEAR"; break;
        case D3D12_FILTER_MAXIMUM_MIN_LINEAR_MAG_MIP_POINT: ret = "D3D12_FILTER_MAXIMUM_MIN_LINEAR_MAG_MIP_POINT"; break;
        case D3D12_FILTER_MAXIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR: ret = "D3D12_FILTER_MAXIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR"; break;
        case D3D12_FILTER_MAXIMUM_MIN_MAG_LINEAR_MIP_POINT: ret = "D3D12_FILTER_MAXIMUM_MIN_MAG_LINEAR_MIP_POINT"; break;
        case D3D12_FILTER_MAXIMUM_MIN_MAG_MIP_LINEAR: ret = "D3D12_FILTER_MAXIMUM_MIN_MAG_MIP_LINEAR"; break;
        case D3D12_FILTER_MAXIMUM_MIN_MAG_ANISOTROPIC_MIP_POINT: ret = "D3D12_FILTER_MAXIMUM_MIN_MAG_ANISOTROPIC_MIP_POINT"; break;
        case D3D12_FILTER_MAXIMUM_ANISOTROPIC: ret = "D3D12_FILTER_MAXIMUM_ANISOTROPIC"; break;
    }
    return ret;
}

std::string ToString(const D3D12_FILTER_TYPE value)
{
    const char* ret = "Unhandled D3D12_FILTER_TYPE";
    switch (value) {
        case D3D12_FILTER_TYPE_POINT: ret = "D3D12_FILTER_TYPE_POINT"; break;
        case D3D12_FILTER_TYPE_LINEAR: ret = "D3D12_FILTER_TYPE_LINEAR"; break;
    }
    return ret;
}

std::string ToString(const D3D12_FILTER_REDUCTION_TYPE value)
{
    const char* ret = "Unhandled D3D12_FILTER_REDUCTION_TYPE";
    switch (value) {
        case D3D12_FILTER_REDUCTION_TYPE_STANDARD: ret = "D3D12_FILTER_REDUCTION_TYPE_STANDARD"; break;
        case D3D12_FILTER_REDUCTION_TYPE_COMPARISON: ret = "D3D12_FILTER_REDUCTION_TYPE_COMPARISON"; break;
        case D3D12_FILTER_REDUCTION_TYPE_MINIMUM: ret = "D3D12_FILTER_REDUCTION_TYPE_MINIMUM"; break;
        case D3D12_FILTER_REDUCTION_TYPE_MAXIMUM: ret = "D3D12_FILTER_REDUCTION_TYPE_MAXIMUM"; break;
    }
    return ret;
}

std::string ToString(const D3D12_TEXTURE_ADDRESS_MODE value)
{
    const char* ret = "Unhandled D3D12_TEXTURE_ADDRESS_MODE";
    switch (value) {
        case D3D12_TEXTURE_ADDRESS_MODE_WRAP: ret = "D3D12_TEXTURE_ADDRESS_MODE_WRAP"; break;
        case D3D12_TEXTURE_ADDRESS_MODE_MIRROR: ret = "D3D12_TEXTURE_ADDRESS_MODE_MIRROR"; break;
        case D3D12_TEXTURE_ADDRESS_MODE_CLAMP: ret = "D3D12_TEXTURE_ADDRESS_MODE_CLAMP"; break;
        case D3D12_TEXTURE_ADDRESS_MODE_BORDER: ret = "D3D12_TEXTURE_ADDRESS_MODE_BORDER"; break;
        case D3D12_TEXTURE_ADDRESS_MODE_MIRROR_ONCE: ret = "D3D12_TEXTURE_ADDRESS_MODE_MIRROR_ONCE"; break;
    }
    return ret;
}

std::string ToString(const D3D12_SAMPLER_FLAGS value)
{
    const char* ret = "Unhandled D3D12_SAMPLER_FLAGS";
    switch (value) {
        case D3D12_SAMPLER_FLAG_NONE: ret = "D3D12_SAMPLER_FLAG_NONE"; break;
        case D3D12_SAMPLER_FLAG_UINT_BORDER_COLOR: ret = "D3D12_SAMPLER_FLAG_UINT_BORDER_COLOR"; break;
        case D3D12_SAMPLER_FLAG_NON_NORMALIZED_COORDINATES: ret = "D3D12_SAMPLER_FLAG_NON_NORMALIZED_COORDINATES"; break;
    }
    return ret;
}

std::string ToString_D3D12_SAMPLER_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_SAMPLER_FLAGS>(flags);
}

std::string ToString(const D3D12_BUFFER_UAV_FLAGS value)
{
    const char* ret = "Unhandled D3D12_BUFFER_UAV_FLAGS";
    switch (value) {
        case D3D12_BUFFER_UAV_FLAG_NONE: ret = "D3D12_BUFFER_UAV_FLAG_NONE"; break;
        case D3D12_BUFFER_UAV_FLAG_RAW: ret = "D3D12_BUFFER_UAV_FLAG_RAW"; break;
    }
    return ret;
}

std::string ToString_D3D12_BUFFER_UAV_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_BUFFER_UAV_FLAGS>(flags);
}

std::string ToString(const D3D12_UAV_DIMENSION value)
{
    const char* ret = "Unhandled D3D12_UAV_DIMENSION";
    switch (value) {
        case D3D12_UAV_DIMENSION_UNKNOWN: ret = "D3D12_UAV_DIMENSION_UNKNOWN"; break;
        case D3D12_UAV_DIMENSION_BUFFER: ret = "D3D12_UAV_DIMENSION_BUFFER"; break;
        case D3D12_UAV_DIMENSION_TEXTURE1D: ret = "D3D12_UAV_DIMENSION_TEXTURE1D"; break;
        case D3D12_UAV_DIMENSION_TEXTURE1DARRAY: ret = "D3D12_UAV_DIMENSION_TEXTURE1DARRAY"; break;
        case D3D12_UAV_DIMENSION_TEXTURE2D: ret = "D3D12_UAV_DIMENSION_TEXTURE2D"; break;
        case D3D12_UAV_DIMENSION_TEXTURE2DARRAY: ret = "D3D12_UAV_DIMENSION_TEXTURE2DARRAY"; break;
        case D3D12_UAV_DIMENSION_TEXTURE2DMS: ret = "D3D12_UAV_DIMENSION_TEXTURE2DMS"; break;
        case D3D12_UAV_DIMENSION_TEXTURE2DMSARRAY: ret = "D3D12_UAV_DIMENSION_TEXTURE2DMSARRAY"; break;
        case D3D12_UAV_DIMENSION_TEXTURE3D: ret = "D3D12_UAV_DIMENSION_TEXTURE3D"; break;
    }
    return ret;
}

std::string ToString(const D3D12_RTV_DIMENSION value)
{
    const char* ret = "Unhandled D3D12_RTV_DIMENSION";
    switch (value) {
        case D3D12_RTV_DIMENSION_UNKNOWN: ret = "D3D12_RTV_DIMENSION_UNKNOWN"; break;
        case D3D12_RTV_DIMENSION_BUFFER: ret = "D3D12_RTV_DIMENSION_BUFFER"; break;
        case D3D12_RTV_DIMENSION_TEXTURE1D: ret = "D3D12_RTV_DIMENSION_TEXTURE1D"; break;
        case D3D12_RTV_DIMENSION_TEXTURE1DARRAY: ret = "D3D12_RTV_DIMENSION_TEXTURE1DARRAY"; break;
        case D3D12_RTV_DIMENSION_TEXTURE2D: ret = "D3D12_RTV_DIMENSION_TEXTURE2D"; break;
        case D3D12_RTV_DIMENSION_TEXTURE2DARRAY: ret = "D3D12_RTV_DIMENSION_TEXTURE2DARRAY"; break;
        case D3D12_RTV_DIMENSION_TEXTURE2DMS: ret = "D3D12_RTV_DIMENSION_TEXTURE2DMS"; break;
        case D3D12_RTV_DIMENSION_TEXTURE2DMSARRAY: ret = "D3D12_RTV_DIMENSION_TEXTURE2DMSARRAY"; break;
        case D3D12_RTV_DIMENSION_TEXTURE3D: ret = "D3D12_RTV_DIMENSION_TEXTURE3D"; break;
    }
    return ret;
}

std::string ToString(const D3D12_DSV_FLAGS value)
{
    const char* ret = "Unhandled D3D12_DSV_FLAGS";
    switch (value) {
        case D3D12_DSV_FLAG_NONE: ret = "D3D12_DSV_FLAG_NONE"; break;
        case D3D12_DSV_FLAG_READ_ONLY_DEPTH: ret = "D3D12_DSV_FLAG_READ_ONLY_DEPTH"; break;
        case D3D12_DSV_FLAG_READ_ONLY_STENCIL: ret = "D3D12_DSV_FLAG_READ_ONLY_STENCIL"; break;
    }
    return ret;
}

std::string ToString_D3D12_DSV_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_DSV_FLAGS>(flags);
}

std::string ToString(const D3D12_DSV_DIMENSION value)
{
    const char* ret = "Unhandled D3D12_DSV_DIMENSION";
    switch (value) {
        case D3D12_DSV_DIMENSION_UNKNOWN: ret = "D3D12_DSV_DIMENSION_UNKNOWN"; break;
        case D3D12_DSV_DIMENSION_TEXTURE1D: ret = "D3D12_DSV_DIMENSION_TEXTURE1D"; break;
        case D3D12_DSV_DIMENSION_TEXTURE1DARRAY: ret = "D3D12_DSV_DIMENSION_TEXTURE1DARRAY"; break;
        case D3D12_DSV_DIMENSION_TEXTURE2D: ret = "D3D12_DSV_DIMENSION_TEXTURE2D"; break;
        case D3D12_DSV_DIMENSION_TEXTURE2DARRAY: ret = "D3D12_DSV_DIMENSION_TEXTURE2DARRAY"; break;
        case D3D12_DSV_DIMENSION_TEXTURE2DMS: ret = "D3D12_DSV_DIMENSION_TEXTURE2DMS"; break;
        case D3D12_DSV_DIMENSION_TEXTURE2DMSARRAY: ret = "D3D12_DSV_DIMENSION_TEXTURE2DMSARRAY"; break;
    }
    return ret;
}

std::string ToString(const D3D12_CLEAR_FLAGS value)
{
    const char* ret = "Unhandled D3D12_CLEAR_FLAGS";
    switch (value) {
        case D3D12_CLEAR_FLAG_DEPTH: ret = "D3D12_CLEAR_FLAG_DEPTH"; break;
        case D3D12_CLEAR_FLAG_STENCIL: ret = "D3D12_CLEAR_FLAG_STENCIL"; break;
    }
    return ret;
}

std::string ToString_D3D12_CLEAR_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_CLEAR_FLAGS>(flags);
}

std::string ToString(const D3D12_FENCE_FLAGS value)
{
    const char* ret = "Unhandled D3D12_FENCE_FLAGS";
    switch (value) {
        case D3D12_FENCE_FLAG_NONE: ret = "D3D12_FENCE_FLAG_NONE"; break;
        case D3D12_FENCE_FLAG_SHARED: ret = "D3D12_FENCE_FLAG_SHARED"; break;
        case D3D12_FENCE_FLAG_SHARED_CROSS_ADAPTER: ret = "D3D12_FENCE_FLAG_SHARED_CROSS_ADAPTER"; break;
        case D3D12_FENCE_FLAG_NON_MONITORED: ret = "D3D12_FENCE_FLAG_NON_MONITORED"; break;
    }
    return ret;
}

std::string ToString_D3D12_FENCE_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_FENCE_FLAGS>(flags);
}

std::string ToString(const D3D12_DESCRIPTOR_HEAP_TYPE value)
{
    const char* ret = "Unhandled D3D12_DESCRIPTOR_HEAP_TYPE";
    switch (value) {
        case D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV: ret = "D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV"; break;
        case D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER: ret = "D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER"; break;
        case D3D12_DESCRIPTOR_HEAP_TYPE_RTV: ret = "D3D12_DESCRIPTOR_HEAP_TYPE_RTV"; break;
        case D3D12_DESCRIPTOR_HEAP_TYPE_DSV: ret = "D3D12_DESCRIPTOR_HEAP_TYPE_DSV"; break;
        case D3D12_DESCRIPTOR_HEAP_TYPE_NUM_TYPES: ret = "D3D12_DESCRIPTOR_HEAP_TYPE_NUM_TYPES"; break;
    }
    return ret;
}

std::string ToString(const D3D12_DESCRIPTOR_HEAP_FLAGS value)
{
    const char* ret = "Unhandled D3D12_DESCRIPTOR_HEAP_FLAGS";
    switch (value) {
        case D3D12_DESCRIPTOR_HEAP_FLAG_NONE: ret = "D3D12_DESCRIPTOR_HEAP_FLAG_NONE"; break;
        case D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE: ret = "D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE"; break;
    }
    return ret;
}

std::string ToString_D3D12_DESCRIPTOR_HEAP_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_DESCRIPTOR_HEAP_FLAGS>(flags);
}

std::string ToString(const D3D12_DESCRIPTOR_RANGE_TYPE value)
{
    const char* ret = "Unhandled D3D12_DESCRIPTOR_RANGE_TYPE";
    switch (value) {
        case D3D12_DESCRIPTOR_RANGE_TYPE_SRV: ret = "D3D12_DESCRIPTOR_RANGE_TYPE_SRV"; break;
        case D3D12_DESCRIPTOR_RANGE_TYPE_UAV: ret = "D3D12_DESCRIPTOR_RANGE_TYPE_UAV"; break;
        case D3D12_DESCRIPTOR_RANGE_TYPE_CBV: ret = "D3D12_DESCRIPTOR_RANGE_TYPE_CBV"; break;
        case D3D12_DESCRIPTOR_RANGE_TYPE_SAMPLER: ret = "D3D12_DESCRIPTOR_RANGE_TYPE_SAMPLER"; break;
    }
    return ret;
}

std::string ToString(const D3D12_SHADER_VISIBILITY value)
{
    const char* ret = "Unhandled D3D12_SHADER_VISIBILITY";
    switch (value) {
        case D3D12_SHADER_VISIBILITY_ALL: ret = "D3D12_SHADER_VISIBILITY_ALL"; break;
        case D3D12_SHADER_VISIBILITY_VERTEX: ret = "D3D12_SHADER_VISIBILITY_VERTEX"; break;
        case D3D12_SHADER_VISIBILITY_HULL: ret = "D3D12_SHADER_VISIBILITY_HULL"; break;
        case D3D12_SHADER_VISIBILITY_DOMAIN: ret = "D3D12_SHADER_VISIBILITY_DOMAIN"; break;
        case D3D12_SHADER_VISIBILITY_GEOMETRY: ret = "D3D12_SHADER_VISIBILITY_GEOMETRY"; break;
        case D3D12_SHADER_VISIBILITY_PIXEL: ret = "D3D12_SHADER_VISIBILITY_PIXEL"; break;
        case D3D12_SHADER_VISIBILITY_AMPLIFICATION: ret = "D3D12_SHADER_VISIBILITY_AMPLIFICATION"; break;
        case D3D12_SHADER_VISIBILITY_MESH: ret = "D3D12_SHADER_VISIBILITY_MESH"; break;
    }
    return ret;
}

std::string ToString(const D3D12_ROOT_PARAMETER_TYPE value)
{
    const char* ret = "Unhandled D3D12_ROOT_PARAMETER_TYPE";
    switch (value) {
        case D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE: ret = "D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE"; break;
        case D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS: ret = "D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS"; break;
        case D3D12_ROOT_PARAMETER_TYPE_CBV: ret = "D3D12_ROOT_PARAMETER_TYPE_CBV"; break;
        case D3D12_ROOT_PARAMETER_TYPE_SRV: ret = "D3D12_ROOT_PARAMETER_TYPE_SRV"; break;
        case D3D12_ROOT_PARAMETER_TYPE_UAV: ret = "D3D12_ROOT_PARAMETER_TYPE_UAV"; break;
    }
    return ret;
}

std::string ToString(const D3D12_ROOT_SIGNATURE_FLAGS value)
{
    const char* ret = "Unhandled D3D12_ROOT_SIGNATURE_FLAGS";
    switch (value) {
        case D3D12_ROOT_SIGNATURE_FLAG_NONE: ret = "D3D12_ROOT_SIGNATURE_FLAG_NONE"; break;
        case D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT: ret = "D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT"; break;
        case D3D12_ROOT_SIGNATURE_FLAG_DENY_VERTEX_SHADER_ROOT_ACCESS: ret = "D3D12_ROOT_SIGNATURE_FLAG_DENY_VERTEX_SHADER_ROOT_ACCESS"; break;
        case D3D12_ROOT_SIGNATURE_FLAG_DENY_HULL_SHADER_ROOT_ACCESS: ret = "D3D12_ROOT_SIGNATURE_FLAG_DENY_HULL_SHADER_ROOT_ACCESS"; break;
        case D3D12_ROOT_SIGNATURE_FLAG_DENY_DOMAIN_SHADER_ROOT_ACCESS: ret = "D3D12_ROOT_SIGNATURE_FLAG_DENY_DOMAIN_SHADER_ROOT_ACCESS"; break;
        case D3D12_ROOT_SIGNATURE_FLAG_DENY_GEOMETRY_SHADER_ROOT_ACCESS: ret = "D3D12_ROOT_SIGNATURE_FLAG_DENY_GEOMETRY_SHADER_ROOT_ACCESS"; break;
        case D3D12_ROOT_SIGNATURE_FLAG_DENY_PIXEL_SHADER_ROOT_ACCESS: ret = "D3D12_ROOT_SIGNATURE_FLAG_DENY_PIXEL_SHADER_ROOT_ACCESS"; break;
        case D3D12_ROOT_SIGNATURE_FLAG_ALLOW_STREAM_OUTPUT: ret = "D3D12_ROOT_SIGNATURE_FLAG_ALLOW_STREAM_OUTPUT"; break;
        case D3D12_ROOT_SIGNATURE_FLAG_LOCAL_ROOT_SIGNATURE: ret = "D3D12_ROOT_SIGNATURE_FLAG_LOCAL_ROOT_SIGNATURE"; break;
        case D3D12_ROOT_SIGNATURE_FLAG_DENY_AMPLIFICATION_SHADER_ROOT_ACCESS: ret = "D3D12_ROOT_SIGNATURE_FLAG_DENY_AMPLIFICATION_SHADER_ROOT_ACCESS"; break;
        case D3D12_ROOT_SIGNATURE_FLAG_DENY_MESH_SHADER_ROOT_ACCESS: ret = "D3D12_ROOT_SIGNATURE_FLAG_DENY_MESH_SHADER_ROOT_ACCESS"; break;
        case D3D12_ROOT_SIGNATURE_FLAG_CBV_SRV_UAV_HEAP_DIRECTLY_INDEXED: ret = "D3D12_ROOT_SIGNATURE_FLAG_CBV_SRV_UAV_HEAP_DIRECTLY_INDEXED"; break;
        case D3D12_ROOT_SIGNATURE_FLAG_SAMPLER_HEAP_DIRECTLY_INDEXED: ret = "D3D12_ROOT_SIGNATURE_FLAG_SAMPLER_HEAP_DIRECTLY_INDEXED"; break;
    }
    return ret;
}

std::string ToString_D3D12_ROOT_SIGNATURE_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_ROOT_SIGNATURE_FLAGS>(flags);
}

std::string ToString(const D3D12_STATIC_BORDER_COLOR value)
{
    const char* ret = "Unhandled D3D12_STATIC_BORDER_COLOR";
    switch (value) {
        case D3D12_STATIC_BORDER_COLOR_TRANSPARENT_BLACK: ret = "D3D12_STATIC_BORDER_COLOR_TRANSPARENT_BLACK"; break;
        case D3D12_STATIC_BORDER_COLOR_OPAQUE_BLACK: ret = "D3D12_STATIC_BORDER_COLOR_OPAQUE_BLACK"; break;
        case D3D12_STATIC_BORDER_COLOR_OPAQUE_WHITE: ret = "D3D12_STATIC_BORDER_COLOR_OPAQUE_WHITE"; break;
        case D3D12_STATIC_BORDER_COLOR_OPAQUE_BLACK_UINT: ret = "D3D12_STATIC_BORDER_COLOR_OPAQUE_BLACK_UINT"; break;
        case D3D12_STATIC_BORDER_COLOR_OPAQUE_WHITE_UINT: ret = "D3D12_STATIC_BORDER_COLOR_OPAQUE_WHITE_UINT"; break;
    }
    return ret;
}

std::string ToString(const D3D12_DESCRIPTOR_RANGE_FLAGS value)
{
    const char* ret = "Unhandled D3D12_DESCRIPTOR_RANGE_FLAGS";
    switch (value) {
        case D3D12_DESCRIPTOR_RANGE_FLAG_NONE: ret = "D3D12_DESCRIPTOR_RANGE_FLAG_NONE"; break;
        case D3D12_DESCRIPTOR_RANGE_FLAG_DESCRIPTORS_VOLATILE: ret = "D3D12_DESCRIPTOR_RANGE_FLAG_DESCRIPTORS_VOLATILE"; break;
        case D3D12_DESCRIPTOR_RANGE_FLAG_DATA_VOLATILE: ret = "D3D12_DESCRIPTOR_RANGE_FLAG_DATA_VOLATILE"; break;
        case D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC_WHILE_SET_AT_EXECUTE: ret = "D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC_WHILE_SET_AT_EXECUTE"; break;
        case D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC: ret = "D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC"; break;
        case D3D12_DESCRIPTOR_RANGE_FLAG_DESCRIPTORS_STATIC_KEEPING_BUFFER_BOUNDS_CHECKS: ret = "D3D12_DESCRIPTOR_RANGE_FLAG_DESCRIPTORS_STATIC_KEEPING_BUFFER_BOUNDS_CHECKS"; break;
    }
    return ret;
}

std::string ToString_D3D12_DESCRIPTOR_RANGE_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_DESCRIPTOR_RANGE_FLAGS>(flags);
}

std::string ToString(const D3D12_ROOT_DESCRIPTOR_FLAGS value)
{
    const char* ret = "Unhandled D3D12_ROOT_DESCRIPTOR_FLAGS";
    switch (value) {
        case D3D12_ROOT_DESCRIPTOR_FLAG_NONE: ret = "D3D12_ROOT_DESCRIPTOR_FLAG_NONE"; break;
        case D3D12_ROOT_DESCRIPTOR_FLAG_DATA_VOLATILE: ret = "D3D12_ROOT_DESCRIPTOR_FLAG_DATA_VOLATILE"; break;
        case D3D12_ROOT_DESCRIPTOR_FLAG_DATA_STATIC_WHILE_SET_AT_EXECUTE: ret = "D3D12_ROOT_DESCRIPTOR_FLAG_DATA_STATIC_WHILE_SET_AT_EXECUTE"; break;
        case D3D12_ROOT_DESCRIPTOR_FLAG_DATA_STATIC: ret = "D3D12_ROOT_DESCRIPTOR_FLAG_DATA_STATIC"; break;
    }
    return ret;
}

std::string ToString_D3D12_ROOT_DESCRIPTOR_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_ROOT_DESCRIPTOR_FLAGS>(flags);
}

std::string ToString(const D3D12_QUERY_HEAP_TYPE value)
{
    const char* ret = "Unhandled D3D12_QUERY_HEAP_TYPE";
    switch (value) {
        case D3D12_QUERY_HEAP_TYPE_OCCLUSION: ret = "D3D12_QUERY_HEAP_TYPE_OCCLUSION"; break;
        case D3D12_QUERY_HEAP_TYPE_TIMESTAMP: ret = "D3D12_QUERY_HEAP_TYPE_TIMESTAMP"; break;
        case D3D12_QUERY_HEAP_TYPE_PIPELINE_STATISTICS: ret = "D3D12_QUERY_HEAP_TYPE_PIPELINE_STATISTICS"; break;
        case D3D12_QUERY_HEAP_TYPE_SO_STATISTICS: ret = "D3D12_QUERY_HEAP_TYPE_SO_STATISTICS"; break;
        case D3D12_QUERY_HEAP_TYPE_VIDEO_DECODE_STATISTICS: ret = "D3D12_QUERY_HEAP_TYPE_VIDEO_DECODE_STATISTICS"; break;
        case D3D12_QUERY_HEAP_TYPE_COPY_QUEUE_TIMESTAMP: ret = "D3D12_QUERY_HEAP_TYPE_COPY_QUEUE_TIMESTAMP"; break;
        case D3D12_QUERY_HEAP_TYPE_PIPELINE_STATISTICS1: ret = "D3D12_QUERY_HEAP_TYPE_PIPELINE_STATISTICS1"; break;
    }
    return ret;
}

std::string ToString(const D3D12_QUERY_TYPE value)
{
    const char* ret = "Unhandled D3D12_QUERY_TYPE";
    switch (value) {
        case D3D12_QUERY_TYPE_OCCLUSION: ret = "D3D12_QUERY_TYPE_OCCLUSION"; break;
        case D3D12_QUERY_TYPE_BINARY_OCCLUSION: ret = "D3D12_QUERY_TYPE_BINARY_OCCLUSION"; break;
        case D3D12_QUERY_TYPE_TIMESTAMP: ret = "D3D12_QUERY_TYPE_TIMESTAMP"; break;
        case D3D12_QUERY_TYPE_PIPELINE_STATISTICS: ret = "D3D12_QUERY_TYPE_PIPELINE_STATISTICS"; break;
        case D3D12_QUERY_TYPE_SO_STATISTICS_STREAM0: ret = "D3D12_QUERY_TYPE_SO_STATISTICS_STREAM0"; break;
        case D3D12_QUERY_TYPE_SO_STATISTICS_STREAM1: ret = "D3D12_QUERY_TYPE_SO_STATISTICS_STREAM1"; break;
        case D3D12_QUERY_TYPE_SO_STATISTICS_STREAM2: ret = "D3D12_QUERY_TYPE_SO_STATISTICS_STREAM2"; break;
        case D3D12_QUERY_TYPE_SO_STATISTICS_STREAM3: ret = "D3D12_QUERY_TYPE_SO_STATISTICS_STREAM3"; break;
        case D3D12_QUERY_TYPE_VIDEO_DECODE_STATISTICS: ret = "D3D12_QUERY_TYPE_VIDEO_DECODE_STATISTICS"; break;
        case D3D12_QUERY_TYPE_PIPELINE_STATISTICS1: ret = "D3D12_QUERY_TYPE_PIPELINE_STATISTICS1"; break;
    }
    return ret;
}

std::string ToString(const D3D12_PREDICATION_OP value)
{
    const char* ret = "Unhandled D3D12_PREDICATION_OP";
    switch (value) {
        case D3D12_PREDICATION_OP_EQUAL_ZERO: ret = "D3D12_PREDICATION_OP_EQUAL_ZERO"; break;
        case D3D12_PREDICATION_OP_NOT_EQUAL_ZERO: ret = "D3D12_PREDICATION_OP_NOT_EQUAL_ZERO"; break;
    }
    return ret;
}

std::string ToString(const D3D12_INDIRECT_ARGUMENT_TYPE value)
{
    const char* ret = "Unhandled D3D12_INDIRECT_ARGUMENT_TYPE";
    switch (value) {
        case D3D12_INDIRECT_ARGUMENT_TYPE_DRAW: ret = "D3D12_INDIRECT_ARGUMENT_TYPE_DRAW"; break;
        case D3D12_INDIRECT_ARGUMENT_TYPE_DRAW_INDEXED: ret = "D3D12_INDIRECT_ARGUMENT_TYPE_DRAW_INDEXED"; break;
        case D3D12_INDIRECT_ARGUMENT_TYPE_DISPATCH: ret = "D3D12_INDIRECT_ARGUMENT_TYPE_DISPATCH"; break;
        case D3D12_INDIRECT_ARGUMENT_TYPE_VERTEX_BUFFER_VIEW: ret = "D3D12_INDIRECT_ARGUMENT_TYPE_VERTEX_BUFFER_VIEW"; break;
        case D3D12_INDIRECT_ARGUMENT_TYPE_INDEX_BUFFER_VIEW: ret = "D3D12_INDIRECT_ARGUMENT_TYPE_INDEX_BUFFER_VIEW"; break;
        case D3D12_INDIRECT_ARGUMENT_TYPE_CONSTANT: ret = "D3D12_INDIRECT_ARGUMENT_TYPE_CONSTANT"; break;
        case D3D12_INDIRECT_ARGUMENT_TYPE_CONSTANT_BUFFER_VIEW: ret = "D3D12_INDIRECT_ARGUMENT_TYPE_CONSTANT_BUFFER_VIEW"; break;
        case D3D12_INDIRECT_ARGUMENT_TYPE_SHADER_RESOURCE_VIEW: ret = "D3D12_INDIRECT_ARGUMENT_TYPE_SHADER_RESOURCE_VIEW"; break;
        case D3D12_INDIRECT_ARGUMENT_TYPE_UNORDERED_ACCESS_VIEW: ret = "D3D12_INDIRECT_ARGUMENT_TYPE_UNORDERED_ACCESS_VIEW"; break;
        case D3D12_INDIRECT_ARGUMENT_TYPE_DISPATCH_RAYS: ret = "D3D12_INDIRECT_ARGUMENT_TYPE_DISPATCH_RAYS"; break;
        case D3D12_INDIRECT_ARGUMENT_TYPE_DISPATCH_MESH: ret = "D3D12_INDIRECT_ARGUMENT_TYPE_DISPATCH_MESH"; break;
    }
    return ret;
}

std::string ToString(const D3D12_WRITEBUFFERIMMEDIATE_MODE value)
{
    const char* ret = "Unhandled D3D12_WRITEBUFFERIMMEDIATE_MODE";
    switch (value) {
        case D3D12_WRITEBUFFERIMMEDIATE_MODE_DEFAULT: ret = "D3D12_WRITEBUFFERIMMEDIATE_MODE_DEFAULT"; break;
        case D3D12_WRITEBUFFERIMMEDIATE_MODE_MARKER_IN: ret = "D3D12_WRITEBUFFERIMMEDIATE_MODE_MARKER_IN"; break;
        case D3D12_WRITEBUFFERIMMEDIATE_MODE_MARKER_OUT: ret = "D3D12_WRITEBUFFERIMMEDIATE_MODE_MARKER_OUT"; break;
    }
    return ret;
}

std::string ToString(const D3D12_MULTIPLE_FENCE_WAIT_FLAGS value)
{
    const char* ret = "Unhandled D3D12_MULTIPLE_FENCE_WAIT_FLAGS";
    switch (value) {
        case D3D12_MULTIPLE_FENCE_WAIT_FLAG_NONE: ret = "D3D12_MULTIPLE_FENCE_WAIT_FLAG_NONE"; break;
        case D3D12_MULTIPLE_FENCE_WAIT_FLAG_ANY: ret = "D3D12_MULTIPLE_FENCE_WAIT_FLAG_ANY"; break;
    }
    return ret;
}

std::string ToString_D3D12_MULTIPLE_FENCE_WAIT_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_MULTIPLE_FENCE_WAIT_FLAGS>(flags);
}

std::string ToString(const D3D12_RESIDENCY_PRIORITY value)
{
    const char* ret = "Unhandled D3D12_RESIDENCY_PRIORITY";
    switch (value) {
        case D3D12_RESIDENCY_PRIORITY_MINIMUM: ret = "D3D12_RESIDENCY_PRIORITY_MINIMUM"; break;
        case D3D12_RESIDENCY_PRIORITY_LOW: ret = "D3D12_RESIDENCY_PRIORITY_LOW"; break;
        case D3D12_RESIDENCY_PRIORITY_NORMAL: ret = "D3D12_RESIDENCY_PRIORITY_NORMAL"; break;
        case D3D12_RESIDENCY_PRIORITY_HIGH: ret = "D3D12_RESIDENCY_PRIORITY_HIGH"; break;
        case D3D12_RESIDENCY_PRIORITY_MAXIMUM: ret = "D3D12_RESIDENCY_PRIORITY_MAXIMUM"; break;
    }
    return ret;
}

std::string ToString(const D3D12_RESIDENCY_FLAGS value)
{
    const char* ret = "Unhandled D3D12_RESIDENCY_FLAGS";
    switch (value) {
        case D3D12_RESIDENCY_FLAG_NONE: ret = "D3D12_RESIDENCY_FLAG_NONE"; break;
        case D3D12_RESIDENCY_FLAG_DENY_OVERBUDGET: ret = "D3D12_RESIDENCY_FLAG_DENY_OVERBUDGET"; break;
    }
    return ret;
}

std::string ToString_D3D12_RESIDENCY_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_RESIDENCY_FLAGS>(flags);
}

std::string ToString(const D3D12_COMMAND_LIST_FLAGS value)
{
    const char* ret = "Unhandled D3D12_COMMAND_LIST_FLAGS";
    switch (value) {
        case D3D12_COMMAND_LIST_FLAG_NONE: ret = "D3D12_COMMAND_LIST_FLAG_NONE"; break;
    }
    return ret;
}

std::string ToString_D3D12_COMMAND_LIST_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_COMMAND_LIST_FLAGS>(flags);
}

std::string ToString(const D3D12_COMMAND_POOL_FLAGS value)
{
    const char* ret = "Unhandled D3D12_COMMAND_POOL_FLAGS";
    switch (value) {
        case D3D12_COMMAND_POOL_FLAG_NONE: ret = "D3D12_COMMAND_POOL_FLAG_NONE"; break;
    }
    return ret;
}

std::string ToString_D3D12_COMMAND_POOL_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_COMMAND_POOL_FLAGS>(flags);
}

std::string ToString(const D3D12_COMMAND_RECORDER_FLAGS value)
{
    const char* ret = "Unhandled D3D12_COMMAND_RECORDER_FLAGS";
    switch (value) {
        case D3D12_COMMAND_RECORDER_FLAG_NONE: ret = "D3D12_COMMAND_RECORDER_FLAG_NONE"; break;
    }
    return ret;
}

std::string ToString_D3D12_COMMAND_RECORDER_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_COMMAND_RECORDER_FLAGS>(flags);
}

std::string ToString(const D3D12_PROTECTED_SESSION_STATUS value)
{
    const char* ret = "Unhandled D3D12_PROTECTED_SESSION_STATUS";
    switch (value) {
        case D3D12_PROTECTED_SESSION_STATUS_OK: ret = "D3D12_PROTECTED_SESSION_STATUS_OK"; break;
        case D3D12_PROTECTED_SESSION_STATUS_INVALID: ret = "D3D12_PROTECTED_SESSION_STATUS_INVALID"; break;
    }
    return ret;
}

std::string ToString_D3D12_PROTECTED_SESSION_STATUS(const uint32_t flags)
{
    return BitmaskToString<D3D12_PROTECTED_SESSION_STATUS>(flags);
}

std::string ToString(const D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAGS value)
{
    const char* ret = "Unhandled D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAGS";
    switch (value) {
        case D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAG_NONE: ret = "D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAG_NONE"; break;
        case D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAG_SUPPORTED: ret = "D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAG_SUPPORTED"; break;
    }
    return ret;
}

std::string ToString_D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAGS>(flags);
}

std::string ToString(const D3D12_PROTECTED_RESOURCE_SESSION_FLAGS value)
{
    const char* ret = "Unhandled D3D12_PROTECTED_RESOURCE_SESSION_FLAGS";
    switch (value) {
        case D3D12_PROTECTED_RESOURCE_SESSION_FLAG_NONE: ret = "D3D12_PROTECTED_RESOURCE_SESSION_FLAG_NONE"; break;
    }
    return ret;
}

std::string ToString_D3D12_PROTECTED_RESOURCE_SESSION_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_PROTECTED_RESOURCE_SESSION_FLAGS>(flags);
}

std::string ToString(const D3D12_LIFETIME_STATE value)
{
    const char* ret = "Unhandled D3D12_LIFETIME_STATE";
    switch (value) {
        case D3D12_LIFETIME_STATE_IN_USE: ret = "D3D12_LIFETIME_STATE_IN_USE"; break;
        case D3D12_LIFETIME_STATE_NOT_IN_USE: ret = "D3D12_LIFETIME_STATE_NOT_IN_USE"; break;
    }
    return ret;
}

std::string ToString(const D3D12_META_COMMAND_PARAMETER_TYPE value)
{
    const char* ret = "Unhandled D3D12_META_COMMAND_PARAMETER_TYPE";
    switch (value) {
        case D3D12_META_COMMAND_PARAMETER_TYPE_FLOAT: ret = "D3D12_META_COMMAND_PARAMETER_TYPE_FLOAT"; break;
        case D3D12_META_COMMAND_PARAMETER_TYPE_UINT64: ret = "D3D12_META_COMMAND_PARAMETER_TYPE_UINT64"; break;
        case D3D12_META_COMMAND_PARAMETER_TYPE_GPU_VIRTUAL_ADDRESS: ret = "D3D12_META_COMMAND_PARAMETER_TYPE_GPU_VIRTUAL_ADDRESS"; break;
        case D3D12_META_COMMAND_PARAMETER_TYPE_CPU_DESCRIPTOR_HANDLE_HEAP_TYPE_CBV_SRV_UAV: ret = "D3D12_META_COMMAND_PARAMETER_TYPE_CPU_DESCRIPTOR_HANDLE_HEAP_TYPE_CBV_SRV_UAV"; break;
        case D3D12_META_COMMAND_PARAMETER_TYPE_GPU_DESCRIPTOR_HANDLE_HEAP_TYPE_CBV_SRV_UAV: ret = "D3D12_META_COMMAND_PARAMETER_TYPE_GPU_DESCRIPTOR_HANDLE_HEAP_TYPE_CBV_SRV_UAV"; break;
    }
    return ret;
}

std::string ToString(const D3D12_META_COMMAND_PARAMETER_FLAGS value)
{
    const char* ret = "Unhandled D3D12_META_COMMAND_PARAMETER_FLAGS";
    switch (value) {
        case D3D12_META_COMMAND_PARAMETER_FLAG_INPUT: ret = "D3D12_META_COMMAND_PARAMETER_FLAG_INPUT"; break;
        case D3D12_META_COMMAND_PARAMETER_FLAG_OUTPUT: ret = "D3D12_META_COMMAND_PARAMETER_FLAG_OUTPUT"; break;
    }
    return ret;
}

std::string ToString_D3D12_META_COMMAND_PARAMETER_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_META_COMMAND_PARAMETER_FLAGS>(flags);
}

std::string ToString(const D3D12_META_COMMAND_PARAMETER_STAGE value)
{
    const char* ret = "Unhandled D3D12_META_COMMAND_PARAMETER_STAGE";
    switch (value) {
        case D3D12_META_COMMAND_PARAMETER_STAGE_CREATION: ret = "D3D12_META_COMMAND_PARAMETER_STAGE_CREATION"; break;
        case D3D12_META_COMMAND_PARAMETER_STAGE_INITIALIZATION: ret = "D3D12_META_COMMAND_PARAMETER_STAGE_INITIALIZATION"; break;
        case D3D12_META_COMMAND_PARAMETER_STAGE_EXECUTION: ret = "D3D12_META_COMMAND_PARAMETER_STAGE_EXECUTION"; break;
    }
    return ret;
}

std::string ToString(const D3D12_GRAPHICS_STATES value)
{
    const char* ret = "Unhandled D3D12_GRAPHICS_STATES";
    switch (value) {
        case D3D12_GRAPHICS_STATE_NONE: ret = "D3D12_GRAPHICS_STATE_NONE"; break;
        case D3D12_GRAPHICS_STATE_IA_VERTEX_BUFFERS: ret = "D3D12_GRAPHICS_STATE_IA_VERTEX_BUFFERS"; break;
        case D3D12_GRAPHICS_STATE_IA_INDEX_BUFFER: ret = "D3D12_GRAPHICS_STATE_IA_INDEX_BUFFER"; break;
        case D3D12_GRAPHICS_STATE_IA_PRIMITIVE_TOPOLOGY: ret = "D3D12_GRAPHICS_STATE_IA_PRIMITIVE_TOPOLOGY"; break;
        case D3D12_GRAPHICS_STATE_DESCRIPTOR_HEAP: ret = "D3D12_GRAPHICS_STATE_DESCRIPTOR_HEAP"; break;
        case D3D12_GRAPHICS_STATE_GRAPHICS_ROOT_SIGNATURE: ret = "D3D12_GRAPHICS_STATE_GRAPHICS_ROOT_SIGNATURE"; break;
        case D3D12_GRAPHICS_STATE_COMPUTE_ROOT_SIGNATURE: ret = "D3D12_GRAPHICS_STATE_COMPUTE_ROOT_SIGNATURE"; break;
        case D3D12_GRAPHICS_STATE_RS_VIEWPORTS: ret = "D3D12_GRAPHICS_STATE_RS_VIEWPORTS"; break;
        case D3D12_GRAPHICS_STATE_RS_SCISSOR_RECTS: ret = "D3D12_GRAPHICS_STATE_RS_SCISSOR_RECTS"; break;
        case D3D12_GRAPHICS_STATE_PREDICATION: ret = "D3D12_GRAPHICS_STATE_PREDICATION"; break;
        case D3D12_GRAPHICS_STATE_OM_RENDER_TARGETS: ret = "D3D12_GRAPHICS_STATE_OM_RENDER_TARGETS"; break;
        case D3D12_GRAPHICS_STATE_OM_STENCIL_REF: ret = "D3D12_GRAPHICS_STATE_OM_STENCIL_REF"; break;
        case D3D12_GRAPHICS_STATE_OM_BLEND_FACTOR: ret = "D3D12_GRAPHICS_STATE_OM_BLEND_FACTOR"; break;
        case D3D12_GRAPHICS_STATE_PIPELINE_STATE: ret = "D3D12_GRAPHICS_STATE_PIPELINE_STATE"; break;
        case D3D12_GRAPHICS_STATE_SO_TARGETS: ret = "D3D12_GRAPHICS_STATE_SO_TARGETS"; break;
        case D3D12_GRAPHICS_STATE_OM_DEPTH_BOUNDS: ret = "D3D12_GRAPHICS_STATE_OM_DEPTH_BOUNDS"; break;
        case D3D12_GRAPHICS_STATE_SAMPLE_POSITIONS: ret = "D3D12_GRAPHICS_STATE_SAMPLE_POSITIONS"; break;
        case D3D12_GRAPHICS_STATE_VIEW_INSTANCE_MASK: ret = "D3D12_GRAPHICS_STATE_VIEW_INSTANCE_MASK"; break;
    }
    return ret;
}

std::string ToString_D3D12_GRAPHICS_STATES(const uint32_t flags)
{
    return BitmaskToString<D3D12_GRAPHICS_STATES>(flags);
}

std::string ToString(const D3D12_STATE_SUBOBJECT_TYPE value)
{
    const char* ret = "Unhandled D3D12_STATE_SUBOBJECT_TYPE";
    switch (value) {
        case D3D12_STATE_SUBOBJECT_TYPE_STATE_OBJECT_CONFIG: ret = "D3D12_STATE_SUBOBJECT_TYPE_STATE_OBJECT_CONFIG"; break;
        case D3D12_STATE_SUBOBJECT_TYPE_GLOBAL_ROOT_SIGNATURE: ret = "D3D12_STATE_SUBOBJECT_TYPE_GLOBAL_ROOT_SIGNATURE"; break;
        case D3D12_STATE_SUBOBJECT_TYPE_LOCAL_ROOT_SIGNATURE: ret = "D3D12_STATE_SUBOBJECT_TYPE_LOCAL_ROOT_SIGNATURE"; break;
        case D3D12_STATE_SUBOBJECT_TYPE_NODE_MASK: ret = "D3D12_STATE_SUBOBJECT_TYPE_NODE_MASK"; break;
        case D3D12_STATE_SUBOBJECT_TYPE_DXIL_LIBRARY: ret = "D3D12_STATE_SUBOBJECT_TYPE_DXIL_LIBRARY"; break;
        case D3D12_STATE_SUBOBJECT_TYPE_EXISTING_COLLECTION: ret = "D3D12_STATE_SUBOBJECT_TYPE_EXISTING_COLLECTION"; break;
        case D3D12_STATE_SUBOBJECT_TYPE_SUBOBJECT_TO_EXPORTS_ASSOCIATION: ret = "D3D12_STATE_SUBOBJECT_TYPE_SUBOBJECT_TO_EXPORTS_ASSOCIATION"; break;
        case D3D12_STATE_SUBOBJECT_TYPE_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION: ret = "D3D12_STATE_SUBOBJECT_TYPE_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION"; break;
        case D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_SHADER_CONFIG: ret = "D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_SHADER_CONFIG"; break;
        case D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_PIPELINE_CONFIG: ret = "D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_PIPELINE_CONFIG"; break;
        case D3D12_STATE_SUBOBJECT_TYPE_HIT_GROUP: ret = "D3D12_STATE_SUBOBJECT_TYPE_HIT_GROUP"; break;
        case D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_PIPELINE_CONFIG1: ret = "D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_PIPELINE_CONFIG1"; break;
        case D3D12_STATE_SUBOBJECT_TYPE_MAX_VALID: ret = "D3D12_STATE_SUBOBJECT_TYPE_MAX_VALID"; break;
    }
    return ret;
}

std::string ToString(const D3D12_STATE_OBJECT_FLAGS value)
{
    const char* ret = "Unhandled D3D12_STATE_OBJECT_FLAGS";
    switch (value) {
        case D3D12_STATE_OBJECT_FLAG_NONE: ret = "D3D12_STATE_OBJECT_FLAG_NONE"; break;
        case D3D12_STATE_OBJECT_FLAG_ALLOW_LOCAL_DEPENDENCIES_ON_EXTERNAL_DEFINITIONS: ret = "D3D12_STATE_OBJECT_FLAG_ALLOW_LOCAL_DEPENDENCIES_ON_EXTERNAL_DEFINITIONS"; break;
        case D3D12_STATE_OBJECT_FLAG_ALLOW_EXTERNAL_DEPENDENCIES_ON_LOCAL_DEFINITIONS: ret = "D3D12_STATE_OBJECT_FLAG_ALLOW_EXTERNAL_DEPENDENCIES_ON_LOCAL_DEFINITIONS"; break;
        case D3D12_STATE_OBJECT_FLAG_ALLOW_STATE_OBJECT_ADDITIONS: ret = "D3D12_STATE_OBJECT_FLAG_ALLOW_STATE_OBJECT_ADDITIONS"; break;
    }
    return ret;
}

std::string ToString_D3D12_STATE_OBJECT_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_STATE_OBJECT_FLAGS>(flags);
}

std::string ToString(const D3D12_EXPORT_FLAGS value)
{
    const char* ret = "Unhandled D3D12_EXPORT_FLAGS";
    switch (value) {
        case D3D12_EXPORT_FLAG_NONE: ret = "D3D12_EXPORT_FLAG_NONE"; break;
    }
    return ret;
}

std::string ToString_D3D12_EXPORT_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_EXPORT_FLAGS>(flags);
}

std::string ToString(const D3D12_HIT_GROUP_TYPE value)
{
    const char* ret = "Unhandled D3D12_HIT_GROUP_TYPE";
    switch (value) {
        case D3D12_HIT_GROUP_TYPE_TRIANGLES: ret = "D3D12_HIT_GROUP_TYPE_TRIANGLES"; break;
        case D3D12_HIT_GROUP_TYPE_PROCEDURAL_PRIMITIVE: ret = "D3D12_HIT_GROUP_TYPE_PROCEDURAL_PRIMITIVE"; break;
    }
    return ret;
}

std::string ToString(const D3D12_RAYTRACING_PIPELINE_FLAGS value)
{
    const char* ret = "Unhandled D3D12_RAYTRACING_PIPELINE_FLAGS";
    switch (value) {
        case D3D12_RAYTRACING_PIPELINE_FLAG_NONE: ret = "D3D12_RAYTRACING_PIPELINE_FLAG_NONE"; break;
        case D3D12_RAYTRACING_PIPELINE_FLAG_SKIP_TRIANGLES: ret = "D3D12_RAYTRACING_PIPELINE_FLAG_SKIP_TRIANGLES"; break;
        case D3D12_RAYTRACING_PIPELINE_FLAG_SKIP_PROCEDURAL_PRIMITIVES: ret = "D3D12_RAYTRACING_PIPELINE_FLAG_SKIP_PROCEDURAL_PRIMITIVES"; break;
    }
    return ret;
}

std::string ToString_D3D12_RAYTRACING_PIPELINE_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_RAYTRACING_PIPELINE_FLAGS>(flags);
}

std::string ToString(const D3D12_STATE_OBJECT_TYPE value)
{
    const char* ret = "Unhandled D3D12_STATE_OBJECT_TYPE";
    switch (value) {
        case D3D12_STATE_OBJECT_TYPE_COLLECTION: ret = "D3D12_STATE_OBJECT_TYPE_COLLECTION"; break;
        case D3D12_STATE_OBJECT_TYPE_RAYTRACING_PIPELINE: ret = "D3D12_STATE_OBJECT_TYPE_RAYTRACING_PIPELINE"; break;
    }
    return ret;
}

std::string ToString(const D3D12_RAYTRACING_GEOMETRY_FLAGS value)
{
    const char* ret = "Unhandled D3D12_RAYTRACING_GEOMETRY_FLAGS";
    switch (value) {
        case D3D12_RAYTRACING_GEOMETRY_FLAG_NONE: ret = "D3D12_RAYTRACING_GEOMETRY_FLAG_NONE"; break;
        case D3D12_RAYTRACING_GEOMETRY_FLAG_OPAQUE: ret = "D3D12_RAYTRACING_GEOMETRY_FLAG_OPAQUE"; break;
        case D3D12_RAYTRACING_GEOMETRY_FLAG_NO_DUPLICATE_ANYHIT_INVOCATION: ret = "D3D12_RAYTRACING_GEOMETRY_FLAG_NO_DUPLICATE_ANYHIT_INVOCATION"; break;
    }
    return ret;
}

std::string ToString_D3D12_RAYTRACING_GEOMETRY_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_RAYTRACING_GEOMETRY_FLAGS>(flags);
}

std::string ToString(const D3D12_RAYTRACING_GEOMETRY_TYPE value)
{
    const char* ret = "Unhandled D3D12_RAYTRACING_GEOMETRY_TYPE";
    switch (value) {
        case D3D12_RAYTRACING_GEOMETRY_TYPE_TRIANGLES: ret = "D3D12_RAYTRACING_GEOMETRY_TYPE_TRIANGLES"; break;
        case D3D12_RAYTRACING_GEOMETRY_TYPE_PROCEDURAL_PRIMITIVE_AABBS: ret = "D3D12_RAYTRACING_GEOMETRY_TYPE_PROCEDURAL_PRIMITIVE_AABBS"; break;
    }
    return ret;
}

std::string ToString(const D3D12_RAYTRACING_INSTANCE_FLAGS value)
{
    const char* ret = "Unhandled D3D12_RAYTRACING_INSTANCE_FLAGS";
    switch (value) {
        case D3D12_RAYTRACING_INSTANCE_FLAG_NONE: ret = "D3D12_RAYTRACING_INSTANCE_FLAG_NONE"; break;
        case D3D12_RAYTRACING_INSTANCE_FLAG_TRIANGLE_CULL_DISABLE: ret = "D3D12_RAYTRACING_INSTANCE_FLAG_TRIANGLE_CULL_DISABLE"; break;
        case D3D12_RAYTRACING_INSTANCE_FLAG_TRIANGLE_FRONT_COUNTERCLOCKWISE: ret = "D3D12_RAYTRACING_INSTANCE_FLAG_TRIANGLE_FRONT_COUNTERCLOCKWISE"; break;
        case D3D12_RAYTRACING_INSTANCE_FLAG_FORCE_OPAQUE: ret = "D3D12_RAYTRACING_INSTANCE_FLAG_FORCE_OPAQUE"; break;
        case D3D12_RAYTRACING_INSTANCE_FLAG_FORCE_NON_OPAQUE: ret = "D3D12_RAYTRACING_INSTANCE_FLAG_FORCE_NON_OPAQUE"; break;
    }
    return ret;
}

std::string ToString_D3D12_RAYTRACING_INSTANCE_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_RAYTRACING_INSTANCE_FLAGS>(flags);
}

std::string ToString(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS value)
{
    const char* ret = "Unhandled D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS";
    switch (value) {
        case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_NONE: ret = "D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_NONE"; break;
        case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_UPDATE: ret = "D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_UPDATE"; break;
        case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_COMPACTION: ret = "D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_COMPACTION"; break;
        case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_PREFER_FAST_TRACE: ret = "D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_PREFER_FAST_TRACE"; break;
        case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_PREFER_FAST_BUILD: ret = "D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_PREFER_FAST_BUILD"; break;
        case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_MINIMIZE_MEMORY: ret = "D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_MINIMIZE_MEMORY"; break;
        case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_PERFORM_UPDATE: ret = "D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_PERFORM_UPDATE"; break;
    }
    return ret;
}

std::string ToString_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS>(flags);
}

std::string ToString(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE value)
{
    const char* ret = "Unhandled D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE";
    switch (value) {
        case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE_CLONE: ret = "D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE_CLONE"; break;
        case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE_COMPACT: ret = "D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE_COMPACT"; break;
        case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE_VISUALIZATION_DECODE_FOR_TOOLS: ret = "D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE_VISUALIZATION_DECODE_FOR_TOOLS"; break;
        case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE_SERIALIZE: ret = "D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE_SERIALIZE"; break;
        case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE_DESERIALIZE: ret = "D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE_DESERIALIZE"; break;
    }
    return ret;
}

std::string ToString(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE value)
{
    const char* ret = "Unhandled D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE";
    switch (value) {
        case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL: ret = "D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL"; break;
        case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL: ret = "D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL"; break;
    }
    return ret;
}

std::string ToString(const D3D12_ELEMENTS_LAYOUT value)
{
    const char* ret = "Unhandled D3D12_ELEMENTS_LAYOUT";
    switch (value) {
        case D3D12_ELEMENTS_LAYOUT_ARRAY: ret = "D3D12_ELEMENTS_LAYOUT_ARRAY"; break;
        case D3D12_ELEMENTS_LAYOUT_ARRAY_OF_POINTERS: ret = "D3D12_ELEMENTS_LAYOUT_ARRAY_OF_POINTERS"; break;
    }
    return ret;
}

std::string ToString(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TYPE value)
{
    const char* ret = "Unhandled D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TYPE";
    switch (value) {
        case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE: ret = "D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE"; break;
        case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION: ret = "D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION"; break;
        case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION: ret = "D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION"; break;
        case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE: ret = "D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE"; break;
    }
    return ret;
}

std::string ToString(const D3D12_SERIALIZED_DATA_TYPE value)
{
    const char* ret = "Unhandled D3D12_SERIALIZED_DATA_TYPE";
    switch (value) {
        case D3D12_SERIALIZED_DATA_RAYTRACING_ACCELERATION_STRUCTURE: ret = "D3D12_SERIALIZED_DATA_RAYTRACING_ACCELERATION_STRUCTURE"; break;
    }
    return ret;
}

std::string ToString(const D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS value)
{
    const char* ret = "Unhandled D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS";
    switch (value) {
        case D3D12_DRIVER_MATCHING_IDENTIFIER_COMPATIBLE_WITH_DEVICE: ret = "D3D12_DRIVER_MATCHING_IDENTIFIER_COMPATIBLE_WITH_DEVICE"; break;
        case D3D12_DRIVER_MATCHING_IDENTIFIER_UNSUPPORTED_TYPE: ret = "D3D12_DRIVER_MATCHING_IDENTIFIER_UNSUPPORTED_TYPE"; break;
        case D3D12_DRIVER_MATCHING_IDENTIFIER_UNRECOGNIZED: ret = "D3D12_DRIVER_MATCHING_IDENTIFIER_UNRECOGNIZED"; break;
        case D3D12_DRIVER_MATCHING_IDENTIFIER_INCOMPATIBLE_VERSION: ret = "D3D12_DRIVER_MATCHING_IDENTIFIER_INCOMPATIBLE_VERSION"; break;
        case D3D12_DRIVER_MATCHING_IDENTIFIER_INCOMPATIBLE_TYPE: ret = "D3D12_DRIVER_MATCHING_IDENTIFIER_INCOMPATIBLE_TYPE"; break;
    }
    return ret;
}

std::string ToString_D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS(const uint32_t flags)
{
    return BitmaskToString<D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS>(flags);
}

std::string ToString(const D3D12_RAY_FLAGS value)
{
    const char* ret = "Unhandled D3D12_RAY_FLAGS";
    switch (value) {
        case D3D12_RAY_FLAG_NONE: ret = "D3D12_RAY_FLAG_NONE"; break;
        case D3D12_RAY_FLAG_FORCE_OPAQUE: ret = "D3D12_RAY_FLAG_FORCE_OPAQUE"; break;
        case D3D12_RAY_FLAG_FORCE_NON_OPAQUE: ret = "D3D12_RAY_FLAG_FORCE_NON_OPAQUE"; break;
        case D3D12_RAY_FLAG_ACCEPT_FIRST_HIT_AND_END_SEARCH: ret = "D3D12_RAY_FLAG_ACCEPT_FIRST_HIT_AND_END_SEARCH"; break;
        case D3D12_RAY_FLAG_SKIP_CLOSEST_HIT_SHADER: ret = "D3D12_RAY_FLAG_SKIP_CLOSEST_HIT_SHADER"; break;
        case D3D12_RAY_FLAG_CULL_BACK_FACING_TRIANGLES: ret = "D3D12_RAY_FLAG_CULL_BACK_FACING_TRIANGLES"; break;
        case D3D12_RAY_FLAG_CULL_FRONT_FACING_TRIANGLES: ret = "D3D12_RAY_FLAG_CULL_FRONT_FACING_TRIANGLES"; break;
        case D3D12_RAY_FLAG_CULL_OPAQUE: ret = "D3D12_RAY_FLAG_CULL_OPAQUE"; break;
        case D3D12_RAY_FLAG_CULL_NON_OPAQUE: ret = "D3D12_RAY_FLAG_CULL_NON_OPAQUE"; break;
        case D3D12_RAY_FLAG_SKIP_TRIANGLES: ret = "D3D12_RAY_FLAG_SKIP_TRIANGLES"; break;
        case D3D12_RAY_FLAG_SKIP_PROCEDURAL_PRIMITIVES: ret = "D3D12_RAY_FLAG_SKIP_PROCEDURAL_PRIMITIVES"; break;
    }
    return ret;
}

std::string ToString_D3D12_RAY_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_RAY_FLAGS>(flags);
}

std::string ToString(const D3D12_HIT_KIND value)
{
    const char* ret = "Unhandled D3D12_HIT_KIND";
    switch (value) {
        case D3D12_HIT_KIND_TRIANGLE_FRONT_FACE: ret = "D3D12_HIT_KIND_TRIANGLE_FRONT_FACE"; break;
        case D3D12_HIT_KIND_TRIANGLE_BACK_FACE: ret = "D3D12_HIT_KIND_TRIANGLE_BACK_FACE"; break;
    }
    return ret;
}

std::string ToString(const D3D12_AUTO_BREADCRUMB_OP value)
{
    const char* ret = "Unhandled D3D12_AUTO_BREADCRUMB_OP";
    switch (value) {
        case D3D12_AUTO_BREADCRUMB_OP_SETMARKER: ret = "D3D12_AUTO_BREADCRUMB_OP_SETMARKER"; break;
        case D3D12_AUTO_BREADCRUMB_OP_BEGINEVENT: ret = "D3D12_AUTO_BREADCRUMB_OP_BEGINEVENT"; break;
        case D3D12_AUTO_BREADCRUMB_OP_ENDEVENT: ret = "D3D12_AUTO_BREADCRUMB_OP_ENDEVENT"; break;
        case D3D12_AUTO_BREADCRUMB_OP_DRAWINSTANCED: ret = "D3D12_AUTO_BREADCRUMB_OP_DRAWINSTANCED"; break;
        case D3D12_AUTO_BREADCRUMB_OP_DRAWINDEXEDINSTANCED: ret = "D3D12_AUTO_BREADCRUMB_OP_DRAWINDEXEDINSTANCED"; break;
        case D3D12_AUTO_BREADCRUMB_OP_EXECUTEINDIRECT: ret = "D3D12_AUTO_BREADCRUMB_OP_EXECUTEINDIRECT"; break;
        case D3D12_AUTO_BREADCRUMB_OP_DISPATCH: ret = "D3D12_AUTO_BREADCRUMB_OP_DISPATCH"; break;
        case D3D12_AUTO_BREADCRUMB_OP_COPYBUFFERREGION: ret = "D3D12_AUTO_BREADCRUMB_OP_COPYBUFFERREGION"; break;
        case D3D12_AUTO_BREADCRUMB_OP_COPYTEXTUREREGION: ret = "D3D12_AUTO_BREADCRUMB_OP_COPYTEXTUREREGION"; break;
        case D3D12_AUTO_BREADCRUMB_OP_COPYRESOURCE: ret = "D3D12_AUTO_BREADCRUMB_OP_COPYRESOURCE"; break;
        case D3D12_AUTO_BREADCRUMB_OP_COPYTILES: ret = "D3D12_AUTO_BREADCRUMB_OP_COPYTILES"; break;
        case D3D12_AUTO_BREADCRUMB_OP_RESOLVESUBRESOURCE: ret = "D3D12_AUTO_BREADCRUMB_OP_RESOLVESUBRESOURCE"; break;
        case D3D12_AUTO_BREADCRUMB_OP_CLEARRENDERTARGETVIEW: ret = "D3D12_AUTO_BREADCRUMB_OP_CLEARRENDERTARGETVIEW"; break;
        case D3D12_AUTO_BREADCRUMB_OP_CLEARUNORDEREDACCESSVIEW: ret = "D3D12_AUTO_BREADCRUMB_OP_CLEARUNORDEREDACCESSVIEW"; break;
        case D3D12_AUTO_BREADCRUMB_OP_CLEARDEPTHSTENCILVIEW: ret = "D3D12_AUTO_BREADCRUMB_OP_CLEARDEPTHSTENCILVIEW"; break;
        case D3D12_AUTO_BREADCRUMB_OP_RESOURCEBARRIER: ret = "D3D12_AUTO_BREADCRUMB_OP_RESOURCEBARRIER"; break;
        case D3D12_AUTO_BREADCRUMB_OP_EXECUTEBUNDLE: ret = "D3D12_AUTO_BREADCRUMB_OP_EXECUTEBUNDLE"; break;
        case D3D12_AUTO_BREADCRUMB_OP_PRESENT: ret = "D3D12_AUTO_BREADCRUMB_OP_PRESENT"; break;
        case D3D12_AUTO_BREADCRUMB_OP_RESOLVEQUERYDATA: ret = "D3D12_AUTO_BREADCRUMB_OP_RESOLVEQUERYDATA"; break;
        case D3D12_AUTO_BREADCRUMB_OP_BEGINSUBMISSION: ret = "D3D12_AUTO_BREADCRUMB_OP_BEGINSUBMISSION"; break;
        case D3D12_AUTO_BREADCRUMB_OP_ENDSUBMISSION: ret = "D3D12_AUTO_BREADCRUMB_OP_ENDSUBMISSION"; break;
        case D3D12_AUTO_BREADCRUMB_OP_DECODEFRAME: ret = "D3D12_AUTO_BREADCRUMB_OP_DECODEFRAME"; break;
        case D3D12_AUTO_BREADCRUMB_OP_PROCESSFRAMES: ret = "D3D12_AUTO_BREADCRUMB_OP_PROCESSFRAMES"; break;
        case D3D12_AUTO_BREADCRUMB_OP_ATOMICCOPYBUFFERUINT: ret = "D3D12_AUTO_BREADCRUMB_OP_ATOMICCOPYBUFFERUINT"; break;
        case D3D12_AUTO_BREADCRUMB_OP_ATOMICCOPYBUFFERUINT64: ret = "D3D12_AUTO_BREADCRUMB_OP_ATOMICCOPYBUFFERUINT64"; break;
        case D3D12_AUTO_BREADCRUMB_OP_RESOLVESUBRESOURCEREGION: ret = "D3D12_AUTO_BREADCRUMB_OP_RESOLVESUBRESOURCEREGION"; break;
        case D3D12_AUTO_BREADCRUMB_OP_WRITEBUFFERIMMEDIATE: ret = "D3D12_AUTO_BREADCRUMB_OP_WRITEBUFFERIMMEDIATE"; break;
        case D3D12_AUTO_BREADCRUMB_OP_DECODEFRAME1: ret = "D3D12_AUTO_BREADCRUMB_OP_DECODEFRAME1"; break;
        case D3D12_AUTO_BREADCRUMB_OP_SETPROTECTEDRESOURCESESSION: ret = "D3D12_AUTO_BREADCRUMB_OP_SETPROTECTEDRESOURCESESSION"; break;
        case D3D12_AUTO_BREADCRUMB_OP_DECODEFRAME2: ret = "D3D12_AUTO_BREADCRUMB_OP_DECODEFRAME2"; break;
        case D3D12_AUTO_BREADCRUMB_OP_PROCESSFRAMES1: ret = "D3D12_AUTO_BREADCRUMB_OP_PROCESSFRAMES1"; break;
        case D3D12_AUTO_BREADCRUMB_OP_BUILDRAYTRACINGACCELERATIONSTRUCTURE: ret = "D3D12_AUTO_BREADCRUMB_OP_BUILDRAYTRACINGACCELERATIONSTRUCTURE"; break;
        case D3D12_AUTO_BREADCRUMB_OP_EMITRAYTRACINGACCELERATIONSTRUCTUREPOSTBUILDINFO: ret = "D3D12_AUTO_BREADCRUMB_OP_EMITRAYTRACINGACCELERATIONSTRUCTUREPOSTBUILDINFO"; break;
        case D3D12_AUTO_BREADCRUMB_OP_COPYRAYTRACINGACCELERATIONSTRUCTURE: ret = "D3D12_AUTO_BREADCRUMB_OP_COPYRAYTRACINGACCELERATIONSTRUCTURE"; break;
        case D3D12_AUTO_BREADCRUMB_OP_DISPATCHRAYS: ret = "D3D12_AUTO_BREADCRUMB_OP_DISPATCHRAYS"; break;
        case D3D12_AUTO_BREADCRUMB_OP_INITIALIZEMETACOMMAND: ret = "D3D12_AUTO_BREADCRUMB_OP_INITIALIZEMETACOMMAND"; break;
        case D3D12_AUTO_BREADCRUMB_OP_EXECUTEMETACOMMAND: ret = "D3D12_AUTO_BREADCRUMB_OP_EXECUTEMETACOMMAND"; break;
        case D3D12_AUTO_BREADCRUMB_OP_ESTIMATEMOTION: ret = "D3D12_AUTO_BREADCRUMB_OP_ESTIMATEMOTION"; break;
        case D3D12_AUTO_BREADCRUMB_OP_RESOLVEMOTIONVECTORHEAP: ret = "D3D12_AUTO_BREADCRUMB_OP_RESOLVEMOTIONVECTORHEAP"; break;
        case D3D12_AUTO_BREADCRUMB_OP_SETPIPELINESTATE1: ret = "D3D12_AUTO_BREADCRUMB_OP_SETPIPELINESTATE1"; break;
        case D3D12_AUTO_BREADCRUMB_OP_INITIALIZEEXTENSIONCOMMAND: ret = "D3D12_AUTO_BREADCRUMB_OP_INITIALIZEEXTENSIONCOMMAND"; break;
        case D3D12_AUTO_BREADCRUMB_OP_EXECUTEEXTENSIONCOMMAND: ret = "D3D12_AUTO_BREADCRUMB_OP_EXECUTEEXTENSIONCOMMAND"; break;
        case D3D12_AUTO_BREADCRUMB_OP_DISPATCHMESH: ret = "D3D12_AUTO_BREADCRUMB_OP_DISPATCHMESH"; break;
        case D3D12_AUTO_BREADCRUMB_OP_ENCODEFRAME: ret = "D3D12_AUTO_BREADCRUMB_OP_ENCODEFRAME"; break;
        case D3D12_AUTO_BREADCRUMB_OP_RESOLVEENCODEROUTPUTMETADATA: ret = "D3D12_AUTO_BREADCRUMB_OP_RESOLVEENCODEROUTPUTMETADATA"; break;
        case D3D12_AUTO_BREADCRUMB_OP_BARRIER: ret = "D3D12_AUTO_BREADCRUMB_OP_BARRIER"; break;
    }
    return ret;
}

std::string ToString(const D3D12_DRED_VERSION value)
{
    const char* ret = "Unhandled D3D12_DRED_VERSION";
    switch (value) {
        case D3D12_DRED_VERSION_1_0: ret = "D3D12_DRED_VERSION_1_0"; break;
        case D3D12_DRED_VERSION_1_1: ret = "D3D12_DRED_VERSION_1_1"; break;
        case D3D12_DRED_VERSION_1_2: ret = "D3D12_DRED_VERSION_1_2"; break;
        case D3D12_DRED_VERSION_1_3: ret = "D3D12_DRED_VERSION_1_3"; break;
    }
    return ret;
}

std::string ToString(const D3D12_DRED_FLAGS value)
{
    const char* ret = "Unhandled D3D12_DRED_FLAGS";
    switch (value) {
        case D3D12_DRED_FLAG_NONE: ret = "D3D12_DRED_FLAG_NONE"; break;
        case D3D12_DRED_FLAG_FORCE_ENABLE: ret = "D3D12_DRED_FLAG_FORCE_ENABLE"; break;
        case D3D12_DRED_FLAG_DISABLE_AUTOBREADCRUMBS: ret = "D3D12_DRED_FLAG_DISABLE_AUTOBREADCRUMBS"; break;
    }
    return ret;
}

std::string ToString_D3D12_DRED_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_DRED_FLAGS>(flags);
}

std::string ToString(const D3D12_DRED_ENABLEMENT value)
{
    const char* ret = "Unhandled D3D12_DRED_ENABLEMENT";
    switch (value) {
        case D3D12_DRED_ENABLEMENT_SYSTEM_CONTROLLED: ret = "D3D12_DRED_ENABLEMENT_SYSTEM_CONTROLLED"; break;
        case D3D12_DRED_ENABLEMENT_FORCED_OFF: ret = "D3D12_DRED_ENABLEMENT_FORCED_OFF"; break;
        case D3D12_DRED_ENABLEMENT_FORCED_ON: ret = "D3D12_DRED_ENABLEMENT_FORCED_ON"; break;
    }
    return ret;
}

std::string ToString(const D3D12_DRED_ALLOCATION_TYPE value)
{
    const char* ret = "Unhandled D3D12_DRED_ALLOCATION_TYPE";
    switch (value) {
        case D3D12_DRED_ALLOCATION_TYPE_COMMAND_QUEUE: ret = "D3D12_DRED_ALLOCATION_TYPE_COMMAND_QUEUE"; break;
        case D3D12_DRED_ALLOCATION_TYPE_COMMAND_ALLOCATOR: ret = "D3D12_DRED_ALLOCATION_TYPE_COMMAND_ALLOCATOR"; break;
        case D3D12_DRED_ALLOCATION_TYPE_PIPELINE_STATE: ret = "D3D12_DRED_ALLOCATION_TYPE_PIPELINE_STATE"; break;
        case D3D12_DRED_ALLOCATION_TYPE_COMMAND_LIST: ret = "D3D12_DRED_ALLOCATION_TYPE_COMMAND_LIST"; break;
        case D3D12_DRED_ALLOCATION_TYPE_FENCE: ret = "D3D12_DRED_ALLOCATION_TYPE_FENCE"; break;
        case D3D12_DRED_ALLOCATION_TYPE_DESCRIPTOR_HEAP: ret = "D3D12_DRED_ALLOCATION_TYPE_DESCRIPTOR_HEAP"; break;
        case D3D12_DRED_ALLOCATION_TYPE_HEAP: ret = "D3D12_DRED_ALLOCATION_TYPE_HEAP"; break;
        case D3D12_DRED_ALLOCATION_TYPE_QUERY_HEAP: ret = "D3D12_DRED_ALLOCATION_TYPE_QUERY_HEAP"; break;
        case D3D12_DRED_ALLOCATION_TYPE_COMMAND_SIGNATURE: ret = "D3D12_DRED_ALLOCATION_TYPE_COMMAND_SIGNATURE"; break;
        case D3D12_DRED_ALLOCATION_TYPE_PIPELINE_LIBRARY: ret = "D3D12_DRED_ALLOCATION_TYPE_PIPELINE_LIBRARY"; break;
        case D3D12_DRED_ALLOCATION_TYPE_VIDEO_DECODER: ret = "D3D12_DRED_ALLOCATION_TYPE_VIDEO_DECODER"; break;
        case D3D12_DRED_ALLOCATION_TYPE_VIDEO_PROCESSOR: ret = "D3D12_DRED_ALLOCATION_TYPE_VIDEO_PROCESSOR"; break;
        case D3D12_DRED_ALLOCATION_TYPE_RESOURCE: ret = "D3D12_DRED_ALLOCATION_TYPE_RESOURCE"; break;
        case D3D12_DRED_ALLOCATION_TYPE_PASS: ret = "D3D12_DRED_ALLOCATION_TYPE_PASS"; break;
        case D3D12_DRED_ALLOCATION_TYPE_CRYPTOSESSION: ret = "D3D12_DRED_ALLOCATION_TYPE_CRYPTOSESSION"; break;
        case D3D12_DRED_ALLOCATION_TYPE_CRYPTOSESSIONPOLICY: ret = "D3D12_DRED_ALLOCATION_TYPE_CRYPTOSESSIONPOLICY"; break;
        case D3D12_DRED_ALLOCATION_TYPE_PROTECTEDRESOURCESESSION: ret = "D3D12_DRED_ALLOCATION_TYPE_PROTECTEDRESOURCESESSION"; break;
        case D3D12_DRED_ALLOCATION_TYPE_VIDEO_DECODER_HEAP: ret = "D3D12_DRED_ALLOCATION_TYPE_VIDEO_DECODER_HEAP"; break;
        case D3D12_DRED_ALLOCATION_TYPE_COMMAND_POOL: ret = "D3D12_DRED_ALLOCATION_TYPE_COMMAND_POOL"; break;
        case D3D12_DRED_ALLOCATION_TYPE_COMMAND_RECORDER: ret = "D3D12_DRED_ALLOCATION_TYPE_COMMAND_RECORDER"; break;
        case D3D12_DRED_ALLOCATION_TYPE_STATE_OBJECT: ret = "D3D12_DRED_ALLOCATION_TYPE_STATE_OBJECT"; break;
        case D3D12_DRED_ALLOCATION_TYPE_METACOMMAND: ret = "D3D12_DRED_ALLOCATION_TYPE_METACOMMAND"; break;
        case D3D12_DRED_ALLOCATION_TYPE_SCHEDULINGGROUP: ret = "D3D12_DRED_ALLOCATION_TYPE_SCHEDULINGGROUP"; break;
        case D3D12_DRED_ALLOCATION_TYPE_VIDEO_MOTION_ESTIMATOR: ret = "D3D12_DRED_ALLOCATION_TYPE_VIDEO_MOTION_ESTIMATOR"; break;
        case D3D12_DRED_ALLOCATION_TYPE_VIDEO_MOTION_VECTOR_HEAP: ret = "D3D12_DRED_ALLOCATION_TYPE_VIDEO_MOTION_VECTOR_HEAP"; break;
        case D3D12_DRED_ALLOCATION_TYPE_VIDEO_EXTENSION_COMMAND: ret = "D3D12_DRED_ALLOCATION_TYPE_VIDEO_EXTENSION_COMMAND"; break;
        case D3D12_DRED_ALLOCATION_TYPE_VIDEO_ENCODER: ret = "D3D12_DRED_ALLOCATION_TYPE_VIDEO_ENCODER"; break;
        case D3D12_DRED_ALLOCATION_TYPE_VIDEO_ENCODER_HEAP: ret = "D3D12_DRED_ALLOCATION_TYPE_VIDEO_ENCODER_HEAP"; break;
        case D3D12_DRED_ALLOCATION_TYPE_INVALID: ret = "D3D12_DRED_ALLOCATION_TYPE_INVALID"; break;
    }
    return ret;
}

std::string ToString(const D3D12_DRED_PAGE_FAULT_FLAGS value)
{
    const char* ret = "Unhandled D3D12_DRED_PAGE_FAULT_FLAGS";
    switch (value) {
        case D3D12_DRED_PAGE_FAULT_FLAGS_NONE: ret = "D3D12_DRED_PAGE_FAULT_FLAGS_NONE"; break;
    }
    return ret;
}

std::string ToString_D3D12_DRED_PAGE_FAULT_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_DRED_PAGE_FAULT_FLAGS>(flags);
}

std::string ToString(const D3D12_DRED_DEVICE_STATE value)
{
    const char* ret = "Unhandled D3D12_DRED_DEVICE_STATE";
    switch (value) {
        case D3D12_DRED_DEVICE_STATE_UNKNOWN: ret = "D3D12_DRED_DEVICE_STATE_UNKNOWN"; break;
        case D3D12_DRED_DEVICE_STATE_HUNG: ret = "D3D12_DRED_DEVICE_STATE_HUNG"; break;
        case D3D12_DRED_DEVICE_STATE_FAULT: ret = "D3D12_DRED_DEVICE_STATE_FAULT"; break;
        case D3D12_DRED_DEVICE_STATE_PAGEFAULT: ret = "D3D12_DRED_DEVICE_STATE_PAGEFAULT"; break;
    }
    return ret;
}

std::string ToString(const D3D12_BACKGROUND_PROCESSING_MODE value)
{
    const char* ret = "Unhandled D3D12_BACKGROUND_PROCESSING_MODE";
    switch (value) {
        case D3D12_BACKGROUND_PROCESSING_MODE_ALLOWED: ret = "D3D12_BACKGROUND_PROCESSING_MODE_ALLOWED"; break;
        case D3D12_BACKGROUND_PROCESSING_MODE_ALLOW_INTRUSIVE_MEASUREMENTS: ret = "D3D12_BACKGROUND_PROCESSING_MODE_ALLOW_INTRUSIVE_MEASUREMENTS"; break;
        case D3D12_BACKGROUND_PROCESSING_MODE_DISABLE_BACKGROUND_WORK: ret = "D3D12_BACKGROUND_PROCESSING_MODE_DISABLE_BACKGROUND_WORK"; break;
        case D3D12_BACKGROUND_PROCESSING_MODE_DISABLE_PROFILING_BY_SYSTEM: ret = "D3D12_BACKGROUND_PROCESSING_MODE_DISABLE_PROFILING_BY_SYSTEM"; break;
    }
    return ret;
}

std::string ToString(const D3D12_MEASUREMENTS_ACTION value)
{
    const char* ret = "Unhandled D3D12_MEASUREMENTS_ACTION";
    switch (value) {
        case D3D12_MEASUREMENTS_ACTION_KEEP_ALL: ret = "D3D12_MEASUREMENTS_ACTION_KEEP_ALL"; break;
        case D3D12_MEASUREMENTS_ACTION_COMMIT_RESULTS: ret = "D3D12_MEASUREMENTS_ACTION_COMMIT_RESULTS"; break;
        case D3D12_MEASUREMENTS_ACTION_COMMIT_RESULTS_HIGH_PRIORITY: ret = "D3D12_MEASUREMENTS_ACTION_COMMIT_RESULTS_HIGH_PRIORITY"; break;
        case D3D12_MEASUREMENTS_ACTION_DISCARD_PREVIOUS: ret = "D3D12_MEASUREMENTS_ACTION_DISCARD_PREVIOUS"; break;
    }
    return ret;
}

std::string ToString(const D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE value)
{
    const char* ret = "Unhandled D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE";
    switch (value) {
        case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_DISCARD: ret = "D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_DISCARD"; break;
        case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE: ret = "D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE"; break;
        case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_CLEAR: ret = "D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_CLEAR"; break;
        case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_NO_ACCESS: ret = "D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_NO_ACCESS"; break;
        case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE_LOCAL_RENDER: ret = "D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE_LOCAL_RENDER"; break;
        case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE_LOCAL_SRV: ret = "D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE_LOCAL_SRV"; break;
        case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE_LOCAL_UAV: ret = "D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE_LOCAL_UAV"; break;
    }
    return ret;
}

std::string ToString(const D3D12_RENDER_PASS_ENDING_ACCESS_TYPE value)
{
    const char* ret = "Unhandled D3D12_RENDER_PASS_ENDING_ACCESS_TYPE";
    switch (value) {
        case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_DISCARD: ret = "D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_DISCARD"; break;
        case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE: ret = "D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE"; break;
        case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_RESOLVE: ret = "D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_RESOLVE"; break;
        case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_NO_ACCESS: ret = "D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_NO_ACCESS"; break;
        case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE_LOCAL_RENDER: ret = "D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE_LOCAL_RENDER"; break;
        case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE_LOCAL_SRV: ret = "D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE_LOCAL_SRV"; break;
        case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE_LOCAL_UAV: ret = "D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE_LOCAL_UAV"; break;
    }
    return ret;
}

std::string ToString(const D3D12_RENDER_PASS_FLAGS value)
{
    const char* ret = "Unhandled D3D12_RENDER_PASS_FLAGS";
    switch (value) {
        case D3D12_RENDER_PASS_FLAG_NONE: ret = "D3D12_RENDER_PASS_FLAG_NONE"; break;
        case D3D12_RENDER_PASS_FLAG_ALLOW_UAV_WRITES: ret = "D3D12_RENDER_PASS_FLAG_ALLOW_UAV_WRITES"; break;
        case D3D12_RENDER_PASS_FLAG_SUSPENDING_PASS: ret = "D3D12_RENDER_PASS_FLAG_SUSPENDING_PASS"; break;
        case D3D12_RENDER_PASS_FLAG_RESUMING_PASS: ret = "D3D12_RENDER_PASS_FLAG_RESUMING_PASS"; break;
        case D3D12_RENDER_PASS_FLAG_BIND_READ_ONLY_DEPTH: ret = "D3D12_RENDER_PASS_FLAG_BIND_READ_ONLY_DEPTH"; break;
        case D3D12_RENDER_PASS_FLAG_BIND_READ_ONLY_STENCIL: ret = "D3D12_RENDER_PASS_FLAG_BIND_READ_ONLY_STENCIL"; break;
    }
    return ret;
}

std::string ToString_D3D12_RENDER_PASS_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_RENDER_PASS_FLAGS>(flags);
}

std::string ToString(const D3D12_SHADER_CACHE_MODE value)
{
    const char* ret = "Unhandled D3D12_SHADER_CACHE_MODE";
    switch (value) {
        case D3D12_SHADER_CACHE_MODE_MEMORY: ret = "D3D12_SHADER_CACHE_MODE_MEMORY"; break;
        case D3D12_SHADER_CACHE_MODE_DISK: ret = "D3D12_SHADER_CACHE_MODE_DISK"; break;
    }
    return ret;
}

std::string ToString(const D3D12_SHADER_CACHE_FLAGS value)
{
    const char* ret = "Unhandled D3D12_SHADER_CACHE_FLAGS";
    switch (value) {
        case D3D12_SHADER_CACHE_FLAG_NONE: ret = "D3D12_SHADER_CACHE_FLAG_NONE"; break;
        case D3D12_SHADER_CACHE_FLAG_DRIVER_VERSIONED: ret = "D3D12_SHADER_CACHE_FLAG_DRIVER_VERSIONED"; break;
        case D3D12_SHADER_CACHE_FLAG_USE_WORKING_DIR: ret = "D3D12_SHADER_CACHE_FLAG_USE_WORKING_DIR"; break;
    }
    return ret;
}

std::string ToString_D3D12_SHADER_CACHE_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_SHADER_CACHE_FLAGS>(flags);
}

std::string ToString(const D3D12_BARRIER_LAYOUT value)
{
    const char* ret = "Unhandled D3D12_BARRIER_LAYOUT";
    switch (value) {
        case D3D12_BARRIER_LAYOUT_UNDEFINED: ret = "D3D12_BARRIER_LAYOUT_UNDEFINED"; break;
        case D3D12_BARRIER_LAYOUT_COMMON: ret = "D3D12_BARRIER_LAYOUT_COMMON"; break;
        case D3D12_BARRIER_LAYOUT_GENERIC_READ: ret = "D3D12_BARRIER_LAYOUT_GENERIC_READ"; break;
        case D3D12_BARRIER_LAYOUT_RENDER_TARGET: ret = "D3D12_BARRIER_LAYOUT_RENDER_TARGET"; break;
        case D3D12_BARRIER_LAYOUT_UNORDERED_ACCESS: ret = "D3D12_BARRIER_LAYOUT_UNORDERED_ACCESS"; break;
        case D3D12_BARRIER_LAYOUT_DEPTH_STENCIL_WRITE: ret = "D3D12_BARRIER_LAYOUT_DEPTH_STENCIL_WRITE"; break;
        case D3D12_BARRIER_LAYOUT_DEPTH_STENCIL_READ: ret = "D3D12_BARRIER_LAYOUT_DEPTH_STENCIL_READ"; break;
        case D3D12_BARRIER_LAYOUT_SHADER_RESOURCE: ret = "D3D12_BARRIER_LAYOUT_SHADER_RESOURCE"; break;
        case D3D12_BARRIER_LAYOUT_COPY_SOURCE: ret = "D3D12_BARRIER_LAYOUT_COPY_SOURCE"; break;
        case D3D12_BARRIER_LAYOUT_COPY_DEST: ret = "D3D12_BARRIER_LAYOUT_COPY_DEST"; break;
        case D3D12_BARRIER_LAYOUT_RESOLVE_SOURCE: ret = "D3D12_BARRIER_LAYOUT_RESOLVE_SOURCE"; break;
        case D3D12_BARRIER_LAYOUT_RESOLVE_DEST: ret = "D3D12_BARRIER_LAYOUT_RESOLVE_DEST"; break;
        case D3D12_BARRIER_LAYOUT_SHADING_RATE_SOURCE: ret = "D3D12_BARRIER_LAYOUT_SHADING_RATE_SOURCE"; break;
        case D3D12_BARRIER_LAYOUT_VIDEO_DECODE_READ: ret = "D3D12_BARRIER_LAYOUT_VIDEO_DECODE_READ"; break;
        case D3D12_BARRIER_LAYOUT_VIDEO_DECODE_WRITE: ret = "D3D12_BARRIER_LAYOUT_VIDEO_DECODE_WRITE"; break;
        case D3D12_BARRIER_LAYOUT_VIDEO_PROCESS_READ: ret = "D3D12_BARRIER_LAYOUT_VIDEO_PROCESS_READ"; break;
        case D3D12_BARRIER_LAYOUT_VIDEO_PROCESS_WRITE: ret = "D3D12_BARRIER_LAYOUT_VIDEO_PROCESS_WRITE"; break;
        case D3D12_BARRIER_LAYOUT_VIDEO_ENCODE_READ: ret = "D3D12_BARRIER_LAYOUT_VIDEO_ENCODE_READ"; break;
        case D3D12_BARRIER_LAYOUT_VIDEO_ENCODE_WRITE: ret = "D3D12_BARRIER_LAYOUT_VIDEO_ENCODE_WRITE"; break;
        case D3D12_BARRIER_LAYOUT_DIRECT_QUEUE_COMMON: ret = "D3D12_BARRIER_LAYOUT_DIRECT_QUEUE_COMMON"; break;
        case D3D12_BARRIER_LAYOUT_DIRECT_QUEUE_GENERIC_READ: ret = "D3D12_BARRIER_LAYOUT_DIRECT_QUEUE_GENERIC_READ"; break;
        case D3D12_BARRIER_LAYOUT_DIRECT_QUEUE_UNORDERED_ACCESS: ret = "D3D12_BARRIER_LAYOUT_DIRECT_QUEUE_UNORDERED_ACCESS"; break;
        case D3D12_BARRIER_LAYOUT_DIRECT_QUEUE_SHADER_RESOURCE: ret = "D3D12_BARRIER_LAYOUT_DIRECT_QUEUE_SHADER_RESOURCE"; break;
        case D3D12_BARRIER_LAYOUT_DIRECT_QUEUE_COPY_SOURCE: ret = "D3D12_BARRIER_LAYOUT_DIRECT_QUEUE_COPY_SOURCE"; break;
        case D3D12_BARRIER_LAYOUT_DIRECT_QUEUE_COPY_DEST: ret = "D3D12_BARRIER_LAYOUT_DIRECT_QUEUE_COPY_DEST"; break;
        case D3D12_BARRIER_LAYOUT_COMPUTE_QUEUE_COMMON: ret = "D3D12_BARRIER_LAYOUT_COMPUTE_QUEUE_COMMON"; break;
        case D3D12_BARRIER_LAYOUT_COMPUTE_QUEUE_GENERIC_READ: ret = "D3D12_BARRIER_LAYOUT_COMPUTE_QUEUE_GENERIC_READ"; break;
        case D3D12_BARRIER_LAYOUT_COMPUTE_QUEUE_UNORDERED_ACCESS: ret = "D3D12_BARRIER_LAYOUT_COMPUTE_QUEUE_UNORDERED_ACCESS"; break;
        case D3D12_BARRIER_LAYOUT_COMPUTE_QUEUE_SHADER_RESOURCE: ret = "D3D12_BARRIER_LAYOUT_COMPUTE_QUEUE_SHADER_RESOURCE"; break;
        case D3D12_BARRIER_LAYOUT_COMPUTE_QUEUE_COPY_SOURCE: ret = "D3D12_BARRIER_LAYOUT_COMPUTE_QUEUE_COPY_SOURCE"; break;
        case D3D12_BARRIER_LAYOUT_COMPUTE_QUEUE_COPY_DEST: ret = "D3D12_BARRIER_LAYOUT_COMPUTE_QUEUE_COPY_DEST"; break;
        case D3D12_BARRIER_LAYOUT_VIDEO_QUEUE_COMMON: ret = "D3D12_BARRIER_LAYOUT_VIDEO_QUEUE_COMMON"; break;
    }
    return ret;
}

std::string ToString(const D3D12_BARRIER_SYNC value)
{
    const char* ret = "Unhandled D3D12_BARRIER_SYNC";
    switch (value) {
        case D3D12_BARRIER_SYNC_NONE: ret = "D3D12_BARRIER_SYNC_NONE"; break;
        case D3D12_BARRIER_SYNC_ALL: ret = "D3D12_BARRIER_SYNC_ALL"; break;
        case D3D12_BARRIER_SYNC_DRAW: ret = "D3D12_BARRIER_SYNC_DRAW"; break;
        case D3D12_BARRIER_SYNC_INDEX_INPUT: ret = "D3D12_BARRIER_SYNC_INDEX_INPUT"; break;
        case D3D12_BARRIER_SYNC_VERTEX_SHADING: ret = "D3D12_BARRIER_SYNC_VERTEX_SHADING"; break;
        case D3D12_BARRIER_SYNC_PIXEL_SHADING: ret = "D3D12_BARRIER_SYNC_PIXEL_SHADING"; break;
        case D3D12_BARRIER_SYNC_DEPTH_STENCIL: ret = "D3D12_BARRIER_SYNC_DEPTH_STENCIL"; break;
        case D3D12_BARRIER_SYNC_RENDER_TARGET: ret = "D3D12_BARRIER_SYNC_RENDER_TARGET"; break;
        case D3D12_BARRIER_SYNC_COMPUTE_SHADING: ret = "D3D12_BARRIER_SYNC_COMPUTE_SHADING"; break;
        case D3D12_BARRIER_SYNC_RAYTRACING: ret = "D3D12_BARRIER_SYNC_RAYTRACING"; break;
        case D3D12_BARRIER_SYNC_COPY: ret = "D3D12_BARRIER_SYNC_COPY"; break;
        case D3D12_BARRIER_SYNC_RESOLVE: ret = "D3D12_BARRIER_SYNC_RESOLVE"; break;
        case D3D12_BARRIER_SYNC_EXECUTE_INDIRECT: ret = "D3D12_BARRIER_SYNC_EXECUTE_INDIRECT"; break;
        case D3D12_BARRIER_SYNC_ALL_SHADING: ret = "D3D12_BARRIER_SYNC_ALL_SHADING"; break;
        case D3D12_BARRIER_SYNC_NON_PIXEL_SHADING: ret = "D3D12_BARRIER_SYNC_NON_PIXEL_SHADING"; break;
        case D3D12_BARRIER_SYNC_EMIT_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO: ret = "D3D12_BARRIER_SYNC_EMIT_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO"; break;
        case D3D12_BARRIER_SYNC_CLEAR_UNORDERED_ACCESS_VIEW: ret = "D3D12_BARRIER_SYNC_CLEAR_UNORDERED_ACCESS_VIEW"; break;
        case D3D12_BARRIER_SYNC_VIDEO_DECODE: ret = "D3D12_BARRIER_SYNC_VIDEO_DECODE"; break;
        case D3D12_BARRIER_SYNC_VIDEO_PROCESS: ret = "D3D12_BARRIER_SYNC_VIDEO_PROCESS"; break;
        case D3D12_BARRIER_SYNC_VIDEO_ENCODE: ret = "D3D12_BARRIER_SYNC_VIDEO_ENCODE"; break;
        case D3D12_BARRIER_SYNC_BUILD_RAYTRACING_ACCELERATION_STRUCTURE: ret = "D3D12_BARRIER_SYNC_BUILD_RAYTRACING_ACCELERATION_STRUCTURE"; break;
        case D3D12_BARRIER_SYNC_COPY_RAYTRACING_ACCELERATION_STRUCTURE: ret = "D3D12_BARRIER_SYNC_COPY_RAYTRACING_ACCELERATION_STRUCTURE"; break;
        case D3D12_BARRIER_SYNC_SPLIT: ret = "D3D12_BARRIER_SYNC_SPLIT"; break;
    }
    return ret;
}

std::string ToString(const D3D12_BARRIER_ACCESS value)
{
    const char* ret = "Unhandled D3D12_BARRIER_ACCESS";
    switch (value) {
        case D3D12_BARRIER_ACCESS_COMMON: ret = "D3D12_BARRIER_ACCESS_COMMON"; break;
        case D3D12_BARRIER_ACCESS_VERTEX_BUFFER: ret = "D3D12_BARRIER_ACCESS_VERTEX_BUFFER"; break;
        case D3D12_BARRIER_ACCESS_CONSTANT_BUFFER: ret = "D3D12_BARRIER_ACCESS_CONSTANT_BUFFER"; break;
        case D3D12_BARRIER_ACCESS_INDEX_BUFFER: ret = "D3D12_BARRIER_ACCESS_INDEX_BUFFER"; break;
        case D3D12_BARRIER_ACCESS_RENDER_TARGET: ret = "D3D12_BARRIER_ACCESS_RENDER_TARGET"; break;
        case D3D12_BARRIER_ACCESS_UNORDERED_ACCESS: ret = "D3D12_BARRIER_ACCESS_UNORDERED_ACCESS"; break;
        case D3D12_BARRIER_ACCESS_DEPTH_STENCIL_WRITE: ret = "D3D12_BARRIER_ACCESS_DEPTH_STENCIL_WRITE"; break;
        case D3D12_BARRIER_ACCESS_DEPTH_STENCIL_READ: ret = "D3D12_BARRIER_ACCESS_DEPTH_STENCIL_READ"; break;
        case D3D12_BARRIER_ACCESS_SHADER_RESOURCE: ret = "D3D12_BARRIER_ACCESS_SHADER_RESOURCE"; break;
        case D3D12_BARRIER_ACCESS_STREAM_OUTPUT: ret = "D3D12_BARRIER_ACCESS_STREAM_OUTPUT"; break;
        case D3D12_BARRIER_ACCESS_INDIRECT_ARGUMENT: ret = "D3D12_BARRIER_ACCESS_INDIRECT_ARGUMENT"; break;
        case D3D12_BARRIER_ACCESS_COPY_DEST: ret = "D3D12_BARRIER_ACCESS_COPY_DEST"; break;
        case D3D12_BARRIER_ACCESS_COPY_SOURCE: ret = "D3D12_BARRIER_ACCESS_COPY_SOURCE"; break;
        case D3D12_BARRIER_ACCESS_RESOLVE_DEST: ret = "D3D12_BARRIER_ACCESS_RESOLVE_DEST"; break;
        case D3D12_BARRIER_ACCESS_RESOLVE_SOURCE: ret = "D3D12_BARRIER_ACCESS_RESOLVE_SOURCE"; break;
        case D3D12_BARRIER_ACCESS_RAYTRACING_ACCELERATION_STRUCTURE_READ: ret = "D3D12_BARRIER_ACCESS_RAYTRACING_ACCELERATION_STRUCTURE_READ"; break;
        case D3D12_BARRIER_ACCESS_RAYTRACING_ACCELERATION_STRUCTURE_WRITE: ret = "D3D12_BARRIER_ACCESS_RAYTRACING_ACCELERATION_STRUCTURE_WRITE"; break;
        case D3D12_BARRIER_ACCESS_SHADING_RATE_SOURCE: ret = "D3D12_BARRIER_ACCESS_SHADING_RATE_SOURCE"; break;
        case D3D12_BARRIER_ACCESS_VIDEO_DECODE_READ: ret = "D3D12_BARRIER_ACCESS_VIDEO_DECODE_READ"; break;
        case D3D12_BARRIER_ACCESS_VIDEO_DECODE_WRITE: ret = "D3D12_BARRIER_ACCESS_VIDEO_DECODE_WRITE"; break;
        case D3D12_BARRIER_ACCESS_VIDEO_PROCESS_READ: ret = "D3D12_BARRIER_ACCESS_VIDEO_PROCESS_READ"; break;
        case D3D12_BARRIER_ACCESS_VIDEO_PROCESS_WRITE: ret = "D3D12_BARRIER_ACCESS_VIDEO_PROCESS_WRITE"; break;
        case D3D12_BARRIER_ACCESS_VIDEO_ENCODE_READ: ret = "D3D12_BARRIER_ACCESS_VIDEO_ENCODE_READ"; break;
        case D3D12_BARRIER_ACCESS_VIDEO_ENCODE_WRITE: ret = "D3D12_BARRIER_ACCESS_VIDEO_ENCODE_WRITE"; break;
        case D3D12_BARRIER_ACCESS_NO_ACCESS: ret = "D3D12_BARRIER_ACCESS_NO_ACCESS"; break;
    }
    return ret;
}

std::string ToString(const D3D12_BARRIER_TYPE value)
{
    const char* ret = "Unhandled D3D12_BARRIER_TYPE";
    switch (value) {
        case D3D12_BARRIER_TYPE_GLOBAL: ret = "D3D12_BARRIER_TYPE_GLOBAL"; break;
        case D3D12_BARRIER_TYPE_TEXTURE: ret = "D3D12_BARRIER_TYPE_TEXTURE"; break;
        case D3D12_BARRIER_TYPE_BUFFER: ret = "D3D12_BARRIER_TYPE_BUFFER"; break;
    }
    return ret;
}

std::string ToString(const D3D12_TEXTURE_BARRIER_FLAGS value)
{
    const char* ret = "Unhandled D3D12_TEXTURE_BARRIER_FLAGS";
    switch (value) {
        case D3D12_TEXTURE_BARRIER_FLAG_NONE: ret = "D3D12_TEXTURE_BARRIER_FLAG_NONE"; break;
        case D3D12_TEXTURE_BARRIER_FLAG_DISCARD: ret = "D3D12_TEXTURE_BARRIER_FLAG_DISCARD"; break;
    }
    return ret;
}

std::string ToString_D3D12_TEXTURE_BARRIER_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_TEXTURE_BARRIER_FLAGS>(flags);
}

std::string ToString(const D3D12_SHADER_CACHE_KIND_FLAGS value)
{
    const char* ret = "Unhandled D3D12_SHADER_CACHE_KIND_FLAGS";
    switch (value) {
        case D3D12_SHADER_CACHE_KIND_FLAG_IMPLICIT_D3D_CACHE_FOR_DRIVER: ret = "D3D12_SHADER_CACHE_KIND_FLAG_IMPLICIT_D3D_CACHE_FOR_DRIVER"; break;
        case D3D12_SHADER_CACHE_KIND_FLAG_IMPLICIT_D3D_CONVERSIONS: ret = "D3D12_SHADER_CACHE_KIND_FLAG_IMPLICIT_D3D_CONVERSIONS"; break;
        case D3D12_SHADER_CACHE_KIND_FLAG_IMPLICIT_DRIVER_MANAGED: ret = "D3D12_SHADER_CACHE_KIND_FLAG_IMPLICIT_DRIVER_MANAGED"; break;
        case D3D12_SHADER_CACHE_KIND_FLAG_APPLICATION_MANAGED: ret = "D3D12_SHADER_CACHE_KIND_FLAG_APPLICATION_MANAGED"; break;
    }
    return ret;
}

std::string ToString_D3D12_SHADER_CACHE_KIND_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_SHADER_CACHE_KIND_FLAGS>(flags);
}

std::string ToString(const D3D12_SHADER_CACHE_CONTROL_FLAGS value)
{
    const char* ret = "Unhandled D3D12_SHADER_CACHE_CONTROL_FLAGS";
    switch (value) {
        case D3D12_SHADER_CACHE_CONTROL_FLAG_DISABLE: ret = "D3D12_SHADER_CACHE_CONTROL_FLAG_DISABLE"; break;
        case D3D12_SHADER_CACHE_CONTROL_FLAG_ENABLE: ret = "D3D12_SHADER_CACHE_CONTROL_FLAG_ENABLE"; break;
        case D3D12_SHADER_CACHE_CONTROL_FLAG_CLEAR: ret = "D3D12_SHADER_CACHE_CONTROL_FLAG_CLEAR"; break;
    }
    return ret;
}

std::string ToString_D3D12_SHADER_CACHE_CONTROL_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_SHADER_CACHE_CONTROL_FLAGS>(flags);
}

std::string ToString(const D3D12_DEVICE_FACTORY_FLAGS value)
{
    const char* ret = "Unhandled D3D12_DEVICE_FACTORY_FLAGS";
    switch (value) {
        case D3D12_DEVICE_FACTORY_FLAG_NONE: ret = "D3D12_DEVICE_FACTORY_FLAG_NONE"; break;
        case D3D12_DEVICE_FACTORY_FLAG_ALLOW_RETURNING_EXISTING_DEVICE: ret = "D3D12_DEVICE_FACTORY_FLAG_ALLOW_RETURNING_EXISTING_DEVICE"; break;
        case D3D12_DEVICE_FACTORY_FLAG_ALLOW_RETURNING_INCOMPATIBLE_EXISTING_DEVICE: ret = "D3D12_DEVICE_FACTORY_FLAG_ALLOW_RETURNING_INCOMPATIBLE_EXISTING_DEVICE"; break;
        case D3D12_DEVICE_FACTORY_FLAG_DISALLOW_STORING_NEW_DEVICE_AS_SINGLETON: ret = "D3D12_DEVICE_FACTORY_FLAG_DISALLOW_STORING_NEW_DEVICE_AS_SINGLETON"; break;
    }
    return ret;
}

std::string ToString_D3D12_DEVICE_FACTORY_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_DEVICE_FACTORY_FLAGS>(flags);
}

std::string ToString(const D3D12_DEVICE_FLAGS value)
{
    const char* ret = "Unhandled D3D12_DEVICE_FLAGS";
    switch (value) {
        case D3D12_DEVICE_FLAG_NONE: ret = "D3D12_DEVICE_FLAG_NONE"; break;
        case D3D12_DEVICE_FLAG_DEBUG_LAYER_ENABLED: ret = "D3D12_DEVICE_FLAG_DEBUG_LAYER_ENABLED"; break;
        case D3D12_DEVICE_FLAG_GPU_BASED_VALIDATION_ENABLED: ret = "D3D12_DEVICE_FLAG_GPU_BASED_VALIDATION_ENABLED"; break;
        case D3D12_DEVICE_FLAG_SYNCHRONIZED_COMMAND_QUEUE_VALIDATION_DISABLED: ret = "D3D12_DEVICE_FLAG_SYNCHRONIZED_COMMAND_QUEUE_VALIDATION_DISABLED"; break;
        case D3D12_DEVICE_FLAG_DRED_AUTO_BREADCRUMBS_ENABLED: ret = "D3D12_DEVICE_FLAG_DRED_AUTO_BREADCRUMBS_ENABLED"; break;
        case D3D12_DEVICE_FLAG_DRED_PAGE_FAULT_REPORTING_ENABLED: ret = "D3D12_DEVICE_FLAG_DRED_PAGE_FAULT_REPORTING_ENABLED"; break;
        case D3D12_DEVICE_FLAG_DRED_WATSON_REPORTING_ENABLED: ret = "D3D12_DEVICE_FLAG_DRED_WATSON_REPORTING_ENABLED"; break;
        case D3D12_DEVICE_FLAG_DRED_BREADCRUMB_CONTEXT_ENABLED: ret = "D3D12_DEVICE_FLAG_DRED_BREADCRUMB_CONTEXT_ENABLED"; break;
        case D3D12_DEVICE_FLAG_DRED_USE_MARKERS_ONLY_BREADCRUMBS: ret = "D3D12_DEVICE_FLAG_DRED_USE_MARKERS_ONLY_BREADCRUMBS"; break;
        case D3D12_DEVICE_FLAG_SHADER_INSTRUMENTATION_ENABLED: ret = "D3D12_DEVICE_FLAG_SHADER_INSTRUMENTATION_ENABLED"; break;
        case D3D12_DEVICE_FLAG_AUTO_DEBUG_NAME_ENABLED: ret = "D3D12_DEVICE_FLAG_AUTO_DEBUG_NAME_ENABLED"; break;
        case D3D12_DEVICE_FLAG_FORCE_LEGACY_STATE_VALIDATION: ret = "D3D12_DEVICE_FLAG_FORCE_LEGACY_STATE_VALIDATION"; break;
    }
    return ret;
}

std::string ToString_D3D12_DEVICE_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_DEVICE_FLAGS>(flags);
}

std::string ToString(const D3D12_AXIS_SHADING_RATE value)
{
    const char* ret = "Unhandled D3D12_AXIS_SHADING_RATE";
    switch (value) {
        case D3D12_AXIS_SHADING_RATE_1X: ret = "D3D12_AXIS_SHADING_RATE_1X"; break;
        case D3D12_AXIS_SHADING_RATE_2X: ret = "D3D12_AXIS_SHADING_RATE_2X"; break;
        case D3D12_AXIS_SHADING_RATE_4X: ret = "D3D12_AXIS_SHADING_RATE_4X"; break;
    }
    return ret;
}

std::string ToString(const D3D12_SHADING_RATE value)
{
    const char* ret = "Unhandled D3D12_SHADING_RATE";
    switch (value) {
        case D3D12_SHADING_RATE_1X1: ret = "D3D12_SHADING_RATE_1X1"; break;
        case D3D12_SHADING_RATE_1X2: ret = "D3D12_SHADING_RATE_1X2"; break;
        case D3D12_SHADING_RATE_2X1: ret = "D3D12_SHADING_RATE_2X1"; break;
        case D3D12_SHADING_RATE_2X2: ret = "D3D12_SHADING_RATE_2X2"; break;
        case D3D12_SHADING_RATE_2X4: ret = "D3D12_SHADING_RATE_2X4"; break;
        case D3D12_SHADING_RATE_4X2: ret = "D3D12_SHADING_RATE_4X2"; break;
        case D3D12_SHADING_RATE_4X4: ret = "D3D12_SHADING_RATE_4X4"; break;
    }
    return ret;
}

std::string ToString(const D3D12_SHADING_RATE_COMBINER value)
{
    const char* ret = "Unhandled D3D12_SHADING_RATE_COMBINER";
    switch (value) {
        case D3D12_SHADING_RATE_COMBINER_PASSTHROUGH: ret = "D3D12_SHADING_RATE_COMBINER_PASSTHROUGH"; break;
        case D3D12_SHADING_RATE_COMBINER_OVERRIDE: ret = "D3D12_SHADING_RATE_COMBINER_OVERRIDE"; break;
        case D3D12_SHADING_RATE_COMBINER_MIN: ret = "D3D12_SHADING_RATE_COMBINER_MIN"; break;
        case D3D12_SHADING_RATE_COMBINER_MAX: ret = "D3D12_SHADING_RATE_COMBINER_MAX"; break;
        case D3D12_SHADING_RATE_COMBINER_SUM: ret = "D3D12_SHADING_RATE_COMBINER_SUM"; break;
    }
    return ret;
}

std::string ToString(const D3D_DRIVER_TYPE value)
{
    const char* ret = "Unhandled D3D_DRIVER_TYPE";
    switch (value) {
        case D3D_DRIVER_TYPE_UNKNOWN: ret = "D3D_DRIVER_TYPE_UNKNOWN"; break;
        case D3D_DRIVER_TYPE_HARDWARE: ret = "D3D_DRIVER_TYPE_HARDWARE"; break;
        case D3D_DRIVER_TYPE_REFERENCE: ret = "D3D_DRIVER_TYPE_REFERENCE"; break;
        case D3D_DRIVER_TYPE_NULL: ret = "D3D_DRIVER_TYPE_NULL"; break;
        case D3D_DRIVER_TYPE_SOFTWARE: ret = "D3D_DRIVER_TYPE_SOFTWARE"; break;
        case D3D_DRIVER_TYPE_WARP: ret = "D3D_DRIVER_TYPE_WARP"; break;
    }
    return ret;
}

std::string ToString(const D3D_FEATURE_LEVEL value)
{
    const char* ret = "Unhandled D3D_FEATURE_LEVEL";
    switch (value) {
        case D3D_FEATURE_LEVEL_1_0_CORE: ret = "D3D_FEATURE_LEVEL_1_0_CORE"; break;
        case D3D_FEATURE_LEVEL_9_1: ret = "D3D_FEATURE_LEVEL_9_1"; break;
        case D3D_FEATURE_LEVEL_9_2: ret = "D3D_FEATURE_LEVEL_9_2"; break;
        case D3D_FEATURE_LEVEL_9_3: ret = "D3D_FEATURE_LEVEL_9_3"; break;
        case D3D_FEATURE_LEVEL_10_0: ret = "D3D_FEATURE_LEVEL_10_0"; break;
        case D3D_FEATURE_LEVEL_10_1: ret = "D3D_FEATURE_LEVEL_10_1"; break;
        case D3D_FEATURE_LEVEL_11_0: ret = "D3D_FEATURE_LEVEL_11_0"; break;
        case D3D_FEATURE_LEVEL_11_1: ret = "D3D_FEATURE_LEVEL_11_1"; break;
        case D3D_FEATURE_LEVEL_12_0: ret = "D3D_FEATURE_LEVEL_12_0"; break;
        case D3D_FEATURE_LEVEL_12_1: ret = "D3D_FEATURE_LEVEL_12_1"; break;
        case D3D_FEATURE_LEVEL_12_2: ret = "D3D_FEATURE_LEVEL_12_2"; break;
    }
    return ret;
}

std::string ToString(const D3D_PRIMITIVE_TOPOLOGY value)
{
    const char* ret = "Unhandled D3D_PRIMITIVE_TOPOLOGY";
    switch (value) {
        case D3D_PRIMITIVE_TOPOLOGY_UNDEFINED: ret = "D3D_PRIMITIVE_TOPOLOGY_UNDEFINED"; break;
        case D3D_PRIMITIVE_TOPOLOGY_POINTLIST: ret = "D3D_PRIMITIVE_TOPOLOGY_POINTLIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_LINELIST: ret = "D3D_PRIMITIVE_TOPOLOGY_LINELIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_LINESTRIP: ret = "D3D_PRIMITIVE_TOPOLOGY_LINESTRIP"; break;
        case D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST: ret = "D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP: ret = "D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP"; break;
        case D3D_PRIMITIVE_TOPOLOGY_TRIANGLEFAN: ret = "D3D_PRIMITIVE_TOPOLOGY_TRIANGLEFAN"; break;
        case D3D_PRIMITIVE_TOPOLOGY_LINELIST_ADJ: ret = "D3D_PRIMITIVE_TOPOLOGY_LINELIST_ADJ"; break;
        case D3D_PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ: ret = "D3D_PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ"; break;
        case D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ: ret = "D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ"; break;
        case D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ: ret = "D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ"; break;
        case D3D_PRIMITIVE_TOPOLOGY_1_CONTROL_POINT_PATCHLIST: ret = "D3D_PRIMITIVE_TOPOLOGY_1_CONTROL_POINT_PATCHLIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_2_CONTROL_POINT_PATCHLIST: ret = "D3D_PRIMITIVE_TOPOLOGY_2_CONTROL_POINT_PATCHLIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_3_CONTROL_POINT_PATCHLIST: ret = "D3D_PRIMITIVE_TOPOLOGY_3_CONTROL_POINT_PATCHLIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_4_CONTROL_POINT_PATCHLIST: ret = "D3D_PRIMITIVE_TOPOLOGY_4_CONTROL_POINT_PATCHLIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_5_CONTROL_POINT_PATCHLIST: ret = "D3D_PRIMITIVE_TOPOLOGY_5_CONTROL_POINT_PATCHLIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_6_CONTROL_POINT_PATCHLIST: ret = "D3D_PRIMITIVE_TOPOLOGY_6_CONTROL_POINT_PATCHLIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_7_CONTROL_POINT_PATCHLIST: ret = "D3D_PRIMITIVE_TOPOLOGY_7_CONTROL_POINT_PATCHLIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_8_CONTROL_POINT_PATCHLIST: ret = "D3D_PRIMITIVE_TOPOLOGY_8_CONTROL_POINT_PATCHLIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_9_CONTROL_POINT_PATCHLIST: ret = "D3D_PRIMITIVE_TOPOLOGY_9_CONTROL_POINT_PATCHLIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_10_CONTROL_POINT_PATCHLIST: ret = "D3D_PRIMITIVE_TOPOLOGY_10_CONTROL_POINT_PATCHLIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_11_CONTROL_POINT_PATCHLIST: ret = "D3D_PRIMITIVE_TOPOLOGY_11_CONTROL_POINT_PATCHLIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_12_CONTROL_POINT_PATCHLIST: ret = "D3D_PRIMITIVE_TOPOLOGY_12_CONTROL_POINT_PATCHLIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_13_CONTROL_POINT_PATCHLIST: ret = "D3D_PRIMITIVE_TOPOLOGY_13_CONTROL_POINT_PATCHLIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_14_CONTROL_POINT_PATCHLIST: ret = "D3D_PRIMITIVE_TOPOLOGY_14_CONTROL_POINT_PATCHLIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_15_CONTROL_POINT_PATCHLIST: ret = "D3D_PRIMITIVE_TOPOLOGY_15_CONTROL_POINT_PATCHLIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_16_CONTROL_POINT_PATCHLIST: ret = "D3D_PRIMITIVE_TOPOLOGY_16_CONTROL_POINT_PATCHLIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_17_CONTROL_POINT_PATCHLIST: ret = "D3D_PRIMITIVE_TOPOLOGY_17_CONTROL_POINT_PATCHLIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_18_CONTROL_POINT_PATCHLIST: ret = "D3D_PRIMITIVE_TOPOLOGY_18_CONTROL_POINT_PATCHLIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_19_CONTROL_POINT_PATCHLIST: ret = "D3D_PRIMITIVE_TOPOLOGY_19_CONTROL_POINT_PATCHLIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_20_CONTROL_POINT_PATCHLIST: ret = "D3D_PRIMITIVE_TOPOLOGY_20_CONTROL_POINT_PATCHLIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_21_CONTROL_POINT_PATCHLIST: ret = "D3D_PRIMITIVE_TOPOLOGY_21_CONTROL_POINT_PATCHLIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_22_CONTROL_POINT_PATCHLIST: ret = "D3D_PRIMITIVE_TOPOLOGY_22_CONTROL_POINT_PATCHLIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_23_CONTROL_POINT_PATCHLIST: ret = "D3D_PRIMITIVE_TOPOLOGY_23_CONTROL_POINT_PATCHLIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_24_CONTROL_POINT_PATCHLIST: ret = "D3D_PRIMITIVE_TOPOLOGY_24_CONTROL_POINT_PATCHLIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_25_CONTROL_POINT_PATCHLIST: ret = "D3D_PRIMITIVE_TOPOLOGY_25_CONTROL_POINT_PATCHLIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_26_CONTROL_POINT_PATCHLIST: ret = "D3D_PRIMITIVE_TOPOLOGY_26_CONTROL_POINT_PATCHLIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_27_CONTROL_POINT_PATCHLIST: ret = "D3D_PRIMITIVE_TOPOLOGY_27_CONTROL_POINT_PATCHLIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_28_CONTROL_POINT_PATCHLIST: ret = "D3D_PRIMITIVE_TOPOLOGY_28_CONTROL_POINT_PATCHLIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_29_CONTROL_POINT_PATCHLIST: ret = "D3D_PRIMITIVE_TOPOLOGY_29_CONTROL_POINT_PATCHLIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_30_CONTROL_POINT_PATCHLIST: ret = "D3D_PRIMITIVE_TOPOLOGY_30_CONTROL_POINT_PATCHLIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_31_CONTROL_POINT_PATCHLIST: ret = "D3D_PRIMITIVE_TOPOLOGY_31_CONTROL_POINT_PATCHLIST"; break;
        case D3D_PRIMITIVE_TOPOLOGY_32_CONTROL_POINT_PATCHLIST: ret = "D3D_PRIMITIVE_TOPOLOGY_32_CONTROL_POINT_PATCHLIST"; break;
    }
    return ret;
}

std::string ToString(const D3D_PRIMITIVE value)
{
    const char* ret = "Unhandled D3D_PRIMITIVE";
    switch (value) {
        case D3D_PRIMITIVE_UNDEFINED: ret = "D3D_PRIMITIVE_UNDEFINED"; break;
        case D3D_PRIMITIVE_POINT: ret = "D3D_PRIMITIVE_POINT"; break;
        case D3D_PRIMITIVE_LINE: ret = "D3D_PRIMITIVE_LINE"; break;
        case D3D_PRIMITIVE_TRIANGLE: ret = "D3D_PRIMITIVE_TRIANGLE"; break;
        case D3D_PRIMITIVE_LINE_ADJ: ret = "D3D_PRIMITIVE_LINE_ADJ"; break;
        case D3D_PRIMITIVE_TRIANGLE_ADJ: ret = "D3D_PRIMITIVE_TRIANGLE_ADJ"; break;
        case D3D_PRIMITIVE_1_CONTROL_POINT_PATCH: ret = "D3D_PRIMITIVE_1_CONTROL_POINT_PATCH"; break;
        case D3D_PRIMITIVE_2_CONTROL_POINT_PATCH: ret = "D3D_PRIMITIVE_2_CONTROL_POINT_PATCH"; break;
        case D3D_PRIMITIVE_3_CONTROL_POINT_PATCH: ret = "D3D_PRIMITIVE_3_CONTROL_POINT_PATCH"; break;
        case D3D_PRIMITIVE_4_CONTROL_POINT_PATCH: ret = "D3D_PRIMITIVE_4_CONTROL_POINT_PATCH"; break;
        case D3D_PRIMITIVE_5_CONTROL_POINT_PATCH: ret = "D3D_PRIMITIVE_5_CONTROL_POINT_PATCH"; break;
        case D3D_PRIMITIVE_6_CONTROL_POINT_PATCH: ret = "D3D_PRIMITIVE_6_CONTROL_POINT_PATCH"; break;
        case D3D_PRIMITIVE_7_CONTROL_POINT_PATCH: ret = "D3D_PRIMITIVE_7_CONTROL_POINT_PATCH"; break;
        case D3D_PRIMITIVE_8_CONTROL_POINT_PATCH: ret = "D3D_PRIMITIVE_8_CONTROL_POINT_PATCH"; break;
        case D3D_PRIMITIVE_9_CONTROL_POINT_PATCH: ret = "D3D_PRIMITIVE_9_CONTROL_POINT_PATCH"; break;
        case D3D_PRIMITIVE_10_CONTROL_POINT_PATCH: ret = "D3D_PRIMITIVE_10_CONTROL_POINT_PATCH"; break;
        case D3D_PRIMITIVE_11_CONTROL_POINT_PATCH: ret = "D3D_PRIMITIVE_11_CONTROL_POINT_PATCH"; break;
        case D3D_PRIMITIVE_12_CONTROL_POINT_PATCH: ret = "D3D_PRIMITIVE_12_CONTROL_POINT_PATCH"; break;
        case D3D_PRIMITIVE_13_CONTROL_POINT_PATCH: ret = "D3D_PRIMITIVE_13_CONTROL_POINT_PATCH"; break;
        case D3D_PRIMITIVE_14_CONTROL_POINT_PATCH: ret = "D3D_PRIMITIVE_14_CONTROL_POINT_PATCH"; break;
        case D3D_PRIMITIVE_15_CONTROL_POINT_PATCH: ret = "D3D_PRIMITIVE_15_CONTROL_POINT_PATCH"; break;
        case D3D_PRIMITIVE_16_CONTROL_POINT_PATCH: ret = "D3D_PRIMITIVE_16_CONTROL_POINT_PATCH"; break;
        case D3D_PRIMITIVE_17_CONTROL_POINT_PATCH: ret = "D3D_PRIMITIVE_17_CONTROL_POINT_PATCH"; break;
        case D3D_PRIMITIVE_18_CONTROL_POINT_PATCH: ret = "D3D_PRIMITIVE_18_CONTROL_POINT_PATCH"; break;
        case D3D_PRIMITIVE_19_CONTROL_POINT_PATCH: ret = "D3D_PRIMITIVE_19_CONTROL_POINT_PATCH"; break;
        case D3D_PRIMITIVE_20_CONTROL_POINT_PATCH: ret = "D3D_PRIMITIVE_20_CONTROL_POINT_PATCH"; break;
        case D3D_PRIMITIVE_21_CONTROL_POINT_PATCH: ret = "D3D_PRIMITIVE_21_CONTROL_POINT_PATCH"; break;
        case D3D_PRIMITIVE_22_CONTROL_POINT_PATCH: ret = "D3D_PRIMITIVE_22_CONTROL_POINT_PATCH"; break;
        case D3D_PRIMITIVE_23_CONTROL_POINT_PATCH: ret = "D3D_PRIMITIVE_23_CONTROL_POINT_PATCH"; break;
        case D3D_PRIMITIVE_24_CONTROL_POINT_PATCH: ret = "D3D_PRIMITIVE_24_CONTROL_POINT_PATCH"; break;
        case D3D_PRIMITIVE_25_CONTROL_POINT_PATCH: ret = "D3D_PRIMITIVE_25_CONTROL_POINT_PATCH"; break;
        case D3D_PRIMITIVE_26_CONTROL_POINT_PATCH: ret = "D3D_PRIMITIVE_26_CONTROL_POINT_PATCH"; break;
        case D3D_PRIMITIVE_27_CONTROL_POINT_PATCH: ret = "D3D_PRIMITIVE_27_CONTROL_POINT_PATCH"; break;
        case D3D_PRIMITIVE_28_CONTROL_POINT_PATCH: ret = "D3D_PRIMITIVE_28_CONTROL_POINT_PATCH"; break;
        case D3D_PRIMITIVE_29_CONTROL_POINT_PATCH: ret = "D3D_PRIMITIVE_29_CONTROL_POINT_PATCH"; break;
        case D3D_PRIMITIVE_30_CONTROL_POINT_PATCH: ret = "D3D_PRIMITIVE_30_CONTROL_POINT_PATCH"; break;
        case D3D_PRIMITIVE_31_CONTROL_POINT_PATCH: ret = "D3D_PRIMITIVE_31_CONTROL_POINT_PATCH"; break;
        case D3D_PRIMITIVE_32_CONTROL_POINT_PATCH: ret = "D3D_PRIMITIVE_32_CONTROL_POINT_PATCH"; break;
    }
    return ret;
}

std::string ToString(const D3D_SRV_DIMENSION value)
{
    const char* ret = "Unhandled D3D_SRV_DIMENSION";
    switch (value) {
        case D3D_SRV_DIMENSION_UNKNOWN: ret = "D3D_SRV_DIMENSION_UNKNOWN"; break;
        case D3D_SRV_DIMENSION_BUFFER: ret = "D3D_SRV_DIMENSION_BUFFER"; break;
        case D3D_SRV_DIMENSION_TEXTURE1D: ret = "D3D_SRV_DIMENSION_TEXTURE1D"; break;
        case D3D_SRV_DIMENSION_TEXTURE1DARRAY: ret = "D3D_SRV_DIMENSION_TEXTURE1DARRAY"; break;
        case D3D_SRV_DIMENSION_TEXTURE2D: ret = "D3D_SRV_DIMENSION_TEXTURE2D"; break;
        case D3D_SRV_DIMENSION_TEXTURE2DARRAY: ret = "D3D_SRV_DIMENSION_TEXTURE2DARRAY"; break;
        case D3D_SRV_DIMENSION_TEXTURE2DMS: ret = "D3D_SRV_DIMENSION_TEXTURE2DMS"; break;
        case D3D_SRV_DIMENSION_TEXTURE2DMSARRAY: ret = "D3D_SRV_DIMENSION_TEXTURE2DMSARRAY"; break;
        case D3D_SRV_DIMENSION_TEXTURE3D: ret = "D3D_SRV_DIMENSION_TEXTURE3D"; break;
        case D3D_SRV_DIMENSION_TEXTURECUBE: ret = "D3D_SRV_DIMENSION_TEXTURECUBE"; break;
        case D3D_SRV_DIMENSION_TEXTURECUBEARRAY: ret = "D3D_SRV_DIMENSION_TEXTURECUBEARRAY"; break;
        case D3D_SRV_DIMENSION_BUFFEREX: ret = "D3D_SRV_DIMENSION_BUFFEREX"; break;
    }
    return ret;
}

std::string ToString(const D3D_INCLUDE_TYPE value)
{
    const char* ret = "Unhandled D3D_INCLUDE_TYPE";
    switch (value) {
        case D3D_INCLUDE_LOCAL: ret = "D3D_INCLUDE_LOCAL"; break;
        case D3D_INCLUDE_SYSTEM: ret = "D3D_INCLUDE_SYSTEM"; break;
        case D3D_INCLUDE_FORCE_DWORD: ret = "D3D_INCLUDE_FORCE_DWORD"; break;
    }
    return ret;
}

std::string ToString(const D3D_SHADER_VARIABLE_CLASS value)
{
    const char* ret = "Unhandled D3D_SHADER_VARIABLE_CLASS";
    switch (value) {
        case D3D_SVC_SCALAR: ret = "D3D_SVC_SCALAR"; break;
        case D3D_SVC_VECTOR: ret = "D3D_SVC_VECTOR"; break;
        case D3D_SVC_MATRIX_ROWS: ret = "D3D_SVC_MATRIX_ROWS"; break;
        case D3D_SVC_MATRIX_COLUMNS: ret = "D3D_SVC_MATRIX_COLUMNS"; break;
        case D3D_SVC_OBJECT: ret = "D3D_SVC_OBJECT"; break;
        case D3D_SVC_STRUCT: ret = "D3D_SVC_STRUCT"; break;
        case D3D_SVC_INTERFACE_CLASS: ret = "D3D_SVC_INTERFACE_CLASS"; break;
        case D3D_SVC_INTERFACE_POINTER: ret = "D3D_SVC_INTERFACE_POINTER"; break;
        case D3D_SVC_FORCE_DWORD: ret = "D3D_SVC_FORCE_DWORD"; break;
    }
    return ret;
}

std::string ToString(const D3D_SHADER_VARIABLE_FLAGS value)
{
    const char* ret = "Unhandled D3D_SHADER_VARIABLE_FLAGS";
    switch (value) {
        case D3D_SVF_USERPACKED: ret = "D3D_SVF_USERPACKED"; break;
        case D3D_SVF_USED: ret = "D3D_SVF_USED"; break;
        case D3D_SVF_INTERFACE_POINTER: ret = "D3D_SVF_INTERFACE_POINTER"; break;
        case D3D_SVF_INTERFACE_PARAMETER: ret = "D3D_SVF_INTERFACE_PARAMETER"; break;
        case D3D_SVF_FORCE_DWORD: ret = "D3D_SVF_FORCE_DWORD"; break;
    }
    return ret;
}

std::string ToString_D3D_SHADER_VARIABLE_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D_SHADER_VARIABLE_FLAGS>(flags);
}

std::string ToString(const D3D_SHADER_VARIABLE_TYPE value)
{
    const char* ret = "Unhandled D3D_SHADER_VARIABLE_TYPE";
    switch (value) {
        case D3D_SVT_VOID: ret = "D3D_SVT_VOID"; break;
        case D3D_SVT_BOOL: ret = "D3D_SVT_BOOL"; break;
        case D3D_SVT_INT: ret = "D3D_SVT_INT"; break;
        case D3D_SVT_FLOAT: ret = "D3D_SVT_FLOAT"; break;
        case D3D_SVT_STRING: ret = "D3D_SVT_STRING"; break;
        case D3D_SVT_TEXTURE: ret = "D3D_SVT_TEXTURE"; break;
        case D3D_SVT_TEXTURE1D: ret = "D3D_SVT_TEXTURE1D"; break;
        case D3D_SVT_TEXTURE2D: ret = "D3D_SVT_TEXTURE2D"; break;
        case D3D_SVT_TEXTURE3D: ret = "D3D_SVT_TEXTURE3D"; break;
        case D3D_SVT_TEXTURECUBE: ret = "D3D_SVT_TEXTURECUBE"; break;
        case D3D_SVT_SAMPLER: ret = "D3D_SVT_SAMPLER"; break;
        case D3D_SVT_SAMPLER1D: ret = "D3D_SVT_SAMPLER1D"; break;
        case D3D_SVT_SAMPLER2D: ret = "D3D_SVT_SAMPLER2D"; break;
        case D3D_SVT_SAMPLER3D: ret = "D3D_SVT_SAMPLER3D"; break;
        case D3D_SVT_SAMPLERCUBE: ret = "D3D_SVT_SAMPLERCUBE"; break;
        case D3D_SVT_PIXELSHADER: ret = "D3D_SVT_PIXELSHADER"; break;
        case D3D_SVT_VERTEXSHADER: ret = "D3D_SVT_VERTEXSHADER"; break;
        case D3D_SVT_PIXELFRAGMENT: ret = "D3D_SVT_PIXELFRAGMENT"; break;
        case D3D_SVT_VERTEXFRAGMENT: ret = "D3D_SVT_VERTEXFRAGMENT"; break;
        case D3D_SVT_UINT: ret = "D3D_SVT_UINT"; break;
        case D3D_SVT_UINT8: ret = "D3D_SVT_UINT8"; break;
        case D3D_SVT_GEOMETRYSHADER: ret = "D3D_SVT_GEOMETRYSHADER"; break;
        case D3D_SVT_RASTERIZER: ret = "D3D_SVT_RASTERIZER"; break;
        case D3D_SVT_DEPTHSTENCIL: ret = "D3D_SVT_DEPTHSTENCIL"; break;
        case D3D_SVT_BLEND: ret = "D3D_SVT_BLEND"; break;
        case D3D_SVT_BUFFER: ret = "D3D_SVT_BUFFER"; break;
        case D3D_SVT_CBUFFER: ret = "D3D_SVT_CBUFFER"; break;
        case D3D_SVT_TBUFFER: ret = "D3D_SVT_TBUFFER"; break;
        case D3D_SVT_TEXTURE1DARRAY: ret = "D3D_SVT_TEXTURE1DARRAY"; break;
        case D3D_SVT_TEXTURE2DARRAY: ret = "D3D_SVT_TEXTURE2DARRAY"; break;
        case D3D_SVT_RENDERTARGETVIEW: ret = "D3D_SVT_RENDERTARGETVIEW"; break;
        case D3D_SVT_DEPTHSTENCILVIEW: ret = "D3D_SVT_DEPTHSTENCILVIEW"; break;
        case D3D_SVT_TEXTURE2DMS: ret = "D3D_SVT_TEXTURE2DMS"; break;
        case D3D_SVT_TEXTURE2DMSARRAY: ret = "D3D_SVT_TEXTURE2DMSARRAY"; break;
        case D3D_SVT_TEXTURECUBEARRAY: ret = "D3D_SVT_TEXTURECUBEARRAY"; break;
        case D3D_SVT_HULLSHADER: ret = "D3D_SVT_HULLSHADER"; break;
        case D3D_SVT_DOMAINSHADER: ret = "D3D_SVT_DOMAINSHADER"; break;
        case D3D_SVT_INTERFACE_POINTER: ret = "D3D_SVT_INTERFACE_POINTER"; break;
        case D3D_SVT_COMPUTESHADER: ret = "D3D_SVT_COMPUTESHADER"; break;
        case D3D_SVT_DOUBLE: ret = "D3D_SVT_DOUBLE"; break;
        case D3D_SVT_RWTEXTURE1D: ret = "D3D_SVT_RWTEXTURE1D"; break;
        case D3D_SVT_RWTEXTURE1DARRAY: ret = "D3D_SVT_RWTEXTURE1DARRAY"; break;
        case D3D_SVT_RWTEXTURE2D: ret = "D3D_SVT_RWTEXTURE2D"; break;
        case D3D_SVT_RWTEXTURE2DARRAY: ret = "D3D_SVT_RWTEXTURE2DARRAY"; break;
        case D3D_SVT_RWTEXTURE3D: ret = "D3D_SVT_RWTEXTURE3D"; break;
        case D3D_SVT_RWBUFFER: ret = "D3D_SVT_RWBUFFER"; break;
        case D3D_SVT_BYTEADDRESS_BUFFER: ret = "D3D_SVT_BYTEADDRESS_BUFFER"; break;
        case D3D_SVT_RWBYTEADDRESS_BUFFER: ret = "D3D_SVT_RWBYTEADDRESS_BUFFER"; break;
        case D3D_SVT_STRUCTURED_BUFFER: ret = "D3D_SVT_STRUCTURED_BUFFER"; break;
        case D3D_SVT_RWSTRUCTURED_BUFFER: ret = "D3D_SVT_RWSTRUCTURED_BUFFER"; break;
        case D3D_SVT_APPEND_STRUCTURED_BUFFER: ret = "D3D_SVT_APPEND_STRUCTURED_BUFFER"; break;
        case D3D_SVT_CONSUME_STRUCTURED_BUFFER: ret = "D3D_SVT_CONSUME_STRUCTURED_BUFFER"; break;
        case D3D_SVT_MIN8FLOAT: ret = "D3D_SVT_MIN8FLOAT"; break;
        case D3D_SVT_MIN10FLOAT: ret = "D3D_SVT_MIN10FLOAT"; break;
        case D3D_SVT_MIN16FLOAT: ret = "D3D_SVT_MIN16FLOAT"; break;
        case D3D_SVT_MIN12INT: ret = "D3D_SVT_MIN12INT"; break;
        case D3D_SVT_MIN16INT: ret = "D3D_SVT_MIN16INT"; break;
        case D3D_SVT_MIN16UINT: ret = "D3D_SVT_MIN16UINT"; break;
        case D3D_SVT_INT16: ret = "D3D_SVT_INT16"; break;
        case D3D_SVT_UINT16: ret = "D3D_SVT_UINT16"; break;
        case D3D_SVT_FLOAT16: ret = "D3D_SVT_FLOAT16"; break;
        case D3D_SVT_INT64: ret = "D3D_SVT_INT64"; break;
        case D3D_SVT_UINT64: ret = "D3D_SVT_UINT64"; break;
        case D3D_SVT_FORCE_DWORD: ret = "D3D_SVT_FORCE_DWORD"; break;
    }
    return ret;
}

std::string ToString(const D3D_SHADER_INPUT_FLAGS value)
{
    const char* ret = "Unhandled D3D_SHADER_INPUT_FLAGS";
    switch (value) {
        case D3D_SIF_USERPACKED: ret = "D3D_SIF_USERPACKED"; break;
        case D3D_SIF_COMPARISON_SAMPLER: ret = "D3D_SIF_COMPARISON_SAMPLER"; break;
        case D3D_SIF_TEXTURE_COMPONENT_0: ret = "D3D_SIF_TEXTURE_COMPONENT_0"; break;
        case D3D_SIF_TEXTURE_COMPONENT_1: ret = "D3D_SIF_TEXTURE_COMPONENT_1"; break;
        case D3D_SIF_TEXTURE_COMPONENTS: ret = "D3D_SIF_TEXTURE_COMPONENTS"; break;
        case D3D_SIF_UNUSED: ret = "D3D_SIF_UNUSED"; break;
        case D3D_SIF_FORCE_DWORD: ret = "D3D_SIF_FORCE_DWORD"; break;
    }
    return ret;
}

std::string ToString_D3D_SHADER_INPUT_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D_SHADER_INPUT_FLAGS>(flags);
}

std::string ToString(const D3D_SHADER_INPUT_TYPE value)
{
    const char* ret = "Unhandled D3D_SHADER_INPUT_TYPE";
    switch (value) {
        case D3D_SIT_CBUFFER: ret = "D3D_SIT_CBUFFER"; break;
        case D3D_SIT_TBUFFER: ret = "D3D_SIT_TBUFFER"; break;
        case D3D_SIT_TEXTURE: ret = "D3D_SIT_TEXTURE"; break;
        case D3D_SIT_SAMPLER: ret = "D3D_SIT_SAMPLER"; break;
        case D3D_SIT_UAV_RWTYPED: ret = "D3D_SIT_UAV_RWTYPED"; break;
        case D3D_SIT_STRUCTURED: ret = "D3D_SIT_STRUCTURED"; break;
        case D3D_SIT_UAV_RWSTRUCTURED: ret = "D3D_SIT_UAV_RWSTRUCTURED"; break;
        case D3D_SIT_BYTEADDRESS: ret = "D3D_SIT_BYTEADDRESS"; break;
        case D3D_SIT_UAV_RWBYTEADDRESS: ret = "D3D_SIT_UAV_RWBYTEADDRESS"; break;
        case D3D_SIT_UAV_APPEND_STRUCTURED: ret = "D3D_SIT_UAV_APPEND_STRUCTURED"; break;
        case D3D_SIT_UAV_CONSUME_STRUCTURED: ret = "D3D_SIT_UAV_CONSUME_STRUCTURED"; break;
        case D3D_SIT_UAV_RWSTRUCTURED_WITH_COUNTER: ret = "D3D_SIT_UAV_RWSTRUCTURED_WITH_COUNTER"; break;
        case D3D_SIT_RTACCELERATIONSTRUCTURE: ret = "D3D_SIT_RTACCELERATIONSTRUCTURE"; break;
        case D3D_SIT_UAV_FEEDBACKTEXTURE: ret = "D3D_SIT_UAV_FEEDBACKTEXTURE"; break;
    }
    return ret;
}

std::string ToString(const D3D_SHADER_CBUFFER_FLAGS value)
{
    const char* ret = "Unhandled D3D_SHADER_CBUFFER_FLAGS";
    switch (value) {
        case D3D_CBF_USERPACKED: ret = "D3D_CBF_USERPACKED"; break;
        case D3D_CBF_FORCE_DWORD: ret = "D3D_CBF_FORCE_DWORD"; break;
    }
    return ret;
}

std::string ToString_D3D_SHADER_CBUFFER_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D_SHADER_CBUFFER_FLAGS>(flags);
}

std::string ToString(const D3D_CBUFFER_TYPE value)
{
    const char* ret = "Unhandled D3D_CBUFFER_TYPE";
    switch (value) {
        case D3D_CT_CBUFFER: ret = "D3D_CT_CBUFFER"; break;
        case D3D_CT_TBUFFER: ret = "D3D_CT_TBUFFER"; break;
        case D3D_CT_INTERFACE_POINTERS: ret = "D3D_CT_INTERFACE_POINTERS"; break;
        case D3D_CT_RESOURCE_BIND_INFO: ret = "D3D_CT_RESOURCE_BIND_INFO"; break;
    }
    return ret;
}

std::string ToString(const D3D_NAME value)
{
    const char* ret = "Unhandled D3D_NAME";
    switch (value) {
        case D3D_NAME_UNDEFINED: ret = "D3D_NAME_UNDEFINED"; break;
        case D3D_NAME_POSITION: ret = "D3D_NAME_POSITION"; break;
        case D3D_NAME_CLIP_DISTANCE: ret = "D3D_NAME_CLIP_DISTANCE"; break;
        case D3D_NAME_CULL_DISTANCE: ret = "D3D_NAME_CULL_DISTANCE"; break;
        case D3D_NAME_RENDER_TARGET_ARRAY_INDEX: ret = "D3D_NAME_RENDER_TARGET_ARRAY_INDEX"; break;
        case D3D_NAME_VIEWPORT_ARRAY_INDEX: ret = "D3D_NAME_VIEWPORT_ARRAY_INDEX"; break;
        case D3D_NAME_VERTEX_ID: ret = "D3D_NAME_VERTEX_ID"; break;
        case D3D_NAME_PRIMITIVE_ID: ret = "D3D_NAME_PRIMITIVE_ID"; break;
        case D3D_NAME_INSTANCE_ID: ret = "D3D_NAME_INSTANCE_ID"; break;
        case D3D_NAME_IS_FRONT_FACE: ret = "D3D_NAME_IS_FRONT_FACE"; break;
        case D3D_NAME_SAMPLE_INDEX: ret = "D3D_NAME_SAMPLE_INDEX"; break;
        case D3D_NAME_FINAL_QUAD_EDGE_TESSFACTOR: ret = "D3D_NAME_FINAL_QUAD_EDGE_TESSFACTOR"; break;
        case D3D_NAME_FINAL_QUAD_INSIDE_TESSFACTOR: ret = "D3D_NAME_FINAL_QUAD_INSIDE_TESSFACTOR"; break;
        case D3D_NAME_FINAL_TRI_EDGE_TESSFACTOR: ret = "D3D_NAME_FINAL_TRI_EDGE_TESSFACTOR"; break;
        case D3D_NAME_FINAL_TRI_INSIDE_TESSFACTOR: ret = "D3D_NAME_FINAL_TRI_INSIDE_TESSFACTOR"; break;
        case D3D_NAME_FINAL_LINE_DETAIL_TESSFACTOR: ret = "D3D_NAME_FINAL_LINE_DETAIL_TESSFACTOR"; break;
        case D3D_NAME_FINAL_LINE_DENSITY_TESSFACTOR: ret = "D3D_NAME_FINAL_LINE_DENSITY_TESSFACTOR"; break;
        case D3D_NAME_BARYCENTRICS: ret = "D3D_NAME_BARYCENTRICS"; break;
        case D3D_NAME_SHADINGRATE: ret = "D3D_NAME_SHADINGRATE"; break;
        case D3D_NAME_CULLPRIMITIVE: ret = "D3D_NAME_CULLPRIMITIVE"; break;
        case D3D_NAME_TARGET: ret = "D3D_NAME_TARGET"; break;
        case D3D_NAME_DEPTH: ret = "D3D_NAME_DEPTH"; break;
        case D3D_NAME_COVERAGE: ret = "D3D_NAME_COVERAGE"; break;
        case D3D_NAME_DEPTH_GREATER_EQUAL: ret = "D3D_NAME_DEPTH_GREATER_EQUAL"; break;
        case D3D_NAME_DEPTH_LESS_EQUAL: ret = "D3D_NAME_DEPTH_LESS_EQUAL"; break;
        case D3D_NAME_STENCIL_REF: ret = "D3D_NAME_STENCIL_REF"; break;
        case D3D_NAME_INNER_COVERAGE: ret = "D3D_NAME_INNER_COVERAGE"; break;
    }
    return ret;
}

std::string ToString(const D3D_RESOURCE_RETURN_TYPE value)
{
    const char* ret = "Unhandled D3D_RESOURCE_RETURN_TYPE";
    switch (value) {
        case D3D_RETURN_TYPE_UNORM: ret = "D3D_RETURN_TYPE_UNORM"; break;
        case D3D_RETURN_TYPE_SNORM: ret = "D3D_RETURN_TYPE_SNORM"; break;
        case D3D_RETURN_TYPE_SINT: ret = "D3D_RETURN_TYPE_SINT"; break;
        case D3D_RETURN_TYPE_UINT: ret = "D3D_RETURN_TYPE_UINT"; break;
        case D3D_RETURN_TYPE_FLOAT: ret = "D3D_RETURN_TYPE_FLOAT"; break;
        case D3D_RETURN_TYPE_MIXED: ret = "D3D_RETURN_TYPE_MIXED"; break;
        case D3D_RETURN_TYPE_DOUBLE: ret = "D3D_RETURN_TYPE_DOUBLE"; break;
        case D3D_RETURN_TYPE_CONTINUED: ret = "D3D_RETURN_TYPE_CONTINUED"; break;
    }
    return ret;
}

std::string ToString(const D3D_REGISTER_COMPONENT_TYPE value)
{
    const char* ret = "Unhandled D3D_REGISTER_COMPONENT_TYPE";
    switch (value) {
        case D3D_REGISTER_COMPONENT_UNKNOWN: ret = "D3D_REGISTER_COMPONENT_UNKNOWN"; break;
        case D3D_REGISTER_COMPONENT_UINT32: ret = "D3D_REGISTER_COMPONENT_UINT32"; break;
        case D3D_REGISTER_COMPONENT_SINT32: ret = "D3D_REGISTER_COMPONENT_SINT32"; break;
        case D3D_REGISTER_COMPONENT_FLOAT32: ret = "D3D_REGISTER_COMPONENT_FLOAT32"; break;
    }
    return ret;
}

std::string ToString(const D3D_TESSELLATOR_DOMAIN value)
{
    const char* ret = "Unhandled D3D_TESSELLATOR_DOMAIN";
    switch (value) {
        case D3D_TESSELLATOR_DOMAIN_UNDEFINED: ret = "D3D_TESSELLATOR_DOMAIN_UNDEFINED"; break;
        case D3D_TESSELLATOR_DOMAIN_ISOLINE: ret = "D3D_TESSELLATOR_DOMAIN_ISOLINE"; break;
        case D3D_TESSELLATOR_DOMAIN_TRI: ret = "D3D_TESSELLATOR_DOMAIN_TRI"; break;
        case D3D_TESSELLATOR_DOMAIN_QUAD: ret = "D3D_TESSELLATOR_DOMAIN_QUAD"; break;
    }
    return ret;
}

std::string ToString(const D3D_TESSELLATOR_PARTITIONING value)
{
    const char* ret = "Unhandled D3D_TESSELLATOR_PARTITIONING";
    switch (value) {
        case D3D_TESSELLATOR_PARTITIONING_UNDEFINED: ret = "D3D_TESSELLATOR_PARTITIONING_UNDEFINED"; break;
        case D3D_TESSELLATOR_PARTITIONING_INTEGER: ret = "D3D_TESSELLATOR_PARTITIONING_INTEGER"; break;
        case D3D_TESSELLATOR_PARTITIONING_POW2: ret = "D3D_TESSELLATOR_PARTITIONING_POW2"; break;
        case D3D_TESSELLATOR_PARTITIONING_FRACTIONAL_ODD: ret = "D3D_TESSELLATOR_PARTITIONING_FRACTIONAL_ODD"; break;
        case D3D_TESSELLATOR_PARTITIONING_FRACTIONAL_EVEN: ret = "D3D_TESSELLATOR_PARTITIONING_FRACTIONAL_EVEN"; break;
    }
    return ret;
}

std::string ToString(const D3D_TESSELLATOR_OUTPUT_PRIMITIVE value)
{
    const char* ret = "Unhandled D3D_TESSELLATOR_OUTPUT_PRIMITIVE";
    switch (value) {
        case D3D_TESSELLATOR_OUTPUT_UNDEFINED: ret = "D3D_TESSELLATOR_OUTPUT_UNDEFINED"; break;
        case D3D_TESSELLATOR_OUTPUT_POINT: ret = "D3D_TESSELLATOR_OUTPUT_POINT"; break;
        case D3D_TESSELLATOR_OUTPUT_LINE: ret = "D3D_TESSELLATOR_OUTPUT_LINE"; break;
        case D3D_TESSELLATOR_OUTPUT_TRIANGLE_CW: ret = "D3D_TESSELLATOR_OUTPUT_TRIANGLE_CW"; break;
        case D3D_TESSELLATOR_OUTPUT_TRIANGLE_CCW: ret = "D3D_TESSELLATOR_OUTPUT_TRIANGLE_CCW"; break;
    }
    return ret;
}

std::string ToString(const D3D_MIN_PRECISION value)
{
    const char* ret = "Unhandled D3D_MIN_PRECISION";
    switch (value) {
        case D3D_MIN_PRECISION_DEFAULT: ret = "D3D_MIN_PRECISION_DEFAULT"; break;
        case D3D_MIN_PRECISION_FLOAT_16: ret = "D3D_MIN_PRECISION_FLOAT_16"; break;
        case D3D_MIN_PRECISION_FLOAT_2_8: ret = "D3D_MIN_PRECISION_FLOAT_2_8"; break;
        case D3D_MIN_PRECISION_RESERVED: ret = "D3D_MIN_PRECISION_RESERVED"; break;
        case D3D_MIN_PRECISION_SINT_16: ret = "D3D_MIN_PRECISION_SINT_16"; break;
        case D3D_MIN_PRECISION_UINT_16: ret = "D3D_MIN_PRECISION_UINT_16"; break;
        case D3D_MIN_PRECISION_ANY_16: ret = "D3D_MIN_PRECISION_ANY_16"; break;
        case D3D_MIN_PRECISION_ANY_10: ret = "D3D_MIN_PRECISION_ANY_10"; break;
    }
    return ret;
}

std::string ToString(const D3D_INTERPOLATION_MODE value)
{
    const char* ret = "Unhandled D3D_INTERPOLATION_MODE";
    switch (value) {
        case D3D_INTERPOLATION_UNDEFINED: ret = "D3D_INTERPOLATION_UNDEFINED"; break;
        case D3D_INTERPOLATION_CONSTANT: ret = "D3D_INTERPOLATION_CONSTANT"; break;
        case D3D_INTERPOLATION_LINEAR: ret = "D3D_INTERPOLATION_LINEAR"; break;
        case D3D_INTERPOLATION_LINEAR_CENTROID: ret = "D3D_INTERPOLATION_LINEAR_CENTROID"; break;
        case D3D_INTERPOLATION_LINEAR_NOPERSPECTIVE: ret = "D3D_INTERPOLATION_LINEAR_NOPERSPECTIVE"; break;
        case D3D_INTERPOLATION_LINEAR_NOPERSPECTIVE_CENTROID: ret = "D3D_INTERPOLATION_LINEAR_NOPERSPECTIVE_CENTROID"; break;
        case D3D_INTERPOLATION_LINEAR_SAMPLE: ret = "D3D_INTERPOLATION_LINEAR_SAMPLE"; break;
        case D3D_INTERPOLATION_LINEAR_NOPERSPECTIVE_SAMPLE: ret = "D3D_INTERPOLATION_LINEAR_NOPERSPECTIVE_SAMPLE"; break;
    }
    return ret;
}

std::string ToString(const D3D_PARAMETER_FLAGS value)
{
    const char* ret = "Unhandled D3D_PARAMETER_FLAGS";
    switch (value) {
        case D3D_PF_NONE: ret = "D3D_PF_NONE"; break;
        case D3D_PF_IN: ret = "D3D_PF_IN"; break;
        case D3D_PF_OUT: ret = "D3D_PF_OUT"; break;
        case D3D_PF_FORCE_DWORD: ret = "D3D_PF_FORCE_DWORD"; break;
    }
    return ret;
}

std::string ToString_D3D_PARAMETER_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D_PARAMETER_FLAGS>(flags);
}

std::string ToString(const D3D_FORMAT_LAYOUT value)
{
    const char* ret = "Unhandled D3D_FORMAT_LAYOUT";
    switch (value) {
        case D3DFL_STANDARD: ret = "D3DFL_STANDARD"; break;
        case D3DFL_CUSTOM: ret = "D3DFL_CUSTOM"; break;
    }
    return ret;
}

std::string ToString(const D3D_FORMAT_TYPE_LEVEL value)
{
    const char* ret = "Unhandled D3D_FORMAT_TYPE_LEVEL";
    switch (value) {
        case D3DFTL_NO_TYPE: ret = "D3DFTL_NO_TYPE"; break;
        case D3DFTL_PARTIAL_TYPE: ret = "D3DFTL_PARTIAL_TYPE"; break;
        case D3DFTL_FULL_TYPE: ret = "D3DFTL_FULL_TYPE"; break;
    }
    return ret;
}

std::string ToString(const D3D_FORMAT_COMPONENT_NAME value)
{
    const char* ret = "Unhandled D3D_FORMAT_COMPONENT_NAME";
    switch (value) {
        case D3DFCN_R: ret = "D3DFCN_R"; break;
        case D3DFCN_G: ret = "D3DFCN_G"; break;
        case D3DFCN_B: ret = "D3DFCN_B"; break;
        case D3DFCN_A: ret = "D3DFCN_A"; break;
        case D3DFCN_D: ret = "D3DFCN_D"; break;
        case D3DFCN_S: ret = "D3DFCN_S"; break;
        case D3DFCN_X: ret = "D3DFCN_X"; break;
    }
    return ret;
}

std::string ToString(const D3D_FORMAT_COMPONENT_INTERPRETATION value)
{
    const char* ret = "Unhandled D3D_FORMAT_COMPONENT_INTERPRETATION";
    switch (value) {
        case D3DFCI_TYPELESS: ret = "D3DFCI_TYPELESS"; break;
        case D3DFCI_FLOAT: ret = "D3DFCI_FLOAT"; break;
        case D3DFCI_SNORM: ret = "D3DFCI_SNORM"; break;
        case D3DFCI_UNORM: ret = "D3DFCI_UNORM"; break;
        case D3DFCI_SINT: ret = "D3DFCI_SINT"; break;
        case D3DFCI_UINT: ret = "D3DFCI_UINT"; break;
        case D3DFCI_UNORM_SRGB: ret = "D3DFCI_UNORM_SRGB"; break;
        case D3DFCI_BIASED_FIXED_2_8: ret = "D3DFCI_BIASED_FIXED_2_8"; break;
    }
    return ret;
}

std::string ToString(const D3D12_GPU_BASED_VALIDATION_FLAGS value)
{
    const char* ret = "Unhandled D3D12_GPU_BASED_VALIDATION_FLAGS";
    switch (value) {
        case D3D12_GPU_BASED_VALIDATION_FLAGS_NONE: ret = "D3D12_GPU_BASED_VALIDATION_FLAGS_NONE"; break;
        case D3D12_GPU_BASED_VALIDATION_FLAGS_DISABLE_STATE_TRACKING: ret = "D3D12_GPU_BASED_VALIDATION_FLAGS_DISABLE_STATE_TRACKING"; break;
    }
    return ret;
}

std::string ToString_D3D12_GPU_BASED_VALIDATION_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_GPU_BASED_VALIDATION_FLAGS>(flags);
}

std::string ToString(const D3D12_RLDO_FLAGS value)
{
    const char* ret = "Unhandled D3D12_RLDO_FLAGS";
    switch (value) {
        case D3D12_RLDO_NONE: ret = "D3D12_RLDO_NONE"; break;
        case D3D12_RLDO_SUMMARY: ret = "D3D12_RLDO_SUMMARY"; break;
        case D3D12_RLDO_DETAIL: ret = "D3D12_RLDO_DETAIL"; break;
        case D3D12_RLDO_IGNORE_INTERNAL: ret = "D3D12_RLDO_IGNORE_INTERNAL"; break;
    }
    return ret;
}

std::string ToString_D3D12_RLDO_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_RLDO_FLAGS>(flags);
}

std::string ToString(const D3D12_DEBUG_DEVICE_PARAMETER_TYPE value)
{
    const char* ret = "Unhandled D3D12_DEBUG_DEVICE_PARAMETER_TYPE";
    switch (value) {
        case D3D12_DEBUG_DEVICE_PARAMETER_FEATURE_FLAGS: ret = "D3D12_DEBUG_DEVICE_PARAMETER_FEATURE_FLAGS"; break;
        case D3D12_DEBUG_DEVICE_PARAMETER_GPU_BASED_VALIDATION_SETTINGS: ret = "D3D12_DEBUG_DEVICE_PARAMETER_GPU_BASED_VALIDATION_SETTINGS"; break;
        case D3D12_DEBUG_DEVICE_PARAMETER_GPU_SLOWDOWN_PERFORMANCE_FACTOR: ret = "D3D12_DEBUG_DEVICE_PARAMETER_GPU_SLOWDOWN_PERFORMANCE_FACTOR"; break;
    }
    return ret;
}

std::string ToString(const D3D12_DEBUG_FEATURE value)
{
    const char* ret = "Unhandled D3D12_DEBUG_FEATURE";
    switch (value) {
        case D3D12_DEBUG_FEATURE_NONE: ret = "D3D12_DEBUG_FEATURE_NONE"; break;
        case D3D12_DEBUG_FEATURE_ALLOW_BEHAVIOR_CHANGING_DEBUG_AIDS: ret = "D3D12_DEBUG_FEATURE_ALLOW_BEHAVIOR_CHANGING_DEBUG_AIDS"; break;
        case D3D12_DEBUG_FEATURE_CONSERVATIVE_RESOURCE_STATE_TRACKING: ret = "D3D12_DEBUG_FEATURE_CONSERVATIVE_RESOURCE_STATE_TRACKING"; break;
        case D3D12_DEBUG_FEATURE_DISABLE_VIRTUALIZED_BUNDLES_VALIDATION: ret = "D3D12_DEBUG_FEATURE_DISABLE_VIRTUALIZED_BUNDLES_VALIDATION"; break;
        case D3D12_DEBUG_FEATURE_EMULATE_WINDOWS7: ret = "D3D12_DEBUG_FEATURE_EMULATE_WINDOWS7"; break;
    }
    return ret;
}

std::string ToString(const D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE value)
{
    const char* ret = "Unhandled D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE";
    switch (value) {
        case D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE_NONE: ret = "D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE_NONE"; break;
        case D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE_STATE_TRACKING_ONLY: ret = "D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE_STATE_TRACKING_ONLY"; break;
        case D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE_UNGUARDED_VALIDATION: ret = "D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE_UNGUARDED_VALIDATION"; break;
        case D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE_GUARDED_VALIDATION: ret = "D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE_GUARDED_VALIDATION"; break;
        case NUM_D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODES: ret = "NUM_D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODES"; break;
    }
    return ret;
}

std::string ToString(const D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS value)
{
    const char* ret = "Unhandled D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS";
    switch (value) {
        case D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAG_NONE: ret = "D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAG_NONE"; break;
        case D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAG_FRONT_LOAD_CREATE_TRACKING_ONLY_SHADERS: ret = "D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAG_FRONT_LOAD_CREATE_TRACKING_ONLY_SHADERS"; break;
        case D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAG_FRONT_LOAD_CREATE_UNGUARDED_VALIDATION_SHADERS: ret = "D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAG_FRONT_LOAD_CREATE_UNGUARDED_VALIDATION_SHADERS"; break;
        case D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAG_FRONT_LOAD_CREATE_GUARDED_VALIDATION_SHADERS: ret = "D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAG_FRONT_LOAD_CREATE_GUARDED_VALIDATION_SHADERS"; break;
        case D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS_VALID_MASK: ret = "D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS_VALID_MASK"; break;
    }
    return ret;
}

std::string ToString_D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS>(flags);
}

std::string ToString(const D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE value)
{
    const char* ret = "Unhandled D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE";
    switch (value) {
        case D3D12_DEBUG_COMMAND_LIST_PARAMETER_GPU_BASED_VALIDATION_SETTINGS: ret = "D3D12_DEBUG_COMMAND_LIST_PARAMETER_GPU_BASED_VALIDATION_SETTINGS"; break;
    }
    return ret;
}

std::string ToString(const D3D12_MESSAGE_CATEGORY value)
{
    const char* ret = "Unhandled D3D12_MESSAGE_CATEGORY";
    switch (value) {
        case D3D12_MESSAGE_CATEGORY_APPLICATION_DEFINED: ret = "D3D12_MESSAGE_CATEGORY_APPLICATION_DEFINED"; break;
        case D3D12_MESSAGE_CATEGORY_MISCELLANEOUS: ret = "D3D12_MESSAGE_CATEGORY_MISCELLANEOUS"; break;
        case D3D12_MESSAGE_CATEGORY_INITIALIZATION: ret = "D3D12_MESSAGE_CATEGORY_INITIALIZATION"; break;
        case D3D12_MESSAGE_CATEGORY_CLEANUP: ret = "D3D12_MESSAGE_CATEGORY_CLEANUP"; break;
        case D3D12_MESSAGE_CATEGORY_COMPILATION: ret = "D3D12_MESSAGE_CATEGORY_COMPILATION"; break;
        case D3D12_MESSAGE_CATEGORY_STATE_CREATION: ret = "D3D12_MESSAGE_CATEGORY_STATE_CREATION"; break;
        case D3D12_MESSAGE_CATEGORY_STATE_SETTING: ret = "D3D12_MESSAGE_CATEGORY_STATE_SETTING"; break;
        case D3D12_MESSAGE_CATEGORY_STATE_GETTING: ret = "D3D12_MESSAGE_CATEGORY_STATE_GETTING"; break;
        case D3D12_MESSAGE_CATEGORY_RESOURCE_MANIPULATION: ret = "D3D12_MESSAGE_CATEGORY_RESOURCE_MANIPULATION"; break;
        case D3D12_MESSAGE_CATEGORY_EXECUTION: ret = "D3D12_MESSAGE_CATEGORY_EXECUTION"; break;
        case D3D12_MESSAGE_CATEGORY_SHADER: ret = "D3D12_MESSAGE_CATEGORY_SHADER"; break;
    }
    return ret;
}

std::string ToString(const D3D12_MESSAGE_SEVERITY value)
{
    const char* ret = "Unhandled D3D12_MESSAGE_SEVERITY";
    switch (value) {
        case D3D12_MESSAGE_SEVERITY_CORRUPTION: ret = "D3D12_MESSAGE_SEVERITY_CORRUPTION"; break;
        case D3D12_MESSAGE_SEVERITY_ERROR: ret = "D3D12_MESSAGE_SEVERITY_ERROR"; break;
        case D3D12_MESSAGE_SEVERITY_WARNING: ret = "D3D12_MESSAGE_SEVERITY_WARNING"; break;
        case D3D12_MESSAGE_SEVERITY_INFO: ret = "D3D12_MESSAGE_SEVERITY_INFO"; break;
        case D3D12_MESSAGE_SEVERITY_MESSAGE: ret = "D3D12_MESSAGE_SEVERITY_MESSAGE"; break;
    }
    return ret;
}

std::string ToString(const D3D12_MESSAGE_ID value)
{
    const char* ret = "Unhandled D3D12_MESSAGE_ID";
    switch (value) {
        case D3D12_MESSAGE_ID_UNKNOWN: ret = "D3D12_MESSAGE_ID_UNKNOWN"; break;
        case D3D12_MESSAGE_ID_STRING_FROM_APPLICATION: ret = "D3D12_MESSAGE_ID_STRING_FROM_APPLICATION"; break;
        case D3D12_MESSAGE_ID_CORRUPTED_THIS: ret = "D3D12_MESSAGE_ID_CORRUPTED_THIS"; break;
        case D3D12_MESSAGE_ID_CORRUPTED_PARAMETER1: ret = "D3D12_MESSAGE_ID_CORRUPTED_PARAMETER1"; break;
        case D3D12_MESSAGE_ID_CORRUPTED_PARAMETER2: ret = "D3D12_MESSAGE_ID_CORRUPTED_PARAMETER2"; break;
        case D3D12_MESSAGE_ID_CORRUPTED_PARAMETER3: ret = "D3D12_MESSAGE_ID_CORRUPTED_PARAMETER3"; break;
        case D3D12_MESSAGE_ID_CORRUPTED_PARAMETER4: ret = "D3D12_MESSAGE_ID_CORRUPTED_PARAMETER4"; break;
        case D3D12_MESSAGE_ID_CORRUPTED_PARAMETER5: ret = "D3D12_MESSAGE_ID_CORRUPTED_PARAMETER5"; break;
        case D3D12_MESSAGE_ID_CORRUPTED_PARAMETER6: ret = "D3D12_MESSAGE_ID_CORRUPTED_PARAMETER6"; break;
        case D3D12_MESSAGE_ID_CORRUPTED_PARAMETER7: ret = "D3D12_MESSAGE_ID_CORRUPTED_PARAMETER7"; break;
        case D3D12_MESSAGE_ID_CORRUPTED_PARAMETER8: ret = "D3D12_MESSAGE_ID_CORRUPTED_PARAMETER8"; break;
        case D3D12_MESSAGE_ID_CORRUPTED_PARAMETER9: ret = "D3D12_MESSAGE_ID_CORRUPTED_PARAMETER9"; break;
        case D3D12_MESSAGE_ID_CORRUPTED_PARAMETER10: ret = "D3D12_MESSAGE_ID_CORRUPTED_PARAMETER10"; break;
        case D3D12_MESSAGE_ID_CORRUPTED_PARAMETER11: ret = "D3D12_MESSAGE_ID_CORRUPTED_PARAMETER11"; break;
        case D3D12_MESSAGE_ID_CORRUPTED_PARAMETER12: ret = "D3D12_MESSAGE_ID_CORRUPTED_PARAMETER12"; break;
        case D3D12_MESSAGE_ID_CORRUPTED_PARAMETER13: ret = "D3D12_MESSAGE_ID_CORRUPTED_PARAMETER13"; break;
        case D3D12_MESSAGE_ID_CORRUPTED_PARAMETER14: ret = "D3D12_MESSAGE_ID_CORRUPTED_PARAMETER14"; break;
        case D3D12_MESSAGE_ID_CORRUPTED_PARAMETER15: ret = "D3D12_MESSAGE_ID_CORRUPTED_PARAMETER15"; break;
        case D3D12_MESSAGE_ID_CORRUPTED_MULTITHREADING: ret = "D3D12_MESSAGE_ID_CORRUPTED_MULTITHREADING"; break;
        case D3D12_MESSAGE_ID_MESSAGE_REPORTING_OUTOFMEMORY: ret = "D3D12_MESSAGE_ID_MESSAGE_REPORTING_OUTOFMEMORY"; break;
        case D3D12_MESSAGE_ID_GETPRIVATEDATA_MOREDATA: ret = "D3D12_MESSAGE_ID_GETPRIVATEDATA_MOREDATA"; break;
        case D3D12_MESSAGE_ID_SETPRIVATEDATA_INVALIDFREEDATA: ret = "D3D12_MESSAGE_ID_SETPRIVATEDATA_INVALIDFREEDATA"; break;
        case D3D12_MESSAGE_ID_SETPRIVATEDATA_CHANGINGPARAMS: ret = "D3D12_MESSAGE_ID_SETPRIVATEDATA_CHANGINGPARAMS"; break;
        case D3D12_MESSAGE_ID_SETPRIVATEDATA_OUTOFMEMORY: ret = "D3D12_MESSAGE_ID_SETPRIVATEDATA_OUTOFMEMORY"; break;
        case D3D12_MESSAGE_ID_CREATESHADERRESOURCEVIEW_UNRECOGNIZEDFORMAT: ret = "D3D12_MESSAGE_ID_CREATESHADERRESOURCEVIEW_UNRECOGNIZEDFORMAT"; break;
        case D3D12_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDDESC: ret = "D3D12_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDDESC"; break;
        case D3D12_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDFORMAT: ret = "D3D12_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDFORMAT"; break;
        case D3D12_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDVIDEOPLANESLICE: ret = "D3D12_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDVIDEOPLANESLICE"; break;
        case D3D12_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDPLANESLICE: ret = "D3D12_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDPLANESLICE"; break;
        case D3D12_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDDIMENSIONS: ret = "D3D12_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDDIMENSIONS"; break;
        case D3D12_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDRESOURCE: ret = "D3D12_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDRESOURCE"; break;
        case D3D12_MESSAGE_ID_CREATERENDERTARGETVIEW_UNRECOGNIZEDFORMAT: ret = "D3D12_MESSAGE_ID_CREATERENDERTARGETVIEW_UNRECOGNIZEDFORMAT"; break;
        case D3D12_MESSAGE_ID_CREATERENDERTARGETVIEW_UNSUPPORTEDFORMAT: ret = "D3D12_MESSAGE_ID_CREATERENDERTARGETVIEW_UNSUPPORTEDFORMAT"; break;
        case D3D12_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDDESC: ret = "D3D12_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDDESC"; break;
        case D3D12_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDFORMAT: ret = "D3D12_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDFORMAT"; break;
        case D3D12_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDVIDEOPLANESLICE: ret = "D3D12_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDVIDEOPLANESLICE"; break;
        case D3D12_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDPLANESLICE: ret = "D3D12_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDPLANESLICE"; break;
        case D3D12_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDDIMENSIONS: ret = "D3D12_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDDIMENSIONS"; break;
        case D3D12_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDRESOURCE: ret = "D3D12_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDRESOURCE"; break;
        case D3D12_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_UNRECOGNIZEDFORMAT: ret = "D3D12_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_UNRECOGNIZEDFORMAT"; break;
        case D3D12_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDDESC: ret = "D3D12_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDDESC"; break;
        case D3D12_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDFORMAT: ret = "D3D12_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDFORMAT"; break;
        case D3D12_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDDIMENSIONS: ret = "D3D12_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDDIMENSIONS"; break;
        case D3D12_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDRESOURCE: ret = "D3D12_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDRESOURCE"; break;
        case D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_OUTOFMEMORY: ret = "D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_OUTOFMEMORY"; break;
        case D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_TOOMANYELEMENTS: ret = "D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_TOOMANYELEMENTS"; break;
        case D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDFORMAT: ret = "D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDFORMAT"; break;
        case D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_INCOMPATIBLEFORMAT: ret = "D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_INCOMPATIBLEFORMAT"; break;
        case D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDSLOT: ret = "D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDSLOT"; break;
        case D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDINPUTSLOTCLASS: ret = "D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDINPUTSLOTCLASS"; break;
        case D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_STEPRATESLOTCLASSMISMATCH: ret = "D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_STEPRATESLOTCLASSMISMATCH"; break;
        case D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDSLOTCLASSCHANGE: ret = "D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDSLOTCLASSCHANGE"; break;
        case D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDSTEPRATECHANGE: ret = "D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDSTEPRATECHANGE"; break;
        case D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDALIGNMENT: ret = "D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDALIGNMENT"; break;
        case D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_DUPLICATESEMANTIC: ret = "D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_DUPLICATESEMANTIC"; break;
        case D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_UNPARSEABLEINPUTSIGNATURE: ret = "D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_UNPARSEABLEINPUTSIGNATURE"; break;
        case D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_NULLSEMANTIC: ret = "D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_NULLSEMANTIC"; break;
        case D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_MISSINGELEMENT: ret = "D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_MISSINGELEMENT"; break;
        case D3D12_MESSAGE_ID_CREATEVERTEXSHADER_OUTOFMEMORY: ret = "D3D12_MESSAGE_ID_CREATEVERTEXSHADER_OUTOFMEMORY"; break;
        case D3D12_MESSAGE_ID_CREATEVERTEXSHADER_INVALIDSHADERBYTECODE: ret = "D3D12_MESSAGE_ID_CREATEVERTEXSHADER_INVALIDSHADERBYTECODE"; break;
        case D3D12_MESSAGE_ID_CREATEVERTEXSHADER_INVALIDSHADERTYPE: ret = "D3D12_MESSAGE_ID_CREATEVERTEXSHADER_INVALIDSHADERTYPE"; break;
        case D3D12_MESSAGE_ID_CREATEGEOMETRYSHADER_OUTOFMEMORY: ret = "D3D12_MESSAGE_ID_CREATEGEOMETRYSHADER_OUTOFMEMORY"; break;
        case D3D12_MESSAGE_ID_CREATEGEOMETRYSHADER_INVALIDSHADERBYTECODE: ret = "D3D12_MESSAGE_ID_CREATEGEOMETRYSHADER_INVALIDSHADERBYTECODE"; break;
        case D3D12_MESSAGE_ID_CREATEGEOMETRYSHADER_INVALIDSHADERTYPE: ret = "D3D12_MESSAGE_ID_CREATEGEOMETRYSHADER_INVALIDSHADERTYPE"; break;
        case D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_OUTOFMEMORY: ret = "D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_OUTOFMEMORY"; break;
        case D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSHADERBYTECODE: ret = "D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSHADERBYTECODE"; break;
        case D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSHADERTYPE: ret = "D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSHADERTYPE"; break;
        case D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDNUMENTRIES: ret = "D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDNUMENTRIES"; break;
        case D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_OUTPUTSTREAMSTRIDEUNUSED: ret = "D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_OUTPUTSTREAMSTRIDEUNUSED"; break;
        case D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_OUTPUTSLOT0EXPECTED: ret = "D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_OUTPUTSLOT0EXPECTED"; break;
        case D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDOUTPUTSLOT: ret = "D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDOUTPUTSLOT"; break;
        case D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_ONLYONEELEMENTPERSLOT: ret = "D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_ONLYONEELEMENTPERSLOT"; break;
        case D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDCOMPONENTCOUNT: ret = "D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDCOMPONENTCOUNT"; break;
        case D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSTARTCOMPONENTANDCOMPONENTCOUNT: ret = "D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSTARTCOMPONENTANDCOMPONENTCOUNT"; break;
        case D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDGAPDEFINITION: ret = "D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDGAPDEFINITION"; break;
        case D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_REPEATEDOUTPUT: ret = "D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_REPEATEDOUTPUT"; break;
        case D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDOUTPUTSTREAMSTRIDE: ret = "D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDOUTPUTSTREAMSTRIDE"; break;
        case D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_MISSINGSEMANTIC: ret = "D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_MISSINGSEMANTIC"; break;
        case D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_MASKMISMATCH: ret = "D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_MASKMISMATCH"; break;
        case D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_CANTHAVEONLYGAPS: ret = "D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_CANTHAVEONLYGAPS"; break;
        case D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_DECLTOOCOMPLEX: ret = "D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_DECLTOOCOMPLEX"; break;
        case D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_MISSINGOUTPUTSIGNATURE: ret = "D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_MISSINGOUTPUTSIGNATURE"; break;
        case D3D12_MESSAGE_ID_CREATEPIXELSHADER_OUTOFMEMORY: ret = "D3D12_MESSAGE_ID_CREATEPIXELSHADER_OUTOFMEMORY"; break;
        case D3D12_MESSAGE_ID_CREATEPIXELSHADER_INVALIDSHADERBYTECODE: ret = "D3D12_MESSAGE_ID_CREATEPIXELSHADER_INVALIDSHADERBYTECODE"; break;
        case D3D12_MESSAGE_ID_CREATEPIXELSHADER_INVALIDSHADERTYPE: ret = "D3D12_MESSAGE_ID_CREATEPIXELSHADER_INVALIDSHADERTYPE"; break;
        case D3D12_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDFILLMODE: ret = "D3D12_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDFILLMODE"; break;
        case D3D12_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDCULLMODE: ret = "D3D12_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDCULLMODE"; break;
        case D3D12_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDDEPTHBIASCLAMP: ret = "D3D12_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDDEPTHBIASCLAMP"; break;
        case D3D12_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDSLOPESCALEDDEPTHBIAS: ret = "D3D12_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDSLOPESCALEDDEPTHBIAS"; break;
        case D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDDEPTHWRITEMASK: ret = "D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDDEPTHWRITEMASK"; break;
        case D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDDEPTHFUNC: ret = "D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDDEPTHFUNC"; break;
        case D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDFRONTFACESTENCILFAILOP: ret = "D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDFRONTFACESTENCILFAILOP"; break;
        case D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDFRONTFACESTENCILZFAILOP: ret = "D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDFRONTFACESTENCILZFAILOP"; break;
        case D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDFRONTFACESTENCILPASSOP: ret = "D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDFRONTFACESTENCILPASSOP"; break;
        case D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDFRONTFACESTENCILFUNC: ret = "D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDFRONTFACESTENCILFUNC"; break;
        case D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDBACKFACESTENCILFAILOP: ret = "D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDBACKFACESTENCILFAILOP"; break;
        case D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDBACKFACESTENCILZFAILOP: ret = "D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDBACKFACESTENCILZFAILOP"; break;
        case D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDBACKFACESTENCILPASSOP: ret = "D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDBACKFACESTENCILPASSOP"; break;
        case D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDBACKFACESTENCILFUNC: ret = "D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDBACKFACESTENCILFUNC"; break;
        case D3D12_MESSAGE_ID_CREATEBLENDSTATE_INVALIDSRCBLEND: ret = "D3D12_MESSAGE_ID_CREATEBLENDSTATE_INVALIDSRCBLEND"; break;
        case D3D12_MESSAGE_ID_CREATEBLENDSTATE_INVALIDDESTBLEND: ret = "D3D12_MESSAGE_ID_CREATEBLENDSTATE_INVALIDDESTBLEND"; break;
        case D3D12_MESSAGE_ID_CREATEBLENDSTATE_INVALIDBLENDOP: ret = "D3D12_MESSAGE_ID_CREATEBLENDSTATE_INVALIDBLENDOP"; break;
        case D3D12_MESSAGE_ID_CREATEBLENDSTATE_INVALIDSRCBLENDALPHA: ret = "D3D12_MESSAGE_ID_CREATEBLENDSTATE_INVALIDSRCBLENDALPHA"; break;
        case D3D12_MESSAGE_ID_CREATEBLENDSTATE_INVALIDDESTBLENDALPHA: ret = "D3D12_MESSAGE_ID_CREATEBLENDSTATE_INVALIDDESTBLENDALPHA"; break;
        case D3D12_MESSAGE_ID_CREATEBLENDSTATE_INVALIDBLENDOPALPHA: ret = "D3D12_MESSAGE_ID_CREATEBLENDSTATE_INVALIDBLENDOPALPHA"; break;
        case D3D12_MESSAGE_ID_CREATEBLENDSTATE_INVALIDRENDERTARGETWRITEMASK: ret = "D3D12_MESSAGE_ID_CREATEBLENDSTATE_INVALIDRENDERTARGETWRITEMASK"; break;
        case D3D12_MESSAGE_ID_CLEARDEPTHSTENCILVIEW_INVALID: ret = "D3D12_MESSAGE_ID_CLEARDEPTHSTENCILVIEW_INVALID"; break;
        case D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_ROOT_SIGNATURE_NOT_SET: ret = "D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_ROOT_SIGNATURE_NOT_SET"; break;
        case D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_ROOT_SIGNATURE_MISMATCH: ret = "D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_ROOT_SIGNATURE_MISMATCH"; break;
        case D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_VERTEX_BUFFER_NOT_SET: ret = "D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_VERTEX_BUFFER_NOT_SET"; break;
        case D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_VERTEX_BUFFER_STRIDE_TOO_SMALL: ret = "D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_VERTEX_BUFFER_STRIDE_TOO_SMALL"; break;
        case D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_VERTEX_BUFFER_TOO_SMALL: ret = "D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_VERTEX_BUFFER_TOO_SMALL"; break;
        case D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_INDEX_BUFFER_NOT_SET: ret = "D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_INDEX_BUFFER_NOT_SET"; break;
        case D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_INDEX_BUFFER_FORMAT_INVALID: ret = "D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_INDEX_BUFFER_FORMAT_INVALID"; break;
        case D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_INDEX_BUFFER_TOO_SMALL: ret = "D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_INDEX_BUFFER_TOO_SMALL"; break;
        case D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_INVALID_PRIMITIVETOPOLOGY: ret = "D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_INVALID_PRIMITIVETOPOLOGY"; break;
        case D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_VERTEX_STRIDE_UNALIGNED: ret = "D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_VERTEX_STRIDE_UNALIGNED"; break;
        case D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_INDEX_OFFSET_UNALIGNED: ret = "D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_INDEX_OFFSET_UNALIGNED"; break;
        case D3D12_MESSAGE_ID_DEVICE_REMOVAL_PROCESS_AT_FAULT: ret = "D3D12_MESSAGE_ID_DEVICE_REMOVAL_PROCESS_AT_FAULT"; break;
        case D3D12_MESSAGE_ID_DEVICE_REMOVAL_PROCESS_POSSIBLY_AT_FAULT: ret = "D3D12_MESSAGE_ID_DEVICE_REMOVAL_PROCESS_POSSIBLY_AT_FAULT"; break;
        case D3D12_MESSAGE_ID_DEVICE_REMOVAL_PROCESS_NOT_AT_FAULT: ret = "D3D12_MESSAGE_ID_DEVICE_REMOVAL_PROCESS_NOT_AT_FAULT"; break;
        case D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_TRAILING_DIGIT_IN_SEMANTIC: ret = "D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_TRAILING_DIGIT_IN_SEMANTIC"; break;
        case D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_TRAILING_DIGIT_IN_SEMANTIC: ret = "D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_TRAILING_DIGIT_IN_SEMANTIC"; break;
        case D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_TYPE_MISMATCH: ret = "D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_TYPE_MISMATCH"; break;
        case D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_EMPTY_LAYOUT: ret = "D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_EMPTY_LAYOUT"; break;
        case D3D12_MESSAGE_ID_LIVE_OBJECT_SUMMARY: ret = "D3D12_MESSAGE_ID_LIVE_OBJECT_SUMMARY"; break;
        case D3D12_MESSAGE_ID_LIVE_DEVICE: ret = "D3D12_MESSAGE_ID_LIVE_DEVICE"; break;
        case D3D12_MESSAGE_ID_LIVE_SWAPCHAIN: ret = "D3D12_MESSAGE_ID_LIVE_SWAPCHAIN"; break;
        case D3D12_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDFLAGS: ret = "D3D12_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDFLAGS"; break;
        case D3D12_MESSAGE_ID_CREATEVERTEXSHADER_INVALIDCLASSLINKAGE: ret = "D3D12_MESSAGE_ID_CREATEVERTEXSHADER_INVALIDCLASSLINKAGE"; break;
        case D3D12_MESSAGE_ID_CREATEGEOMETRYSHADER_INVALIDCLASSLINKAGE: ret = "D3D12_MESSAGE_ID_CREATEGEOMETRYSHADER_INVALIDCLASSLINKAGE"; break;
        case D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSTREAMTORASTERIZER: ret = "D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSTREAMTORASTERIZER"; break;
        case D3D12_MESSAGE_ID_CREATEPIXELSHADER_INVALIDCLASSLINKAGE: ret = "D3D12_MESSAGE_ID_CREATEPIXELSHADER_INVALIDCLASSLINKAGE"; break;
        case D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSTREAM: ret = "D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSTREAM"; break;
        case D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_UNEXPECTEDENTRIES: ret = "D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_UNEXPECTEDENTRIES"; break;
        case D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_UNEXPECTEDSTRIDES: ret = "D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_UNEXPECTEDSTRIDES"; break;
        case D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDNUMSTRIDES: ret = "D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDNUMSTRIDES"; break;
        case D3D12_MESSAGE_ID_CREATEHULLSHADER_OUTOFMEMORY: ret = "D3D12_MESSAGE_ID_CREATEHULLSHADER_OUTOFMEMORY"; break;
        case D3D12_MESSAGE_ID_CREATEHULLSHADER_INVALIDSHADERBYTECODE: ret = "D3D12_MESSAGE_ID_CREATEHULLSHADER_INVALIDSHADERBYTECODE"; break;
        case D3D12_MESSAGE_ID_CREATEHULLSHADER_INVALIDSHADERTYPE: ret = "D3D12_MESSAGE_ID_CREATEHULLSHADER_INVALIDSHADERTYPE"; break;
        case D3D12_MESSAGE_ID_CREATEHULLSHADER_INVALIDCLASSLINKAGE: ret = "D3D12_MESSAGE_ID_CREATEHULLSHADER_INVALIDCLASSLINKAGE"; break;
        case D3D12_MESSAGE_ID_CREATEDOMAINSHADER_OUTOFMEMORY: ret = "D3D12_MESSAGE_ID_CREATEDOMAINSHADER_OUTOFMEMORY"; break;
        case D3D12_MESSAGE_ID_CREATEDOMAINSHADER_INVALIDSHADERBYTECODE: ret = "D3D12_MESSAGE_ID_CREATEDOMAINSHADER_INVALIDSHADERBYTECODE"; break;
        case D3D12_MESSAGE_ID_CREATEDOMAINSHADER_INVALIDSHADERTYPE: ret = "D3D12_MESSAGE_ID_CREATEDOMAINSHADER_INVALIDSHADERTYPE"; break;
        case D3D12_MESSAGE_ID_CREATEDOMAINSHADER_INVALIDCLASSLINKAGE: ret = "D3D12_MESSAGE_ID_CREATEDOMAINSHADER_INVALIDCLASSLINKAGE"; break;
        case D3D12_MESSAGE_ID_RESOURCE_UNMAP_NOTMAPPED: ret = "D3D12_MESSAGE_ID_RESOURCE_UNMAP_NOTMAPPED"; break;
        case D3D12_MESSAGE_ID_DEVICE_CHECKFEATURESUPPORT_MISMATCHED_DATA_SIZE: ret = "D3D12_MESSAGE_ID_DEVICE_CHECKFEATURESUPPORT_MISMATCHED_DATA_SIZE"; break;
        case D3D12_MESSAGE_ID_CREATECOMPUTESHADER_OUTOFMEMORY: ret = "D3D12_MESSAGE_ID_CREATECOMPUTESHADER_OUTOFMEMORY"; break;
        case D3D12_MESSAGE_ID_CREATECOMPUTESHADER_INVALIDSHADERBYTECODE: ret = "D3D12_MESSAGE_ID_CREATECOMPUTESHADER_INVALIDSHADERBYTECODE"; break;
        case D3D12_MESSAGE_ID_CREATECOMPUTESHADER_INVALIDCLASSLINKAGE: ret = "D3D12_MESSAGE_ID_CREATECOMPUTESHADER_INVALIDCLASSLINKAGE"; break;
        case D3D12_MESSAGE_ID_DEVICE_CREATEVERTEXSHADER_DOUBLEFLOATOPSNOTSUPPORTED: ret = "D3D12_MESSAGE_ID_DEVICE_CREATEVERTEXSHADER_DOUBLEFLOATOPSNOTSUPPORTED"; break;
        case D3D12_MESSAGE_ID_DEVICE_CREATEHULLSHADER_DOUBLEFLOATOPSNOTSUPPORTED: ret = "D3D12_MESSAGE_ID_DEVICE_CREATEHULLSHADER_DOUBLEFLOATOPSNOTSUPPORTED"; break;
        case D3D12_MESSAGE_ID_DEVICE_CREATEDOMAINSHADER_DOUBLEFLOATOPSNOTSUPPORTED: ret = "D3D12_MESSAGE_ID_DEVICE_CREATEDOMAINSHADER_DOUBLEFLOATOPSNOTSUPPORTED"; break;
        case D3D12_MESSAGE_ID_DEVICE_CREATEGEOMETRYSHADER_DOUBLEFLOATOPSNOTSUPPORTED: ret = "D3D12_MESSAGE_ID_DEVICE_CREATEGEOMETRYSHADER_DOUBLEFLOATOPSNOTSUPPORTED"; break;
        case D3D12_MESSAGE_ID_DEVICE_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_DOUBLEFLOATOPSNOTSUPPORTED: ret = "D3D12_MESSAGE_ID_DEVICE_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_DOUBLEFLOATOPSNOTSUPPORTED"; break;
        case D3D12_MESSAGE_ID_DEVICE_CREATEPIXELSHADER_DOUBLEFLOATOPSNOTSUPPORTED: ret = "D3D12_MESSAGE_ID_DEVICE_CREATEPIXELSHADER_DOUBLEFLOATOPSNOTSUPPORTED"; break;
        case D3D12_MESSAGE_ID_DEVICE_CREATECOMPUTESHADER_DOUBLEFLOATOPSNOTSUPPORTED: ret = "D3D12_MESSAGE_ID_DEVICE_CREATECOMPUTESHADER_DOUBLEFLOATOPSNOTSUPPORTED"; break;
        case D3D12_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDRESOURCE: ret = "D3D12_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDRESOURCE"; break;
        case D3D12_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDDESC: ret = "D3D12_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDDESC"; break;
        case D3D12_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDFORMAT: ret = "D3D12_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDFORMAT"; break;
        case D3D12_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDVIDEOPLANESLICE: ret = "D3D12_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDVIDEOPLANESLICE"; break;
        case D3D12_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDPLANESLICE: ret = "D3D12_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDPLANESLICE"; break;
        case D3D12_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDDIMENSIONS: ret = "D3D12_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDDIMENSIONS"; break;
        case D3D12_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_UNRECOGNIZEDFORMAT: ret = "D3D12_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_UNRECOGNIZEDFORMAT"; break;
        case D3D12_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDFLAGS: ret = "D3D12_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDFLAGS"; break;
        case D3D12_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDFORCEDSAMPLECOUNT: ret = "D3D12_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDFORCEDSAMPLECOUNT"; break;
        case D3D12_MESSAGE_ID_CREATEBLENDSTATE_INVALIDLOGICOPS: ret = "D3D12_MESSAGE_ID_CREATEBLENDSTATE_INVALIDLOGICOPS"; break;
        case D3D12_MESSAGE_ID_DEVICE_CREATEVERTEXSHADER_DOUBLEEXTENSIONSNOTSUPPORTED: ret = "D3D12_MESSAGE_ID_DEVICE_CREATEVERTEXSHADER_DOUBLEEXTENSIONSNOTSUPPORTED"; break;
        case D3D12_MESSAGE_ID_DEVICE_CREATEHULLSHADER_DOUBLEEXTENSIONSNOTSUPPORTED: ret = "D3D12_MESSAGE_ID_DEVICE_CREATEHULLSHADER_DOUBLEEXTENSIONSNOTSUPPORTED"; break;
        case D3D12_MESSAGE_ID_DEVICE_CREATEDOMAINSHADER_DOUBLEEXTENSIONSNOTSUPPORTED: ret = "D3D12_MESSAGE_ID_DEVICE_CREATEDOMAINSHADER_DOUBLEEXTENSIONSNOTSUPPORTED"; break;
        case D3D12_MESSAGE_ID_DEVICE_CREATEGEOMETRYSHADER_DOUBLEEXTENSIONSNOTSUPPORTED: ret = "D3D12_MESSAGE_ID_DEVICE_CREATEGEOMETRYSHADER_DOUBLEEXTENSIONSNOTSUPPORTED"; break;
        case D3D12_MESSAGE_ID_DEVICE_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_DOUBLEEXTENSIONSNOTSUPPORTED: ret = "D3D12_MESSAGE_ID_DEVICE_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_DOUBLEEXTENSIONSNOTSUPPORTED"; break;
        case D3D12_MESSAGE_ID_DEVICE_CREATEPIXELSHADER_DOUBLEEXTENSIONSNOTSUPPORTED: ret = "D3D12_MESSAGE_ID_DEVICE_CREATEPIXELSHADER_DOUBLEEXTENSIONSNOTSUPPORTED"; break;
        case D3D12_MESSAGE_ID_DEVICE_CREATECOMPUTESHADER_DOUBLEEXTENSIONSNOTSUPPORTED: ret = "D3D12_MESSAGE_ID_DEVICE_CREATECOMPUTESHADER_DOUBLEEXTENSIONSNOTSUPPORTED"; break;
        case D3D12_MESSAGE_ID_DEVICE_CREATEVERTEXSHADER_UAVSNOTSUPPORTED: ret = "D3D12_MESSAGE_ID_DEVICE_CREATEVERTEXSHADER_UAVSNOTSUPPORTED"; break;
        case D3D12_MESSAGE_ID_DEVICE_CREATEHULLSHADER_UAVSNOTSUPPORTED: ret = "D3D12_MESSAGE_ID_DEVICE_CREATEHULLSHADER_UAVSNOTSUPPORTED"; break;
        case D3D12_MESSAGE_ID_DEVICE_CREATEDOMAINSHADER_UAVSNOTSUPPORTED: ret = "D3D12_MESSAGE_ID_DEVICE_CREATEDOMAINSHADER_UAVSNOTSUPPORTED"; break;
        case D3D12_MESSAGE_ID_DEVICE_CREATEGEOMETRYSHADER_UAVSNOTSUPPORTED: ret = "D3D12_MESSAGE_ID_DEVICE_CREATEGEOMETRYSHADER_UAVSNOTSUPPORTED"; break;
        case D3D12_MESSAGE_ID_DEVICE_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_UAVSNOTSUPPORTED: ret = "D3D12_MESSAGE_ID_DEVICE_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_UAVSNOTSUPPORTED"; break;
        case D3D12_MESSAGE_ID_DEVICE_CREATEPIXELSHADER_UAVSNOTSUPPORTED: ret = "D3D12_MESSAGE_ID_DEVICE_CREATEPIXELSHADER_UAVSNOTSUPPORTED"; break;
        case D3D12_MESSAGE_ID_DEVICE_CREATECOMPUTESHADER_UAVSNOTSUPPORTED: ret = "D3D12_MESSAGE_ID_DEVICE_CREATECOMPUTESHADER_UAVSNOTSUPPORTED"; break;
        case D3D12_MESSAGE_ID_DEVICE_CLEARVIEW_INVALIDSOURCERECT: ret = "D3D12_MESSAGE_ID_DEVICE_CLEARVIEW_INVALIDSOURCERECT"; break;
        case D3D12_MESSAGE_ID_DEVICE_CLEARVIEW_EMPTYRECT: ret = "D3D12_MESSAGE_ID_DEVICE_CLEARVIEW_EMPTYRECT"; break;
        case D3D12_MESSAGE_ID_UPDATETILEMAPPINGS_INVALID_PARAMETER: ret = "D3D12_MESSAGE_ID_UPDATETILEMAPPINGS_INVALID_PARAMETER"; break;
        case D3D12_MESSAGE_ID_COPYTILEMAPPINGS_INVALID_PARAMETER: ret = "D3D12_MESSAGE_ID_COPYTILEMAPPINGS_INVALID_PARAMETER"; break;
        case D3D12_MESSAGE_ID_CREATEDEVICE_INVALIDARGS: ret = "D3D12_MESSAGE_ID_CREATEDEVICE_INVALIDARGS"; break;
        case D3D12_MESSAGE_ID_CREATEDEVICE_WARNING: ret = "D3D12_MESSAGE_ID_CREATEDEVICE_WARNING"; break;
        case D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_TYPE: ret = "D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_TYPE"; break;
        case D3D12_MESSAGE_ID_RESOURCE_BARRIER_NULL_POINTER: ret = "D3D12_MESSAGE_ID_RESOURCE_BARRIER_NULL_POINTER"; break;
        case D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_SUBRESOURCE: ret = "D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_SUBRESOURCE"; break;
        case D3D12_MESSAGE_ID_RESOURCE_BARRIER_RESERVED_BITS: ret = "D3D12_MESSAGE_ID_RESOURCE_BARRIER_RESERVED_BITS"; break;
        case D3D12_MESSAGE_ID_RESOURCE_BARRIER_MISSING_BIND_FLAGS: ret = "D3D12_MESSAGE_ID_RESOURCE_BARRIER_MISSING_BIND_FLAGS"; break;
        case D3D12_MESSAGE_ID_RESOURCE_BARRIER_MISMATCHING_MISC_FLAGS: ret = "D3D12_MESSAGE_ID_RESOURCE_BARRIER_MISMATCHING_MISC_FLAGS"; break;
        case D3D12_MESSAGE_ID_RESOURCE_BARRIER_MATCHING_STATES: ret = "D3D12_MESSAGE_ID_RESOURCE_BARRIER_MATCHING_STATES"; break;
        case D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_COMBINATION: ret = "D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_COMBINATION"; break;
        case D3D12_MESSAGE_ID_RESOURCE_BARRIER_BEFORE_AFTER_MISMATCH: ret = "D3D12_MESSAGE_ID_RESOURCE_BARRIER_BEFORE_AFTER_MISMATCH"; break;
        case D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_RESOURCE: ret = "D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_RESOURCE"; break;
        case D3D12_MESSAGE_ID_RESOURCE_BARRIER_SAMPLE_COUNT: ret = "D3D12_MESSAGE_ID_RESOURCE_BARRIER_SAMPLE_COUNT"; break;
        case D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_FLAGS: ret = "D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_FLAGS"; break;
        case D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_COMBINED_FLAGS: ret = "D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_COMBINED_FLAGS"; break;
        case D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_FLAGS_FOR_FORMAT: ret = "D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_FLAGS_FOR_FORMAT"; break;
        case D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_SPLIT_BARRIER: ret = "D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_SPLIT_BARRIER"; break;
        case D3D12_MESSAGE_ID_RESOURCE_BARRIER_UNMATCHED_END: ret = "D3D12_MESSAGE_ID_RESOURCE_BARRIER_UNMATCHED_END"; break;
        case D3D12_MESSAGE_ID_RESOURCE_BARRIER_UNMATCHED_BEGIN: ret = "D3D12_MESSAGE_ID_RESOURCE_BARRIER_UNMATCHED_BEGIN"; break;
        case D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_FLAG: ret = "D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_FLAG"; break;
        case D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_COMMAND_LIST_TYPE: ret = "D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_COMMAND_LIST_TYPE"; break;
        case D3D12_MESSAGE_ID_INVALID_SUBRESOURCE_STATE: ret = "D3D12_MESSAGE_ID_INVALID_SUBRESOURCE_STATE"; break;
        case D3D12_MESSAGE_ID_COMMAND_ALLOCATOR_CONTENTION: ret = "D3D12_MESSAGE_ID_COMMAND_ALLOCATOR_CONTENTION"; break;
        case D3D12_MESSAGE_ID_COMMAND_ALLOCATOR_RESET: ret = "D3D12_MESSAGE_ID_COMMAND_ALLOCATOR_RESET"; break;
        case D3D12_MESSAGE_ID_COMMAND_ALLOCATOR_RESET_BUNDLE: ret = "D3D12_MESSAGE_ID_COMMAND_ALLOCATOR_RESET_BUNDLE"; break;
        case D3D12_MESSAGE_ID_COMMAND_ALLOCATOR_CANNOT_RESET: ret = "D3D12_MESSAGE_ID_COMMAND_ALLOCATOR_CANNOT_RESET"; break;
        case D3D12_MESSAGE_ID_COMMAND_LIST_OPEN: ret = "D3D12_MESSAGE_ID_COMMAND_LIST_OPEN"; break;
        case D3D12_MESSAGE_ID_INVALID_BUNDLE_API: ret = "D3D12_MESSAGE_ID_INVALID_BUNDLE_API"; break;
        case D3D12_MESSAGE_ID_COMMAND_LIST_CLOSED: ret = "D3D12_MESSAGE_ID_COMMAND_LIST_CLOSED"; break;
        case D3D12_MESSAGE_ID_WRONG_COMMAND_ALLOCATOR_TYPE: ret = "D3D12_MESSAGE_ID_WRONG_COMMAND_ALLOCATOR_TYPE"; break;
        case D3D12_MESSAGE_ID_COMMAND_ALLOCATOR_SYNC: ret = "D3D12_MESSAGE_ID_COMMAND_ALLOCATOR_SYNC"; break;
        case D3D12_MESSAGE_ID_COMMAND_LIST_SYNC: ret = "D3D12_MESSAGE_ID_COMMAND_LIST_SYNC"; break;
        case D3D12_MESSAGE_ID_SET_DESCRIPTOR_HEAP_INVALID: ret = "D3D12_MESSAGE_ID_SET_DESCRIPTOR_HEAP_INVALID"; break;
        case D3D12_MESSAGE_ID_CREATE_COMMANDQUEUE: ret = "D3D12_MESSAGE_ID_CREATE_COMMANDQUEUE"; break;
        case D3D12_MESSAGE_ID_CREATE_COMMANDALLOCATOR: ret = "D3D12_MESSAGE_ID_CREATE_COMMANDALLOCATOR"; break;
        case D3D12_MESSAGE_ID_CREATE_PIPELINESTATE: ret = "D3D12_MESSAGE_ID_CREATE_PIPELINESTATE"; break;
        case D3D12_MESSAGE_ID_CREATE_COMMANDLIST12: ret = "D3D12_MESSAGE_ID_CREATE_COMMANDLIST12"; break;
        case D3D12_MESSAGE_ID_CREATE_RESOURCE: ret = "D3D12_MESSAGE_ID_CREATE_RESOURCE"; break;
        case D3D12_MESSAGE_ID_CREATE_DESCRIPTORHEAP: ret = "D3D12_MESSAGE_ID_CREATE_DESCRIPTORHEAP"; break;
        case D3D12_MESSAGE_ID_CREATE_ROOTSIGNATURE: ret = "D3D12_MESSAGE_ID_CREATE_ROOTSIGNATURE"; break;
        case D3D12_MESSAGE_ID_CREATE_LIBRARY: ret = "D3D12_MESSAGE_ID_CREATE_LIBRARY"; break;
        case D3D12_MESSAGE_ID_CREATE_HEAP: ret = "D3D12_MESSAGE_ID_CREATE_HEAP"; break;
        case D3D12_MESSAGE_ID_CREATE_MONITOREDFENCE: ret = "D3D12_MESSAGE_ID_CREATE_MONITOREDFENCE"; break;
        case D3D12_MESSAGE_ID_CREATE_QUERYHEAP: ret = "D3D12_MESSAGE_ID_CREATE_QUERYHEAP"; break;
        case D3D12_MESSAGE_ID_CREATE_COMMANDSIGNATURE: ret = "D3D12_MESSAGE_ID_CREATE_COMMANDSIGNATURE"; break;
        case D3D12_MESSAGE_ID_LIVE_COMMANDQUEUE: ret = "D3D12_MESSAGE_ID_LIVE_COMMANDQUEUE"; break;
        case D3D12_MESSAGE_ID_LIVE_COMMANDALLOCATOR: ret = "D3D12_MESSAGE_ID_LIVE_COMMANDALLOCATOR"; break;
        case D3D12_MESSAGE_ID_LIVE_PIPELINESTATE: ret = "D3D12_MESSAGE_ID_LIVE_PIPELINESTATE"; break;
        case D3D12_MESSAGE_ID_LIVE_COMMANDLIST12: ret = "D3D12_MESSAGE_ID_LIVE_COMMANDLIST12"; break;
        case D3D12_MESSAGE_ID_LIVE_RESOURCE: ret = "D3D12_MESSAGE_ID_LIVE_RESOURCE"; break;
        case D3D12_MESSAGE_ID_LIVE_DESCRIPTORHEAP: ret = "D3D12_MESSAGE_ID_LIVE_DESCRIPTORHEAP"; break;
        case D3D12_MESSAGE_ID_LIVE_ROOTSIGNATURE: ret = "D3D12_MESSAGE_ID_LIVE_ROOTSIGNATURE"; break;
        case D3D12_MESSAGE_ID_LIVE_LIBRARY: ret = "D3D12_MESSAGE_ID_LIVE_LIBRARY"; break;
        case D3D12_MESSAGE_ID_LIVE_HEAP: ret = "D3D12_MESSAGE_ID_LIVE_HEAP"; break;
        case D3D12_MESSAGE_ID_LIVE_MONITOREDFENCE: ret = "D3D12_MESSAGE_ID_LIVE_MONITOREDFENCE"; break;
        case D3D12_MESSAGE_ID_LIVE_QUERYHEAP: ret = "D3D12_MESSAGE_ID_LIVE_QUERYHEAP"; break;
        case D3D12_MESSAGE_ID_LIVE_COMMANDSIGNATURE: ret = "D3D12_MESSAGE_ID_LIVE_COMMANDSIGNATURE"; break;
        case D3D12_MESSAGE_ID_DESTROY_COMMANDQUEUE: ret = "D3D12_MESSAGE_ID_DESTROY_COMMANDQUEUE"; break;
        case D3D12_MESSAGE_ID_DESTROY_COMMANDALLOCATOR: ret = "D3D12_MESSAGE_ID_DESTROY_COMMANDALLOCATOR"; break;
        case D3D12_MESSAGE_ID_DESTROY_PIPELINESTATE: ret = "D3D12_MESSAGE_ID_DESTROY_PIPELINESTATE"; break;
        case D3D12_MESSAGE_ID_DESTROY_COMMANDLIST12: ret = "D3D12_MESSAGE_ID_DESTROY_COMMANDLIST12"; break;
        case D3D12_MESSAGE_ID_DESTROY_RESOURCE: ret = "D3D12_MESSAGE_ID_DESTROY_RESOURCE"; break;
        case D3D12_MESSAGE_ID_DESTROY_DESCRIPTORHEAP: ret = "D3D12_MESSAGE_ID_DESTROY_DESCRIPTORHEAP"; break;
        case D3D12_MESSAGE_ID_DESTROY_ROOTSIGNATURE: ret = "D3D12_MESSAGE_ID_DESTROY_ROOTSIGNATURE"; break;
        case D3D12_MESSAGE_ID_DESTROY_LIBRARY: ret = "D3D12_MESSAGE_ID_DESTROY_LIBRARY"; break;
        case D3D12_MESSAGE_ID_DESTROY_HEAP: ret = "D3D12_MESSAGE_ID_DESTROY_HEAP"; break;
        case D3D12_MESSAGE_ID_DESTROY_MONITOREDFENCE: ret = "D3D12_MESSAGE_ID_DESTROY_MONITOREDFENCE"; break;
        case D3D12_MESSAGE_ID_DESTROY_QUERYHEAP: ret = "D3D12_MESSAGE_ID_DESTROY_QUERYHEAP"; break;
        case D3D12_MESSAGE_ID_DESTROY_COMMANDSIGNATURE: ret = "D3D12_MESSAGE_ID_DESTROY_COMMANDSIGNATURE"; break;
        case D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDDIMENSIONS: ret = "D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDDIMENSIONS"; break;
        case D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDMISCFLAGS: ret = "D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDMISCFLAGS"; break;
        case D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDARG_RETURN: ret = "D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDARG_RETURN"; break;
        case D3D12_MESSAGE_ID_CREATERESOURCE_OUTOFMEMORY_RETURN: ret = "D3D12_MESSAGE_ID_CREATERESOURCE_OUTOFMEMORY_RETURN"; break;
        case D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDDESC: ret = "D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDDESC"; break;
        case D3D12_MESSAGE_ID_POSSIBLY_INVALID_SUBRESOURCE_STATE: ret = "D3D12_MESSAGE_ID_POSSIBLY_INVALID_SUBRESOURCE_STATE"; break;
        case D3D12_MESSAGE_ID_INVALID_USE_OF_NON_RESIDENT_RESOURCE: ret = "D3D12_MESSAGE_ID_INVALID_USE_OF_NON_RESIDENT_RESOURCE"; break;
        case D3D12_MESSAGE_ID_POSSIBLE_INVALID_USE_OF_NON_RESIDENT_RESOURCE: ret = "D3D12_MESSAGE_ID_POSSIBLE_INVALID_USE_OF_NON_RESIDENT_RESOURCE"; break;
        case D3D12_MESSAGE_ID_BUNDLE_PIPELINE_STATE_MISMATCH: ret = "D3D12_MESSAGE_ID_BUNDLE_PIPELINE_STATE_MISMATCH"; break;
        case D3D12_MESSAGE_ID_PRIMITIVE_TOPOLOGY_MISMATCH_PIPELINE_STATE: ret = "D3D12_MESSAGE_ID_PRIMITIVE_TOPOLOGY_MISMATCH_PIPELINE_STATE"; break;
        case D3D12_MESSAGE_ID_RENDER_TARGET_FORMAT_MISMATCH_PIPELINE_STATE: ret = "D3D12_MESSAGE_ID_RENDER_TARGET_FORMAT_MISMATCH_PIPELINE_STATE"; break;
        case D3D12_MESSAGE_ID_RENDER_TARGET_SAMPLE_DESC_MISMATCH_PIPELINE_STATE: ret = "D3D12_MESSAGE_ID_RENDER_TARGET_SAMPLE_DESC_MISMATCH_PIPELINE_STATE"; break;
        case D3D12_MESSAGE_ID_DEPTH_STENCIL_FORMAT_MISMATCH_PIPELINE_STATE: ret = "D3D12_MESSAGE_ID_DEPTH_STENCIL_FORMAT_MISMATCH_PIPELINE_STATE"; break;
        case D3D12_MESSAGE_ID_DEPTH_STENCIL_SAMPLE_DESC_MISMATCH_PIPELINE_STATE: ret = "D3D12_MESSAGE_ID_DEPTH_STENCIL_SAMPLE_DESC_MISMATCH_PIPELINE_STATE"; break;
        case D3D12_MESSAGE_ID_CREATESHADER_INVALIDBYTECODE: ret = "D3D12_MESSAGE_ID_CREATESHADER_INVALIDBYTECODE"; break;
        case D3D12_MESSAGE_ID_CREATEHEAP_NULLDESC: ret = "D3D12_MESSAGE_ID_CREATEHEAP_NULLDESC"; break;
        case D3D12_MESSAGE_ID_CREATEHEAP_INVALIDSIZE: ret = "D3D12_MESSAGE_ID_CREATEHEAP_INVALIDSIZE"; break;
        case D3D12_MESSAGE_ID_CREATEHEAP_UNRECOGNIZEDHEAPTYPE: ret = "D3D12_MESSAGE_ID_CREATEHEAP_UNRECOGNIZEDHEAPTYPE"; break;
        case D3D12_MESSAGE_ID_CREATEHEAP_UNRECOGNIZEDCPUPAGEPROPERTIES: ret = "D3D12_MESSAGE_ID_CREATEHEAP_UNRECOGNIZEDCPUPAGEPROPERTIES"; break;
        case D3D12_MESSAGE_ID_CREATEHEAP_UNRECOGNIZEDMEMORYPOOL: ret = "D3D12_MESSAGE_ID_CREATEHEAP_UNRECOGNIZEDMEMORYPOOL"; break;
        case D3D12_MESSAGE_ID_CREATEHEAP_INVALIDPROPERTIES: ret = "D3D12_MESSAGE_ID_CREATEHEAP_INVALIDPROPERTIES"; break;
        case D3D12_MESSAGE_ID_CREATEHEAP_INVALIDALIGNMENT: ret = "D3D12_MESSAGE_ID_CREATEHEAP_INVALIDALIGNMENT"; break;
        case D3D12_MESSAGE_ID_CREATEHEAP_UNRECOGNIZEDMISCFLAGS: ret = "D3D12_MESSAGE_ID_CREATEHEAP_UNRECOGNIZEDMISCFLAGS"; break;
        case D3D12_MESSAGE_ID_CREATEHEAP_INVALIDMISCFLAGS: ret = "D3D12_MESSAGE_ID_CREATEHEAP_INVALIDMISCFLAGS"; break;
        case D3D12_MESSAGE_ID_CREATEHEAP_INVALIDARG_RETURN: ret = "D3D12_MESSAGE_ID_CREATEHEAP_INVALIDARG_RETURN"; break;
        case D3D12_MESSAGE_ID_CREATEHEAP_OUTOFMEMORY_RETURN: ret = "D3D12_MESSAGE_ID_CREATEHEAP_OUTOFMEMORY_RETURN"; break;
        case D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_NULLHEAPPROPERTIES: ret = "D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_NULLHEAPPROPERTIES"; break;
        case D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_UNRECOGNIZEDHEAPTYPE: ret = "D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_UNRECOGNIZEDHEAPTYPE"; break;
        case D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_UNRECOGNIZEDCPUPAGEPROPERTIES: ret = "D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_UNRECOGNIZEDCPUPAGEPROPERTIES"; break;
        case D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_UNRECOGNIZEDMEMORYPOOL: ret = "D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_UNRECOGNIZEDMEMORYPOOL"; break;
        case D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_INVALIDHEAPPROPERTIES: ret = "D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_INVALIDHEAPPROPERTIES"; break;
        case D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_UNRECOGNIZEDHEAPMISCFLAGS: ret = "D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_UNRECOGNIZEDHEAPMISCFLAGS"; break;
        case D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_INVALIDHEAPMISCFLAGS: ret = "D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_INVALIDHEAPMISCFLAGS"; break;
        case D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_INVALIDARG_RETURN: ret = "D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_INVALIDARG_RETURN"; break;
        case D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_OUTOFMEMORY_RETURN: ret = "D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_OUTOFMEMORY_RETURN"; break;
        case D3D12_MESSAGE_ID_GETCUSTOMHEAPPROPERTIES_UNRECOGNIZEDHEAPTYPE: ret = "D3D12_MESSAGE_ID_GETCUSTOMHEAPPROPERTIES_UNRECOGNIZEDHEAPTYPE"; break;
        case D3D12_MESSAGE_ID_GETCUSTOMHEAPPROPERTIES_INVALIDHEAPTYPE: ret = "D3D12_MESSAGE_ID_GETCUSTOMHEAPPROPERTIES_INVALIDHEAPTYPE"; break;
        case D3D12_MESSAGE_ID_CREATE_DESCRIPTOR_HEAP_INVALID_DESC: ret = "D3D12_MESSAGE_ID_CREATE_DESCRIPTOR_HEAP_INVALID_DESC"; break;
        case D3D12_MESSAGE_ID_INVALID_DESCRIPTOR_HANDLE: ret = "D3D12_MESSAGE_ID_INVALID_DESCRIPTOR_HANDLE"; break;
        case D3D12_MESSAGE_ID_CREATERASTERIZERSTATE_INVALID_CONSERVATIVERASTERMODE: ret = "D3D12_MESSAGE_ID_CREATERASTERIZERSTATE_INVALID_CONSERVATIVERASTERMODE"; break;
        case D3D12_MESSAGE_ID_CREATE_CONSTANT_BUFFER_VIEW_INVALID_RESOURCE: ret = "D3D12_MESSAGE_ID_CREATE_CONSTANT_BUFFER_VIEW_INVALID_RESOURCE"; break;
        case D3D12_MESSAGE_ID_CREATE_CONSTANT_BUFFER_VIEW_INVALID_DESC: ret = "D3D12_MESSAGE_ID_CREATE_CONSTANT_BUFFER_VIEW_INVALID_DESC"; break;
        case D3D12_MESSAGE_ID_CREATE_UNORDEREDACCESS_VIEW_INVALID_COUNTER_USAGE: ret = "D3D12_MESSAGE_ID_CREATE_UNORDEREDACCESS_VIEW_INVALID_COUNTER_USAGE"; break;
        case D3D12_MESSAGE_ID_COPY_DESCRIPTORS_INVALID_RANGES: ret = "D3D12_MESSAGE_ID_COPY_DESCRIPTORS_INVALID_RANGES"; break;
        case D3D12_MESSAGE_ID_COPY_DESCRIPTORS_WRITE_ONLY_DESCRIPTOR: ret = "D3D12_MESSAGE_ID_COPY_DESCRIPTORS_WRITE_ONLY_DESCRIPTOR"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_RTV_FORMAT_NOT_UNKNOWN: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_RTV_FORMAT_NOT_UNKNOWN"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INVALID_RENDER_TARGET_COUNT: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INVALID_RENDER_TARGET_COUNT"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_VERTEX_SHADER_NOT_SET: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_VERTEX_SHADER_NOT_SET"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INPUTLAYOUT_NOT_SET: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INPUTLAYOUT_NOT_SET"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_LINKAGE_HS_DS_SIGNATURE_MISMATCH: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_LINKAGE_HS_DS_SIGNATURE_MISMATCH"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_LINKAGE_REGISTERINDEX: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_LINKAGE_REGISTERINDEX"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_LINKAGE_COMPONENTTYPE: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_LINKAGE_COMPONENTTYPE"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_LINKAGE_REGISTERMASK: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_LINKAGE_REGISTERMASK"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_LINKAGE_SYSTEMVALUE: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_LINKAGE_SYSTEMVALUE"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_LINKAGE_NEVERWRITTEN_ALWAYSREADS: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_LINKAGE_NEVERWRITTEN_ALWAYSREADS"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_LINKAGE_MINPRECISION: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_LINKAGE_MINPRECISION"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_LINKAGE_SEMANTICNAME_NOT_FOUND: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_LINKAGE_SEMANTICNAME_NOT_FOUND"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_HS_XOR_DS_MISMATCH: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_HS_XOR_DS_MISMATCH"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_HULL_SHADER_INPUT_TOPOLOGY_MISMATCH: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_HULL_SHADER_INPUT_TOPOLOGY_MISMATCH"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_HS_DS_CONTROL_POINT_COUNT_MISMATCH: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_HS_DS_CONTROL_POINT_COUNT_MISMATCH"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_HS_DS_TESSELLATOR_DOMAIN_MISMATCH: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_HS_DS_TESSELLATOR_DOMAIN_MISMATCH"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INVALID_USE_OF_CENTER_MULTISAMPLE_PATTERN: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INVALID_USE_OF_CENTER_MULTISAMPLE_PATTERN"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INVALID_USE_OF_FORCED_SAMPLE_COUNT: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INVALID_USE_OF_FORCED_SAMPLE_COUNT"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INVALID_PRIMITIVETOPOLOGY: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INVALID_PRIMITIVETOPOLOGY"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INVALID_SYSTEMVALUE: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INVALID_SYSTEMVALUE"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_OM_DUAL_SOURCE_BLENDING_CAN_ONLY_HAVE_RENDER_TARGET_0: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_OM_DUAL_SOURCE_BLENDING_CAN_ONLY_HAVE_RENDER_TARGET_0"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_OM_RENDER_TARGET_DOES_NOT_SUPPORT_BLENDING: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_OM_RENDER_TARGET_DOES_NOT_SUPPORT_BLENDING"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_PS_OUTPUT_TYPE_MISMATCH: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_PS_OUTPUT_TYPE_MISMATCH"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_OM_RENDER_TARGET_DOES_NOT_SUPPORT_LOGIC_OPS: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_OM_RENDER_TARGET_DOES_NOT_SUPPORT_LOGIC_OPS"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_RENDERTARGETVIEW_NOT_SET: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_RENDERTARGETVIEW_NOT_SET"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_DEPTHSTENCILVIEW_NOT_SET: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_DEPTHSTENCILVIEW_NOT_SET"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_GS_INPUT_PRIMITIVE_MISMATCH: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_GS_INPUT_PRIMITIVE_MISMATCH"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_POSITION_NOT_PRESENT: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_POSITION_NOT_PRESENT"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_MISSING_ROOT_SIGNATURE_FLAGS: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_MISSING_ROOT_SIGNATURE_FLAGS"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INVALID_INDEX_BUFFER_PROPERTIES: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INVALID_INDEX_BUFFER_PROPERTIES"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INVALID_SAMPLE_DESC: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INVALID_SAMPLE_DESC"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_HS_ROOT_SIGNATURE_MISMATCH: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_HS_ROOT_SIGNATURE_MISMATCH"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_DS_ROOT_SIGNATURE_MISMATCH: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_DS_ROOT_SIGNATURE_MISMATCH"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_VS_ROOT_SIGNATURE_MISMATCH: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_VS_ROOT_SIGNATURE_MISMATCH"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_GS_ROOT_SIGNATURE_MISMATCH: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_GS_ROOT_SIGNATURE_MISMATCH"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_PS_ROOT_SIGNATURE_MISMATCH: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_PS_ROOT_SIGNATURE_MISMATCH"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_MISSING_ROOT_SIGNATURE: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_MISSING_ROOT_SIGNATURE"; break;
        case D3D12_MESSAGE_ID_EXECUTE_BUNDLE_OPEN_BUNDLE: ret = "D3D12_MESSAGE_ID_EXECUTE_BUNDLE_OPEN_BUNDLE"; break;
        case D3D12_MESSAGE_ID_EXECUTE_BUNDLE_DESCRIPTOR_HEAP_MISMATCH: ret = "D3D12_MESSAGE_ID_EXECUTE_BUNDLE_DESCRIPTOR_HEAP_MISMATCH"; break;
        case D3D12_MESSAGE_ID_EXECUTE_BUNDLE_TYPE: ret = "D3D12_MESSAGE_ID_EXECUTE_BUNDLE_TYPE"; break;
        case D3D12_MESSAGE_ID_DRAW_EMPTY_SCISSOR_RECTANGLE: ret = "D3D12_MESSAGE_ID_DRAW_EMPTY_SCISSOR_RECTANGLE"; break;
        case D3D12_MESSAGE_ID_CREATE_ROOT_SIGNATURE_BLOB_NOT_FOUND: ret = "D3D12_MESSAGE_ID_CREATE_ROOT_SIGNATURE_BLOB_NOT_FOUND"; break;
        case D3D12_MESSAGE_ID_CREATE_ROOT_SIGNATURE_DESERIALIZE_FAILED: ret = "D3D12_MESSAGE_ID_CREATE_ROOT_SIGNATURE_DESERIALIZE_FAILED"; break;
        case D3D12_MESSAGE_ID_CREATE_ROOT_SIGNATURE_INVALID_CONFIGURATION: ret = "D3D12_MESSAGE_ID_CREATE_ROOT_SIGNATURE_INVALID_CONFIGURATION"; break;
        case D3D12_MESSAGE_ID_CREATE_ROOT_SIGNATURE_NOT_SUPPORTED_ON_DEVICE: ret = "D3D12_MESSAGE_ID_CREATE_ROOT_SIGNATURE_NOT_SUPPORTED_ON_DEVICE"; break;
        case D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_NULLRESOURCEPROPERTIES: ret = "D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_NULLRESOURCEPROPERTIES"; break;
        case D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_NULLHEAP: ret = "D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_NULLHEAP"; break;
        case D3D12_MESSAGE_ID_GETRESOURCEALLOCATIONINFO_INVALIDRDESCS: ret = "D3D12_MESSAGE_ID_GETRESOURCEALLOCATIONINFO_INVALIDRDESCS"; break;
        case D3D12_MESSAGE_ID_MAKERESIDENT_NULLOBJECTARRAY: ret = "D3D12_MESSAGE_ID_MAKERESIDENT_NULLOBJECTARRAY"; break;
        case D3D12_MESSAGE_ID_EVICT_NULLOBJECTARRAY: ret = "D3D12_MESSAGE_ID_EVICT_NULLOBJECTARRAY"; break;
        case D3D12_MESSAGE_ID_SET_DESCRIPTOR_TABLE_INVALID: ret = "D3D12_MESSAGE_ID_SET_DESCRIPTOR_TABLE_INVALID"; break;
        case D3D12_MESSAGE_ID_SET_ROOT_CONSTANT_INVALID: ret = "D3D12_MESSAGE_ID_SET_ROOT_CONSTANT_INVALID"; break;
        case D3D12_MESSAGE_ID_SET_ROOT_CONSTANT_BUFFER_VIEW_INVALID: ret = "D3D12_MESSAGE_ID_SET_ROOT_CONSTANT_BUFFER_VIEW_INVALID"; break;
        case D3D12_MESSAGE_ID_SET_ROOT_SHADER_RESOURCE_VIEW_INVALID: ret = "D3D12_MESSAGE_ID_SET_ROOT_SHADER_RESOURCE_VIEW_INVALID"; break;
        case D3D12_MESSAGE_ID_SET_ROOT_UNORDERED_ACCESS_VIEW_INVALID: ret = "D3D12_MESSAGE_ID_SET_ROOT_UNORDERED_ACCESS_VIEW_INVALID"; break;
        case D3D12_MESSAGE_ID_SET_VERTEX_BUFFERS_INVALID_DESC: ret = "D3D12_MESSAGE_ID_SET_VERTEX_BUFFERS_INVALID_DESC"; break;
        case D3D12_MESSAGE_ID_SET_INDEX_BUFFER_INVALID_DESC: ret = "D3D12_MESSAGE_ID_SET_INDEX_BUFFER_INVALID_DESC"; break;
        case D3D12_MESSAGE_ID_SET_STREAM_OUTPUT_BUFFERS_INVALID_DESC: ret = "D3D12_MESSAGE_ID_SET_STREAM_OUTPUT_BUFFERS_INVALID_DESC"; break;
        case D3D12_MESSAGE_ID_CREATERESOURCE_UNRECOGNIZEDDIMENSIONALITY: ret = "D3D12_MESSAGE_ID_CREATERESOURCE_UNRECOGNIZEDDIMENSIONALITY"; break;
        case D3D12_MESSAGE_ID_CREATERESOURCE_UNRECOGNIZEDLAYOUT: ret = "D3D12_MESSAGE_ID_CREATERESOURCE_UNRECOGNIZEDLAYOUT"; break;
        case D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDDIMENSIONALITY: ret = "D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDDIMENSIONALITY"; break;
        case D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDALIGNMENT: ret = "D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDALIGNMENT"; break;
        case D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDMIPLEVELS: ret = "D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDMIPLEVELS"; break;
        case D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDSAMPLEDESC: ret = "D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDSAMPLEDESC"; break;
        case D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDLAYOUT: ret = "D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDLAYOUT"; break;
        case D3D12_MESSAGE_ID_SET_INDEX_BUFFER_INVALID: ret = "D3D12_MESSAGE_ID_SET_INDEX_BUFFER_INVALID"; break;
        case D3D12_MESSAGE_ID_SET_VERTEX_BUFFERS_INVALID: ret = "D3D12_MESSAGE_ID_SET_VERTEX_BUFFERS_INVALID"; break;
        case D3D12_MESSAGE_ID_SET_STREAM_OUTPUT_BUFFERS_INVALID: ret = "D3D12_MESSAGE_ID_SET_STREAM_OUTPUT_BUFFERS_INVALID"; break;
        case D3D12_MESSAGE_ID_SET_RENDER_TARGETS_INVALID: ret = "D3D12_MESSAGE_ID_SET_RENDER_TARGETS_INVALID"; break;
        case D3D12_MESSAGE_ID_CREATEQUERY_HEAP_INVALID_PARAMETERS: ret = "D3D12_MESSAGE_ID_CREATEQUERY_HEAP_INVALID_PARAMETERS"; break;
        case D3D12_MESSAGE_ID_BEGIN_END_QUERY_INVALID_PARAMETERS: ret = "D3D12_MESSAGE_ID_BEGIN_END_QUERY_INVALID_PARAMETERS"; break;
        case D3D12_MESSAGE_ID_CLOSE_COMMAND_LIST_OPEN_QUERY: ret = "D3D12_MESSAGE_ID_CLOSE_COMMAND_LIST_OPEN_QUERY"; break;
        case D3D12_MESSAGE_ID_RESOLVE_QUERY_DATA_INVALID_PARAMETERS: ret = "D3D12_MESSAGE_ID_RESOLVE_QUERY_DATA_INVALID_PARAMETERS"; break;
        case D3D12_MESSAGE_ID_SET_PREDICATION_INVALID_PARAMETERS: ret = "D3D12_MESSAGE_ID_SET_PREDICATION_INVALID_PARAMETERS"; break;
        case D3D12_MESSAGE_ID_TIMESTAMPS_NOT_SUPPORTED: ret = "D3D12_MESSAGE_ID_TIMESTAMPS_NOT_SUPPORTED"; break;
        case D3D12_MESSAGE_ID_CREATERESOURCE_UNRECOGNIZEDFORMAT: ret = "D3D12_MESSAGE_ID_CREATERESOURCE_UNRECOGNIZEDFORMAT"; break;
        case D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDFORMAT: ret = "D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDFORMAT"; break;
        case D3D12_MESSAGE_ID_GETCOPYABLEFOOTPRINTS_INVALIDSUBRESOURCERANGE: ret = "D3D12_MESSAGE_ID_GETCOPYABLEFOOTPRINTS_INVALIDSUBRESOURCERANGE"; break;
        case D3D12_MESSAGE_ID_GETCOPYABLEFOOTPRINTS_INVALIDBASEOFFSET: ret = "D3D12_MESSAGE_ID_GETCOPYABLEFOOTPRINTS_INVALIDBASEOFFSET"; break;
        case D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_HEAP: ret = "D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_HEAP"; break;
        case D3D12_MESSAGE_ID_CREATE_SAMPLER_INVALID: ret = "D3D12_MESSAGE_ID_CREATE_SAMPLER_INVALID"; break;
        case D3D12_MESSAGE_ID_CREATECOMMANDSIGNATURE_INVALID: ret = "D3D12_MESSAGE_ID_CREATECOMMANDSIGNATURE_INVALID"; break;
        case D3D12_MESSAGE_ID_EXECUTE_INDIRECT_INVALID_PARAMETERS: ret = "D3D12_MESSAGE_ID_EXECUTE_INDIRECT_INVALID_PARAMETERS"; break;
        case D3D12_MESSAGE_ID_GETGPUVIRTUALADDRESS_INVALID_RESOURCE_DIMENSION: ret = "D3D12_MESSAGE_ID_GETGPUVIRTUALADDRESS_INVALID_RESOURCE_DIMENSION"; break;
        case D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDCLEARVALUE: ret = "D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDCLEARVALUE"; break;
        case D3D12_MESSAGE_ID_CREATERESOURCE_UNRECOGNIZEDCLEARVALUEFORMAT: ret = "D3D12_MESSAGE_ID_CREATERESOURCE_UNRECOGNIZEDCLEARVALUEFORMAT"; break;
        case D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDCLEARVALUEFORMAT: ret = "D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDCLEARVALUEFORMAT"; break;
        case D3D12_MESSAGE_ID_CREATERESOURCE_CLEARVALUEDENORMFLUSH: ret = "D3D12_MESSAGE_ID_CREATERESOURCE_CLEARVALUEDENORMFLUSH"; break;
        case D3D12_MESSAGE_ID_CLEARRENDERTARGETVIEW_MISMATCHINGCLEARVALUE: ret = "D3D12_MESSAGE_ID_CLEARRENDERTARGETVIEW_MISMATCHINGCLEARVALUE"; break;
        case D3D12_MESSAGE_ID_CLEARDEPTHSTENCILVIEW_MISMATCHINGCLEARVALUE: ret = "D3D12_MESSAGE_ID_CLEARDEPTHSTENCILVIEW_MISMATCHINGCLEARVALUE"; break;
        case D3D12_MESSAGE_ID_MAP_INVALIDHEAP: ret = "D3D12_MESSAGE_ID_MAP_INVALIDHEAP"; break;
        case D3D12_MESSAGE_ID_UNMAP_INVALIDHEAP: ret = "D3D12_MESSAGE_ID_UNMAP_INVALIDHEAP"; break;
        case D3D12_MESSAGE_ID_MAP_INVALIDRESOURCE: ret = "D3D12_MESSAGE_ID_MAP_INVALIDRESOURCE"; break;
        case D3D12_MESSAGE_ID_UNMAP_INVALIDRESOURCE: ret = "D3D12_MESSAGE_ID_UNMAP_INVALIDRESOURCE"; break;
        case D3D12_MESSAGE_ID_MAP_INVALIDSUBRESOURCE: ret = "D3D12_MESSAGE_ID_MAP_INVALIDSUBRESOURCE"; break;
        case D3D12_MESSAGE_ID_UNMAP_INVALIDSUBRESOURCE: ret = "D3D12_MESSAGE_ID_UNMAP_INVALIDSUBRESOURCE"; break;
        case D3D12_MESSAGE_ID_MAP_INVALIDRANGE: ret = "D3D12_MESSAGE_ID_MAP_INVALIDRANGE"; break;
        case D3D12_MESSAGE_ID_UNMAP_INVALIDRANGE: ret = "D3D12_MESSAGE_ID_UNMAP_INVALIDRANGE"; break;
        case D3D12_MESSAGE_ID_MAP_INVALIDDATAPOINTER: ret = "D3D12_MESSAGE_ID_MAP_INVALIDDATAPOINTER"; break;
        case D3D12_MESSAGE_ID_MAP_INVALIDARG_RETURN: ret = "D3D12_MESSAGE_ID_MAP_INVALIDARG_RETURN"; break;
        case D3D12_MESSAGE_ID_MAP_OUTOFMEMORY_RETURN: ret = "D3D12_MESSAGE_ID_MAP_OUTOFMEMORY_RETURN"; break;
        case D3D12_MESSAGE_ID_EXECUTECOMMANDLISTS_BUNDLENOTSUPPORTED: ret = "D3D12_MESSAGE_ID_EXECUTECOMMANDLISTS_BUNDLENOTSUPPORTED"; break;
        case D3D12_MESSAGE_ID_EXECUTECOMMANDLISTS_COMMANDLISTMISMATCH: ret = "D3D12_MESSAGE_ID_EXECUTECOMMANDLISTS_COMMANDLISTMISMATCH"; break;
        case D3D12_MESSAGE_ID_EXECUTECOMMANDLISTS_OPENCOMMANDLIST: ret = "D3D12_MESSAGE_ID_EXECUTECOMMANDLISTS_OPENCOMMANDLIST"; break;
        case D3D12_MESSAGE_ID_EXECUTECOMMANDLISTS_FAILEDCOMMANDLIST: ret = "D3D12_MESSAGE_ID_EXECUTECOMMANDLISTS_FAILEDCOMMANDLIST"; break;
        case D3D12_MESSAGE_ID_COPYBUFFERREGION_NULLDST: ret = "D3D12_MESSAGE_ID_COPYBUFFERREGION_NULLDST"; break;
        case D3D12_MESSAGE_ID_COPYBUFFERREGION_INVALIDDSTRESOURCEDIMENSION: ret = "D3D12_MESSAGE_ID_COPYBUFFERREGION_INVALIDDSTRESOURCEDIMENSION"; break;
        case D3D12_MESSAGE_ID_COPYBUFFERREGION_DSTRANGEOUTOFBOUNDS: ret = "D3D12_MESSAGE_ID_COPYBUFFERREGION_DSTRANGEOUTOFBOUNDS"; break;
        case D3D12_MESSAGE_ID_COPYBUFFERREGION_NULLSRC: ret = "D3D12_MESSAGE_ID_COPYBUFFERREGION_NULLSRC"; break;
        case D3D12_MESSAGE_ID_COPYBUFFERREGION_INVALIDSRCRESOURCEDIMENSION: ret = "D3D12_MESSAGE_ID_COPYBUFFERREGION_INVALIDSRCRESOURCEDIMENSION"; break;
        case D3D12_MESSAGE_ID_COPYBUFFERREGION_SRCRANGEOUTOFBOUNDS: ret = "D3D12_MESSAGE_ID_COPYBUFFERREGION_SRCRANGEOUTOFBOUNDS"; break;
        case D3D12_MESSAGE_ID_COPYBUFFERREGION_INVALIDCOPYFLAGS: ret = "D3D12_MESSAGE_ID_COPYBUFFERREGION_INVALIDCOPYFLAGS"; break;
        case D3D12_MESSAGE_ID_COPYTEXTUREREGION_NULLDST: ret = "D3D12_MESSAGE_ID_COPYTEXTUREREGION_NULLDST"; break;
        case D3D12_MESSAGE_ID_COPYTEXTUREREGION_UNRECOGNIZEDDSTTYPE: ret = "D3D12_MESSAGE_ID_COPYTEXTUREREGION_UNRECOGNIZEDDSTTYPE"; break;
        case D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTRESOURCEDIMENSION: ret = "D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTRESOURCEDIMENSION"; break;
        case D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTRESOURCE: ret = "D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTRESOURCE"; break;
        case D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTSUBRESOURCE: ret = "D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTSUBRESOURCE"; break;
        case D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTOFFSET: ret = "D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTOFFSET"; break;
        case D3D12_MESSAGE_ID_COPYTEXTUREREGION_UNRECOGNIZEDDSTFORMAT: ret = "D3D12_MESSAGE_ID_COPYTEXTUREREGION_UNRECOGNIZEDDSTFORMAT"; break;
        case D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTFORMAT: ret = "D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTFORMAT"; break;
        case D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTDIMENSIONS: ret = "D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTDIMENSIONS"; break;
        case D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTROWPITCH: ret = "D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTROWPITCH"; break;
        case D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTPLACEMENT: ret = "D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTPLACEMENT"; break;
        case D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTDSPLACEDFOOTPRINTFORMAT: ret = "D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTDSPLACEDFOOTPRINTFORMAT"; break;
        case D3D12_MESSAGE_ID_COPYTEXTUREREGION_DSTREGIONOUTOFBOUNDS: ret = "D3D12_MESSAGE_ID_COPYTEXTUREREGION_DSTREGIONOUTOFBOUNDS"; break;
        case D3D12_MESSAGE_ID_COPYTEXTUREREGION_NULLSRC: ret = "D3D12_MESSAGE_ID_COPYTEXTUREREGION_NULLSRC"; break;
        case D3D12_MESSAGE_ID_COPYTEXTUREREGION_UNRECOGNIZEDSRCTYPE: ret = "D3D12_MESSAGE_ID_COPYTEXTUREREGION_UNRECOGNIZEDSRCTYPE"; break;
        case D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCRESOURCEDIMENSION: ret = "D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCRESOURCEDIMENSION"; break;
        case D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCRESOURCE: ret = "D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCRESOURCE"; break;
        case D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCSUBRESOURCE: ret = "D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCSUBRESOURCE"; break;
        case D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCOFFSET: ret = "D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCOFFSET"; break;
        case D3D12_MESSAGE_ID_COPYTEXTUREREGION_UNRECOGNIZEDSRCFORMAT: ret = "D3D12_MESSAGE_ID_COPYTEXTUREREGION_UNRECOGNIZEDSRCFORMAT"; break;
        case D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCFORMAT: ret = "D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCFORMAT"; break;
        case D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCDIMENSIONS: ret = "D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCDIMENSIONS"; break;
        case D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCROWPITCH: ret = "D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCROWPITCH"; break;
        case D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCPLACEMENT: ret = "D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCPLACEMENT"; break;
        case D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCDSPLACEDFOOTPRINTFORMAT: ret = "D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCDSPLACEDFOOTPRINTFORMAT"; break;
        case D3D12_MESSAGE_ID_COPYTEXTUREREGION_SRCREGIONOUTOFBOUNDS: ret = "D3D12_MESSAGE_ID_COPYTEXTUREREGION_SRCREGIONOUTOFBOUNDS"; break;
        case D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTCOORDINATES: ret = "D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTCOORDINATES"; break;
        case D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCBOX: ret = "D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCBOX"; break;
        case D3D12_MESSAGE_ID_COPYTEXTUREREGION_FORMATMISMATCH: ret = "D3D12_MESSAGE_ID_COPYTEXTUREREGION_FORMATMISMATCH"; break;
        case D3D12_MESSAGE_ID_COPYTEXTUREREGION_EMPTYBOX: ret = "D3D12_MESSAGE_ID_COPYTEXTUREREGION_EMPTYBOX"; break;
        case D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDCOPYFLAGS: ret = "D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDCOPYFLAGS"; break;
        case D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_INVALID_SUBRESOURCE_INDEX: ret = "D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_INVALID_SUBRESOURCE_INDEX"; break;
        case D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_INVALID_FORMAT: ret = "D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_INVALID_FORMAT"; break;
        case D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_RESOURCE_MISMATCH: ret = "D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_RESOURCE_MISMATCH"; break;
        case D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_INVALID_SAMPLE_COUNT: ret = "D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_INVALID_SAMPLE_COUNT"; break;
        case D3D12_MESSAGE_ID_CREATECOMPUTEPIPELINESTATE_INVALID_SHADER: ret = "D3D12_MESSAGE_ID_CREATECOMPUTEPIPELINESTATE_INVALID_SHADER"; break;
        case D3D12_MESSAGE_ID_CREATECOMPUTEPIPELINESTATE_CS_ROOT_SIGNATURE_MISMATCH: ret = "D3D12_MESSAGE_ID_CREATECOMPUTEPIPELINESTATE_CS_ROOT_SIGNATURE_MISMATCH"; break;
        case D3D12_MESSAGE_ID_CREATECOMPUTEPIPELINESTATE_MISSING_ROOT_SIGNATURE: ret = "D3D12_MESSAGE_ID_CREATECOMPUTEPIPELINESTATE_MISSING_ROOT_SIGNATURE"; break;
        case D3D12_MESSAGE_ID_CREATEPIPELINESTATE_INVALIDCACHEDBLOB: ret = "D3D12_MESSAGE_ID_CREATEPIPELINESTATE_INVALIDCACHEDBLOB"; break;
        case D3D12_MESSAGE_ID_CREATEPIPELINESTATE_CACHEDBLOBADAPTERMISMATCH: ret = "D3D12_MESSAGE_ID_CREATEPIPELINESTATE_CACHEDBLOBADAPTERMISMATCH"; break;
        case D3D12_MESSAGE_ID_CREATEPIPELINESTATE_CACHEDBLOBDRIVERVERSIONMISMATCH: ret = "D3D12_MESSAGE_ID_CREATEPIPELINESTATE_CACHEDBLOBDRIVERVERSIONMISMATCH"; break;
        case D3D12_MESSAGE_ID_CREATEPIPELINESTATE_CACHEDBLOBDESCMISMATCH: ret = "D3D12_MESSAGE_ID_CREATEPIPELINESTATE_CACHEDBLOBDESCMISMATCH"; break;
        case D3D12_MESSAGE_ID_CREATEPIPELINESTATE_CACHEDBLOBIGNORED: ret = "D3D12_MESSAGE_ID_CREATEPIPELINESTATE_CACHEDBLOBIGNORED"; break;
        case D3D12_MESSAGE_ID_WRITETOSUBRESOURCE_INVALIDHEAP: ret = "D3D12_MESSAGE_ID_WRITETOSUBRESOURCE_INVALIDHEAP"; break;
        case D3D12_MESSAGE_ID_WRITETOSUBRESOURCE_INVALIDRESOURCE: ret = "D3D12_MESSAGE_ID_WRITETOSUBRESOURCE_INVALIDRESOURCE"; break;
        case D3D12_MESSAGE_ID_WRITETOSUBRESOURCE_INVALIDBOX: ret = "D3D12_MESSAGE_ID_WRITETOSUBRESOURCE_INVALIDBOX"; break;
        case D3D12_MESSAGE_ID_WRITETOSUBRESOURCE_INVALIDSUBRESOURCE: ret = "D3D12_MESSAGE_ID_WRITETOSUBRESOURCE_INVALIDSUBRESOURCE"; break;
        case D3D12_MESSAGE_ID_WRITETOSUBRESOURCE_EMPTYBOX: ret = "D3D12_MESSAGE_ID_WRITETOSUBRESOURCE_EMPTYBOX"; break;
        case D3D12_MESSAGE_ID_READFROMSUBRESOURCE_INVALIDHEAP: ret = "D3D12_MESSAGE_ID_READFROMSUBRESOURCE_INVALIDHEAP"; break;
        case D3D12_MESSAGE_ID_READFROMSUBRESOURCE_INVALIDRESOURCE: ret = "D3D12_MESSAGE_ID_READFROMSUBRESOURCE_INVALIDRESOURCE"; break;
        case D3D12_MESSAGE_ID_READFROMSUBRESOURCE_INVALIDBOX: ret = "D3D12_MESSAGE_ID_READFROMSUBRESOURCE_INVALIDBOX"; break;
        case D3D12_MESSAGE_ID_READFROMSUBRESOURCE_INVALIDSUBRESOURCE: ret = "D3D12_MESSAGE_ID_READFROMSUBRESOURCE_INVALIDSUBRESOURCE"; break;
        case D3D12_MESSAGE_ID_READFROMSUBRESOURCE_EMPTYBOX: ret = "D3D12_MESSAGE_ID_READFROMSUBRESOURCE_EMPTYBOX"; break;
        case D3D12_MESSAGE_ID_TOO_MANY_NODES_SPECIFIED: ret = "D3D12_MESSAGE_ID_TOO_MANY_NODES_SPECIFIED"; break;
        case D3D12_MESSAGE_ID_INVALID_NODE_INDEX: ret = "D3D12_MESSAGE_ID_INVALID_NODE_INDEX"; break;
        case D3D12_MESSAGE_ID_GETHEAPPROPERTIES_INVALIDRESOURCE: ret = "D3D12_MESSAGE_ID_GETHEAPPROPERTIES_INVALIDRESOURCE"; break;
        case D3D12_MESSAGE_ID_NODE_MASK_MISMATCH: ret = "D3D12_MESSAGE_ID_NODE_MASK_MISMATCH"; break;
        case D3D12_MESSAGE_ID_COMMAND_LIST_OUTOFMEMORY: ret = "D3D12_MESSAGE_ID_COMMAND_LIST_OUTOFMEMORY"; break;
        case D3D12_MESSAGE_ID_COMMAND_LIST_MULTIPLE_SWAPCHAIN_BUFFER_REFERENCES: ret = "D3D12_MESSAGE_ID_COMMAND_LIST_MULTIPLE_SWAPCHAIN_BUFFER_REFERENCES"; break;
        case D3D12_MESSAGE_ID_COMMAND_LIST_TOO_MANY_SWAPCHAIN_REFERENCES: ret = "D3D12_MESSAGE_ID_COMMAND_LIST_TOO_MANY_SWAPCHAIN_REFERENCES"; break;
        case D3D12_MESSAGE_ID_COMMAND_QUEUE_TOO_MANY_SWAPCHAIN_REFERENCES: ret = "D3D12_MESSAGE_ID_COMMAND_QUEUE_TOO_MANY_SWAPCHAIN_REFERENCES"; break;
        case D3D12_MESSAGE_ID_EXECUTECOMMANDLISTS_WRONGSWAPCHAINBUFFERREFERENCE: ret = "D3D12_MESSAGE_ID_EXECUTECOMMANDLISTS_WRONGSWAPCHAINBUFFERREFERENCE"; break;
        case D3D12_MESSAGE_ID_COMMAND_LIST_SETRENDERTARGETS_INVALIDNUMRENDERTARGETS: ret = "D3D12_MESSAGE_ID_COMMAND_LIST_SETRENDERTARGETS_INVALIDNUMRENDERTARGETS"; break;
        case D3D12_MESSAGE_ID_CREATE_QUEUE_INVALID_TYPE: ret = "D3D12_MESSAGE_ID_CREATE_QUEUE_INVALID_TYPE"; break;
        case D3D12_MESSAGE_ID_CREATE_QUEUE_INVALID_FLAGS: ret = "D3D12_MESSAGE_ID_CREATE_QUEUE_INVALID_FLAGS"; break;
        case D3D12_MESSAGE_ID_CREATESHAREDRESOURCE_INVALIDFLAGS: ret = "D3D12_MESSAGE_ID_CREATESHAREDRESOURCE_INVALIDFLAGS"; break;
        case D3D12_MESSAGE_ID_CREATESHAREDRESOURCE_INVALIDFORMAT: ret = "D3D12_MESSAGE_ID_CREATESHAREDRESOURCE_INVALIDFORMAT"; break;
        case D3D12_MESSAGE_ID_CREATESHAREDHEAP_INVALIDFLAGS: ret = "D3D12_MESSAGE_ID_CREATESHAREDHEAP_INVALIDFLAGS"; break;
        case D3D12_MESSAGE_ID_REFLECTSHAREDPROPERTIES_UNRECOGNIZEDPROPERTIES: ret = "D3D12_MESSAGE_ID_REFLECTSHAREDPROPERTIES_UNRECOGNIZEDPROPERTIES"; break;
        case D3D12_MESSAGE_ID_REFLECTSHAREDPROPERTIES_INVALIDSIZE: ret = "D3D12_MESSAGE_ID_REFLECTSHAREDPROPERTIES_INVALIDSIZE"; break;
        case D3D12_MESSAGE_ID_REFLECTSHAREDPROPERTIES_INVALIDOBJECT: ret = "D3D12_MESSAGE_ID_REFLECTSHAREDPROPERTIES_INVALIDOBJECT"; break;
        case D3D12_MESSAGE_ID_KEYEDMUTEX_INVALIDOBJECT: ret = "D3D12_MESSAGE_ID_KEYEDMUTEX_INVALIDOBJECT"; break;
        case D3D12_MESSAGE_ID_KEYEDMUTEX_INVALIDKEY: ret = "D3D12_MESSAGE_ID_KEYEDMUTEX_INVALIDKEY"; break;
        case D3D12_MESSAGE_ID_KEYEDMUTEX_WRONGSTATE: ret = "D3D12_MESSAGE_ID_KEYEDMUTEX_WRONGSTATE"; break;
        case D3D12_MESSAGE_ID_CREATE_QUEUE_INVALID_PRIORITY: ret = "D3D12_MESSAGE_ID_CREATE_QUEUE_INVALID_PRIORITY"; break;
        case D3D12_MESSAGE_ID_OBJECT_DELETED_WHILE_STILL_IN_USE: ret = "D3D12_MESSAGE_ID_OBJECT_DELETED_WHILE_STILL_IN_USE"; break;
        case D3D12_MESSAGE_ID_CREATEPIPELINESTATE_INVALID_FLAGS: ret = "D3D12_MESSAGE_ID_CREATEPIPELINESTATE_INVALID_FLAGS"; break;
        case D3D12_MESSAGE_ID_HEAP_ADDRESS_RANGE_HAS_NO_RESOURCE: ret = "D3D12_MESSAGE_ID_HEAP_ADDRESS_RANGE_HAS_NO_RESOURCE"; break;
        case D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_RENDER_TARGET_DELETED: ret = "D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_RENDER_TARGET_DELETED"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_ALL_RENDER_TARGETS_HAVE_UNKNOWN_FORMAT: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_ALL_RENDER_TARGETS_HAVE_UNKNOWN_FORMAT"; break;
        case D3D12_MESSAGE_ID_HEAP_ADDRESS_RANGE_INTERSECTS_MULTIPLE_BUFFERS: ret = "D3D12_MESSAGE_ID_HEAP_ADDRESS_RANGE_INTERSECTS_MULTIPLE_BUFFERS"; break;
        case D3D12_MESSAGE_ID_EXECUTECOMMANDLISTS_GPU_WRITTEN_READBACK_RESOURCE_MAPPED: ret = "D3D12_MESSAGE_ID_EXECUTECOMMANDLISTS_GPU_WRITTEN_READBACK_RESOURCE_MAPPED"; break;
        case D3D12_MESSAGE_ID_UNMAP_RANGE_NOT_EMPTY: ret = "D3D12_MESSAGE_ID_UNMAP_RANGE_NOT_EMPTY"; break;
        case D3D12_MESSAGE_ID_MAP_INVALID_NULLRANGE: ret = "D3D12_MESSAGE_ID_MAP_INVALID_NULLRANGE"; break;
        case D3D12_MESSAGE_ID_UNMAP_INVALID_NULLRANGE: ret = "D3D12_MESSAGE_ID_UNMAP_INVALID_NULLRANGE"; break;
        case D3D12_MESSAGE_ID_NO_GRAPHICS_API_SUPPORT: ret = "D3D12_MESSAGE_ID_NO_GRAPHICS_API_SUPPORT"; break;
        case D3D12_MESSAGE_ID_NO_COMPUTE_API_SUPPORT: ret = "D3D12_MESSAGE_ID_NO_COMPUTE_API_SUPPORT"; break;
        case D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_RESOURCE_FLAGS_NOT_SUPPORTED: ret = "D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_RESOURCE_FLAGS_NOT_SUPPORTED"; break;
        case D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_ROOT_ARGUMENT_UNINITIALIZED: ret = "D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_ROOT_ARGUMENT_UNINITIALIZED"; break;
        case D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_DESCRIPTOR_HEAP_INDEX_OUT_OF_BOUNDS: ret = "D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_DESCRIPTOR_HEAP_INDEX_OUT_OF_BOUNDS"; break;
        case D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_DESCRIPTOR_TABLE_REGISTER_INDEX_OUT_OF_BOUNDS: ret = "D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_DESCRIPTOR_TABLE_REGISTER_INDEX_OUT_OF_BOUNDS"; break;
        case D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_DESCRIPTOR_UNINITIALIZED: ret = "D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_DESCRIPTOR_UNINITIALIZED"; break;
        case D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_DESCRIPTOR_TYPE_MISMATCH: ret = "D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_DESCRIPTOR_TYPE_MISMATCH"; break;
        case D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_SRV_RESOURCE_DIMENSION_MISMATCH: ret = "D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_SRV_RESOURCE_DIMENSION_MISMATCH"; break;
        case D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_UAV_RESOURCE_DIMENSION_MISMATCH: ret = "D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_UAV_RESOURCE_DIMENSION_MISMATCH"; break;
        case D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_INCOMPATIBLE_RESOURCE_STATE: ret = "D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_INCOMPATIBLE_RESOURCE_STATE"; break;
        case D3D12_MESSAGE_ID_COPYRESOURCE_NULLDST: ret = "D3D12_MESSAGE_ID_COPYRESOURCE_NULLDST"; break;
        case D3D12_MESSAGE_ID_COPYRESOURCE_INVALIDDSTRESOURCE: ret = "D3D12_MESSAGE_ID_COPYRESOURCE_INVALIDDSTRESOURCE"; break;
        case D3D12_MESSAGE_ID_COPYRESOURCE_NULLSRC: ret = "D3D12_MESSAGE_ID_COPYRESOURCE_NULLSRC"; break;
        case D3D12_MESSAGE_ID_COPYRESOURCE_INVALIDSRCRESOURCE: ret = "D3D12_MESSAGE_ID_COPYRESOURCE_INVALIDSRCRESOURCE"; break;
        case D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_NULLDST: ret = "D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_NULLDST"; break;
        case D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_INVALIDDSTRESOURCE: ret = "D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_INVALIDDSTRESOURCE"; break;
        case D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_NULLSRC: ret = "D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_NULLSRC"; break;
        case D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_INVALIDSRCRESOURCE: ret = "D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_INVALIDSRCRESOURCE"; break;
        case D3D12_MESSAGE_ID_PIPELINE_STATE_TYPE_MISMATCH: ret = "D3D12_MESSAGE_ID_PIPELINE_STATE_TYPE_MISMATCH"; break;
        case D3D12_MESSAGE_ID_COMMAND_LIST_DISPATCH_ROOT_SIGNATURE_NOT_SET: ret = "D3D12_MESSAGE_ID_COMMAND_LIST_DISPATCH_ROOT_SIGNATURE_NOT_SET"; break;
        case D3D12_MESSAGE_ID_COMMAND_LIST_DISPATCH_ROOT_SIGNATURE_MISMATCH: ret = "D3D12_MESSAGE_ID_COMMAND_LIST_DISPATCH_ROOT_SIGNATURE_MISMATCH"; break;
        case D3D12_MESSAGE_ID_RESOURCE_BARRIER_ZERO_BARRIERS: ret = "D3D12_MESSAGE_ID_RESOURCE_BARRIER_ZERO_BARRIERS"; break;
        case D3D12_MESSAGE_ID_BEGIN_END_EVENT_MISMATCH: ret = "D3D12_MESSAGE_ID_BEGIN_END_EVENT_MISMATCH"; break;
        case D3D12_MESSAGE_ID_RESOURCE_BARRIER_POSSIBLE_BEFORE_AFTER_MISMATCH: ret = "D3D12_MESSAGE_ID_RESOURCE_BARRIER_POSSIBLE_BEFORE_AFTER_MISMATCH"; break;
        case D3D12_MESSAGE_ID_RESOURCE_BARRIER_MISMATCHING_BEGIN_END: ret = "D3D12_MESSAGE_ID_RESOURCE_BARRIER_MISMATCHING_BEGIN_END"; break;
        case D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_INVALID_RESOURCE: ret = "D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_INVALID_RESOURCE"; break;
        case D3D12_MESSAGE_ID_USE_OF_ZERO_REFCOUNT_OBJECT: ret = "D3D12_MESSAGE_ID_USE_OF_ZERO_REFCOUNT_OBJECT"; break;
        case D3D12_MESSAGE_ID_OBJECT_EVICTED_WHILE_STILL_IN_USE: ret = "D3D12_MESSAGE_ID_OBJECT_EVICTED_WHILE_STILL_IN_USE"; break;
        case D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_ROOT_DESCRIPTOR_ACCESS_OUT_OF_BOUNDS: ret = "D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_ROOT_DESCRIPTOR_ACCESS_OUT_OF_BOUNDS"; break;
        case D3D12_MESSAGE_ID_CREATEPIPELINELIBRARY_INVALIDLIBRARYBLOB: ret = "D3D12_MESSAGE_ID_CREATEPIPELINELIBRARY_INVALIDLIBRARYBLOB"; break;
        case D3D12_MESSAGE_ID_CREATEPIPELINELIBRARY_DRIVERVERSIONMISMATCH: ret = "D3D12_MESSAGE_ID_CREATEPIPELINELIBRARY_DRIVERVERSIONMISMATCH"; break;
        case D3D12_MESSAGE_ID_CREATEPIPELINELIBRARY_ADAPTERVERSIONMISMATCH: ret = "D3D12_MESSAGE_ID_CREATEPIPELINELIBRARY_ADAPTERVERSIONMISMATCH"; break;
        case D3D12_MESSAGE_ID_CREATEPIPELINELIBRARY_UNSUPPORTED: ret = "D3D12_MESSAGE_ID_CREATEPIPELINELIBRARY_UNSUPPORTED"; break;
        case D3D12_MESSAGE_ID_CREATE_PIPELINELIBRARY: ret = "D3D12_MESSAGE_ID_CREATE_PIPELINELIBRARY"; break;
        case D3D12_MESSAGE_ID_LIVE_PIPELINELIBRARY: ret = "D3D12_MESSAGE_ID_LIVE_PIPELINELIBRARY"; break;
        case D3D12_MESSAGE_ID_DESTROY_PIPELINELIBRARY: ret = "D3D12_MESSAGE_ID_DESTROY_PIPELINELIBRARY"; break;
        case D3D12_MESSAGE_ID_STOREPIPELINE_NONAME: ret = "D3D12_MESSAGE_ID_STOREPIPELINE_NONAME"; break;
        case D3D12_MESSAGE_ID_STOREPIPELINE_DUPLICATENAME: ret = "D3D12_MESSAGE_ID_STOREPIPELINE_DUPLICATENAME"; break;
        case D3D12_MESSAGE_ID_LOADPIPELINE_NAMENOTFOUND: ret = "D3D12_MESSAGE_ID_LOADPIPELINE_NAMENOTFOUND"; break;
        case D3D12_MESSAGE_ID_LOADPIPELINE_INVALIDDESC: ret = "D3D12_MESSAGE_ID_LOADPIPELINE_INVALIDDESC"; break;
        case D3D12_MESSAGE_ID_PIPELINELIBRARY_SERIALIZE_NOTENOUGHMEMORY: ret = "D3D12_MESSAGE_ID_PIPELINELIBRARY_SERIALIZE_NOTENOUGHMEMORY"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_PS_OUTPUT_RT_OUTPUT_MISMATCH: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_PS_OUTPUT_RT_OUTPUT_MISMATCH"; break;
        case D3D12_MESSAGE_ID_SETEVENTONMULTIPLEFENCECOMPLETION_INVALIDFLAGS: ret = "D3D12_MESSAGE_ID_SETEVENTONMULTIPLEFENCECOMPLETION_INVALIDFLAGS"; break;
        case D3D12_MESSAGE_ID_CREATE_QUEUE_VIDEO_NOT_SUPPORTED: ret = "D3D12_MESSAGE_ID_CREATE_QUEUE_VIDEO_NOT_SUPPORTED"; break;
        case D3D12_MESSAGE_ID_CREATE_COMMAND_ALLOCATOR_VIDEO_NOT_SUPPORTED: ret = "D3D12_MESSAGE_ID_CREATE_COMMAND_ALLOCATOR_VIDEO_NOT_SUPPORTED"; break;
        case D3D12_MESSAGE_ID_CREATEQUERY_HEAP_VIDEO_DECODE_STATISTICS_NOT_SUPPORTED: ret = "D3D12_MESSAGE_ID_CREATEQUERY_HEAP_VIDEO_DECODE_STATISTICS_NOT_SUPPORTED"; break;
        case D3D12_MESSAGE_ID_CREATE_VIDEODECODECOMMANDLIST: ret = "D3D12_MESSAGE_ID_CREATE_VIDEODECODECOMMANDLIST"; break;
        case D3D12_MESSAGE_ID_CREATE_VIDEODECODER: ret = "D3D12_MESSAGE_ID_CREATE_VIDEODECODER"; break;
        case D3D12_MESSAGE_ID_CREATE_VIDEODECODESTREAM: ret = "D3D12_MESSAGE_ID_CREATE_VIDEODECODESTREAM"; break;
        case D3D12_MESSAGE_ID_LIVE_VIDEODECODECOMMANDLIST: ret = "D3D12_MESSAGE_ID_LIVE_VIDEODECODECOMMANDLIST"; break;
        case D3D12_MESSAGE_ID_LIVE_VIDEODECODER: ret = "D3D12_MESSAGE_ID_LIVE_VIDEODECODER"; break;
        case D3D12_MESSAGE_ID_LIVE_VIDEODECODESTREAM: ret = "D3D12_MESSAGE_ID_LIVE_VIDEODECODESTREAM"; break;
        case D3D12_MESSAGE_ID_DESTROY_VIDEODECODECOMMANDLIST: ret = "D3D12_MESSAGE_ID_DESTROY_VIDEODECODECOMMANDLIST"; break;
        case D3D12_MESSAGE_ID_DESTROY_VIDEODECODER: ret = "D3D12_MESSAGE_ID_DESTROY_VIDEODECODER"; break;
        case D3D12_MESSAGE_ID_DESTROY_VIDEODECODESTREAM: ret = "D3D12_MESSAGE_ID_DESTROY_VIDEODECODESTREAM"; break;
        case D3D12_MESSAGE_ID_DECODE_FRAME_INVALID_PARAMETERS: ret = "D3D12_MESSAGE_ID_DECODE_FRAME_INVALID_PARAMETERS"; break;
        case D3D12_MESSAGE_ID_DEPRECATED_API: ret = "D3D12_MESSAGE_ID_DEPRECATED_API"; break;
        case D3D12_MESSAGE_ID_RESOURCE_BARRIER_MISMATCHING_COMMAND_LIST_TYPE: ret = "D3D12_MESSAGE_ID_RESOURCE_BARRIER_MISMATCHING_COMMAND_LIST_TYPE"; break;
        case D3D12_MESSAGE_ID_COMMAND_LIST_DESCRIPTOR_TABLE_NOT_SET: ret = "D3D12_MESSAGE_ID_COMMAND_LIST_DESCRIPTOR_TABLE_NOT_SET"; break;
        case D3D12_MESSAGE_ID_COMMAND_LIST_ROOT_CONSTANT_BUFFER_VIEW_NOT_SET: ret = "D3D12_MESSAGE_ID_COMMAND_LIST_ROOT_CONSTANT_BUFFER_VIEW_NOT_SET"; break;
        case D3D12_MESSAGE_ID_COMMAND_LIST_ROOT_SHADER_RESOURCE_VIEW_NOT_SET: ret = "D3D12_MESSAGE_ID_COMMAND_LIST_ROOT_SHADER_RESOURCE_VIEW_NOT_SET"; break;
        case D3D12_MESSAGE_ID_COMMAND_LIST_ROOT_UNORDERED_ACCESS_VIEW_NOT_SET: ret = "D3D12_MESSAGE_ID_COMMAND_LIST_ROOT_UNORDERED_ACCESS_VIEW_NOT_SET"; break;
        case D3D12_MESSAGE_ID_DISCARD_INVALID_SUBRESOURCE_RANGE: ret = "D3D12_MESSAGE_ID_DISCARD_INVALID_SUBRESOURCE_RANGE"; break;
        case D3D12_MESSAGE_ID_DISCARD_ONE_SUBRESOURCE_FOR_MIPS_WITH_RECTS: ret = "D3D12_MESSAGE_ID_DISCARD_ONE_SUBRESOURCE_FOR_MIPS_WITH_RECTS"; break;
        case D3D12_MESSAGE_ID_DISCARD_NO_RECTS_FOR_NON_TEXTURE2D: ret = "D3D12_MESSAGE_ID_DISCARD_NO_RECTS_FOR_NON_TEXTURE2D"; break;
        case D3D12_MESSAGE_ID_COPY_ON_SAME_SUBRESOURCE: ret = "D3D12_MESSAGE_ID_COPY_ON_SAME_SUBRESOURCE"; break;
        case D3D12_MESSAGE_ID_SETRESIDENCYPRIORITY_INVALID_PAGEABLE: ret = "D3D12_MESSAGE_ID_SETRESIDENCYPRIORITY_INVALID_PAGEABLE"; break;
        case D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_UNSUPPORTED: ret = "D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_UNSUPPORTED"; break;
        case D3D12_MESSAGE_ID_STATIC_DESCRIPTOR_INVALID_DESCRIPTOR_CHANGE: ret = "D3D12_MESSAGE_ID_STATIC_DESCRIPTOR_INVALID_DESCRIPTOR_CHANGE"; break;
        case D3D12_MESSAGE_ID_DATA_STATIC_DESCRIPTOR_INVALID_DATA_CHANGE: ret = "D3D12_MESSAGE_ID_DATA_STATIC_DESCRIPTOR_INVALID_DATA_CHANGE"; break;
        case D3D12_MESSAGE_ID_DATA_STATIC_WHILE_SET_AT_EXECUTE_DESCRIPTOR_INVALID_DATA_CHANGE: ret = "D3D12_MESSAGE_ID_DATA_STATIC_WHILE_SET_AT_EXECUTE_DESCRIPTOR_INVALID_DATA_CHANGE"; break;
        case D3D12_MESSAGE_ID_EXECUTE_BUNDLE_STATIC_DESCRIPTOR_DATA_STATIC_NOT_SET: ret = "D3D12_MESSAGE_ID_EXECUTE_BUNDLE_STATIC_DESCRIPTOR_DATA_STATIC_NOT_SET"; break;
        case D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_RESOURCE_ACCESS_OUT_OF_BOUNDS: ret = "D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_RESOURCE_ACCESS_OUT_OF_BOUNDS"; break;
        case D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_SAMPLER_MODE_MISMATCH: ret = "D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_SAMPLER_MODE_MISMATCH"; break;
        case D3D12_MESSAGE_ID_CREATE_FENCE_INVALID_FLAGS: ret = "D3D12_MESSAGE_ID_CREATE_FENCE_INVALID_FLAGS"; break;
        case D3D12_MESSAGE_ID_RESOURCE_BARRIER_DUPLICATE_SUBRESOURCE_TRANSITIONS: ret = "D3D12_MESSAGE_ID_RESOURCE_BARRIER_DUPLICATE_SUBRESOURCE_TRANSITIONS"; break;
        case D3D12_MESSAGE_ID_SETRESIDENCYPRIORITY_INVALID_PRIORITY: ret = "D3D12_MESSAGE_ID_SETRESIDENCYPRIORITY_INVALID_PRIORITY"; break;
        case D3D12_MESSAGE_ID_CREATE_DESCRIPTOR_HEAP_LARGE_NUM_DESCRIPTORS: ret = "D3D12_MESSAGE_ID_CREATE_DESCRIPTOR_HEAP_LARGE_NUM_DESCRIPTORS"; break;
        case D3D12_MESSAGE_ID_BEGIN_EVENT: ret = "D3D12_MESSAGE_ID_BEGIN_EVENT"; break;
        case D3D12_MESSAGE_ID_END_EVENT: ret = "D3D12_MESSAGE_ID_END_EVENT"; break;
        case D3D12_MESSAGE_ID_CREATEDEVICE_DEBUG_LAYER_STARTUP_OPTIONS: ret = "D3D12_MESSAGE_ID_CREATEDEVICE_DEBUG_LAYER_STARTUP_OPTIONS"; break;
        case D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_DEPTHBOUNDSTEST_UNSUPPORTED: ret = "D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_DEPTHBOUNDSTEST_UNSUPPORTED"; break;
        case D3D12_MESSAGE_ID_CREATEPIPELINESTATE_DUPLICATE_SUBOBJECT: ret = "D3D12_MESSAGE_ID_CREATEPIPELINESTATE_DUPLICATE_SUBOBJECT"; break;
        case D3D12_MESSAGE_ID_CREATEPIPELINESTATE_UNKNOWN_SUBOBJECT: ret = "D3D12_MESSAGE_ID_CREATEPIPELINESTATE_UNKNOWN_SUBOBJECT"; break;
        case D3D12_MESSAGE_ID_CREATEPIPELINESTATE_ZERO_SIZE_STREAM: ret = "D3D12_MESSAGE_ID_CREATEPIPELINESTATE_ZERO_SIZE_STREAM"; break;
        case D3D12_MESSAGE_ID_CREATEPIPELINESTATE_INVALID_STREAM: ret = "D3D12_MESSAGE_ID_CREATEPIPELINESTATE_INVALID_STREAM"; break;
        case D3D12_MESSAGE_ID_CREATEPIPELINESTATE_CANNOT_DEDUCE_TYPE: ret = "D3D12_MESSAGE_ID_CREATEPIPELINESTATE_CANNOT_DEDUCE_TYPE"; break;
        case D3D12_MESSAGE_ID_COMMAND_LIST_STATIC_DESCRIPTOR_RESOURCE_DIMENSION_MISMATCH: ret = "D3D12_MESSAGE_ID_COMMAND_LIST_STATIC_DESCRIPTOR_RESOURCE_DIMENSION_MISMATCH"; break;
        case D3D12_MESSAGE_ID_CREATE_COMMAND_QUEUE_INSUFFICIENT_PRIVILEGE_FOR_GLOBAL_REALTIME: ret = "D3D12_MESSAGE_ID_CREATE_COMMAND_QUEUE_INSUFFICIENT_PRIVILEGE_FOR_GLOBAL_REALTIME"; break;
        case D3D12_MESSAGE_ID_CREATE_COMMAND_QUEUE_INSUFFICIENT_HARDWARE_SUPPORT_FOR_GLOBAL_REALTIME: ret = "D3D12_MESSAGE_ID_CREATE_COMMAND_QUEUE_INSUFFICIENT_HARDWARE_SUPPORT_FOR_GLOBAL_REALTIME"; break;
        case D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_INVALID_ARCHITECTURE: ret = "D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_INVALID_ARCHITECTURE"; break;
        case D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_NULL_DST: ret = "D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_NULL_DST"; break;
        case D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_INVALID_DST_RESOURCE_DIMENSION: ret = "D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_INVALID_DST_RESOURCE_DIMENSION"; break;
        case D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_DST_RANGE_OUT_OF_BOUNDS: ret = "D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_DST_RANGE_OUT_OF_BOUNDS"; break;
        case D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_NULL_SRC: ret = "D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_NULL_SRC"; break;
        case D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_INVALID_SRC_RESOURCE_DIMENSION: ret = "D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_INVALID_SRC_RESOURCE_DIMENSION"; break;
        case D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_SRC_RANGE_OUT_OF_BOUNDS: ret = "D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_SRC_RANGE_OUT_OF_BOUNDS"; break;
        case D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_INVALID_OFFSET_ALIGNMENT: ret = "D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_INVALID_OFFSET_ALIGNMENT"; break;
        case D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_NULL_DEPENDENT_RESOURCES: ret = "D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_NULL_DEPENDENT_RESOURCES"; break;
        case D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_NULL_DEPENDENT_SUBRESOURCE_RANGES: ret = "D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_NULL_DEPENDENT_SUBRESOURCE_RANGES"; break;
        case D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_INVALID_DEPENDENT_RESOURCE: ret = "D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_INVALID_DEPENDENT_RESOURCE"; break;
        case D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_INVALID_DEPENDENT_SUBRESOURCE_RANGE: ret = "D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_INVALID_DEPENDENT_SUBRESOURCE_RANGE"; break;
        case D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_DEPENDENT_SUBRESOURCE_OUT_OF_BOUNDS: ret = "D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_DEPENDENT_SUBRESOURCE_OUT_OF_BOUNDS"; break;
        case D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_DEPENDENT_RANGE_OUT_OF_BOUNDS: ret = "D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_DEPENDENT_RANGE_OUT_OF_BOUNDS"; break;
        case D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_ZERO_DEPENDENCIES: ret = "D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_ZERO_DEPENDENCIES"; break;
        case D3D12_MESSAGE_ID_DEVICE_CREATE_SHARED_HANDLE_INVALIDARG: ret = "D3D12_MESSAGE_ID_DEVICE_CREATE_SHARED_HANDLE_INVALIDARG"; break;
        case D3D12_MESSAGE_ID_DESCRIPTOR_HANDLE_WITH_INVALID_RESOURCE: ret = "D3D12_MESSAGE_ID_DESCRIPTOR_HANDLE_WITH_INVALID_RESOURCE"; break;
        case D3D12_MESSAGE_ID_SETDEPTHBOUNDS_INVALIDARGS: ret = "D3D12_MESSAGE_ID_SETDEPTHBOUNDS_INVALIDARGS"; break;
        case D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_RESOURCE_STATE_IMPRECISE: ret = "D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_RESOURCE_STATE_IMPRECISE"; break;
        case D3D12_MESSAGE_ID_COMMAND_LIST_PIPELINE_STATE_NOT_SET: ret = "D3D12_MESSAGE_ID_COMMAND_LIST_PIPELINE_STATE_NOT_SET"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_MODEL_MISMATCH: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_MODEL_MISMATCH"; break;
        case D3D12_MESSAGE_ID_OBJECT_ACCESSED_WHILE_STILL_IN_USE: ret = "D3D12_MESSAGE_ID_OBJECT_ACCESSED_WHILE_STILL_IN_USE"; break;
        case D3D12_MESSAGE_ID_PROGRAMMABLE_MSAA_UNSUPPORTED: ret = "D3D12_MESSAGE_ID_PROGRAMMABLE_MSAA_UNSUPPORTED"; break;
        case D3D12_MESSAGE_ID_SETSAMPLEPOSITIONS_INVALIDARGS: ret = "D3D12_MESSAGE_ID_SETSAMPLEPOSITIONS_INVALIDARGS"; break;
        case D3D12_MESSAGE_ID_RESOLVESUBRESOURCEREGION_INVALID_RECT: ret = "D3D12_MESSAGE_ID_RESOLVESUBRESOURCEREGION_INVALID_RECT"; break;
        case D3D12_MESSAGE_ID_CREATE_VIDEODECODECOMMANDQUEUE: ret = "D3D12_MESSAGE_ID_CREATE_VIDEODECODECOMMANDQUEUE"; break;
        case D3D12_MESSAGE_ID_CREATE_VIDEOPROCESSCOMMANDLIST: ret = "D3D12_MESSAGE_ID_CREATE_VIDEOPROCESSCOMMANDLIST"; break;
        case D3D12_MESSAGE_ID_CREATE_VIDEOPROCESSCOMMANDQUEUE: ret = "D3D12_MESSAGE_ID_CREATE_VIDEOPROCESSCOMMANDQUEUE"; break;
        case D3D12_MESSAGE_ID_LIVE_VIDEODECODECOMMANDQUEUE: ret = "D3D12_MESSAGE_ID_LIVE_VIDEODECODECOMMANDQUEUE"; break;
        case D3D12_MESSAGE_ID_LIVE_VIDEOPROCESSCOMMANDLIST: ret = "D3D12_MESSAGE_ID_LIVE_VIDEOPROCESSCOMMANDLIST"; break;
        case D3D12_MESSAGE_ID_LIVE_VIDEOPROCESSCOMMANDQUEUE: ret = "D3D12_MESSAGE_ID_LIVE_VIDEOPROCESSCOMMANDQUEUE"; break;
        case D3D12_MESSAGE_ID_DESTROY_VIDEODECODECOMMANDQUEUE: ret = "D3D12_MESSAGE_ID_DESTROY_VIDEODECODECOMMANDQUEUE"; break;
        case D3D12_MESSAGE_ID_DESTROY_VIDEOPROCESSCOMMANDLIST: ret = "D3D12_MESSAGE_ID_DESTROY_VIDEOPROCESSCOMMANDLIST"; break;
        case D3D12_MESSAGE_ID_DESTROY_VIDEOPROCESSCOMMANDQUEUE: ret = "D3D12_MESSAGE_ID_DESTROY_VIDEOPROCESSCOMMANDQUEUE"; break;
        case D3D12_MESSAGE_ID_CREATE_VIDEOPROCESSOR: ret = "D3D12_MESSAGE_ID_CREATE_VIDEOPROCESSOR"; break;
        case D3D12_MESSAGE_ID_CREATE_VIDEOPROCESSSTREAM: ret = "D3D12_MESSAGE_ID_CREATE_VIDEOPROCESSSTREAM"; break;
        case D3D12_MESSAGE_ID_LIVE_VIDEOPROCESSOR: ret = "D3D12_MESSAGE_ID_LIVE_VIDEOPROCESSOR"; break;
        case D3D12_MESSAGE_ID_LIVE_VIDEOPROCESSSTREAM: ret = "D3D12_MESSAGE_ID_LIVE_VIDEOPROCESSSTREAM"; break;
        case D3D12_MESSAGE_ID_DESTROY_VIDEOPROCESSOR: ret = "D3D12_MESSAGE_ID_DESTROY_VIDEOPROCESSOR"; break;
        case D3D12_MESSAGE_ID_DESTROY_VIDEOPROCESSSTREAM: ret = "D3D12_MESSAGE_ID_DESTROY_VIDEOPROCESSSTREAM"; break;
        case D3D12_MESSAGE_ID_PROCESS_FRAME_INVALID_PARAMETERS: ret = "D3D12_MESSAGE_ID_PROCESS_FRAME_INVALID_PARAMETERS"; break;
        case D3D12_MESSAGE_ID_COPY_INVALIDLAYOUT: ret = "D3D12_MESSAGE_ID_COPY_INVALIDLAYOUT"; break;
        case D3D12_MESSAGE_ID_CREATE_CRYPTO_SESSION: ret = "D3D12_MESSAGE_ID_CREATE_CRYPTO_SESSION"; break;
        case D3D12_MESSAGE_ID_CREATE_CRYPTO_SESSION_POLICY: ret = "D3D12_MESSAGE_ID_CREATE_CRYPTO_SESSION_POLICY"; break;
        case D3D12_MESSAGE_ID_CREATE_PROTECTED_RESOURCE_SESSION: ret = "D3D12_MESSAGE_ID_CREATE_PROTECTED_RESOURCE_SESSION"; break;
        case D3D12_MESSAGE_ID_LIVE_CRYPTO_SESSION: ret = "D3D12_MESSAGE_ID_LIVE_CRYPTO_SESSION"; break;
        case D3D12_MESSAGE_ID_LIVE_CRYPTO_SESSION_POLICY: ret = "D3D12_MESSAGE_ID_LIVE_CRYPTO_SESSION_POLICY"; break;
        case D3D12_MESSAGE_ID_LIVE_PROTECTED_RESOURCE_SESSION: ret = "D3D12_MESSAGE_ID_LIVE_PROTECTED_RESOURCE_SESSION"; break;
        case D3D12_MESSAGE_ID_DESTROY_CRYPTO_SESSION: ret = "D3D12_MESSAGE_ID_DESTROY_CRYPTO_SESSION"; break;
        case D3D12_MESSAGE_ID_DESTROY_CRYPTO_SESSION_POLICY: ret = "D3D12_MESSAGE_ID_DESTROY_CRYPTO_SESSION_POLICY"; break;
        case D3D12_MESSAGE_ID_DESTROY_PROTECTED_RESOURCE_SESSION: ret = "D3D12_MESSAGE_ID_DESTROY_PROTECTED_RESOURCE_SESSION"; break;
        case D3D12_MESSAGE_ID_PROTECTED_RESOURCE_SESSION_UNSUPPORTED: ret = "D3D12_MESSAGE_ID_PROTECTED_RESOURCE_SESSION_UNSUPPORTED"; break;
        case D3D12_MESSAGE_ID_FENCE_INVALIDOPERATION: ret = "D3D12_MESSAGE_ID_FENCE_INVALIDOPERATION"; break;
        case D3D12_MESSAGE_ID_CREATEQUERY_HEAP_COPY_QUEUE_TIMESTAMPS_NOT_SUPPORTED: ret = "D3D12_MESSAGE_ID_CREATEQUERY_HEAP_COPY_QUEUE_TIMESTAMPS_NOT_SUPPORTED"; break;
        case D3D12_MESSAGE_ID_SAMPLEPOSITIONS_MISMATCH_DEFERRED: ret = "D3D12_MESSAGE_ID_SAMPLEPOSITIONS_MISMATCH_DEFERRED"; break;
        case D3D12_MESSAGE_ID_SAMPLEPOSITIONS_MISMATCH_RECORDTIME_ASSUMEDFROMFIRSTUSE: ret = "D3D12_MESSAGE_ID_SAMPLEPOSITIONS_MISMATCH_RECORDTIME_ASSUMEDFROMFIRSTUSE"; break;
        case D3D12_MESSAGE_ID_SAMPLEPOSITIONS_MISMATCH_RECORDTIME_ASSUMEDFROMCLEAR: ret = "D3D12_MESSAGE_ID_SAMPLEPOSITIONS_MISMATCH_RECORDTIME_ASSUMEDFROMCLEAR"; break;
        case D3D12_MESSAGE_ID_CREATE_VIDEODECODERHEAP: ret = "D3D12_MESSAGE_ID_CREATE_VIDEODECODERHEAP"; break;
        case D3D12_MESSAGE_ID_LIVE_VIDEODECODERHEAP: ret = "D3D12_MESSAGE_ID_LIVE_VIDEODECODERHEAP"; break;
        case D3D12_MESSAGE_ID_DESTROY_VIDEODECODERHEAP: ret = "D3D12_MESSAGE_ID_DESTROY_VIDEODECODERHEAP"; break;
        case D3D12_MESSAGE_ID_OPENEXISTINGHEAP_INVALIDARG_RETURN: ret = "D3D12_MESSAGE_ID_OPENEXISTINGHEAP_INVALIDARG_RETURN"; break;
        case D3D12_MESSAGE_ID_OPENEXISTINGHEAP_OUTOFMEMORY_RETURN: ret = "D3D12_MESSAGE_ID_OPENEXISTINGHEAP_OUTOFMEMORY_RETURN"; break;
        case D3D12_MESSAGE_ID_OPENEXISTINGHEAP_INVALIDADDRESS: ret = "D3D12_MESSAGE_ID_OPENEXISTINGHEAP_INVALIDADDRESS"; break;
        case D3D12_MESSAGE_ID_OPENEXISTINGHEAP_INVALIDHANDLE: ret = "D3D12_MESSAGE_ID_OPENEXISTINGHEAP_INVALIDHANDLE"; break;
        case D3D12_MESSAGE_ID_WRITEBUFFERIMMEDIATE_INVALID_DEST: ret = "D3D12_MESSAGE_ID_WRITEBUFFERIMMEDIATE_INVALID_DEST"; break;
        case D3D12_MESSAGE_ID_WRITEBUFFERIMMEDIATE_INVALID_MODE: ret = "D3D12_MESSAGE_ID_WRITEBUFFERIMMEDIATE_INVALID_MODE"; break;
        case D3D12_MESSAGE_ID_WRITEBUFFERIMMEDIATE_INVALID_ALIGNMENT: ret = "D3D12_MESSAGE_ID_WRITEBUFFERIMMEDIATE_INVALID_ALIGNMENT"; break;
        case D3D12_MESSAGE_ID_WRITEBUFFERIMMEDIATE_NOT_SUPPORTED: ret = "D3D12_MESSAGE_ID_WRITEBUFFERIMMEDIATE_NOT_SUPPORTED"; break;
        case D3D12_MESSAGE_ID_SETVIEWINSTANCEMASK_INVALIDARGS: ret = "D3D12_MESSAGE_ID_SETVIEWINSTANCEMASK_INVALIDARGS"; break;
        case D3D12_MESSAGE_ID_VIEW_INSTANCING_UNSUPPORTED: ret = "D3D12_MESSAGE_ID_VIEW_INSTANCING_UNSUPPORTED"; break;
        case D3D12_MESSAGE_ID_VIEW_INSTANCING_INVALIDARGS: ret = "D3D12_MESSAGE_ID_VIEW_INSTANCING_INVALIDARGS"; break;
        case D3D12_MESSAGE_ID_COPYTEXTUREREGION_MISMATCH_DECODE_REFERENCE_ONLY_FLAG: ret = "D3D12_MESSAGE_ID_COPYTEXTUREREGION_MISMATCH_DECODE_REFERENCE_ONLY_FLAG"; break;
        case D3D12_MESSAGE_ID_COPYRESOURCE_MISMATCH_DECODE_REFERENCE_ONLY_FLAG: ret = "D3D12_MESSAGE_ID_COPYRESOURCE_MISMATCH_DECODE_REFERENCE_ONLY_FLAG"; break;
        case D3D12_MESSAGE_ID_CREATE_VIDEO_DECODE_HEAP_CAPS_FAILURE: ret = "D3D12_MESSAGE_ID_CREATE_VIDEO_DECODE_HEAP_CAPS_FAILURE"; break;
        case D3D12_MESSAGE_ID_CREATE_VIDEO_DECODE_HEAP_CAPS_UNSUPPORTED: ret = "D3D12_MESSAGE_ID_CREATE_VIDEO_DECODE_HEAP_CAPS_UNSUPPORTED"; break;
        case D3D12_MESSAGE_ID_VIDEO_DECODE_SUPPORT_INVALID_INPUT: ret = "D3D12_MESSAGE_ID_VIDEO_DECODE_SUPPORT_INVALID_INPUT"; break;
        case D3D12_MESSAGE_ID_CREATE_VIDEO_DECODER_UNSUPPORTED: ret = "D3D12_MESSAGE_ID_CREATE_VIDEO_DECODER_UNSUPPORTED"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_METADATA_ERROR: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_METADATA_ERROR"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_VIEW_INSTANCING_VERTEX_SIZE_EXCEEDED: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_VIEW_INSTANCING_VERTEX_SIZE_EXCEEDED"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_RUNTIME_INTERNAL_ERROR: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_RUNTIME_INTERNAL_ERROR"; break;
        case D3D12_MESSAGE_ID_NO_VIDEO_API_SUPPORT: ret = "D3D12_MESSAGE_ID_NO_VIDEO_API_SUPPORT"; break;
        case D3D12_MESSAGE_ID_VIDEO_PROCESS_SUPPORT_INVALID_INPUT: ret = "D3D12_MESSAGE_ID_VIDEO_PROCESS_SUPPORT_INVALID_INPUT"; break;
        case D3D12_MESSAGE_ID_CREATE_VIDEO_PROCESSOR_CAPS_FAILURE: ret = "D3D12_MESSAGE_ID_CREATE_VIDEO_PROCESSOR_CAPS_FAILURE"; break;
        case D3D12_MESSAGE_ID_VIDEO_PROCESS_SUPPORT_UNSUPPORTED_FORMAT: ret = "D3D12_MESSAGE_ID_VIDEO_PROCESS_SUPPORT_UNSUPPORTED_FORMAT"; break;
        case D3D12_MESSAGE_ID_VIDEO_DECODE_FRAME_INVALID_ARGUMENT: ret = "D3D12_MESSAGE_ID_VIDEO_DECODE_FRAME_INVALID_ARGUMENT"; break;
        case D3D12_MESSAGE_ID_ENQUEUE_MAKE_RESIDENT_INVALID_FLAGS: ret = "D3D12_MESSAGE_ID_ENQUEUE_MAKE_RESIDENT_INVALID_FLAGS"; break;
        case D3D12_MESSAGE_ID_OPENEXISTINGHEAP_UNSUPPORTED: ret = "D3D12_MESSAGE_ID_OPENEXISTINGHEAP_UNSUPPORTED"; break;
        case D3D12_MESSAGE_ID_VIDEO_PROCESS_FRAMES_INVALID_ARGUMENT: ret = "D3D12_MESSAGE_ID_VIDEO_PROCESS_FRAMES_INVALID_ARGUMENT"; break;
        case D3D12_MESSAGE_ID_VIDEO_DECODE_SUPPORT_UNSUPPORTED: ret = "D3D12_MESSAGE_ID_VIDEO_DECODE_SUPPORT_UNSUPPORTED"; break;
        case D3D12_MESSAGE_ID_CREATE_COMMANDRECORDER: ret = "D3D12_MESSAGE_ID_CREATE_COMMANDRECORDER"; break;
        case D3D12_MESSAGE_ID_LIVE_COMMANDRECORDER: ret = "D3D12_MESSAGE_ID_LIVE_COMMANDRECORDER"; break;
        case D3D12_MESSAGE_ID_DESTROY_COMMANDRECORDER: ret = "D3D12_MESSAGE_ID_DESTROY_COMMANDRECORDER"; break;
        case D3D12_MESSAGE_ID_CREATE_COMMAND_RECORDER_VIDEO_NOT_SUPPORTED: ret = "D3D12_MESSAGE_ID_CREATE_COMMAND_RECORDER_VIDEO_NOT_SUPPORTED"; break;
        case D3D12_MESSAGE_ID_CREATE_COMMAND_RECORDER_INVALID_SUPPORT_FLAGS: ret = "D3D12_MESSAGE_ID_CREATE_COMMAND_RECORDER_INVALID_SUPPORT_FLAGS"; break;
        case D3D12_MESSAGE_ID_CREATE_COMMAND_RECORDER_INVALID_FLAGS: ret = "D3D12_MESSAGE_ID_CREATE_COMMAND_RECORDER_INVALID_FLAGS"; break;
        case D3D12_MESSAGE_ID_CREATE_COMMAND_RECORDER_MORE_RECORDERS_THAN_LOGICAL_PROCESSORS: ret = "D3D12_MESSAGE_ID_CREATE_COMMAND_RECORDER_MORE_RECORDERS_THAN_LOGICAL_PROCESSORS"; break;
        case D3D12_MESSAGE_ID_CREATE_COMMANDPOOL: ret = "D3D12_MESSAGE_ID_CREATE_COMMANDPOOL"; break;
        case D3D12_MESSAGE_ID_LIVE_COMMANDPOOL: ret = "D3D12_MESSAGE_ID_LIVE_COMMANDPOOL"; break;
        case D3D12_MESSAGE_ID_DESTROY_COMMANDPOOL: ret = "D3D12_MESSAGE_ID_DESTROY_COMMANDPOOL"; break;
        case D3D12_MESSAGE_ID_CREATE_COMMAND_POOL_INVALID_FLAGS: ret = "D3D12_MESSAGE_ID_CREATE_COMMAND_POOL_INVALID_FLAGS"; break;
        case D3D12_MESSAGE_ID_CREATE_COMMAND_LIST_VIDEO_NOT_SUPPORTED: ret = "D3D12_MESSAGE_ID_CREATE_COMMAND_LIST_VIDEO_NOT_SUPPORTED"; break;
        case D3D12_MESSAGE_ID_COMMAND_RECORDER_SUPPORT_FLAGS_MISMATCH: ret = "D3D12_MESSAGE_ID_COMMAND_RECORDER_SUPPORT_FLAGS_MISMATCH"; break;
        case D3D12_MESSAGE_ID_COMMAND_RECORDER_CONTENTION: ret = "D3D12_MESSAGE_ID_COMMAND_RECORDER_CONTENTION"; break;
        case D3D12_MESSAGE_ID_COMMAND_RECORDER_USAGE_WITH_CREATECOMMANDLIST_COMMAND_LIST: ret = "D3D12_MESSAGE_ID_COMMAND_RECORDER_USAGE_WITH_CREATECOMMANDLIST_COMMAND_LIST"; break;
        case D3D12_MESSAGE_ID_COMMAND_ALLOCATOR_USAGE_WITH_CREATECOMMANDLIST1_COMMAND_LIST: ret = "D3D12_MESSAGE_ID_COMMAND_ALLOCATOR_USAGE_WITH_CREATECOMMANDLIST1_COMMAND_LIST"; break;
        case D3D12_MESSAGE_ID_CANNOT_EXECUTE_EMPTY_COMMAND_LIST: ret = "D3D12_MESSAGE_ID_CANNOT_EXECUTE_EMPTY_COMMAND_LIST"; break;
        case D3D12_MESSAGE_ID_CANNOT_RESET_COMMAND_POOL_WITH_OPEN_COMMAND_LISTS: ret = "D3D12_MESSAGE_ID_CANNOT_RESET_COMMAND_POOL_WITH_OPEN_COMMAND_LISTS"; break;
        case D3D12_MESSAGE_ID_CANNOT_USE_COMMAND_RECORDER_WITHOUT_CURRENT_TARGET: ret = "D3D12_MESSAGE_ID_CANNOT_USE_COMMAND_RECORDER_WITHOUT_CURRENT_TARGET"; break;
        case D3D12_MESSAGE_ID_CANNOT_CHANGE_COMMAND_RECORDER_TARGET_WHILE_RECORDING: ret = "D3D12_MESSAGE_ID_CANNOT_CHANGE_COMMAND_RECORDER_TARGET_WHILE_RECORDING"; break;
        case D3D12_MESSAGE_ID_COMMAND_POOL_SYNC: ret = "D3D12_MESSAGE_ID_COMMAND_POOL_SYNC"; break;
        case D3D12_MESSAGE_ID_EVICT_UNDERFLOW: ret = "D3D12_MESSAGE_ID_EVICT_UNDERFLOW"; break;
        case D3D12_MESSAGE_ID_CREATE_META_COMMAND: ret = "D3D12_MESSAGE_ID_CREATE_META_COMMAND"; break;
        case D3D12_MESSAGE_ID_LIVE_META_COMMAND: ret = "D3D12_MESSAGE_ID_LIVE_META_COMMAND"; break;
        case D3D12_MESSAGE_ID_DESTROY_META_COMMAND: ret = "D3D12_MESSAGE_ID_DESTROY_META_COMMAND"; break;
        case D3D12_MESSAGE_ID_COPYBUFFERREGION_INVALID_DST_RESOURCE: ret = "D3D12_MESSAGE_ID_COPYBUFFERREGION_INVALID_DST_RESOURCE"; break;
        case D3D12_MESSAGE_ID_COPYBUFFERREGION_INVALID_SRC_RESOURCE: ret = "D3D12_MESSAGE_ID_COPYBUFFERREGION_INVALID_SRC_RESOURCE"; break;
        case D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_INVALID_DST_RESOURCE: ret = "D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_INVALID_DST_RESOURCE"; break;
        case D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_INVALID_SRC_RESOURCE: ret = "D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_INVALID_SRC_RESOURCE"; break;
        case D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_NULL_BUFFER: ret = "D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_NULL_BUFFER"; break;
        case D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_NULL_RESOURCE_DESC: ret = "D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_NULL_RESOURCE_DESC"; break;
        case D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_UNSUPPORTED: ret = "D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_UNSUPPORTED"; break;
        case D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_INVALID_BUFFER_DIMENSION: ret = "D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_INVALID_BUFFER_DIMENSION"; break;
        case D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_INVALID_BUFFER_FLAGS: ret = "D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_INVALID_BUFFER_FLAGS"; break;
        case D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_INVALID_BUFFER_OFFSET: ret = "D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_INVALID_BUFFER_OFFSET"; break;
        case D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_INVALID_RESOURCE_DIMENSION: ret = "D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_INVALID_RESOURCE_DIMENSION"; break;
        case D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_INVALID_RESOURCE_FLAGS: ret = "D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_INVALID_RESOURCE_FLAGS"; break;
        case D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_OUTOFMEMORY_RETURN: ret = "D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_OUTOFMEMORY_RETURN"; break;
        case D3D12_MESSAGE_ID_CANNOT_CREATE_GRAPHICS_AND_VIDEO_COMMAND_RECORDER: ret = "D3D12_MESSAGE_ID_CANNOT_CREATE_GRAPHICS_AND_VIDEO_COMMAND_RECORDER"; break;
        case D3D12_MESSAGE_ID_UPDATETILEMAPPINGS_POSSIBLY_MISMATCHING_PROPERTIES: ret = "D3D12_MESSAGE_ID_UPDATETILEMAPPINGS_POSSIBLY_MISMATCHING_PROPERTIES"; break;
        case D3D12_MESSAGE_ID_CREATE_COMMAND_LIST_INVALID_COMMAND_LIST_TYPE: ret = "D3D12_MESSAGE_ID_CREATE_COMMAND_LIST_INVALID_COMMAND_LIST_TYPE"; break;
        case D3D12_MESSAGE_ID_CLEARUNORDEREDACCESSVIEW_INCOMPATIBLE_WITH_STRUCTURED_BUFFERS: ret = "D3D12_MESSAGE_ID_CLEARUNORDEREDACCESSVIEW_INCOMPATIBLE_WITH_STRUCTURED_BUFFERS"; break;
        case D3D12_MESSAGE_ID_COMPUTE_ONLY_DEVICE_OPERATION_UNSUPPORTED: ret = "D3D12_MESSAGE_ID_COMPUTE_ONLY_DEVICE_OPERATION_UNSUPPORTED"; break;
        case D3D12_MESSAGE_ID_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INVALID: ret = "D3D12_MESSAGE_ID_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INVALID"; break;
        case D3D12_MESSAGE_ID_EMIT_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_INVALID: ret = "D3D12_MESSAGE_ID_EMIT_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_INVALID"; break;
        case D3D12_MESSAGE_ID_COPY_RAYTRACING_ACCELERATION_STRUCTURE_INVALID: ret = "D3D12_MESSAGE_ID_COPY_RAYTRACING_ACCELERATION_STRUCTURE_INVALID"; break;
        case D3D12_MESSAGE_ID_DISPATCH_RAYS_INVALID: ret = "D3D12_MESSAGE_ID_DISPATCH_RAYS_INVALID"; break;
        case D3D12_MESSAGE_ID_GET_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO_INVALID: ret = "D3D12_MESSAGE_ID_GET_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO_INVALID"; break;
        case D3D12_MESSAGE_ID_CREATE_LIFETIMETRACKER: ret = "D3D12_MESSAGE_ID_CREATE_LIFETIMETRACKER"; break;
        case D3D12_MESSAGE_ID_LIVE_LIFETIMETRACKER: ret = "D3D12_MESSAGE_ID_LIVE_LIFETIMETRACKER"; break;
        case D3D12_MESSAGE_ID_DESTROY_LIFETIMETRACKER: ret = "D3D12_MESSAGE_ID_DESTROY_LIFETIMETRACKER"; break;
        case D3D12_MESSAGE_ID_DESTROYOWNEDOBJECT_OBJECTNOTOWNED: ret = "D3D12_MESSAGE_ID_DESTROYOWNEDOBJECT_OBJECTNOTOWNED"; break;
        case D3D12_MESSAGE_ID_CREATE_TRACKEDWORKLOAD: ret = "D3D12_MESSAGE_ID_CREATE_TRACKEDWORKLOAD"; break;
        case D3D12_MESSAGE_ID_LIVE_TRACKEDWORKLOAD: ret = "D3D12_MESSAGE_ID_LIVE_TRACKEDWORKLOAD"; break;
        case D3D12_MESSAGE_ID_DESTROY_TRACKEDWORKLOAD: ret = "D3D12_MESSAGE_ID_DESTROY_TRACKEDWORKLOAD"; break;
        case D3D12_MESSAGE_ID_RENDER_PASS_ERROR: ret = "D3D12_MESSAGE_ID_RENDER_PASS_ERROR"; break;
        case D3D12_MESSAGE_ID_META_COMMAND_ID_INVALID: ret = "D3D12_MESSAGE_ID_META_COMMAND_ID_INVALID"; break;
        case D3D12_MESSAGE_ID_META_COMMAND_UNSUPPORTED_PARAMS: ret = "D3D12_MESSAGE_ID_META_COMMAND_UNSUPPORTED_PARAMS"; break;
        case D3D12_MESSAGE_ID_META_COMMAND_FAILED_ENUMERATION: ret = "D3D12_MESSAGE_ID_META_COMMAND_FAILED_ENUMERATION"; break;
        case D3D12_MESSAGE_ID_META_COMMAND_PARAMETER_SIZE_MISMATCH: ret = "D3D12_MESSAGE_ID_META_COMMAND_PARAMETER_SIZE_MISMATCH"; break;
        case D3D12_MESSAGE_ID_UNINITIALIZED_META_COMMAND: ret = "D3D12_MESSAGE_ID_UNINITIALIZED_META_COMMAND"; break;
        case D3D12_MESSAGE_ID_META_COMMAND_INVALID_GPU_VIRTUAL_ADDRESS: ret = "D3D12_MESSAGE_ID_META_COMMAND_INVALID_GPU_VIRTUAL_ADDRESS"; break;
        case D3D12_MESSAGE_ID_CREATE_VIDEOENCODECOMMANDLIST: ret = "D3D12_MESSAGE_ID_CREATE_VIDEOENCODECOMMANDLIST"; break;
        case D3D12_MESSAGE_ID_LIVE_VIDEOENCODECOMMANDLIST: ret = "D3D12_MESSAGE_ID_LIVE_VIDEOENCODECOMMANDLIST"; break;
        case D3D12_MESSAGE_ID_DESTROY_VIDEOENCODECOMMANDLIST: ret = "D3D12_MESSAGE_ID_DESTROY_VIDEOENCODECOMMANDLIST"; break;
        case D3D12_MESSAGE_ID_CREATE_VIDEOENCODECOMMANDQUEUE: ret = "D3D12_MESSAGE_ID_CREATE_VIDEOENCODECOMMANDQUEUE"; break;
        case D3D12_MESSAGE_ID_LIVE_VIDEOENCODECOMMANDQUEUE: ret = "D3D12_MESSAGE_ID_LIVE_VIDEOENCODECOMMANDQUEUE"; break;
        case D3D12_MESSAGE_ID_DESTROY_VIDEOENCODECOMMANDQUEUE: ret = "D3D12_MESSAGE_ID_DESTROY_VIDEOENCODECOMMANDQUEUE"; break;
        case D3D12_MESSAGE_ID_CREATE_VIDEOMOTIONESTIMATOR: ret = "D3D12_MESSAGE_ID_CREATE_VIDEOMOTIONESTIMATOR"; break;
        case D3D12_MESSAGE_ID_LIVE_VIDEOMOTIONESTIMATOR: ret = "D3D12_MESSAGE_ID_LIVE_VIDEOMOTIONESTIMATOR"; break;
        case D3D12_MESSAGE_ID_DESTROY_VIDEOMOTIONESTIMATOR: ret = "D3D12_MESSAGE_ID_DESTROY_VIDEOMOTIONESTIMATOR"; break;
        case D3D12_MESSAGE_ID_CREATE_VIDEOMOTIONVECTORHEAP: ret = "D3D12_MESSAGE_ID_CREATE_VIDEOMOTIONVECTORHEAP"; break;
        case D3D12_MESSAGE_ID_LIVE_VIDEOMOTIONVECTORHEAP: ret = "D3D12_MESSAGE_ID_LIVE_VIDEOMOTIONVECTORHEAP"; break;
        case D3D12_MESSAGE_ID_DESTROY_VIDEOMOTIONVECTORHEAP: ret = "D3D12_MESSAGE_ID_DESTROY_VIDEOMOTIONVECTORHEAP"; break;
        case D3D12_MESSAGE_ID_MULTIPLE_TRACKED_WORKLOADS: ret = "D3D12_MESSAGE_ID_MULTIPLE_TRACKED_WORKLOADS"; break;
        case D3D12_MESSAGE_ID_MULTIPLE_TRACKED_WORKLOAD_PAIRS: ret = "D3D12_MESSAGE_ID_MULTIPLE_TRACKED_WORKLOAD_PAIRS"; break;
        case D3D12_MESSAGE_ID_OUT_OF_ORDER_TRACKED_WORKLOAD_PAIR: ret = "D3D12_MESSAGE_ID_OUT_OF_ORDER_TRACKED_WORKLOAD_PAIR"; break;
        case D3D12_MESSAGE_ID_CANNOT_ADD_TRACKED_WORKLOAD: ret = "D3D12_MESSAGE_ID_CANNOT_ADD_TRACKED_WORKLOAD"; break;
        case D3D12_MESSAGE_ID_INCOMPLETE_TRACKED_WORKLOAD_PAIR: ret = "D3D12_MESSAGE_ID_INCOMPLETE_TRACKED_WORKLOAD_PAIR"; break;
        case D3D12_MESSAGE_ID_CREATE_STATE_OBJECT_ERROR: ret = "D3D12_MESSAGE_ID_CREATE_STATE_OBJECT_ERROR"; break;
        case D3D12_MESSAGE_ID_GET_SHADER_IDENTIFIER_ERROR: ret = "D3D12_MESSAGE_ID_GET_SHADER_IDENTIFIER_ERROR"; break;
        case D3D12_MESSAGE_ID_GET_SHADER_STACK_SIZE_ERROR: ret = "D3D12_MESSAGE_ID_GET_SHADER_STACK_SIZE_ERROR"; break;
        case D3D12_MESSAGE_ID_GET_PIPELINE_STACK_SIZE_ERROR: ret = "D3D12_MESSAGE_ID_GET_PIPELINE_STACK_SIZE_ERROR"; break;
        case D3D12_MESSAGE_ID_SET_PIPELINE_STACK_SIZE_ERROR: ret = "D3D12_MESSAGE_ID_SET_PIPELINE_STACK_SIZE_ERROR"; break;
        case D3D12_MESSAGE_ID_GET_SHADER_IDENTIFIER_SIZE_INVALID: ret = "D3D12_MESSAGE_ID_GET_SHADER_IDENTIFIER_SIZE_INVALID"; break;
        case D3D12_MESSAGE_ID_CHECK_DRIVER_MATCHING_IDENTIFIER_INVALID: ret = "D3D12_MESSAGE_ID_CHECK_DRIVER_MATCHING_IDENTIFIER_INVALID"; break;
        case D3D12_MESSAGE_ID_CHECK_DRIVER_MATCHING_IDENTIFIER_DRIVER_REPORTED_ISSUE: ret = "D3D12_MESSAGE_ID_CHECK_DRIVER_MATCHING_IDENTIFIER_DRIVER_REPORTED_ISSUE"; break;
        case D3D12_MESSAGE_ID_RENDER_PASS_INVALID_RESOURCE_BARRIER: ret = "D3D12_MESSAGE_ID_RENDER_PASS_INVALID_RESOURCE_BARRIER"; break;
        case D3D12_MESSAGE_ID_RENDER_PASS_DISALLOWED_API_CALLED: ret = "D3D12_MESSAGE_ID_RENDER_PASS_DISALLOWED_API_CALLED"; break;
        case D3D12_MESSAGE_ID_RENDER_PASS_CANNOT_NEST_RENDER_PASSES: ret = "D3D12_MESSAGE_ID_RENDER_PASS_CANNOT_NEST_RENDER_PASSES"; break;
        case D3D12_MESSAGE_ID_RENDER_PASS_CANNOT_END_WITHOUT_BEGIN: ret = "D3D12_MESSAGE_ID_RENDER_PASS_CANNOT_END_WITHOUT_BEGIN"; break;
        case D3D12_MESSAGE_ID_RENDER_PASS_CANNOT_CLOSE_COMMAND_LIST: ret = "D3D12_MESSAGE_ID_RENDER_PASS_CANNOT_CLOSE_COMMAND_LIST"; break;
        case D3D12_MESSAGE_ID_RENDER_PASS_GPU_WORK_WHILE_SUSPENDED: ret = "D3D12_MESSAGE_ID_RENDER_PASS_GPU_WORK_WHILE_SUSPENDED"; break;
        case D3D12_MESSAGE_ID_RENDER_PASS_MISMATCHING_SUSPEND_RESUME: ret = "D3D12_MESSAGE_ID_RENDER_PASS_MISMATCHING_SUSPEND_RESUME"; break;
        case D3D12_MESSAGE_ID_RENDER_PASS_NO_PRIOR_SUSPEND_WITHIN_EXECUTECOMMANDLISTS: ret = "D3D12_MESSAGE_ID_RENDER_PASS_NO_PRIOR_SUSPEND_WITHIN_EXECUTECOMMANDLISTS"; break;
        case D3D12_MESSAGE_ID_RENDER_PASS_NO_SUBSEQUENT_RESUME_WITHIN_EXECUTECOMMANDLISTS: ret = "D3D12_MESSAGE_ID_RENDER_PASS_NO_SUBSEQUENT_RESUME_WITHIN_EXECUTECOMMANDLISTS"; break;
        case D3D12_MESSAGE_ID_TRACKED_WORKLOAD_COMMAND_QUEUE_MISMATCH: ret = "D3D12_MESSAGE_ID_TRACKED_WORKLOAD_COMMAND_QUEUE_MISMATCH"; break;
        case D3D12_MESSAGE_ID_TRACKED_WORKLOAD_NOT_SUPPORTED: ret = "D3D12_MESSAGE_ID_TRACKED_WORKLOAD_NOT_SUPPORTED"; break;
        case D3D12_MESSAGE_ID_RENDER_PASS_MISMATCHING_NO_ACCESS: ret = "D3D12_MESSAGE_ID_RENDER_PASS_MISMATCHING_NO_ACCESS"; break;
        case D3D12_MESSAGE_ID_RENDER_PASS_UNSUPPORTED_RESOLVE: ret = "D3D12_MESSAGE_ID_RENDER_PASS_UNSUPPORTED_RESOLVE"; break;
        case D3D12_MESSAGE_ID_CLEARUNORDEREDACCESSVIEW_INVALID_RESOURCE_PTR: ret = "D3D12_MESSAGE_ID_CLEARUNORDEREDACCESSVIEW_INVALID_RESOURCE_PTR"; break;
        case D3D12_MESSAGE_ID_WINDOWS7_FENCE_OUTOFORDER_SIGNAL: ret = "D3D12_MESSAGE_ID_WINDOWS7_FENCE_OUTOFORDER_SIGNAL"; break;
        case D3D12_MESSAGE_ID_WINDOWS7_FENCE_OUTOFORDER_WAIT: ret = "D3D12_MESSAGE_ID_WINDOWS7_FENCE_OUTOFORDER_WAIT"; break;
        case D3D12_MESSAGE_ID_VIDEO_CREATE_MOTION_ESTIMATOR_INVALID_ARGUMENT: ret = "D3D12_MESSAGE_ID_VIDEO_CREATE_MOTION_ESTIMATOR_INVALID_ARGUMENT"; break;
        case D3D12_MESSAGE_ID_VIDEO_CREATE_MOTION_VECTOR_HEAP_INVALID_ARGUMENT: ret = "D3D12_MESSAGE_ID_VIDEO_CREATE_MOTION_VECTOR_HEAP_INVALID_ARGUMENT"; break;
        case D3D12_MESSAGE_ID_ESTIMATE_MOTION_INVALID_ARGUMENT: ret = "D3D12_MESSAGE_ID_ESTIMATE_MOTION_INVALID_ARGUMENT"; break;
        case D3D12_MESSAGE_ID_RESOLVE_MOTION_VECTOR_HEAP_INVALID_ARGUMENT: ret = "D3D12_MESSAGE_ID_RESOLVE_MOTION_VECTOR_HEAP_INVALID_ARGUMENT"; break;
        case D3D12_MESSAGE_ID_GETGPUVIRTUALADDRESS_INVALID_HEAP_TYPE: ret = "D3D12_MESSAGE_ID_GETGPUVIRTUALADDRESS_INVALID_HEAP_TYPE"; break;
        case D3D12_MESSAGE_ID_SET_BACKGROUND_PROCESSING_MODE_INVALID_ARGUMENT: ret = "D3D12_MESSAGE_ID_SET_BACKGROUND_PROCESSING_MODE_INVALID_ARGUMENT"; break;
        case D3D12_MESSAGE_ID_CREATE_COMMAND_LIST_INVALID_COMMAND_LIST_TYPE_FOR_FEATURE_LEVEL: ret = "D3D12_MESSAGE_ID_CREATE_COMMAND_LIST_INVALID_COMMAND_LIST_TYPE_FOR_FEATURE_LEVEL"; break;
        case D3D12_MESSAGE_ID_CREATE_VIDEOEXTENSIONCOMMAND: ret = "D3D12_MESSAGE_ID_CREATE_VIDEOEXTENSIONCOMMAND"; break;
        case D3D12_MESSAGE_ID_LIVE_VIDEOEXTENSIONCOMMAND: ret = "D3D12_MESSAGE_ID_LIVE_VIDEOEXTENSIONCOMMAND"; break;
        case D3D12_MESSAGE_ID_DESTROY_VIDEOEXTENSIONCOMMAND: ret = "D3D12_MESSAGE_ID_DESTROY_VIDEOEXTENSIONCOMMAND"; break;
        case D3D12_MESSAGE_ID_INVALID_VIDEO_EXTENSION_COMMAND_ID: ret = "D3D12_MESSAGE_ID_INVALID_VIDEO_EXTENSION_COMMAND_ID"; break;
        case D3D12_MESSAGE_ID_VIDEO_EXTENSION_COMMAND_INVALID_ARGUMENT: ret = "D3D12_MESSAGE_ID_VIDEO_EXTENSION_COMMAND_INVALID_ARGUMENT"; break;
        case D3D12_MESSAGE_ID_CREATE_ROOT_SIGNATURE_NOT_UNIQUE_IN_DXIL_LIBRARY: ret = "D3D12_MESSAGE_ID_CREATE_ROOT_SIGNATURE_NOT_UNIQUE_IN_DXIL_LIBRARY"; break;
        case D3D12_MESSAGE_ID_VARIABLE_SHADING_RATE_NOT_ALLOWED_WITH_TIR: ret = "D3D12_MESSAGE_ID_VARIABLE_SHADING_RATE_NOT_ALLOWED_WITH_TIR"; break;
        case D3D12_MESSAGE_ID_GEOMETRY_SHADER_OUTPUTTING_BOTH_VIEWPORT_ARRAY_INDEX_AND_SHADING_RATE_NOT_SUPPORTED_ON_DEVICE: ret = "D3D12_MESSAGE_ID_GEOMETRY_SHADER_OUTPUTTING_BOTH_VIEWPORT_ARRAY_INDEX_AND_SHADING_RATE_NOT_SUPPORTED_ON_DEVICE"; break;
        case D3D12_MESSAGE_ID_RSSETSHADING_RATE_INVALID_SHADING_RATE: ret = "D3D12_MESSAGE_ID_RSSETSHADING_RATE_INVALID_SHADING_RATE"; break;
        case D3D12_MESSAGE_ID_RSSETSHADING_RATE_SHADING_RATE_NOT_PERMITTED_BY_CAP: ret = "D3D12_MESSAGE_ID_RSSETSHADING_RATE_SHADING_RATE_NOT_PERMITTED_BY_CAP"; break;
        case D3D12_MESSAGE_ID_RSSETSHADING_RATE_INVALID_COMBINER: ret = "D3D12_MESSAGE_ID_RSSETSHADING_RATE_INVALID_COMBINER"; break;
        case D3D12_MESSAGE_ID_RSSETSHADINGRATEIMAGE_REQUIRES_TIER_2: ret = "D3D12_MESSAGE_ID_RSSETSHADINGRATEIMAGE_REQUIRES_TIER_2"; break;
        case D3D12_MESSAGE_ID_RSSETSHADINGRATE_REQUIRES_TIER_1: ret = "D3D12_MESSAGE_ID_RSSETSHADINGRATE_REQUIRES_TIER_1"; break;
        case D3D12_MESSAGE_ID_SHADING_RATE_IMAGE_INCORRECT_FORMAT: ret = "D3D12_MESSAGE_ID_SHADING_RATE_IMAGE_INCORRECT_FORMAT"; break;
        case D3D12_MESSAGE_ID_SHADING_RATE_IMAGE_INCORRECT_ARRAY_SIZE: ret = "D3D12_MESSAGE_ID_SHADING_RATE_IMAGE_INCORRECT_ARRAY_SIZE"; break;
        case D3D12_MESSAGE_ID_SHADING_RATE_IMAGE_INCORRECT_MIP_LEVEL: ret = "D3D12_MESSAGE_ID_SHADING_RATE_IMAGE_INCORRECT_MIP_LEVEL"; break;
        case D3D12_MESSAGE_ID_SHADING_RATE_IMAGE_INCORRECT_SAMPLE_COUNT: ret = "D3D12_MESSAGE_ID_SHADING_RATE_IMAGE_INCORRECT_SAMPLE_COUNT"; break;
        case D3D12_MESSAGE_ID_SHADING_RATE_IMAGE_INCORRECT_SAMPLE_QUALITY: ret = "D3D12_MESSAGE_ID_SHADING_RATE_IMAGE_INCORRECT_SAMPLE_QUALITY"; break;
        case D3D12_MESSAGE_ID_NON_RETAIL_SHADER_MODEL_WONT_VALIDATE: ret = "D3D12_MESSAGE_ID_NON_RETAIL_SHADER_MODEL_WONT_VALIDATE"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_AS_ROOT_SIGNATURE_MISMATCH: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_AS_ROOT_SIGNATURE_MISMATCH"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_MS_ROOT_SIGNATURE_MISMATCH: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_MS_ROOT_SIGNATURE_MISMATCH"; break;
        case D3D12_MESSAGE_ID_ADD_TO_STATE_OBJECT_ERROR: ret = "D3D12_MESSAGE_ID_ADD_TO_STATE_OBJECT_ERROR"; break;
        case D3D12_MESSAGE_ID_CREATE_PROTECTED_RESOURCE_SESSION_INVALID_ARGUMENT: ret = "D3D12_MESSAGE_ID_CREATE_PROTECTED_RESOURCE_SESSION_INVALID_ARGUMENT"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_MS_PSO_DESC_MISMATCH: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_MS_PSO_DESC_MISMATCH"; break;
        case D3D12_MESSAGE_ID_CREATEPIPELINESTATE_MS_INCOMPLETE_TYPE: ret = "D3D12_MESSAGE_ID_CREATEPIPELINESTATE_MS_INCOMPLETE_TYPE"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_AS_NOT_MS_MISMATCH: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_AS_NOT_MS_MISMATCH"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_MS_NOT_PS_MISMATCH: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_MS_NOT_PS_MISMATCH"; break;
        case D3D12_MESSAGE_ID_NONZERO_SAMPLER_FEEDBACK_MIP_REGION_WITH_INCOMPATIBLE_FORMAT: ret = "D3D12_MESSAGE_ID_NONZERO_SAMPLER_FEEDBACK_MIP_REGION_WITH_INCOMPATIBLE_FORMAT"; break;
        case D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INPUTLAYOUT_SHADER_MISMATCH: ret = "D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INPUTLAYOUT_SHADER_MISMATCH"; break;
        case D3D12_MESSAGE_ID_EMPTY_DISPATCH: ret = "D3D12_MESSAGE_ID_EMPTY_DISPATCH"; break;
        case D3D12_MESSAGE_ID_RESOURCE_FORMAT_REQUIRES_SAMPLER_FEEDBACK_CAPABILITY: ret = "D3D12_MESSAGE_ID_RESOURCE_FORMAT_REQUIRES_SAMPLER_FEEDBACK_CAPABILITY"; break;
        case D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_MAP_INVALID_MIP_REGION: ret = "D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_MAP_INVALID_MIP_REGION"; break;
        case D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_MAP_INVALID_DIMENSION: ret = "D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_MAP_INVALID_DIMENSION"; break;
        case D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_MAP_INVALID_SAMPLE_COUNT: ret = "D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_MAP_INVALID_SAMPLE_COUNT"; break;
        case D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_MAP_INVALID_SAMPLE_QUALITY: ret = "D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_MAP_INVALID_SAMPLE_QUALITY"; break;
        case D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_MAP_INVALID_LAYOUT: ret = "D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_MAP_INVALID_LAYOUT"; break;
        case D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_MAP_REQUIRES_UNORDERED_ACCESS_FLAG: ret = "D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_MAP_REQUIRES_UNORDERED_ACCESS_FLAG"; break;
        case D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_CREATE_UAV_NULL_ARGUMENTS: ret = "D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_CREATE_UAV_NULL_ARGUMENTS"; break;
        case D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_UAV_REQUIRES_SAMPLER_FEEDBACK_CAPABILITY: ret = "D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_UAV_REQUIRES_SAMPLER_FEEDBACK_CAPABILITY"; break;
        case D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_CREATE_UAV_REQUIRES_FEEDBACK_MAP_FORMAT: ret = "D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_CREATE_UAV_REQUIRES_FEEDBACK_MAP_FORMAT"; break;
        case D3D12_MESSAGE_ID_CREATEMESHSHADER_INVALIDSHADERBYTECODE: ret = "D3D12_MESSAGE_ID_CREATEMESHSHADER_INVALIDSHADERBYTECODE"; break;
        case D3D12_MESSAGE_ID_CREATEMESHSHADER_OUTOFMEMORY: ret = "D3D12_MESSAGE_ID_CREATEMESHSHADER_OUTOFMEMORY"; break;
        case D3D12_MESSAGE_ID_CREATEMESHSHADERWITHSTREAMOUTPUT_INVALIDSHADERTYPE: ret = "D3D12_MESSAGE_ID_CREATEMESHSHADERWITHSTREAMOUTPUT_INVALIDSHADERTYPE"; break;
        case D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_SAMPLER_FEEDBACK_TRANSCODE_INVALID_FORMAT: ret = "D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_SAMPLER_FEEDBACK_TRANSCODE_INVALID_FORMAT"; break;
        case D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_SAMPLER_FEEDBACK_INVALID_MIP_LEVEL_COUNT: ret = "D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_SAMPLER_FEEDBACK_INVALID_MIP_LEVEL_COUNT"; break;
        case D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_SAMPLER_FEEDBACK_TRANSCODE_ARRAY_SIZE_MISMATCH: ret = "D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_SAMPLER_FEEDBACK_TRANSCODE_ARRAY_SIZE_MISMATCH"; break;
        case D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_CREATE_UAV_MISMATCHING_TARGETED_RESOURCE: ret = "D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_CREATE_UAV_MISMATCHING_TARGETED_RESOURCE"; break;
        case D3D12_MESSAGE_ID_CREATEMESHSHADER_OUTPUTEXCEEDSMAXSIZE: ret = "D3D12_MESSAGE_ID_CREATEMESHSHADER_OUTPUTEXCEEDSMAXSIZE"; break;
        case D3D12_MESSAGE_ID_CREATEMESHSHADER_GROUPSHAREDEXCEEDSMAXSIZE: ret = "D3D12_MESSAGE_ID_CREATEMESHSHADER_GROUPSHAREDEXCEEDSMAXSIZE"; break;
        case D3D12_MESSAGE_ID_VERTEX_SHADER_OUTPUTTING_BOTH_VIEWPORT_ARRAY_INDEX_AND_SHADING_RATE_NOT_SUPPORTED_ON_DEVICE: ret = "D3D12_MESSAGE_ID_VERTEX_SHADER_OUTPUTTING_BOTH_VIEWPORT_ARRAY_INDEX_AND_SHADING_RATE_NOT_SUPPORTED_ON_DEVICE"; break;
        case D3D12_MESSAGE_ID_MESH_SHADER_OUTPUTTING_BOTH_VIEWPORT_ARRAY_INDEX_AND_SHADING_RATE_NOT_SUPPORTED_ON_DEVICE: ret = "D3D12_MESSAGE_ID_MESH_SHADER_OUTPUTTING_BOTH_VIEWPORT_ARRAY_INDEX_AND_SHADING_RATE_NOT_SUPPORTED_ON_DEVICE"; break;
        case D3D12_MESSAGE_ID_CREATEMESHSHADER_MISMATCHEDASMSPAYLOADSIZE: ret = "D3D12_MESSAGE_ID_CREATEMESHSHADER_MISMATCHEDASMSPAYLOADSIZE"; break;
        case D3D12_MESSAGE_ID_CREATE_ROOT_SIGNATURE_UNBOUNDED_STATIC_DESCRIPTORS: ret = "D3D12_MESSAGE_ID_CREATE_ROOT_SIGNATURE_UNBOUNDED_STATIC_DESCRIPTORS"; break;
        case D3D12_MESSAGE_ID_CREATEAMPLIFICATIONSHADER_INVALIDSHADERBYTECODE: ret = "D3D12_MESSAGE_ID_CREATEAMPLIFICATIONSHADER_INVALIDSHADERBYTECODE"; break;
        case D3D12_MESSAGE_ID_CREATEAMPLIFICATIONSHADER_OUTOFMEMORY: ret = "D3D12_MESSAGE_ID_CREATEAMPLIFICATIONSHADER_OUTOFMEMORY"; break;
        case D3D12_MESSAGE_ID_CREATE_SHADERCACHESESSION: ret = "D3D12_MESSAGE_ID_CREATE_SHADERCACHESESSION"; break;
        case D3D12_MESSAGE_ID_LIVE_SHADERCACHESESSION: ret = "D3D12_MESSAGE_ID_LIVE_SHADERCACHESESSION"; break;
        case D3D12_MESSAGE_ID_DESTROY_SHADERCACHESESSION: ret = "D3D12_MESSAGE_ID_DESTROY_SHADERCACHESESSION"; break;
        case D3D12_MESSAGE_ID_CREATESHADERCACHESESSION_INVALIDARGS: ret = "D3D12_MESSAGE_ID_CREATESHADERCACHESESSION_INVALIDARGS"; break;
        case D3D12_MESSAGE_ID_CREATESHADERCACHESESSION_DISABLED: ret = "D3D12_MESSAGE_ID_CREATESHADERCACHESESSION_DISABLED"; break;
        case D3D12_MESSAGE_ID_CREATESHADERCACHESESSION_ALREADYOPEN: ret = "D3D12_MESSAGE_ID_CREATESHADERCACHESESSION_ALREADYOPEN"; break;
        case D3D12_MESSAGE_ID_SHADERCACHECONTROL_DEVELOPERMODE: ret = "D3D12_MESSAGE_ID_SHADERCACHECONTROL_DEVELOPERMODE"; break;
        case D3D12_MESSAGE_ID_SHADERCACHECONTROL_INVALIDFLAGS: ret = "D3D12_MESSAGE_ID_SHADERCACHECONTROL_INVALIDFLAGS"; break;
        case D3D12_MESSAGE_ID_SHADERCACHECONTROL_STATEALREADYSET: ret = "D3D12_MESSAGE_ID_SHADERCACHECONTROL_STATEALREADYSET"; break;
        case D3D12_MESSAGE_ID_SHADERCACHECONTROL_IGNOREDFLAG: ret = "D3D12_MESSAGE_ID_SHADERCACHECONTROL_IGNOREDFLAG"; break;
        case D3D12_MESSAGE_ID_SHADERCACHESESSION_STOREVALUE_ALREADYPRESENT: ret = "D3D12_MESSAGE_ID_SHADERCACHESESSION_STOREVALUE_ALREADYPRESENT"; break;
        case D3D12_MESSAGE_ID_SHADERCACHESESSION_STOREVALUE_HASHCOLLISION: ret = "D3D12_MESSAGE_ID_SHADERCACHESESSION_STOREVALUE_HASHCOLLISION"; break;
        case D3D12_MESSAGE_ID_SHADERCACHESESSION_STOREVALUE_CACHEFULL: ret = "D3D12_MESSAGE_ID_SHADERCACHESESSION_STOREVALUE_CACHEFULL"; break;
        case D3D12_MESSAGE_ID_SHADERCACHESESSION_FINDVALUE_NOTFOUND: ret = "D3D12_MESSAGE_ID_SHADERCACHESESSION_FINDVALUE_NOTFOUND"; break;
        case D3D12_MESSAGE_ID_SHADERCACHESESSION_CORRUPT: ret = "D3D12_MESSAGE_ID_SHADERCACHESESSION_CORRUPT"; break;
        case D3D12_MESSAGE_ID_SHADERCACHESESSION_DISABLED: ret = "D3D12_MESSAGE_ID_SHADERCACHESESSION_DISABLED"; break;
        case D3D12_MESSAGE_ID_OVERSIZED_DISPATCH: ret = "D3D12_MESSAGE_ID_OVERSIZED_DISPATCH"; break;
        case D3D12_MESSAGE_ID_CREATE_VIDEOENCODER: ret = "D3D12_MESSAGE_ID_CREATE_VIDEOENCODER"; break;
        case D3D12_MESSAGE_ID_LIVE_VIDEOENCODER: ret = "D3D12_MESSAGE_ID_LIVE_VIDEOENCODER"; break;
        case D3D12_MESSAGE_ID_DESTROY_VIDEOENCODER: ret = "D3D12_MESSAGE_ID_DESTROY_VIDEOENCODER"; break;
        case D3D12_MESSAGE_ID_CREATE_VIDEOENCODERHEAP: ret = "D3D12_MESSAGE_ID_CREATE_VIDEOENCODERHEAP"; break;
        case D3D12_MESSAGE_ID_LIVE_VIDEOENCODERHEAP: ret = "D3D12_MESSAGE_ID_LIVE_VIDEOENCODERHEAP"; break;
        case D3D12_MESSAGE_ID_DESTROY_VIDEOENCODERHEAP: ret = "D3D12_MESSAGE_ID_DESTROY_VIDEOENCODERHEAP"; break;
        case D3D12_MESSAGE_ID_COPYTEXTUREREGION_MISMATCH_ENCODE_REFERENCE_ONLY_FLAG: ret = "D3D12_MESSAGE_ID_COPYTEXTUREREGION_MISMATCH_ENCODE_REFERENCE_ONLY_FLAG"; break;
        case D3D12_MESSAGE_ID_COPYRESOURCE_MISMATCH_ENCODE_REFERENCE_ONLY_FLAG: ret = "D3D12_MESSAGE_ID_COPYRESOURCE_MISMATCH_ENCODE_REFERENCE_ONLY_FLAG"; break;
        case D3D12_MESSAGE_ID_ENCODE_FRAME_INVALID_PARAMETERS: ret = "D3D12_MESSAGE_ID_ENCODE_FRAME_INVALID_PARAMETERS"; break;
        case D3D12_MESSAGE_ID_ENCODE_FRAME_UNSUPPORTED_PARAMETERS: ret = "D3D12_MESSAGE_ID_ENCODE_FRAME_UNSUPPORTED_PARAMETERS"; break;
        case D3D12_MESSAGE_ID_RESOLVE_ENCODER_OUTPUT_METADATA_INVALID_PARAMETERS: ret = "D3D12_MESSAGE_ID_RESOLVE_ENCODER_OUTPUT_METADATA_INVALID_PARAMETERS"; break;
        case D3D12_MESSAGE_ID_RESOLVE_ENCODER_OUTPUT_METADATA_UNSUPPORTED_PARAMETERS: ret = "D3D12_MESSAGE_ID_RESOLVE_ENCODER_OUTPUT_METADATA_UNSUPPORTED_PARAMETERS"; break;
        case D3D12_MESSAGE_ID_CREATE_VIDEO_ENCODER_INVALID_PARAMETERS: ret = "D3D12_MESSAGE_ID_CREATE_VIDEO_ENCODER_INVALID_PARAMETERS"; break;
        case D3D12_MESSAGE_ID_CREATE_VIDEO_ENCODER_UNSUPPORTED_PARAMETERS: ret = "D3D12_MESSAGE_ID_CREATE_VIDEO_ENCODER_UNSUPPORTED_PARAMETERS"; break;
        case D3D12_MESSAGE_ID_CREATE_VIDEO_ENCODER_HEAP_INVALID_PARAMETERS: ret = "D3D12_MESSAGE_ID_CREATE_VIDEO_ENCODER_HEAP_INVALID_PARAMETERS"; break;
        case D3D12_MESSAGE_ID_CREATE_VIDEO_ENCODER_HEAP_UNSUPPORTED_PARAMETERS: ret = "D3D12_MESSAGE_ID_CREATE_VIDEO_ENCODER_HEAP_UNSUPPORTED_PARAMETERS"; break;
        case D3D12_MESSAGE_ID_CREATECOMMANDLIST_NULL_COMMANDALLOCATOR: ret = "D3D12_MESSAGE_ID_CREATECOMMANDLIST_NULL_COMMANDALLOCATOR"; break;
        case D3D12_MESSAGE_ID_CLEAR_UNORDERED_ACCESS_VIEW_INVALID_DESCRIPTOR_HANDLE: ret = "D3D12_MESSAGE_ID_CLEAR_UNORDERED_ACCESS_VIEW_INVALID_DESCRIPTOR_HANDLE"; break;
        case D3D12_MESSAGE_ID_DESCRIPTOR_HEAP_NOT_SHADER_VISIBLE: ret = "D3D12_MESSAGE_ID_DESCRIPTOR_HEAP_NOT_SHADER_VISIBLE"; break;
        case D3D12_MESSAGE_ID_CREATEBLENDSTATE_BLENDOP_WARNING: ret = "D3D12_MESSAGE_ID_CREATEBLENDSTATE_BLENDOP_WARNING"; break;
        case D3D12_MESSAGE_ID_CREATEBLENDSTATE_BLENDOPALPHA_WARNING: ret = "D3D12_MESSAGE_ID_CREATEBLENDSTATE_BLENDOPALPHA_WARNING"; break;
        case D3D12_MESSAGE_ID_WRITE_COMBINE_PERFORMANCE_WARNING: ret = "D3D12_MESSAGE_ID_WRITE_COMBINE_PERFORMANCE_WARNING"; break;
        case D3D12_MESSAGE_ID_RESOLVE_QUERY_INVALID_QUERY_STATE: ret = "D3D12_MESSAGE_ID_RESOLVE_QUERY_INVALID_QUERY_STATE"; break;
        case D3D12_MESSAGE_ID_SETPRIVATEDATA_NO_ACCESS: ret = "D3D12_MESSAGE_ID_SETPRIVATEDATA_NO_ACCESS"; break;
        case D3D12_MESSAGE_ID_COMMAND_LIST_STATIC_DESCRIPTOR_SAMPLER_MODE_MISMATCH: ret = "D3D12_MESSAGE_ID_COMMAND_LIST_STATIC_DESCRIPTOR_SAMPLER_MODE_MISMATCH"; break;
        case D3D12_MESSAGE_ID_GETCOPYABLEFOOTPRINTS_UNSUPPORTED_BUFFER_WIDTH: ret = "D3D12_MESSAGE_ID_GETCOPYABLEFOOTPRINTS_UNSUPPORTED_BUFFER_WIDTH"; break;
        case D3D12_MESSAGE_ID_CREATEMESHSHADER_TOPOLOGY_MISMATCH: ret = "D3D12_MESSAGE_ID_CREATEMESHSHADER_TOPOLOGY_MISMATCH"; break;
        case D3D12_MESSAGE_ID_VRS_SUM_COMBINER_REQUIRES_CAPABILITY: ret = "D3D12_MESSAGE_ID_VRS_SUM_COMBINER_REQUIRES_CAPABILITY"; break;
        case D3D12_MESSAGE_ID_SETTING_SHADING_RATE_FROM_MS_REQUIRES_CAPABILITY: ret = "D3D12_MESSAGE_ID_SETTING_SHADING_RATE_FROM_MS_REQUIRES_CAPABILITY"; break;
        case D3D12_MESSAGE_ID_SHADERCACHESESSION_SHADERCACHEDELETE_NOTSUPPORTED: ret = "D3D12_MESSAGE_ID_SHADERCACHESESSION_SHADERCACHEDELETE_NOTSUPPORTED"; break;
        case D3D12_MESSAGE_ID_SHADERCACHECONTROL_SHADERCACHECLEAR_NOTSUPPORTED: ret = "D3D12_MESSAGE_ID_SHADERCACHECONTROL_SHADERCACHECLEAR_NOTSUPPORTED"; break;
        case D3D12_MESSAGE_ID_CREATERESOURCE_STATE_IGNORED: ret = "D3D12_MESSAGE_ID_CREATERESOURCE_STATE_IGNORED"; break;
        case D3D12_MESSAGE_ID_UNUSED_CROSS_EXECUTE_SPLIT_BARRIER: ret = "D3D12_MESSAGE_ID_UNUSED_CROSS_EXECUTE_SPLIT_BARRIER"; break;
        case D3D12_MESSAGE_ID_DEVICE_OPEN_SHARED_HANDLE_ACCESS_DENIED: ret = "D3D12_MESSAGE_ID_DEVICE_OPEN_SHARED_HANDLE_ACCESS_DENIED"; break;
        case D3D12_MESSAGE_ID_INCOMPATIBLE_BARRIER_VALUES: ret = "D3D12_MESSAGE_ID_INCOMPATIBLE_BARRIER_VALUES"; break;
        case D3D12_MESSAGE_ID_INCOMPATIBLE_BARRIER_ACCESS: ret = "D3D12_MESSAGE_ID_INCOMPATIBLE_BARRIER_ACCESS"; break;
        case D3D12_MESSAGE_ID_INCOMPATIBLE_BARRIER_SYNC: ret = "D3D12_MESSAGE_ID_INCOMPATIBLE_BARRIER_SYNC"; break;
        case D3D12_MESSAGE_ID_INCOMPATIBLE_BARRIER_LAYOUT: ret = "D3D12_MESSAGE_ID_INCOMPATIBLE_BARRIER_LAYOUT"; break;
        case D3D12_MESSAGE_ID_INCOMPATIBLE_BARRIER_TYPE: ret = "D3D12_MESSAGE_ID_INCOMPATIBLE_BARRIER_TYPE"; break;
        case D3D12_MESSAGE_ID_OUT_OF_BOUNDS_BARRIER_SUBRESOURCE_RANGE: ret = "D3D12_MESSAGE_ID_OUT_OF_BOUNDS_BARRIER_SUBRESOURCE_RANGE"; break;
        case D3D12_MESSAGE_ID_INCOMPATIBLE_BARRIER_RESOURCE_DIMENSION: ret = "D3D12_MESSAGE_ID_INCOMPATIBLE_BARRIER_RESOURCE_DIMENSION"; break;
        case D3D12_MESSAGE_ID_SET_SCISSOR_RECTS_INVALID_RECT: ret = "D3D12_MESSAGE_ID_SET_SCISSOR_RECTS_INVALID_RECT"; break;
        case D3D12_MESSAGE_ID_SHADING_RATE_SOURCE_REQUIRES_DIMENSION_TEXTURE2D: ret = "D3D12_MESSAGE_ID_SHADING_RATE_SOURCE_REQUIRES_DIMENSION_TEXTURE2D"; break;
        case D3D12_MESSAGE_ID_BUFFER_BARRIER_SUBREGION_OUT_OF_BOUNDS: ret = "D3D12_MESSAGE_ID_BUFFER_BARRIER_SUBREGION_OUT_OF_BOUNDS"; break;
        case D3D12_MESSAGE_ID_UNSUPPORTED_BARRIER_LAYOUT: ret = "D3D12_MESSAGE_ID_UNSUPPORTED_BARRIER_LAYOUT"; break;
        case D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_INVALID_PARAMETERS: ret = "D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_INVALID_PARAMETERS"; break;
        case D3D12_MESSAGE_ID_ENHANCED_BARRIERS_NOT_SUPPORTED: ret = "D3D12_MESSAGE_ID_ENHANCED_BARRIERS_NOT_SUPPORTED"; break;
        case D3D12_MESSAGE_ID_LEGACY_BARRIER_VALIDATION_FORCED_ON: ret = "D3D12_MESSAGE_ID_LEGACY_BARRIER_VALIDATION_FORCED_ON"; break;
        case D3D12_MESSAGE_ID_EMPTY_ROOT_DESCRIPTOR_TABLE: ret = "D3D12_MESSAGE_ID_EMPTY_ROOT_DESCRIPTOR_TABLE"; break;
        case D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_ELEMENT_OFFSET_UNALIGNED: ret = "D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_ELEMENT_OFFSET_UNALIGNED"; break;
        case D3D12_MESSAGE_ID_ALPHA_BLEND_FACTOR_NOT_SUPPORTED: ret = "D3D12_MESSAGE_ID_ALPHA_BLEND_FACTOR_NOT_SUPPORTED"; break;
        case D3D12_MESSAGE_ID_BARRIER_INTEROP_INVALID_LAYOUT: ret = "D3D12_MESSAGE_ID_BARRIER_INTEROP_INVALID_LAYOUT"; break;
        case D3D12_MESSAGE_ID_BARRIER_INTEROP_INVALID_STATE: ret = "D3D12_MESSAGE_ID_BARRIER_INTEROP_INVALID_STATE"; break;
        case D3D12_MESSAGE_ID_GRAPHICS_PIPELINE_STATE_DESC_ZERO_SAMPLE_MASK: ret = "D3D12_MESSAGE_ID_GRAPHICS_PIPELINE_STATE_DESC_ZERO_SAMPLE_MASK"; break;
        case D3D12_MESSAGE_ID_INDEPENDENT_STENCIL_REF_NOT_SUPPORTED: ret = "D3D12_MESSAGE_ID_INDEPENDENT_STENCIL_REF_NOT_SUPPORTED"; break;
        case D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INDEPENDENT_MASKS_UNSUPPORTED: ret = "D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INDEPENDENT_MASKS_UNSUPPORTED"; break;
        case D3D12_MESSAGE_ID_TEXTURE_BARRIER_SUBRESOURCES_OUT_OF_BOUNDS: ret = "D3D12_MESSAGE_ID_TEXTURE_BARRIER_SUBRESOURCES_OUT_OF_BOUNDS"; break;
        case D3D12_MESSAGE_ID_NON_OPTIMAL_BARRIER_ONLY_EXECUTE_COMMAND_LISTS: ret = "D3D12_MESSAGE_ID_NON_OPTIMAL_BARRIER_ONLY_EXECUTE_COMMAND_LISTS"; break;
        case D3D12_MESSAGE_ID_EXECUTE_INDIRECT_ZERO_COMMAND_COUNT: ret = "D3D12_MESSAGE_ID_EXECUTE_INDIRECT_ZERO_COMMAND_COUNT"; break;
        case D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_INCOMPATIBLE_TEXTURE_LAYOUT: ret = "D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_INCOMPATIBLE_TEXTURE_LAYOUT"; break;
        case D3D12_MESSAGE_ID_DYNAMIC_INDEX_BUFFER_STRIP_CUT_NOT_SUPPORTED: ret = "D3D12_MESSAGE_ID_DYNAMIC_INDEX_BUFFER_STRIP_CUT_NOT_SUPPORTED"; break;
        case D3D12_MESSAGE_ID_PRIMITIVE_TOPOLOGY_TRIANGLE_FANS_NOT_SUPPORTED: ret = "D3D12_MESSAGE_ID_PRIMITIVE_TOPOLOGY_TRIANGLE_FANS_NOT_SUPPORTED"; break;
        case D3D12_MESSAGE_ID_CREATE_SAMPLER_COMPARISON_FUNC_IGNORED: ret = "D3D12_MESSAGE_ID_CREATE_SAMPLER_COMPARISON_FUNC_IGNORED"; break;
        case D3D12_MESSAGE_ID_CREATEHEAP_INVALIDHEAPTYPE: ret = "D3D12_MESSAGE_ID_CREATEHEAP_INVALIDHEAPTYPE"; break;
        case D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_INVALIDHEAPTYPE: ret = "D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_INVALIDHEAPTYPE"; break;
        case D3D12_MESSAGE_ID_DYNAMIC_DEPTH_BIAS_NOT_SUPPORTED: ret = "D3D12_MESSAGE_ID_DYNAMIC_DEPTH_BIAS_NOT_SUPPORTED"; break;
        case D3D12_MESSAGE_ID_CREATERASTERIZERSTATE_NON_WHOLE_DYNAMIC_DEPTH_BIAS: ret = "D3D12_MESSAGE_ID_CREATERASTERIZERSTATE_NON_WHOLE_DYNAMIC_DEPTH_BIAS"; break;
        case D3D12_MESSAGE_ID_DYNAMIC_DEPTH_BIAS_FLAG_MISSING: ret = "D3D12_MESSAGE_ID_DYNAMIC_DEPTH_BIAS_FLAG_MISSING"; break;
        case D3D12_MESSAGE_ID_DYNAMIC_DEPTH_BIAS_NO_PIPELINE: ret = "D3D12_MESSAGE_ID_DYNAMIC_DEPTH_BIAS_NO_PIPELINE"; break;
        case D3D12_MESSAGE_ID_DYNAMIC_INDEX_BUFFER_STRIP_CUT_FLAG_MISSING: ret = "D3D12_MESSAGE_ID_DYNAMIC_INDEX_BUFFER_STRIP_CUT_FLAG_MISSING"; break;
        case D3D12_MESSAGE_ID_DYNAMIC_INDEX_BUFFER_STRIP_CUT_NO_PIPELINE: ret = "D3D12_MESSAGE_ID_DYNAMIC_INDEX_BUFFER_STRIP_CUT_NO_PIPELINE"; break;
        case D3D12_MESSAGE_ID_NONNORMALIZED_COORDINATE_SAMPLING_NOT_SUPPORTED: ret = "D3D12_MESSAGE_ID_NONNORMALIZED_COORDINATE_SAMPLING_NOT_SUPPORTED"; break;
        case D3D12_MESSAGE_ID_INVALID_CAST_TARGET: ret = "D3D12_MESSAGE_ID_INVALID_CAST_TARGET"; break;
        case D3D12_MESSAGE_ID_RENDER_PASS_COMMANDLIST_INVALID_END_STATE: ret = "D3D12_MESSAGE_ID_RENDER_PASS_COMMANDLIST_INVALID_END_STATE"; break;
        case D3D12_MESSAGE_ID_RENDER_PASS_COMMANDLIST_INVALID_START_STATE: ret = "D3D12_MESSAGE_ID_RENDER_PASS_COMMANDLIST_INVALID_START_STATE"; break;
        case D3D12_MESSAGE_ID_RENDER_PASS_MISMATCHING_ACCESS: ret = "D3D12_MESSAGE_ID_RENDER_PASS_MISMATCHING_ACCESS"; break;
        case D3D12_MESSAGE_ID_RENDER_PASS_MISMATCHING_LOCAL_PRESERVE_PARAMETERS: ret = "D3D12_MESSAGE_ID_RENDER_PASS_MISMATCHING_LOCAL_PRESERVE_PARAMETERS"; break;
        case D3D12_MESSAGE_ID_RENDER_PASS_LOCAL_PRESERVE_RENDER_PARAMETERS_ERROR: ret = "D3D12_MESSAGE_ID_RENDER_PASS_LOCAL_PRESERVE_RENDER_PARAMETERS_ERROR"; break;
        case D3D12_MESSAGE_ID_RENDER_PASS_LOCAL_DEPTH_STENCIL_ERROR: ret = "D3D12_MESSAGE_ID_RENDER_PASS_LOCAL_DEPTH_STENCIL_ERROR"; break;
        case D3D12_MESSAGE_ID_DRAW_POTENTIALLY_OUTSIDE_OF_VALID_RENDER_AREA: ret = "D3D12_MESSAGE_ID_DRAW_POTENTIALLY_OUTSIDE_OF_VALID_RENDER_AREA"; break;
        case D3D12_MESSAGE_ID_CREATERASTERIZERSTATE_INVALID_LINERASTERIZATIONMODE: ret = "D3D12_MESSAGE_ID_CREATERASTERIZERSTATE_INVALID_LINERASTERIZATIONMODE"; break;
        case D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDALIGNMENT_SMALLRESOURCE: ret = "D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDALIGNMENT_SMALLRESOURCE"; break;
        case D3D12_MESSAGE_ID_D3D12_MESSAGES_END: ret = "D3D12_MESSAGE_ID_D3D12_MESSAGES_END"; break;
    }
    return ret;
}

std::string ToString(const D3D12_MESSAGE_CALLBACK_FLAGS value)
{
    const char* ret = "Unhandled D3D12_MESSAGE_CALLBACK_FLAGS";
    switch (value) {
        case D3D12_MESSAGE_CALLBACK_FLAG_NONE: ret = "D3D12_MESSAGE_CALLBACK_FLAG_NONE"; break;
        case D3D12_MESSAGE_CALLBACK_IGNORE_FILTERS: ret = "D3D12_MESSAGE_CALLBACK_IGNORE_FILTERS"; break;
    }
    return ret;
}

std::string ToString_D3D12_MESSAGE_CALLBACK_FLAGS(const uint32_t flags)
{
    return BitmaskToString<D3D12_MESSAGE_CALLBACK_FLAGS>(flags);
}

std::string ToString(const IID& iid)
{
    if (iid == IID_IDXGIObject) return "IID_IDXGIObject";
    if (iid == IID_IDXGIDeviceSubObject) return "IID_IDXGIDeviceSubObject";
    if (iid == IID_IDXGIResource) return "IID_IDXGIResource";
    if (iid == IID_IDXGIKeyedMutex) return "IID_IDXGIKeyedMutex";
    if (iid == IID_IDXGISurface) return "IID_IDXGISurface";
    if (iid == IID_IDXGISurface1) return "IID_IDXGISurface1";
    if (iid == IID_IDXGIAdapter) return "IID_IDXGIAdapter";
    if (iid == IID_IDXGIOutput) return "IID_IDXGIOutput";
    if (iid == IID_IDXGISwapChain) return "IID_IDXGISwapChain";
    if (iid == IID_IDXGIFactory) return "IID_IDXGIFactory";
    if (iid == IID_IDXGIDevice) return "IID_IDXGIDevice";
    if (iid == IID_IDXGIFactory1) return "IID_IDXGIFactory1";
    if (iid == IID_IDXGIAdapter1) return "IID_IDXGIAdapter1";
    if (iid == IID_IDXGIDevice1) return "IID_IDXGIDevice1";
    if (iid == IID_IDXGIDisplayControl) return "IID_IDXGIDisplayControl";
    if (iid == IID_IDXGIOutputDuplication) return "IID_IDXGIOutputDuplication";
    if (iid == IID_IDXGISurface2) return "IID_IDXGISurface2";
    if (iid == IID_IDXGIResource1) return "IID_IDXGIResource1";
    if (iid == IID_IDXGIDevice2) return "IID_IDXGIDevice2";
    if (iid == IID_IDXGISwapChain1) return "IID_IDXGISwapChain1";
    if (iid == IID_IDXGIFactory2) return "IID_IDXGIFactory2";
    if (iid == IID_IDXGIAdapter2) return "IID_IDXGIAdapter2";
    if (iid == IID_IDXGIOutput1) return "IID_IDXGIOutput1";
    if (iid == IID_IDXGIDevice3) return "IID_IDXGIDevice3";
    if (iid == IID_IDXGISwapChain2) return "IID_IDXGISwapChain2";
    if (iid == IID_IDXGIOutput2) return "IID_IDXGIOutput2";
    if (iid == IID_IDXGIFactory3) return "IID_IDXGIFactory3";
    if (iid == IID_IDXGIDecodeSwapChain) return "IID_IDXGIDecodeSwapChain";
    if (iid == IID_IDXGIFactoryMedia) return "IID_IDXGIFactoryMedia";
    if (iid == IID_IDXGISwapChainMedia) return "IID_IDXGISwapChainMedia";
    if (iid == IID_IDXGIOutput3) return "IID_IDXGIOutput3";
    if (iid == IID_IDXGISwapChain3) return "IID_IDXGISwapChain3";
    if (iid == IID_IDXGIOutput4) return "IID_IDXGIOutput4";
    if (iid == IID_IDXGIFactory4) return "IID_IDXGIFactory4";
    if (iid == IID_IDXGIAdapter3) return "IID_IDXGIAdapter3";
    if (iid == IID_IDXGIOutput5) return "IID_IDXGIOutput5";
    if (iid == IID_IDXGISwapChain4) return "IID_IDXGISwapChain4";
    if (iid == IID_IDXGIDevice4) return "IID_IDXGIDevice4";
    if (iid == IID_IDXGIFactory5) return "IID_IDXGIFactory5";
    if (iid == IID_IDXGIAdapter4) return "IID_IDXGIAdapter4";
    if (iid == IID_IDXGIOutput6) return "IID_IDXGIOutput6";
    if (iid == IID_IDXGIFactory6) return "IID_IDXGIFactory6";
    if (iid == IID_IDXGIFactory7) return "IID_IDXGIFactory7";
    if (iid == D3D12_PROTECTED_RESOURCES_SESSION_HARDWARE_PROTECTED) return "D3D12_PROTECTED_RESOURCES_SESSION_HARDWARE_PROTECTED";
    if (iid == CLSID_D3D12Debug) return "CLSID_D3D12Debug";
    if (iid == CLSID_D3D12Tools) return "CLSID_D3D12Tools";
    if (iid == CLSID_D3D12DeviceRemovedExtendedData) return "CLSID_D3D12DeviceRemovedExtendedData";
    if (iid == CLSID_D3D12SDKConfiguration) return "CLSID_D3D12SDKConfiguration";
    if (iid == CLSID_D3D12DeviceFactory) return "CLSID_D3D12DeviceFactory";
    if (iid == CLSID_D3D12DSRDeviceFactory) return "CLSID_D3D12DSRDeviceFactory";
    if (iid == IID_ID3D12Object) return "IID_ID3D12Object";
    if (iid == IID_ID3D12DeviceChild) return "IID_ID3D12DeviceChild";
    if (iid == IID_ID3D12RootSignature) return "IID_ID3D12RootSignature";
    if (iid == IID_ID3D12RootSignatureDeserializer) return "IID_ID3D12RootSignatureDeserializer";
    if (iid == IID_ID3D12VersionedRootSignatureDeserializer) return "IID_ID3D12VersionedRootSignatureDeserializer";
    if (iid == IID_ID3D12Pageable) return "IID_ID3D12Pageable";
    if (iid == IID_ID3D12Heap) return "IID_ID3D12Heap";
    if (iid == IID_ID3D12Resource) return "IID_ID3D12Resource";
    if (iid == IID_ID3D12CommandAllocator) return "IID_ID3D12CommandAllocator";
    if (iid == IID_ID3D12Fence) return "IID_ID3D12Fence";
    if (iid == IID_ID3D12Fence1) return "IID_ID3D12Fence1";
    if (iid == IID_ID3D12PipelineState) return "IID_ID3D12PipelineState";
    if (iid == IID_ID3D12DescriptorHeap) return "IID_ID3D12DescriptorHeap";
    if (iid == IID_ID3D12QueryHeap) return "IID_ID3D12QueryHeap";
    if (iid == IID_ID3D12CommandSignature) return "IID_ID3D12CommandSignature";
    if (iid == IID_ID3D12CommandList) return "IID_ID3D12CommandList";
    if (iid == IID_ID3D12GraphicsCommandList) return "IID_ID3D12GraphicsCommandList";
    if (iid == IID_ID3D12GraphicsCommandList1) return "IID_ID3D12GraphicsCommandList1";
    if (iid == IID_ID3D12GraphicsCommandList2) return "IID_ID3D12GraphicsCommandList2";
    if (iid == IID_ID3D12CommandQueue) return "IID_ID3D12CommandQueue";
    if (iid == IID_ID3D12Device) return "IID_ID3D12Device";
    if (iid == IID_ID3D12PipelineLibrary) return "IID_ID3D12PipelineLibrary";
    if (iid == IID_ID3D12PipelineLibrary1) return "IID_ID3D12PipelineLibrary1";
    if (iid == IID_ID3D12Device1) return "IID_ID3D12Device1";
    if (iid == IID_ID3D12Device2) return "IID_ID3D12Device2";
    if (iid == IID_ID3D12Device3) return "IID_ID3D12Device3";
    if (iid == IID_ID3D12ProtectedSession) return "IID_ID3D12ProtectedSession";
    if (iid == IID_ID3D12ProtectedResourceSession) return "IID_ID3D12ProtectedResourceSession";
    if (iid == IID_ID3D12Device4) return "IID_ID3D12Device4";
    if (iid == IID_ID3D12LifetimeOwner) return "IID_ID3D12LifetimeOwner";
    if (iid == IID_ID3D12SwapChainAssistant) return "IID_ID3D12SwapChainAssistant";
    if (iid == IID_ID3D12LifetimeTracker) return "IID_ID3D12LifetimeTracker";
    if (iid == IID_ID3D12StateObject) return "IID_ID3D12StateObject";
    if (iid == IID_ID3D12StateObjectProperties) return "IID_ID3D12StateObjectProperties";
    if (iid == IID_ID3D12Device5) return "IID_ID3D12Device5";
    if (iid == IID_ID3D12DeviceRemovedExtendedDataSettings) return "IID_ID3D12DeviceRemovedExtendedDataSettings";
    if (iid == IID_ID3D12DeviceRemovedExtendedDataSettings1) return "IID_ID3D12DeviceRemovedExtendedDataSettings1";
    if (iid == IID_ID3D12DeviceRemovedExtendedDataSettings2) return "IID_ID3D12DeviceRemovedExtendedDataSettings2";
    if (iid == IID_ID3D12DeviceRemovedExtendedData) return "IID_ID3D12DeviceRemovedExtendedData";
    if (iid == IID_ID3D12DeviceRemovedExtendedData1) return "IID_ID3D12DeviceRemovedExtendedData1";
    if (iid == IID_ID3D12DeviceRemovedExtendedData2) return "IID_ID3D12DeviceRemovedExtendedData2";
    if (iid == IID_ID3D12Device6) return "IID_ID3D12Device6";
    if (iid == IID_ID3D12ProtectedResourceSession1) return "IID_ID3D12ProtectedResourceSession1";
    if (iid == IID_ID3D12Device7) return "IID_ID3D12Device7";
    if (iid == IID_ID3D12Device8) return "IID_ID3D12Device8";
    if (iid == IID_ID3D12Resource1) return "IID_ID3D12Resource1";
    if (iid == IID_ID3D12Resource2) return "IID_ID3D12Resource2";
    if (iid == IID_ID3D12Heap1) return "IID_ID3D12Heap1";
    if (iid == IID_ID3D12GraphicsCommandList3) return "IID_ID3D12GraphicsCommandList3";
    if (iid == IID_ID3D12MetaCommand) return "IID_ID3D12MetaCommand";
    if (iid == IID_ID3D12GraphicsCommandList4) return "IID_ID3D12GraphicsCommandList4";
    if (iid == IID_ID3D12ShaderCacheSession) return "IID_ID3D12ShaderCacheSession";
    if (iid == IID_ID3D12Device9) return "IID_ID3D12Device9";
    if (iid == IID_ID3D12Device10) return "IID_ID3D12Device10";
    if (iid == IID_ID3D12Device11) return "IID_ID3D12Device11";
    if (iid == IID_ID3D12Device12) return "IID_ID3D12Device12";
    if (iid == IID_ID3D12VirtualizationGuestDevice) return "IID_ID3D12VirtualizationGuestDevice";
    if (iid == IID_ID3D12Tools) return "IID_ID3D12Tools";
    if (iid == IID_ID3D12SDKConfiguration) return "IID_ID3D12SDKConfiguration";
    if (iid == IID_ID3D12SDKConfiguration1) return "IID_ID3D12SDKConfiguration1";
    if (iid == IID_ID3D12DeviceFactory) return "IID_ID3D12DeviceFactory";
    if (iid == IID_ID3D12DeviceConfiguration) return "IID_ID3D12DeviceConfiguration";
    if (iid == IID_ID3D12GraphicsCommandList5) return "IID_ID3D12GraphicsCommandList5";
    if (iid == IID_ID3D12GraphicsCommandList6) return "IID_ID3D12GraphicsCommandList6";
    if (iid == IID_ID3D12GraphicsCommandList7) return "IID_ID3D12GraphicsCommandList7";
    if (iid == IID_ID3D12GraphicsCommandList8) return "IID_ID3D12GraphicsCommandList8";
    if (iid == IID_ID3D12GraphicsCommandList9) return "IID_ID3D12GraphicsCommandList9";
    if (iid == IID_ID3D12DSRDeviceFactory) return "IID_ID3D12DSRDeviceFactory";
    if (iid == IID_ID3D10Blob) return "IID_ID3D10Blob";
    if (iid == WKPDID_D3DDebugObjectName) return "WKPDID_D3DDebugObjectName";
    if (iid == WKPDID_D3DDebugObjectNameW) return "WKPDID_D3DDebugObjectNameW";
    if (iid == WKPDID_CommentStringW) return "WKPDID_CommentStringW";
    if (iid == WKPDID_D3D12UniqueObjectId) return "WKPDID_D3D12UniqueObjectId";
    if (iid == D3D_TEXTURE_LAYOUT_ROW_MAJOR) return "D3D_TEXTURE_LAYOUT_ROW_MAJOR";
    if (iid == D3D_TEXTURE_LAYOUT_64KB_STANDARD_SWIZZLE) return "D3D_TEXTURE_LAYOUT_64KB_STANDARD_SWIZZLE";
    if (iid == WKPDID_D3DAutoDebugObjectNameW) return "WKPDID_D3DAutoDebugObjectNameW";
    if (iid == DXGI_DEBUG_D3D12) return "DXGI_DEBUG_D3D12";
    if (iid == IID_ID3D12Debug) return "IID_ID3D12Debug";
    if (iid == IID_ID3D12Debug1) return "IID_ID3D12Debug1";
    if (iid == IID_ID3D12Debug2) return "IID_ID3D12Debug2";
    if (iid == IID_ID3D12Debug3) return "IID_ID3D12Debug3";
    if (iid == IID_ID3D12Debug4) return "IID_ID3D12Debug4";
    if (iid == IID_ID3D12Debug5) return "IID_ID3D12Debug5";
    if (iid == IID_ID3D12Debug6) return "IID_ID3D12Debug6";
    if (iid == IID_ID3D12DebugDevice1) return "IID_ID3D12DebugDevice1";
    if (iid == IID_ID3D12DebugDevice) return "IID_ID3D12DebugDevice";
    if (iid == IID_ID3D12DebugDevice2) return "IID_ID3D12DebugDevice2";
    if (iid == IID_ID3D12DebugCommandQueue) return "IID_ID3D12DebugCommandQueue";
    if (iid == IID_ID3D12DebugCommandQueue1) return "IID_ID3D12DebugCommandQueue1";
    if (iid == IID_ID3D12DebugCommandList1) return "IID_ID3D12DebugCommandList1";
    if (iid == IID_ID3D12DebugCommandList) return "IID_ID3D12DebugCommandList";
    if (iid == IID_ID3D12DebugCommandList2) return "IID_ID3D12DebugCommandList2";
    if (iid == IID_ID3D12DebugCommandList3) return "IID_ID3D12DebugCommandList3";
    if (iid == IID_ID3D12SharingContract) return "IID_ID3D12SharingContract";
    if (iid == IID_ID3D12ManualWriteTrackingResource) return "IID_ID3D12ManualWriteTrackingResource";
    if (iid == IID_ID3D12InfoQueue) return "IID_ID3D12InfoQueue";
    if (iid == IID_ID3D12InfoQueue1) return "IID_ID3D12InfoQueue1";
    if (iid == IID_IUnknown) return "IID_IUnknown";
    return "Invalid IID";
}


GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // defined(D3D12_SUPPORT) || defined(ENABLE_OPENXR_SUPPORT)
