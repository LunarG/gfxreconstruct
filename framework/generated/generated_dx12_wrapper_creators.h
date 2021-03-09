/*
** Copyright (c) 2021 LunarG, Inc.
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
** This file is generated from dx12_wrapper_creators_header_generator.py.
**
*/

#ifndef  GFXRECON_GENERATED_DX12_WRAPPER_CREATORS_H
#define  GFXRECON_GENERATED_DX12_WRAPPER_CREATORS_H

#include "encode/dx12_object_wrapper_resources.h"
#include "util/defines.h"
#include <unordered_map>
#include <functional>

#include <dxgi.h>
#include <dxgi1_2.h>
#include <dxgi1_3.h>
#include <dxgi1_4.h>
#include <dxgi1_5.h>
#include <dxgi1_6.h>
#include <dxgicommon.h>
#include <dxgiformat.h>
#include <dxgitype.h>
#include <d3d12.h>
#include <d3dcommon.h>
#include <Unknwnbase.h>
#include <guiddef.h>
#include <windef.h>
#include <minwinbase.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

struct IidHash {
    size_t operator()(const IID &iid) const noexcept {
        const uint32_t *p = reinterpret_cast<const uint32_t *>(&iid);
        return p[0] ^ p[1] ^ p[2] ^ p[3];
    }
};


