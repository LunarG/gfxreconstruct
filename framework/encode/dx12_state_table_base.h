/*
** Copyright (c) 2021 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_DX12_STATE_TABLE_BASE_H
#define GFXRECON_DX12_STATE_TABLE_BASE_H

#include "format/format.h"
#include "generated/generated_dx12_wrappers.h"
#include "graphics/dx12_gpu_va_map.h"
#include "util/defines.h"

#include <functional>
#include <map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class Dx12StateTableBase
{
  public:
    Dx12StateTableBase() {}

    ~Dx12StateTableBase() {}

    void AddResourceGpuVa(ID3D12Resource_Wrapper* resource_wrapper, D3D12_GPU_VIRTUAL_ADDRESS address)
    {
        gpu_va_map_.Add(resource_wrapper->GetCaptureId(), address, resource_wrapper->GetDesc().Width, address);
    }

    // Returns the handle ID for the resource that contains the GPU VA address or kNullHandleId if no match is found.
    format::HandleId GetResourceForGpuVa(D3D12_GPU_VIRTUAL_ADDRESS          address,
                                         uint64_t                           minimum_end_address,
                                         graphics::ResourceMatchFunctionPtr resource_match_func = nullptr)
    {
        bool             found  = false;
        format::HandleId result = format::kNullHandleId;
        gpu_va_map_.Map(address, &result, &found, minimum_end_address, resource_match_func);
        return result;
    }

  protected:
    template <typename T>
    bool InsertEntry(format::HandleId id, T* wrapper, std::map<format::HandleId, T*>& map)
    {
        const auto& inserted = map.insert(std::make_pair(id, wrapper));
        return inserted.second;
    }

    template <typename Wrapper>
    bool RemoveEntry(const Wrapper* wrapper, std::map<format::HandleId, Wrapper*>& map)
    {
        assert(wrapper != nullptr);
        return (map.erase(wrapper->GetCaptureId()) != 0);
    }

    template <typename T>
    T* GetWrapper(format::HandleId id, std::map<format::HandleId, T*>& map)
    {
        auto entry = map.find(id);
        return (entry != map.end()) ? entry->second : nullptr;
    }

    template <typename T>
    const T* GetWrapper(format::HandleId id, const std::map<format::HandleId, T*>& map) const
    {
        auto entry = map.find(id);
        return (entry != map.end()) ? entry->second : nullptr;
    }

    // Specializations:
    template <>
    bool RemoveEntry(const ID3D12Resource_Wrapper* wrapper, std::map<format::HandleId, ID3D12Resource_Wrapper*>& map)
    {
        GFXRECON_ASSERT(wrapper != nullptr);
        if (wrapper->GetObjectInfo()->gpu_va != 0)
        {
            gpu_va_map_.Remove(wrapper->GetCaptureId(), wrapper->GetObjectInfo()->gpu_va);
        }
        return (map.erase(wrapper->GetCaptureId()) != 0);
    }

  private:
    graphics::Dx12GpuVaMap gpu_va_map_; ///< Used to map GPU VAs to the containing resource's handle.
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DX12_STATE_TABLE_BASE_H
