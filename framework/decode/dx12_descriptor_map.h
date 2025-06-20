/*
** Copyright (c) 2022 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_DX12_DESCRIPTOR_MAP_H
#define GFXRECON_DECODE_DX12_DESCRIPTOR_MAP_H

#include "format/format.h"

#include <d3d12.h>

#include <array>
#include <map>
#include <memory>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

typedef std::array<UINT, D3D12_DESCRIPTOR_HEAP_TYPE_NUM_TYPES> DescriptorIncrements;

class Dx12DescriptorMap
{
  public:
    static const size_t   kNullCpuAddress = 0;
    static const uint64_t kNullGpuAddress = 0;

    Dx12DescriptorMap(const Dx12DescriptorMap&) = delete;
    Dx12DescriptorMap& operator=(const Dx12DescriptorMap&) = delete;

    Dx12DescriptorMap() = default;

    Dx12DescriptorMap(Dx12DescriptorMap&&) noexcept = default;
    Dx12DescriptorMap& operator=(Dx12DescriptorMap&&) noexcept = default;

    void AddCpuDescriptorHeap(const D3D12_CPU_DESCRIPTOR_HANDLE&     capture_cpu_start,
                              const D3D12_CPU_DESCRIPTOR_HANDLE&     replay_cpu_start,
                              D3D12_DESCRIPTOR_HEAP_TYPE             heap_info_descriptor_type,
                              uint32_t                               heap_info_descriptor_count,
                              std::shared_ptr<DescriptorIncrements>& heap_info_capture_increments,
                              std::shared_ptr<DescriptorIncrements>& heap_info_replay_increments);

    void AddGpuDescriptorHeap(const D3D12_GPU_DESCRIPTOR_HANDLE&     capture_gpu_start,
                              const D3D12_GPU_DESCRIPTOR_HANDLE&     replay_gpu_start,
                              D3D12_DESCRIPTOR_HEAP_TYPE             heap_info_descriptor_type,
                              uint32_t                               heap_info_descriptor_count,
                              std::shared_ptr<DescriptorIncrements>& heap_info_capture_increments,
                              std::shared_ptr<DescriptorIncrements>& heap_info_replay_increments);

    void GetCpuAddress(D3D12_CPU_DESCRIPTOR_HANDLE& descriptor) const;

    void GetGpuAddress(D3D12_GPU_DESCRIPTOR_HANDLE& descriptor, bool* found = nullptr) const;

    void RemoveCpuDescriptorHeap(const size_t capture_cpu_addr_begin);

    void RemoveGpuDescriptorHeap(const uint64_t capture_gpu_addr_begin);

  private:
    template <typename T1, typename T2>
    bool Get(T1& handle, T2& descriptor_addresses) const
    {
        T1   replay_addr = 0;
        auto entry       = descriptor_addresses.lower_bound(handle);

        if (entry != descriptor_addresses.end())
        {
            auto info = entry->second;

            assert(info.capture_begin == entry->first);

            // Skip the offset calculation when the target address matches the heap start address.
            if (handle == info.capture_begin)
            {
                replay_addr = info.replay_begin;
            }
            else
            {
                auto type              = info.descriptor_type;
                auto start_addr        = info.capture_begin;
                auto capture_increment = (*info.capture_increments)[type];
                auto replay_increment  = (*info.replay_increments)[type];

                // Check to see if the descriptor address is within the range of the captured descriptor heap address
                // boundaries.
                if (info.capture_end == 0)
                {
                    // Compute the end address for the heap.
                    auto size        = capture_increment * info.descriptor_count;
                    info.capture_end = start_addr + size;
                }

                if (handle < info.capture_end)
                {
                    replay_addr = info.replay_begin;

                    // Compute offset from address.
                    auto offset = handle - start_addr;
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
            handle = replay_addr;
            return true;
        }
        return false;
    }

    template <typename T>
    struct HeapInfo
    {
        T                                     capture_begin;
        T                                     capture_end;
        T                                     replay_begin;
        D3D12_DESCRIPTOR_HEAP_TYPE            descriptor_type;
        uint32_t                              descriptor_count;
        std::shared_ptr<DescriptorIncrements> capture_increments;
        std::shared_ptr<DescriptorIncrements> replay_increments;
    };

    std::map<size_t, HeapInfo<size_t>, std::greater<size_t>>       descriptor_cpu_addresses_;
    std::map<uint64_t, HeapInfo<uint64_t>, std::greater<uint64_t>> descriptor_gpu_addresses_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_DESCRIPTOR_MAP_H
