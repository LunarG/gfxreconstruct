/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2021 LunarG, Inc.
** Copyright (c) 2021 Advanced Micro Devices, Inc. All rights reserved.
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

#include "encode/dx12_object_wrapper_info.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

D3D12CaptureManager*  D3D12CaptureManager::instance_   = nullptr;
thread_local uint32_t D3D12CaptureManager::call_scope_ = 0;

bool D3D12CaptureManager::CreateInstance()
{
    return CaptureManager::CreateInstance([]() -> CaptureManager* { return instance_; },
                                          []() {
                                              assert(instance_ == nullptr);
                                              instance_ = new D3D12CaptureManager();
                                          });
}

void D3D12CaptureManager::DestroyInstance()
{
    CaptureManager::DestroyInstance([]() -> const CaptureManager* { return instance_; },
                                    []() {
                                        assert(instance_ != nullptr);
                                        delete instance_;
                                        instance_ = nullptr;
                                    });
}

void D3D12CaptureManager::InitializeID3D12ResourceInfo(ID3D12Device_Wrapper*      device_wrapper,
                                                       ID3D12Resource_Wrapper*    resource_wrapper,
                                                       const D3D12_RESOURCE_DESC* desc,
                                                       D3D12_HEAP_TYPE            heap_type,
                                                       D3D12_CPU_PAGE_PROPERTY    page_property,
                                                       bool                       has_write_watch)
{
    assert((resource_wrapper != nullptr) && (desc != nullptr));

    auto info = resource_wrapper->GetObjectInfo();
    assert(info != nullptr);

    info->heap_type       = heap_type;
    info->page_property   = page_property;
    info->has_write_watch = has_write_watch;

    if (desc->Dimension == D3D12_RESOURCE_DIMENSION_BUFFER)
    {
        info->num_subresources     = 1;
        info->mapped_subresources  = std::make_unique<MappedSubresource[]>(info->num_subresources);
        info->subresource_sizes    = std::make_unique<uint64_t[]>(info->num_subresources);
        info->subresource_sizes[0] = desc->Width;
    }
    else
    {
        assert(device_wrapper != nullptr);
        assert((desc->Dimension == D3D12_RESOURCE_DIMENSION_TEXTURE1D) ||
               (desc->Dimension == D3D12_RESOURCE_DIMENSION_TEXTURE2D) ||
               (desc->Dimension == D3D12_RESOURCE_DIMENSION_TEXTURE3D));

        uint32_t        plane_count = 1;
        ID3D12Device*   device      = nullptr;
        ID3D12Resource* resource    = nullptr;

        device_wrapper->GetWrappedObject(&device);
        resource_wrapper->GetWrappedObject(&resource);

        // Retrieve the D3D12_RESOURCE_DESC from the resource, which has MipLevel set to the actual number of
        // miplevels computed by the implementation when the application set it to 0.
        auto full_desc = resource->GetDesc();

        // Get the plane count for the texture format.  With D3D12, each plane has its own subresource.
        D3D12_FEATURE_DATA_FORMAT_INFO format_info = { full_desc.Format, 0 };
        if (SUCCEEDED(device->CheckFeatureSupport(D3D12_FEATURE_FORMAT_INFO, &format_info, sizeof(format_info))))
        {
            plane_count = format_info.PlaneCount;
        }

        auto num_subresources = full_desc.MipLevels * plane_count;

        if ((desc->Dimension == D3D12_RESOURCE_DIMENSION_TEXTURE2D) ||
            (desc->Dimension == D3D12_RESOURCE_DIMENSION_TEXTURE1D))
        {
            num_subresources *= full_desc.DepthOrArraySize;
        }

        auto layouts = std::make_unique<D3D12_PLACED_SUBRESOURCE_FOOTPRINT[]>(num_subresources);

        device->GetCopyableFootprints(desc, 0, num_subresources, 0, layouts.get(), nullptr, nullptr, nullptr);

        info->num_subresources    = num_subresources;
        info->mapped_subresources = std::make_unique<MappedSubresource[]>(num_subresources);
        info->subresource_sizes   = std::make_unique<uint64_t[]>(num_subresources);

        for (size_t i = 0; i < num_subresources; ++i)
        {
            info->subresource_sizes[i] =
                (static_cast<uint64_t>(layouts[i].Footprint.RowPitch) * layouts[i].Footprint.Height) *
                layouts[i].Footprint.Depth;
        }
    }
}

