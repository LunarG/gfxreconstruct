/*
** Copyright (c) 2021 LunarG, Inc.
** Copyright (c) 2023 Qualcomm Innovation Center, Inc. All rights reserved.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

#ifndef GFXRECON_CUSTOM_DX12_TO_STRING_H
#define GFXRECON_CUSTOM_DX12_TO_STRING_H

#include "format/platform_types.h"
#include "util/custom_common_to_string.h"
#include "util/defines.h"
#include "util/to_string.h"

#include <d3d12.h>
#include <d3d11.h>
#include <d3d11_3.h>

#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

std::string ToString(const D3D12_CPU_DESCRIPTOR_HANDLE& obj,
                     ToStringFlags                      toStringFlags = kToString_Default,
                     uint32_t                           tabCount      = kToStringDefaultTabCount,
                     uint32_t                           tabSize       = kToStringDefaultTabSize);

std::string ToString(const D3D12_GPU_DESCRIPTOR_HANDLE& obj,
                     ToStringFlags                      toStringFlags = kToString_Default,
                     uint32_t                           tabCount      = kToStringDefaultTabCount,
                     uint32_t                           tabSize       = kToStringDefaultTabSize);

std::string ToString(const LARGE_INTEGER& obj,
                     ToStringFlags        toStringFlags = kToString_Default,
                     uint32_t             tabCount      = kToStringDefaultTabCount,
                     uint32_t             tabSize       = kToStringDefaultTabSize);

std::string ToString(const D3D12_VERSIONED_ROOT_SIGNATURE_DESC& obj,
                     ToStringFlags                              toStringFlags = kToString_Default,
                     uint32_t                                   tabCount      = kToStringDefaultTabCount,
                     uint32_t                                   tabSize       = kToStringDefaultTabSize);

std::string ToString(const D3D12_TEXTURE_COPY_LOCATION& obj,
                     ToStringFlags                      toStringFlags = kToString_Default,
                     uint32_t                           tabCount      = kToStringDefaultTabCount,
                     uint32_t                           tabSize       = kToStringDefaultTabSize);

std::string ToString(const D3D12_SHADER_RESOURCE_VIEW_DESC& obj,
                     ToStringFlags                          toStringFlags = kToString_Default,
                     uint32_t                               tabCount      = kToStringDefaultTabCount,
                     uint32_t                               tabSize       = kToStringDefaultTabSize);

std::string ToString(const D3D12_UNORDERED_ACCESS_VIEW_DESC& obj,
                     ToStringFlags                           toStringFlags = kToString_Default,
                     uint32_t                                tabCount      = kToStringDefaultTabCount,
                     uint32_t                                tabSize       = kToStringDefaultTabSize);

std::string ToString(const D3D12_RENDER_TARGET_VIEW_DESC& obj,
                     ToStringFlags                        toStringFlags = kToString_Default,
                     uint32_t                             tabCount      = kToStringDefaultTabCount,
                     uint32_t                             tabSize       = kToStringDefaultTabSize);

std::string ToString(const D3D12_DEPTH_STENCIL_VIEW_DESC& obj,
                     ToStringFlags                        toStringFlags = kToString_Default,
                     uint32_t                             tabCount      = kToStringDefaultTabCount,
                     uint32_t                             tabSize       = kToStringDefaultTabSize);

std::string ToString(const D3D12_CLEAR_VALUE& obj,
                     ToStringFlags            toStringFlags = kToString_Default,
                     uint32_t                 tabCount      = kToStringDefaultTabCount,
                     uint32_t                 tabSize       = kToStringDefaultTabSize);

std::string ToString(const D3D12_PIPELINE_STATE_STREAM_DESC& obj,
                     ToStringFlags                           toStringFlags = kToString_Default,
                     uint32_t                                tabCount      = kToStringDefaultTabCount,
                     uint32_t                                tabSize       = kToStringDefaultTabSize);

std::string ToString(const D3D12_STATE_OBJECT_DESC& obj,
                     ToStringFlags                  toStringFlags = kToString_Default,
                     uint32_t                       tabCount      = kToStringDefaultTabCount,
                     uint32_t                       tabSize       = kToStringDefaultTabSize);

std::string ToString(const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS& obj,
                     ToStringFlags                                               toStringFlags = kToString_Default,
                     uint32_t                                                    tabCount = kToStringDefaultTabCount,
                     uint32_t                                                    tabSize  = kToStringDefaultTabSize);

std::string ToString(const D3D12_RENDER_PASS_BEGINNING_ACCESS& obj,
                     ToStringFlags                             toStringFlags = kToString_Default,
                     uint32_t                                  tabCount      = kToStringDefaultTabCount,
                     uint32_t                                  tabSize       = kToStringDefaultTabSize);

std::string ToString(const D3D12_RENDER_PASS_ENDING_ACCESS& obj,
                     ToStringFlags                          toStringFlags = kToString_Default,
                     uint32_t                               tabCount      = kToStringDefaultTabCount,
                     uint32_t                               tabSize       = kToStringDefaultTabSize);

std::string ToString(const D3D12_ROOT_PARAMETER& obj,
                     ToStringFlags               toStringFlags = kToString_Default,
                     uint32_t                    tabCount      = kToStringDefaultTabCount,
                     uint32_t                    tabSize       = kToStringDefaultTabSize);

std::string ToString(const D3D12_ROOT_PARAMETER1& obj,
                     ToStringFlags                toStringFlags = kToString_Default,
                     uint32_t                     tabCount      = kToStringDefaultTabCount,
                     uint32_t                     tabSize       = kToStringDefaultTabSize);

std::string ToString(const D3D12_INDIRECT_ARGUMENT_DESC& obj,
                     ToStringFlags                       toStringFlags = kToString_Default,
                     uint32_t                            tabCount      = kToStringDefaultTabCount,
                     uint32_t                            tabSize       = kToStringDefaultTabSize);

std::string ToString(const D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION& obj,
                     ToStringFlags                                      toStringFlags = kToString_Default,
                     uint32_t                                           tabCount      = kToStringDefaultTabCount,
                     uint32_t                                           tabSize       = kToStringDefaultTabSize);

std::string ToString(const D3D12_RESOURCE_BARRIER& obj,
                     ToStringFlags                 toStringFlags = kToString_Default,
                     uint32_t                      tabCount      = kToStringDefaultTabCount,
                     uint32_t                      tabSize       = kToStringDefaultTabSize);

std::string ToString(const D3D12_STATE_SUBOBJECT& obj,
                     ToStringFlags                toStringFlags = kToString_Default,
                     uint32_t                     tabCount      = kToStringDefaultTabCount,
                     uint32_t                     tabSize       = kToStringDefaultTabSize);

std::string ToString(const D3D12_RAYTRACING_GEOMETRY_DESC& obj,
                     ToStringFlags                         toStringFlags = kToString_Default,
                     uint32_t                              tabCount      = kToStringDefaultTabCount,
                     uint32_t                              tabSize       = kToStringDefaultTabSize);

template <>
std::string ToString<D3D11_SUBRESOURCE_DATA>(const D3D11_SUBRESOURCE_DATA& obj,
                                             ToStringFlags                 toStringFlags,
                                             uint32_t                      tabCount,
                                             uint32_t                      tabSize);

template <>
std::string ToString<D3D11_BUFFER_SRV>(const D3D11_BUFFER_SRV& obj,
                                       ToStringFlags           toStringFlags,
                                       uint32_t                tabCount,
                                       uint32_t                tabSize);

template <>
std::string ToString<D3D11_SHADER_RESOURCE_VIEW_DESC>(const D3D11_SHADER_RESOURCE_VIEW_DESC& obj,
                                                      ToStringFlags                          toStringFlags,
                                                      uint32_t                               tabCount,
                                                      uint32_t                               tabSize);

template <>
std::string ToString<D3D11_BUFFER_RTV>(const D3D11_BUFFER_RTV& obj,
                                       ToStringFlags           toStringFlags,
                                       uint32_t                tabCount,
                                       uint32_t                tabSize);

template <>
std::string ToString<D3D11_UNORDERED_ACCESS_VIEW_DESC>(const D3D11_UNORDERED_ACCESS_VIEW_DESC& obj,
                                                       ToStringFlags                           toStringFlags,
                                                       uint32_t                                tabCount,
                                                       uint32_t                                tabSize);

template <>
std::string ToString<D3D11_RENDER_TARGET_VIEW_DESC>(const D3D11_RENDER_TARGET_VIEW_DESC& obj,
                                                    ToStringFlags                        toStringFlags,
                                                    uint32_t                             tabCount,
                                                    uint32_t                             tabSize);

template <>
std::string ToString<D3D11_DEPTH_STENCIL_VIEW_DESC>(const D3D11_DEPTH_STENCIL_VIEW_DESC& obj,
                                                    ToStringFlags                        toStringFlags,
                                                    uint32_t                             tabCount,
                                                    uint32_t                             tabSize);

template <>
std::string ToString<D3D11_SHADER_RESOURCE_VIEW_DESC1>(const D3D11_SHADER_RESOURCE_VIEW_DESC1& obj,
                                                       ToStringFlags                           toStringFlags,
                                                       uint32_t                                tabCount,
                                                       uint32_t                                tabSize);

template <>
std::string ToString<D3D11_UNORDERED_ACCESS_VIEW_DESC1>(const D3D11_UNORDERED_ACCESS_VIEW_DESC1& obj,
                                                        ToStringFlags                            toStringFlags,
                                                        uint32_t                                 tabCount,
                                                        uint32_t                                 tabSize);

template <>
std::string ToString<D3D11_RENDER_TARGET_VIEW_DESC1>(const D3D11_RENDER_TARGET_VIEW_DESC1& obj,
                                                     ToStringFlags                         toStringFlags,
                                                     uint32_t                              tabCount,
                                                     uint32_t                              tabSize);

template <>
std::string ToString<D3D11_VIDEO_COLOR>(const D3D11_VIDEO_COLOR& obj,
                                        ToStringFlags            toStringFlags,
                                        uint32_t                 tabCount,
                                        uint32_t                 tabSize);

template <>
std::string ToString<D3D11_AUTHENTICATED_PROTECTION_FLAGS>(const D3D11_AUTHENTICATED_PROTECTION_FLAGS& obj,
                                                           ToStringFlags                               toStringFlags,
                                                           uint32_t                                    tabCount,
                                                           uint32_t                                    tabSize);

template <>
std::string ToString<D3D11_VIDEO_DECODER_OUTPUT_VIEW_DESC>(const D3D11_VIDEO_DECODER_OUTPUT_VIEW_DESC& obj,
                                                           ToStringFlags                               toStringFlags,
                                                           uint32_t                                    tabCount,
                                                           uint32_t                                    tabSize);

template <>
std::string ToString<D3D11_VIDEO_PROCESSOR_INPUT_VIEW_DESC>(const D3D11_VIDEO_PROCESSOR_INPUT_VIEW_DESC& obj,
                                                            ToStringFlags                                toStringFlags,
                                                            uint32_t                                     tabCount,
                                                            uint32_t                                     tabSize);

template <>
std::string ToString<D3D11_VIDEO_PROCESSOR_OUTPUT_VIEW_DESC>(const D3D11_VIDEO_PROCESSOR_OUTPUT_VIEW_DESC& obj,
                                                             ToStringFlags toStringFlags,
                                                             uint32_t      tabCount,
                                                             uint32_t      tabSize);

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_CUSTOM_DX12_TO_STRING_H
