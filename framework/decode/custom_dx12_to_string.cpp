/*
** Copyright (c) 2021 LunarG, Inc.
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

#include "custom_dx12_to_string.h"
#include "generated/generated_dx12_enum_to_string.h"
#include "generated/generated_dx12_struct_to_string.h"

#include <algorithm>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

template <>
std::string ToString<D3D12_CPU_DESCRIPTOR_HANDLE>(const D3D12_CPU_DESCRIPTOR_HANDLE& obj,
                                                  ToStringFlags                      toStringFlags,
                                                  uint32_t                           tabCount,
                                                  uint32_t                           tabSize)
{
    return {};
}

template <>
std::string ToString<D3D12_GPU_DESCRIPTOR_HANDLE>(const D3D12_GPU_DESCRIPTOR_HANDLE& obj,
                                                  ToStringFlags                      toStringFlags,
                                                  uint32_t                           tabCount,
                                                  uint32_t                           tabSize)
{
    return {};
}

template <>
std::string
ToString<LARGE_INTEGER>(const LARGE_INTEGER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return {};
}

template <>
std::string ToString<D3D12_VERSIONED_ROOT_SIGNATURE_DESC>(const D3D12_VERSIONED_ROOT_SIGNATURE_DESC& obj,
    ToStringFlags                              toStringFlags,
    uint32_t                                   tabCount,
    uint32_t                                   tabSize)
{
    return {};
}

template <>
std::string ToString<D3D12_TEXTURE_COPY_LOCATION>(const D3D12_TEXTURE_COPY_LOCATION& obj,
    ToStringFlags                      toStringFlags,
    uint32_t                           tabCount,
    uint32_t                           tabSize)
{
    return {};
}

template <>
std::string ToString<D3D12_SHADER_RESOURCE_VIEW_DESC>(const D3D12_SHADER_RESOURCE_VIEW_DESC& obj,
    ToStringFlags                          toStringFlags,
    uint32_t                               tabCount,
    uint32_t                               tabSize)
{
    return {};
}

template <>
std::string ToString<D3D12_UNORDERED_ACCESS_VIEW_DESC>(const D3D12_UNORDERED_ACCESS_VIEW_DESC& obj,
    ToStringFlags                           toStringFlags,
    uint32_t                                tabCount,
    uint32_t                                tabSize)
{
    return {};
}

template <>
std::string ToString<D3D12_RENDER_TARGET_VIEW_DESC>(const D3D12_RENDER_TARGET_VIEW_DESC& obj,
    ToStringFlags                        toStringFlags,
    uint32_t                             tabCount,
    uint32_t                             tabSize)
{
    return {};
}

template <>
std::string ToString<D3D12_DEPTH_STENCIL_VIEW_DESC>(const D3D12_DEPTH_STENCIL_VIEW_DESC& obj,
    ToStringFlags                        toStringFlags,
    uint32_t                             tabCount,
    uint32_t                             tabSize)
{
    return {};
}

template <>
std::string ToString<D3D12_CLEAR_VALUE>(const D3D12_CLEAR_VALUE& obj,
    ToStringFlags            toStringFlags,
    uint32_t                 tabCount,
    uint32_t                 tabSize)
{
    return {};
}

template <>
std::string ToString<D3D12_PIPELINE_STATE_STREAM_DESC>(const D3D12_PIPELINE_STATE_STREAM_DESC& obj,
    ToStringFlags                           toStringFlags,
    uint32_t                                tabCount,
    uint32_t                                tabSize)
{
    return {};
}

template <>
std::string ToString<D3D12_STATE_OBJECT_DESC>(const D3D12_STATE_OBJECT_DESC& obj,
    ToStringFlags                  toStringFlags,
    uint32_t                       tabCount,
    uint32_t                       tabSize)
{
    return {};
}

template <>
std::string ToString<D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS>(
    const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS& obj,
    ToStringFlags                                               toStringFlags,
    uint32_t                                                    tabCount,
    uint32_t                                                    tabSize)
{
    return {};
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
