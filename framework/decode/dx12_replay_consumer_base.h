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

#include "decode/dx12_object_info.h"
#include "decode/dx12_object_mapping_util.h"
#include "decode/window.h"
#include "format/format.h"
#include "generated/generated_dx12_consumer.h"
#include "util/gpu_va_map.h"

#include <map>
#include <unordered_map>
#include <unordered_set>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class Dx12ReplayConsumerBase : public Dx12Consumer
{
  public:
    Dx12ReplayConsumerBase(WindowFactory* window_factory);

    virtual ~Dx12ReplayConsumerBase() override;

    virtual void ProcessFillMemoryCommand(uint64_t memory_id, uint64_t offset, uint64_t size, const uint8_t* data);

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
    std::vector<T*> MapObjects(const format::HandleId* p_ids, const size_t ids_len)
    {
        return object_mapping::MapObjectArray<T>(p_ids, ids_len, object_info_table_);
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

  private:
    HRESULT
    CreateSwapChainForHwnd(DxObjectInfo*                                                  replay_object_info,
                           HRESULT                                                        original_result,
                           DxObjectInfo*                                                  device_info,
                           uint64_t                                                       hwnd_id,
                           StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>*           desc,
                           StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC>* full_screen_desc,
                           DxObjectInfo*                                                  restrict_to_output_info,
                           HandlePointerDecoder<IDXGISwapChain1*>*                        swapchain);

    void SetSwapchainInfoWindow(DxObjectInfo* info, Window* window);

    void DestroyActiveWindows();

  private:
    Dx12ObjectInfoTable                          object_info_table_;
    WindowFactory*                               window_factory_;
    std::unordered_set<Window*>                  active_windows_;
    std::unordered_map<uint64_t, void*>          mapped_memory_;
    std::map<size_t, D3D12DescriptorHeapInfo*, std::greater<size_t>>     descriptor_cpu_addresses_;
    std::map<uint64_t, D3D12DescriptorHeapInfo*, std::greater<uint64_t>> descriptor_gpu_addresses_;
    util::GpuVaMap                                                       gpu_va_map_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_REPLAY_CONSUMER_BASE_H