bool D3D12CaptureManager::UseWriteWatch(D3D12_HEAP_TYPE type, D3D12_CPU_PAGE_PROPERTY page_property)
{
    if ((GetPageGuardMemoryMode() == kMemoryModeExternal) &&
        ((type == D3D12_HEAP_TYPE_UPLOAD) || (type == D3D12_HEAP_TYPE_READBACK) ||
         ((type == D3D12_HEAP_TYPE_CUSTOM) && (page_property != D3D12_CPU_PAGE_PROPERTY_NOT_AVAILABLE) &&
          (page_property != D3D12_CPU_PAGE_PROPERTY_UNKNOWN))))
    {
        return true;
    }
    return false;
}

bool D3D12CaptureManager::IsUploadResource(D3D12_HEAP_TYPE type, D3D12_CPU_PAGE_PROPERTY page_property)
{
    if ((type == D3D12_HEAP_TYPE_UPLOAD) ||
        ((type == D3D12_HEAP_TYPE_CUSTOM) && (page_property != D3D12_CPU_PAGE_PROPERTY_NOT_AVAILABLE) &&
         (page_property != D3D12_CPU_PAGE_PROPERTY_UNKNOWN)))
    {
        return true;
    }
    return false;
}

void D3D12CaptureManager::PostProcess_ID3D12Device_CreateHeap(
    ID3D12Device_Wrapper* wrapper, HRESULT result, const D3D12_HEAP_DESC* desc, REFIID riid, void** heap)
{
    GFXRECON_UNREFERENCED_PARAMETER(riid);

    if (SUCCEEDED(result) && (wrapper != nullptr) && (desc != nullptr) && (heap != nullptr) && ((*heap) != nullptr))
    {
        auto resource_wrapper = reinterpret_cast<ID3D12Heap_Wrapper*>(*heap);
        auto info             = resource_wrapper->GetObjectInfo();
        assert(info != nullptr);

        info->heap_type       = desc->Properties.Type;
        info->page_property   = desc->Properties.CPUPageProperty;
        info->has_write_watch = UseWriteWatch(info->heap_type, info->page_property);
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Device_CreateCommittedResource(
    ID3D12Device_Wrapper*        wrapper,
    HRESULT                      result,
    const D3D12_HEAP_PROPERTIES* heap_properties,
    D3D12_HEAP_FLAGS             heap_flags,
    const D3D12_RESOURCE_DESC*   desc,
    D3D12_RESOURCE_STATES        initial_resource_state,
    const D3D12_CLEAR_VALUE*     optimized_clear_value,
    REFIID                       riid,
    void**                       resource)
{
    GFXRECON_UNREFERENCED_PARAMETER(heap_flags);
    GFXRECON_UNREFERENCED_PARAMETER(initial_resource_state);
    GFXRECON_UNREFERENCED_PARAMETER(optimized_clear_value);
    GFXRECON_UNREFERENCED_PARAMETER(riid);

    if (SUCCEEDED(result) && (wrapper != nullptr) && (heap_properties != nullptr) && (desc != nullptr) &&
        (resource != nullptr) && ((*resource) != nullptr))
    {
        auto resource_wrapper = reinterpret_cast<ID3D12Resource_Wrapper*>(*resource);

        InitializeID3D12ResourceInfo(wrapper,
                                     resource_wrapper,
                                     desc,
                                     heap_properties->Type,
                                     heap_properties->CPUPageProperty,
                                     UseWriteWatch(heap_properties->Type, heap_properties->CPUPageProperty));
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Device_CreatePlacedResource(ID3D12Device_Wrapper*      wrapper,
                                                                        HRESULT                    result,
                                                                        ID3D12Heap*                heap,
                                                                        UINT64                     heap_offset,
                                                                        const D3D12_RESOURCE_DESC* desc,
                                                                        D3D12_RESOURCE_STATES      initial_state,
                                                                        const D3D12_CLEAR_VALUE* optimized_clear_value,
                                                                        REFIID                   riid,
                                                                        void**                   resource)
{
    GFXRECON_UNREFERENCED_PARAMETER(heap_offset);
    GFXRECON_UNREFERENCED_PARAMETER(initial_state);
    GFXRECON_UNREFERENCED_PARAMETER(optimized_clear_value);
    GFXRECON_UNREFERENCED_PARAMETER(riid);

    if (SUCCEEDED(result) && (wrapper != nullptr) && (heap != nullptr) && (desc != nullptr) && (resource != nullptr) &&
        ((*resource) != nullptr))
    {
        auto heap_wrapper     = reinterpret_cast<ID3D12Heap_Wrapper*>(heap);
        auto resource_wrapper = reinterpret_cast<ID3D12Resource_Wrapper*>(*resource);
        auto heap_info        = heap_wrapper->GetObjectInfo();
        assert(heap_info != nullptr);

        InitializeID3D12ResourceInfo(wrapper,
                                     resource_wrapper,
                                     desc,
                                     heap_info->heap_type,
                                     heap_info->page_property,
                                     heap_info->has_write_watch);
    }
}

void D3D12CaptureManager::PostProcess_ID3D12Resource_Map(
    ID3D12Resource_Wrapper* wrapper, HRESULT result, UINT subresource, const D3D12_RANGE* read_range, void** data)
{
    GFXRECON_UNREFERENCED_PARAMETER(read_range);

    if (SUCCEEDED(result) && (wrapper != nullptr) && (data != nullptr))
    {
        auto info = wrapper->GetObjectInfo();
        assert((info != nullptr) && (subresource < info->num_subresources));

        if (IsUploadResource(info->heap_type, info->page_property) || info->has_write_watch)
        {
            auto& mapped_subresource = info->mapped_subresources[subresource];

            std::lock_guard<std::mutex> lock(mapped_memory_lock_);
            if (++mapped_subresource.map_count == 1)
            {
                mapped_subresource.data = (*data);

                if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard)
                {
                    util::PageGuardManager* manager = util::PageGuardManager::Get();
                    assert(manager != nullptr);

                    uint64_t size = info->subresource_sizes[subresource];
                    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, size);

                    bool use_shadow_memory = true;
                    bool use_write_watch   = false;

                    if (info->has_write_watch)
                    {
                        use_shadow_memory = false;
                        use_write_watch   = true;
                    }
                    else if ((GetPageGuardMemoryMode() == kMemoryModeShadowPersistent) &&
                             (mapped_subresource.shadow_allocation == util::PageGuardManager::kNullShadowHandle))
                    {
                        mapped_subresource.shadow_allocation =
                            manager->AllocatePersistentShadowMemory(static_cast<size_t>(size));
                    }

                    // Return the pointer provided by the pageguard manager, which may be a pointer to shadow memory,
                    // not the mapped memory.
                    (*data) = manager->AddTrackedMemory(reinterpret_cast<uint64_t>(mapped_subresource.data),
                                                        mapped_subresource.data,
                                                        0,
                                                        static_cast<size_t>(size),
                                                        mapped_subresource.shadow_allocation,
                                                        use_shadow_memory,
                                                        use_write_watch);
                }
                else if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUnassisted)
                {
                    // Need to keep track of mapped memory objects so memory content can be written at queue submit.
                    mapped_resources_.insert(wrapper);
                }
            }
            else
            {
                // The application has mapped the same ID3D12Resource object more than once and the pageguard
                // manager is already tracking it, so we will return the pointer obtained from the pageguard manager
                // on the first map call.
                if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard)
                {
                    // Return the shadow memory that was allocated for the previous map operation.
                    util::PageGuardManager* manager = util::PageGuardManager::Get();
                    assert(manager != nullptr);

                    manager->GetTrackedMemory(reinterpret_cast<uint64_t>(mapped_subresource.data), data);
                }
            }
        }
    }
}

