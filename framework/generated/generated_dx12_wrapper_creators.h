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

#include "util/defines.h"

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

void WrapObject(REFIID riid, void** object);

void WrapIDXGIKeyedMutex(REFIID riid, IDXGIKeyedMutex** object);

void WrapIDXGIDisplayControl(REFIID riid, IDXGIDisplayControl** object);

void WrapIDXGIOutputDuplication(REFIID riid, IDXGIOutputDuplication** object);

void WrapIDXGISurface(REFIID riid, IDXGISurface** object);

void WrapIDXGIResource(REFIID riid, IDXGIResource** object);

void WrapIDXGIDecodeSwapChain(REFIID riid, IDXGIDecodeSwapChain** object);

void WrapIDXGIFactoryMedia(REFIID riid, IDXGIFactoryMedia** object);

void WrapIDXGISwapChainMedia(REFIID riid, IDXGISwapChainMedia** object);

void WrapIDXGISwapChain(REFIID riid, IDXGISwapChain** object);

void WrapIDXGIDevice(REFIID riid, IDXGIDevice** object);

void WrapIDXGIAdapter(REFIID riid, IDXGIAdapter** object);

void WrapIDXGIOutput(REFIID riid, IDXGIOutput** object);

void WrapIDXGIFactory(REFIID riid, IDXGIFactory** object);

void WrapID3D12RootSignature(REFIID riid, ID3D12RootSignature** object);

void WrapID3D12RootSignatureDeserializer(REFIID riid, ID3D12RootSignatureDeserializer** object);

void WrapID3D12VersionedRootSignatureDeserializer(REFIID riid, ID3D12VersionedRootSignatureDeserializer** object);

void WrapID3D12CommandAllocator(REFIID riid, ID3D12CommandAllocator** object);

void WrapID3D12Fence(REFIID riid, ID3D12Fence** object);

void WrapID3D12PipelineState(REFIID riid, ID3D12PipelineState** object);

void WrapID3D12DescriptorHeap(REFIID riid, ID3D12DescriptorHeap** object);

void WrapID3D12QueryHeap(REFIID riid, ID3D12QueryHeap** object);

void WrapID3D12CommandSignature(REFIID riid, ID3D12CommandSignature** object);

void WrapID3D12CommandQueue(REFIID riid, ID3D12CommandQueue** object);

void WrapID3D12PipelineLibrary(REFIID riid, ID3D12PipelineLibrary** object);

void WrapID3D12LifetimeOwner(REFIID riid, ID3D12LifetimeOwner** object);

void WrapID3D12SwapChainAssistant(REFIID riid, ID3D12SwapChainAssistant** object);

void WrapID3D12LifetimeTracker(REFIID riid, ID3D12LifetimeTracker** object);

void WrapID3D12StateObject(REFIID riid, ID3D12StateObject** object);

void WrapID3D12StateObjectProperties(REFIID riid, ID3D12StateObjectProperties** object);

void WrapID3D12DeviceRemovedExtendedDataSettings(REFIID riid, ID3D12DeviceRemovedExtendedDataSettings** object);

void WrapID3D12DeviceRemovedExtendedData(REFIID riid, ID3D12DeviceRemovedExtendedData** object);

void WrapID3D12ProtectedResourceSession(REFIID riid, ID3D12ProtectedResourceSession** object);

void WrapID3D12Device(REFIID riid, ID3D12Device** object);

void WrapID3D12Resource(REFIID riid, ID3D12Resource** object);

void WrapID3D12Heap(REFIID riid, ID3D12Heap** object);

void WrapID3D12MetaCommand(REFIID riid, ID3D12MetaCommand** object);

void WrapID3D12Tools(REFIID riid, ID3D12Tools** object);

void WrapID3D12GraphicsCommandList(REFIID riid, ID3D12GraphicsCommandList** object);

void WrapID3D10Blob(REFIID riid, ID3D10Blob** object);

void WrapID3DDestructionNotifier(REFIID riid, ID3DDestructionNotifier** object);

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
