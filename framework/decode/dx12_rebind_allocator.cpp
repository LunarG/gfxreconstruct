/*
** Copyright (c) 2025 LunarG, Inc.
** Copyright (c) 2025 Arm Limited and/or its affiliates <open-source-office@arm.com>
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

#include "decode/dx12_rebind_allocator.h"
#include "graphics/dx12_util.h"
#include "util/logging.h"
#include "util/options.h"
#include "util/platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

Dx12RebindAllocator::Dx12RebindAllocator() : allocator_(nullptr), device_(nullptr), enable_as_committed_(true) {}

HRESULT Dx12RebindAllocator::Initialize(const IUnknown* adapter, const void* pvDevice)
{
    device_                      = reinterpret_cast<ID3D12Device*>(const_cast<void*>(pvDevice));
    D3D12MA::ALLOCATOR_DESC desc = {};
    desc.pDevice                 = reinterpret_cast<ID3D12Device*>(const_cast<void*>(pvDevice));
    desc.pAdapter                = reinterpret_cast<IDXGIAdapter*>(const_cast<IUnknown*>(adapter));
    desc.Flags = D3D12MA_RECOMMENDED_ALLOCATOR_FLAGS | D3D12MA::ALLOCATOR_FLAG_DONT_USE_TIGHT_ALIGNMENT;

    GFXRECON_LOG_INFO_ONCE("Replay with D3D12 rebind memory translation.");
    HRESULT result = D3D12MA::CreateAllocator(&desc, &allocator_);

    std::string env_value = gfxrecon::util::platform::GetEnv("GFXRECON_ACCEL_STRUCT_COMMITTED");
    enable_as_committed_  = gfxrecon::util::ParseBoolString(env_value, true);

    return result;
}

void Dx12RebindAllocator::Destroy()
{
    // The order of release is Resource->allocation->custom pool
    for (auto& alloc : resource_id_allocation_)
    {
        alloc.second.Reset();
    }
    resource_id_allocation_.clear();

    for (auto& [heap_id, offset_map] : heap_id_offset_aliasing_allocation_)
    {
        for (auto& [offset, alloc] : offset_map)
        {
            alloc.Reset();
        }
    }
    heap_id_offset_aliasing_allocation_.clear();

    for (auto& pool : heap_id_custom_pool_)
    {
        pool.second.Reset();
    }
    heap_id_custom_pool_.clear();

    for (auto& recreated_heap : resource_id_recreated_heap_)
    {
        for (auto& heap : recreated_heap.second)
        {
            heap.Reset();
        }
    }
    resource_id_recreated_heap_.clear();

    for (auto& heap : heap_id_recreated_heap_)
    {
        heap.second.Reset();
    }
    heap_id_recreated_heap_.clear();

    if (allocator_ != nullptr)
    {
        allocator_.Reset();
    }

    device_ = nullptr;
}

D3D12_HEAP_PROPERTIES
Dx12RebindAllocator::GetReplayCustomHeapProperties(const D3D12_CPU_PAGE_PROPERTY cpu_page_property)
{
    D3D12_HEAP_PROPERTIES heap_props;
    if (cpu_page_property == D3D12_CPU_PAGE_PROPERTY_WRITE_BACK)
    {
        heap_props = device_->GetCustomHeapProperties(1, D3D12_HEAP_TYPE_READBACK);
    }
    else if (cpu_page_property == D3D12_CPU_PAGE_PROPERTY_WRITE_COMBINE)
    {
        heap_props = device_->GetCustomHeapProperties(1, D3D12_HEAP_TYPE_UPLOAD);
    }
    else
    {
        heap_props = device_->GetCustomHeapProperties(1, D3D12_HEAP_TYPE_DEFAULT);
    }

    return heap_props;
}

void Dx12RebindAllocator::SetReplayResourceCompatibility(const format::HandleId    heap_capture_id,
                                                         const ID3D12Heap*         heap,
                                                         const UINT64              Heap_offset,
                                                         D3D12_RESOURCE_DESC1*     resource_desc,
                                                         D3D12MA::ALLOCATION_DESC& allocation_desc)
{
    assert(resource_desc != nullptr);
    const_cast<D3D12_RESOURCE_DESC1*>(resource_desc)->Alignment = 0;

    assert(heap != nullptr);
    allocation_desc.Flags = D3D12MA::ALLOCATION_FLAGS::ALLOCATION_FLAG_NONE;

    if (heap_id_desc_.find(heap_capture_id) == heap_id_desc_.end())
    {
        D3D12_HEAP_DESC heap_desc = const_cast<ID3D12Heap*>(heap)->GetDesc();
        heap_id_desc_.insert_or_assign(heap_capture_id, heap_desc);
    }

    // remove SHARED and SHARED_CROSS_ADAPTER flags that are not allowed on real heaps
    heap_id_desc_[heap_capture_id].Flags &= ~(D3D12_HEAP_FLAG_SHARED | D3D12_HEAP_FLAG_SHARED_CROSS_ADAPTER);
    resource_desc->Flags &= ~D3D12_RESOURCE_FLAG_ALLOW_CROSS_ADAPTER;

    D3D12_FEATURE_DATA_D3D12_OPTIONS opts = {};
    if (SUCCEEDED(device_->CheckFeatureSupport(D3D12_FEATURE_D3D12_OPTIONS, &opts, sizeof(opts))))
    {
        if (opts.ResourceHeapTier == D3D12_RESOURCE_HEAP_TIER_1)
        {
            if ((heap_id_desc_[heap_capture_id].Flags &
                 (D3D12_HEAP_FLAG_DENY_BUFFERS | D3D12_HEAP_FLAG_DENY_RT_DS_TEXTURES |
                  D3D12_HEAP_FLAG_DENY_NON_RT_DS_TEXTURES)) == 0)
            {
                GFXRECON_LOG_WARNING("Adding DENY_RT_DS_TEXTURES|DENY_NON_RT_DS_TEXTURES to OpenExistingHeap heap "
                                     "for tier 1 compatibility");
                heap_id_desc_[heap_capture_id].Flags |=
                    (D3D12_HEAP_FLAG_DENY_RT_DS_TEXTURES | D3D12_HEAP_FLAG_DENY_NON_RT_DS_TEXTURES);
            }
        }
    }

    allocation_desc.HeapType       = heap_id_desc_[heap_capture_id].Properties.Type;
    allocation_desc.ExtraHeapFlags = heap_id_desc_[heap_capture_id].Flags;

    if (allocation_desc.HeapType == D3D12_HEAP_TYPE_CUSTOM)
    {
        auto                  cpu_page_property = heap_id_desc_[heap_capture_id].Properties.CPUPageProperty;
        D3D12_HEAP_PROPERTIES heap_properties   = GetReplayCustomHeapProperties(cpu_page_property);
        D3D12_HEAP_FLAGS      heap_flags        = heap_id_desc_[heap_capture_id].Flags;

        ComPtr<D3D12MA::Pool> custom_pool = nullptr;
        D3D12MA::CPOOL_DESC   pool_desc{ heap_properties, heap_flags };

        if (heap_id_custom_pool_.find(heap_capture_id) != heap_id_custom_pool_.end())
        {
            allocation_desc.CustomPool = heap_id_custom_pool_[heap_capture_id].Get();
        }
        else
        {
            if (S_OK == allocator_->CreatePool(&pool_desc, &custom_pool))
            {
                allocation_desc.CustomPool = custom_pool.Get();
                heap_id_custom_pool_.insert_or_assign(heap_capture_id, std::move(custom_pool));
            }
            else
            {
                GFXRECON_LOG_FATAL("Failed to create custom pool for for resource using D3D12_HEAP_TYPE_CUSTOM!");
            }
        }
    }

    // prevent it creating with `CreateCommittedResource` for ALLOW_SHADER_ATOMICS flag
    if ((allocation_desc.ExtraHeapFlags & D3D12_HEAP_FLAG_ALLOW_SHADER_ATOMICS) != 0 &&
        (resource_desc->Flags & D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS) == 0)
    {
        allocation_desc.ExtraHeapFlags &= ~D3D12_HEAP_FLAG_ALLOW_SHADER_ATOMICS;
    }

    // don't create resources non-resident
    allocation_desc.ExtraHeapFlags &= ~D3D12_HEAP_FLAG_CREATE_NOT_RESIDENT;
}

D3D12_RESOURCE_ALLOCATION_INFO
Dx12RebindAllocator::GetReplayResourceDescAllocationInfo1(const D3D12_RESOURCE_DESC* resource_desc)
{
    D3D12_RESOURCE_ALLOCATION_INFO  alloc_info  = {};
    D3D12_RESOURCE_ALLOCATION_INFO1 alloc_info1 = {};

    if (device_ != nullptr)
    {
        graphics::dx12::ID3D12Device4ComPtr device4;
        device_->QueryInterface(IID_PPV_ARGS(&device4));

        if (device4 != nullptr)
        {
            alloc_info = device4->GetResourceAllocationInfo1(0, 1, resource_desc, &alloc_info1);
        }
        else
        {
            alloc_info = device_->GetResourceAllocationInfo(0, 1, resource_desc);
        }

        // Alignment is set to 0, the runtime will set it to the correct value
        const_cast<D3D12_RESOURCE_DESC*>(resource_desc)->Alignment = 0;

        if (resource_desc->Dimension == D3D12_RESOURCE_DIMENSION_BUFFER)
        {
            if (alloc_info.SizeInBytes && alloc_info.SizeInBytes != resource_desc->Width)
            {
                const_cast<D3D12_RESOURCE_DESC*>(resource_desc)->Width = alloc_info.SizeInBytes;
            }
        }
    }

    return alloc_info;
}

D3D12_RESOURCE_ALLOCATION_INFO
Dx12RebindAllocator::GetReplayResourceDescAllocationInfo2(const D3D12_RESOURCE_DESC1* resource_desc)
{
    D3D12_RESOURCE_ALLOCATION_INFO  alloc_info  = {};
    D3D12_RESOURCE_ALLOCATION_INFO1 alloc_info1 = {};

    if (device_ != nullptr)
    {
        graphics::dx12::ID3D12Device4ComPtr device4;
        device_->QueryInterface(IID_PPV_ARGS(&device4));

        graphics::dx12::ID3D12Device8ComPtr device8;
        device_->QueryInterface(IID_PPV_ARGS(&device8));

        if (device8 != nullptr)
        {
            alloc_info = device8->GetResourceAllocationInfo2(0, 1, resource_desc, &alloc_info1);
        }
        else if (device4 != nullptr)
        {
            D3D12_RESOURCE_DESC* desc =
                reinterpret_cast<D3D12_RESOURCE_DESC*>(const_cast<D3D12_RESOURCE_DESC1*>(resource_desc));
            alloc_info = device4->GetResourceAllocationInfo1(0, 1, desc, &alloc_info1);
        }
        else
        {
            D3D12_RESOURCE_DESC* desc =
                reinterpret_cast<D3D12_RESOURCE_DESC*>(const_cast<D3D12_RESOURCE_DESC1*>(resource_desc));
            alloc_info = device_->GetResourceAllocationInfo(0, 1, desc);
        }

        // Alignment is set to 0, the runtime will set it to the correct value
        const_cast<D3D12_RESOURCE_DESC1*>(resource_desc)->Alignment = 0;

        if (resource_desc->Dimension == D3D12_RESOURCE_DIMENSION_BUFFER)
        {
            if (alloc_info.SizeInBytes && alloc_info.SizeInBytes != resource_desc->Width)
            {
                const_cast<D3D12_RESOURCE_DESC1*>(resource_desc)->Width = alloc_info.SizeInBytes;
            }
        }
    }

    return alloc_info;
}

D3D12_RESOURCE_ALLOCATION_INFO
Dx12RebindAllocator::GetReplayResourceDescAllocationInfo3(const D3D12_RESOURCE_DESC1* resource_desc,
                                                          const UINT32                num_castable_formats,
                                                          const DXGI_FORMAT*          castable_formats)
{
    D3D12_RESOURCE_ALLOCATION_INFO  alloc_info  = {};
    D3D12_RESOURCE_ALLOCATION_INFO1 alloc_info1 = {};

    if (device_ != nullptr)
    {
        graphics::dx12::ID3D12Device4ComPtr device4;
        device_->QueryInterface(IID_PPV_ARGS(&device4));

        graphics::dx12::ID3D12Device8ComPtr device8;
        device_->QueryInterface(IID_PPV_ARGS(&device8));

        graphics::dx12::ID3D12Device12ComPtr device12;
        device_->QueryInterface(IID_PPV_ARGS(&device12));

        if ((device12 != nullptr) && (num_castable_formats > 0) && (castable_formats != nullptr))
        {
            alloc_info = device12->GetResourceAllocationInfo3(
                0, 1, resource_desc, &num_castable_formats, &castable_formats, &alloc_info1);
        }
        else if (device8 != nullptr)
        {
            alloc_info = device8->GetResourceAllocationInfo2(0, 1, resource_desc, &alloc_info1);
        }
        else if (device4 != nullptr)
        {
            D3D12_RESOURCE_DESC* desc =
                reinterpret_cast<D3D12_RESOURCE_DESC*>(const_cast<D3D12_RESOURCE_DESC1*>(resource_desc));
            alloc_info = device4->GetResourceAllocationInfo1(0, 1, desc, &alloc_info1);
        }
        else
        {
            D3D12_RESOURCE_DESC* desc =
                reinterpret_cast<D3D12_RESOURCE_DESC*>(const_cast<D3D12_RESOURCE_DESC1*>(resource_desc));
            alloc_info = device_->GetResourceAllocationInfo(0, 1, desc);
        }

        // Alignment is set to 0, the runtime will set it to the correct value
        const_cast<D3D12_RESOURCE_DESC1*>(resource_desc)->Alignment = 0;

        if (resource_desc->Dimension == D3D12_RESOURCE_DIMENSION_BUFFER)
        {
            if (alloc_info.SizeInBytes && alloc_info.SizeInBytes != resource_desc->Width)
            {
                const_cast<D3D12_RESOURCE_DESC1*>(resource_desc)->Width = alloc_info.SizeInBytes;
            }
        }
    }

    return alloc_info;
}

ULONG Dx12RebindAllocator::Release(IUnknown* object, format::HandleId object_id)
{
    // The order of release is Resource->allocation->custom pool
    if (resource_id_allocation_.find(object_id) != resource_id_allocation_.end())
    {
        resource_id_allocation_[object_id] = nullptr;
        resource_id_allocation_.erase(object_id);
    }

    if (heap_id_offset_aliasing_allocation_.count(object_id))
    {
        heap_id_offset_aliasing_allocation_.erase(object_id);
    }

    if (heap_id_custom_pool_.find(object_id) != heap_id_custom_pool_.end())
    {
        heap_id_custom_pool_[object_id] = nullptr;
        heap_id_custom_pool_.erase(object_id);
    }

    if (resource_id_recreated_heap_.find(object_id) != resource_id_recreated_heap_.end())
    {
        resource_id_recreated_heap_[object_id].clear();
        resource_id_recreated_heap_.erase(object_id);
    }

    if (heap_id_recreated_heap_.find(object_id) != heap_id_recreated_heap_.end())
    {
        heap_id_recreated_heap_[object_id] = nullptr;
        heap_id_recreated_heap_.erase(object_id);
    }

    return 0;
}

HRESULT Dx12RebindAllocator::CreateHeap(format::HandleId            capture_id,
                                        _In_ const D3D12_HEAP_DESC* pDesc,
                                        REFIID                      riid,
                                        _COM_Outptr_opt_ void**     ppvHeap)
{
    if (pDesc == nullptr)
    {
        return E_INVALIDARG;
    }

    if (pDesc->Properties.Type == D3D12_HEAP_TYPE_CUSTOM)
    {
        D3D12_HEAP_PROPERTIES heap_props = GetReplayCustomHeapProperties(pDesc->Properties.CPUPageProperty);
        if (heap_props.CPUPageProperty == D3D12_CPU_PAGE_PROPERTY_NOT_AVAILABLE)
        {
            // The capture may use MemoryPoolPreference L0, so set it to L0 for compatibility.
            heap_props.MemoryPoolPreference = (pDesc->Properties.MemoryPoolPreference == D3D12_MEMORY_POOL_L0)
                                                  ? D3D12_MEMORY_POOL_L0
                                                  : heap_props.MemoryPoolPreference;
        }
        const_cast<D3D12_HEAP_DESC*>(pDesc)->Properties = heap_props;
    }

    heap_id_desc_.insert_or_assign(capture_id, *pDesc);
    // D3D12 spec: If tile mapping of reserved resources is used with a shared heap, the obtained heap reference is
    // opened via CreateSharedHandle and OpenSharedHandle. This class does not support OpenSharedHandle.
    if ((pDesc->Flags & D3D12_HEAP_FLAG_SHARED) != D3D12_HEAP_FLAG_SHARED)
    {
        const_cast<D3D12_HEAP_DESC*>(pDesc)->SizeInBytes = D3D12_SMALL_RESOURCE_PLACEMENT_ALIGNMENT;
    }

    HRESULT result = device_->CreateHeap(pDesc, riid, ppvHeap);

    return result;
}

HRESULT Dx12RebindAllocator::CreateHeap1(format::HandleId                         capture_id,
                                         _In_ const D3D12_HEAP_DESC*              pDesc,
                                         _In_opt_ ID3D12ProtectedResourceSession* pProtectedSession,
                                         REFIID                                   riid,
                                         _COM_Outptr_opt_ void**                  ppvHeap)
{
    if (pDesc == nullptr)
    {
        return E_INVALIDARG;
    }

    if (pDesc->Properties.Type == D3D12_HEAP_TYPE_CUSTOM)
    {
        D3D12_HEAP_PROPERTIES heap_props = GetReplayCustomHeapProperties(pDesc->Properties.CPUPageProperty);
        if (heap_props.CPUPageProperty == D3D12_CPU_PAGE_PROPERTY_NOT_AVAILABLE)
        {
            // The capture may use MemoryPoolPreference L0, so set it to L0 for compatibility.
            heap_props.MemoryPoolPreference = (pDesc->Properties.MemoryPoolPreference == D3D12_MEMORY_POOL_L0)
                                                  ? D3D12_MEMORY_POOL_L0
                                                  : heap_props.MemoryPoolPreference;
        }
        const_cast<D3D12_HEAP_DESC*>(pDesc)->Properties = heap_props;
    }

    heap_id_desc_.insert_or_assign(capture_id, *pDesc);
    // D3D12 spec: If tile mapping of reserved resources is used with a shared heap, the obtained heap reference is
    // opened via CreateSharedHandle and OpenSharedHandle. This class does not support OpenSharedHandle.
    if ((pDesc->Flags & D3D12_HEAP_FLAG_SHARED) != D3D12_HEAP_FLAG_SHARED)
    {
        const_cast<D3D12_HEAP_DESC*>(pDesc)->SizeInBytes = D3D12_SMALL_RESOURCE_PLACEMENT_ALIGNMENT;
    }

    graphics::dx12::ID3D12Device4ComPtr device4;
    device_->QueryInterface(IID_PPV_ARGS(&device4));
    HRESULT result = device4->CreateHeap1(pDesc, pProtectedSession, riid, ppvHeap);

    return result;
}

HRESULT Dx12RebindAllocator::CreateCommittedResource(_In_ const D3D12_HEAP_PROPERTIES* pHeapProperties,
                                                     D3D12_HEAP_FLAGS                  HeapFlags,
                                                     _In_ const D3D12_RESOURCE_DESC*   pDesc,
                                                     D3D12_RESOURCE_STATES             InitialResourceState,
                                                     _In_opt_ const D3D12_CLEAR_VALUE* pOptimizedClearValue,
                                                     REFIID                            riidResource,
                                                     HandlePointerDecoder<void*>*      ppvResource)
{
    HRESULT                     result     = S_FALSE;
    ComPtr<D3D12MA::Allocation> allocation = nullptr;
    D3D12MA::ALLOCATION_DESC    alloc_desc = {};

    // don't create resources non-resident
    HeapFlags &= ~D3D12_HEAP_FLAG_CREATE_NOT_RESIDENT;
    GetReplayResourceDescAllocationInfo1(pDesc);

    if (pHeapProperties->Type == D3D12_HEAP_TYPE_CUSTOM)
    {
        if (device_ != nullptr)
        {
            D3D12_HEAP_PROPERTIES heap_props = GetReplayCustomHeapProperties(pHeapProperties->CPUPageProperty);

            result = device_->CreateCommittedResource(&heap_props,
                                                      HeapFlags,
                                                      pDesc,
                                                      InitialResourceState,
                                                      pOptimizedClearValue,
                                                      riidResource,
                                                      ppvResource->GetHandlePointer());
        }
    }
    else
    {
        if (allocator_ != nullptr)
        {
            alloc_desc.Flags          = D3D12MA::ALLOCATION_FLAGS::ALLOCATION_FLAG_COMMITTED;
            alloc_desc.HeapType       = pHeapProperties->Type;
            alloc_desc.ExtraHeapFlags = HeapFlags;

            result = allocator_->CreateResource(&alloc_desc,
                                                pDesc,
                                                InitialResourceState,
                                                pOptimizedClearValue,
                                                &allocation,
                                                riidResource,
                                                ppvResource->GetHandlePointer());

            if (SUCCEEDED(result))
            {
                auto resource_id = *(ppvResource->GetPointer());
                resource_id_allocation_.insert_or_assign(resource_id, std::move(allocation));
            }
        }
    }

    return result;
}

HRESULT Dx12RebindAllocator::CreatePlacedResource(format::HandleId                  heap_capture_id,
                                                  _In_ ID3D12Heap*                  pHeap,
                                                  UINT64                            HeapOffset,
                                                  _In_ const D3D12_RESOURCE_DESC*   pDesc,
                                                  D3D12_RESOURCE_STATES             InitialState,
                                                  _In_opt_ const D3D12_CLEAR_VALUE* pOptimizedClearValue,
                                                  REFIID                            riid,
                                                  HandlePointerDecoder<void*>*      ppvResource,
                                                  UINT64                            max_aliasing_size)
{
    HRESULT                     result     = S_FALSE;
    ComPtr<D3D12MA::Allocation> allocation = nullptr;
    D3D12MA::ALLOCATION_DESC    alloc_desc = {};

    D3D12_RESOURCE_DESC* resource_desc = const_cast<D3D12_RESOURCE_DESC*>(pDesc);
    SetReplayResourceCompatibility(heap_capture_id, pHeap, HeapOffset, resource_desc, alloc_desc);

    if (allocator_ != nullptr)
    {
        bool should_use_committed =
            enable_as_committed_ && ((InitialState & D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE) != 0);
        bool use_aliasing_path = (max_aliasing_size > 0) && !should_use_committed;

        if (should_use_committed)
        {
            alloc_desc.Flags = D3D12MA::ALLOCATION_FLAGS::ALLOCATION_FLAG_COMMITTED;
        }

        if ((pDesc->SampleDesc.Count > 1) || should_use_committed || !use_aliasing_path)
        {
            result = allocator_->CreateResource(&alloc_desc,
                                                pDesc,
                                                InitialState,
                                                pOptimizedClearValue,
                                                &allocation,
                                                riid,
                                                ppvResource->GetHandlePointer());
        }
        else
        {
            D3D12MA::Allocation*           aliasing_alloc    = nullptr;
            D3D12_RESOURCE_ALLOCATION_INFO alloc_info        = { 0, 0 };
            UINT64                         aliasing_offset   = 0;
            UINT64                         allocation_offset = HeapOffset;
            if (pDesc->Dimension == D3D12_RESOURCE_DIMENSION_BUFFER)
            {
                allocation_offset = 0;
                aliasing_offset   = HeapOffset;
            }

            auto& offset_map = heap_id_offset_aliasing_allocation_[heap_capture_id];
            if (offset_map.find(allocation_offset) == offset_map.end())
            {
                auto replay_alloc_info = GetReplayResourceDescAllocationInfo1(pDesc);
                max_aliasing_size      = std::max(max_aliasing_size, replay_alloc_info.SizeInBytes);
                max_aliasing_size =
                    util::platform::AlignValue<D3D12_DEFAULT_RESOURCE_PLACEMENT_ALIGNMENT>(max_aliasing_size);
                alloc_info.Alignment   = replay_alloc_info.Alignment;
                alloc_info.SizeInBytes = max_aliasing_size;

                if (pDesc->Dimension == D3D12_RESOURCE_DIMENSION_BUFFER)
                {
                    auto heap_iter = heap_id_desc_.find(heap_capture_id);
                    if (heap_iter != heap_id_desc_.end())
                    {
                        max_aliasing_size      = std::max(max_aliasing_size, heap_iter->second.SizeInBytes);
                        alloc_info.SizeInBytes = max_aliasing_size;
                    }
                    else
                    {
                        GFXRECON_LOG_ERROR("Failed to find heap description for heap capture id %" PRIu64,
                                           heap_capture_id);
                    }
                }

                result = allocator_->AllocateMemory(&alloc_desc, &alloc_info, &allocation);
                if (SUCCEEDED(result))
                {
                    offset_map[allocation_offset] = allocation;
                    aliasing_alloc                = allocation.Get();
                }
            }
            else
            {
                result         = S_OK;
                aliasing_alloc = offset_map[allocation_offset].Get();
                allocation     = aliasing_alloc;
            }

            if (SUCCEEDED(result))
            {
                result = allocator_->CreateAliasingResource(aliasing_alloc,
                                                            aliasing_offset,
                                                            pDesc,
                                                            InitialState,
                                                            pOptimizedClearValue,
                                                            riid,
                                                            ppvResource->GetHandlePointer());
            }
        }

        if (SUCCEEDED(result))
        {
            auto resource_id = *(ppvResource->GetPointer());
            resource_id_allocation_.insert_or_assign(resource_id, std::move(allocation));
        }
    }

    return result;
}

HRESULT Dx12RebindAllocator::CreateReservedResource(_In_ const D3D12_RESOURCE_DESC*   pDesc,
                                                    D3D12_RESOURCE_STATES             InitialState,
                                                    _In_opt_ const D3D12_CLEAR_VALUE* pOptimizedClearValue,
                                                    REFIID                            riid,
                                                    HandlePointerDecoder<void*>*      ppvResource)
{
    HRESULT result = S_FALSE;

    if (device_ != nullptr)
    {
        GetReplayResourceDescAllocationInfo1(pDesc);
        result = device_->CreateReservedResource(
            pDesc, InitialState, pOptimizedClearValue, riid, ppvResource->GetHandlePointer());
    }
    return result;
}

HRESULT Dx12RebindAllocator::CreateCommittedResource1(_In_ const D3D12_HEAP_PROPERTIES*        pHeapProperties,
                                                      D3D12_HEAP_FLAGS                         HeapFlags,
                                                      _In_ const D3D12_RESOURCE_DESC*          pDesc,
                                                      D3D12_RESOURCE_STATES                    InitialResourceState,
                                                      _In_opt_ const D3D12_CLEAR_VALUE*        pOptimizedClearValue,
                                                      _In_opt_ ID3D12ProtectedResourceSession* pProtectedSession,
                                                      REFIID                                   riidResource,
                                                      HandlePointerDecoder<void*>*             ppvResource)
{
    HRESULT                     result     = S_FALSE;
    ComPtr<D3D12MA::Allocation> allocation = nullptr;
    D3D12MA::ALLOCATION_DESC    alloc_desc = {};

    // don't create resources non-resident
    HeapFlags &= ~D3D12_HEAP_FLAG_CREATE_NOT_RESIDENT;
    GetReplayResourceDescAllocationInfo1(pDesc);

    if (pHeapProperties->Type == D3D12_HEAP_TYPE_CUSTOM || pProtectedSession != nullptr)
    {
        graphics::dx12::ID3D12Device4ComPtr device4;
        device_->QueryInterface(IID_PPV_ARGS(&device4));
        assert(device4 != nullptr);
        if (pHeapProperties->Type == D3D12_HEAP_TYPE_CUSTOM)
        {
            D3D12_HEAP_PROPERTIES heap_props = GetReplayCustomHeapProperties(pHeapProperties->CPUPageProperty);

            result = device4->CreateCommittedResource1(&heap_props,
                                                       HeapFlags,
                                                       pDesc,
                                                       InitialResourceState,
                                                       pOptimizedClearValue,
                                                       pProtectedSession,
                                                       riidResource,
                                                       ppvResource->GetHandlePointer());
        }
        else
        {
            result = device4->CreateCommittedResource1(pHeapProperties,
                                                       HeapFlags,
                                                       pDesc,
                                                       InitialResourceState,
                                                       pOptimizedClearValue,
                                                       pProtectedSession,
                                                       riidResource,
                                                       ppvResource->GetHandlePointer());
        }
    }
    else
    {
        if (allocator_ != nullptr)
        {
            alloc_desc.Flags          = D3D12MA::ALLOCATION_FLAGS::ALLOCATION_FLAG_COMMITTED;
            alloc_desc.HeapType       = pHeapProperties->Type;
            alloc_desc.ExtraHeapFlags = HeapFlags;

            result = allocator_->CreateResource(&alloc_desc,
                                                pDesc,
                                                InitialResourceState,
                                                pOptimizedClearValue,
                                                &allocation,
                                                riidResource,
                                                ppvResource->GetHandlePointer());

            if (SUCCEEDED(result))
            {
                auto resource_id = *(ppvResource->GetPointer());
                resource_id_allocation_.insert_or_assign(resource_id, std::move(allocation));
            }
        }
    }

    return result;
}

HRESULT Dx12RebindAllocator::CreatePlacedResource1(format::HandleId                  heap_capture_id,
                                                   _In_ ID3D12Heap*                  pHeap,
                                                   UINT64                            HeapOffset,
                                                   _In_ const D3D12_RESOURCE_DESC1*  pDesc,
                                                   D3D12_RESOURCE_STATES             InitialState,
                                                   _In_opt_ const D3D12_CLEAR_VALUE* pOptimizedClearValue,
                                                   REFIID                            riid,
                                                   HandlePointerDecoder<void*>*      ppvResource,
                                                   UINT64                            max_aliasing_size)
{
    HRESULT                     result     = S_FALSE;
    ComPtr<D3D12MA::Allocation> allocation = nullptr;
    D3D12MA::ALLOCATION_DESC    alloc_desc = {};

    D3D12_RESOURCE_DESC1* resource_desc = const_cast<D3D12_RESOURCE_DESC1*>(pDesc);
    SetReplayResourceCompatibility(heap_capture_id, pHeap, HeapOffset, resource_desc, alloc_desc);

    if (allocator_ != nullptr)
    {
        bool should_use_committed =
            enable_as_committed_ && ((InitialState & D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE) != 0);
        bool use_aliasing_path = (max_aliasing_size > 0) && !should_use_committed;

        if (should_use_committed)
        {
            alloc_desc.Flags = D3D12MA::ALLOCATION_FLAGS::ALLOCATION_FLAG_COMMITTED;
        }

        if ((pDesc->SampleDesc.Count > 1) || should_use_committed || !use_aliasing_path)
        {
            result = allocator_->CreateResource2(&alloc_desc,
                                                 pDesc,
                                                 InitialState,
                                                 pOptimizedClearValue,
                                                 &allocation,
                                                 riid,
                                                 ppvResource->GetHandlePointer());
        }
        else
        {
            D3D12MA::Allocation*           aliasing_alloc    = nullptr;
            D3D12_RESOURCE_ALLOCATION_INFO alloc_info        = { 0, 0 };
            UINT64                         aliasing_offset   = 0;
            UINT64                         allocation_offset = HeapOffset;
            if (pDesc->Dimension == D3D12_RESOURCE_DIMENSION_BUFFER)
            {
                allocation_offset = 0;
                aliasing_offset   = HeapOffset;
            }

            auto& offset_map = heap_id_offset_aliasing_allocation_[heap_capture_id];
            if (offset_map.find(allocation_offset) == offset_map.end())
            {
                auto replay_alloc_info = GetReplayResourceDescAllocationInfo2(pDesc);
                max_aliasing_size      = std::max(max_aliasing_size, replay_alloc_info.SizeInBytes);
                max_aliasing_size =
                    util::platform::AlignValue<D3D12_DEFAULT_RESOURCE_PLACEMENT_ALIGNMENT>(max_aliasing_size);
                alloc_info.Alignment   = replay_alloc_info.Alignment;
                alloc_info.SizeInBytes = max_aliasing_size;

                if (pDesc->Dimension == D3D12_RESOURCE_DIMENSION_BUFFER)
                {
                    auto heap_iter = heap_id_desc_.find(heap_capture_id);
                    if (heap_iter != heap_id_desc_.end())
                    {
                        max_aliasing_size      = std::max(max_aliasing_size, heap_iter->second.SizeInBytes);
                        alloc_info.SizeInBytes = max_aliasing_size;
                    }
                    else
                    {
                        GFXRECON_LOG_ERROR("Failed to find heap description for heap capture id %" PRIu64,
                                           heap_capture_id);
                    }
                }

                result = allocator_->AllocateMemory(&alloc_desc, &alloc_info, &allocation);
                if (SUCCEEDED(result))
                {
                    offset_map[allocation_offset] = allocation;
                    aliasing_alloc                = allocation.Get();
                }
            }
            else
            {
                result         = S_OK;
                aliasing_alloc = offset_map[allocation_offset].Get();
                allocation     = aliasing_alloc;
            }

            if (SUCCEEDED(result))
            {
                result = allocator_->CreateAliasingResource1(aliasing_alloc,
                                                             aliasing_offset,
                                                             pDesc,
                                                             InitialState,
                                                             pOptimizedClearValue,
                                                             riid,
                                                             ppvResource->GetHandlePointer());
            }
        }

        if (SUCCEEDED(result))
        {
            auto resource_id = *(ppvResource->GetPointer());
            resource_id_allocation_.insert_or_assign(resource_id, std::move(allocation));
        }
    }

    return result;
}

HRESULT Dx12RebindAllocator::CreateReservedResource1(_In_ const D3D12_RESOURCE_DESC*          pDesc,
                                                     D3D12_RESOURCE_STATES                    InitialState,
                                                     _In_opt_ const D3D12_CLEAR_VALUE*        pOptimizedClearValue,
                                                     _In_opt_ ID3D12ProtectedResourceSession* pProtectedSession,
                                                     REFIID                                   riid,
                                                     HandlePointerDecoder<void*>*             ppvResource)
{
    HRESULT result = S_FALSE;

    if (device_ != nullptr)
    {
        GetReplayResourceDescAllocationInfo1(pDesc);

        graphics::dx12::ID3D12Device4ComPtr device4;
        device_->QueryInterface(IID_PPV_ARGS(&device4));

        result = device4->CreateReservedResource1(
            pDesc, InitialState, pOptimizedClearValue, pProtectedSession, riid, ppvResource->GetHandlePointer());
    }

    return result;
}

HRESULT Dx12RebindAllocator::CreateCommittedResource2(_In_ const D3D12_HEAP_PROPERTIES*        pHeapProperties,
                                                      D3D12_HEAP_FLAGS                         HeapFlags,
                                                      _In_ const D3D12_RESOURCE_DESC1*         pDesc,
                                                      D3D12_RESOURCE_STATES                    InitialResourceState,
                                                      _In_opt_ const D3D12_CLEAR_VALUE*        pOptimizedClearValue,
                                                      _In_opt_ ID3D12ProtectedResourceSession* pProtectedSession,
                                                      REFIID                                   riidResource,
                                                      HandlePointerDecoder<void*>*             ppvResource)
{
    HRESULT                     result     = S_FALSE;
    ComPtr<D3D12MA::Allocation> allocation = nullptr;
    D3D12MA::ALLOCATION_DESC    alloc_desc = {};

    // don't create resources non-resident
    HeapFlags &= ~D3D12_HEAP_FLAG_CREATE_NOT_RESIDENT;
    GetReplayResourceDescAllocationInfo2(pDesc);

    if (pHeapProperties->Type == D3D12_HEAP_TYPE_CUSTOM || pProtectedSession != nullptr)
    {
        graphics::dx12::ID3D12Device8ComPtr device8;
        device_->QueryInterface(IID_PPV_ARGS(&device8));
        assert(device8 != nullptr);
        if (pHeapProperties->Type == D3D12_HEAP_TYPE_CUSTOM)
        {
            D3D12_HEAP_PROPERTIES heap_props = GetReplayCustomHeapProperties(pHeapProperties->CPUPageProperty);

            result = device8->CreateCommittedResource2(&heap_props,
                                                       HeapFlags,
                                                       pDesc,
                                                       InitialResourceState,
                                                       pOptimizedClearValue,
                                                       pProtectedSession,
                                                       riidResource,
                                                       ppvResource->GetHandlePointer());
        }
        else
        {
            result = device8->CreateCommittedResource2(pHeapProperties,
                                                       HeapFlags,
                                                       pDesc,
                                                       InitialResourceState,
                                                       pOptimizedClearValue,
                                                       pProtectedSession,
                                                       riidResource,
                                                       ppvResource->GetHandlePointer());
        }
    }
    else
    {
        if (allocator_ != nullptr)
        {
            alloc_desc.Flags          = D3D12MA::ALLOCATION_FLAGS::ALLOCATION_FLAG_COMMITTED;
            alloc_desc.HeapType       = pHeapProperties->Type;
            alloc_desc.ExtraHeapFlags = HeapFlags;

            result = allocator_->CreateResource2(&alloc_desc,
                                                 pDesc,
                                                 InitialResourceState,
                                                 pOptimizedClearValue,
                                                 &allocation,
                                                 riidResource,
                                                 ppvResource->GetHandlePointer());

            if (SUCCEEDED(result))
            {
                auto resource_id = *(ppvResource->GetPointer());
                resource_id_allocation_.insert_or_assign(resource_id, std::move(allocation));
            }
        }
    }

    return result;
}

HRESULT Dx12RebindAllocator::CreatePlacedResource2(format::HandleId                  heap_capture_id,
                                                   _In_ ID3D12Heap*                  pHeap,
                                                   UINT64                            HeapOffset,
                                                   _In_ const D3D12_RESOURCE_DESC1*  pDesc,
                                                   D3D12_BARRIER_LAYOUT              InitialLayout,
                                                   _In_opt_ const D3D12_CLEAR_VALUE* pOptimizedClearValue,
                                                   UINT32                            NumCastableFormats,
                                                   _In_opt_count_(NumCastableFormats)
                                                       const DXGI_FORMAT*       pCastableFormats,
                                                   REFIID                       riid,
                                                   HandlePointerDecoder<void*>* ppvResource,
                                                   UINT64                       max_aliasing_size)
{
    HRESULT                     result     = S_FALSE;
    ComPtr<D3D12MA::Allocation> allocation = nullptr;
    D3D12MA::ALLOCATION_DESC    alloc_desc = {};

    D3D12_RESOURCE_DESC1* resource_desc = const_cast<D3D12_RESOURCE_DESC1*>(pDesc);
    SetReplayResourceCompatibility(heap_capture_id, pHeap, HeapOffset, resource_desc, alloc_desc);

    if (allocator_ != nullptr)
    {
        bool should_use_committed =
            enable_as_committed_ && (resource_desc->Flags & D3D12_RESOURCE_FLAG_RAYTRACING_ACCELERATION_STRUCTURE) != 0;
        bool use_aliasing_path = (max_aliasing_size > 0) && !should_use_committed;

        if (should_use_committed)
        {
            alloc_desc.Flags = D3D12MA::ALLOCATION_FLAGS::ALLOCATION_FLAG_COMMITTED;
        }

        if ((pDesc->SampleDesc.Count > 1) || should_use_committed || !use_aliasing_path)
        {
            result = allocator_->CreateResource3(&alloc_desc,
                                                 pDesc,
                                                 InitialLayout,
                                                 pOptimizedClearValue,
                                                 NumCastableFormats,
                                                 const_cast<DXGI_FORMAT*>(pCastableFormats),
                                                 &allocation,
                                                 riid,
                                                 ppvResource->GetHandlePointer());
        }
        else
        {
            D3D12MA::Allocation*           aliasing_alloc    = nullptr;
            D3D12_RESOURCE_ALLOCATION_INFO alloc_info        = { 0, 0 };
            UINT64                         aliasing_offset   = 0;
            UINT64                         allocation_offset = HeapOffset;
            if (pDesc->Dimension == D3D12_RESOURCE_DIMENSION_BUFFER)
            {
                allocation_offset = 0;
                aliasing_offset   = HeapOffset;
            }

            auto& offset_map = heap_id_offset_aliasing_allocation_[heap_capture_id];
            if (offset_map.find(allocation_offset) == offset_map.end())
            {
                auto replay_alloc_info =
                    GetReplayResourceDescAllocationInfo3(pDesc, NumCastableFormats, pCastableFormats);
                alloc_info.Alignment = replay_alloc_info.Alignment;
                max_aliasing_size    = std::max(max_aliasing_size, replay_alloc_info.SizeInBytes);
                max_aliasing_size =
                    util::platform::AlignValue<D3D12_DEFAULT_RESOURCE_PLACEMENT_ALIGNMENT>(max_aliasing_size);
                alloc_info.Alignment   = replay_alloc_info.Alignment;
                alloc_info.SizeInBytes = max_aliasing_size;

                if (pDesc->Dimension == D3D12_RESOURCE_DIMENSION_BUFFER)
                {
                    auto heap_iter = heap_id_desc_.find(heap_capture_id);
                    if (heap_iter != heap_id_desc_.end())
                    {
                        max_aliasing_size      = std::max(max_aliasing_size, heap_iter->second.SizeInBytes);
                        alloc_info.SizeInBytes = max_aliasing_size;
                    }
                    else
                    {
                        GFXRECON_LOG_ERROR("Failed to find heap description for heap capture id %" PRIu64,
                                           heap_capture_id);
                    }
                }

                result = allocator_->AllocateMemory(&alloc_desc, &alloc_info, &allocation);
                if (SUCCEEDED(result))
                {
                    offset_map[allocation_offset] = allocation;
                    aliasing_alloc                = allocation.Get();
                }
            }
            else
            {
                result         = S_OK;
                aliasing_alloc = offset_map[allocation_offset].Get();
                allocation     = aliasing_alloc;
            }

            if (SUCCEEDED(result))
            {
                result = allocator_->CreateAliasingResource2(aliasing_alloc,
                                                             aliasing_offset,
                                                             pDesc,
                                                             InitialLayout,
                                                             pOptimizedClearValue,
                                                             NumCastableFormats,
                                                             const_cast<DXGI_FORMAT*>(pCastableFormats),
                                                             riid,
                                                             ppvResource->GetHandlePointer());
            }
        }

        if (SUCCEEDED(result))
        {
            auto resource_id = *(ppvResource->GetPointer());
            resource_id_allocation_.insert_or_assign(resource_id, std::move(allocation));
        }
    }

    return result;
}

HRESULT Dx12RebindAllocator::CreateReservedResource2(_In_ const D3D12_RESOURCE_DESC*          pDesc,
                                                     D3D12_BARRIER_LAYOUT                     InitialLayout,
                                                     _In_opt_ const D3D12_CLEAR_VALUE*        pOptimizedClearValue,
                                                     _In_opt_ ID3D12ProtectedResourceSession* pProtectedSession,
                                                     UINT32                                   NumCastableFormats,
                                                     _In_opt_count_(NumCastableFormats)
                                                         const DXGI_FORMAT*       pCastableFormats,
                                                     REFIID                       riid,
                                                     HandlePointerDecoder<void*>* ppvResource)
{
    HRESULT result = S_FALSE;

    if (device_ != nullptr)
    {
        GetReplayResourceDescAllocationInfo1(pDesc);

        graphics::dx12::ID3D12Device10ComPtr device10;
        device_->QueryInterface(IID_PPV_ARGS(&device10));

        result = device10->CreateReservedResource2(pDesc,
                                                   InitialLayout,
                                                   pOptimizedClearValue,
                                                   pProtectedSession,
                                                   NumCastableFormats,
                                                   pCastableFormats,
                                                   riid,
                                                   ppvResource->GetHandlePointer());
    }

    return result;
}

HRESULT Dx12RebindAllocator::CreateCommittedResource3(_In_ const D3D12_HEAP_PROPERTIES*        pHeapProperties,
                                                      D3D12_HEAP_FLAGS                         HeapFlags,
                                                      _In_ const D3D12_RESOURCE_DESC1*         pDesc,
                                                      D3D12_BARRIER_LAYOUT                     InitialLayout,
                                                      _In_opt_ const D3D12_CLEAR_VALUE*        pOptimizedClearValue,
                                                      _In_opt_ ID3D12ProtectedResourceSession* pProtectedSession,
                                                      UINT32                                   NumCastableFormats,
                                                      _In_opt_count_(NumCastableFormats)
                                                          const DXGI_FORMAT*       pCastableFormats,
                                                      REFIID                       riidResource,
                                                      HandlePointerDecoder<void*>* ppvResource)
{
    HRESULT                     result     = S_FALSE;
    ComPtr<D3D12MA::Allocation> allocation = nullptr;
    D3D12MA::ALLOCATION_DESC    alloc_desc = {};

    // don't create resources non-resident
    HeapFlags &= ~D3D12_HEAP_FLAG_CREATE_NOT_RESIDENT;
    GetReplayResourceDescAllocationInfo3(pDesc, NumCastableFormats, pCastableFormats);

    if (pHeapProperties->Type == D3D12_HEAP_TYPE_CUSTOM || pProtectedSession != nullptr)
    {
        graphics::dx12::ID3D12Device10ComPtr device10;
        device_->QueryInterface(IID_PPV_ARGS(&device10));
        assert(device10 != nullptr);
        if (pHeapProperties->Type == D3D12_HEAP_TYPE_CUSTOM)
        {
            D3D12_HEAP_PROPERTIES heap_props = GetReplayCustomHeapProperties(pHeapProperties->CPUPageProperty);

            result = device10->CreateCommittedResource3(&heap_props,
                                                        HeapFlags,
                                                        pDesc,
                                                        InitialLayout,
                                                        pOptimizedClearValue,
                                                        pProtectedSession,
                                                        NumCastableFormats,
                                                        pCastableFormats,
                                                        riidResource,
                                                        ppvResource->GetHandlePointer());
        }
        else
        {
            result = device10->CreateCommittedResource3(pHeapProperties,
                                                        HeapFlags,
                                                        pDesc,
                                                        InitialLayout,
                                                        pOptimizedClearValue,
                                                        pProtectedSession,
                                                        NumCastableFormats,
                                                        pCastableFormats,
                                                        riidResource,
                                                        ppvResource->GetHandlePointer());
        }
    }
    else
    {
        if (allocator_ != nullptr)
        {
            alloc_desc.Flags          = D3D12MA::ALLOCATION_FLAGS::ALLOCATION_FLAG_COMMITTED;
            alloc_desc.HeapType       = pHeapProperties->Type;
            alloc_desc.ExtraHeapFlags = HeapFlags;

            result = allocator_->CreateResource3(&alloc_desc,
                                                 pDesc,
                                                 InitialLayout,
                                                 pOptimizedClearValue,
                                                 NumCastableFormats,
                                                 const_cast<DXGI_FORMAT*>(pCastableFormats),
                                                 &allocation,
                                                 riidResource,
                                                 ppvResource->GetHandlePointer());

            if (SUCCEEDED(result))
            {
                auto resource_id = *(ppvResource->GetPointer());
                resource_id_allocation_.insert_or_assign(resource_id, std::move(allocation));
            }
        }
    }

    return result;
}

HRESULT Dx12RebindAllocator::SetResidencyPriority(UINT                                   NumObjects,
                                                  HandlePointerDecoder<ID3D12Pageable*>* ppObjects,
                                                  const D3D12_RESIDENCY_PRIORITY*        pPriorities)
{
    HRESULT result = S_FALSE;

    graphics::dx12::ID3D12Device1ComPtr device1;
    device_->QueryInterface(IID_PPV_ARGS(&device1));

    auto object_ids = ppObjects->GetPointer();
    auto objects    = ppObjects->GetHandlePointer();

    for (UINT i = 0; i < NumObjects; i++)
    {
        auto object = reinterpret_cast<ID3D12Resource*>(objects[i]);
        if (resource_id_allocation_.find(object_ids[i]) != resource_id_allocation_.end())
        {
            const auto allocation = resource_id_allocation_[object_ids[i]].Get();
            if (allocation->GetHeap() != nullptr)
            {
                objects[i] = reinterpret_cast<ID3D12Pageable*>(allocation->GetHeap());
            }
        }
    }

    if (device1 != nullptr)
    {
        result = device1->SetResidencyPriority(NumObjects, objects, pPriorities);
    }

    return result;
}

void Dx12RebindAllocator::GetResourceTiling(_In_ ID3D12Resource*             pTiledResource,
                                            _Out_opt_ UINT*                  pNumTilesForEntireResource,
                                            _Out_opt_ D3D12_PACKED_MIP_INFO* pPackedMipDesc,
                                            _Out_opt_ D3D12_TILE_SHAPE*      pStandardTileShapeForNonPackedMips,
                                            _Inout_opt_ UINT*                pNumSubresourceTilings,
                                            _In_ UINT                        FirstSubresourceTilingToGet,
                                            _Out_ D3D12_SUBRESOURCE_TILING*  pSubresourceTilingsForNonPackedMips)
{
    if (device_ != nullptr)
    {
        device_->GetResourceTiling(pTiledResource,
                                   pNumTilesForEntireResource,
                                   pPackedMipDesc,
                                   pStandardTileShapeForNonPackedMips,
                                   pNumSubresourceTilings,
                                   FirstSubresourceTilingToGet,
                                   pSubresourceTilingsForNonPackedMips);
    }
}

void Dx12RebindAllocator::UpdateTileMappings(ID3D12CommandQueue*                    pQueue,
                                             format::HandleId                       resource_capture_id,
                                             format::HandleId                       heap_capture_id,
                                             ID3D12Resource*                        pResource,
                                             UINT                                   NumResourceRegions,
                                             const D3D12_TILED_RESOURCE_COORDINATE* pResourceRegionStartCoordinates,
                                             const D3D12_TILE_REGION_SIZE*          pResourceRegionSizes,
                                             ID3D12Heap*                            pHeap,
                                             UINT                                   NumRanges,
                                             const D3D12_TILE_RANGE_FLAGS*          pRangeFlags,
                                             const UINT*                            pHeapRangeStartOffsets,
                                             const UINT*                            pRangeTileCounts,
                                             D3D12_TILE_MAPPING_FLAGS               Flags)
{
    assert(NumRanges > 0);
    assert(NumResourceRegions > 0);

    UINT                                         num_tiles_for_entire_resource = 0;
    D3D12_RESOURCE_DESC                          resource_desc                 = pResource->GetDesc();
    std::vector<D3D12_TILED_RESOURCE_COORDINATE> corrected_coordinates;
    std::vector<D3D12_TILE_REGION_SIZE>          corrected_sizes;

    std::vector<D3D12_TILE_RANGE_FLAGS> final_range_flags;
    std::vector<UINT>                   final_heap_offsets;
    std::vector<UINT>                   final_range_counts;

    corrected_coordinates.reserve(NumResourceRegions);
    corrected_sizes.reserve(NumResourceRegions);

    final_range_flags.reserve(NumRanges);
    if (pHeapRangeStartOffsets)
        final_heap_offsets.reserve(NumRanges);
    if (pRangeTileCounts)
        final_range_counts.reserve(NumRanges);

    D3D12_PACKED_MIP_INFO packed_mip_info         = {};
    D3D12_TILE_SHAPE      standard_tile_shape     = {};
    UINT                  num_subresource_tilings = 0;
    device_->GetResourceTiling(pResource,
                               &num_tiles_for_entire_resource,
                               &packed_mip_info,
                               &standard_tile_shape,
                               &num_subresource_tilings,
                               0,
                               nullptr);

    const UINT first_packed_mip_index            = packed_mip_info.NumStandardMips;
    const UINT packed_region_start_tile_index    = (packed_mip_info.NumPackedMips > 0)
                                                       ? packed_mip_info.StartTileIndexInOverallResource
                                                       : num_tiles_for_entire_resource;
    const UINT physically_available_packed_tiles = num_tiles_for_entire_resource - packed_region_start_tile_index;

    UINT current_range_index = 0;
    bool x_offset_corrected  = false;
    bool region_skipped      = false;
    bool range_clipped       = false;

    if (NumResourceRegions == 1)
    {
        // pResourceRegionStartCoordinates or pResourceRegionSizes can be null only when NumResourceRegions == 1
        const D3D12_TILED_RESOURCE_COORDINATE& original_coord = pResourceRegionStartCoordinates != nullptr
                                                                    ? pResourceRegionStartCoordinates[0]
                                                                    : D3D12_TILED_RESOURCE_COORDINATE{ 0, 0, 0, 0 };

        UINT original_num_tiles = pResourceRegionSizes != nullptr ? pResourceRegionSizes[0].NumTiles
                                                                  : (pResourceRegionStartCoordinates != nullptr
                                                                         ? 1                               // One tile
                                                                         : num_tiles_for_entire_resource); // All tiles

        const D3D12_TILE_REGION_SIZE& original_size = pResourceRegionSizes[0];

        D3D12_TILED_RESOURCE_COORDINATE final_coord = original_coord;
        D3D12_TILE_REGION_SIZE          final_size  = original_size;
        bool                            needs_correction =
            packed_mip_info.NumPackedMips > 0 && original_coord.Subresource >= first_packed_mip_index;
        if (needs_correction)
        {
            x_offset_corrected = true;
            UINT x_offset      = 0;
            if (original_coord.Subresource > first_packed_mip_index)
            {
                GFXRECON_LOG_DEBUG(
                    "Packed mip correction triggered for Subresource %u. Replay device packs from Subresource %u.",
                    original_coord.Subresource,
                    first_packed_mip_index);

                for (UINT sub_idx = first_packed_mip_index; sub_idx < original_coord.Subresource; ++sub_idx)
                {
                    UINT64 mip_width  = std::max(static_cast<UINT64>(1u), resource_desc.Width >> sub_idx);
                    UINT   mip_height = std::max(1u, resource_desc.Height >> sub_idx);
                    UINT   tiles_x =
                        (mip_width + standard_tile_shape.WidthInTexels - 1) / standard_tile_shape.WidthInTexels;
                    UINT tiles_y =
                        (mip_height + standard_tile_shape.HeightInTexels - 1) / standard_tile_shape.HeightInTexels;
                    x_offset += tiles_x * tiles_y;
                }
            }

            x_offset += original_coord.X;

            if (x_offset >= physically_available_packed_tiles)
            {
                GFXRECON_LOG_DEBUG("Skipping UpdateTileMappings call. Calculated X-offset %u exceeds the physically "
                                   "available tiles (%u) in the packed region.",
                                   x_offset,
                                   physically_available_packed_tiles);
                return;
            }
            else
            {
                UINT remaining_tiles = physically_available_packed_tiles - x_offset;

                UINT clamped_num_tiles = std::min(original_num_tiles, remaining_tiles);

                if (clamped_num_tiles == 0)
                {
                    GFXRECON_LOG_DEBUG("Skipping corrected region, Calculated start offset is at the end of "
                                       "available packed tiles.");
                    return;
                }

                final_coord = { x_offset, 0, 0, first_packed_mip_index };
                final_size  = { clamped_num_tiles, false, 0, 0, 0 };
            }
        }

        corrected_coordinates.push_back(final_coord);
        corrected_sizes.push_back(final_size);

        UINT total_tiles_to_process = pResourceRegionSizes != nullptr ? final_size.NumTiles : original_num_tiles;
        UINT current_range_index    = 0;

        if (pRangeTileCounts != nullptr)
        {
            while (total_tiles_to_process > 0 && current_range_index < NumRanges)
            {
                if (pRangeFlags)
                    final_range_flags.push_back(pRangeFlags[current_range_index]);
                else
                    final_range_flags.push_back(D3D12_TILE_RANGE_FLAG_NONE);

                if (pHeapRangeStartOffsets)
                    final_heap_offsets.push_back(pHeapRangeStartOffsets[current_range_index]);

                UINT current_range_size = pRangeTileCounts[current_range_index];

                if (current_range_size > total_tiles_to_process)
                {
                    range_clipped = true;
                    final_range_counts.push_back(total_tiles_to_process);
                    total_tiles_to_process = 0;
                }
                else
                {
                    final_range_counts.push_back(current_range_size);
                    total_tiles_to_process -= current_range_size;
                }

                current_range_index++;
            }
        }
        else
        {
            // if pRangeTileCounts null, NumRanges = 1
            if (pRangeFlags)
                final_range_flags.push_back(pRangeFlags[current_range_index]);
            else
                final_range_flags.push_back(D3D12_TILE_RANGE_FLAG_NONE);

            if (pHeapRangeStartOffsets)
                final_heap_offsets.push_back(pHeapRangeStartOffsets[current_range_index]);

            // NumRanges = 1, pRangeTileCounts = null represents all tiles.
        }
    }
    else
    {
        assert(pResourceRegionStartCoordinates != nullptr);
        assert(pResourceRegionSizes != nullptr);
        for (UINT i = 0; i < NumResourceRegions; ++i)
        {
            const D3D12_TILED_RESOURCE_COORDINATE& original_coord = pResourceRegionStartCoordinates[i];
            const D3D12_TILE_REGION_SIZE&          original_size  = pResourceRegionSizes[i];
            bool                                   is_skipped     = false;

            D3D12_TILED_RESOURCE_COORDINATE final_coord = original_coord;
            D3D12_TILE_REGION_SIZE          final_size  = original_size;

            bool needs_correction =
                packed_mip_info.NumPackedMips > 0 && original_coord.Subresource >= first_packed_mip_index;
            if (needs_correction)
            {
                x_offset_corrected = true;
                UINT x_offset      = 0;
                if (original_coord.Subresource > first_packed_mip_index)
                {
                    GFXRECON_LOG_DEBUG(
                        "Packed mip correction triggered for Subresource %u. Replay device packs from Subresource %u.",
                        original_coord.Subresource,
                        first_packed_mip_index);

                    for (UINT sub_idx = first_packed_mip_index; sub_idx < original_coord.Subresource; ++sub_idx)
                    {
                        UINT64 mip_width  = std::max(static_cast<UINT64>(1u), resource_desc.Width >> sub_idx);
                        UINT   mip_height = std::max(1u, resource_desc.Height >> sub_idx);
                        UINT   tiles_x =
                            (mip_width + standard_tile_shape.WidthInTexels - 1) / standard_tile_shape.WidthInTexels;
                        UINT tiles_y =
                            (mip_height + standard_tile_shape.HeightInTexels - 1) / standard_tile_shape.HeightInTexels;

                        x_offset += tiles_x * tiles_y;
                    }
                }

                x_offset += original_coord.X;

                if (x_offset >= physically_available_packed_tiles)
                {
                    GFXRECON_LOG_DEBUG("Skipping corrected region %u (original Subresource %u, calculated X-offset %u)."
                                       "The offset exceeds the physically available tiles (%u) in the packed region.",
                                       i,
                                       original_coord.Subresource,
                                       x_offset,
                                       physically_available_packed_tiles);
                    is_skipped     = true;
                    region_skipped = true;

                    if (NumResourceRegions == 1)
                    {
                        GFXRECON_LOG_DEBUG(
                            "All regions in UpdateTileMappings call are invalid/skipped. No API call will be made.");
                        return;
                    }
                }
                else
                {
                    UINT remaining_tiles = physically_available_packed_tiles - x_offset;

                    UINT clamped_num_tiles = std::min(original_size.NumTiles, remaining_tiles);

                    if (clamped_num_tiles == 0)
                    {
                        GFXRECON_LOG_DEBUG("Skipping corrected region %u. Calculated start offset is at the end of "
                                           "available packed tiles.",
                                           i);
                        is_skipped     = true;
                        region_skipped = true;
                    }
                    else
                    {
                        final_coord = { x_offset, 0, 0, first_packed_mip_index };
                        final_size  = { clamped_num_tiles, false, 0, 0, 0 };
                        // usebox needs to be false when in packed range
                    }
                }
            }

            if (is_skipped)
            {
                if (NumRanges > 0)
                {
                    if (pRangeTileCounts != nullptr)
                    {
                        UINT tiles_to_skip = original_size.NumTiles;
                        while (tiles_to_skip > 0 && current_range_index < NumRanges)
                        {
                            tiles_to_skip -= pRangeTileCounts[current_range_index];
                            current_range_index++;
                        }
                    }
                    else if (current_range_index < NumRanges)
                    {
                        // if pRangeTileCounts null, NumRanges = 1
                        GFXRECON_LOG_DEBUG("Only single range present in UpdateTileMappings call, do not skip the "
                                           "range for skipped region.");
                    }
                }
            }
            else
            {
                corrected_coordinates.push_back(final_coord);
                corrected_sizes.push_back(final_size);

                if (NumRanges > 0)
                {
                    UINT total_tiles_to_process = final_size.NumTiles;

                    if (pRangeTileCounts != nullptr)
                    {
                        while (total_tiles_to_process > 0 && current_range_index < NumRanges)
                        {
                            if (pRangeFlags)
                                final_range_flags.push_back(pRangeFlags[current_range_index]);
                            else
                                final_range_flags.push_back(D3D12_TILE_RANGE_FLAG_NONE);

                            if (pHeapRangeStartOffsets)
                                final_heap_offsets.push_back(pHeapRangeStartOffsets[current_range_index]);

                            UINT current_range_size = pRangeTileCounts[current_range_index];

                            if (current_range_size > total_tiles_to_process)
                            {
                                range_clipped = true;
                                final_range_counts.push_back(total_tiles_to_process);
                                total_tiles_to_process = 0;
                            }
                            else
                            {
                                final_range_counts.push_back(current_range_size);
                                total_tiles_to_process -= current_range_size;
                            }

                            current_range_index++;
                        }
                    }
                    else if (current_range_index < NumRanges)
                    {
                        // if pRangeTileCounts null, NumRanges = 1
                        if (pRangeFlags)
                            final_range_flags.push_back(pRangeFlags[current_range_index]);
                        else
                            final_range_flags.push_back(D3D12_TILE_RANGE_FLAG_NONE);

                        if (pHeapRangeStartOffsets)
                            final_heap_offsets.push_back(pHeapRangeStartOffsets[current_range_index]);

                        current_range_index++;
                    }
                }
            }
        }
    }

    if (corrected_coordinates.empty())
    {
        GFXRECON_LOG_DEBUG("All regions in UpdateTileMappings call were invalid/skipped. No API call will be made.");
        return;
    }

    const UINT final_num_regions =
        x_offset_corrected && region_skipped ? static_cast<UINT>(corrected_coordinates.size()) : NumResourceRegions;

    const D3D12_TILED_RESOURCE_COORDINATE* final_coordinates =
        x_offset_corrected ? corrected_coordinates.data() : pResourceRegionStartCoordinates;

    const D3D12_TILE_REGION_SIZE* final_sizes = x_offset_corrected ? corrected_sizes.data() : pResourceRegionSizes;

    const UINT                    final_num_ranges = x_offset_corrected && (region_skipped || range_clipped)
                                                         ? ((NumRanges > 0) ? static_cast<UINT>(final_range_flags.size()) : 0)
                                                         : NumRanges;
    const D3D12_TILE_RANGE_FLAGS* final_range_flags_ptr =
        x_offset_corrected && (region_skipped || range_clipped)
            ? (final_range_flags.empty() ? nullptr : final_range_flags.data())
            : pRangeFlags;
    const UINT* final_heap_offsets_ptr = x_offset_corrected && (region_skipped || range_clipped)
                                             ? (final_heap_offsets.empty() ? nullptr : final_heap_offsets.data())
                                             : pHeapRangeStartOffsets;
    const UINT* final_range_counts_ptr = x_offset_corrected && (region_skipped || range_clipped)
                                             ? (final_range_counts.empty() ? nullptr : final_range_counts.data())
                                             : pRangeTileCounts;

    if (pHeap == nullptr)
    {
        pQueue->UpdateTileMappings(pResource,
                                   final_num_regions,
                                   final_coordinates,
                                   final_sizes,
                                   pHeap,
                                   final_num_ranges,
                                   final_range_flags_ptr,
                                   final_heap_offsets_ptr,
                                   final_range_counts_ptr,
                                   Flags);
    }
    else
    {
        if (heap_id_desc_.find(heap_capture_id) == heap_id_desc_.end())
        {
            D3D12_HEAP_DESC heap_desc = pHeap->GetDesc();

            if (heap_desc.Properties.Type == D3D12_HEAP_TYPE_CUSTOM)
            {
                // remove SHARED and SHARED_CROSS_ADAPTER flags that are not allowed on real heaps
                heap_desc.Flags &= ~(D3D12_HEAP_FLAG_SHARED | D3D12_HEAP_FLAG_SHARED_CROSS_ADAPTER);

                D3D12_FEATURE_DATA_D3D12_OPTIONS opts = {};
                if (SUCCEEDED(device_->CheckFeatureSupport(D3D12_FEATURE_D3D12_OPTIONS, &opts, sizeof(opts))))
                {
                    if (opts.ResourceHeapTier == D3D12_RESOURCE_HEAP_TIER_1)
                    {
                        if ((heap_desc.Flags & (D3D12_HEAP_FLAG_DENY_BUFFERS | D3D12_HEAP_FLAG_DENY_RT_DS_TEXTURES |
                                                D3D12_HEAP_FLAG_DENY_NON_RT_DS_TEXTURES)) == 0)
                        {
                            GFXRECON_LOG_WARNING(
                                "Adding DENY_RT_DS_TEXTURES|DENY_NON_RT_DS_TEXTURES to OpenExistingHeap heap "
                                "for tier 1 compatibility");
                            heap_desc.Flags |=
                                (D3D12_HEAP_FLAG_DENY_RT_DS_TEXTURES | D3D12_HEAP_FLAG_DENY_NON_RT_DS_TEXTURES);
                        }
                    }
                }
            }

            heap_id_desc_.insert_or_assign(heap_capture_id, heap_desc);
        }

        // creat heap
        ID3D12Heap* pNewHeap = nullptr;
        if (heap_id_recreated_heap_.find(heap_capture_id) == heap_id_recreated_heap_.end())
        {
            ComPtr<ID3D12Heap> heap = nullptr;
            HRESULT            hr   = device_->CreateHeap(&heap_id_desc_[heap_capture_id], IID_PPV_ARGS(&heap));
            if (hr == S_OK)
            {
                pNewHeap = heap.Get();
                heap_id_recreated_heap_.insert_or_assign(heap_capture_id, heap);
                resource_id_recreated_heap_[resource_capture_id].push_back(std::move(heap));
            }
            else
            {
                pNewHeap = pHeap;
            }
        }
        else
        {
            pNewHeap = heap_id_recreated_heap_[heap_capture_id].Get();
        }

        pQueue->UpdateTileMappings(pResource,
                                   final_num_regions,
                                   final_coordinates,
                                   final_sizes,
                                   pNewHeap,
                                   final_num_ranges,
                                   final_range_flags_ptr,
                                   final_heap_offsets_ptr,
                                   final_range_counts_ptr,
                                   Flags);
    }
}

void Dx12RebindAllocator::CopyTileMappings(ID3D12CommandQueue*                    pQueue,
                                           format::HandleId                       dst_resource_capture_id,
                                           ID3D12Resource*                        pDstResource,
                                           format::HandleId                       src_resource_capture_id,
                                           ID3D12Resource*                        pSrcResource,
                                           const D3D12_TILED_RESOURCE_COORDINATE* pDstRegionStartCoordinate,
                                           const D3D12_TILED_RESOURCE_COORDINATE* pSrcRegionStartCoordinate,
                                           const D3D12_TILE_REGION_SIZE*          pRegionSize,
                                           D3D12_TILE_MAPPING_FLAGS               Flags)
{
    UINT dst_num_tiles_for_entire_resource = 0;
    UINT src_num_tiles_for_entire_resource = 0;

    D3D12_RESOURCE_DESC dst_resource_desc = pDstResource->GetDesc();
    D3D12_RESOURCE_DESC src_resource_desc = pSrcResource->GetDesc();

    D3D12_PACKED_MIP_INFO dst_packed_mip_info = {}, src_packed_mip_info = {};
    D3D12_TILE_SHAPE      dst_tile_shape = {}, src_tile_shape = {};
    UINT                  dst_num_subresource_tilings = 0, src_num_subresource_tilings = 0;

    device_->GetResourceTiling(pDstResource,
                               &dst_num_tiles_for_entire_resource,
                               &dst_packed_mip_info,
                               &dst_tile_shape,
                               &dst_num_subresource_tilings,
                               0,
                               nullptr);
    device_->GetResourceTiling(pSrcResource,
                               &src_num_tiles_for_entire_resource,
                               &src_packed_mip_info,
                               &src_tile_shape,
                               &src_num_subresource_tilings,
                               0,
                               nullptr);

    const UINT dst_first_packed_mip_index         = dst_packed_mip_info.NumStandardMips;
    const UINT dst_packed_region_start_tile_index = (dst_packed_mip_info.NumPackedMips > 0)
                                                        ? dst_packed_mip_info.StartTileIndexInOverallResource
                                                        : dst_num_tiles_for_entire_resource;
    const UINT dst_physically_available_packed_tiles =
        dst_num_tiles_for_entire_resource - dst_packed_region_start_tile_index;

    const UINT src_first_packed_mip_index         = src_packed_mip_info.NumStandardMips;
    const UINT src_packed_region_start_tile_index = (src_packed_mip_info.NumPackedMips > 0)
                                                        ? src_packed_mip_info.StartTileIndexInOverallResource
                                                        : src_num_tiles_for_entire_resource;
    const UINT src_physically_available_packed_tiles =
        src_num_tiles_for_entire_resource - src_packed_region_start_tile_index;

    D3D12_TILED_RESOURCE_COORDINATE final_dst_coord   = *pDstRegionStartCoordinate;
    D3D12_TILED_RESOURCE_COORDINATE final_src_coord   = *pSrcRegionStartCoordinate;
    D3D12_TILE_REGION_SIZE          final_region_size = *pRegionSize;

    bool dst_needs_correction =
        (dst_packed_mip_info.NumPackedMips > 0) && (final_dst_coord.Subresource >= dst_first_packed_mip_index);

    if (dst_needs_correction)
    {
        UINT dst_x_offset = 0;
        if (final_dst_coord.Subresource > dst_first_packed_mip_index)
        {
            for (UINT sub_idx = dst_first_packed_mip_index; sub_idx < final_dst_coord.Subresource; ++sub_idx)
            {
                UINT64 mip_width  = std::max(static_cast<UINT64>(1u), dst_resource_desc.Width >> sub_idx);
                UINT   mip_height = std::max(1u, dst_resource_desc.Height >> sub_idx);
                UINT   tiles_x    = (mip_width + dst_tile_shape.WidthInTexels - 1) / dst_tile_shape.WidthInTexels;
                UINT   tiles_y    = (mip_height + dst_tile_shape.HeightInTexels - 1) / dst_tile_shape.HeightInTexels;
                dst_x_offset += tiles_x * tiles_y;
            }
        }

        dst_x_offset += final_dst_coord.X;

        if (dst_x_offset >= dst_physically_available_packed_tiles)
        {
            GFXRECON_LOG_DEBUG("Skipping CopyTileMappings for dest region (Subresource=%u start X-offset=%u): out of "
                               "packed mip bounds (%u).",
                               final_dst_coord.Subresource,
                               dst_x_offset,
                               dst_physically_available_packed_tiles);
            return;
        }

        UINT dst_remaining_tiles = dst_physically_available_packed_tiles - dst_x_offset;
        UINT clamped_num_tiles   = std::min(final_region_size.NumTiles, dst_remaining_tiles);

        if (clamped_num_tiles == 0)
        {
            GFXRECON_LOG_DEBUG(
                "Skipping CopyTileMappings for dest region: start offset at last available packed tile.");
            return;
        }

        final_dst_coord            = { dst_x_offset, 0, 0, dst_first_packed_mip_index };
        final_region_size.NumTiles = clamped_num_tiles;
        final_region_size.UseBox   = false;
        // packed mip UseBox=false
    }

    bool src_needs_correction =
        (src_packed_mip_info.NumPackedMips > 0) && (final_src_coord.Subresource >= src_first_packed_mip_index);

    if (src_needs_correction)
    {
        UINT src_x_offset = 0;
        if (final_src_coord.Subresource > src_first_packed_mip_index)
        {
            for (UINT sub_idx = src_first_packed_mip_index; sub_idx < final_src_coord.Subresource; ++sub_idx)
            {
                UINT64 mip_width  = std::max(static_cast<UINT64>(1u), src_resource_desc.Width >> sub_idx);
                UINT   mip_height = std::max(1u, src_resource_desc.Height >> sub_idx);
                UINT   tiles_x    = (mip_width + src_tile_shape.WidthInTexels - 1) / src_tile_shape.WidthInTexels;
                UINT   tiles_y    = (mip_height + src_tile_shape.HeightInTexels - 1) / src_tile_shape.HeightInTexels;
                src_x_offset += tiles_x * tiles_y;
            }
        }

        src_x_offset += final_src_coord.X;

        if (src_x_offset >= src_physically_available_packed_tiles)
        {
            GFXRECON_LOG_DEBUG("Skipping CopyTileMappings for src region (Subresource=%u start X-offset=%u): out of "
                               "packed mip bounds (%u).",
                               final_src_coord.Subresource,
                               src_x_offset,
                               src_physically_available_packed_tiles);
            return;
        }

        UINT src_remaining_tiles   = src_physically_available_packed_tiles - src_x_offset;
        UINT clamped_num_tiles     = std::min(final_region_size.NumTiles, src_remaining_tiles);
        final_region_size.NumTiles = std::min(final_region_size.NumTiles, clamped_num_tiles);

        if (final_region_size.NumTiles == 0)
        {
            GFXRECON_LOG_DEBUG("Skipping CopyTileMappings for src region: start offset at last available packed tile.");
            return;
        }

        final_src_coord          = { src_x_offset, 0, 0, src_first_packed_mip_index };
        final_region_size.UseBox = false;
        // packed mip UseBox=false
    }

    pQueue->CopyTileMappings(pDstResource, &final_dst_coord, pSrcResource, &final_src_coord, &final_region_size, Flags);
}

void Dx12RebindAllocator::CopyTiles(ID3D12GraphicsCommandList*             pList,
                                    format::HandleId                       resource_capture_id,
                                    ID3D12Resource*                        pResource,
                                    const D3D12_TILED_RESOURCE_COORDINATE* pTileRegionStartCoordinate,
                                    const D3D12_TILE_REGION_SIZE*          pTileRegionSize,
                                    format::HandleId                       buffer_capture_id,
                                    ID3D12Resource*                        pBuffer,
                                    UINT64                                 BufferStartOffsetInBytes,
                                    D3D12_TILE_COPY_FLAGS                  Flags)
{
    UINT                  num_tiles_for_entire_resource = 0;
    D3D12_RESOURCE_DESC   resource_desc                 = pResource->GetDesc();
    D3D12_PACKED_MIP_INFO packed_mip_info               = {};
    D3D12_TILE_SHAPE      standard_tile_shape           = {};
    UINT                  num_subresource_tilings       = 0;

    device_->GetResourceTiling(pResource,
                               &num_tiles_for_entire_resource,
                               &packed_mip_info,
                               &standard_tile_shape,
                               &num_subresource_tilings,
                               0,
                               nullptr);

    const UINT first_packed_mip_index            = packed_mip_info.NumStandardMips;
    const UINT packed_region_start_tile_index    = (packed_mip_info.NumPackedMips > 0)
                                                       ? packed_mip_info.StartTileIndexInOverallResource
                                                       : num_tiles_for_entire_resource;
    const UINT physically_available_packed_tiles = num_tiles_for_entire_resource - packed_region_start_tile_index;

    D3D12_TILED_RESOURCE_COORDINATE final_coord = *pTileRegionStartCoordinate;
    D3D12_TILE_REGION_SIZE          final_size  = *pTileRegionSize;

    bool needs_correction = packed_mip_info.NumPackedMips > 0 && final_coord.Subresource >= first_packed_mip_index;

    if (needs_correction)
    {
        UINT x_offset = 0;
        if (final_coord.Subresource > first_packed_mip_index)
        {
            GFXRECON_LOG_DEBUG("Packed mip correction triggered for CopyTiles on Subresource %u. Replay device packs "
                               "from Subresource %u.",
                               final_coord.Subresource,
                               first_packed_mip_index);

            for (UINT sub_idx = first_packed_mip_index; sub_idx < final_coord.Subresource; ++sub_idx)
            {
                UINT64 mip_width  = std::max(static_cast<UINT64>(1u), resource_desc.Width >> sub_idx);
                UINT   mip_height = std::max(1u, resource_desc.Height >> sub_idx);
                UINT tiles_x = (mip_width + standard_tile_shape.WidthInTexels - 1) / standard_tile_shape.WidthInTexels;
                UINT tiles_y =
                    (mip_height + standard_tile_shape.HeightInTexels - 1) / standard_tile_shape.HeightInTexels;
                x_offset += tiles_x * tiles_y;
            }
        }
        x_offset += final_coord.X;

        if (x_offset >= physically_available_packed_tiles)
        {
            GFXRECON_LOG_DEBUG(
                "Skipping CopyTiles. Calculated start offset %u is out of available packed tile bounds (%u).",
                x_offset,
                physically_available_packed_tiles);
            return;
        }

        UINT remaining_tiles   = physically_available_packed_tiles - x_offset;
        UINT clamped_num_tiles = std::min(final_size.NumTiles, remaining_tiles);

        if (clamped_num_tiles == 0)
        {
            GFXRECON_LOG_DEBUG("Skipping CopyTiles. Calculated start offset is at the end of available packed tiles, "
                               "no space left to copy.");
            return;
        }

        final_coord         = { x_offset, 0, 0, first_packed_mip_index };
        final_size.NumTiles = clamped_num_tiles;
        final_size.UseBox   = false;
        // packed mip UseBox=false
    }

    pList->CopyTiles(pResource, &final_coord, &final_size, pBuffer, BufferStartOffsetInBytes, Flags);
}

void Dx12RebindAllocator::ReportResourceIncompatibility(const D3D12_RESOURCE_DESC* resource_desc)
{
    return;
}

void Dx12RebindAllocator::ReportResourceIncompatibility1(const D3D12_RESOURCE_DESC1* resource_desc)
{
    return;
}

bool Dx12RebindAllocator::IsAliasingResourcePairs(const format::HandleId resource_before_id,
                                                  const format::HandleId resource_after_id)
{
    auto before_alloc = resource_id_allocation_.find(resource_before_id);
    auto after_alloc  = resource_id_allocation_.find(resource_after_id);
    if ((before_alloc != resource_id_allocation_.end()) && (after_alloc != resource_id_allocation_.end()))
    {
        if ((before_alloc->second->GetHeap() == nullptr) || (after_alloc->second->GetHeap() == nullptr))
        {
            return false;
        }

        if (before_alloc->second->GetHeap() != after_alloc->second->GetHeap())
        {
            return false;
        }

        auto before_offset = before_alloc->second->GetOffset();
        auto before_end    = before_alloc->second->GetOffset() + before_alloc->second->GetSize();
        auto after_offset  = after_alloc->second->GetOffset();
        auto after_end     = after_alloc->second->GetOffset() + after_alloc->second->GetSize();
        if (before_offset == after_offset)
        {
            return true;
        }
        else if ((before_offset < after_end) && (after_offset < before_end))
        {
            return true;
        }
        else if ((after_offset < before_end) && (before_offset < after_end))
        {
            return true;
        }
    }

    return false;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
