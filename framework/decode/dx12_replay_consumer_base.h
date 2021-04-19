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

#ifndef GFXRECON_DECODE_DX12_REPLAY_CONSUMER_BASE_H
#define GFXRECON_DECODE_DX12_REPLAY_CONSUMER_BASE_H

#include "decode/dx_replay_options.h"
#include "decode/dx12_object_info.h"
#include "decode/dx12_object_mapping_util.h"
#include "decode/window.h"
#include "format/format.h"
#include "generated/generated_dx12_consumer.h"
#include "util/gpu_va_map.h"

#include <unordered_map>
#include <unordered_set>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class Dx12ReplayConsumerBase : public Dx12Consumer
{
  public:
    Dx12ReplayConsumerBase(WindowFactory* window_factory, const DxReplayOptions& options);

    virtual ~Dx12ReplayConsumerBase() override;

    void SetFatalErrorHandler(std::function<void(const char*)> handler) { fatal_error_handler_ = handler; }

    virtual void
    ProcessFillMemoryCommand(uint64_t memory_id, uint64_t offset, uint64_t size, const uint8_t* data) override;

    virtual void Process_ID3D12Device_CheckFeatureSupport(format::HandleId object_id,
                                                          HRESULT          original_result,
                                                          D3D12_FEATURE    feature,
                                                          const void*      capture_feature_data,
                                                          void*            replay_feature_data,
                                                          UINT             feature_data_size) override;

  protected:
    void MapCpuDescriptorHandle(D3D12_CPU_DESCRIPTOR_HANDLE& handle);

    void MapCpuDescriptorHandles(D3D12_CPU_DESCRIPTOR_HANDLE* handles, size_t handles_len);

    void MapGpuDescriptorHandle(D3D12_GPU_DESCRIPTOR_HANDLE& handle);

    void MapGpuDescriptorHandles(D3D12_GPU_DESCRIPTOR_HANDLE* handles, size_t handles_len);

    void MapGpuVirtualAddress(D3D12_GPU_VIRTUAL_ADDRESS& address);

    void MapGpuVirtualAddresses(D3D12_GPU_VIRTUAL_ADDRESS* addresses, size_t addresses_len);

    template <typename T>
    T* MapObject(const format::HandleId id)
    {
        return object_mapping::MapObject<T>(id, object_info_table_);
    }

    template <typename T>
    T** MapObjects(HandlePointerDecoder<T*>* handles_pointer, size_t handles_len)
    {
        // This parameter is only referenced by debug builds.
        GFXRECON_UNREFERENCED_PARAMETER(handles_len);

        T** handles = nullptr;

        if (handles_pointer != nullptr)
        {
            // The handle and ID array sizes are expected to be the same for mapping operations.
            assert(handles_len == handles_pointer->GetLength());

            handles = object_mapping::MapObjectArray(handles_pointer, object_info_table_);
        }

        return handles;
    }

    template <typename T>
    void AddObject(const format::HandleId* p_id, T** pp_object)
    {
        object_mapping::AddObject<T>(p_id, pp_object, &object_info_table_);
    }

    template <typename T>
    void AddObject(const format::HandleId* p_id, T** pp_object, DxObjectInfoType extra_info_type, void* extra_info)
    {
        object_mapping::AddObject<T>(p_id, pp_object, extra_info_type, extra_info, &object_info_table_);
    }

    void RemoveObject(DxObjectInfo* info);

    void CheckReplayResult(const char* call_name, HRESULT capture_result, HRESULT replay_result);

    void* PreProcessExternalObject(uint64_t object_id, format::ApiCallId call_id, const char* call_name);

    void PostProcessExternalObject(
        HRESULT replay_result, void* object, uint64_t* object_id, format::ApiCallId call_id, const char* call_name);

    ULONG OverrideAddRef(DxObjectInfo* replay_object_info, ULONG original_result);

    ULONG OverrideRelease(DxObjectInfo* replay_object_info, ULONG original_result);

    HRESULT OverrideCreateSwapChain(DxObjectInfo*                                       replay_object_info,
                                    HRESULT                                             original_result,
                                    DxObjectInfo*                                       device_info,
                                    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC>* desc,
                                    HandlePointerDecoder<IDXGISwapChain*>*              swapchain);

    HRESULT
    OverrideCreateSwapChainForHwnd(DxObjectInfo*                                                  replay_object_info,
                                   HRESULT                                                        original_result,
                                   DxObjectInfo*                                                  device_info,
                                   uint64_t                                                       hwnd_id,
                                   StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>*           desc,
                                   StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC>* full_screen_desc,
                                   DxObjectInfo*                           restrict_to_output_info,
                                   HandlePointerDecoder<IDXGISwapChain1*>* swapchain);

    HRESULT
    OverrideCreateSwapChainForCoreWindow(DxObjectInfo*                                        replay_object_info,
                                         HRESULT                                              original_result,
                                         DxObjectInfo*                                        device_info,
                                         DxObjectInfo*                                        window_info,
                                         StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* desc,
                                         DxObjectInfo*                                        restrict_to_output_info,
                                         HandlePointerDecoder<IDXGISwapChain1*>*              swapchain);

    HRESULT OverrideCreateSwapChainForComposition(DxObjectInfo* replay_object_info,
                                                  HRESULT       original_result,
                                                  DxObjectInfo* device_info,
                                                  StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* desc,
                                                  DxObjectInfo*                           restrict_to_output_info,
                                                  HandlePointerDecoder<IDXGISwapChain1*>* swapchain);

    HRESULT
    OverrideCreateDXGIFactory2(HRESULT                      original_result,
                               UINT                         flags,
                               Decoded_GUID                 riid,
                               HandlePointerDecoder<void*>* ppFactory);

    HRESULT OverrideD3D12CreateDevice(HRESULT                      original_result,
                                      DxObjectInfo*                adapter_info,
                                      D3D_FEATURE_LEVEL            minimum_feature_level,
                                      Decoded_GUID                 riid,
                                      HandlePointerDecoder<void*>* device);

    HRESULT OverrideCreateDescriptorHeap(DxObjectInfo*                                             replay_object_info,
                                         HRESULT                                                   original_result,
                                         StructPointerDecoder<Decoded_D3D12_DESCRIPTOR_HEAP_DESC>* desc,
                                         Decoded_GUID                                              riid,
                                         HandlePointerDecoder<void*>*                              heap);

    HRESULT OverrideCreateFence(DxObjectInfo*                replay_object_info,
                                HRESULT                      original_result,
                                UINT64                       initial_value,
                                D3D12_FENCE_FLAGS            flags,
                                Decoded_GUID                 riid,
                                HandlePointerDecoder<void*>* fence);

    UINT OverrideGetDescriptorHandleIncrementSize(DxObjectInfo*              replay_object_info,
                                                  UINT                       original_result,
                                                  D3D12_DESCRIPTOR_HEAP_TYPE descriptor_heap_type);

    D3D12_CPU_DESCRIPTOR_HANDLE
    OverrideGetCPUDescriptorHandleForHeapStart(DxObjectInfo*                              replay_object_info,
                                               const Decoded_D3D12_CPU_DESCRIPTOR_HANDLE& original_result);

    D3D12_GPU_DESCRIPTOR_HANDLE
    OverrideGetGPUDescriptorHandleForHeapStart(DxObjectInfo*                              replay_object_info,
                                               const Decoded_D3D12_GPU_DESCRIPTOR_HANDLE& original_result);

    D3D12_GPU_VIRTUAL_ADDRESS OverrideGetGpuVirtualAddress(DxObjectInfo*             replay_object_info,
                                                           D3D12_GPU_VIRTUAL_ADDRESS original_result);

    HRESULT OverrideEnqueueMakeResident(DxObjectInfo*                          replay_object_info,
                                        HRESULT                                original_result,
                                        D3D12_RESIDENCY_FLAGS                  flags,
                                        UINT                                   num_objects,
                                        HandlePointerDecoder<ID3D12Pageable*>* objects,
                                        DxObjectInfo*                          fence_info,
                                        UINT64                                 fence_value);

    HRESULT OverrideResourceMap(DxObjectInfo*                              replay_object_info,
                                HRESULT                                    original_result,
                                UINT                                       subresource,
                                StructPointerDecoder<Decoded_D3D12_RANGE>* read_range,
                                PointerDecoder<uint64_t, void*>*           data);

    void OverrideResourceUnmap(DxObjectInfo*                              replay_object_info,
                               UINT                                       subresource,
                               StructPointerDecoder<Decoded_D3D12_RANGE>* written_range);

    HRESULT
    OverrideWriteToSubresource(DxObjectInfo*                            replay_object_info,
                               HRESULT                                  original_result,
                               UINT                                     dst_subresource,
                               StructPointerDecoder<Decoded_D3D12_BOX>* dst_box,
                               uint64_t                                 src_data,
                               UINT                                     src_row_pitch,
                               UINT                                     src_depth_pitch);

    HRESULT
    OverrideReadFromSubresource(DxObjectInfo*                            replay_object_info,
                                HRESULT                                  original_result,
                                uint64_t                                 dst_data,
                                UINT                                     dst_row_pitch,
                                UINT                                     dst_depth_pitch,
                                UINT                                     src_subresource,
                                StructPointerDecoder<Decoded_D3D12_BOX>* src_box);

    HRESULT OverrideCommandQueueSignal(DxObjectInfo* replay_object_info,
                                       HRESULT       original_result,
                                       DxObjectInfo* fence_info,
                                       UINT64        value);

    HRESULT OverrideSetEventOnCompletion(DxObjectInfo* replay_object_info,
                                         HRESULT       original_result,
                                         UINT64        value,
                                         uint64_t      event_id);

    HRESULT OverrideFenceSignal(DxObjectInfo* replay_object_info, HRESULT original_result, UINT64 value);

    const Dx12ObjectInfoTable& GetObjectInfoTable() const { return object_info_table_; }

    Dx12ObjectInfoTable& GetObjectInfoTable() { return object_info_table_; }

    DxObjectInfo* GetObjectInfo(format::HandleId id)
    {
        auto entry = object_info_table_.find(id);
        if (entry != object_info_table_.end())
        {
            return &entry->second;
        }

        return nullptr;
    }

    const Dx12CpuDescriptorMap& GetCpuAddressTable() const { return descriptor_cpu_addresses_; }

    Dx12CpuDescriptorMap& GetCpuAddressTable() { return descriptor_cpu_addresses_; }

    const Dx12GpuDescriptorMap& GetGpuAddressTable() const { return descriptor_gpu_addresses_; }

    Dx12GpuDescriptorMap& GetGpuAddressTable() { return descriptor_gpu_addresses_; }

    const util::GpuVaMap& GetGpuVaTable() const { return gpu_va_map_; }

    util::GpuVaMap& GetGpuVaTable() { return gpu_va_map_; }

  private:
    void RaiseFatalError(const char* message) const;

    HRESULT
    CreateSwapChainForHwnd(DxObjectInfo*                                                  replay_object_info,
                           HRESULT                                                        original_result,
                           DxObjectInfo*                                                  device_info,
                           uint64_t                                                       hwnd_id,
                           StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>*           desc,
                           StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC>* full_screen_desc,
                           DxObjectInfo*                                                  restrict_to_output_info,
                           HandlePointerDecoder<IDXGISwapChain1*>*                        swapchain);

    void SetSwapchainInfoWindow(DxObjectInfo* info, Window* window, uint64_t hwnd_id, HWND hwnd);

    void DestroyObjectExtraInfo(DxObjectInfo* info);

    void DestroyActiveObjects();

    void DestroyActiveWindows();

    void DestroyActiveEvents();

    void ProcessFenceSignal(DxObjectInfo* info, uint64_t value);

    HANDLE GetEventObject(uint64_t event_id, bool reset);

  private:
    Dx12ObjectInfoTable                  object_info_table_;
    WindowFactory*                       window_factory_;
    DxReplayOptions                      options_;
    std::unordered_set<Window*>          active_windows_;
    std::unordered_map<uint64_t, HWND>   window_handles_;
    std::unordered_map<uint64_t, void*>  mapped_memory_;
    std::unordered_map<uint64_t, HANDLE> event_objects_;
    std::function<void(const char*)>     fatal_error_handler_;
    Dx12CpuDescriptorMap                 descriptor_cpu_addresses_;
    Dx12GpuDescriptorMap                 descriptor_gpu_addresses_;
    util::GpuVaMap                       gpu_va_map_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_REPLAY_CONSUMER_BASE_H
