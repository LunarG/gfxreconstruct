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

#ifndef GFXRECON_GPU_VA_RANGE_H
#define GFXRECON_GPU_VA_RANGE_H

#include "util/defines.h"

#include <d3d12.h>

#include <Windows.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

/// GPU virtual address range
///
/// The range is inclusive = [start, end].
struct GpuVaRange
{
    D3D12_GPU_VIRTUAL_ADDRESS start; ///< range start - inclusive
    D3D12_GPU_VIRTUAL_ADDRESS end;   ///< range end - inclusive
};

//----------------------------------------------------------------------------
/// Get the GPU VA range of the given buffer resource
/// \param resource [in] Resource whose GPU VA range is accessed
/// \param gpu_va_range [out] GPU VA range of the buffer resource
/// \return True is succeed False if resource is null, not a buffer resource or
/// if the buffer GPU VA range access failed
//----------------------------------------------------------------------------

bool GetResourceGpuVaRange(const ID3D12Resource* resource, GpuVaRange* gpu_va_range) noexcept;

/// Compare 2 GPU VA ranges
///
/// \return True if the ranges are equal false if not
bool operator==(const GpuVaRange& lhs, const GpuVaRange& rhs) noexcept;

/// Compare 2 GPU VA ranges
///
/// \return False if the ranges are equal true if not
bool operator!=(const GpuVaRange& lhs, const GpuVaRange& rhs) noexcept;

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GPU_VA_RANGE_H
