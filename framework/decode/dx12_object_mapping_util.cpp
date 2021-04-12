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

#include "decode/dx12_object_mapping_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(object_mapping)

void MapCpuDescriptorHandle(D3D12_CPU_DESCRIPTOR_HANDLE& handle, const Dx12CpuDescriptorMap& descriptor_cpu_addresses)
{
    size_t replay_addr = 0;
    auto   entry       = descriptor_cpu_addresses.lower_bound(handle.ptr);

    if (entry != descriptor_cpu_addresses.end())
    {
        auto info              = entry->second;
        auto type              = info->descriptor_type;
        auto start_addr        = info->capture_cpu_addr_begin;
        auto capture_increment = (*info->capture_increments)[type];
        auto replay_increment  = (*info->replay_increments)[type];

        // Check to see if the descriptor address is withing the range of the captured descriptor heap address
        // boundaries.
        if (info->capture_cpu_addr_end == 0)
        {
            // Compute the end address for the heap.
            auto size                  = capture_increment * info->descriptor_count;
            info->capture_cpu_addr_end = start_addr + size;
        }

        if (handle.ptr < info->capture_cpu_addr_end)
        {
            replay_addr = info->replay_cpu_addr_begin;

            // Compute offset from address.
            auto offset = handle.ptr - start_addr;
            if (offset > 0)
            {
                if (capture_increment == replay_increment)
                {
                    replay_addr += offset;
                }
                else
                {
                    replay_addr += (offset / capture_increment) * replay_increment;
                }
            }
        }
    }

    if (replay_addr != 0)
    {
        handle.ptr = replay_addr;
    }
    else
    {
        GFXRECON_LOG_FATAL("Failed to map CPU descriptor handle 0x%" PRIxPTR, handle.ptr);
    }
}

void MapCpuDescriptorHandles(D3D12_CPU_DESCRIPTOR_HANDLE* handles,
                             size_t                       handles_len,
                             const Dx12CpuDescriptorMap&  descriptor_cpu_addresses)
{
    for (size_t i = 0; i < handles_len; ++i)
    {
        MapCpuDescriptorHandle(handles[i], descriptor_cpu_addresses);
    }
}

void MapGpuDescriptorHandle(D3D12_GPU_DESCRIPTOR_HANDLE& handle, const Dx12GpuDescriptorMap& descriptor_gpu_addresses)
{
    uint64_t replay_addr = 0;
    auto     entry       = descriptor_gpu_addresses.lower_bound(handle.ptr);

    if (entry != descriptor_gpu_addresses.end())
    {
        auto info              = entry->second;
        auto type              = info->descriptor_type;
        auto start_addr        = info->capture_gpu_addr_begin;
        auto capture_increment = (*info->capture_increments)[type];
        auto replay_increment  = (*info->replay_increments)[type];

        // Check to see if the descriptor address is withing the range of the captured descriptor heap address
        // boundaries.
        if (info->capture_gpu_addr_end == 0)
        {
            // Compute the end address for the heap.
            auto size                  = capture_increment * info->descriptor_count;
            info->capture_gpu_addr_end = start_addr + size;
        }

        if (handle.ptr < info->capture_gpu_addr_end)
        {
            replay_addr = info->replay_gpu_addr_begin;

            // Compute offset from address.
            auto offset = handle.ptr - start_addr;
            if (offset > 0)
            {
                if (capture_increment == replay_increment)
                {
                    replay_addr += offset;
                }
                else
                {
                    replay_addr += (offset / capture_increment) * replay_increment;
                }
            }
        }
    }

    if (replay_addr != 0)
    {
        handle.ptr = replay_addr;
    }
    else
    {
        GFXRECON_LOG_FATAL("Failed to map GPU descriptor handle 0x%" PRIx64, handle.ptr);
    }
}

void MapGpuDescriptorHandles(D3D12_GPU_DESCRIPTOR_HANDLE* handles,
                             size_t                       handles_len,
                             const Dx12GpuDescriptorMap&  descriptor_gpu_addresses)
{
    for (size_t i = 0; i < handles_len; ++i)
    {
        MapGpuDescriptorHandle(handles[i], descriptor_gpu_addresses);
    }
}

void MapGpuVirtualAddress(D3D12_GPU_VIRTUAL_ADDRESS& address, const util::GpuVaMap& gpu_va_map)
{
    address = gpu_va_map.GetReplayGpuVa(address);
}

void MapGpuVirtualAddresses(D3D12_GPU_VIRTUAL_ADDRESS* addresses,
                            size_t                     addresses_len,
                            const util::GpuVaMap&      gpu_va_map)
{
    for (size_t i = 0; i < addresses_len; ++i)
    {
        MapGpuVirtualAddress(addresses[i], gpu_va_map);
    }
}

GFXRECON_END_NAMESPACE(object_mapping)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
