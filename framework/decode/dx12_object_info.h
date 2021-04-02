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

#ifndef GFXRECON_DECODE_DX12_OBJECT_INFO_H
#define GFXRECON_DECODE_DX12_OBJECT_INFO_H

#include "decode/window.h"
#include "format/format.h"
#include "util/defines.h"

#include <d3d12.h>

#include <array>
#include <memory>
#include <Unknwn.h>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

//
// Structures for storing DirectX object info.
//

typedef std::array<UINT, D3D12_DESCRIPTOR_HEAP_TYPE_NUM_TYPES> DescriptorIncrements;

enum class DxObjectInfoType : uint32_t
{
    kUnused = 0,
    kIDxgiSwapchainInfo,
    kID3D12DeviceInfo,
    kID3D12DescriptorHeapInfo,
    kID3D12ResourceInfo
};

struct MappedMemoryInfo
{
    uint32_t count{ 0 };     ///< Number of times that the memory has been mapped.
    uint64_t memory_id{ 0 }; ///< Capture ID for the mapped memory.
};

struct DxObjectInfo
{
    // Standard info stored for all DX objects.
    IUnknown*        object{ nullptr };
    format::HandleId capture_id{ format::kNullHandleId };
    uint64_t         ref_count{ 0 };
    DxObjectInfoType extra_info_type{ DxObjectInfoType::kUnused };
    void*            extra_info{ nullptr };
};

struct DxgiSwapchainInfo
{
    Window* window{ nullptr }; ///< Pointer to the platform-specific window object associated with the swapchain.
};

struct D3D12DeviceInfo
{
    std::shared_ptr<DescriptorIncrements> capture_increments{ std::make_shared<DescriptorIncrements>() };
    std::shared_ptr<DescriptorIncrements> replay_increments{ std::make_shared<DescriptorIncrements>() };
};

struct D3D12DescriptorHeapInfo
{
    std::shared_ptr<DescriptorIncrements> capture_increments;
    std::shared_ptr<DescriptorIncrements> replay_increments;

    D3D12_DESCRIPTOR_HEAP_TYPE descriptor_type{};
    uint32_t                   descriptor_count{ 0 };

    size_t   capture_cpu_addr_begin{ 0 };
    size_t   capture_cpu_addr_end{ 0 };
    uint64_t capture_gpu_addr_begin{ 0 };
    uint64_t capture_gpu_addr_end{ 0 };

    size_t   replay_cpu_addr_begin{ 0 };
    uint64_t replay_gpu_addr_begin{ 0 };
};

struct D3D12ResourceInfo
{
    std::unordered_map<uint32_t, MappedMemoryInfo> mapped_memory_info; ///< Map subresource index to mapped memory info.
    uint64_t                                       capture_address_{ 0 }; ///< Capture GPU VA.
    uint64_t                                       replay_address_{ 0 };  ///< Replay GPU VA.
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_OBJECT_INFO_H
