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

#ifndef GFXRECON_DX12_UTILS_H
#define GFXRECON_DX12_UTILS_H

#include "util/defines.h"
#include "dx12_pointers.h"
#include "dx_pointers.h"

#include <d3d12.h>
#include <dxgi.h>

#include <Windows.h>
#include <array>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(test)

// Create the default(WARP) test device
Dx12DevicePtr CreateDx12Device() noexcept;

//----------------------------------------------------------------------------
/// Get the buffer description for a buffer of the given size
/// \param size of buffer
/// \return resource descriptor struct
//----------------------------------------------------------------------------
D3D12_RESOURCE_DESC GetDx12BufferDesc(int size) noexcept;

//----------------------------------------------------------------------------
/// Generate a list of DX12 buffers for testing
/// \param dx12_device pointer to dx12device interface
/// \param list_size defines number of buffers
/// \param buffer_size responsible for the size of each buffer
/// \param mappable if true - resource state = GENERIC READ, if false resource state = COMMON
/// \return vector of pointers to dx12 resources
//----------------------------------------------------------------------------
std::vector<Dx12ResourcePtr>
GenerateDx12BufferList(Dx12DevicePtr::Interface* dx12_device, int list_size, int buffer_size, bool mappable) noexcept;

//----------------------------------------------------------------------------
/// Generate a list of DX12 buffers for testing
/// \param dx12_device pointer to dx12device interface
/// \param list_size defines number of buffers
/// \param buffer_size responsible for the size of each buffer
/// \return vector of pointers to dx12 resources
//----------------------------------------------------------------------------
std::vector<Dx12ResourcePtr> GenerateDx12BufferList(int list_size, int buffer_size) noexcept;

//----------------------------------------------------------------------------
/// Generate a list of DX12 overlapping placed buffers for testing.
/// A total of(bound_count* overlap_count) buffers are generated.
/// \param bound_count
/// \param overlap_count - Every overlap_count buffers are bound to the same address.
/// \param buffer_size
/// \return vector of pointers to placed buffers
//----------------------------------------------------------------------------
std::vector<Dx12ResourcePtr>
GenerateDx12OverlappingBufferList(int bound_count, int overlap_count, int buffer_size) noexcept;

//----------------------------------------------------------------------------
/// Generate a list of DX12 overlapping buffers for testing
/// All buffers are allocad on the same heap.
/// Buffers are bound in a way where buffer i+1 start GPU VA is in the range
/// of buffer i.
/// Buffer size must be equal or greated than D3D12_DEFAULT_RESOURCE_PLACEMENT_ALIGNMENT (64Kb).
/// \param list_size
/// \param buffer_size
/// \return vector of pointers to placed buffers
//----------------------------------------------------------------------------
std::vector<Dx12ResourcePtr> GenerateDx12OverlappingBufferList(int list_size, int buffer_size) noexcept;

GFXRECON_END_NAMESPACE(test)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
#endif