IUnknown_Wrapper* WrapObject(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapIDXGIKeyedMutex(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapIDXGIDisplayControl(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapIDXGIOutputDuplication(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapIDXGISurface(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapIDXGIResource(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapIDXGIDecodeSwapChain(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapIDXGIFactoryMedia(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapIDXGISwapChainMedia(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapIDXGISwapChain(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapIDXGIDevice(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapIDXGIAdapter(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapIDXGIOutput(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapIDXGIFactory(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapID3D12RootSignature(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapID3D12RootSignatureDeserializer(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapID3D12VersionedRootSignatureDeserializer(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapID3D12CommandAllocator(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapID3D12Fence(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapID3D12PipelineState(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapID3D12DescriptorHeap(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapID3D12QueryHeap(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapID3D12CommandSignature(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapID3D12CommandQueue(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapID3D12PipelineLibrary(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapID3D12LifetimeOwner(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapID3D12SwapChainAssistant(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapID3D12LifetimeTracker(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapID3D12StateObject(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapID3D12StateObjectProperties(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapID3D12DeviceRemovedExtendedDataSettings(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapID3D12DeviceRemovedExtendedData(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapID3D12ProtectedResourceSession(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapID3D12Device(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapID3D12Resource(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapID3D12Heap(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapID3D12MetaCommand(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapID3D12Tools(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapID3D12GraphicsCommandList(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapID3D10Blob(REFIID riid, void** object, DxWrapperResources* resources);

IUnknown_Wrapper*  WrapID3DDestructionNotifier(REFIID riid, void** object, DxWrapperResources* resources);

const std::unordered_map<IID, std::function<IUnknown_Wrapper*(REFIID, void**,DxWrapperResources*)>,IidHash> kFunctionTable
{

{IID_IDXGIKeyedMutex, WrapIDXGIKeyedMutex},
{IID_IDXGIDisplayControl, WrapIDXGIDisplayControl},
{IID_IDXGIOutputDuplication, WrapIDXGIOutputDuplication},
{IID_IDXGISurface, WrapIDXGISurface},
{IID_IDXGISurface1, WrapIDXGISurface},
{IID_IDXGISurface2, WrapIDXGISurface},
{IID_IDXGIResource, WrapIDXGIResource},
{IID_IDXGIResource1, WrapIDXGIResource},
{IID_IDXGIDecodeSwapChain, WrapIDXGIDecodeSwapChain},
{IID_IDXGIFactoryMedia, WrapIDXGIFactoryMedia},
{IID_IDXGISwapChainMedia, WrapIDXGISwapChainMedia},
{IID_IDXGISwapChain, WrapIDXGISwapChain},
{IID_IDXGISwapChain1, WrapIDXGISwapChain},
{IID_IDXGISwapChain2, WrapIDXGISwapChain},
{IID_IDXGISwapChain3, WrapIDXGISwapChain},
{IID_IDXGISwapChain4, WrapIDXGISwapChain},
{IID_IDXGIDevice, WrapIDXGIDevice},
{IID_IDXGIDevice1, WrapIDXGIDevice},
{IID_IDXGIDevice2, WrapIDXGIDevice},
{IID_IDXGIDevice3, WrapIDXGIDevice},
{IID_IDXGIDevice4, WrapIDXGIDevice},
{IID_IDXGIAdapter, WrapIDXGIAdapter},
{IID_IDXGIAdapter1, WrapIDXGIAdapter},
{IID_IDXGIAdapter2, WrapIDXGIAdapter},
{IID_IDXGIAdapter3, WrapIDXGIAdapter},
{IID_IDXGIAdapter4, WrapIDXGIAdapter},
{IID_IDXGIOutput, WrapIDXGIOutput},
{IID_IDXGIOutput1, WrapIDXGIOutput},
{IID_IDXGIOutput2, WrapIDXGIOutput},
{IID_IDXGIOutput3, WrapIDXGIOutput},
{IID_IDXGIOutput4, WrapIDXGIOutput},
{IID_IDXGIOutput5, WrapIDXGIOutput},
{IID_IDXGIOutput6, WrapIDXGIOutput},
{IID_IDXGIFactory, WrapIDXGIFactory},
{IID_IDXGIFactory1, WrapIDXGIFactory},
{IID_IDXGIFactory2, WrapIDXGIFactory},
{IID_IDXGIFactory3, WrapIDXGIFactory},
{IID_IDXGIFactory4, WrapIDXGIFactory},
{IID_IDXGIFactory5, WrapIDXGIFactory},
{IID_IDXGIFactory6, WrapIDXGIFactory},
{IID_IDXGIFactory7, WrapIDXGIFactory},
{IID_ID3D12RootSignature, WrapID3D12RootSignature},
{IID_ID3D12RootSignatureDeserializer, WrapID3D12RootSignatureDeserializer},
{IID_ID3D12VersionedRootSignatureDeserializer, WrapID3D12VersionedRootSignatureDeserializer},
{IID_ID3D12CommandAllocator, WrapID3D12CommandAllocator},
{IID_ID3D12Fence, WrapID3D12Fence},
{IID_ID3D12Fence1, WrapID3D12Fence},
{IID_ID3D12PipelineState, WrapID3D12PipelineState},
{IID_ID3D12DescriptorHeap, WrapID3D12DescriptorHeap},
{IID_ID3D12QueryHeap, WrapID3D12QueryHeap},
{IID_ID3D12CommandSignature, WrapID3D12CommandSignature},
{IID_ID3D12CommandQueue, WrapID3D12CommandQueue},
{IID_ID3D12PipelineLibrary, WrapID3D12PipelineLibrary},
{IID_ID3D12PipelineLibrary1, WrapID3D12PipelineLibrary},
{IID_ID3D12LifetimeOwner, WrapID3D12LifetimeOwner},
{IID_ID3D12SwapChainAssistant, WrapID3D12SwapChainAssistant},
{IID_ID3D12LifetimeTracker, WrapID3D12LifetimeTracker},
{IID_ID3D12StateObject, WrapID3D12StateObject},
{IID_ID3D12StateObjectProperties, WrapID3D12StateObjectProperties},
{IID_ID3D12DeviceRemovedExtendedDataSettings, WrapID3D12DeviceRemovedExtendedDataSettings},
{IID_ID3D12DeviceRemovedExtendedDataSettings1, WrapID3D12DeviceRemovedExtendedDataSettings},
{IID_ID3D12DeviceRemovedExtendedData, WrapID3D12DeviceRemovedExtendedData},
{IID_ID3D12DeviceRemovedExtendedData1, WrapID3D12DeviceRemovedExtendedData},
{IID_ID3D12ProtectedResourceSession, WrapID3D12ProtectedResourceSession},
{IID_ID3D12ProtectedResourceSession1, WrapID3D12ProtectedResourceSession},
{IID_ID3D12Device, WrapID3D12Device},
{IID_ID3D12Device1, WrapID3D12Device},
{IID_ID3D12Device2, WrapID3D12Device},
{IID_ID3D12Device3, WrapID3D12Device},
{IID_ID3D12Device4, WrapID3D12Device},
{IID_ID3D12Device5, WrapID3D12Device},
{IID_ID3D12Device6, WrapID3D12Device},
{IID_ID3D12Device7, WrapID3D12Device},
{IID_ID3D12Device8, WrapID3D12Device},
{IID_ID3D12Resource, WrapID3D12Resource},
{IID_ID3D12Resource1, WrapID3D12Resource},
{IID_ID3D12Resource2, WrapID3D12Resource},
{IID_ID3D12Heap, WrapID3D12Heap},
{IID_ID3D12Heap1, WrapID3D12Heap},
{IID_ID3D12MetaCommand, WrapID3D12MetaCommand},
{IID_ID3D12Tools, WrapID3D12Tools},
{IID_ID3D12GraphicsCommandList, WrapID3D12GraphicsCommandList},
{IID_ID3D12GraphicsCommandList1, WrapID3D12GraphicsCommandList},
{IID_ID3D12GraphicsCommandList2, WrapID3D12GraphicsCommandList},
{IID_ID3D12GraphicsCommandList3, WrapID3D12GraphicsCommandList},
{IID_ID3D12GraphicsCommandList4, WrapID3D12GraphicsCommandList},
{IID_ID3D12GraphicsCommandList5, WrapID3D12GraphicsCommandList},
{IID_ID3D12GraphicsCommandList6, WrapID3D12GraphicsCommandList},
{IID_ID3D10Blob, WrapID3D10Blob},
{IID_ID3DDestructionNotifier, WrapID3DDestructionNotifier},

};
GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
