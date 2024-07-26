/*
** Copyright (c) 2021-2023 LunarG, Inc.
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

/*
** This file is generated from dx12_add_entries_header_generator.py.
**
*/

#ifndef  GFXRECON_GENERATED_DX12_ADD_ENTRIES_H
#define  GFXRECON_GENERATED_DX12_ADD_ENTRIES_H

#include "generated/generated_dx12_wrapper_creators.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

template <typename Wrapper, typename ParentWrapper>
void AddEntry(typename void** new_handle, format::ApiCallId create_call_id, ParentWrapper* create_object_wrapper, const util::MemoryOutputStream* create_parameter_buffer, std::mutex &state_table_mutex, Dx12StateTable &state_table)
{
    assert(create_object_wrapper != nullptr);
    if (*new_handle != nullptr)
    {
        auto wrapper = reinterpret_cast<Wrapper*>(*new_handle);

        // Adds the handle wrapper to the object state table, filtering for duplicate handle retrieval.
        std::unique_lock<std::mutex> lock(state_table_mutex);
        if (state_table.InsertWrapper(wrapper->GetCaptureId(), wrapper))
        {
            dx12_state_tracker::InitializeState<Wrapper, ParentWrapper>(wrapper, create_call_id, create_object_wrapper, create_parameter_buffer);
        }
    }
}

template <typename Wrapper>
void AddEntry(typename void** new_handle, format::ApiCallId create_call_id, void* create_object_wrapper, const util::MemoryOutputStream* create_parameter_buffer, std::mutex &state_table_mutex, Dx12StateTable &state_table)
{
    assert(create_object_wrapper == nullptr);
    if (*new_handle != nullptr)
    {
        auto wrapper = reinterpret_cast<Wrapper*>(*new_handle);

        // Adds the handle wrapper to the object state table, filtering for duplicate handle retrieval.
        std::unique_lock<std::mutex> lock(state_table_mutex);
        if (state_table.InsertWrapper(wrapper->GetCaptureId(), wrapper))
        {
            dx12_state_tracker::InitializeState<Wrapper>(wrapper, create_call_id, static_cast<void*>(nullptr), create_parameter_buffer);
        }
    }
}


