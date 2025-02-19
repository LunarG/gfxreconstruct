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

#include "decode/dx12_descriptor_map.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void Dx12DescriptorMap::AddCpuDescriptorHeap(const D3D12_CPU_DESCRIPTOR_HANDLE&     capture_cpu_start,
                                             const D3D12_CPU_DESCRIPTOR_HANDLE&     replay_cpu_start,
                                             D3D12_DESCRIPTOR_HEAP_TYPE             heap_info_descriptor_type,
                                             uint32_t                               heap_info_descriptor_count,
                                             std::shared_ptr<DescriptorIncrements>& heap_info_capture_increments,
                                             std::shared_ptr<DescriptorIncrements>& heap_info_replay_increments)
{
    HeapInfo<size_t> heap_info;
    heap_info.capture_begin      = capture_cpu_start.ptr;
    heap_info.capture_end        = kNullCpuAddress;
    heap_info.replay_begin       = replay_cpu_start.ptr;
    heap_info.descriptor_type    = heap_info_descriptor_type;
    heap_info.descriptor_count   = heap_info_descriptor_count;
    heap_info.capture_increments = heap_info_capture_increments;
    heap_info.replay_increments  = heap_info_replay_increments;

    descriptor_cpu_addresses_[heap_info.capture_begin] = heap_info;
}

void Dx12DescriptorMap::AddGpuDescriptorHeap(const D3D12_GPU_DESCRIPTOR_HANDLE&     capture_gpu_start,
                                             const D3D12_GPU_DESCRIPTOR_HANDLE&     replay_gpu_start,
                                             D3D12_DESCRIPTOR_HEAP_TYPE             heap_info_descriptor_type,
                                             uint32_t                               heap_info_descriptor_count,
                                             std::shared_ptr<DescriptorIncrements>& heap_info_capture_increments,
                                             std::shared_ptr<DescriptorIncrements>& heap_info_replay_increments)
{
    HeapInfo<uint64_t> heap_info;
    heap_info.capture_begin      = capture_gpu_start.ptr;
    heap_info.capture_end        = kNullGpuAddress;
    heap_info.replay_begin       = replay_gpu_start.ptr;
    heap_info.descriptor_type    = heap_info_descriptor_type;
    heap_info.descriptor_count   = heap_info_descriptor_count;
    heap_info.capture_increments = heap_info_capture_increments;
    heap_info.replay_increments  = heap_info_replay_increments;

    descriptor_gpu_addresses_[heap_info.capture_begin] = heap_info;
}

void Dx12DescriptorMap::GetCpuAddress(D3D12_CPU_DESCRIPTOR_HANDLE& descriptor) const
{
    if (!Get(descriptor.ptr, descriptor_cpu_addresses_))
    {
        GFXRECON_LOG_FATAL("Failed to map CPU descriptor handle 0x%" PRIxPTR, descriptor.ptr);
    }
}

void Dx12DescriptorMap::GetGpuAddress(D3D12_GPU_DESCRIPTOR_HANDLE& descriptor, bool* found) const
{
    bool get_result = Get(descriptor.ptr, descriptor_gpu_addresses_);
    if (found != nullptr)
    {
        *found = get_result;
    }
    else if (!get_result)
    {
        GFXRECON_LOG_FATAL_ONCE("Failed to map GPU descriptor handle 0x%" PRIx64, descriptor.ptr);
    }
}

void Dx12DescriptorMap::RemoveCpuDescriptorHeap(const size_t capture_cpu_addr_begin)
{
    descriptor_cpu_addresses_.erase(capture_cpu_addr_begin);
}

void Dx12DescriptorMap::RemoveGpuDescriptorHeap(const uint64_t capture_gpu_addr_begin)
{
    descriptor_gpu_addresses_.erase(capture_gpu_addr_begin);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