void D3D12CaptureManager::PreProcess_ID3D12Resource_Unmap(ID3D12Resource_Wrapper* wrapper,
                                                          UINT                    subresource,
                                                          const D3D12_RANGE*      written_range)
{
    if (wrapper != nullptr)
    {
        auto info = wrapper->GetObjectInfo();
        assert((info != nullptr) && (subresource < info->num_subresources));

        auto& mapped_subresource = info->mapped_subresources[subresource];

        std::lock_guard<std::mutex> lock(mapped_memory_lock_);
        if (mapped_subresource.map_count > 0)
        {
            if ((--mapped_subresource.map_count == 0) && (mapped_subresource.data != nullptr))
            {
                if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard)
                {
                    util::PageGuardManager* manager = util::PageGuardManager::Get();
                    assert(manager != nullptr);

                    auto memory_id = reinterpret_cast<uint64_t>(mapped_subresource.data);

                    manager->ProcessMemoryEntry(
                        memory_id, [this](uint64_t memory_id, void* start_address, size_t offset, size_t size) {
                            WriteFillMemoryCmd(memory_id, offset, size, start_address);
                        });

                    manager->RemoveTrackedMemory(memory_id);
                }
                else if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUnassisted)
                {
                    uint64_t offset = 0;
                    uint64_t size   = info->subresource_sizes[subresource];

                    if (written_range != nullptr)
                    {
                        offset = written_range->Begin;
                        size   = (written_range->End - written_range->Begin) + 1;
                    }

                    WriteFillMemoryCmd(
                        reinterpret_cast<uint64_t>(mapped_subresource.data), offset, size, mapped_subresource.data);

                    bool is_mapped = false;

                    for (size_t i = 0; i < info->num_subresources; ++i)
                    {
                        if (info->mapped_subresources[i].map_count > 0)
                        {
                            is_mapped = true;
                            break;
                        }
                    }

                    if (!is_mapped)
                    {
                        // All subresources have been unmapped.
                        mapped_resources_.erase(wrapper);
                    }
                }

                mapped_subresource.data = nullptr;
            }
        }
        else
        {
            GFXRECON_LOG_WARNING("Attempting to unmap ID3D12Resource object with capture ID = %" PRIx64
                                 " that has not been mapped",
                                 wrapper->GetCaptureId());
        }
    }
}