template <typename ParentWrapper>
const std::unordered_map<IID, std::function<void(typename void**, format::ApiCallId, ParentWrapper*, const util::MemoryOutputStream*, std::mutex &state_table_mutex, Dx12StateTable &state_table)>,IidHash> kAddEntryFunctionTable
{
    { IID_ID3D12RootSignature, AddEntry<ID3D12RootSignature_Wrapper, ParentWrapper> },
    { IID_ID3D12RootSignatureDeserializer, AddEntry<ID3D12RootSignatureDeserializer_Wrapper, ParentWrapper> },
    { IID_ID3D12VersionedRootSignatureDeserializer, AddEntry<ID3D12VersionedRootSignatureDeserializer_Wrapper, ParentWrapper> },
    { IID_ID3D12CommandAllocator, AddEntry<ID3D12CommandAllocator_Wrapper, ParentWrapper> },
    { IID_ID3D12Fence, AddEntry<ID3D12Fence_Wrapper, ParentWrapper> },
    { IID_ID3D12Fence1, AddEntry<ID3D12Fence_Wrapper, ParentWrapper> },
    { IID_ID3D12PipelineState, AddEntry<ID3D12PipelineState_Wrapper, ParentWrapper> },
    { IID_ID3D12DescriptorHeap, AddEntry<ID3D12DescriptorHeap_Wrapper, ParentWrapper> },
    { IID_ID3D12QueryHeap, AddEntry<ID3D12QueryHeap_Wrapper, ParentWrapper> },
    { IID_ID3D12CommandSignature, AddEntry<ID3D12CommandSignature_Wrapper, ParentWrapper> },
    { IID_ID3D12CommandQueue, AddEntry<ID3D12CommandQueue_Wrapper, ParentWrapper> },
    { IID_ID3D12PipelineLibrary, AddEntry<ID3D12PipelineLibrary_Wrapper, ParentWrapper> },
    { IID_ID3D12PipelineLibrary1, AddEntry<ID3D12PipelineLibrary_Wrapper, ParentWrapper> },
    { IID_ID3D12LifetimeOwner, AddEntry<ID3D12LifetimeOwner_Wrapper, ParentWrapper> },
    { IID_ID3D12SwapChainAssistant, AddEntry<ID3D12SwapChainAssistant_Wrapper, ParentWrapper> },
    { IID_ID3D12LifetimeTracker, AddEntry<ID3D12LifetimeTracker_Wrapper, ParentWrapper> },
    { IID_ID3D12StateObject, AddEntry<ID3D12StateObject_Wrapper, ParentWrapper> },
    { IID_ID3D12StateObjectProperties, AddEntry<ID3D12StateObjectProperties_Wrapper, ParentWrapper> },
    { IID_ID3D12StateObjectProperties1, AddEntry<ID3D12StateObjectProperties_Wrapper, ParentWrapper> },
    { IID_ID3D12WorkGraphProperties, AddEntry<ID3D12WorkGraphProperties_Wrapper, ParentWrapper> },
    { IID_ID3D12DeviceRemovedExtendedDataSettings, AddEntry<ID3D12DeviceRemovedExtendedDataSettings_Wrapper, ParentWrapper> },
    { IID_ID3D12DeviceRemovedExtendedDataSettings1, AddEntry<ID3D12DeviceRemovedExtendedDataSettings_Wrapper, ParentWrapper> },
    { IID_ID3D12DeviceRemovedExtendedDataSettings2, AddEntry<ID3D12DeviceRemovedExtendedDataSettings_Wrapper, ParentWrapper> },
    { IID_ID3D12DeviceRemovedExtendedData, AddEntry<ID3D12DeviceRemovedExtendedData_Wrapper, ParentWrapper> },
    { IID_ID3D12DeviceRemovedExtendedData1, AddEntry<ID3D12DeviceRemovedExtendedData_Wrapper, ParentWrapper> },
    { IID_ID3D12DeviceRemovedExtendedData2, AddEntry<ID3D12DeviceRemovedExtendedData_Wrapper, ParentWrapper> },
    { IID_ID3D12ProtectedResourceSession, AddEntry<ID3D12ProtectedResourceSession_Wrapper, ParentWrapper> },
    { IID_ID3D12ProtectedResourceSession1, AddEntry<ID3D12ProtectedResourceSession_Wrapper, ParentWrapper> },
    { IID_ID3D12Resource, AddEntry<ID3D12Resource_Wrapper, ParentWrapper> },
    { IID_ID3D12Resource1, AddEntry<ID3D12Resource_Wrapper, ParentWrapper> },
    { IID_ID3D12Resource2, AddEntry<ID3D12Resource_Wrapper, ParentWrapper> },
    { IID_ID3D12Heap, AddEntry<ID3D12Heap_Wrapper, ParentWrapper> },
    { IID_ID3D12Heap1, AddEntry<ID3D12Heap_Wrapper, ParentWrapper> },
    { IID_ID3D12MetaCommand, AddEntry<ID3D12MetaCommand_Wrapper, ParentWrapper> },
    { IID_ID3D12ShaderCacheSession, AddEntry<ID3D12ShaderCacheSession_Wrapper, ParentWrapper> },
    { IID_ID3D12Device, AddEntry<ID3D12Device_Wrapper, ParentWrapper> },
    { IID_ID3D12Device1, AddEntry<ID3D12Device_Wrapper, ParentWrapper> },
    { IID_ID3D12Device2, AddEntry<ID3D12Device_Wrapper, ParentWrapper> },
    { IID_ID3D12Device3, AddEntry<ID3D12Device_Wrapper, ParentWrapper> },
    { IID_ID3D12Device4, AddEntry<ID3D12Device_Wrapper, ParentWrapper> },
    { IID_ID3D12Device5, AddEntry<ID3D12Device_Wrapper, ParentWrapper> },
    { IID_ID3D12Device6, AddEntry<ID3D12Device_Wrapper, ParentWrapper> },
    { IID_ID3D12Device7, AddEntry<ID3D12Device_Wrapper, ParentWrapper> },
    { IID_ID3D12Device8, AddEntry<ID3D12Device_Wrapper, ParentWrapper> },
    { IID_ID3D12Device9, AddEntry<ID3D12Device_Wrapper, ParentWrapper> },
    { IID_ID3D12Device10, AddEntry<ID3D12Device_Wrapper, ParentWrapper> },
    { IID_ID3D12Device11, AddEntry<ID3D12Device_Wrapper, ParentWrapper> },
    { IID_ID3D12Device12, AddEntry<ID3D12Device_Wrapper, ParentWrapper> },
    { IID_ID3D12Device13, AddEntry<ID3D12Device_Wrapper, ParentWrapper> },
    { IID_ID3D12Device14, AddEntry<ID3D12Device_Wrapper, ParentWrapper> },
    { IID_ID3D12VirtualizationGuestDevice, AddEntry<ID3D12VirtualizationGuestDevice_Wrapper, ParentWrapper> },
    { IID_ID3D12Tools, AddEntry<ID3D12Tools_Wrapper, ParentWrapper> },
    { IID_ID3D12Tools1, AddEntry<ID3D12Tools_Wrapper, ParentWrapper> },
    { IID_ID3D12PageableTools, AddEntry<ID3D12PageableTools_Wrapper, ParentWrapper> },
    { IID_ID3D12DeviceTools, AddEntry<ID3D12DeviceTools_Wrapper, ParentWrapper> },
    { IID_ID3D12SDKConfiguration, AddEntry<ID3D12SDKConfiguration_Wrapper, ParentWrapper> },
    { IID_ID3D12SDKConfiguration1, AddEntry<ID3D12SDKConfiguration_Wrapper, ParentWrapper> },
    { IID_ID3D12DeviceFactory, AddEntry<ID3D12DeviceFactory_Wrapper, ParentWrapper> },
    { IID_ID3D12DeviceConfiguration, AddEntry<ID3D12DeviceConfiguration_Wrapper, ParentWrapper> },
    { IID_ID3D12DeviceConfiguration1, AddEntry<ID3D12DeviceConfiguration_Wrapper, ParentWrapper> },
    { IID_ID3D12CommandList, AddEntry<ID3D12CommandList_Wrapper, ParentWrapper> },
    { IID_ID3D12GraphicsCommandList, AddEntry<ID3D12CommandList_Wrapper, ParentWrapper> },
    { IID_ID3D12GraphicsCommandList1, AddEntry<ID3D12CommandList_Wrapper, ParentWrapper> },
    { IID_ID3D12GraphicsCommandList2, AddEntry<ID3D12CommandList_Wrapper, ParentWrapper> },
    { IID_ID3D12GraphicsCommandList3, AddEntry<ID3D12CommandList_Wrapper, ParentWrapper> },
    { IID_ID3D12GraphicsCommandList4, AddEntry<ID3D12CommandList_Wrapper, ParentWrapper> },
    { IID_ID3D12GraphicsCommandList5, AddEntry<ID3D12CommandList_Wrapper, ParentWrapper> },
    { IID_ID3D12GraphicsCommandList6, AddEntry<ID3D12CommandList_Wrapper, ParentWrapper> },
    { IID_ID3D12GraphicsCommandList7, AddEntry<ID3D12CommandList_Wrapper, ParentWrapper> },
    { IID_ID3D12GraphicsCommandList8, AddEntry<ID3D12CommandList_Wrapper, ParentWrapper> },
    { IID_ID3D12GraphicsCommandList9, AddEntry<ID3D12CommandList_Wrapper, ParentWrapper> },
    { IID_ID3D12GraphicsCommandList10, AddEntry<ID3D12CommandList_Wrapper, ParentWrapper> },
    { IID_ID3D12DSRDeviceFactory, AddEntry<ID3D12DSRDeviceFactory_Wrapper, ParentWrapper> },
    { IID_ID3D12GBVDiagnostics, AddEntry<ID3D12GBVDiagnostics_Wrapper, ParentWrapper> },
    { IID_ID3D10Blob, AddEntry<ID3D10Blob_Wrapper, ParentWrapper> },
    { IID_ID3DDestructionNotifier, AddEntry<ID3DDestructionNotifier_Wrapper, ParentWrapper> },
    { IID_ID3D12Debug1, AddEntry<ID3D12Debug1_Wrapper, ParentWrapper> },
    { IID_ID3D12Debug2, AddEntry<ID3D12Debug2_Wrapper, ParentWrapper> },
    { IID_ID3D12Debug, AddEntry<ID3D12Debug_Wrapper, ParentWrapper> },
    { IID_ID3D12Debug1, AddEntry<ID3D12Debug_Wrapper, ParentWrapper> },
    { IID_ID3D12Debug2, AddEntry<ID3D12Debug_Wrapper, ParentWrapper> },
    { IID_ID3D12Debug3, AddEntry<ID3D12Debug_Wrapper, ParentWrapper> },
    { IID_ID3D12Debug4, AddEntry<ID3D12Debug_Wrapper, ParentWrapper> },
    { IID_ID3D12Debug5, AddEntry<ID3D12Debug_Wrapper, ParentWrapper> },
    { IID_ID3D12Debug6, AddEntry<ID3D12Debug_Wrapper, ParentWrapper> },
    { IID_ID3D12DebugDevice1, AddEntry<ID3D12DebugDevice1_Wrapper, ParentWrapper> },
    { IID_ID3D12DebugDevice, AddEntry<ID3D12DebugDevice_Wrapper, ParentWrapper> },
    { IID_ID3D12DebugDevice1, AddEntry<ID3D12DebugDevice_Wrapper, ParentWrapper> },
    { IID_ID3D12DebugDevice2, AddEntry<ID3D12DebugDevice_Wrapper, ParentWrapper> },
    { IID_ID3D12DebugCommandQueue, AddEntry<ID3D12DebugCommandQueue_Wrapper, ParentWrapper> },
    { IID_ID3D12DebugCommandQueue1, AddEntry<ID3D12DebugCommandQueue_Wrapper, ParentWrapper> },
    { IID_ID3D12DebugCommandList1, AddEntry<ID3D12DebugCommandList1_Wrapper, ParentWrapper> },
    { IID_ID3D12DebugCommandList, AddEntry<ID3D12DebugCommandList_Wrapper, ParentWrapper> },
    { IID_ID3D12DebugCommandList1, AddEntry<ID3D12DebugCommandList_Wrapper, ParentWrapper> },
    { IID_ID3D12DebugCommandList2, AddEntry<ID3D12DebugCommandList_Wrapper, ParentWrapper> },
    { IID_ID3D12DebugCommandList3, AddEntry<ID3D12DebugCommandList_Wrapper, ParentWrapper> },
    { IID_ID3D12SharingContract, AddEntry<ID3D12SharingContract_Wrapper, ParentWrapper> },
    { IID_ID3D12ManualWriteTrackingResource, AddEntry<ID3D12ManualWriteTrackingResource_Wrapper, ParentWrapper> },
    { IID_ID3D12InfoQueue, AddEntry<ID3D12InfoQueue_Wrapper, ParentWrapper> },
    { IID_ID3D12InfoQueue1, AddEntry<ID3D12InfoQueue_Wrapper, ParentWrapper> },
    { IID_ID3D11DepthStencilState, AddEntry<ID3D11DepthStencilState_Wrapper, ParentWrapper> },
    { IID_ID3D11Buffer, AddEntry<ID3D11Buffer_Wrapper, ParentWrapper> },
    { IID_ID3D11Texture1D, AddEntry<ID3D11Texture1D_Wrapper, ParentWrapper> },
    { IID_ID3D11DepthStencilView, AddEntry<ID3D11DepthStencilView_Wrapper, ParentWrapper> },
    { IID_ID3D11VertexShader, AddEntry<ID3D11VertexShader_Wrapper, ParentWrapper> },
    { IID_ID3D11HullShader, AddEntry<ID3D11HullShader_Wrapper, ParentWrapper> },
    { IID_ID3D11DomainShader, AddEntry<ID3D11DomainShader_Wrapper, ParentWrapper> },
    { IID_ID3D11GeometryShader, AddEntry<ID3D11GeometryShader_Wrapper, ParentWrapper> },
    { IID_ID3D11PixelShader, AddEntry<ID3D11PixelShader_Wrapper, ParentWrapper> },
    { IID_ID3D11ComputeShader, AddEntry<ID3D11ComputeShader_Wrapper, ParentWrapper> },
    { IID_ID3D11InputLayout, AddEntry<ID3D11InputLayout_Wrapper, ParentWrapper> },
    { IID_ID3D11SamplerState, AddEntry<ID3D11SamplerState_Wrapper, ParentWrapper> },
    { IID_ID3D11Predicate, AddEntry<ID3D11Predicate_Wrapper, ParentWrapper> },
    { IID_ID3D11Counter, AddEntry<ID3D11Counter_Wrapper, ParentWrapper> },
    { IID_ID3D11ClassInstance, AddEntry<ID3D11ClassInstance_Wrapper, ParentWrapper> },
    { IID_ID3D11ClassLinkage, AddEntry<ID3D11ClassLinkage_Wrapper, ParentWrapper> },
    { IID_ID3D11CommandList, AddEntry<ID3D11CommandList_Wrapper, ParentWrapper> },
    { IID_ID3D11VideoDecoder, AddEntry<ID3D11VideoDecoder_Wrapper, ParentWrapper> },
    { IID_ID3D11VideoProcessor, AddEntry<ID3D11VideoProcessor_Wrapper, ParentWrapper> },
    { IID_ID3D11AuthenticatedChannel, AddEntry<ID3D11AuthenticatedChannel_Wrapper, ParentWrapper> },
    { IID_ID3D11CryptoSession, AddEntry<ID3D11CryptoSession_Wrapper, ParentWrapper> },
    { IID_ID3D11VideoDecoderOutputView, AddEntry<ID3D11VideoDecoderOutputView_Wrapper, ParentWrapper> },
    { IID_ID3D11VideoProcessorInputView, AddEntry<ID3D11VideoProcessorInputView_Wrapper, ParentWrapper> },
    { IID_ID3D11VideoProcessorOutputView, AddEntry<ID3D11VideoProcessorOutputView_Wrapper, ParentWrapper> },
    { IID_ID3D11BlendState, AddEntry<ID3D11BlendState_Wrapper, ParentWrapper> },
    { IID_ID3D11BlendState1, AddEntry<ID3D11BlendState_Wrapper, ParentWrapper> },
    { IID_ID3DDeviceContextState, AddEntry<ID3DDeviceContextState_Wrapper, ParentWrapper> },
    { IID_ID3D11VideoProcessorEnumerator, AddEntry<ID3D11VideoProcessorEnumerator_Wrapper, ParentWrapper> },
    { IID_ID3D11VideoProcessorEnumerator1, AddEntry<ID3D11VideoProcessorEnumerator_Wrapper, ParentWrapper> },
    { IID_ID3DUserDefinedAnnotation, AddEntry<ID3DUserDefinedAnnotation_Wrapper, ParentWrapper> },
    { IID_ID3D11Texture2D, AddEntry<ID3D11Texture2D_Wrapper, ParentWrapper> },
    { IID_ID3D11Texture2D1, AddEntry<ID3D11Texture2D_Wrapper, ParentWrapper> },
    { IID_ID3D11Texture3D, AddEntry<ID3D11Texture3D_Wrapper, ParentWrapper> },
    { IID_ID3D11Texture3D1, AddEntry<ID3D11Texture3D_Wrapper, ParentWrapper> },
    { IID_ID3D11RasterizerState, AddEntry<ID3D11RasterizerState_Wrapper, ParentWrapper> },
    { IID_ID3D11RasterizerState1, AddEntry<ID3D11RasterizerState_Wrapper, ParentWrapper> },
    { IID_ID3D11RasterizerState2, AddEntry<ID3D11RasterizerState_Wrapper, ParentWrapper> },
    { IID_ID3D11ShaderResourceView, AddEntry<ID3D11ShaderResourceView_Wrapper, ParentWrapper> },
    { IID_ID3D11ShaderResourceView1, AddEntry<ID3D11ShaderResourceView_Wrapper, ParentWrapper> },
    { IID_ID3D11RenderTargetView, AddEntry<ID3D11RenderTargetView_Wrapper, ParentWrapper> },
    { IID_ID3D11RenderTargetView1, AddEntry<ID3D11RenderTargetView_Wrapper, ParentWrapper> },
    { IID_ID3D11UnorderedAccessView, AddEntry<ID3D11UnorderedAccessView_Wrapper, ParentWrapper> },
    { IID_ID3D11UnorderedAccessView1, AddEntry<ID3D11UnorderedAccessView_Wrapper, ParentWrapper> },
    { IID_ID3D11Query, AddEntry<ID3D11Query_Wrapper, ParentWrapper> },
    { IID_ID3D11Query1, AddEntry<ID3D11Query_Wrapper, ParentWrapper> },
    { IID_ID3D11Fence, AddEntry<ID3D11Fence_Wrapper, ParentWrapper> },
    { IID_ID3D11DeviceContext, AddEntry<ID3D11DeviceContext_Wrapper, ParentWrapper> },
    { IID_ID3D11DeviceContext1, AddEntry<ID3D11DeviceContext_Wrapper, ParentWrapper> },
    { IID_ID3D11DeviceContext2, AddEntry<ID3D11DeviceContext_Wrapper, ParentWrapper> },
    { IID_ID3D11DeviceContext3, AddEntry<ID3D11DeviceContext_Wrapper, ParentWrapper> },
    { IID_ID3D11DeviceContext4, AddEntry<ID3D11DeviceContext_Wrapper, ParentWrapper> },
    { IID_ID3D11Device, AddEntry<ID3D11Device_Wrapper, ParentWrapper> },
    { IID_ID3D11Device1, AddEntry<ID3D11Device_Wrapper, ParentWrapper> },
    { IID_ID3D11Device2, AddEntry<ID3D11Device_Wrapper, ParentWrapper> },
    { IID_ID3D11Device3, AddEntry<ID3D11Device_Wrapper, ParentWrapper> },
    { IID_ID3D11Device4, AddEntry<ID3D11Device_Wrapper, ParentWrapper> },
    { IID_ID3D11Device5, AddEntry<ID3D11Device_Wrapper, ParentWrapper> },
    { IID_ID3D11Multithread, AddEntry<ID3D11Multithread_Wrapper, ParentWrapper> },
    { IID_ID3D11VideoDevice, AddEntry<ID3D11VideoDevice_Wrapper, ParentWrapper> },
    { IID_ID3D11VideoDevice1, AddEntry<ID3D11VideoDevice_Wrapper, ParentWrapper> },
    { IID_ID3D11VideoDevice2, AddEntry<ID3D11VideoDevice_Wrapper, ParentWrapper> },
    { IID_ID3D11VideoContext, AddEntry<ID3D11VideoContext_Wrapper, ParentWrapper> },
    { IID_ID3D11VideoContext1, AddEntry<ID3D11VideoContext_Wrapper, ParentWrapper> },
    { IID_ID3D11VideoContext2, AddEntry<ID3D11VideoContext_Wrapper, ParentWrapper> },
    { IID_ID3D11VideoContext3, AddEntry<ID3D11VideoContext_Wrapper, ParentWrapper> },
    { IID_IDXGIKeyedMutex, AddEntry<IDXGIKeyedMutex_Wrapper, ParentWrapper> },
    { IID_IDXGIDisplayControl, AddEntry<IDXGIDisplayControl_Wrapper, ParentWrapper> },
    { IID_IDXGIOutputDuplication, AddEntry<IDXGIOutputDuplication_Wrapper, ParentWrapper> },
    { IID_IDXGISurface, AddEntry<IDXGISurface_Wrapper, ParentWrapper> },
    { IID_IDXGISurface1, AddEntry<IDXGISurface_Wrapper, ParentWrapper> },
    { IID_IDXGISurface2, AddEntry<IDXGISurface_Wrapper, ParentWrapper> },
    { IID_IDXGIResource, AddEntry<IDXGIResource_Wrapper, ParentWrapper> },
    { IID_IDXGIResource1, AddEntry<IDXGIResource_Wrapper, ParentWrapper> },
    { IID_IDXGIDecodeSwapChain, AddEntry<IDXGIDecodeSwapChain_Wrapper, ParentWrapper> },
    { IID_IDXGIFactoryMedia, AddEntry<IDXGIFactoryMedia_Wrapper, ParentWrapper> },
    { IID_IDXGISwapChainMedia, AddEntry<IDXGISwapChainMedia_Wrapper, ParentWrapper> },
    { IID_IDXGISwapChain, AddEntry<IDXGISwapChain_Wrapper, ParentWrapper> },
    { IID_IDXGISwapChain1, AddEntry<IDXGISwapChain_Wrapper, ParentWrapper> },
    { IID_IDXGISwapChain2, AddEntry<IDXGISwapChain_Wrapper, ParentWrapper> },
    { IID_IDXGISwapChain3, AddEntry<IDXGISwapChain_Wrapper, ParentWrapper> },
    { IID_IDXGISwapChain4, AddEntry<IDXGISwapChain_Wrapper, ParentWrapper> },
    { IID_IDXGIDevice, AddEntry<IDXGIDevice_Wrapper, ParentWrapper> },
    { IID_IDXGIDevice1, AddEntry<IDXGIDevice_Wrapper, ParentWrapper> },
    { IID_IDXGIDevice2, AddEntry<IDXGIDevice_Wrapper, ParentWrapper> },
    { IID_IDXGIDevice3, AddEntry<IDXGIDevice_Wrapper, ParentWrapper> },
    { IID_IDXGIDevice4, AddEntry<IDXGIDevice_Wrapper, ParentWrapper> },
    { IID_IDXGIAdapter, AddEntry<IDXGIAdapter_Wrapper, ParentWrapper> },
    { IID_IDXGIAdapter1, AddEntry<IDXGIAdapter_Wrapper, ParentWrapper> },
    { IID_IDXGIAdapter2, AddEntry<IDXGIAdapter_Wrapper, ParentWrapper> },
    { IID_IDXGIAdapter3, AddEntry<IDXGIAdapter_Wrapper, ParentWrapper> },
    { IID_IDXGIAdapter4, AddEntry<IDXGIAdapter_Wrapper, ParentWrapper> },
    { IID_IDXGIOutput, AddEntry<IDXGIOutput_Wrapper, ParentWrapper> },
    { IID_IDXGIOutput1, AddEntry<IDXGIOutput_Wrapper, ParentWrapper> },
    { IID_IDXGIOutput2, AddEntry<IDXGIOutput_Wrapper, ParentWrapper> },
    { IID_IDXGIOutput3, AddEntry<IDXGIOutput_Wrapper, ParentWrapper> },
    { IID_IDXGIOutput4, AddEntry<IDXGIOutput_Wrapper, ParentWrapper> },
    { IID_IDXGIOutput5, AddEntry<IDXGIOutput_Wrapper, ParentWrapper> },
    { IID_IDXGIOutput6, AddEntry<IDXGIOutput_Wrapper, ParentWrapper> },
    { IID_IDXGIFactory, AddEntry<IDXGIFactory_Wrapper, ParentWrapper> },
    { IID_IDXGIFactory1, AddEntry<IDXGIFactory_Wrapper, ParentWrapper> },
    { IID_IDXGIFactory2, AddEntry<IDXGIFactory_Wrapper, ParentWrapper> },
    { IID_IDXGIFactory3, AddEntry<IDXGIFactory_Wrapper, ParentWrapper> },
    { IID_IDXGIFactory4, AddEntry<IDXGIFactory_Wrapper, ParentWrapper> },
    { IID_IDXGIFactory5, AddEntry<IDXGIFactory_Wrapper, ParentWrapper> },
    { IID_IDXGIFactory6, AddEntry<IDXGIFactory_Wrapper, ParentWrapper> },
    { IID_IDXGIFactory7, AddEntry<IDXGIFactory_Wrapper, ParentWrapper> },
};

