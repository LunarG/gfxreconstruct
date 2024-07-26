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
** This file is generated from dx12_state_table_header_generator.py.
**
*/

#ifndef  GFXRECON_GENERATED_DX12_STATE_TABLE_H
#define  GFXRECON_GENERATED_DX12_STATE_TABLE_H

#include "encode/dx12_state_table_base.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class Dx12StateTable : public Dx12StateTableBase
{
  public:
    Dx12StateTable() {}
    ~Dx12StateTable() {}

    bool InsertWrapper(format::HandleId id, ID3D12RootSignature_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12RootSignature_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12RootSignatureDeserializer_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12RootSignatureDeserializer_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12VersionedRootSignatureDeserializer_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12VersionedRootSignatureDeserializer_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12CommandAllocator_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12CommandAllocator_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12Fence_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12Fence_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12PipelineState_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12PipelineState_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12DescriptorHeap_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12DescriptorHeap_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12QueryHeap_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12QueryHeap_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12CommandSignature_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12CommandSignature_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12CommandQueue_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12CommandQueue_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12PipelineLibrary_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12PipelineLibrary_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12LifetimeOwner_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12LifetimeOwner_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12SwapChainAssistant_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12SwapChainAssistant_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12LifetimeTracker_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12LifetimeTracker_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12StateObject_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12StateObject_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12StateObjectProperties_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12StateObjectProperties_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12WorkGraphProperties_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12WorkGraphProperties_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12DeviceRemovedExtendedDataSettings_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12DeviceRemovedExtendedDataSettings_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12DeviceRemovedExtendedData_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12DeviceRemovedExtendedData_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12ProtectedResourceSession_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12ProtectedResourceSession_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12Resource_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12Resource_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12Heap_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12Heap_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12MetaCommand_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12MetaCommand_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12ShaderCacheSession_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12ShaderCacheSession_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12Device_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12Device_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12VirtualizationGuestDevice_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12VirtualizationGuestDevice_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12Tools_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12Tools_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12PageableTools_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12PageableTools_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12DeviceTools_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12DeviceTools_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12SDKConfiguration_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12SDKConfiguration_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12DeviceFactory_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12DeviceFactory_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12DeviceConfiguration_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12DeviceConfiguration_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12CommandList_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12CommandList_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12DSRDeviceFactory_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12DSRDeviceFactory_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12GBVDiagnostics_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12GBVDiagnostics_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D10Blob_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D10Blob_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3DDestructionNotifier_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3DDestructionNotifier_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12Debug1_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12Debug1_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12Debug2_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12Debug2_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12Debug_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12Debug_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12DebugDevice1_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12DebugDevice1_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12DebugDevice_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12DebugDevice_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12DebugCommandQueue_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12DebugCommandQueue_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12DebugCommandList1_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12DebugCommandList1_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12DebugCommandList_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12DebugCommandList_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12SharingContract_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12SharingContract_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12ManualWriteTrackingResource_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12ManualWriteTrackingResource_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12InfoQueue_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D12InfoQueue_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11DepthStencilState_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11DepthStencilState_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11Buffer_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11Buffer_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11Texture1D_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11Texture1D_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11DepthStencilView_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11DepthStencilView_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11VertexShader_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11VertexShader_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11HullShader_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11HullShader_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11DomainShader_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11DomainShader_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11GeometryShader_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11GeometryShader_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11PixelShader_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11PixelShader_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11ComputeShader_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11ComputeShader_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11InputLayout_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11InputLayout_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11SamplerState_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11SamplerState_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11Predicate_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11Predicate_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11Counter_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11Counter_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11ClassInstance_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11ClassInstance_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11ClassLinkage_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11ClassLinkage_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11CommandList_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11CommandList_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11VideoDecoder_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11VideoDecoder_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11VideoProcessor_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11VideoProcessor_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11AuthenticatedChannel_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11AuthenticatedChannel_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11CryptoSession_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11CryptoSession_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11VideoDecoderOutputView_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11VideoDecoderOutputView_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11VideoProcessorInputView_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11VideoProcessorInputView_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11VideoProcessorOutputView_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11VideoProcessorOutputView_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11BlendState_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11BlendState_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3DDeviceContextState_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3DDeviceContextState_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11VideoContext_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11VideoContext_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11VideoDevice_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11VideoDevice_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11VideoProcessorEnumerator_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11VideoProcessorEnumerator_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3DUserDefinedAnnotation_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3DUserDefinedAnnotation_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11Texture2D_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11Texture2D_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11Texture3D_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11Texture3D_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11RasterizerState_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11RasterizerState_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11ShaderResourceView_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11ShaderResourceView_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11RenderTargetView_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11RenderTargetView_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11UnorderedAccessView_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11UnorderedAccessView_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11Query_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11Query_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11Fence_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11Fence_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11DeviceContext_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11DeviceContext_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, ID3D11Device_Wrapper* wrapper) { return InsertEntry(id, wrapper, ID3D11Device_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, IDXGIKeyedMutex_Wrapper* wrapper) { return InsertEntry(id, wrapper, IDXGIKeyedMutex_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, IDXGIDisplayControl_Wrapper* wrapper) { return InsertEntry(id, wrapper, IDXGIDisplayControl_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, IDXGIOutputDuplication_Wrapper* wrapper) { return InsertEntry(id, wrapper, IDXGIOutputDuplication_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, IDXGISurface_Wrapper* wrapper) { return InsertEntry(id, wrapper, IDXGISurface_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, IDXGIResource_Wrapper* wrapper) { return InsertEntry(id, wrapper, IDXGIResource_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, IDXGIDecodeSwapChain_Wrapper* wrapper) { return InsertEntry(id, wrapper, IDXGIDecodeSwapChain_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, IDXGIFactoryMedia_Wrapper* wrapper) { return InsertEntry(id, wrapper, IDXGIFactoryMedia_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, IDXGISwapChainMedia_Wrapper* wrapper) { return InsertEntry(id, wrapper, IDXGISwapChainMedia_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, IDXGISwapChain_Wrapper* wrapper) { return InsertEntry(id, wrapper, IDXGISwapChain_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, IDXGIDevice_Wrapper* wrapper) { return InsertEntry(id, wrapper, IDXGIDevice_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, IDXGIAdapter_Wrapper* wrapper) { return InsertEntry(id, wrapper, IDXGIAdapter_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, IDXGIOutput_Wrapper* wrapper) { return InsertEntry(id, wrapper, IDXGIOutput_Wrapper_map_); }
    bool InsertWrapper(format::HandleId id, IDXGIFactory_Wrapper* wrapper) { return InsertEntry(id, wrapper, IDXGIFactory_Wrapper_map_); }

    bool RemoveWrapper(const ID3D12RootSignature_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12RootSignature_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12RootSignatureDeserializer_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12RootSignatureDeserializer_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12VersionedRootSignatureDeserializer_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12VersionedRootSignatureDeserializer_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12CommandAllocator_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12CommandAllocator_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12Fence_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12Fence_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12PipelineState_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12PipelineState_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12DescriptorHeap_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12DescriptorHeap_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12QueryHeap_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12QueryHeap_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12CommandSignature_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12CommandSignature_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12CommandQueue_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12CommandQueue_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12PipelineLibrary_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12PipelineLibrary_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12LifetimeOwner_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12LifetimeOwner_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12SwapChainAssistant_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12SwapChainAssistant_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12LifetimeTracker_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12LifetimeTracker_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12StateObject_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12StateObject_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12StateObjectProperties_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12StateObjectProperties_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12WorkGraphProperties_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12WorkGraphProperties_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12DeviceRemovedExtendedDataSettings_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12DeviceRemovedExtendedDataSettings_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12DeviceRemovedExtendedData_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12DeviceRemovedExtendedData_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12ProtectedResourceSession_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12ProtectedResourceSession_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12Resource_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12Resource_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12Heap_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12Heap_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12MetaCommand_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12MetaCommand_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12ShaderCacheSession_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12ShaderCacheSession_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12Device_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12Device_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12VirtualizationGuestDevice_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12VirtualizationGuestDevice_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12Tools_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12Tools_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12PageableTools_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12PageableTools_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12DeviceTools_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12DeviceTools_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12SDKConfiguration_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12SDKConfiguration_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12DeviceFactory_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12DeviceFactory_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12DeviceConfiguration_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12DeviceConfiguration_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12CommandList_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12CommandList_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12DSRDeviceFactory_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12DSRDeviceFactory_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12GBVDiagnostics_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12GBVDiagnostics_Wrapper_map_); }
    bool RemoveWrapper(const ID3D10Blob_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D10Blob_Wrapper_map_); }
    bool RemoveWrapper(const ID3DDestructionNotifier_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3DDestructionNotifier_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12Debug1_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12Debug1_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12Debug2_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12Debug2_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12Debug_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12Debug_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12DebugDevice1_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12DebugDevice1_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12DebugDevice_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12DebugDevice_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12DebugCommandQueue_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12DebugCommandQueue_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12DebugCommandList1_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12DebugCommandList1_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12DebugCommandList_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12DebugCommandList_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12SharingContract_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12SharingContract_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12ManualWriteTrackingResource_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12ManualWriteTrackingResource_Wrapper_map_); }
    bool RemoveWrapper(const ID3D12InfoQueue_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D12InfoQueue_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11DepthStencilState_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11DepthStencilState_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11Buffer_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11Buffer_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11Texture1D_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11Texture1D_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11DepthStencilView_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11DepthStencilView_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11VertexShader_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11VertexShader_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11HullShader_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11HullShader_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11DomainShader_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11DomainShader_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11GeometryShader_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11GeometryShader_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11PixelShader_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11PixelShader_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11ComputeShader_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11ComputeShader_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11InputLayout_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11InputLayout_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11SamplerState_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11SamplerState_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11Predicate_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11Predicate_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11Counter_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11Counter_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11ClassInstance_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11ClassInstance_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11ClassLinkage_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11ClassLinkage_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11CommandList_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11CommandList_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11VideoDecoder_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11VideoDecoder_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11VideoProcessor_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11VideoProcessor_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11AuthenticatedChannel_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11AuthenticatedChannel_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11CryptoSession_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11CryptoSession_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11VideoDecoderOutputView_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11VideoDecoderOutputView_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11VideoProcessorInputView_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11VideoProcessorInputView_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11VideoProcessorOutputView_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11VideoProcessorOutputView_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11BlendState_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11BlendState_Wrapper_map_); }
    bool RemoveWrapper(const ID3DDeviceContextState_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3DDeviceContextState_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11VideoContext_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11VideoContext_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11VideoDevice_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11VideoDevice_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11VideoProcessorEnumerator_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11VideoProcessorEnumerator_Wrapper_map_); }
    bool RemoveWrapper(const ID3DUserDefinedAnnotation_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3DUserDefinedAnnotation_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11Texture2D_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11Texture2D_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11Texture3D_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11Texture3D_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11RasterizerState_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11RasterizerState_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11ShaderResourceView_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11ShaderResourceView_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11RenderTargetView_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11RenderTargetView_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11UnorderedAccessView_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11UnorderedAccessView_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11Query_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11Query_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11Fence_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11Fence_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11DeviceContext_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11DeviceContext_Wrapper_map_); }
    bool RemoveWrapper(const ID3D11Device_Wrapper* wrapper) { return RemoveEntry(wrapper, ID3D11Device_Wrapper_map_); }
    bool RemoveWrapper(const IDXGIKeyedMutex_Wrapper* wrapper) { return RemoveEntry(wrapper, IDXGIKeyedMutex_Wrapper_map_); }
    bool RemoveWrapper(const IDXGIDisplayControl_Wrapper* wrapper) { return RemoveEntry(wrapper, IDXGIDisplayControl_Wrapper_map_); }
    bool RemoveWrapper(const IDXGIOutputDuplication_Wrapper* wrapper) { return RemoveEntry(wrapper, IDXGIOutputDuplication_Wrapper_map_); }
    bool RemoveWrapper(const IDXGISurface_Wrapper* wrapper) { return RemoveEntry(wrapper, IDXGISurface_Wrapper_map_); }
    bool RemoveWrapper(const IDXGIResource_Wrapper* wrapper) { return RemoveEntry(wrapper, IDXGIResource_Wrapper_map_); }
    bool RemoveWrapper(const IDXGIDecodeSwapChain_Wrapper* wrapper) { return RemoveEntry(wrapper, IDXGIDecodeSwapChain_Wrapper_map_); }
    bool RemoveWrapper(const IDXGIFactoryMedia_Wrapper* wrapper) { return RemoveEntry(wrapper, IDXGIFactoryMedia_Wrapper_map_); }
    bool RemoveWrapper(const IDXGISwapChainMedia_Wrapper* wrapper) { return RemoveEntry(wrapper, IDXGISwapChainMedia_Wrapper_map_); }
    bool RemoveWrapper(const IDXGISwapChain_Wrapper* wrapper) { return RemoveEntry(wrapper, IDXGISwapChain_Wrapper_map_); }
    bool RemoveWrapper(const IDXGIDevice_Wrapper* wrapper) { return RemoveEntry(wrapper, IDXGIDevice_Wrapper_map_); }
    bool RemoveWrapper(const IDXGIAdapter_Wrapper* wrapper) { return RemoveEntry(wrapper, IDXGIAdapter_Wrapper_map_); }
    bool RemoveWrapper(const IDXGIOutput_Wrapper* wrapper) { return RemoveEntry(wrapper, IDXGIOutput_Wrapper_map_); }
    bool RemoveWrapper(const IDXGIFactory_Wrapper* wrapper) { return RemoveEntry(wrapper, IDXGIFactory_Wrapper_map_); }

    void VisitWrappers(std::function<void(ID3D12RootSignature_Wrapper*)> visitor) const { for (auto entry : ID3D12RootSignature_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12RootSignatureDeserializer_Wrapper*)> visitor) const { for (auto entry : ID3D12RootSignatureDeserializer_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12VersionedRootSignatureDeserializer_Wrapper*)> visitor) const { for (auto entry : ID3D12VersionedRootSignatureDeserializer_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12CommandAllocator_Wrapper*)> visitor) const { for (auto entry : ID3D12CommandAllocator_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12Fence_Wrapper*)> visitor) const { for (auto entry : ID3D12Fence_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12PipelineState_Wrapper*)> visitor) const { for (auto entry : ID3D12PipelineState_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12DescriptorHeap_Wrapper*)> visitor) const { for (auto entry : ID3D12DescriptorHeap_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12QueryHeap_Wrapper*)> visitor) const { for (auto entry : ID3D12QueryHeap_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12CommandSignature_Wrapper*)> visitor) const { for (auto entry : ID3D12CommandSignature_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12CommandQueue_Wrapper*)> visitor) const { for (auto entry : ID3D12CommandQueue_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12PipelineLibrary_Wrapper*)> visitor) const { for (auto entry : ID3D12PipelineLibrary_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12LifetimeOwner_Wrapper*)> visitor) const { for (auto entry : ID3D12LifetimeOwner_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12SwapChainAssistant_Wrapper*)> visitor) const { for (auto entry : ID3D12SwapChainAssistant_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12LifetimeTracker_Wrapper*)> visitor) const { for (auto entry : ID3D12LifetimeTracker_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12StateObject_Wrapper*)> visitor) const { for (auto entry : ID3D12StateObject_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12StateObjectProperties_Wrapper*)> visitor) const { for (auto entry : ID3D12StateObjectProperties_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12WorkGraphProperties_Wrapper*)> visitor) const { for (auto entry : ID3D12WorkGraphProperties_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12DeviceRemovedExtendedDataSettings_Wrapper*)> visitor) const { for (auto entry : ID3D12DeviceRemovedExtendedDataSettings_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12DeviceRemovedExtendedData_Wrapper*)> visitor) const { for (auto entry : ID3D12DeviceRemovedExtendedData_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12ProtectedResourceSession_Wrapper*)> visitor) const { for (auto entry : ID3D12ProtectedResourceSession_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12Resource_Wrapper*)> visitor) const { for (auto entry : ID3D12Resource_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12Heap_Wrapper*)> visitor) const { for (auto entry : ID3D12Heap_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12MetaCommand_Wrapper*)> visitor) const { for (auto entry : ID3D12MetaCommand_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12ShaderCacheSession_Wrapper*)> visitor) const { for (auto entry : ID3D12ShaderCacheSession_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12Device_Wrapper*)> visitor) const { for (auto entry : ID3D12Device_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12VirtualizationGuestDevice_Wrapper*)> visitor) const { for (auto entry : ID3D12VirtualizationGuestDevice_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12Tools_Wrapper*)> visitor) const { for (auto entry : ID3D12Tools_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12PageableTools_Wrapper*)> visitor) const { for (auto entry : ID3D12PageableTools_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12DeviceTools_Wrapper*)> visitor) const { for (auto entry : ID3D12DeviceTools_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12SDKConfiguration_Wrapper*)> visitor) const { for (auto entry : ID3D12SDKConfiguration_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12DeviceFactory_Wrapper*)> visitor) const { for (auto entry : ID3D12DeviceFactory_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12DeviceConfiguration_Wrapper*)> visitor) const { for (auto entry : ID3D12DeviceConfiguration_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12CommandList_Wrapper*)> visitor) const { for (auto entry : ID3D12CommandList_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12DSRDeviceFactory_Wrapper*)> visitor) const { for (auto entry : ID3D12DSRDeviceFactory_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12GBVDiagnostics_Wrapper*)> visitor) const { for (auto entry : ID3D12GBVDiagnostics_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D10Blob_Wrapper*)> visitor) const { for (auto entry : ID3D10Blob_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3DDestructionNotifier_Wrapper*)> visitor) const { for (auto entry : ID3DDestructionNotifier_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12Debug1_Wrapper*)> visitor) const { for (auto entry : ID3D12Debug1_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12Debug2_Wrapper*)> visitor) const { for (auto entry : ID3D12Debug2_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12Debug_Wrapper*)> visitor) const { for (auto entry : ID3D12Debug_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12DebugDevice1_Wrapper*)> visitor) const { for (auto entry : ID3D12DebugDevice1_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12DebugDevice_Wrapper*)> visitor) const { for (auto entry : ID3D12DebugDevice_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12DebugCommandQueue_Wrapper*)> visitor) const { for (auto entry : ID3D12DebugCommandQueue_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12DebugCommandList1_Wrapper*)> visitor) const { for (auto entry : ID3D12DebugCommandList1_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12DebugCommandList_Wrapper*)> visitor) const { for (auto entry : ID3D12DebugCommandList_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12SharingContract_Wrapper*)> visitor) const { for (auto entry : ID3D12SharingContract_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12ManualWriteTrackingResource_Wrapper*)> visitor) const { for (auto entry : ID3D12ManualWriteTrackingResource_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D12InfoQueue_Wrapper*)> visitor) const { for (auto entry : ID3D12InfoQueue_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11DepthStencilState_Wrapper*)> visitor) const { for (auto entry : ID3D11DepthStencilState_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11Buffer_Wrapper*)> visitor) const { for (auto entry : ID3D11Buffer_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11Texture1D_Wrapper*)> visitor) const { for (auto entry : ID3D11Texture1D_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11DepthStencilView_Wrapper*)> visitor) const { for (auto entry : ID3D11DepthStencilView_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11VertexShader_Wrapper*)> visitor) const { for (auto entry : ID3D11VertexShader_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11HullShader_Wrapper*)> visitor) const { for (auto entry : ID3D11HullShader_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11DomainShader_Wrapper*)> visitor) const { for (auto entry : ID3D11DomainShader_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11GeometryShader_Wrapper*)> visitor) const { for (auto entry : ID3D11GeometryShader_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11PixelShader_Wrapper*)> visitor) const { for (auto entry : ID3D11PixelShader_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11ComputeShader_Wrapper*)> visitor) const { for (auto entry : ID3D11ComputeShader_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11InputLayout_Wrapper*)> visitor) const { for (auto entry : ID3D11InputLayout_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11SamplerState_Wrapper*)> visitor) const { for (auto entry : ID3D11SamplerState_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11Predicate_Wrapper*)> visitor) const { for (auto entry : ID3D11Predicate_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11Counter_Wrapper*)> visitor) const { for (auto entry : ID3D11Counter_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11ClassInstance_Wrapper*)> visitor) const { for (auto entry : ID3D11ClassInstance_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11ClassLinkage_Wrapper*)> visitor) const { for (auto entry : ID3D11ClassLinkage_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11CommandList_Wrapper*)> visitor) const { for (auto entry : ID3D11CommandList_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11VideoDecoder_Wrapper*)> visitor) const { for (auto entry : ID3D11VideoDecoder_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11VideoProcessor_Wrapper*)> visitor) const { for (auto entry : ID3D11VideoProcessor_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11AuthenticatedChannel_Wrapper*)> visitor) const { for (auto entry : ID3D11AuthenticatedChannel_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11CryptoSession_Wrapper*)> visitor) const { for (auto entry : ID3D11CryptoSession_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11VideoDecoderOutputView_Wrapper*)> visitor) const { for (auto entry : ID3D11VideoDecoderOutputView_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11VideoProcessorInputView_Wrapper*)> visitor) const { for (auto entry : ID3D11VideoProcessorInputView_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11VideoProcessorOutputView_Wrapper*)> visitor) const { for (auto entry : ID3D11VideoProcessorOutputView_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11BlendState_Wrapper*)> visitor) const { for (auto entry : ID3D11BlendState_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3DDeviceContextState_Wrapper*)> visitor) const { for (auto entry : ID3DDeviceContextState_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11VideoContext_Wrapper*)> visitor) const { for (auto entry : ID3D11VideoContext_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11VideoDevice_Wrapper*)> visitor) const { for (auto entry : ID3D11VideoDevice_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11VideoProcessorEnumerator_Wrapper*)> visitor) const { for (auto entry : ID3D11VideoProcessorEnumerator_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3DUserDefinedAnnotation_Wrapper*)> visitor) const { for (auto entry : ID3DUserDefinedAnnotation_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11Texture2D_Wrapper*)> visitor) const { for (auto entry : ID3D11Texture2D_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11Texture3D_Wrapper*)> visitor) const { for (auto entry : ID3D11Texture3D_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11RasterizerState_Wrapper*)> visitor) const { for (auto entry : ID3D11RasterizerState_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11ShaderResourceView_Wrapper*)> visitor) const { for (auto entry : ID3D11ShaderResourceView_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11RenderTargetView_Wrapper*)> visitor) const { for (auto entry : ID3D11RenderTargetView_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11UnorderedAccessView_Wrapper*)> visitor) const { for (auto entry : ID3D11UnorderedAccessView_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11Query_Wrapper*)> visitor) const { for (auto entry : ID3D11Query_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11Fence_Wrapper*)> visitor) const { for (auto entry : ID3D11Fence_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11DeviceContext_Wrapper*)> visitor) const { for (auto entry : ID3D11DeviceContext_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ID3D11Device_Wrapper*)> visitor) const { for (auto entry : ID3D11Device_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(IDXGIKeyedMutex_Wrapper*)> visitor) const { for (auto entry : IDXGIKeyedMutex_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(IDXGIDisplayControl_Wrapper*)> visitor) const { for (auto entry : IDXGIDisplayControl_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(IDXGIOutputDuplication_Wrapper*)> visitor) const { for (auto entry : IDXGIOutputDuplication_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(IDXGISurface_Wrapper*)> visitor) const { for (auto entry : IDXGISurface_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(IDXGIResource_Wrapper*)> visitor) const { for (auto entry : IDXGIResource_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(IDXGIDecodeSwapChain_Wrapper*)> visitor) const { for (auto entry : IDXGIDecodeSwapChain_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(IDXGIFactoryMedia_Wrapper*)> visitor) const { for (auto entry : IDXGIFactoryMedia_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(IDXGISwapChainMedia_Wrapper*)> visitor) const { for (auto entry : IDXGISwapChainMedia_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(IDXGISwapChain_Wrapper*)> visitor) const { for (auto entry : IDXGISwapChain_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(IDXGIDevice_Wrapper*)> visitor) const { for (auto entry : IDXGIDevice_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(IDXGIAdapter_Wrapper*)> visitor) const { for (auto entry : IDXGIAdapter_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(IDXGIOutput_Wrapper*)> visitor) const { for (auto entry : IDXGIOutput_Wrapper_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(IDXGIFactory_Wrapper*)> visitor) const { for (auto entry : IDXGIFactory_Wrapper_map_) { visitor(entry.second); } }

    //
    // Helper functions for state initialization.
    //

    ID3D12RootSignature_Wrapper* GetID3D12RootSignature_Wrapper(format::HandleId id) { return GetWrapper<ID3D12RootSignature_Wrapper>(id, ID3D12RootSignature_Wrapper_map_); }
    const ID3D12RootSignature_Wrapper* GetID3D12RootSignature_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12RootSignature_Wrapper>(id, ID3D12RootSignature_Wrapper_map_); }

    ID3D12RootSignatureDeserializer_Wrapper* GetID3D12RootSignatureDeserializer_Wrapper(format::HandleId id) { return GetWrapper<ID3D12RootSignatureDeserializer_Wrapper>(id, ID3D12RootSignatureDeserializer_Wrapper_map_); }
    const ID3D12RootSignatureDeserializer_Wrapper* GetID3D12RootSignatureDeserializer_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12RootSignatureDeserializer_Wrapper>(id, ID3D12RootSignatureDeserializer_Wrapper_map_); }

    ID3D12VersionedRootSignatureDeserializer_Wrapper* GetID3D12VersionedRootSignatureDeserializer_Wrapper(format::HandleId id) { return GetWrapper<ID3D12VersionedRootSignatureDeserializer_Wrapper>(id, ID3D12VersionedRootSignatureDeserializer_Wrapper_map_); }
    const ID3D12VersionedRootSignatureDeserializer_Wrapper* GetID3D12VersionedRootSignatureDeserializer_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12VersionedRootSignatureDeserializer_Wrapper>(id, ID3D12VersionedRootSignatureDeserializer_Wrapper_map_); }

    ID3D12CommandAllocator_Wrapper* GetID3D12CommandAllocator_Wrapper(format::HandleId id) { return GetWrapper<ID3D12CommandAllocator_Wrapper>(id, ID3D12CommandAllocator_Wrapper_map_); }
    const ID3D12CommandAllocator_Wrapper* GetID3D12CommandAllocator_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12CommandAllocator_Wrapper>(id, ID3D12CommandAllocator_Wrapper_map_); }

    ID3D12Fence_Wrapper* GetID3D12Fence_Wrapper(format::HandleId id) { return GetWrapper<ID3D12Fence_Wrapper>(id, ID3D12Fence_Wrapper_map_); }
    const ID3D12Fence_Wrapper* GetID3D12Fence_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12Fence_Wrapper>(id, ID3D12Fence_Wrapper_map_); }

    ID3D12PipelineState_Wrapper* GetID3D12PipelineState_Wrapper(format::HandleId id) { return GetWrapper<ID3D12PipelineState_Wrapper>(id, ID3D12PipelineState_Wrapper_map_); }
    const ID3D12PipelineState_Wrapper* GetID3D12PipelineState_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12PipelineState_Wrapper>(id, ID3D12PipelineState_Wrapper_map_); }

    ID3D12DescriptorHeap_Wrapper* GetID3D12DescriptorHeap_Wrapper(format::HandleId id) { return GetWrapper<ID3D12DescriptorHeap_Wrapper>(id, ID3D12DescriptorHeap_Wrapper_map_); }
    const ID3D12DescriptorHeap_Wrapper* GetID3D12DescriptorHeap_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12DescriptorHeap_Wrapper>(id, ID3D12DescriptorHeap_Wrapper_map_); }

    ID3D12QueryHeap_Wrapper* GetID3D12QueryHeap_Wrapper(format::HandleId id) { return GetWrapper<ID3D12QueryHeap_Wrapper>(id, ID3D12QueryHeap_Wrapper_map_); }
    const ID3D12QueryHeap_Wrapper* GetID3D12QueryHeap_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12QueryHeap_Wrapper>(id, ID3D12QueryHeap_Wrapper_map_); }

    ID3D12CommandSignature_Wrapper* GetID3D12CommandSignature_Wrapper(format::HandleId id) { return GetWrapper<ID3D12CommandSignature_Wrapper>(id, ID3D12CommandSignature_Wrapper_map_); }
    const ID3D12CommandSignature_Wrapper* GetID3D12CommandSignature_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12CommandSignature_Wrapper>(id, ID3D12CommandSignature_Wrapper_map_); }

    ID3D12CommandQueue_Wrapper* GetID3D12CommandQueue_Wrapper(format::HandleId id) { return GetWrapper<ID3D12CommandQueue_Wrapper>(id, ID3D12CommandQueue_Wrapper_map_); }
    const ID3D12CommandQueue_Wrapper* GetID3D12CommandQueue_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12CommandQueue_Wrapper>(id, ID3D12CommandQueue_Wrapper_map_); }

    ID3D12PipelineLibrary_Wrapper* GetID3D12PipelineLibrary_Wrapper(format::HandleId id) { return GetWrapper<ID3D12PipelineLibrary_Wrapper>(id, ID3D12PipelineLibrary_Wrapper_map_); }
    const ID3D12PipelineLibrary_Wrapper* GetID3D12PipelineLibrary_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12PipelineLibrary_Wrapper>(id, ID3D12PipelineLibrary_Wrapper_map_); }

    ID3D12LifetimeOwner_Wrapper* GetID3D12LifetimeOwner_Wrapper(format::HandleId id) { return GetWrapper<ID3D12LifetimeOwner_Wrapper>(id, ID3D12LifetimeOwner_Wrapper_map_); }
    const ID3D12LifetimeOwner_Wrapper* GetID3D12LifetimeOwner_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12LifetimeOwner_Wrapper>(id, ID3D12LifetimeOwner_Wrapper_map_); }

    ID3D12SwapChainAssistant_Wrapper* GetID3D12SwapChainAssistant_Wrapper(format::HandleId id) { return GetWrapper<ID3D12SwapChainAssistant_Wrapper>(id, ID3D12SwapChainAssistant_Wrapper_map_); }
    const ID3D12SwapChainAssistant_Wrapper* GetID3D12SwapChainAssistant_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12SwapChainAssistant_Wrapper>(id, ID3D12SwapChainAssistant_Wrapper_map_); }

    ID3D12LifetimeTracker_Wrapper* GetID3D12LifetimeTracker_Wrapper(format::HandleId id) { return GetWrapper<ID3D12LifetimeTracker_Wrapper>(id, ID3D12LifetimeTracker_Wrapper_map_); }
    const ID3D12LifetimeTracker_Wrapper* GetID3D12LifetimeTracker_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12LifetimeTracker_Wrapper>(id, ID3D12LifetimeTracker_Wrapper_map_); }

    ID3D12StateObject_Wrapper* GetID3D12StateObject_Wrapper(format::HandleId id) { return GetWrapper<ID3D12StateObject_Wrapper>(id, ID3D12StateObject_Wrapper_map_); }
    const ID3D12StateObject_Wrapper* GetID3D12StateObject_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12StateObject_Wrapper>(id, ID3D12StateObject_Wrapper_map_); }

    ID3D12StateObjectProperties_Wrapper* GetID3D12StateObjectProperties_Wrapper(format::HandleId id) { return GetWrapper<ID3D12StateObjectProperties_Wrapper>(id, ID3D12StateObjectProperties_Wrapper_map_); }
    const ID3D12StateObjectProperties_Wrapper* GetID3D12StateObjectProperties_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12StateObjectProperties_Wrapper>(id, ID3D12StateObjectProperties_Wrapper_map_); }

    ID3D12WorkGraphProperties_Wrapper* GetID3D12WorkGraphProperties_Wrapper(format::HandleId id) { return GetWrapper<ID3D12WorkGraphProperties_Wrapper>(id, ID3D12WorkGraphProperties_Wrapper_map_); }
    const ID3D12WorkGraphProperties_Wrapper* GetID3D12WorkGraphProperties_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12WorkGraphProperties_Wrapper>(id, ID3D12WorkGraphProperties_Wrapper_map_); }

    ID3D12DeviceRemovedExtendedDataSettings_Wrapper* GetID3D12DeviceRemovedExtendedDataSettings_Wrapper(format::HandleId id) { return GetWrapper<ID3D12DeviceRemovedExtendedDataSettings_Wrapper>(id, ID3D12DeviceRemovedExtendedDataSettings_Wrapper_map_); }
    const ID3D12DeviceRemovedExtendedDataSettings_Wrapper* GetID3D12DeviceRemovedExtendedDataSettings_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12DeviceRemovedExtendedDataSettings_Wrapper>(id, ID3D12DeviceRemovedExtendedDataSettings_Wrapper_map_); }

    ID3D12DeviceRemovedExtendedData_Wrapper* GetID3D12DeviceRemovedExtendedData_Wrapper(format::HandleId id) { return GetWrapper<ID3D12DeviceRemovedExtendedData_Wrapper>(id, ID3D12DeviceRemovedExtendedData_Wrapper_map_); }
    const ID3D12DeviceRemovedExtendedData_Wrapper* GetID3D12DeviceRemovedExtendedData_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12DeviceRemovedExtendedData_Wrapper>(id, ID3D12DeviceRemovedExtendedData_Wrapper_map_); }

    ID3D12ProtectedResourceSession_Wrapper* GetID3D12ProtectedResourceSession_Wrapper(format::HandleId id) { return GetWrapper<ID3D12ProtectedResourceSession_Wrapper>(id, ID3D12ProtectedResourceSession_Wrapper_map_); }
    const ID3D12ProtectedResourceSession_Wrapper* GetID3D12ProtectedResourceSession_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12ProtectedResourceSession_Wrapper>(id, ID3D12ProtectedResourceSession_Wrapper_map_); }

    ID3D12Resource_Wrapper* GetID3D12Resource_Wrapper(format::HandleId id) { return GetWrapper<ID3D12Resource_Wrapper>(id, ID3D12Resource_Wrapper_map_); }
    const ID3D12Resource_Wrapper* GetID3D12Resource_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12Resource_Wrapper>(id, ID3D12Resource_Wrapper_map_); }

    ID3D12Heap_Wrapper* GetID3D12Heap_Wrapper(format::HandleId id) { return GetWrapper<ID3D12Heap_Wrapper>(id, ID3D12Heap_Wrapper_map_); }
    const ID3D12Heap_Wrapper* GetID3D12Heap_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12Heap_Wrapper>(id, ID3D12Heap_Wrapper_map_); }

    ID3D12MetaCommand_Wrapper* GetID3D12MetaCommand_Wrapper(format::HandleId id) { return GetWrapper<ID3D12MetaCommand_Wrapper>(id, ID3D12MetaCommand_Wrapper_map_); }
    const ID3D12MetaCommand_Wrapper* GetID3D12MetaCommand_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12MetaCommand_Wrapper>(id, ID3D12MetaCommand_Wrapper_map_); }

    ID3D12ShaderCacheSession_Wrapper* GetID3D12ShaderCacheSession_Wrapper(format::HandleId id) { return GetWrapper<ID3D12ShaderCacheSession_Wrapper>(id, ID3D12ShaderCacheSession_Wrapper_map_); }
    const ID3D12ShaderCacheSession_Wrapper* GetID3D12ShaderCacheSession_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12ShaderCacheSession_Wrapper>(id, ID3D12ShaderCacheSession_Wrapper_map_); }

    ID3D12Device_Wrapper* GetID3D12Device_Wrapper(format::HandleId id) { return GetWrapper<ID3D12Device_Wrapper>(id, ID3D12Device_Wrapper_map_); }
    const ID3D12Device_Wrapper* GetID3D12Device_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12Device_Wrapper>(id, ID3D12Device_Wrapper_map_); }

    ID3D12VirtualizationGuestDevice_Wrapper* GetID3D12VirtualizationGuestDevice_Wrapper(format::HandleId id) { return GetWrapper<ID3D12VirtualizationGuestDevice_Wrapper>(id, ID3D12VirtualizationGuestDevice_Wrapper_map_); }
    const ID3D12VirtualizationGuestDevice_Wrapper* GetID3D12VirtualizationGuestDevice_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12VirtualizationGuestDevice_Wrapper>(id, ID3D12VirtualizationGuestDevice_Wrapper_map_); }

    ID3D12Tools_Wrapper* GetID3D12Tools_Wrapper(format::HandleId id) { return GetWrapper<ID3D12Tools_Wrapper>(id, ID3D12Tools_Wrapper_map_); }
    const ID3D12Tools_Wrapper* GetID3D12Tools_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12Tools_Wrapper>(id, ID3D12Tools_Wrapper_map_); }

    ID3D12PageableTools_Wrapper* GetID3D12PageableTools_Wrapper(format::HandleId id) { return GetWrapper<ID3D12PageableTools_Wrapper>(id, ID3D12PageableTools_Wrapper_map_); }
    const ID3D12PageableTools_Wrapper* GetID3D12PageableTools_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12PageableTools_Wrapper>(id, ID3D12PageableTools_Wrapper_map_); }

    ID3D12DeviceTools_Wrapper* GetID3D12DeviceTools_Wrapper(format::HandleId id) { return GetWrapper<ID3D12DeviceTools_Wrapper>(id, ID3D12DeviceTools_Wrapper_map_); }
    const ID3D12DeviceTools_Wrapper* GetID3D12DeviceTools_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12DeviceTools_Wrapper>(id, ID3D12DeviceTools_Wrapper_map_); }

    ID3D12SDKConfiguration_Wrapper* GetID3D12SDKConfiguration_Wrapper(format::HandleId id) { return GetWrapper<ID3D12SDKConfiguration_Wrapper>(id, ID3D12SDKConfiguration_Wrapper_map_); }
    const ID3D12SDKConfiguration_Wrapper* GetID3D12SDKConfiguration_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12SDKConfiguration_Wrapper>(id, ID3D12SDKConfiguration_Wrapper_map_); }

    ID3D12DeviceFactory_Wrapper* GetID3D12DeviceFactory_Wrapper(format::HandleId id) { return GetWrapper<ID3D12DeviceFactory_Wrapper>(id, ID3D12DeviceFactory_Wrapper_map_); }
    const ID3D12DeviceFactory_Wrapper* GetID3D12DeviceFactory_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12DeviceFactory_Wrapper>(id, ID3D12DeviceFactory_Wrapper_map_); }

    ID3D12DeviceConfiguration_Wrapper* GetID3D12DeviceConfiguration_Wrapper(format::HandleId id) { return GetWrapper<ID3D12DeviceConfiguration_Wrapper>(id, ID3D12DeviceConfiguration_Wrapper_map_); }
    const ID3D12DeviceConfiguration_Wrapper* GetID3D12DeviceConfiguration_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12DeviceConfiguration_Wrapper>(id, ID3D12DeviceConfiguration_Wrapper_map_); }

    ID3D12CommandList_Wrapper* GetID3D12CommandList_Wrapper(format::HandleId id) { return GetWrapper<ID3D12CommandList_Wrapper>(id, ID3D12CommandList_Wrapper_map_); }
    const ID3D12CommandList_Wrapper* GetID3D12CommandList_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12CommandList_Wrapper>(id, ID3D12CommandList_Wrapper_map_); }

    ID3D12DSRDeviceFactory_Wrapper* GetID3D12DSRDeviceFactory_Wrapper(format::HandleId id) { return GetWrapper<ID3D12DSRDeviceFactory_Wrapper>(id, ID3D12DSRDeviceFactory_Wrapper_map_); }
    const ID3D12DSRDeviceFactory_Wrapper* GetID3D12DSRDeviceFactory_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12DSRDeviceFactory_Wrapper>(id, ID3D12DSRDeviceFactory_Wrapper_map_); }

    ID3D12GBVDiagnostics_Wrapper* GetID3D12GBVDiagnostics_Wrapper(format::HandleId id) { return GetWrapper<ID3D12GBVDiagnostics_Wrapper>(id, ID3D12GBVDiagnostics_Wrapper_map_); }
    const ID3D12GBVDiagnostics_Wrapper* GetID3D12GBVDiagnostics_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12GBVDiagnostics_Wrapper>(id, ID3D12GBVDiagnostics_Wrapper_map_); }

    ID3D10Blob_Wrapper* GetID3D10Blob_Wrapper(format::HandleId id) { return GetWrapper<ID3D10Blob_Wrapper>(id, ID3D10Blob_Wrapper_map_); }
    const ID3D10Blob_Wrapper* GetID3D10Blob_Wrapper(format::HandleId id) const { return GetWrapper<ID3D10Blob_Wrapper>(id, ID3D10Blob_Wrapper_map_); }

    ID3DDestructionNotifier_Wrapper* GetID3DDestructionNotifier_Wrapper(format::HandleId id) { return GetWrapper<ID3DDestructionNotifier_Wrapper>(id, ID3DDestructionNotifier_Wrapper_map_); }
    const ID3DDestructionNotifier_Wrapper* GetID3DDestructionNotifier_Wrapper(format::HandleId id) const { return GetWrapper<ID3DDestructionNotifier_Wrapper>(id, ID3DDestructionNotifier_Wrapper_map_); }

    ID3D12Debug1_Wrapper* GetID3D12Debug1_Wrapper(format::HandleId id) { return GetWrapper<ID3D12Debug1_Wrapper>(id, ID3D12Debug1_Wrapper_map_); }
    const ID3D12Debug1_Wrapper* GetID3D12Debug1_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12Debug1_Wrapper>(id, ID3D12Debug1_Wrapper_map_); }

    ID3D12Debug2_Wrapper* GetID3D12Debug2_Wrapper(format::HandleId id) { return GetWrapper<ID3D12Debug2_Wrapper>(id, ID3D12Debug2_Wrapper_map_); }
    const ID3D12Debug2_Wrapper* GetID3D12Debug2_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12Debug2_Wrapper>(id, ID3D12Debug2_Wrapper_map_); }

    ID3D12Debug_Wrapper* GetID3D12Debug_Wrapper(format::HandleId id) { return GetWrapper<ID3D12Debug_Wrapper>(id, ID3D12Debug_Wrapper_map_); }
    const ID3D12Debug_Wrapper* GetID3D12Debug_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12Debug_Wrapper>(id, ID3D12Debug_Wrapper_map_); }

    ID3D12DebugDevice1_Wrapper* GetID3D12DebugDevice1_Wrapper(format::HandleId id) { return GetWrapper<ID3D12DebugDevice1_Wrapper>(id, ID3D12DebugDevice1_Wrapper_map_); }
    const ID3D12DebugDevice1_Wrapper* GetID3D12DebugDevice1_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12DebugDevice1_Wrapper>(id, ID3D12DebugDevice1_Wrapper_map_); }

    ID3D12DebugDevice_Wrapper* GetID3D12DebugDevice_Wrapper(format::HandleId id) { return GetWrapper<ID3D12DebugDevice_Wrapper>(id, ID3D12DebugDevice_Wrapper_map_); }
    const ID3D12DebugDevice_Wrapper* GetID3D12DebugDevice_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12DebugDevice_Wrapper>(id, ID3D12DebugDevice_Wrapper_map_); }

    ID3D12DebugCommandQueue_Wrapper* GetID3D12DebugCommandQueue_Wrapper(format::HandleId id) { return GetWrapper<ID3D12DebugCommandQueue_Wrapper>(id, ID3D12DebugCommandQueue_Wrapper_map_); }
    const ID3D12DebugCommandQueue_Wrapper* GetID3D12DebugCommandQueue_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12DebugCommandQueue_Wrapper>(id, ID3D12DebugCommandQueue_Wrapper_map_); }

    ID3D12DebugCommandList1_Wrapper* GetID3D12DebugCommandList1_Wrapper(format::HandleId id) { return GetWrapper<ID3D12DebugCommandList1_Wrapper>(id, ID3D12DebugCommandList1_Wrapper_map_); }
    const ID3D12DebugCommandList1_Wrapper* GetID3D12DebugCommandList1_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12DebugCommandList1_Wrapper>(id, ID3D12DebugCommandList1_Wrapper_map_); }

    ID3D12DebugCommandList_Wrapper* GetID3D12DebugCommandList_Wrapper(format::HandleId id) { return GetWrapper<ID3D12DebugCommandList_Wrapper>(id, ID3D12DebugCommandList_Wrapper_map_); }
    const ID3D12DebugCommandList_Wrapper* GetID3D12DebugCommandList_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12DebugCommandList_Wrapper>(id, ID3D12DebugCommandList_Wrapper_map_); }

    ID3D12SharingContract_Wrapper* GetID3D12SharingContract_Wrapper(format::HandleId id) { return GetWrapper<ID3D12SharingContract_Wrapper>(id, ID3D12SharingContract_Wrapper_map_); }
    const ID3D12SharingContract_Wrapper* GetID3D12SharingContract_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12SharingContract_Wrapper>(id, ID3D12SharingContract_Wrapper_map_); }

    ID3D12ManualWriteTrackingResource_Wrapper* GetID3D12ManualWriteTrackingResource_Wrapper(format::HandleId id) { return GetWrapper<ID3D12ManualWriteTrackingResource_Wrapper>(id, ID3D12ManualWriteTrackingResource_Wrapper_map_); }
    const ID3D12ManualWriteTrackingResource_Wrapper* GetID3D12ManualWriteTrackingResource_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12ManualWriteTrackingResource_Wrapper>(id, ID3D12ManualWriteTrackingResource_Wrapper_map_); }

    ID3D12InfoQueue_Wrapper* GetID3D12InfoQueue_Wrapper(format::HandleId id) { return GetWrapper<ID3D12InfoQueue_Wrapper>(id, ID3D12InfoQueue_Wrapper_map_); }
    const ID3D12InfoQueue_Wrapper* GetID3D12InfoQueue_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12InfoQueue_Wrapper>(id, ID3D12InfoQueue_Wrapper_map_); }

    ID3D11DepthStencilState_Wrapper* GetID3D11DepthStencilState_Wrapper(format::HandleId id) { return GetWrapper<ID3D11DepthStencilState_Wrapper>(id, ID3D11DepthStencilState_Wrapper_map_); }
    const ID3D11DepthStencilState_Wrapper* GetID3D11DepthStencilState_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11DepthStencilState_Wrapper>(id, ID3D11DepthStencilState_Wrapper_map_); }

    ID3D11Buffer_Wrapper* GetID3D11Buffer_Wrapper(format::HandleId id) { return GetWrapper<ID3D11Buffer_Wrapper>(id, ID3D11Buffer_Wrapper_map_); }
    const ID3D11Buffer_Wrapper* GetID3D11Buffer_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11Buffer_Wrapper>(id, ID3D11Buffer_Wrapper_map_); }

    ID3D11Texture1D_Wrapper* GetID3D11Texture1D_Wrapper(format::HandleId id) { return GetWrapper<ID3D11Texture1D_Wrapper>(id, ID3D11Texture1D_Wrapper_map_); }
    const ID3D11Texture1D_Wrapper* GetID3D11Texture1D_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11Texture1D_Wrapper>(id, ID3D11Texture1D_Wrapper_map_); }

    ID3D11DepthStencilView_Wrapper* GetID3D11DepthStencilView_Wrapper(format::HandleId id) { return GetWrapper<ID3D11DepthStencilView_Wrapper>(id, ID3D11DepthStencilView_Wrapper_map_); }
    const ID3D11DepthStencilView_Wrapper* GetID3D11DepthStencilView_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11DepthStencilView_Wrapper>(id, ID3D11DepthStencilView_Wrapper_map_); }

    ID3D11VertexShader_Wrapper* GetID3D11VertexShader_Wrapper(format::HandleId id) { return GetWrapper<ID3D11VertexShader_Wrapper>(id, ID3D11VertexShader_Wrapper_map_); }
    const ID3D11VertexShader_Wrapper* GetID3D11VertexShader_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11VertexShader_Wrapper>(id, ID3D11VertexShader_Wrapper_map_); }

    ID3D11HullShader_Wrapper* GetID3D11HullShader_Wrapper(format::HandleId id) { return GetWrapper<ID3D11HullShader_Wrapper>(id, ID3D11HullShader_Wrapper_map_); }
    const ID3D11HullShader_Wrapper* GetID3D11HullShader_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11HullShader_Wrapper>(id, ID3D11HullShader_Wrapper_map_); }

    ID3D11DomainShader_Wrapper* GetID3D11DomainShader_Wrapper(format::HandleId id) { return GetWrapper<ID3D11DomainShader_Wrapper>(id, ID3D11DomainShader_Wrapper_map_); }
    const ID3D11DomainShader_Wrapper* GetID3D11DomainShader_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11DomainShader_Wrapper>(id, ID3D11DomainShader_Wrapper_map_); }

    ID3D11GeometryShader_Wrapper* GetID3D11GeometryShader_Wrapper(format::HandleId id) { return GetWrapper<ID3D11GeometryShader_Wrapper>(id, ID3D11GeometryShader_Wrapper_map_); }
    const ID3D11GeometryShader_Wrapper* GetID3D11GeometryShader_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11GeometryShader_Wrapper>(id, ID3D11GeometryShader_Wrapper_map_); }

    ID3D11PixelShader_Wrapper* GetID3D11PixelShader_Wrapper(format::HandleId id) { return GetWrapper<ID3D11PixelShader_Wrapper>(id, ID3D11PixelShader_Wrapper_map_); }
    const ID3D11PixelShader_Wrapper* GetID3D11PixelShader_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11PixelShader_Wrapper>(id, ID3D11PixelShader_Wrapper_map_); }

    ID3D11ComputeShader_Wrapper* GetID3D11ComputeShader_Wrapper(format::HandleId id) { return GetWrapper<ID3D11ComputeShader_Wrapper>(id, ID3D11ComputeShader_Wrapper_map_); }
    const ID3D11ComputeShader_Wrapper* GetID3D11ComputeShader_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11ComputeShader_Wrapper>(id, ID3D11ComputeShader_Wrapper_map_); }

    ID3D11InputLayout_Wrapper* GetID3D11InputLayout_Wrapper(format::HandleId id) { return GetWrapper<ID3D11InputLayout_Wrapper>(id, ID3D11InputLayout_Wrapper_map_); }
    const ID3D11InputLayout_Wrapper* GetID3D11InputLayout_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11InputLayout_Wrapper>(id, ID3D11InputLayout_Wrapper_map_); }

    ID3D11SamplerState_Wrapper* GetID3D11SamplerState_Wrapper(format::HandleId id) { return GetWrapper<ID3D11SamplerState_Wrapper>(id, ID3D11SamplerState_Wrapper_map_); }
    const ID3D11SamplerState_Wrapper* GetID3D11SamplerState_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11SamplerState_Wrapper>(id, ID3D11SamplerState_Wrapper_map_); }

    ID3D11Predicate_Wrapper* GetID3D11Predicate_Wrapper(format::HandleId id) { return GetWrapper<ID3D11Predicate_Wrapper>(id, ID3D11Predicate_Wrapper_map_); }
    const ID3D11Predicate_Wrapper* GetID3D11Predicate_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11Predicate_Wrapper>(id, ID3D11Predicate_Wrapper_map_); }

    ID3D11Counter_Wrapper* GetID3D11Counter_Wrapper(format::HandleId id) { return GetWrapper<ID3D11Counter_Wrapper>(id, ID3D11Counter_Wrapper_map_); }
    const ID3D11Counter_Wrapper* GetID3D11Counter_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11Counter_Wrapper>(id, ID3D11Counter_Wrapper_map_); }

    ID3D11ClassInstance_Wrapper* GetID3D11ClassInstance_Wrapper(format::HandleId id) { return GetWrapper<ID3D11ClassInstance_Wrapper>(id, ID3D11ClassInstance_Wrapper_map_); }
    const ID3D11ClassInstance_Wrapper* GetID3D11ClassInstance_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11ClassInstance_Wrapper>(id, ID3D11ClassInstance_Wrapper_map_); }

    ID3D11ClassLinkage_Wrapper* GetID3D11ClassLinkage_Wrapper(format::HandleId id) { return GetWrapper<ID3D11ClassLinkage_Wrapper>(id, ID3D11ClassLinkage_Wrapper_map_); }
    const ID3D11ClassLinkage_Wrapper* GetID3D11ClassLinkage_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11ClassLinkage_Wrapper>(id, ID3D11ClassLinkage_Wrapper_map_); }

    ID3D11CommandList_Wrapper* GetID3D11CommandList_Wrapper(format::HandleId id) { return GetWrapper<ID3D11CommandList_Wrapper>(id, ID3D11CommandList_Wrapper_map_); }
    const ID3D11CommandList_Wrapper* GetID3D11CommandList_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11CommandList_Wrapper>(id, ID3D11CommandList_Wrapper_map_); }

    ID3D11VideoDecoder_Wrapper* GetID3D11VideoDecoder_Wrapper(format::HandleId id) { return GetWrapper<ID3D11VideoDecoder_Wrapper>(id, ID3D11VideoDecoder_Wrapper_map_); }
    const ID3D11VideoDecoder_Wrapper* GetID3D11VideoDecoder_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11VideoDecoder_Wrapper>(id, ID3D11VideoDecoder_Wrapper_map_); }

    ID3D11VideoProcessor_Wrapper* GetID3D11VideoProcessor_Wrapper(format::HandleId id) { return GetWrapper<ID3D11VideoProcessor_Wrapper>(id, ID3D11VideoProcessor_Wrapper_map_); }
    const ID3D11VideoProcessor_Wrapper* GetID3D11VideoProcessor_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11VideoProcessor_Wrapper>(id, ID3D11VideoProcessor_Wrapper_map_); }

    ID3D11AuthenticatedChannel_Wrapper* GetID3D11AuthenticatedChannel_Wrapper(format::HandleId id) { return GetWrapper<ID3D11AuthenticatedChannel_Wrapper>(id, ID3D11AuthenticatedChannel_Wrapper_map_); }
    const ID3D11AuthenticatedChannel_Wrapper* GetID3D11AuthenticatedChannel_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11AuthenticatedChannel_Wrapper>(id, ID3D11AuthenticatedChannel_Wrapper_map_); }

    ID3D11CryptoSession_Wrapper* GetID3D11CryptoSession_Wrapper(format::HandleId id) { return GetWrapper<ID3D11CryptoSession_Wrapper>(id, ID3D11CryptoSession_Wrapper_map_); }
    const ID3D11CryptoSession_Wrapper* GetID3D11CryptoSession_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11CryptoSession_Wrapper>(id, ID3D11CryptoSession_Wrapper_map_); }

    ID3D11VideoDecoderOutputView_Wrapper* GetID3D11VideoDecoderOutputView_Wrapper(format::HandleId id) { return GetWrapper<ID3D11VideoDecoderOutputView_Wrapper>(id, ID3D11VideoDecoderOutputView_Wrapper_map_); }
    const ID3D11VideoDecoderOutputView_Wrapper* GetID3D11VideoDecoderOutputView_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11VideoDecoderOutputView_Wrapper>(id, ID3D11VideoDecoderOutputView_Wrapper_map_); }

    ID3D11VideoProcessorInputView_Wrapper* GetID3D11VideoProcessorInputView_Wrapper(format::HandleId id) { return GetWrapper<ID3D11VideoProcessorInputView_Wrapper>(id, ID3D11VideoProcessorInputView_Wrapper_map_); }
    const ID3D11VideoProcessorInputView_Wrapper* GetID3D11VideoProcessorInputView_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11VideoProcessorInputView_Wrapper>(id, ID3D11VideoProcessorInputView_Wrapper_map_); }

    ID3D11VideoProcessorOutputView_Wrapper* GetID3D11VideoProcessorOutputView_Wrapper(format::HandleId id) { return GetWrapper<ID3D11VideoProcessorOutputView_Wrapper>(id, ID3D11VideoProcessorOutputView_Wrapper_map_); }
    const ID3D11VideoProcessorOutputView_Wrapper* GetID3D11VideoProcessorOutputView_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11VideoProcessorOutputView_Wrapper>(id, ID3D11VideoProcessorOutputView_Wrapper_map_); }

    ID3D11BlendState_Wrapper* GetID3D11BlendState_Wrapper(format::HandleId id) { return GetWrapper<ID3D11BlendState_Wrapper>(id, ID3D11BlendState_Wrapper_map_); }
    const ID3D11BlendState_Wrapper* GetID3D11BlendState_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11BlendState_Wrapper>(id, ID3D11BlendState_Wrapper_map_); }

    ID3DDeviceContextState_Wrapper* GetID3DDeviceContextState_Wrapper(format::HandleId id) { return GetWrapper<ID3DDeviceContextState_Wrapper>(id, ID3DDeviceContextState_Wrapper_map_); }
    const ID3DDeviceContextState_Wrapper* GetID3DDeviceContextState_Wrapper(format::HandleId id) const { return GetWrapper<ID3DDeviceContextState_Wrapper>(id, ID3DDeviceContextState_Wrapper_map_); }

    ID3D11VideoContext_Wrapper* GetID3D11VideoContext_Wrapper(format::HandleId id) { return GetWrapper<ID3D11VideoContext_Wrapper>(id, ID3D11VideoContext_Wrapper_map_); }
    const ID3D11VideoContext_Wrapper* GetID3D11VideoContext_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11VideoContext_Wrapper>(id, ID3D11VideoContext_Wrapper_map_); }

    ID3D11VideoDevice_Wrapper* GetID3D11VideoDevice_Wrapper(format::HandleId id) { return GetWrapper<ID3D11VideoDevice_Wrapper>(id, ID3D11VideoDevice_Wrapper_map_); }
    const ID3D11VideoDevice_Wrapper* GetID3D11VideoDevice_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11VideoDevice_Wrapper>(id, ID3D11VideoDevice_Wrapper_map_); }

    ID3D11VideoProcessorEnumerator_Wrapper* GetID3D11VideoProcessorEnumerator_Wrapper(format::HandleId id) { return GetWrapper<ID3D11VideoProcessorEnumerator_Wrapper>(id, ID3D11VideoProcessorEnumerator_Wrapper_map_); }
    const ID3D11VideoProcessorEnumerator_Wrapper* GetID3D11VideoProcessorEnumerator_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11VideoProcessorEnumerator_Wrapper>(id, ID3D11VideoProcessorEnumerator_Wrapper_map_); }

    ID3DUserDefinedAnnotation_Wrapper* GetID3DUserDefinedAnnotation_Wrapper(format::HandleId id) { return GetWrapper<ID3DUserDefinedAnnotation_Wrapper>(id, ID3DUserDefinedAnnotation_Wrapper_map_); }
    const ID3DUserDefinedAnnotation_Wrapper* GetID3DUserDefinedAnnotation_Wrapper(format::HandleId id) const { return GetWrapper<ID3DUserDefinedAnnotation_Wrapper>(id, ID3DUserDefinedAnnotation_Wrapper_map_); }

    ID3D11Texture2D_Wrapper* GetID3D11Texture2D_Wrapper(format::HandleId id) { return GetWrapper<ID3D11Texture2D_Wrapper>(id, ID3D11Texture2D_Wrapper_map_); }
    const ID3D11Texture2D_Wrapper* GetID3D11Texture2D_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11Texture2D_Wrapper>(id, ID3D11Texture2D_Wrapper_map_); }

    ID3D11Texture3D_Wrapper* GetID3D11Texture3D_Wrapper(format::HandleId id) { return GetWrapper<ID3D11Texture3D_Wrapper>(id, ID3D11Texture3D_Wrapper_map_); }
    const ID3D11Texture3D_Wrapper* GetID3D11Texture3D_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11Texture3D_Wrapper>(id, ID3D11Texture3D_Wrapper_map_); }

    ID3D11RasterizerState_Wrapper* GetID3D11RasterizerState_Wrapper(format::HandleId id) { return GetWrapper<ID3D11RasterizerState_Wrapper>(id, ID3D11RasterizerState_Wrapper_map_); }
    const ID3D11RasterizerState_Wrapper* GetID3D11RasterizerState_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11RasterizerState_Wrapper>(id, ID3D11RasterizerState_Wrapper_map_); }

    ID3D11ShaderResourceView_Wrapper* GetID3D11ShaderResourceView_Wrapper(format::HandleId id) { return GetWrapper<ID3D11ShaderResourceView_Wrapper>(id, ID3D11ShaderResourceView_Wrapper_map_); }
    const ID3D11ShaderResourceView_Wrapper* GetID3D11ShaderResourceView_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11ShaderResourceView_Wrapper>(id, ID3D11ShaderResourceView_Wrapper_map_); }

    ID3D11RenderTargetView_Wrapper* GetID3D11RenderTargetView_Wrapper(format::HandleId id) { return GetWrapper<ID3D11RenderTargetView_Wrapper>(id, ID3D11RenderTargetView_Wrapper_map_); }
    const ID3D11RenderTargetView_Wrapper* GetID3D11RenderTargetView_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11RenderTargetView_Wrapper>(id, ID3D11RenderTargetView_Wrapper_map_); }

    ID3D11UnorderedAccessView_Wrapper* GetID3D11UnorderedAccessView_Wrapper(format::HandleId id) { return GetWrapper<ID3D11UnorderedAccessView_Wrapper>(id, ID3D11UnorderedAccessView_Wrapper_map_); }
    const ID3D11UnorderedAccessView_Wrapper* GetID3D11UnorderedAccessView_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11UnorderedAccessView_Wrapper>(id, ID3D11UnorderedAccessView_Wrapper_map_); }

    ID3D11Query_Wrapper* GetID3D11Query_Wrapper(format::HandleId id) { return GetWrapper<ID3D11Query_Wrapper>(id, ID3D11Query_Wrapper_map_); }
    const ID3D11Query_Wrapper* GetID3D11Query_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11Query_Wrapper>(id, ID3D11Query_Wrapper_map_); }

    ID3D11Fence_Wrapper* GetID3D11Fence_Wrapper(format::HandleId id) { return GetWrapper<ID3D11Fence_Wrapper>(id, ID3D11Fence_Wrapper_map_); }
    const ID3D11Fence_Wrapper* GetID3D11Fence_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11Fence_Wrapper>(id, ID3D11Fence_Wrapper_map_); }

    ID3D11DeviceContext_Wrapper* GetID3D11DeviceContext_Wrapper(format::HandleId id) { return GetWrapper<ID3D11DeviceContext_Wrapper>(id, ID3D11DeviceContext_Wrapper_map_); }
    const ID3D11DeviceContext_Wrapper* GetID3D11DeviceContext_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11DeviceContext_Wrapper>(id, ID3D11DeviceContext_Wrapper_map_); }

    ID3D11Device_Wrapper* GetID3D11Device_Wrapper(format::HandleId id) { return GetWrapper<ID3D11Device_Wrapper>(id, ID3D11Device_Wrapper_map_); }
    const ID3D11Device_Wrapper* GetID3D11Device_Wrapper(format::HandleId id) const { return GetWrapper<ID3D11Device_Wrapper>(id, ID3D11Device_Wrapper_map_); }

    IDXGIKeyedMutex_Wrapper* GetIDXGIKeyedMutex_Wrapper(format::HandleId id) { return GetWrapper<IDXGIKeyedMutex_Wrapper>(id, IDXGIKeyedMutex_Wrapper_map_); }
    const IDXGIKeyedMutex_Wrapper* GetIDXGIKeyedMutex_Wrapper(format::HandleId id) const { return GetWrapper<IDXGIKeyedMutex_Wrapper>(id, IDXGIKeyedMutex_Wrapper_map_); }

    IDXGIDisplayControl_Wrapper* GetIDXGIDisplayControl_Wrapper(format::HandleId id) { return GetWrapper<IDXGIDisplayControl_Wrapper>(id, IDXGIDisplayControl_Wrapper_map_); }
    const IDXGIDisplayControl_Wrapper* GetIDXGIDisplayControl_Wrapper(format::HandleId id) const { return GetWrapper<IDXGIDisplayControl_Wrapper>(id, IDXGIDisplayControl_Wrapper_map_); }

    IDXGIOutputDuplication_Wrapper* GetIDXGIOutputDuplication_Wrapper(format::HandleId id) { return GetWrapper<IDXGIOutputDuplication_Wrapper>(id, IDXGIOutputDuplication_Wrapper_map_); }
    const IDXGIOutputDuplication_Wrapper* GetIDXGIOutputDuplication_Wrapper(format::HandleId id) const { return GetWrapper<IDXGIOutputDuplication_Wrapper>(id, IDXGIOutputDuplication_Wrapper_map_); }

    IDXGISurface_Wrapper* GetIDXGISurface_Wrapper(format::HandleId id) { return GetWrapper<IDXGISurface_Wrapper>(id, IDXGISurface_Wrapper_map_); }
    const IDXGISurface_Wrapper* GetIDXGISurface_Wrapper(format::HandleId id) const { return GetWrapper<IDXGISurface_Wrapper>(id, IDXGISurface_Wrapper_map_); }

    IDXGIResource_Wrapper* GetIDXGIResource_Wrapper(format::HandleId id) { return GetWrapper<IDXGIResource_Wrapper>(id, IDXGIResource_Wrapper_map_); }
    const IDXGIResource_Wrapper* GetIDXGIResource_Wrapper(format::HandleId id) const { return GetWrapper<IDXGIResource_Wrapper>(id, IDXGIResource_Wrapper_map_); }

    IDXGIDecodeSwapChain_Wrapper* GetIDXGIDecodeSwapChain_Wrapper(format::HandleId id) { return GetWrapper<IDXGIDecodeSwapChain_Wrapper>(id, IDXGIDecodeSwapChain_Wrapper_map_); }
    const IDXGIDecodeSwapChain_Wrapper* GetIDXGIDecodeSwapChain_Wrapper(format::HandleId id) const { return GetWrapper<IDXGIDecodeSwapChain_Wrapper>(id, IDXGIDecodeSwapChain_Wrapper_map_); }

    IDXGIFactoryMedia_Wrapper* GetIDXGIFactoryMedia_Wrapper(format::HandleId id) { return GetWrapper<IDXGIFactoryMedia_Wrapper>(id, IDXGIFactoryMedia_Wrapper_map_); }
    const IDXGIFactoryMedia_Wrapper* GetIDXGIFactoryMedia_Wrapper(format::HandleId id) const { return GetWrapper<IDXGIFactoryMedia_Wrapper>(id, IDXGIFactoryMedia_Wrapper_map_); }

    IDXGISwapChainMedia_Wrapper* GetIDXGISwapChainMedia_Wrapper(format::HandleId id) { return GetWrapper<IDXGISwapChainMedia_Wrapper>(id, IDXGISwapChainMedia_Wrapper_map_); }
    const IDXGISwapChainMedia_Wrapper* GetIDXGISwapChainMedia_Wrapper(format::HandleId id) const { return GetWrapper<IDXGISwapChainMedia_Wrapper>(id, IDXGISwapChainMedia_Wrapper_map_); }

    IDXGISwapChain_Wrapper* GetIDXGISwapChain_Wrapper(format::HandleId id) { return GetWrapper<IDXGISwapChain_Wrapper>(id, IDXGISwapChain_Wrapper_map_); }
    const IDXGISwapChain_Wrapper* GetIDXGISwapChain_Wrapper(format::HandleId id) const { return GetWrapper<IDXGISwapChain_Wrapper>(id, IDXGISwapChain_Wrapper_map_); }

    IDXGIDevice_Wrapper* GetIDXGIDevice_Wrapper(format::HandleId id) { return GetWrapper<IDXGIDevice_Wrapper>(id, IDXGIDevice_Wrapper_map_); }
    const IDXGIDevice_Wrapper* GetIDXGIDevice_Wrapper(format::HandleId id) const { return GetWrapper<IDXGIDevice_Wrapper>(id, IDXGIDevice_Wrapper_map_); }

    IDXGIAdapter_Wrapper* GetIDXGIAdapter_Wrapper(format::HandleId id) { return GetWrapper<IDXGIAdapter_Wrapper>(id, IDXGIAdapter_Wrapper_map_); }
    const IDXGIAdapter_Wrapper* GetIDXGIAdapter_Wrapper(format::HandleId id) const { return GetWrapper<IDXGIAdapter_Wrapper>(id, IDXGIAdapter_Wrapper_map_); }

    IDXGIOutput_Wrapper* GetIDXGIOutput_Wrapper(format::HandleId id) { return GetWrapper<IDXGIOutput_Wrapper>(id, IDXGIOutput_Wrapper_map_); }
    const IDXGIOutput_Wrapper* GetIDXGIOutput_Wrapper(format::HandleId id) const { return GetWrapper<IDXGIOutput_Wrapper>(id, IDXGIOutput_Wrapper_map_); }

    IDXGIFactory_Wrapper* GetIDXGIFactory_Wrapper(format::HandleId id) { return GetWrapper<IDXGIFactory_Wrapper>(id, IDXGIFactory_Wrapper_map_); }
    const IDXGIFactory_Wrapper* GetIDXGIFactory_Wrapper(format::HandleId id) const { return GetWrapper<IDXGIFactory_Wrapper>(id, IDXGIFactory_Wrapper_map_); }


  private:
    std::map<format::HandleId, ID3D12RootSignature_Wrapper*> ID3D12RootSignature_Wrapper_map_;
    std::map<format::HandleId, ID3D12RootSignatureDeserializer_Wrapper*> ID3D12RootSignatureDeserializer_Wrapper_map_;
    std::map<format::HandleId, ID3D12VersionedRootSignatureDeserializer_Wrapper*> ID3D12VersionedRootSignatureDeserializer_Wrapper_map_;
    std::map<format::HandleId, ID3D12CommandAllocator_Wrapper*> ID3D12CommandAllocator_Wrapper_map_;
    std::map<format::HandleId, ID3D12Fence_Wrapper*> ID3D12Fence_Wrapper_map_;
    std::map<format::HandleId, ID3D12PipelineState_Wrapper*> ID3D12PipelineState_Wrapper_map_;
    std::map<format::HandleId, ID3D12DescriptorHeap_Wrapper*> ID3D12DescriptorHeap_Wrapper_map_;
    std::map<format::HandleId, ID3D12QueryHeap_Wrapper*> ID3D12QueryHeap_Wrapper_map_;
    std::map<format::HandleId, ID3D12CommandSignature_Wrapper*> ID3D12CommandSignature_Wrapper_map_;
    std::map<format::HandleId, ID3D12CommandQueue_Wrapper*> ID3D12CommandQueue_Wrapper_map_;
    std::map<format::HandleId, ID3D12PipelineLibrary_Wrapper*> ID3D12PipelineLibrary_Wrapper_map_;
    std::map<format::HandleId, ID3D12LifetimeOwner_Wrapper*> ID3D12LifetimeOwner_Wrapper_map_;
    std::map<format::HandleId, ID3D12SwapChainAssistant_Wrapper*> ID3D12SwapChainAssistant_Wrapper_map_;
    std::map<format::HandleId, ID3D12LifetimeTracker_Wrapper*> ID3D12LifetimeTracker_Wrapper_map_;
    std::map<format::HandleId, ID3D12StateObject_Wrapper*> ID3D12StateObject_Wrapper_map_;
    std::map<format::HandleId, ID3D12StateObjectProperties_Wrapper*> ID3D12StateObjectProperties_Wrapper_map_;
    std::map<format::HandleId, ID3D12WorkGraphProperties_Wrapper*> ID3D12WorkGraphProperties_Wrapper_map_;
    std::map<format::HandleId, ID3D12DeviceRemovedExtendedDataSettings_Wrapper*> ID3D12DeviceRemovedExtendedDataSettings_Wrapper_map_;
    std::map<format::HandleId, ID3D12DeviceRemovedExtendedData_Wrapper*> ID3D12DeviceRemovedExtendedData_Wrapper_map_;
    std::map<format::HandleId, ID3D12ProtectedResourceSession_Wrapper*> ID3D12ProtectedResourceSession_Wrapper_map_;
    std::map<format::HandleId, ID3D12Resource_Wrapper*> ID3D12Resource_Wrapper_map_;
    std::map<format::HandleId, ID3D12Heap_Wrapper*> ID3D12Heap_Wrapper_map_;
    std::map<format::HandleId, ID3D12MetaCommand_Wrapper*> ID3D12MetaCommand_Wrapper_map_;
    std::map<format::HandleId, ID3D12ShaderCacheSession_Wrapper*> ID3D12ShaderCacheSession_Wrapper_map_;
    std::map<format::HandleId, ID3D12Device_Wrapper*> ID3D12Device_Wrapper_map_;
    std::map<format::HandleId, ID3D12VirtualizationGuestDevice_Wrapper*> ID3D12VirtualizationGuestDevice_Wrapper_map_;
    std::map<format::HandleId, ID3D12Tools_Wrapper*> ID3D12Tools_Wrapper_map_;
    std::map<format::HandleId, ID3D12PageableTools_Wrapper*> ID3D12PageableTools_Wrapper_map_;
    std::map<format::HandleId, ID3D12DeviceTools_Wrapper*> ID3D12DeviceTools_Wrapper_map_;
    std::map<format::HandleId, ID3D12SDKConfiguration_Wrapper*> ID3D12SDKConfiguration_Wrapper_map_;
    std::map<format::HandleId, ID3D12DeviceFactory_Wrapper*> ID3D12DeviceFactory_Wrapper_map_;
    std::map<format::HandleId, ID3D12DeviceConfiguration_Wrapper*> ID3D12DeviceConfiguration_Wrapper_map_;
    std::map<format::HandleId, ID3D12CommandList_Wrapper*> ID3D12CommandList_Wrapper_map_;
    std::map<format::HandleId, ID3D12DSRDeviceFactory_Wrapper*> ID3D12DSRDeviceFactory_Wrapper_map_;
    std::map<format::HandleId, ID3D12GBVDiagnostics_Wrapper*> ID3D12GBVDiagnostics_Wrapper_map_;
    std::map<format::HandleId, ID3D10Blob_Wrapper*> ID3D10Blob_Wrapper_map_;
    std::map<format::HandleId, ID3DDestructionNotifier_Wrapper*> ID3DDestructionNotifier_Wrapper_map_;
    std::map<format::HandleId, ID3D12Debug1_Wrapper*> ID3D12Debug1_Wrapper_map_;
    std::map<format::HandleId, ID3D12Debug2_Wrapper*> ID3D12Debug2_Wrapper_map_;
    std::map<format::HandleId, ID3D12Debug_Wrapper*> ID3D12Debug_Wrapper_map_;
    std::map<format::HandleId, ID3D12DebugDevice1_Wrapper*> ID3D12DebugDevice1_Wrapper_map_;
    std::map<format::HandleId, ID3D12DebugDevice_Wrapper*> ID3D12DebugDevice_Wrapper_map_;
    std::map<format::HandleId, ID3D12DebugCommandQueue_Wrapper*> ID3D12DebugCommandQueue_Wrapper_map_;
    std::map<format::HandleId, ID3D12DebugCommandList1_Wrapper*> ID3D12DebugCommandList1_Wrapper_map_;
    std::map<format::HandleId, ID3D12DebugCommandList_Wrapper*> ID3D12DebugCommandList_Wrapper_map_;
    std::map<format::HandleId, ID3D12SharingContract_Wrapper*> ID3D12SharingContract_Wrapper_map_;
    std::map<format::HandleId, ID3D12ManualWriteTrackingResource_Wrapper*> ID3D12ManualWriteTrackingResource_Wrapper_map_;
    std::map<format::HandleId, ID3D12InfoQueue_Wrapper*> ID3D12InfoQueue_Wrapper_map_;
    std::map<format::HandleId, ID3D11DepthStencilState_Wrapper*> ID3D11DepthStencilState_Wrapper_map_;
    std::map<format::HandleId, ID3D11Buffer_Wrapper*> ID3D11Buffer_Wrapper_map_;
    std::map<format::HandleId, ID3D11Texture1D_Wrapper*> ID3D11Texture1D_Wrapper_map_;
    std::map<format::HandleId, ID3D11DepthStencilView_Wrapper*> ID3D11DepthStencilView_Wrapper_map_;
    std::map<format::HandleId, ID3D11VertexShader_Wrapper*> ID3D11VertexShader_Wrapper_map_;
    std::map<format::HandleId, ID3D11HullShader_Wrapper*> ID3D11HullShader_Wrapper_map_;
    std::map<format::HandleId, ID3D11DomainShader_Wrapper*> ID3D11DomainShader_Wrapper_map_;
    std::map<format::HandleId, ID3D11GeometryShader_Wrapper*> ID3D11GeometryShader_Wrapper_map_;
    std::map<format::HandleId, ID3D11PixelShader_Wrapper*> ID3D11PixelShader_Wrapper_map_;
    std::map<format::HandleId, ID3D11ComputeShader_Wrapper*> ID3D11ComputeShader_Wrapper_map_;
    std::map<format::HandleId, ID3D11InputLayout_Wrapper*> ID3D11InputLayout_Wrapper_map_;
    std::map<format::HandleId, ID3D11SamplerState_Wrapper*> ID3D11SamplerState_Wrapper_map_;
    std::map<format::HandleId, ID3D11Predicate_Wrapper*> ID3D11Predicate_Wrapper_map_;
    std::map<format::HandleId, ID3D11Counter_Wrapper*> ID3D11Counter_Wrapper_map_;
    std::map<format::HandleId, ID3D11ClassInstance_Wrapper*> ID3D11ClassInstance_Wrapper_map_;
    std::map<format::HandleId, ID3D11ClassLinkage_Wrapper*> ID3D11ClassLinkage_Wrapper_map_;
    std::map<format::HandleId, ID3D11CommandList_Wrapper*> ID3D11CommandList_Wrapper_map_;
    std::map<format::HandleId, ID3D11VideoDecoder_Wrapper*> ID3D11VideoDecoder_Wrapper_map_;
    std::map<format::HandleId, ID3D11VideoProcessor_Wrapper*> ID3D11VideoProcessor_Wrapper_map_;
    std::map<format::HandleId, ID3D11AuthenticatedChannel_Wrapper*> ID3D11AuthenticatedChannel_Wrapper_map_;
    std::map<format::HandleId, ID3D11CryptoSession_Wrapper*> ID3D11CryptoSession_Wrapper_map_;
    std::map<format::HandleId, ID3D11VideoDecoderOutputView_Wrapper*> ID3D11VideoDecoderOutputView_Wrapper_map_;
    std::map<format::HandleId, ID3D11VideoProcessorInputView_Wrapper*> ID3D11VideoProcessorInputView_Wrapper_map_;
    std::map<format::HandleId, ID3D11VideoProcessorOutputView_Wrapper*> ID3D11VideoProcessorOutputView_Wrapper_map_;
    std::map<format::HandleId, ID3D11BlendState_Wrapper*> ID3D11BlendState_Wrapper_map_;
    std::map<format::HandleId, ID3DDeviceContextState_Wrapper*> ID3DDeviceContextState_Wrapper_map_;
    std::map<format::HandleId, ID3D11VideoContext_Wrapper*> ID3D11VideoContext_Wrapper_map_;
    std::map<format::HandleId, ID3D11VideoDevice_Wrapper*> ID3D11VideoDevice_Wrapper_map_;
    std::map<format::HandleId, ID3D11VideoProcessorEnumerator_Wrapper*> ID3D11VideoProcessorEnumerator_Wrapper_map_;
    std::map<format::HandleId, ID3DUserDefinedAnnotation_Wrapper*> ID3DUserDefinedAnnotation_Wrapper_map_;
    std::map<format::HandleId, ID3D11Texture2D_Wrapper*> ID3D11Texture2D_Wrapper_map_;
    std::map<format::HandleId, ID3D11Texture3D_Wrapper*> ID3D11Texture3D_Wrapper_map_;
    std::map<format::HandleId, ID3D11RasterizerState_Wrapper*> ID3D11RasterizerState_Wrapper_map_;
    std::map<format::HandleId, ID3D11ShaderResourceView_Wrapper*> ID3D11ShaderResourceView_Wrapper_map_;
    std::map<format::HandleId, ID3D11RenderTargetView_Wrapper*> ID3D11RenderTargetView_Wrapper_map_;
    std::map<format::HandleId, ID3D11UnorderedAccessView_Wrapper*> ID3D11UnorderedAccessView_Wrapper_map_;
    std::map<format::HandleId, ID3D11Query_Wrapper*> ID3D11Query_Wrapper_map_;
    std::map<format::HandleId, ID3D11Fence_Wrapper*> ID3D11Fence_Wrapper_map_;
    std::map<format::HandleId, ID3D11DeviceContext_Wrapper*> ID3D11DeviceContext_Wrapper_map_;
    std::map<format::HandleId, ID3D11Device_Wrapper*> ID3D11Device_Wrapper_map_;
    std::map<format::HandleId, IDXGIKeyedMutex_Wrapper*> IDXGIKeyedMutex_Wrapper_map_;
    std::map<format::HandleId, IDXGIDisplayControl_Wrapper*> IDXGIDisplayControl_Wrapper_map_;
    std::map<format::HandleId, IDXGIOutputDuplication_Wrapper*> IDXGIOutputDuplication_Wrapper_map_;
    std::map<format::HandleId, IDXGISurface_Wrapper*> IDXGISurface_Wrapper_map_;
    std::map<format::HandleId, IDXGIResource_Wrapper*> IDXGIResource_Wrapper_map_;
    std::map<format::HandleId, IDXGIDecodeSwapChain_Wrapper*> IDXGIDecodeSwapChain_Wrapper_map_;
    std::map<format::HandleId, IDXGIFactoryMedia_Wrapper*> IDXGIFactoryMedia_Wrapper_map_;
    std::map<format::HandleId, IDXGISwapChainMedia_Wrapper*> IDXGISwapChainMedia_Wrapper_map_;
    std::map<format::HandleId, IDXGISwapChain_Wrapper*> IDXGISwapChain_Wrapper_map_;
    std::map<format::HandleId, IDXGIDevice_Wrapper*> IDXGIDevice_Wrapper_map_;
    std::map<format::HandleId, IDXGIAdapter_Wrapper*> IDXGIAdapter_Wrapper_map_;
    std::map<format::HandleId, IDXGIOutput_Wrapper*> IDXGIOutput_Wrapper_map_;
    std::map<format::HandleId, IDXGIFactory_Wrapper*> IDXGIFactory_Wrapper_map_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