void D3D12CaptureManager::Destroy_ID3D12Resource(ID3D12Resource_Wrapper* wrapper)
{
    if (wrapper != nullptr)
    {
        auto info = wrapper->GetObjectInfo();
        assert(info != nullptr);

        if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard)
        {
            util::PageGuardManager* manager = util::PageGuardManager::Get();
            assert(manager != nullptr);

            // Remove memory tracking.
            for (size_t i = 0; i < info->num_subresources; ++i)
            {
                auto& mapped_subresource = info->mapped_subresources[i];

                auto memory_id = reinterpret_cast<uint64_t>(mapped_subresource.data);
                if (memory_id != 0)
                {
                    manager->RemoveTrackedMemory(memory_id);
                }

                if (mapped_subresource.shadow_allocation != util::PageGuardManager::kNullShadowHandle)
                {
                    manager->FreePersistentShadowMemory(mapped_subresource.shadow_allocation);
                }
            }
        }
        else if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUnassisted)
        {
            bool is_mapped = false;

            for (size_t i = 0; i < info->num_subresources; ++i)
            {
                if (info->mapped_subresources[i].map_count > 0)
                {
                    is_mapped = true;
                    break;
                }
            }

            if (is_mapped)
            {
                // If any subresources were mapped, the resource wrapper needs to be removed from the mapped resource
                // table.
                std::lock_guard<std::mutex> lock(mapped_memory_lock_);
                mapped_resources_.erase(wrapper);
            }
        }
    }
}

void D3D12CaptureManager::PreProcess_ID3D12CommandQueue_ExecuteCommandLists(ID3D12CommandQueue_Wrapper* wrapper,
                                                                            UINT                        num_lists,
                                                                            ID3D12CommandList* const*   lists)
{
    GFXRECON_UNREFERENCED_PARAMETER(wrapper);
    GFXRECON_UNREFERENCED_PARAMETER(num_lists);
    GFXRECON_UNREFERENCED_PARAMETER(lists);

    if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard)
    {
        util::PageGuardManager* manager = util::PageGuardManager::Get();
        assert(manager != nullptr);

        manager->ProcessMemoryEntries([this](uint64_t memory_id, void* start_address, size_t offset, size_t size) {
            WriteFillMemoryCmd(memory_id, offset, size, start_address);
        });
    }
    else if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUnassisted)
    {
        std::lock_guard<std::mutex> lock(mapped_memory_lock_);
        for (auto resource_wrapper : mapped_resources_)
        {
            auto info = resource_wrapper->GetObjectInfo();

            for (size_t i = 0; i < info->num_subresources; ++i)
            {
                // If the memory is mapped, write the entire mapped region.
                auto        size               = info->subresource_sizes[i];
                const auto& mapped_subresource = info->mapped_subresources[i];

                WriteFillMemoryCmd(
                    reinterpret_cast<uint64_t>(mapped_subresource.data), 0, size, mapped_subresource.data);
            }
        }
    }
}

