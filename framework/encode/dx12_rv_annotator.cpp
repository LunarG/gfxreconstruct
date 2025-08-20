/*
** Copyright (c) 2023 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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

#include "encode/d3d12_capture_manager.h"
#include "encode/dx12_rv_annotator.h"
#include "encode/dx12_rv_annotation_util.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void Dx12ResourceValueAnnotator::RemoveObjectGPUVA(IUnknown_Wrapper* wrapper)
{
    auto riid = wrapper->GetRiid();
    if (IsEqualGUID(riid, __uuidof(ID3D12Resource)) || IsEqualGUID(riid, __uuidof(ID3D12Resource1)) ||
        IsEqualGUID(riid, __uuidof(ID3D12Resource2)))
    {
        if (reinterpret_cast<ID3D12Resource_Wrapper*>(wrapper)->GetObjectInfo()->heap_wrapper == nullptr)
        {
            RemoveGPUVA(reinterpret_cast<ID3D12Resource_Wrapper*>(wrapper)->GetObjectInfo()->gpu_va);
        }
    }
    else if (IsEqualGUID(riid, __uuidof(ID3D12Heap)) || IsEqualGUID(riid, __uuidof(ID3D12Heap1)))
    {
        RemoveGPUVA(reinterpret_cast<ID3D12Heap_Wrapper*>(wrapper)->GetObjectInfo()->gpu_va);
    }
}

void Dx12ResourceValueAnnotator::AddNewRangeofGPUVA(uint64_t start_address, uint64_t end_address)
{
    if (low_gpuva == 0 || low_gpuva > start_address)
    {
        low_gpuva = start_address;
    }
    if (high_gpuva == 0 || high_gpuva < end_address)
    {
        high_gpuva = end_address;
    }
    auto gpuva = gpuva_map_.find(start_address);
    if (gpuva == gpuva_map_.end())
    {
#ifdef _DEBUG
        auto va_entry = gpuva_map_.lower_bound(start_address);
        if (va_entry != gpuva_map_.end())
        {
            _ASSERT(va_entry->second <= start_address);
        }
#endif
        gpuva_map_.insert(std::pair<uint64_t, uint64_t>(start_address, end_address));
    }
#ifdef _DEBUG
    else
    {
        _ASSERT(gpuva->second >= end_address);
    }
#endif
}

void Dx12ResourceValueAnnotator::SetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE type,
                                                                  uint8_t                    increment_size)
{
    increment_size_[type] = increment_size;
}

void Dx12ResourceValueAnnotator::AddDescriptorHandleStart(ID3D12DescriptorHeap_Wrapper* wrapper,
                                                          D3D12_GPU_DESCRIPTOR_HANDLE   result)
{

    uint8_t                            increment_size = 0;
    graphics::dx12::ID3D12DeviceComPtr device         = nullptr;
    D3D12_DESCRIPTOR_HEAP_DESC         desc           = wrapper->GetDesc();
    if (SUCCEEDED(wrapper->GetDevice(IID_PPV_ARGS(&device))))
    {
        increment_size = device->GetDescriptorHandleIncrementSize(desc.Type);
        if (result.ptr != 0)
        {
            if (low_handle == 0 || low_handle > result.ptr)
            {
                low_handle = result.ptr;
            }
            descriptor_map_.insert(std::pair<uint64_t, D3D12_DESCRIPTOR_HEAP_DESC>(result.ptr, desc));
            increment_size_[desc.Type] = increment_size;
            uint64_t end_handle        = result.ptr + (uint64_t)increment_size * desc.NumDescriptors;
            if (high_handle == 0 || high_handle < end_handle)
            {
                high_handle = end_handle;
            }
        }
    }
}

void Dx12ResourceValueAnnotator::AddShaderID(graphics::Dx12ShaderIdentifier shader_id)
{
    constexpr graphics::Dx12ShaderIdentifier zero_id = { 0 };
    if (shader_id != zero_id)
    {
        shader_ids_.insert(shader_id);
    }
}

void Dx12ResourceValueAnnotator::RemoveGPUVA(D3D12_GPU_VIRTUAL_ADDRESS start_address)
{
    auto va_entry = gpuva_map_.find(start_address);
    if (va_entry != gpuva_map_.end())
    {
        gpuva_map_.erase(start_address);
    }
}

bool Dx12ResourceValueAnnotator::IsValidGpuVa(D3D12_GPU_VIRTUAL_ADDRESS address)
{
    if (address >= low_gpuva && address <= high_gpuva)
    {
        auto va_entry = gpuva_map_.lower_bound(address);
        if (va_entry != gpuva_map_.end())
        {
            if (address < va_entry->second)
            {
                return true;
            }
        }
    }
    return false;
}

bool Dx12ResourceValueAnnotator::IsValidGPUDescriptorHandle(D3D12_GPU_DESCRIPTOR_HANDLE handle)
{
    if (handle.ptr >= low_handle && handle.ptr <= high_handle)
    {
        for (auto& it : descriptor_map_)
        {
            uint64_t diff = handle.ptr - it.first;
            if ((diff % increment_size_[it.second.Type]) == 0)
            {
                if (diff / increment_size_[it.second.Type] <= it.second.NumDescriptors)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Dx12ResourceValueAnnotator::MatchShaderIdentifier(const uint8_t* data)
{
    for (const auto& shader_id : shader_ids_)
    {
        bool match = true;
        for (uint64_t i = 0; (i < D3D12_SHADER_IDENTIFIER_SIZE_IN_BYTES - sizeof(uint64_t)) && match; ++i)
        {
            match = match && (shader_id.data()[i] == data[i]);
        }
        if (match)
        {
            return true;
        }
    }
    return false;
}

void Dx12ResourceValueAnnotator::PostProcessGetGPUVirtualAddress(ID3D12Resource_Wrapper*   wrapper,
                                                                 D3D12_GPU_VIRTUAL_ADDRESS result)
{
    static bool bCheckedGPUVABits = false;
    if (bCheckedGPUVABits == false)
    {
        ID3D12Device* device = nullptr;
        HRESULT       result = wrapper->GetDevice(IID_PPV_ARGS(&device));
        if (result == S_OK)
        {
            D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT feature_data{};
            device->CheckFeatureSupport(D3D12_FEATURE_GPU_VIRTUAL_ADDRESS_SUPPORT,
                                        &feature_data,
                                        sizeof(D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT));
            UINT maxGPUVAbits =
                feature_data.MaxGPUVirtualAddressBitsPerResource >= feature_data.MaxGPUVirtualAddressBitsPerProcess
                    ? feature_data.MaxGPUVirtualAddressBitsPerResource
                    : feature_data.MaxGPUVirtualAddressBitsPerProcess;
            if (maxGPUVAbits <= (64 - RvAnnotationUtil::kMaskSizeOfBits))
            {
                bCheckedGPUVABits = true;
            }
            else
            {
                GFXRECON_LOG_ERROR_ONCE("Insufficient bits available in GPUVA for RV annotation");
            }
            device->Release();
        }
    }

    auto resource_info = wrapper->GetObjectInfo();
    if (resource_info->dimension == D3D12_RESOURCE_DIMENSION_BUFFER)
    {
        uint64_t width        = resource_info->subresource_sizes[0];
        resource_info->gpu_va = result;
        if (resource_info->heap_wrapper != nullptr)
        {
            auto heap_info    = resource_info->heap_wrapper->GetObjectInfo();
            heap_info->gpu_va = result - resource_info->heap_offset;
            width             = heap_info->heap_size;
        }
        AddNewRangeofGPUVA(result - resource_info->heap_offset, result - resource_info->heap_offset + width);
    }
}

static size_t GetResourceValueSize(format::ResourceValueType type)
{
    switch (type)
    {
        case format::ResourceValueType::kGpuVirtualAddress:
            return sizeof(D3D12_GPU_VIRTUAL_ADDRESS);
        case format::ResourceValueType::kGpuDescriptorHandle:
            return sizeof(D3D12_GPU_DESCRIPTOR_HANDLE::ptr);
        case format::ResourceValueType::kShaderIdentifier:
            return D3D12_SHADER_IDENTIFIER_SIZE_IN_BYTES;
        default:
            GFXRECON_ASSERT(false && "Unrecognized resource value type.");
            return 0;
    }
}

void Dx12ResourceValueAnnotator::ScanForGPUVA(uint64_t memory_id, uint8_t* data, uint64_t size, uint64_t offset)
{
    std::map<uint64_t, Dx12FillCommandResourceValue> resource_values;
    auto                                             manager                      = D3D12CaptureManager::Get();
    auto&                                            existing_resource_values_map = resource_values_map_[memory_id];

    if (size >= sizeof(uint64_t))
    {
        constexpr uint64_t stride = 4;
        for (uint64_t index = 0; index <= size - sizeof(uint64_t); index += stride)
        {
            // check if data contains a previously identified RV
            if (existing_resource_values_map.count(index + offset) > 0)
            {
                auto& existing_rv_data = existing_resource_values_map[index + offset];
                auto  existing_rv_size = GetResourceValueSize(existing_rv_data.type);
                bool  match            = true;
                for (size_t i = 0; i < existing_rv_size && (index + i) < size; ++i)
                {
                    if (existing_rv_data.value[i] != data[index + i])
                    {
                        match = false;
                        break;
                    }
                }
                if (match)
                {
                    resource_values[index + offset] = existing_rv_data;
                    index += existing_rv_size - stride;
                    continue;
                }
            }

            if (index <= size - D3D12_SHADER_IDENTIFIER_SIZE_IN_BYTES)
            {
                uint64_t shader_id_mask;
                memcpy(&shader_id_mask, data + index + 3 * sizeof(uint64_t), sizeof(uint64_t));
                if (shader_id_mask == manager->GetShaderIDMask())
                {
                    if (MatchShaderIdentifier(data + index))
                    {
                        Dx12FillCommandResourceValue rv = { index + offset,
                                                            format::ResourceValueType::kShaderIdentifier };
                        std::memcpy(rv.value.data(),
                                    data + index,
                                    GetResourceValueSize(format::ResourceValueType::kShaderIdentifier));

                        resource_values[index + offset] = std::move(rv);

                        index += D3D12_SHADER_IDENTIFIER_SIZE_IN_BYTES - stride;
                        continue;
                    }
                }
            }

            uint64_t data_value;
            memcpy(&data_value, data + index, sizeof(uint64_t));
            if (data_value != 0x0)
            {
                uint64_t mask = data_value >> (64 - RvAnnotationUtil::kMaskSizeOfBits);
                if (mask == manager->GetGPUVAMask())
                {
                    uint64_t gpu_va = data_value & (~0x0ui64 >> RvAnnotationUtil::kMaskSizeOfBits);
                    if (gpu_va != 0x0 && IsValidGpuVa(data_value) == true)
                    {
                        Dx12FillCommandResourceValue rv = { index + offset,
                                                            format::ResourceValueType::kGpuVirtualAddress };
                        std::memcpy(rv.value.data(),
                                    data + index,
                                    GetResourceValueSize(format::ResourceValueType::kGpuVirtualAddress));

                        resource_values[index + offset] = std::move(rv);
                        index += sizeof(uint64_t) - stride;
                    }
                }
                else if (mask == manager->GetDescriptorMask())
                {
                    uint64_t gpu_desc_ptr              = data_value & (~0x0ui64 >> RvAnnotationUtil::kMaskSizeOfBits);
                    D3D12_GPU_DESCRIPTOR_HANDLE handle = { data_value };
                    if (handle.ptr != 0x0 && IsValidGPUDescriptorHandle(handle) == true)
                    {
                        Dx12FillCommandResourceValue rv = { index + offset,
                                                            format::ResourceValueType::kGpuDescriptorHandle };
                        std::memcpy(rv.value.data(),
                                    data + index,
                                    GetResourceValueSize(format::ResourceValueType::kGpuDescriptorHandle));

                        resource_values[index + offset] = std::move(rv);
                        index += sizeof(uint64_t) - stride;
                    }
                }
            }
        }
    }

    auto lower_iter = existing_resource_values_map.lower_bound(offset);
    auto upper_iter = existing_resource_values_map.upper_bound(offset + size);
    existing_resource_values_map.erase(lower_iter, upper_iter);

    if (resource_values.size() > 0)
    {
        manager->AddFillMemoryResourceValueCommand(resource_values);
        existing_resource_values_map.insert(resource_values.begin(), resource_values.end());
    }
}

bool Dx12ResourceValueAnnotator::RestoreForGPUVA(uint64_t memory_id, uint8_t* data, uint64_t size, uint64_t offset)
{
    bool memory_modified = false;
    auto manager         = D3D12CaptureManager::Get();

    if (size >= sizeof(uint64_t))
    {
        constexpr uint64_t stride = 4;
        for (uint64_t index = 0; index <= (size - sizeof(uint64_t)); index += stride)
        {
            uint64_t data_value;
            std::memcpy(&data_value, data + index, sizeof(uint64_t));
            if (data_value != 0x0)
            {
                uint64_t mask = data_value >> (64 - RvAnnotationUtil::kMaskSizeOfBits);
                if (mask == manager->GetGPUVAMask())
                {
                    uint64_t gpu_va = data_value & (~0x0ui64 >> RvAnnotationUtil::kMaskSizeOfBits);
                    if ((gpu_va != 0x0) && (IsValidGpuVa(data_value) == true))
                    {
                        memory_modified = true;
                        std::memcpy(data + index, &gpu_va, sizeof(uint64_t));
                        index += sizeof(uint64_t) - stride;
                    }
                }
                else if (mask == manager->GetDescriptorMask())
                {
                    uint64_t gpu_desc_ptr              = data_value & (~0x0ui64 >> RvAnnotationUtil::kMaskSizeOfBits);
                    D3D12_GPU_DESCRIPTOR_HANDLE handle = { data_value };
                    if ((handle.ptr != 0x0) && (IsValidGPUDescriptorHandle(handle) == true))
                    {
                        memory_modified = true;
                        std::memcpy(data + index, &gpu_desc_ptr, sizeof(uint64_t));
                        index += sizeof(uint64_t) - stride;
                    }
                }
            }

            if (index <= size - D3D12_SHADER_IDENTIFIER_SIZE_IN_BYTES)
            {
                uint64_t shader_id_mask;
                uint32_t shader_id_mask_offset = D3D12_SHADER_IDENTIFIER_SIZE_IN_BYTES - sizeof(uint64_t);
                std::memcpy(&shader_id_mask, data + index + shader_id_mask_offset, sizeof(uint64_t));
                if (shader_id_mask == manager->GetShaderIDMask())
                {
                    if (MatchShaderIdentifier(data + index))
                    {
                        memory_modified = true;
                        std::memset(data + index + shader_id_mask_offset, 0x0, sizeof(uint64_t));
                        index += D3D12_SHADER_IDENTIFIER_SIZE_IN_BYTES - stride;
                    }
                }
            }
        }
    }

    if (memory_modified == true)
    {
        if (ResetWriteWatch(data, size) != 0)
        {
            GFXRECON_LOG_ERROR("PageGuardManager failed to reset write-modified pages for memory region.");
        }
    }

    return memory_modified;
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