const std::unordered_map<IID, std::function<void(typename void**, format::ApiCallId, void*, const util::MemoryOutputStream*, std::mutex &state_table_mutex, Dx12StateTable &state_table)>,IidHash> kAddEntryVoidFunctionTable
{
    { IID_ID3D12RootSignature, AddEntry<ID3D12RootSignature_Wrapper> },
    { IID_ID3D12RootSignatureDeserializer, AddEntry<ID3D12RootSignatureDeserializer_Wrapper> },
    { IID_ID3D12VersionedRootSignatureDeserializer, AddEntry<ID3D12VersionedRootSignatureDeserializer_Wrapper> },
    { IID_ID3D12CommandAllocator, AddEntry<ID3D12CommandAllocator_Wrapper> },
    { IID_ID3D12Fence, AddEntry<ID3D12Fence_Wrapper> },
    { IID_ID3D12Fence1, AddEntry<ID3D12Fence_Wrapper> },
    { IID_ID3D12PipelineState, AddEntry<ID3D12PipelineState_Wrapper> },
    { IID_ID3D12DescriptorHeap, AddEntry<ID3D12DescriptorHeap_Wrapper> },
    { IID_ID3D12QueryHeap, AddEntry<ID3D12QueryHeap_Wrapper> },
    { IID_ID3D12CommandSignature, AddEntry<ID3D12CommandSignature_Wrapper> },
    { IID_ID3D12CommandQueue, AddEntry<ID3D12CommandQueue_Wrapper> },
    { IID_ID3D12PipelineLibrary, AddEntry<ID3D12PipelineLibrary_Wrapper> },
    { IID_ID3D12PipelineLibrary1, AddEntry<ID3D12PipelineLibrary_Wrapper> },
    { IID_ID3D12LifetimeOwner, AddEntry<ID3D12LifetimeOwner_Wrapper> },
    { IID_ID3D12SwapChainAssistant, AddEntry<ID3D12SwapChainAssistant_Wrapper> },
    { IID_ID3D12LifetimeTracker, AddEntry<ID3D12LifetimeTracker_Wrapper> },
    { IID_ID3D12StateObject, AddEntry<ID3D12StateObject_Wrapper> },
    { IID_ID3D12StateObjectProperties, AddEntry<ID3D12StateObjectProperties_Wrapper> },
    { IID_ID3D12StateObjectProperties1, AddEntry<ID3D12StateObjectProperties_Wrapper> },
    { IID_ID3D12WorkGraphProperties, AddEntry<ID3D12WorkGraphProperties_Wrapper> },
    { IID_ID3D12DeviceRemovedExtendedDataSettings, AddEntry<ID3D12DeviceRemovedExtendedDataSettings_Wrapper> },
    { IID_ID3D12DeviceRemovedExtendedDataSettings1, AddEntry<ID3D12DeviceRemovedExtendedDataSettings_Wrapper> },
    { IID_ID3D12DeviceRemovedExtendedDataSettings2, AddEntry<ID3D12DeviceRemovedExtendedDataSettings_Wrapper> },
    { IID_ID3D12DeviceRemovedExtendedData, AddEntry<ID3D12DeviceRemovedExtendedData_Wrapper> },
    { IID_ID3D12DeviceRemovedExtendedData1, AddEntry<ID3D12DeviceRemovedExtendedData_Wrapper> },
    { IID_ID3D12DeviceRemovedExtendedData2, AddEntry<ID3D12DeviceRemovedExtendedData_Wrapper> },
    { IID_ID3D12ProtectedResourceSession, AddEntry<ID3D12ProtectedResourceSession_Wrapper> },
    { IID_ID3D12ProtectedResourceSession1, AddEntry<ID3D12ProtectedResourceSession_Wrapper> },
    { IID_ID3D12Resource, AddEntry<ID3D12Resource_Wrapper> },
    { IID_ID3D12Resource1, AddEntry<ID3D12Resource_Wrapper> },
    { IID_ID3D12Resource2, AddEntry<ID3D12Resource_Wrapper> },
    { IID_ID3D12Heap, AddEntry<ID3D12Heap_Wrapper> },
    { IID_ID3D12Heap1, AddEntry<ID3D12Heap_Wrapper> },
    { IID_ID3D12MetaCommand, AddEntry<ID3D12MetaCommand_Wrapper> },
    { IID_ID3D12ShaderCacheSession, AddEntry<ID3D12ShaderCacheSession_Wrapper> },
    { IID_ID3D12Device, AddEntry<ID3D12Device_Wrapper> },
    { IID_ID3D12Device1, AddEntry<ID3D12Device_Wrapper> },
    { IID_ID3D12Device2, AddEntry<ID3D12Device_Wrapper> },
    { IID_ID3D12Device3, AddEntry<ID3D12Device_Wrapper> },
    { IID_ID3D12Device4, AddEntry<ID3D12Device_Wrapper> },
    { IID_ID3D12Device5, AddEntry<ID3D12Device_Wrapper> },
    { IID_ID3D12Device6, AddEntry<ID3D12Device_Wrapper> },
    { IID_ID3D12Device7, AddEntry<ID3D12Device_Wrapper> },
    { IID_ID3D12Device8, AddEntry<ID3D12Device_Wrapper> },
    { IID_ID3D12Device9, AddEntry<ID3D12Device_Wrapper> },
    { IID_ID3D12Device10, AddEntry<ID3D12Device_Wrapper> },
    { IID_ID3D12Device11, AddEntry<ID3D12Device_Wrapper> },
    { IID_ID3D12Device12, AddEntry<ID3D12Device_Wrapper> },
    { IID_ID3D12Device13, AddEntry<ID3D12Device_Wrapper> },
    { IID_ID3D12Device14, AddEntry<ID3D12Device_Wrapper> },
    { IID_ID3D12VirtualizationGuestDevice, AddEntry<ID3D12VirtualizationGuestDevice_Wrapper> },
    { IID_ID3D12Tools, AddEntry<ID3D12Tools_Wrapper> },
    { IID_ID3D12Tools1, AddEntry<ID3D12Tools_Wrapper> },
    { IID_ID3D12PageableTools, AddEntry<ID3D12PageableTools_Wrapper> },
    { IID_ID3D12DeviceTools, AddEntry<ID3D12DeviceTools_Wrapper> },
    { IID_ID3D12SDKConfiguration, AddEntry<ID3D12SDKConfiguration_Wrapper> },
    { IID_ID3D12SDKConfiguration1, AddEntry<ID3D12SDKConfiguration_Wrapper> },
    { IID_ID3D12DeviceFactory, AddEntry<ID3D12DeviceFactory_Wrapper> },
    { IID_ID3D12DeviceConfiguration, AddEntry<ID3D12DeviceConfiguration_Wrapper> },
    { IID_ID3D12DeviceConfiguration1, AddEntry<ID3D12DeviceConfiguration_Wrapper> },
    { IID_ID3D12CommandList, AddEntry<ID3D12CommandList_Wrapper> },
    { IID_ID3D12GraphicsCommandList, AddEntry<ID3D12CommandList_Wrapper> },
    { IID_ID3D12GraphicsCommandList1, AddEntry<ID3D12CommandList_Wrapper> },
    { IID_ID3D12GraphicsCommandList2, AddEntry<ID3D12CommandList_Wrapper> },
    { IID_ID3D12GraphicsCommandList3, AddEntry<ID3D12CommandList_Wrapper> },
    { IID_ID3D12GraphicsCommandList4, AddEntry<ID3D12CommandList_Wrapper> },
    { IID_ID3D12GraphicsCommandList5, AddEntry<ID3D12CommandList_Wrapper> },
    { IID_ID3D12GraphicsCommandList6, AddEntry<ID3D12CommandList_Wrapper> },
    { IID_ID3D12GraphicsCommandList7, AddEntry<ID3D12CommandList_Wrapper> },
    { IID_ID3D12GraphicsCommandList8, AddEntry<ID3D12CommandList_Wrapper> },
    { IID_ID3D12GraphicsCommandList9, AddEntry<ID3D12CommandList_Wrapper> },
    { IID_ID3D12GraphicsCommandList10, AddEntry<ID3D12CommandList_Wrapper> },
    { IID_ID3D12DSRDeviceFactory, AddEntry<ID3D12DSRDeviceFactory_Wrapper> },
    { IID_ID3D12GBVDiagnostics, AddEntry<ID3D12GBVDiagnostics_Wrapper> },
    { IID_ID3D10Blob, AddEntry<ID3D10Blob_Wrapper> },
    { IID_ID3DDestructionNotifier, AddEntry<ID3DDestructionNotifier_Wrapper> },
    { IID_ID3D12Debug1, AddEntry<ID3D12Debug1_Wrapper> },
    { IID_ID3D12Debug2, AddEntry<ID3D12Debug2_Wrapper> },
    { IID_ID3D12Debug, AddEntry<ID3D12Debug_Wrapper> },
    { IID_ID3D12Debug1, AddEntry<ID3D12Debug_Wrapper> },
    { IID_ID3D12Debug2, AddEntry<ID3D12Debug_Wrapper> },
    { IID_ID3D12Debug3, AddEntry<ID3D12Debug_Wrapper> },
    { IID_ID3D12Debug4, AddEntry<ID3D12Debug_Wrapper> },
    { IID_ID3D12Debug5, AddEntry<ID3D12Debug_Wrapper> },
    { IID_ID3D12Debug6, AddEntry<ID3D12Debug_Wrapper> },
    { IID_ID3D12DebugDevice1, AddEntry<ID3D12DebugDevice1_Wrapper> },
    { IID_ID3D12DebugDevice, AddEntry<ID3D12DebugDevice_Wrapper> },
    { IID_ID3D12DebugDevice1, AddEntry<ID3D12DebugDevice_Wrapper> },
    { IID_ID3D12DebugDevice2, AddEntry<ID3D12DebugDevice_Wrapper> },
    { IID_ID3D12DebugCommandQueue, AddEntry<ID3D12DebugCommandQueue_Wrapper> },
    { IID_ID3D12DebugCommandQueue1, AddEntry<ID3D12DebugCommandQueue_Wrapper> },
    { IID_ID3D12DebugCommandList1, AddEntry<ID3D12DebugCommandList1_Wrapper> },
    { IID_ID3D12DebugCommandList, AddEntry<ID3D12DebugCommandList_Wrapper> },
    { IID_ID3D12DebugCommandList1, AddEntry<ID3D12DebugCommandList_Wrapper> },
    { IID_ID3D12DebugCommandList2, AddEntry<ID3D12DebugCommandList_Wrapper> },
    { IID_ID3D12DebugCommandList3, AddEntry<ID3D12DebugCommandList_Wrapper> },
    { IID_ID3D12SharingContract, AddEntry<ID3D12SharingContract_Wrapper> },
    { IID_ID3D12ManualWriteTrackingResource, AddEntry<ID3D12ManualWriteTrackingResource_Wrapper> },
    { IID_ID3D12InfoQueue, AddEntry<ID3D12InfoQueue_Wrapper> },
    { IID_ID3D12InfoQueue1, AddEntry<ID3D12InfoQueue_Wrapper> },
    { IID_ID3D11DepthStencilState, AddEntry<ID3D11DepthStencilState_Wrapper> },
    { IID_ID3D11Buffer, AddEntry<ID3D11Buffer_Wrapper> },
    { IID_ID3D11Texture1D, AddEntry<ID3D11Texture1D_Wrapper> },
    { IID_ID3D11DepthStencilView, AddEntry<ID3D11DepthStencilView_Wrapper> },
    { IID_ID3D11VertexShader, AddEntry<ID3D11VertexShader_Wrapper> },
    { IID_ID3D11HullShader, AddEntry<ID3D11HullShader_Wrapper> },
    { IID_ID3D11DomainShader, AddEntry<ID3D11DomainShader_Wrapper> },
    { IID_ID3D11GeometryShader, AddEntry<ID3D11GeometryShader_Wrapper> },
    { IID_ID3D11PixelShader, AddEntry<ID3D11PixelShader_Wrapper> },
    { IID_ID3D11ComputeShader, AddEntry<ID3D11ComputeShader_Wrapper> },
    { IID_ID3D11InputLayout, AddEntry<ID3D11InputLayout_Wrapper> },
    { IID_ID3D11SamplerState, AddEntry<ID3D11SamplerState_Wrapper> },
    { IID_ID3D11Predicate, AddEntry<ID3D11Predicate_Wrapper> },
    { IID_ID3D11Counter, AddEntry<ID3D11Counter_Wrapper> },
    { IID_ID3D11ClassInstance, AddEntry<ID3D11ClassInstance_Wrapper> },
    { IID_ID3D11ClassLinkage, AddEntry<ID3D11ClassLinkage_Wrapper> },
    { IID_ID3D11CommandList, AddEntry<ID3D11CommandList_Wrapper> },
    { IID_ID3D11VideoDecoder, AddEntry<ID3D11VideoDecoder_Wrapper> },
    { IID_ID3D11VideoProcessor, AddEntry<ID3D11VideoProcessor_Wrapper> },
    { IID_ID3D11AuthenticatedChannel, AddEntry<ID3D11AuthenticatedChannel_Wrapper> },
    { IID_ID3D11CryptoSession, AddEntry<ID3D11CryptoSession_Wrapper> },
    { IID_ID3D11VideoDecoderOutputView, AddEntry<ID3D11VideoDecoderOutputView_Wrapper> },
    { IID_ID3D11VideoProcessorInputView, AddEntry<ID3D11VideoProcessorInputView_Wrapper> },
    { IID_ID3D11VideoProcessorOutputView, AddEntry<ID3D11VideoProcessorOutputView_Wrapper> },
    { IID_ID3D11BlendState, AddEntry<ID3D11BlendState_Wrapper> },
    { IID_ID3D11BlendState1, AddEntry<ID3D11BlendState_Wrapper> },
    { IID_ID3DDeviceContextState, AddEntry<ID3DDeviceContextState_Wrapper> },
    { IID_ID3D11VideoProcessorEnumerator, AddEntry<ID3D11VideoProcessorEnumerator_Wrapper> },
    { IID_ID3D11VideoProcessorEnumerator1, AddEntry<ID3D11VideoProcessorEnumerator_Wrapper> },
    { IID_ID3DUserDefinedAnnotation, AddEntry<ID3DUserDefinedAnnotation_Wrapper> },
    { IID_ID3D11Texture2D, AddEntry<ID3D11Texture2D_Wrapper> },
    { IID_ID3D11Texture2D1, AddEntry<ID3D11Texture2D_Wrapper> },
    { IID_ID3D11Texture3D, AddEntry<ID3D11Texture3D_Wrapper> },
    { IID_ID3D11Texture3D1, AddEntry<ID3D11Texture3D_Wrapper> },
    { IID_ID3D11RasterizerState, AddEntry<ID3D11RasterizerState_Wrapper> },
    { IID_ID3D11RasterizerState1, AddEntry<ID3D11RasterizerState_Wrapper> },
    { IID_ID3D11RasterizerState2, AddEntry<ID3D11RasterizerState_Wrapper> },
    { IID_ID3D11ShaderResourceView, AddEntry<ID3D11ShaderResourceView_Wrapper> },
    { IID_ID3D11ShaderResourceView1, AddEntry<ID3D11ShaderResourceView_Wrapper> },
    { IID_ID3D11RenderTargetView, AddEntry<ID3D11RenderTargetView_Wrapper> },
    { IID_ID3D11RenderTargetView1, AddEntry<ID3D11RenderTargetView_Wrapper> },
    { IID_ID3D11UnorderedAccessView, AddEntry<ID3D11UnorderedAccessView_Wrapper> },
    { IID_ID3D11UnorderedAccessView1, AddEntry<ID3D11UnorderedAccessView_Wrapper> },
    { IID_ID3D11Query, AddEntry<ID3D11Query_Wrapper> },
    { IID_ID3D11Query1, AddEntry<ID3D11Query_Wrapper> },
    { IID_ID3D11Fence, AddEntry<ID3D11Fence_Wrapper> },
    { IID_ID3D11DeviceContext, AddEntry<ID3D11DeviceContext_Wrapper> },
    { IID_ID3D11DeviceContext1, AddEntry<ID3D11DeviceContext_Wrapper> },
    { IID_ID3D11DeviceContext2, AddEntry<ID3D11DeviceContext_Wrapper> },
    { IID_ID3D11DeviceContext3, AddEntry<ID3D11DeviceContext_Wrapper> },
    { IID_ID3D11DeviceContext4, AddEntry<ID3D11DeviceContext_Wrapper> },
    { IID_ID3D11Device, AddEntry<ID3D11Device_Wrapper> },
    { IID_ID3D11Device1, AddEntry<ID3D11Device_Wrapper> },
    { IID_ID3D11Device2, AddEntry<ID3D11Device_Wrapper> },
    { IID_ID3D11Device3, AddEntry<ID3D11Device_Wrapper> },
    { IID_ID3D11Device4, AddEntry<ID3D11Device_Wrapper> },
    { IID_ID3D11Device5, AddEntry<ID3D11Device_Wrapper> },
    { IID_ID3D11Multithread, AddEntry<ID3D11Multithread_Wrapper> },
    { IID_ID3D11VideoDevice, AddEntry<ID3D11VideoDevice_Wrapper> },
    { IID_ID3D11VideoDevice1, AddEntry<ID3D11VideoDevice_Wrapper> },
    { IID_ID3D11VideoDevice2, AddEntry<ID3D11VideoDevice_Wrapper> },
    { IID_ID3D11VideoContext, AddEntry<ID3D11VideoContext_Wrapper> },
    { IID_ID3D11VideoContext1, AddEntry<ID3D11VideoContext_Wrapper> },
    { IID_ID3D11VideoContext2, AddEntry<ID3D11VideoContext_Wrapper> },
    { IID_ID3D11VideoContext3, AddEntry<ID3D11VideoContext_Wrapper> },
    { IID_IDXGIKeyedMutex, AddEntry<IDXGIKeyedMutex_Wrapper> },
    { IID_IDXGIDisplayControl, AddEntry<IDXGIDisplayControl_Wrapper> },
    { IID_IDXGIOutputDuplication, AddEntry<IDXGIOutputDuplication_Wrapper> },
    { IID_IDXGISurface, AddEntry<IDXGISurface_Wrapper> },
    { IID_IDXGISurface1, AddEntry<IDXGISurface_Wrapper> },
    { IID_IDXGISurface2, AddEntry<IDXGISurface_Wrapper> },
    { IID_IDXGIResource, AddEntry<IDXGIResource_Wrapper> },
    { IID_IDXGIResource1, AddEntry<IDXGIResource_Wrapper> },
    { IID_IDXGIDecodeSwapChain, AddEntry<IDXGIDecodeSwapChain_Wrapper> },
    { IID_IDXGIFactoryMedia, AddEntry<IDXGIFactoryMedia_Wrapper> },
    { IID_IDXGISwapChainMedia, AddEntry<IDXGISwapChainMedia_Wrapper> },
    { IID_IDXGISwapChain, AddEntry<IDXGISwapChain_Wrapper> },
    { IID_IDXGISwapChain1, AddEntry<IDXGISwapChain_Wrapper> },
    { IID_IDXGISwapChain2, AddEntry<IDXGISwapChain_Wrapper> },
    { IID_IDXGISwapChain3, AddEntry<IDXGISwapChain_Wrapper> },
    { IID_IDXGISwapChain4, AddEntry<IDXGISwapChain_Wrapper> },
    { IID_IDXGIDevice, AddEntry<IDXGIDevice_Wrapper> },
    { IID_IDXGIDevice1, AddEntry<IDXGIDevice_Wrapper> },
    { IID_IDXGIDevice2, AddEntry<IDXGIDevice_Wrapper> },
    { IID_IDXGIDevice3, AddEntry<IDXGIDevice_Wrapper> },
    { IID_IDXGIDevice4, AddEntry<IDXGIDevice_Wrapper> },
    { IID_IDXGIAdapter, AddEntry<IDXGIAdapter_Wrapper> },
    { IID_IDXGIAdapter1, AddEntry<IDXGIAdapter_Wrapper> },
    { IID_IDXGIAdapter2, AddEntry<IDXGIAdapter_Wrapper> },
    { IID_IDXGIAdapter3, AddEntry<IDXGIAdapter_Wrapper> },
    { IID_IDXGIAdapter4, AddEntry<IDXGIAdapter_Wrapper> },
    { IID_IDXGIOutput, AddEntry<IDXGIOutput_Wrapper> },
    { IID_IDXGIOutput1, AddEntry<IDXGIOutput_Wrapper> },
    { IID_IDXGIOutput2, AddEntry<IDXGIOutput_Wrapper> },
    { IID_IDXGIOutput3, AddEntry<IDXGIOutput_Wrapper> },
    { IID_IDXGIOutput4, AddEntry<IDXGIOutput_Wrapper> },
    { IID_IDXGIOutput5, AddEntry<IDXGIOutput_Wrapper> },
    { IID_IDXGIOutput6, AddEntry<IDXGIOutput_Wrapper> },
    { IID_IDXGIFactory, AddEntry<IDXGIFactory_Wrapper> },
    { IID_IDXGIFactory1, AddEntry<IDXGIFactory_Wrapper> },
    { IID_IDXGIFactory2, AddEntry<IDXGIFactory_Wrapper> },
    { IID_IDXGIFactory3, AddEntry<IDXGIFactory_Wrapper> },
    { IID_IDXGIFactory4, AddEntry<IDXGIFactory_Wrapper> },
    { IID_IDXGIFactory5, AddEntry<IDXGIFactory_Wrapper> },
    { IID_IDXGIFactory6, AddEntry<IDXGIFactory_Wrapper> },
    { IID_IDXGIFactory7, AddEntry<IDXGIFactory_Wrapper> },
};

