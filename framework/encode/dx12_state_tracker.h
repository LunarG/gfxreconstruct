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

#ifndef GFXRECON_ENCODE_DX12_STATE_TRACKER_H
#define GFXRECON_ENCODE_DX12_STATE_TRACKER_H

#include "encode/dx12_state_table.h"
#include "encode/dx12_state_tracker_initializers.h"
#include "encode/dx12_state_writer.h"
#include "generated/generated_dx12_wrapper_creators.h"
#include "util/defines.h"

#include <guiddef.h>
#include <mutex>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class Dx12StateTracker
{
  public:
    Dx12StateTracker();

    ~Dx12StateTracker();

    void WriteState(Dx12StateWriter* writer, uint64_t frame_number);

    // TODO (GH #83): replace this with a generated lookup table and functions
    template <typename ParentWrapper>
    void AddEntry(REFIID                          riid,
                  typename void**                 new_handle,
                  format::ApiCallId               create_call_id,
                  ParentWrapper*                  create_object_wrapper,
                  const util::MemoryOutputStream* create_parameter_buffer)
    {
        // clang-format off
             if(riid == IID_IDXGIKeyedMutex) AddEntry<IDXGIKeyedMutex_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGIDisplayControl) AddEntry<IDXGIDisplayControl_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGIOutputDuplication) AddEntry<IDXGIOutputDuplication_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGISurface) AddEntry<IDXGISurface_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGISurface1) AddEntry<IDXGISurface_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGISurface2) AddEntry<IDXGISurface_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGIResource) AddEntry<IDXGIResource_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGIResource1) AddEntry<IDXGIResource_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGIDecodeSwapChain) AddEntry<IDXGIDecodeSwapChain_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGIFactoryMedia) AddEntry<IDXGIFactoryMedia_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGISwapChainMedia) AddEntry<IDXGISwapChainMedia_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGISwapChain) AddEntry<IDXGISwapChain_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGISwapChain1) AddEntry<IDXGISwapChain_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGISwapChain2) AddEntry<IDXGISwapChain_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGISwapChain3) AddEntry<IDXGISwapChain_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGISwapChain4) AddEntry<IDXGISwapChain_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGIDevice) AddEntry<IDXGIDevice_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGIDevice1) AddEntry<IDXGIDevice_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGIDevice2) AddEntry<IDXGIDevice_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGIDevice3) AddEntry<IDXGIDevice_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGIDevice4) AddEntry<IDXGIDevice_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGIAdapter) AddEntry<IDXGIAdapter_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGIAdapter1) AddEntry<IDXGIAdapter_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGIAdapter2) AddEntry<IDXGIAdapter_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGIAdapter3) AddEntry<IDXGIAdapter_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGIAdapter4) AddEntry<IDXGIAdapter_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGIOutput) AddEntry<IDXGIOutput_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGIOutput1) AddEntry<IDXGIOutput_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGIOutput2) AddEntry<IDXGIOutput_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGIOutput3) AddEntry<IDXGIOutput_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGIOutput4) AddEntry<IDXGIOutput_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGIOutput5) AddEntry<IDXGIOutput_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGIOutput6) AddEntry<IDXGIOutput_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGIFactory) AddEntry<IDXGIFactory_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGIFactory1) AddEntry<IDXGIFactory_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGIFactory2) AddEntry<IDXGIFactory_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGIFactory3) AddEntry<IDXGIFactory_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGIFactory4) AddEntry<IDXGIFactory_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGIFactory5) AddEntry<IDXGIFactory_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGIFactory6) AddEntry<IDXGIFactory_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_IDXGIFactory7) AddEntry<IDXGIFactory_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12RootSignature) AddEntry<ID3D12RootSignature_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12RootSignatureDeserializer) AddEntry<ID3D12RootSignatureDeserializer_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12VersionedRootSignatureDeserializer) AddEntry<ID3D12VersionedRootSignatureDeserializer_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12CommandAllocator) AddEntry<ID3D12CommandAllocator_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12Fence) AddEntry<ID3D12Fence_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12Fence1) AddEntry<ID3D12Fence_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12PipelineState) AddEntry<ID3D12PipelineState_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12DescriptorHeap) AddEntry<ID3D12DescriptorHeap_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12QueryHeap) AddEntry<ID3D12QueryHeap_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12CommandSignature) AddEntry<ID3D12CommandSignature_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12CommandQueue) AddEntry<ID3D12CommandQueue_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12PipelineLibrary) AddEntry<ID3D12PipelineLibrary_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12PipelineLibrary1) AddEntry<ID3D12PipelineLibrary_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12LifetimeOwner) AddEntry<ID3D12LifetimeOwner_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12SwapChainAssistant) AddEntry<ID3D12SwapChainAssistant_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12LifetimeTracker) AddEntry<ID3D12LifetimeTracker_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12StateObject) AddEntry<ID3D12StateObject_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12StateObjectProperties) AddEntry<ID3D12StateObjectProperties_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12DeviceRemovedExtendedDataSettings) AddEntry<ID3D12DeviceRemovedExtendedDataSettings_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12DeviceRemovedExtendedDataSettings1) AddEntry<ID3D12DeviceRemovedExtendedDataSettings_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12DeviceRemovedExtendedData) AddEntry<ID3D12DeviceRemovedExtendedData_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12DeviceRemovedExtendedData1) AddEntry<ID3D12DeviceRemovedExtendedData_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12ProtectedResourceSession) AddEntry<ID3D12ProtectedResourceSession_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12ProtectedResourceSession1) AddEntry<ID3D12ProtectedResourceSession_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12Device) AddEntry<ID3D12Device_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12Device1) AddEntry<ID3D12Device_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12Device2) AddEntry<ID3D12Device_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12Device3) AddEntry<ID3D12Device_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12Device4) AddEntry<ID3D12Device_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12Device5) AddEntry<ID3D12Device_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12Device6) AddEntry<ID3D12Device_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12Device7) AddEntry<ID3D12Device_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12Device8) AddEntry<ID3D12Device_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12Resource) AddEntry<ID3D12Resource_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12Resource1) AddEntry<ID3D12Resource_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12Resource2) AddEntry<ID3D12Resource_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12Heap) AddEntry<ID3D12Heap_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12Heap1) AddEntry<ID3D12Heap_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12MetaCommand) AddEntry<ID3D12MetaCommand_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12Tools) AddEntry<ID3D12Tools_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12GraphicsCommandList) AddEntry<ID3D12GraphicsCommandList_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12GraphicsCommandList1) AddEntry<ID3D12GraphicsCommandList_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12GraphicsCommandList2) AddEntry<ID3D12GraphicsCommandList_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12GraphicsCommandList3) AddEntry<ID3D12GraphicsCommandList_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12GraphicsCommandList4) AddEntry<ID3D12GraphicsCommandList_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12GraphicsCommandList5) AddEntry<ID3D12GraphicsCommandList_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12GraphicsCommandList6) AddEntry<ID3D12GraphicsCommandList_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D10Blob) AddEntry<ID3D10Blob_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3DDestructionNotifier) AddEntry<ID3DDestructionNotifier_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12Debug1) AddEntry<ID3D12Debug1_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12Debug2) AddEntry<ID3D12Debug2_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12Debug) AddEntry<ID3D12Debug_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12Debug1) AddEntry<ID3D12Debug_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12Debug2) AddEntry<ID3D12Debug_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12Debug3) AddEntry<ID3D12Debug_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12DebugDevice1) AddEntry<ID3D12DebugDevice1_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12DebugDevice) AddEntry<ID3D12DebugDevice_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12DebugDevice1) AddEntry<ID3D12DebugDevice_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12DebugDevice2) AddEntry<ID3D12DebugDevice_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12DebugCommandQueue) AddEntry<ID3D12DebugCommandQueue_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12DebugCommandList1) AddEntry<ID3D12DebugCommandList1_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12DebugCommandList) AddEntry<ID3D12DebugCommandList_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12DebugCommandList1) AddEntry<ID3D12DebugCommandList_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12DebugCommandList2) AddEntry<ID3D12DebugCommandList_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12SharingContract) AddEntry<ID3D12SharingContract_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        else if(riid == IID_ID3D12InfoQueue) AddEntry<ID3D12InfoQueue_Wrapper>(new_handle, create_call_id, create_object_wrapper, create_parameter_buffer);
        // clang-format on
    };

    template <typename Wrapper, typename ParentWrapper>
    void AddEntry(typename void**                 new_handle,
                  format::ApiCallId               create_call_id,
                  ParentWrapper*                  create_object_wrapper,
                  const util::MemoryOutputStream* create_parameter_buffer)
    {
        assert(new_handle != nullptr);
        assert(create_object_wrapper != nullptr);
        assert(create_parameter_buffer != nullptr);

        if (*new_handle != nullptr)
        {
            auto wrapper = reinterpret_cast<Wrapper*>(*new_handle);

            // Adds the handle wrapper to the object state table, filtering for duplicate handle retrieval.
            std::unique_lock<std::mutex> lock(state_table_mutex_);
            if (state_table_.InsertWrapper(wrapper->GetCaptureId(), wrapper))
            {
                dx12_state_tracker::InitializeState<Wrapper, ParentWrapper>(
                    wrapper, create_call_id, create_object_wrapper, create_parameter_buffer);
            }
        }
    }

    // Specialize templated AddEntry for API calls (which do not have a calling object).
    template <typename Wrapper>
    void AddEntry(typename void**                 new_handle,
                  format::ApiCallId               create_call_id,
                  void*                           create_object_wrapper,
                  const util::MemoryOutputStream* create_parameter_buffer)
    {
        assert(new_handle != nullptr);
        assert(create_object_wrapper == nullptr);
        assert(create_parameter_buffer != nullptr);

        if (*new_handle != nullptr)
        {
            auto wrapper = reinterpret_cast<Wrapper*>(*new_handle);

            // Adds the handle wrapper to the object state table, filtering for duplicate handle retrieval.
            std::unique_lock<std::mutex> lock(state_table_mutex_);
            if (state_table_.InsertWrapper(wrapper->GetCaptureId(), wrapper))
            {
                dx12_state_tracker::InitializeState<Wrapper>(
                    wrapper, create_call_id, static_cast<void*>(nullptr), create_parameter_buffer);
            }
        }
    }

    template <typename Wrapper>
    void RemoveEntry(typename Wrapper* wrapper)
    {
        if (wrapper != nullptr)
        {
            // Scope the state table mutex lock because DestroyState also modifies the state table and will attempt to
            // lock the mutex.
            {
                std::unique_lock<std::mutex> lock(state_table_mutex_);
                if (!state_table_.RemoveWrapper(wrapper))
                {
                    // TODO (GH #83): Once tracking is complete and all wrappers are tracked, enable this warning.
                    // Disable it for now in order to prevent redundant log messages.
                    // GFXRECON_LOG_WARNING(
                    //    "Attempting to remove entry from state tracker for object that is not being tracked");
                }
            }

            DestroyState(wrapper);
        }
    }

    void TrackOpenExistingHeapFromAddress(void** heap, const void* address);

    void TrackFenceSetEventOnCompletion(ID3D12Fence_Wrapper* fence, UINT64 value, HANDLE event);

    void TrackFenceSignal(ID3D12Fence_Wrapper* fence, UINT64 value);

    void TrackCommand(ID3D12GraphicsCommandList_Wrapper* list_wrapper,
                      format::ApiCallId                  call_id,
                      const util::MemoryOutputStream*    parameter_buffer);

  private:
    template <typename Wrapper>
    void DestroyState(Wrapper* wrapper)
    {
        assert(wrapper != nullptr);

        // Tracked state is stored in the wrapper's info struct as a shared pointer. It may need to exist after
        // wrapper is no longer being tracked--for example, if another tracked state needs to create a temporary copy of
        // the wrapped object. The tracked state will be freed when all dependent object wrappers are destroyed, so
        // nothing needs to be destroyed here.
    }

  private:
    std::mutex     state_table_mutex_;
    Dx12StateTable state_table_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_DX12_STATE_TRACKER_H
