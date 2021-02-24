/*
** Copyright (c) 2018-2021 Advanced Micro Devices, Inc. All rights reserved.
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

#include "gpu_va_range.h"

#include <d3d12.h>
#include "logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

bool GetResourceGpuVaRange(const ID3D12Resource* resource, GpuVaRange* gpu_va_range) noexcept
{
    if ((nullptr == resource) || (nullptr == gpu_va_range))
    {
        GFXRECON_LOG_INFO("Invalid argument passed to a function");
        return false;
    }
    D3D12_RESOURCE_DESC resource_desc = const_cast<ID3D12Resource*>(resource)->GetDesc();
    if (D3D12_RESOURCE_DIMENSION_BUFFER != resource_desc.Dimension)
    {
        GFXRECON_LOG_INFO("Invalid argument passed to a function");
        return false;
    }
    gpu_va_range->start = const_cast<ID3D12Resource*>(resource)->GetGPUVirtualAddress();
    gpu_va_range->end   = gpu_va_range->start + resource_desc.Width;
    return true;
}

bool operator==(const GpuVaRange& lhs, const GpuVaRange& rhs) noexcept
{
    return ((lhs.start == rhs.start) && (lhs.end == rhs.end));
}

bool operator!=(const GpuVaRange& lhs, const GpuVaRange& rhs) noexcept
{
    return (!(lhs == rhs));
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