HRESULT
D3D12CaptureManager::OverrideID3D12Device_CreateCommittedResource(ID3D12Device_Wrapper*        wrapper,
                                                                  const D3D12_HEAP_PROPERTIES* heap_properties,
                                                                  D3D12_HEAP_FLAGS             heap_flags,
                                                                  const D3D12_RESOURCE_DESC*   desc,
                                                                  D3D12_RESOURCE_STATES        initial_resource_state,
                                                                  const D3D12_CLEAR_VALUE*     optimized_clear_value,
                                                                  REFIID                       riid_resource,
                                                                  void**                       ppv_resource)
{
    if (desc == nullptr || heap_properties == nullptr)
    {
        return E_INVALIDARG;
    }
    else if (UseWriteWatch(heap_properties->Type, heap_properties->CPUPageProperty))
    {
        heap_flags |= D3D12_HEAP_FLAG_ALLOW_WRITE_WATCH;
    }

    ID3D12Device* device = nullptr;
    wrapper->GetWrappedObject(&device);
    return device->CreateCommittedResource(
        heap_properties, heap_flags, desc, initial_resource_state, optimized_clear_value, riid_resource, ppv_resource);
}

D3D12CaptureManager::D3D12CaptureManager() :
    CaptureManager(format::ApiFamilyId::ApiFamily_D3D12), dxgi_dispatch_table_{}, d3d12_dispatch_table_{}
{}

HRESULT D3D12CaptureManager::OverrideID3D12Device_CreateHeap(ID3D12Device_Wrapper*  wrapper,
                                                             const D3D12_HEAP_DESC* desc,
                                                             REFIID                 riid,
                                                             void**                 heap)
{
    ID3D12Device* device = nullptr;
    wrapper->GetWrappedObject(&device);

    if (desc == nullptr)
    {
        return E_INVALIDARG;
    }
    else if (UseWriteWatch(desc->Properties.Type, desc->Properties.CPUPageProperty))
    {
        D3D12_HEAP_DESC desc_copy = *desc;
        desc_copy.Flags |= D3D12_HEAP_FLAG_ALLOW_WRITE_WATCH;
        return device->CreateHeap(&desc_copy, riid, heap);
    }
    else
    {
        return device->CreateHeap(desc, riid, heap);
    }
}

HRESULT D3D12CaptureManager::OverrideCreateDXGIFactory2(UINT Flags, REFIID riid, void** ppFactory)
{
    HRESULT result = E_FAIL;

    if (GetDebugLayer())
    {
        PFN_D3D12_GET_DEBUG_INTERFACE get_debug_interface = d3d12_dispatch_table_.D3D12GetDebugInterface;

        if (get_debug_interface == nullptr)
        {
            HMODULE d3d12_dll = LoadLibraryA("d3d12_ms.dll");

            if (d3d12_dll == NULL)
            {
                d3d12_dll = LoadLibraryA("d3d12.dll");
            }

            if (d3d12_dll != nullptr)
            {
                get_debug_interface = reinterpret_cast<PFN_D3D12_GET_DEBUG_INTERFACE>(
                    GetProcAddress(d3d12_dll, "D3D12GetDebugInterface"));
            }
        }

        if (get_debug_interface != nullptr)
        {
            ID3D12Debug* debugController = nullptr;
            result                       = get_debug_interface(IID_PPV_ARGS(&debugController));

            if (result == S_OK)
            {
                debugController->EnableDebugLayer();
            }
        }

        Flags |= DXGI_CREATE_FACTORY_DEBUG;
    }

    result = dxgi_dispatch_table_.CreateDXGIFactory2(Flags, riid, ppFactory);

    return result;
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