static DxWrapperInfo* GetWrapperInfo(IUnknown_Wrapper* wrapper)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto riid = wrapper->GetRiid();
    if(riid == IID_ID3D12RootSignature)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12RootSignature_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12RootSignatureDeserializer)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12RootSignatureDeserializer_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12VersionedRootSignatureDeserializer)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12VersionedRootSignatureDeserializer_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12CommandAllocator)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12CommandAllocator_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12Fence)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12Fence_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12Fence1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12Fence_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12PipelineState)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12PipelineState_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12DescriptorHeap)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12DescriptorHeap_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12QueryHeap)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12QueryHeap_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12CommandSignature)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12CommandSignature_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12CommandQueue)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12CommandQueue_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12PipelineLibrary)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12PipelineLibrary_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12PipelineLibrary1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12PipelineLibrary_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12LifetimeOwner)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12LifetimeOwner_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12SwapChainAssistant)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12SwapChainAssistant_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12LifetimeTracker)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12LifetimeTracker_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12StateObject)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12StateObject_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12StateObjectProperties)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12StateObjectProperties_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12StateObjectProperties1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12StateObjectProperties_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12WorkGraphProperties)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12WorkGraphProperties_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12DeviceRemovedExtendedDataSettings)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12DeviceRemovedExtendedDataSettings_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12DeviceRemovedExtendedDataSettings1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12DeviceRemovedExtendedDataSettings_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12DeviceRemovedExtendedDataSettings2)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12DeviceRemovedExtendedDataSettings_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12DeviceRemovedExtendedData)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12DeviceRemovedExtendedData_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12DeviceRemovedExtendedData1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12DeviceRemovedExtendedData_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12DeviceRemovedExtendedData2)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12DeviceRemovedExtendedData_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12ProtectedResourceSession)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12ProtectedResourceSession_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12ProtectedResourceSession1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12ProtectedResourceSession_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12Resource)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12Resource_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12Resource1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12Resource_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12Resource2)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12Resource_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12Heap)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12Heap_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12Heap1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12Heap_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12MetaCommand)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12MetaCommand_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12ShaderCacheSession)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12ShaderCacheSession_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12Device)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12Device_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12Device1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12Device_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12Device2)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12Device_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12Device3)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12Device_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12Device4)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12Device_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12Device5)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12Device_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12Device6)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12Device_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12Device7)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12Device_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12Device8)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12Device_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12Device9)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12Device_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12Device10)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12Device_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12Device11)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12Device_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12Device12)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12Device_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12Device13)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12Device_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12Device14)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12Device_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12VirtualizationGuestDevice)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12VirtualizationGuestDevice_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12Tools)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12Tools_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12Tools1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12Tools_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12PageableTools)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12PageableTools_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12DeviceTools)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12DeviceTools_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12SDKConfiguration)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12SDKConfiguration_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12SDKConfiguration1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12SDKConfiguration_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12DeviceFactory)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12DeviceFactory_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12DeviceConfiguration)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12DeviceConfiguration_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12DeviceConfiguration1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12DeviceConfiguration_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12CommandList)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12CommandList_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12GraphicsCommandList)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12CommandList_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12GraphicsCommandList1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12CommandList_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12GraphicsCommandList2)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12CommandList_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12GraphicsCommandList3)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12CommandList_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12GraphicsCommandList4)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12CommandList_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12GraphicsCommandList5)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12CommandList_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12GraphicsCommandList6)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12CommandList_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12GraphicsCommandList7)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12CommandList_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12GraphicsCommandList8)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12CommandList_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12GraphicsCommandList9)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12CommandList_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12GraphicsCommandList10)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12CommandList_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12DSRDeviceFactory)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12DSRDeviceFactory_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12GBVDiagnostics)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12GBVDiagnostics_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D10Blob)
    {
        auto* new_wrapper = reinterpret_cast<ID3D10Blob_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3DDestructionNotifier)
    {
        auto* new_wrapper = reinterpret_cast<ID3DDestructionNotifier_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12Debug1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12Debug1_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12Debug2)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12Debug2_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12Debug)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12Debug_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12Debug1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12Debug_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12Debug2)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12Debug_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12Debug3)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12Debug_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12Debug4)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12Debug_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12Debug5)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12Debug_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12Debug6)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12Debug_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12DebugDevice1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12DebugDevice1_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12DebugDevice)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12DebugDevice_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12DebugDevice1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12DebugDevice_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12DebugDevice2)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12DebugDevice_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12DebugCommandQueue)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12DebugCommandQueue_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12DebugCommandQueue1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12DebugCommandQueue_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12DebugCommandList1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12DebugCommandList1_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12DebugCommandList)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12DebugCommandList_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12DebugCommandList1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12DebugCommandList_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12DebugCommandList2)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12DebugCommandList_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12DebugCommandList3)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12DebugCommandList_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12SharingContract)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12SharingContract_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12ManualWriteTrackingResource)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12ManualWriteTrackingResource_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12InfoQueue)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12InfoQueue_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D12InfoQueue1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D12InfoQueue_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11DepthStencilState)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11DepthStencilState_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11Buffer)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11Buffer_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11Texture1D)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11Texture1D_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11DepthStencilView)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11DepthStencilView_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11VertexShader)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11VertexShader_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11HullShader)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11HullShader_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11DomainShader)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11DomainShader_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11GeometryShader)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11GeometryShader_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11PixelShader)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11PixelShader_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11ComputeShader)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11ComputeShader_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11InputLayout)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11InputLayout_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11SamplerState)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11SamplerState_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11Predicate)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11Predicate_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11Counter)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11Counter_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11ClassInstance)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11ClassInstance_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11ClassLinkage)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11ClassLinkage_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11CommandList)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11CommandList_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11VideoDecoder)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11VideoDecoder_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11VideoProcessor)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11VideoProcessor_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11AuthenticatedChannel)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11AuthenticatedChannel_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11CryptoSession)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11CryptoSession_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11VideoDecoderOutputView)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11VideoDecoderOutputView_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11VideoProcessorInputView)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11VideoProcessorInputView_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11VideoProcessorOutputView)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11VideoProcessorOutputView_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11BlendState)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11BlendState_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11BlendState1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11BlendState_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3DDeviceContextState)
    {
        auto* new_wrapper = reinterpret_cast<ID3DDeviceContextState_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11VideoProcessorEnumerator)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11VideoProcessorEnumerator_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11VideoProcessorEnumerator1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11VideoProcessorEnumerator_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3DUserDefinedAnnotation)
    {
        auto* new_wrapper = reinterpret_cast<ID3DUserDefinedAnnotation_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11Texture2D)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11Texture2D_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11Texture2D1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11Texture2D_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11Texture3D)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11Texture3D_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11Texture3D1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11Texture3D_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11RasterizerState)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11RasterizerState_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11RasterizerState1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11RasterizerState_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11RasterizerState2)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11RasterizerState_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11ShaderResourceView)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11ShaderResourceView_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11ShaderResourceView1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11ShaderResourceView_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11RenderTargetView)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11RenderTargetView_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11RenderTargetView1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11RenderTargetView_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11UnorderedAccessView)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11UnorderedAccessView_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11UnorderedAccessView1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11UnorderedAccessView_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11Query)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11Query_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11Query1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11Query_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11Fence)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11Fence_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11DeviceContext)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11DeviceContext_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11DeviceContext1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11DeviceContext_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11DeviceContext2)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11DeviceContext_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11DeviceContext3)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11DeviceContext_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11DeviceContext4)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11DeviceContext_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11Device)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11Device_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11Device1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11Device_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11Device2)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11Device_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11Device3)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11Device_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11Device4)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11Device_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11Device5)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11Device_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11Multithread)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11Multithread_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11VideoDevice)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11VideoDevice_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11VideoDevice1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11VideoDevice_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11VideoDevice2)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11VideoDevice_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11VideoContext)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11VideoContext_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11VideoContext1)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11VideoContext_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11VideoContext2)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11VideoContext_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_ID3D11VideoContext3)
    {
        auto* new_wrapper = reinterpret_cast<ID3D11VideoContext_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGIKeyedMutex)
    {
        auto* new_wrapper = reinterpret_cast<IDXGIKeyedMutex_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGIDisplayControl)
    {
        auto* new_wrapper = reinterpret_cast<IDXGIDisplayControl_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGIOutputDuplication)
    {
        auto* new_wrapper = reinterpret_cast<IDXGIOutputDuplication_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGISurface)
    {
        auto* new_wrapper = reinterpret_cast<IDXGISurface_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGISurface1)
    {
        auto* new_wrapper = reinterpret_cast<IDXGISurface_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGISurface2)
    {
        auto* new_wrapper = reinterpret_cast<IDXGISurface_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGIResource)
    {
        auto* new_wrapper = reinterpret_cast<IDXGIResource_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGIResource1)
    {
        auto* new_wrapper = reinterpret_cast<IDXGIResource_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGIDecodeSwapChain)
    {
        auto* new_wrapper = reinterpret_cast<IDXGIDecodeSwapChain_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGIFactoryMedia)
    {
        auto* new_wrapper = reinterpret_cast<IDXGIFactoryMedia_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGISwapChainMedia)
    {
        auto* new_wrapper = reinterpret_cast<IDXGISwapChainMedia_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGISwapChain)
    {
        auto* new_wrapper = reinterpret_cast<IDXGISwapChain_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGISwapChain1)
    {
        auto* new_wrapper = reinterpret_cast<IDXGISwapChain_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGISwapChain2)
    {
        auto* new_wrapper = reinterpret_cast<IDXGISwapChain_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGISwapChain3)
    {
        auto* new_wrapper = reinterpret_cast<IDXGISwapChain_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGISwapChain4)
    {
        auto* new_wrapper = reinterpret_cast<IDXGISwapChain_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGIDevice)
    {
        auto* new_wrapper = reinterpret_cast<IDXGIDevice_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGIDevice1)
    {
        auto* new_wrapper = reinterpret_cast<IDXGIDevice_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGIDevice2)
    {
        auto* new_wrapper = reinterpret_cast<IDXGIDevice_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGIDevice3)
    {
        auto* new_wrapper = reinterpret_cast<IDXGIDevice_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGIDevice4)
    {
        auto* new_wrapper = reinterpret_cast<IDXGIDevice_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGIAdapter)
    {
        auto* new_wrapper = reinterpret_cast<IDXGIAdapter_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGIAdapter1)
    {
        auto* new_wrapper = reinterpret_cast<IDXGIAdapter_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGIAdapter2)
    {
        auto* new_wrapper = reinterpret_cast<IDXGIAdapter_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGIAdapter3)
    {
        auto* new_wrapper = reinterpret_cast<IDXGIAdapter_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGIAdapter4)
    {
        auto* new_wrapper = reinterpret_cast<IDXGIAdapter_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGIOutput)
    {
        auto* new_wrapper = reinterpret_cast<IDXGIOutput_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGIOutput1)
    {
        auto* new_wrapper = reinterpret_cast<IDXGIOutput_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGIOutput2)
    {
        auto* new_wrapper = reinterpret_cast<IDXGIOutput_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGIOutput3)
    {
        auto* new_wrapper = reinterpret_cast<IDXGIOutput_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGIOutput4)
    {
        auto* new_wrapper = reinterpret_cast<IDXGIOutput_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGIOutput5)
    {
        auto* new_wrapper = reinterpret_cast<IDXGIOutput_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGIOutput6)
    {
        auto* new_wrapper = reinterpret_cast<IDXGIOutput_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGIFactory)
    {
        auto* new_wrapper = reinterpret_cast<IDXGIFactory_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGIFactory1)
    {
        auto* new_wrapper = reinterpret_cast<IDXGIFactory_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGIFactory2)
    {
        auto* new_wrapper = reinterpret_cast<IDXGIFactory_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGIFactory3)
    {
        auto* new_wrapper = reinterpret_cast<IDXGIFactory_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGIFactory4)
    {
        auto* new_wrapper = reinterpret_cast<IDXGIFactory_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGIFactory5)
    {
        auto* new_wrapper = reinterpret_cast<IDXGIFactory_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGIFactory6)
    {
        auto* new_wrapper = reinterpret_cast<IDXGIFactory_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    if(riid == IID_IDXGIFactory7)
    {
        auto* new_wrapper = reinterpret_cast<IDXGIFactory_Wrapper*>(wrapper);
        return new_wrapper->GetObjectInfo().get();
    }
    return nullptr;
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
