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
** This file is generated from dx12_wrapper_creators_body_generator.py.
**
*/

#include "generated/generated_dx12_wrapper_creators.h"

#include "encode/dx12_object_wrapper_util.h"
#include "generated/generated_dx12_wrappers.h"
#include "util/defines.h"
#include "util/logging.h"

#include <cassert>
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

void WrapObject(REFIID riid, void** object)
{
    if ((object == nullptr) || (*object == nullptr))
    {
        return;
    }

    if (IsEqualIID(riid, IID_IDXGIKeyedMutex))
    {
        WrapIDXGIKeyedMutex(riid, reinterpret_cast<IDXGIKeyedMutex**>(object));
    }
    else if (IsEqualIID(riid, IID_IDXGIDisplayControl))
    {
        WrapIDXGIDisplayControl(riid, reinterpret_cast<IDXGIDisplayControl**>(object));
    }
    else if (IsEqualIID(riid, IID_IDXGIOutputDuplication))
    {
        WrapIDXGIOutputDuplication(riid, reinterpret_cast<IDXGIOutputDuplication**>(object));
    }
    else if (IsEqualIID(riid, IID_IDXGISurface) ||
             IsEqualIID(riid, IID_IDXGISurface1) ||
             IsEqualIID(riid, IID_IDXGISurface2))
    {
        WrapIDXGISurface(riid, reinterpret_cast<IDXGISurface**>(object));
    }
    else if (IsEqualIID(riid, IID_IDXGIResource) ||
             IsEqualIID(riid, IID_IDXGIResource1))
    {
        WrapIDXGIResource(riid, reinterpret_cast<IDXGIResource**>(object));
    }
    else if (IsEqualIID(riid, IID_IDXGIDecodeSwapChain))
    {
        WrapIDXGIDecodeSwapChain(riid, reinterpret_cast<IDXGIDecodeSwapChain**>(object));
    }
    else if (IsEqualIID(riid, IID_IDXGIFactoryMedia))
    {
        WrapIDXGIFactoryMedia(riid, reinterpret_cast<IDXGIFactoryMedia**>(object));
    }
    else if (IsEqualIID(riid, IID_IDXGISwapChainMedia))
    {
        WrapIDXGISwapChainMedia(riid, reinterpret_cast<IDXGISwapChainMedia**>(object));
    }
    else if (IsEqualIID(riid, IID_IDXGISwapChain) ||
             IsEqualIID(riid, IID_IDXGISwapChain1) ||
             IsEqualIID(riid, IID_IDXGISwapChain2) ||
             IsEqualIID(riid, IID_IDXGISwapChain3) ||
             IsEqualIID(riid, IID_IDXGISwapChain4))
    {
        WrapIDXGISwapChain(riid, reinterpret_cast<IDXGISwapChain**>(object));
    }
    else if (IsEqualIID(riid, IID_IDXGIDevice) ||
             IsEqualIID(riid, IID_IDXGIDevice1) ||
             IsEqualIID(riid, IID_IDXGIDevice2) ||
             IsEqualIID(riid, IID_IDXGIDevice3) ||
             IsEqualIID(riid, IID_IDXGIDevice4))
    {
        WrapIDXGIDevice(riid, reinterpret_cast<IDXGIDevice**>(object));
    }
    else if (IsEqualIID(riid, IID_IDXGIAdapter) ||
             IsEqualIID(riid, IID_IDXGIAdapter1) ||
             IsEqualIID(riid, IID_IDXGIAdapter2) ||
             IsEqualIID(riid, IID_IDXGIAdapter3) ||
             IsEqualIID(riid, IID_IDXGIAdapter4))
    {
        WrapIDXGIAdapter(riid, reinterpret_cast<IDXGIAdapter**>(object));
    }
    else if (IsEqualIID(riid, IID_IDXGIOutput) ||
             IsEqualIID(riid, IID_IDXGIOutput1) ||
             IsEqualIID(riid, IID_IDXGIOutput2) ||
             IsEqualIID(riid, IID_IDXGIOutput3) ||
             IsEqualIID(riid, IID_IDXGIOutput4) ||
             IsEqualIID(riid, IID_IDXGIOutput5) ||
             IsEqualIID(riid, IID_IDXGIOutput6))
    {
        WrapIDXGIOutput(riid, reinterpret_cast<IDXGIOutput**>(object));
    }
    else if (IsEqualIID(riid, IID_IDXGIFactory) ||
             IsEqualIID(riid, IID_IDXGIFactory1) ||
             IsEqualIID(riid, IID_IDXGIFactory2) ||
             IsEqualIID(riid, IID_IDXGIFactory3) ||
             IsEqualIID(riid, IID_IDXGIFactory4) ||
             IsEqualIID(riid, IID_IDXGIFactory5) ||
             IsEqualIID(riid, IID_IDXGIFactory6) ||
             IsEqualIID(riid, IID_IDXGIFactory7))
    {
        WrapIDXGIFactory(riid, reinterpret_cast<IDXGIFactory**>(object));
    }
    else if (IsEqualIID(riid, IID_ID3D12RootSignature))
    {
        WrapID3D12RootSignature(riid, reinterpret_cast<ID3D12RootSignature**>(object));
    }
    else if (IsEqualIID(riid, IID_ID3D12RootSignatureDeserializer))
    {
        WrapID3D12RootSignatureDeserializer(riid, reinterpret_cast<ID3D12RootSignatureDeserializer**>(object));
    }
    else if (IsEqualIID(riid, IID_ID3D12VersionedRootSignatureDeserializer))
    {
        WrapID3D12VersionedRootSignatureDeserializer(riid, reinterpret_cast<ID3D12VersionedRootSignatureDeserializer**>(object));
    }
    else if (IsEqualIID(riid, IID_ID3D12CommandAllocator))
    {
        WrapID3D12CommandAllocator(riid, reinterpret_cast<ID3D12CommandAllocator**>(object));
    }
    else if (IsEqualIID(riid, IID_ID3D12Fence) ||
             IsEqualIID(riid, IID_ID3D12Fence1))
    {
        WrapID3D12Fence(riid, reinterpret_cast<ID3D12Fence**>(object));
    }
    else if (IsEqualIID(riid, IID_ID3D12PipelineState))
    {
        WrapID3D12PipelineState(riid, reinterpret_cast<ID3D12PipelineState**>(object));
    }
    else if (IsEqualIID(riid, IID_ID3D12DescriptorHeap))
    {
        WrapID3D12DescriptorHeap(riid, reinterpret_cast<ID3D12DescriptorHeap**>(object));
    }
    else if (IsEqualIID(riid, IID_ID3D12QueryHeap))
    {
        WrapID3D12QueryHeap(riid, reinterpret_cast<ID3D12QueryHeap**>(object));
    }
    else if (IsEqualIID(riid, IID_ID3D12CommandSignature))
    {
        WrapID3D12CommandSignature(riid, reinterpret_cast<ID3D12CommandSignature**>(object));
    }
    else if (IsEqualIID(riid, IID_ID3D12CommandQueue))
    {
        WrapID3D12CommandQueue(riid, reinterpret_cast<ID3D12CommandQueue**>(object));
    }
    else if (IsEqualIID(riid, IID_ID3D12PipelineLibrary) ||
             IsEqualIID(riid, IID_ID3D12PipelineLibrary1))
    {
        WrapID3D12PipelineLibrary(riid, reinterpret_cast<ID3D12PipelineLibrary**>(object));
    }
    else if (IsEqualIID(riid, IID_ID3D12LifetimeOwner))
    {
        WrapID3D12LifetimeOwner(riid, reinterpret_cast<ID3D12LifetimeOwner**>(object));
    }
    else if (IsEqualIID(riid, IID_ID3D12SwapChainAssistant))
    {
        WrapID3D12SwapChainAssistant(riid, reinterpret_cast<ID3D12SwapChainAssistant**>(object));
    }
    else if (IsEqualIID(riid, IID_ID3D12LifetimeTracker))
    {
        WrapID3D12LifetimeTracker(riid, reinterpret_cast<ID3D12LifetimeTracker**>(object));
    }
    else if (IsEqualIID(riid, IID_ID3D12StateObject))
    {
        WrapID3D12StateObject(riid, reinterpret_cast<ID3D12StateObject**>(object));
    }
    else if (IsEqualIID(riid, IID_ID3D12StateObjectProperties))
    {
        WrapID3D12StateObjectProperties(riid, reinterpret_cast<ID3D12StateObjectProperties**>(object));
    }
    else if (IsEqualIID(riid, IID_ID3D12DeviceRemovedExtendedDataSettings) ||
             IsEqualIID(riid, IID_ID3D12DeviceRemovedExtendedDataSettings1))
    {
        WrapID3D12DeviceRemovedExtendedDataSettings(riid, reinterpret_cast<ID3D12DeviceRemovedExtendedDataSettings**>(object));
    }
    else if (IsEqualIID(riid, IID_ID3D12DeviceRemovedExtendedData) ||
             IsEqualIID(riid, IID_ID3D12DeviceRemovedExtendedData1))
    {
        WrapID3D12DeviceRemovedExtendedData(riid, reinterpret_cast<ID3D12DeviceRemovedExtendedData**>(object));
    }
    else if (IsEqualIID(riid, IID_ID3D12ProtectedResourceSession) ||
             IsEqualIID(riid, IID_ID3D12ProtectedResourceSession1))
    {
        WrapID3D12ProtectedResourceSession(riid, reinterpret_cast<ID3D12ProtectedResourceSession**>(object));
    }
    else if (IsEqualIID(riid, IID_ID3D12Device) ||
             IsEqualIID(riid, IID_ID3D12Device1) ||
             IsEqualIID(riid, IID_ID3D12Device2) ||
             IsEqualIID(riid, IID_ID3D12Device3) ||
             IsEqualIID(riid, IID_ID3D12Device4) ||
             IsEqualIID(riid, IID_ID3D12Device5) ||
             IsEqualIID(riid, IID_ID3D12Device6) ||
             IsEqualIID(riid, IID_ID3D12Device7) ||
             IsEqualIID(riid, IID_ID3D12Device8))
    {
        WrapID3D12Device(riid, reinterpret_cast<ID3D12Device**>(object));
    }
    else if (IsEqualIID(riid, IID_ID3D12Resource) ||
             IsEqualIID(riid, IID_ID3D12Resource1) ||
             IsEqualIID(riid, IID_ID3D12Resource2))
    {
        WrapID3D12Resource(riid, reinterpret_cast<ID3D12Resource**>(object));
    }
    else if (IsEqualIID(riid, IID_ID3D12Heap) ||
             IsEqualIID(riid, IID_ID3D12Heap1))
    {
        WrapID3D12Heap(riid, reinterpret_cast<ID3D12Heap**>(object));
    }
    else if (IsEqualIID(riid, IID_ID3D12MetaCommand))
    {
        WrapID3D12MetaCommand(riid, reinterpret_cast<ID3D12MetaCommand**>(object));
    }
    else if (IsEqualIID(riid, IID_ID3D12Tools))
    {
        WrapID3D12Tools(riid, reinterpret_cast<ID3D12Tools**>(object));
    }
    else if (IsEqualIID(riid, IID_ID3D12GraphicsCommandList) ||
             IsEqualIID(riid, IID_ID3D12GraphicsCommandList1) ||
             IsEqualIID(riid, IID_ID3D12GraphicsCommandList2) ||
             IsEqualIID(riid, IID_ID3D12GraphicsCommandList3) ||
             IsEqualIID(riid, IID_ID3D12GraphicsCommandList4) ||
             IsEqualIID(riid, IID_ID3D12GraphicsCommandList5) ||
             IsEqualIID(riid, IID_ID3D12GraphicsCommandList6))
    {
        WrapID3D12GraphicsCommandList(riid, reinterpret_cast<ID3D12GraphicsCommandList**>(object));
    }
    else if (IsEqualIID(riid, IID_ID3D10Blob))
    {
        WrapID3D10Blob(riid, reinterpret_cast<ID3D10Blob**>(object));
    }
    else if (IsEqualIID(riid, IID_ID3DDestructionNotifier))
    {
        WrapID3DDestructionNotifier(riid, reinterpret_cast<ID3DDestructionNotifier**>(object));
    }
}

void WrapIDXGIKeyedMutex(REFIID riid, IDXGIKeyedMutex** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_IDXGIKeyedMutex))
    {
        auto wrapper = new IDXGIKeyedMutex_Wrapper(static_cast<IDXGIKeyedMutex*>(*object));
        (*object) = reinterpret_cast<IDXGIKeyedMutex*>(wrapper);
        return;
    }
    else
    {
        IDXGIKeyedMutex* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIKeyedMutex_Wrapper(static_cast<IDXGIKeyedMutex*>(*object));
            (*object) = reinterpret_cast<IDXGIKeyedMutex*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported IDXGIKeyedMutex object type for capture");
}

void WrapIDXGIDisplayControl(REFIID riid, IDXGIDisplayControl** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_IDXGIDisplayControl))
    {
        auto wrapper = new IDXGIDisplayControl_Wrapper(static_cast<IDXGIDisplayControl*>(*object));
        (*object) = reinterpret_cast<IDXGIDisplayControl*>(wrapper);
        return;
    }
    else
    {
        IDXGIDisplayControl* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIDisplayControl_Wrapper(static_cast<IDXGIDisplayControl*>(*object));
            (*object) = reinterpret_cast<IDXGIDisplayControl*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported IDXGIDisplayControl object type for capture");
}

void WrapIDXGIOutputDuplication(REFIID riid, IDXGIOutputDuplication** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_IDXGIOutputDuplication))
    {
        auto wrapper = new IDXGIOutputDuplication_Wrapper(static_cast<IDXGIOutputDuplication*>(*object));
        (*object) = reinterpret_cast<IDXGIOutputDuplication*>(wrapper);
        return;
    }
    else
    {
        IDXGIOutputDuplication* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIOutputDuplication_Wrapper(static_cast<IDXGIOutputDuplication*>(*object));
            (*object) = reinterpret_cast<IDXGIOutputDuplication*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported IDXGIOutputDuplication object type for capture");
}

void WrapIDXGISurface(REFIID riid, IDXGISurface** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_IDXGISurface2))
    {
        auto wrapper = new IDXGISurface2_Wrapper(static_cast<IDXGISurface2*>(*object));
        (*object) = reinterpret_cast<IDXGISurface2*>(wrapper);
        return;
    }
    else
    {
        IDXGISurface2* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGISurface2_Wrapper(static_cast<IDXGISurface2*>(*object));
            (*object) = reinterpret_cast<IDXGISurface2*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_IDXGISurface1))
    {
        auto wrapper = new IDXGISurface1_Wrapper(static_cast<IDXGISurface1*>(*object));
        (*object) = reinterpret_cast<IDXGISurface1*>(wrapper);
        return;
    }
    else
    {
        IDXGISurface1* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGISurface1_Wrapper(static_cast<IDXGISurface1*>(*object));
            (*object) = reinterpret_cast<IDXGISurface1*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_IDXGISurface))
    {
        auto wrapper = new IDXGISurface_Wrapper(static_cast<IDXGISurface*>(*object));
        (*object) = reinterpret_cast<IDXGISurface*>(wrapper);
        return;
    }
    else
    {
        IDXGISurface* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGISurface_Wrapper(static_cast<IDXGISurface*>(*object));
            (*object) = reinterpret_cast<IDXGISurface*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported IDXGISurface object type for capture");
}

void WrapIDXGIResource(REFIID riid, IDXGIResource** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_IDXGIResource1))
    {
        auto wrapper = new IDXGIResource1_Wrapper(static_cast<IDXGIResource1*>(*object));
        (*object) = reinterpret_cast<IDXGIResource1*>(wrapper);
        return;
    }
    else
    {
        IDXGIResource1* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIResource1_Wrapper(static_cast<IDXGIResource1*>(*object));
            (*object) = reinterpret_cast<IDXGIResource1*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIResource))
    {
        auto wrapper = new IDXGIResource_Wrapper(static_cast<IDXGIResource*>(*object));
        (*object) = reinterpret_cast<IDXGIResource*>(wrapper);
        return;
    }
    else
    {
        IDXGIResource* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIResource_Wrapper(static_cast<IDXGIResource*>(*object));
            (*object) = reinterpret_cast<IDXGIResource*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported IDXGIResource object type for capture");
}

void WrapIDXGIDecodeSwapChain(REFIID riid, IDXGIDecodeSwapChain** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_IDXGIDecodeSwapChain))
    {
        auto wrapper = new IDXGIDecodeSwapChain_Wrapper(static_cast<IDXGIDecodeSwapChain*>(*object));
        (*object) = reinterpret_cast<IDXGIDecodeSwapChain*>(wrapper);
        return;
    }
    else
    {
        IDXGIDecodeSwapChain* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIDecodeSwapChain_Wrapper(static_cast<IDXGIDecodeSwapChain*>(*object));
            (*object) = reinterpret_cast<IDXGIDecodeSwapChain*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported IDXGIDecodeSwapChain object type for capture");
}

void WrapIDXGIFactoryMedia(REFIID riid, IDXGIFactoryMedia** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_IDXGIFactoryMedia))
    {
        auto wrapper = new IDXGIFactoryMedia_Wrapper(static_cast<IDXGIFactoryMedia*>(*object));
        (*object) = reinterpret_cast<IDXGIFactoryMedia*>(wrapper);
        return;
    }
    else
    {
        IDXGIFactoryMedia* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIFactoryMedia_Wrapper(static_cast<IDXGIFactoryMedia*>(*object));
            (*object) = reinterpret_cast<IDXGIFactoryMedia*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported IDXGIFactoryMedia object type for capture");
}

void WrapIDXGISwapChainMedia(REFIID riid, IDXGISwapChainMedia** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_IDXGISwapChainMedia))
    {
        auto wrapper = new IDXGISwapChainMedia_Wrapper(static_cast<IDXGISwapChainMedia*>(*object));
        (*object) = reinterpret_cast<IDXGISwapChainMedia*>(wrapper);
        return;
    }
    else
    {
        IDXGISwapChainMedia* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGISwapChainMedia_Wrapper(static_cast<IDXGISwapChainMedia*>(*object));
            (*object) = reinterpret_cast<IDXGISwapChainMedia*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported IDXGISwapChainMedia object type for capture");
}

void WrapIDXGISwapChain(REFIID riid, IDXGISwapChain** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_IDXGISwapChain4))
    {
        auto wrapper = new IDXGISwapChain4_Wrapper(static_cast<IDXGISwapChain4*>(*object));
        (*object) = reinterpret_cast<IDXGISwapChain4*>(wrapper);
        return;
    }
    else
    {
        IDXGISwapChain4* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGISwapChain4_Wrapper(static_cast<IDXGISwapChain4*>(*object));
            (*object) = reinterpret_cast<IDXGISwapChain4*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_IDXGISwapChain3))
    {
        auto wrapper = new IDXGISwapChain3_Wrapper(static_cast<IDXGISwapChain3*>(*object));
        (*object) = reinterpret_cast<IDXGISwapChain3*>(wrapper);
        return;
    }
    else
    {
        IDXGISwapChain3* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGISwapChain3_Wrapper(static_cast<IDXGISwapChain3*>(*object));
            (*object) = reinterpret_cast<IDXGISwapChain3*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_IDXGISwapChain2))
    {
        auto wrapper = new IDXGISwapChain2_Wrapper(static_cast<IDXGISwapChain2*>(*object));
        (*object) = reinterpret_cast<IDXGISwapChain2*>(wrapper);
        return;
    }
    else
    {
        IDXGISwapChain2* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGISwapChain2_Wrapper(static_cast<IDXGISwapChain2*>(*object));
            (*object) = reinterpret_cast<IDXGISwapChain2*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_IDXGISwapChain1))
    {
        auto wrapper = new IDXGISwapChain1_Wrapper(static_cast<IDXGISwapChain1*>(*object));
        (*object) = reinterpret_cast<IDXGISwapChain1*>(wrapper);
        return;
    }
    else
    {
        IDXGISwapChain1* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGISwapChain1_Wrapper(static_cast<IDXGISwapChain1*>(*object));
            (*object) = reinterpret_cast<IDXGISwapChain1*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_IDXGISwapChain))
    {
        auto wrapper = new IDXGISwapChain_Wrapper(static_cast<IDXGISwapChain*>(*object));
        (*object) = reinterpret_cast<IDXGISwapChain*>(wrapper);
        return;
    }
    else
    {
        IDXGISwapChain* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGISwapChain_Wrapper(static_cast<IDXGISwapChain*>(*object));
            (*object) = reinterpret_cast<IDXGISwapChain*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported IDXGISwapChain object type for capture");
}

void WrapIDXGIDevice(REFIID riid, IDXGIDevice** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_IDXGIDevice4))
    {
        auto wrapper = new IDXGIDevice4_Wrapper(static_cast<IDXGIDevice4*>(*object));
        (*object) = reinterpret_cast<IDXGIDevice4*>(wrapper);
        return;
    }
    else
    {
        IDXGIDevice4* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIDevice4_Wrapper(static_cast<IDXGIDevice4*>(*object));
            (*object) = reinterpret_cast<IDXGIDevice4*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIDevice3))
    {
        auto wrapper = new IDXGIDevice3_Wrapper(static_cast<IDXGIDevice3*>(*object));
        (*object) = reinterpret_cast<IDXGIDevice3*>(wrapper);
        return;
    }
    else
    {
        IDXGIDevice3* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIDevice3_Wrapper(static_cast<IDXGIDevice3*>(*object));
            (*object) = reinterpret_cast<IDXGIDevice3*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIDevice2))
    {
        auto wrapper = new IDXGIDevice2_Wrapper(static_cast<IDXGIDevice2*>(*object));
        (*object) = reinterpret_cast<IDXGIDevice2*>(wrapper);
        return;
    }
    else
    {
        IDXGIDevice2* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIDevice2_Wrapper(static_cast<IDXGIDevice2*>(*object));
            (*object) = reinterpret_cast<IDXGIDevice2*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIDevice1))
    {
        auto wrapper = new IDXGIDevice1_Wrapper(static_cast<IDXGIDevice1*>(*object));
        (*object) = reinterpret_cast<IDXGIDevice1*>(wrapper);
        return;
    }
    else
    {
        IDXGIDevice1* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIDevice1_Wrapper(static_cast<IDXGIDevice1*>(*object));
            (*object) = reinterpret_cast<IDXGIDevice1*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIDevice))
    {
        auto wrapper = new IDXGIDevice_Wrapper(static_cast<IDXGIDevice*>(*object));
        (*object) = reinterpret_cast<IDXGIDevice*>(wrapper);
        return;
    }
    else
    {
        IDXGIDevice* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIDevice_Wrapper(static_cast<IDXGIDevice*>(*object));
            (*object) = reinterpret_cast<IDXGIDevice*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported IDXGIDevice object type for capture");
}

void WrapIDXGIAdapter(REFIID riid, IDXGIAdapter** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_IDXGIAdapter4))
    {
        auto wrapper = new IDXGIAdapter4_Wrapper(static_cast<IDXGIAdapter4*>(*object));
        (*object) = reinterpret_cast<IDXGIAdapter4*>(wrapper);
        return;
    }
    else
    {
        IDXGIAdapter4* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIAdapter4_Wrapper(static_cast<IDXGIAdapter4*>(*object));
            (*object) = reinterpret_cast<IDXGIAdapter4*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIAdapter3))
    {
        auto wrapper = new IDXGIAdapter3_Wrapper(static_cast<IDXGIAdapter3*>(*object));
        (*object) = reinterpret_cast<IDXGIAdapter3*>(wrapper);
        return;
    }
    else
    {
        IDXGIAdapter3* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIAdapter3_Wrapper(static_cast<IDXGIAdapter3*>(*object));
            (*object) = reinterpret_cast<IDXGIAdapter3*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIAdapter2))
    {
        auto wrapper = new IDXGIAdapter2_Wrapper(static_cast<IDXGIAdapter2*>(*object));
        (*object) = reinterpret_cast<IDXGIAdapter2*>(wrapper);
        return;
    }
    else
    {
        IDXGIAdapter2* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIAdapter2_Wrapper(static_cast<IDXGIAdapter2*>(*object));
            (*object) = reinterpret_cast<IDXGIAdapter2*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIAdapter1))
    {
        auto wrapper = new IDXGIAdapter1_Wrapper(static_cast<IDXGIAdapter1*>(*object));
        (*object) = reinterpret_cast<IDXGIAdapter1*>(wrapper);
        return;
    }
    else
    {
        IDXGIAdapter1* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIAdapter1_Wrapper(static_cast<IDXGIAdapter1*>(*object));
            (*object) = reinterpret_cast<IDXGIAdapter1*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIAdapter))
    {
        auto wrapper = new IDXGIAdapter_Wrapper(static_cast<IDXGIAdapter*>(*object));
        (*object) = reinterpret_cast<IDXGIAdapter*>(wrapper);
        return;
    }
    else
    {
        IDXGIAdapter* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIAdapter_Wrapper(static_cast<IDXGIAdapter*>(*object));
            (*object) = reinterpret_cast<IDXGIAdapter*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported IDXGIAdapter object type for capture");
}

void WrapIDXGIOutput(REFIID riid, IDXGIOutput** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_IDXGIOutput6))
    {
        auto wrapper = new IDXGIOutput6_Wrapper(static_cast<IDXGIOutput6*>(*object));
        (*object) = reinterpret_cast<IDXGIOutput6*>(wrapper);
        return;
    }
    else
    {
        IDXGIOutput6* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIOutput6_Wrapper(static_cast<IDXGIOutput6*>(*object));
            (*object) = reinterpret_cast<IDXGIOutput6*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIOutput5))
    {
        auto wrapper = new IDXGIOutput5_Wrapper(static_cast<IDXGIOutput5*>(*object));
        (*object) = reinterpret_cast<IDXGIOutput5*>(wrapper);
        return;
    }
    else
    {
        IDXGIOutput5* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIOutput5_Wrapper(static_cast<IDXGIOutput5*>(*object));
            (*object) = reinterpret_cast<IDXGIOutput5*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIOutput4))
    {
        auto wrapper = new IDXGIOutput4_Wrapper(static_cast<IDXGIOutput4*>(*object));
        (*object) = reinterpret_cast<IDXGIOutput4*>(wrapper);
        return;
    }
    else
    {
        IDXGIOutput4* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIOutput4_Wrapper(static_cast<IDXGIOutput4*>(*object));
            (*object) = reinterpret_cast<IDXGIOutput4*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIOutput3))
    {
        auto wrapper = new IDXGIOutput3_Wrapper(static_cast<IDXGIOutput3*>(*object));
        (*object) = reinterpret_cast<IDXGIOutput3*>(wrapper);
        return;
    }
    else
    {
        IDXGIOutput3* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIOutput3_Wrapper(static_cast<IDXGIOutput3*>(*object));
            (*object) = reinterpret_cast<IDXGIOutput3*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIOutput2))
    {
        auto wrapper = new IDXGIOutput2_Wrapper(static_cast<IDXGIOutput2*>(*object));
        (*object) = reinterpret_cast<IDXGIOutput2*>(wrapper);
        return;
    }
    else
    {
        IDXGIOutput2* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIOutput2_Wrapper(static_cast<IDXGIOutput2*>(*object));
            (*object) = reinterpret_cast<IDXGIOutput2*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIOutput1))
    {
        auto wrapper = new IDXGIOutput1_Wrapper(static_cast<IDXGIOutput1*>(*object));
        (*object) = reinterpret_cast<IDXGIOutput1*>(wrapper);
        return;
    }
    else
    {
        IDXGIOutput1* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIOutput1_Wrapper(static_cast<IDXGIOutput1*>(*object));
            (*object) = reinterpret_cast<IDXGIOutput1*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIOutput))
    {
        auto wrapper = new IDXGIOutput_Wrapper(static_cast<IDXGIOutput*>(*object));
        (*object) = reinterpret_cast<IDXGIOutput*>(wrapper);
        return;
    }
    else
    {
        IDXGIOutput* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIOutput_Wrapper(static_cast<IDXGIOutput*>(*object));
            (*object) = reinterpret_cast<IDXGIOutput*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported IDXGIOutput object type for capture");
}

void WrapIDXGIFactory(REFIID riid, IDXGIFactory** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_IDXGIFactory7))
    {
        auto wrapper = new IDXGIFactory7_Wrapper(static_cast<IDXGIFactory7*>(*object));
        (*object) = reinterpret_cast<IDXGIFactory7*>(wrapper);
        return;
    }
    else
    {
        IDXGIFactory7* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIFactory7_Wrapper(static_cast<IDXGIFactory7*>(*object));
            (*object) = reinterpret_cast<IDXGIFactory7*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIFactory6))
    {
        auto wrapper = new IDXGIFactory6_Wrapper(static_cast<IDXGIFactory6*>(*object));
        (*object) = reinterpret_cast<IDXGIFactory6*>(wrapper);
        return;
    }
    else
    {
        IDXGIFactory6* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIFactory6_Wrapper(static_cast<IDXGIFactory6*>(*object));
            (*object) = reinterpret_cast<IDXGIFactory6*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIFactory5))
    {
        auto wrapper = new IDXGIFactory5_Wrapper(static_cast<IDXGIFactory5*>(*object));
        (*object) = reinterpret_cast<IDXGIFactory5*>(wrapper);
        return;
    }
    else
    {
        IDXGIFactory5* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIFactory5_Wrapper(static_cast<IDXGIFactory5*>(*object));
            (*object) = reinterpret_cast<IDXGIFactory5*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIFactory4))
    {
        auto wrapper = new IDXGIFactory4_Wrapper(static_cast<IDXGIFactory4*>(*object));
        (*object) = reinterpret_cast<IDXGIFactory4*>(wrapper);
        return;
    }
    else
    {
        IDXGIFactory4* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIFactory4_Wrapper(static_cast<IDXGIFactory4*>(*object));
            (*object) = reinterpret_cast<IDXGIFactory4*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIFactory3))
    {
        auto wrapper = new IDXGIFactory3_Wrapper(static_cast<IDXGIFactory3*>(*object));
        (*object) = reinterpret_cast<IDXGIFactory3*>(wrapper);
        return;
    }
    else
    {
        IDXGIFactory3* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIFactory3_Wrapper(static_cast<IDXGIFactory3*>(*object));
            (*object) = reinterpret_cast<IDXGIFactory3*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIFactory2))
    {
        auto wrapper = new IDXGIFactory2_Wrapper(static_cast<IDXGIFactory2*>(*object));
        (*object) = reinterpret_cast<IDXGIFactory2*>(wrapper);
        return;
    }
    else
    {
        IDXGIFactory2* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIFactory2_Wrapper(static_cast<IDXGIFactory2*>(*object));
            (*object) = reinterpret_cast<IDXGIFactory2*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIFactory1))
    {
        auto wrapper = new IDXGIFactory1_Wrapper(static_cast<IDXGIFactory1*>(*object));
        (*object) = reinterpret_cast<IDXGIFactory1*>(wrapper);
        return;
    }
    else
    {
        IDXGIFactory1* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIFactory1_Wrapper(static_cast<IDXGIFactory1*>(*object));
            (*object) = reinterpret_cast<IDXGIFactory1*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIFactory))
    {
        auto wrapper = new IDXGIFactory_Wrapper(static_cast<IDXGIFactory*>(*object));
        (*object) = reinterpret_cast<IDXGIFactory*>(wrapper);
        return;
    }
    else
    {
        IDXGIFactory* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIFactory_Wrapper(static_cast<IDXGIFactory*>(*object));
            (*object) = reinterpret_cast<IDXGIFactory*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported IDXGIFactory object type for capture");
}

void WrapID3D12RootSignature(REFIID riid, ID3D12RootSignature** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_ID3D12RootSignature))
    {
        auto wrapper = new ID3D12RootSignature_Wrapper(static_cast<ID3D12RootSignature*>(*object));
        (*object) = reinterpret_cast<ID3D12RootSignature*>(wrapper);
        return;
    }
    else
    {
        ID3D12RootSignature* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12RootSignature_Wrapper(static_cast<ID3D12RootSignature*>(*object));
            (*object) = reinterpret_cast<ID3D12RootSignature*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12RootSignature object type for capture");
}

void WrapID3D12RootSignatureDeserializer(REFIID riid, ID3D12RootSignatureDeserializer** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_ID3D12RootSignatureDeserializer))
    {
        auto wrapper = new ID3D12RootSignatureDeserializer_Wrapper(static_cast<ID3D12RootSignatureDeserializer*>(*object));
        (*object) = reinterpret_cast<ID3D12RootSignatureDeserializer*>(wrapper);
        return;
    }
    else
    {
        ID3D12RootSignatureDeserializer* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12RootSignatureDeserializer_Wrapper(static_cast<ID3D12RootSignatureDeserializer*>(*object));
            (*object) = reinterpret_cast<ID3D12RootSignatureDeserializer*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12RootSignatureDeserializer object type for capture");
}

void WrapID3D12VersionedRootSignatureDeserializer(REFIID riid, ID3D12VersionedRootSignatureDeserializer** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_ID3D12VersionedRootSignatureDeserializer))
    {
        auto wrapper = new ID3D12VersionedRootSignatureDeserializer_Wrapper(static_cast<ID3D12VersionedRootSignatureDeserializer*>(*object));
        (*object) = reinterpret_cast<ID3D12VersionedRootSignatureDeserializer*>(wrapper);
        return;
    }
    else
    {
        ID3D12VersionedRootSignatureDeserializer* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12VersionedRootSignatureDeserializer_Wrapper(static_cast<ID3D12VersionedRootSignatureDeserializer*>(*object));
            (*object) = reinterpret_cast<ID3D12VersionedRootSignatureDeserializer*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12VersionedRootSignatureDeserializer object type for capture");
}

void WrapID3D12CommandAllocator(REFIID riid, ID3D12CommandAllocator** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_ID3D12CommandAllocator))
    {
        auto wrapper = new ID3D12CommandAllocator_Wrapper(static_cast<ID3D12CommandAllocator*>(*object));
        (*object) = reinterpret_cast<ID3D12CommandAllocator*>(wrapper);
        return;
    }
    else
    {
        ID3D12CommandAllocator* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12CommandAllocator_Wrapper(static_cast<ID3D12CommandAllocator*>(*object));
            (*object) = reinterpret_cast<ID3D12CommandAllocator*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12CommandAllocator object type for capture");
}

void WrapID3D12Fence(REFIID riid, ID3D12Fence** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_ID3D12Fence1))
    {
        auto wrapper = new ID3D12Fence1_Wrapper(static_cast<ID3D12Fence1*>(*object));
        (*object) = reinterpret_cast<ID3D12Fence1*>(wrapper);
        return;
    }
    else
    {
        ID3D12Fence1* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Fence1_Wrapper(static_cast<ID3D12Fence1*>(*object));
            (*object) = reinterpret_cast<ID3D12Fence1*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12Fence))
    {
        auto wrapper = new ID3D12Fence_Wrapper(static_cast<ID3D12Fence*>(*object));
        (*object) = reinterpret_cast<ID3D12Fence*>(wrapper);
        return;
    }
    else
    {
        ID3D12Fence* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Fence_Wrapper(static_cast<ID3D12Fence*>(*object));
            (*object) = reinterpret_cast<ID3D12Fence*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12Fence object type for capture");
}

void WrapID3D12PipelineState(REFIID riid, ID3D12PipelineState** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_ID3D12PipelineState))
    {
        auto wrapper = new ID3D12PipelineState_Wrapper(static_cast<ID3D12PipelineState*>(*object));
        (*object) = reinterpret_cast<ID3D12PipelineState*>(wrapper);
        return;
    }
    else
    {
        ID3D12PipelineState* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12PipelineState_Wrapper(static_cast<ID3D12PipelineState*>(*object));
            (*object) = reinterpret_cast<ID3D12PipelineState*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12PipelineState object type for capture");
}

void WrapID3D12DescriptorHeap(REFIID riid, ID3D12DescriptorHeap** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_ID3D12DescriptorHeap))
    {
        auto wrapper = new ID3D12DescriptorHeap_Wrapper(static_cast<ID3D12DescriptorHeap*>(*object));
        (*object) = reinterpret_cast<ID3D12DescriptorHeap*>(wrapper);
        return;
    }
    else
    {
        ID3D12DescriptorHeap* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12DescriptorHeap_Wrapper(static_cast<ID3D12DescriptorHeap*>(*object));
            (*object) = reinterpret_cast<ID3D12DescriptorHeap*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12DescriptorHeap object type for capture");
}

void WrapID3D12QueryHeap(REFIID riid, ID3D12QueryHeap** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_ID3D12QueryHeap))
    {
        auto wrapper = new ID3D12QueryHeap_Wrapper(static_cast<ID3D12QueryHeap*>(*object));
        (*object) = reinterpret_cast<ID3D12QueryHeap*>(wrapper);
        return;
    }
    else
    {
        ID3D12QueryHeap* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12QueryHeap_Wrapper(static_cast<ID3D12QueryHeap*>(*object));
            (*object) = reinterpret_cast<ID3D12QueryHeap*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12QueryHeap object type for capture");
}

void WrapID3D12CommandSignature(REFIID riid, ID3D12CommandSignature** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_ID3D12CommandSignature))
    {
        auto wrapper = new ID3D12CommandSignature_Wrapper(static_cast<ID3D12CommandSignature*>(*object));
        (*object) = reinterpret_cast<ID3D12CommandSignature*>(wrapper);
        return;
    }
    else
    {
        ID3D12CommandSignature* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12CommandSignature_Wrapper(static_cast<ID3D12CommandSignature*>(*object));
            (*object) = reinterpret_cast<ID3D12CommandSignature*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12CommandSignature object type for capture");
}

void WrapID3D12CommandQueue(REFIID riid, ID3D12CommandQueue** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_ID3D12CommandQueue))
    {
        auto wrapper = new ID3D12CommandQueue_Wrapper(static_cast<ID3D12CommandQueue*>(*object));
        (*object) = reinterpret_cast<ID3D12CommandQueue*>(wrapper);
        return;
    }
    else
    {
        ID3D12CommandQueue* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12CommandQueue_Wrapper(static_cast<ID3D12CommandQueue*>(*object));
            (*object) = reinterpret_cast<ID3D12CommandQueue*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12CommandQueue object type for capture");
}

void WrapID3D12PipelineLibrary(REFIID riid, ID3D12PipelineLibrary** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_ID3D12PipelineLibrary1))
    {
        auto wrapper = new ID3D12PipelineLibrary1_Wrapper(static_cast<ID3D12PipelineLibrary1*>(*object));
        (*object) = reinterpret_cast<ID3D12PipelineLibrary1*>(wrapper);
        return;
    }
    else
    {
        ID3D12PipelineLibrary1* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12PipelineLibrary1_Wrapper(static_cast<ID3D12PipelineLibrary1*>(*object));
            (*object) = reinterpret_cast<ID3D12PipelineLibrary1*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12PipelineLibrary))
    {
        auto wrapper = new ID3D12PipelineLibrary_Wrapper(static_cast<ID3D12PipelineLibrary*>(*object));
        (*object) = reinterpret_cast<ID3D12PipelineLibrary*>(wrapper);
        return;
    }
    else
    {
        ID3D12PipelineLibrary* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12PipelineLibrary_Wrapper(static_cast<ID3D12PipelineLibrary*>(*object));
            (*object) = reinterpret_cast<ID3D12PipelineLibrary*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12PipelineLibrary object type for capture");
}

void WrapID3D12LifetimeOwner(REFIID riid, ID3D12LifetimeOwner** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_ID3D12LifetimeOwner))
    {
        auto wrapper = new ID3D12LifetimeOwner_Wrapper(static_cast<ID3D12LifetimeOwner*>(*object));
        (*object) = reinterpret_cast<ID3D12LifetimeOwner*>(wrapper);
        return;
    }
    else
    {
        ID3D12LifetimeOwner* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12LifetimeOwner_Wrapper(static_cast<ID3D12LifetimeOwner*>(*object));
            (*object) = reinterpret_cast<ID3D12LifetimeOwner*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12LifetimeOwner object type for capture");
}

void WrapID3D12SwapChainAssistant(REFIID riid, ID3D12SwapChainAssistant** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_ID3D12SwapChainAssistant))
    {
        auto wrapper = new ID3D12SwapChainAssistant_Wrapper(static_cast<ID3D12SwapChainAssistant*>(*object));
        (*object) = reinterpret_cast<ID3D12SwapChainAssistant*>(wrapper);
        return;
    }
    else
    {
        ID3D12SwapChainAssistant* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12SwapChainAssistant_Wrapper(static_cast<ID3D12SwapChainAssistant*>(*object));
            (*object) = reinterpret_cast<ID3D12SwapChainAssistant*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12SwapChainAssistant object type for capture");
}

void WrapID3D12LifetimeTracker(REFIID riid, ID3D12LifetimeTracker** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_ID3D12LifetimeTracker))
    {
        auto wrapper = new ID3D12LifetimeTracker_Wrapper(static_cast<ID3D12LifetimeTracker*>(*object));
        (*object) = reinterpret_cast<ID3D12LifetimeTracker*>(wrapper);
        return;
    }
    else
    {
        ID3D12LifetimeTracker* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12LifetimeTracker_Wrapper(static_cast<ID3D12LifetimeTracker*>(*object));
            (*object) = reinterpret_cast<ID3D12LifetimeTracker*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12LifetimeTracker object type for capture");
}

void WrapID3D12StateObject(REFIID riid, ID3D12StateObject** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_ID3D12StateObject))
    {
        auto wrapper = new ID3D12StateObject_Wrapper(static_cast<ID3D12StateObject*>(*object));
        (*object) = reinterpret_cast<ID3D12StateObject*>(wrapper);
        return;
    }
    else
    {
        ID3D12StateObject* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12StateObject_Wrapper(static_cast<ID3D12StateObject*>(*object));
            (*object) = reinterpret_cast<ID3D12StateObject*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12StateObject object type for capture");
}

void WrapID3D12StateObjectProperties(REFIID riid, ID3D12StateObjectProperties** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_ID3D12StateObjectProperties))
    {
        auto wrapper = new ID3D12StateObjectProperties_Wrapper(static_cast<ID3D12StateObjectProperties*>(*object));
        (*object) = reinterpret_cast<ID3D12StateObjectProperties*>(wrapper);
        return;
    }
    else
    {
        ID3D12StateObjectProperties* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12StateObjectProperties_Wrapper(static_cast<ID3D12StateObjectProperties*>(*object));
            (*object) = reinterpret_cast<ID3D12StateObjectProperties*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12StateObjectProperties object type for capture");
}

void WrapID3D12DeviceRemovedExtendedDataSettings(REFIID riid, ID3D12DeviceRemovedExtendedDataSettings** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_ID3D12DeviceRemovedExtendedDataSettings1))
    {
        auto wrapper = new ID3D12DeviceRemovedExtendedDataSettings1_Wrapper(static_cast<ID3D12DeviceRemovedExtendedDataSettings1*>(*object));
        (*object) = reinterpret_cast<ID3D12DeviceRemovedExtendedDataSettings1*>(wrapper);
        return;
    }
    else
    {
        ID3D12DeviceRemovedExtendedDataSettings1* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12DeviceRemovedExtendedDataSettings1_Wrapper(static_cast<ID3D12DeviceRemovedExtendedDataSettings1*>(*object));
            (*object) = reinterpret_cast<ID3D12DeviceRemovedExtendedDataSettings1*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12DeviceRemovedExtendedDataSettings))
    {
        auto wrapper = new ID3D12DeviceRemovedExtendedDataSettings_Wrapper(static_cast<ID3D12DeviceRemovedExtendedDataSettings*>(*object));
        (*object) = reinterpret_cast<ID3D12DeviceRemovedExtendedDataSettings*>(wrapper);
        return;
    }
    else
    {
        ID3D12DeviceRemovedExtendedDataSettings* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12DeviceRemovedExtendedDataSettings_Wrapper(static_cast<ID3D12DeviceRemovedExtendedDataSettings*>(*object));
            (*object) = reinterpret_cast<ID3D12DeviceRemovedExtendedDataSettings*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12DeviceRemovedExtendedDataSettings object type for capture");
}

void WrapID3D12DeviceRemovedExtendedData(REFIID riid, ID3D12DeviceRemovedExtendedData** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_ID3D12DeviceRemovedExtendedData1))
    {
        auto wrapper = new ID3D12DeviceRemovedExtendedData1_Wrapper(static_cast<ID3D12DeviceRemovedExtendedData1*>(*object));
        (*object) = reinterpret_cast<ID3D12DeviceRemovedExtendedData1*>(wrapper);
        return;
    }
    else
    {
        ID3D12DeviceRemovedExtendedData1* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12DeviceRemovedExtendedData1_Wrapper(static_cast<ID3D12DeviceRemovedExtendedData1*>(*object));
            (*object) = reinterpret_cast<ID3D12DeviceRemovedExtendedData1*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12DeviceRemovedExtendedData))
    {
        auto wrapper = new ID3D12DeviceRemovedExtendedData_Wrapper(static_cast<ID3D12DeviceRemovedExtendedData*>(*object));
        (*object) = reinterpret_cast<ID3D12DeviceRemovedExtendedData*>(wrapper);
        return;
    }
    else
    {
        ID3D12DeviceRemovedExtendedData* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12DeviceRemovedExtendedData_Wrapper(static_cast<ID3D12DeviceRemovedExtendedData*>(*object));
            (*object) = reinterpret_cast<ID3D12DeviceRemovedExtendedData*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12DeviceRemovedExtendedData object type for capture");
}

void WrapID3D12ProtectedResourceSession(REFIID riid, ID3D12ProtectedResourceSession** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_ID3D12ProtectedResourceSession1))
    {
        auto wrapper = new ID3D12ProtectedResourceSession1_Wrapper(static_cast<ID3D12ProtectedResourceSession1*>(*object));
        (*object) = reinterpret_cast<ID3D12ProtectedResourceSession1*>(wrapper);
        return;
    }
    else
    {
        ID3D12ProtectedResourceSession1* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12ProtectedResourceSession1_Wrapper(static_cast<ID3D12ProtectedResourceSession1*>(*object));
            (*object) = reinterpret_cast<ID3D12ProtectedResourceSession1*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12ProtectedResourceSession))
    {
        auto wrapper = new ID3D12ProtectedResourceSession_Wrapper(static_cast<ID3D12ProtectedResourceSession*>(*object));
        (*object) = reinterpret_cast<ID3D12ProtectedResourceSession*>(wrapper);
        return;
    }
    else
    {
        ID3D12ProtectedResourceSession* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12ProtectedResourceSession_Wrapper(static_cast<ID3D12ProtectedResourceSession*>(*object));
            (*object) = reinterpret_cast<ID3D12ProtectedResourceSession*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12ProtectedResourceSession object type for capture");
}

void WrapID3D12Device(REFIID riid, ID3D12Device** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_ID3D12Device8))
    {
        auto wrapper = new ID3D12Device8_Wrapper(static_cast<ID3D12Device8*>(*object));
        (*object) = reinterpret_cast<ID3D12Device8*>(wrapper);
        return;
    }
    else
    {
        ID3D12Device8* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Device8_Wrapper(static_cast<ID3D12Device8*>(*object));
            (*object) = reinterpret_cast<ID3D12Device8*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12Device7))
    {
        auto wrapper = new ID3D12Device7_Wrapper(static_cast<ID3D12Device7*>(*object));
        (*object) = reinterpret_cast<ID3D12Device7*>(wrapper);
        return;
    }
    else
    {
        ID3D12Device7* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Device7_Wrapper(static_cast<ID3D12Device7*>(*object));
            (*object) = reinterpret_cast<ID3D12Device7*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12Device6))
    {
        auto wrapper = new ID3D12Device6_Wrapper(static_cast<ID3D12Device6*>(*object));
        (*object) = reinterpret_cast<ID3D12Device6*>(wrapper);
        return;
    }
    else
    {
        ID3D12Device6* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Device6_Wrapper(static_cast<ID3D12Device6*>(*object));
            (*object) = reinterpret_cast<ID3D12Device6*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12Device5))
    {
        auto wrapper = new ID3D12Device5_Wrapper(static_cast<ID3D12Device5*>(*object));
        (*object) = reinterpret_cast<ID3D12Device5*>(wrapper);
        return;
    }
    else
    {
        ID3D12Device5* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Device5_Wrapper(static_cast<ID3D12Device5*>(*object));
            (*object) = reinterpret_cast<ID3D12Device5*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12Device4))
    {
        auto wrapper = new ID3D12Device4_Wrapper(static_cast<ID3D12Device4*>(*object));
        (*object) = reinterpret_cast<ID3D12Device4*>(wrapper);
        return;
    }
    else
    {
        ID3D12Device4* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Device4_Wrapper(static_cast<ID3D12Device4*>(*object));
            (*object) = reinterpret_cast<ID3D12Device4*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12Device3))
    {
        auto wrapper = new ID3D12Device3_Wrapper(static_cast<ID3D12Device3*>(*object));
        (*object) = reinterpret_cast<ID3D12Device3*>(wrapper);
        return;
    }
    else
    {
        ID3D12Device3* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Device3_Wrapper(static_cast<ID3D12Device3*>(*object));
            (*object) = reinterpret_cast<ID3D12Device3*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12Device2))
    {
        auto wrapper = new ID3D12Device2_Wrapper(static_cast<ID3D12Device2*>(*object));
        (*object) = reinterpret_cast<ID3D12Device2*>(wrapper);
        return;
    }
    else
    {
        ID3D12Device2* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Device2_Wrapper(static_cast<ID3D12Device2*>(*object));
            (*object) = reinterpret_cast<ID3D12Device2*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12Device1))
    {
        auto wrapper = new ID3D12Device1_Wrapper(static_cast<ID3D12Device1*>(*object));
        (*object) = reinterpret_cast<ID3D12Device1*>(wrapper);
        return;
    }
    else
    {
        ID3D12Device1* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Device1_Wrapper(static_cast<ID3D12Device1*>(*object));
            (*object) = reinterpret_cast<ID3D12Device1*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12Device))
    {
        auto wrapper = new ID3D12Device_Wrapper(static_cast<ID3D12Device*>(*object));
        (*object) = reinterpret_cast<ID3D12Device*>(wrapper);
        return;
    }
    else
    {
        ID3D12Device* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Device_Wrapper(static_cast<ID3D12Device*>(*object));
            (*object) = reinterpret_cast<ID3D12Device*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12Device object type for capture");
}

void WrapID3D12Resource(REFIID riid, ID3D12Resource** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_ID3D12Resource2))
    {
        auto wrapper = new ID3D12Resource2_Wrapper(static_cast<ID3D12Resource2*>(*object));
        (*object) = reinterpret_cast<ID3D12Resource2*>(wrapper);
        return;
    }
    else
    {
        ID3D12Resource2* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Resource2_Wrapper(static_cast<ID3D12Resource2*>(*object));
            (*object) = reinterpret_cast<ID3D12Resource2*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12Resource1))
    {
        auto wrapper = new ID3D12Resource1_Wrapper(static_cast<ID3D12Resource1*>(*object));
        (*object) = reinterpret_cast<ID3D12Resource1*>(wrapper);
        return;
    }
    else
    {
        ID3D12Resource1* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Resource1_Wrapper(static_cast<ID3D12Resource1*>(*object));
            (*object) = reinterpret_cast<ID3D12Resource1*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12Resource))
    {
        auto wrapper = new ID3D12Resource_Wrapper(static_cast<ID3D12Resource*>(*object));
        (*object) = reinterpret_cast<ID3D12Resource*>(wrapper);
        return;
    }
    else
    {
        ID3D12Resource* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Resource_Wrapper(static_cast<ID3D12Resource*>(*object));
            (*object) = reinterpret_cast<ID3D12Resource*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12Resource object type for capture");
}

void WrapID3D12Heap(REFIID riid, ID3D12Heap** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_ID3D12Heap1))
    {
        auto wrapper = new ID3D12Heap1_Wrapper(static_cast<ID3D12Heap1*>(*object));
        (*object) = reinterpret_cast<ID3D12Heap1*>(wrapper);
        return;
    }
    else
    {
        ID3D12Heap1* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Heap1_Wrapper(static_cast<ID3D12Heap1*>(*object));
            (*object) = reinterpret_cast<ID3D12Heap1*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12Heap))
    {
        auto wrapper = new ID3D12Heap_Wrapper(static_cast<ID3D12Heap*>(*object));
        (*object) = reinterpret_cast<ID3D12Heap*>(wrapper);
        return;
    }
    else
    {
        ID3D12Heap* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Heap_Wrapper(static_cast<ID3D12Heap*>(*object));
            (*object) = reinterpret_cast<ID3D12Heap*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12Heap object type for capture");
}

void WrapID3D12MetaCommand(REFIID riid, ID3D12MetaCommand** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_ID3D12MetaCommand))
    {
        auto wrapper = new ID3D12MetaCommand_Wrapper(static_cast<ID3D12MetaCommand*>(*object));
        (*object) = reinterpret_cast<ID3D12MetaCommand*>(wrapper);
        return;
    }
    else
    {
        ID3D12MetaCommand* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12MetaCommand_Wrapper(static_cast<ID3D12MetaCommand*>(*object));
            (*object) = reinterpret_cast<ID3D12MetaCommand*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12MetaCommand object type for capture");
}

void WrapID3D12Tools(REFIID riid, ID3D12Tools** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_ID3D12Tools))
    {
        auto wrapper = new ID3D12Tools_Wrapper(static_cast<ID3D12Tools*>(*object));
        (*object) = reinterpret_cast<ID3D12Tools*>(wrapper);
        return;
    }
    else
    {
        ID3D12Tools* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Tools_Wrapper(static_cast<ID3D12Tools*>(*object));
            (*object) = reinterpret_cast<ID3D12Tools*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12Tools object type for capture");
}

void WrapID3D12GraphicsCommandList(REFIID riid, ID3D12GraphicsCommandList** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_ID3D12GraphicsCommandList6))
    {
        auto wrapper = new ID3D12GraphicsCommandList6_Wrapper(static_cast<ID3D12GraphicsCommandList6*>(*object));
        (*object) = reinterpret_cast<ID3D12GraphicsCommandList6*>(wrapper);
        return;
    }
    else
    {
        ID3D12GraphicsCommandList6* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12GraphicsCommandList6_Wrapper(static_cast<ID3D12GraphicsCommandList6*>(*object));
            (*object) = reinterpret_cast<ID3D12GraphicsCommandList6*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12GraphicsCommandList5))
    {
        auto wrapper = new ID3D12GraphicsCommandList5_Wrapper(static_cast<ID3D12GraphicsCommandList5*>(*object));
        (*object) = reinterpret_cast<ID3D12GraphicsCommandList5*>(wrapper);
        return;
    }
    else
    {
        ID3D12GraphicsCommandList5* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12GraphicsCommandList5_Wrapper(static_cast<ID3D12GraphicsCommandList5*>(*object));
            (*object) = reinterpret_cast<ID3D12GraphicsCommandList5*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12GraphicsCommandList4))
    {
        auto wrapper = new ID3D12GraphicsCommandList4_Wrapper(static_cast<ID3D12GraphicsCommandList4*>(*object));
        (*object) = reinterpret_cast<ID3D12GraphicsCommandList4*>(wrapper);
        return;
    }
    else
    {
        ID3D12GraphicsCommandList4* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12GraphicsCommandList4_Wrapper(static_cast<ID3D12GraphicsCommandList4*>(*object));
            (*object) = reinterpret_cast<ID3D12GraphicsCommandList4*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12GraphicsCommandList3))
    {
        auto wrapper = new ID3D12GraphicsCommandList3_Wrapper(static_cast<ID3D12GraphicsCommandList3*>(*object));
        (*object) = reinterpret_cast<ID3D12GraphicsCommandList3*>(wrapper);
        return;
    }
    else
    {
        ID3D12GraphicsCommandList3* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12GraphicsCommandList3_Wrapper(static_cast<ID3D12GraphicsCommandList3*>(*object));
            (*object) = reinterpret_cast<ID3D12GraphicsCommandList3*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12GraphicsCommandList2))
    {
        auto wrapper = new ID3D12GraphicsCommandList2_Wrapper(static_cast<ID3D12GraphicsCommandList2*>(*object));
        (*object) = reinterpret_cast<ID3D12GraphicsCommandList2*>(wrapper);
        return;
    }
    else
    {
        ID3D12GraphicsCommandList2* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12GraphicsCommandList2_Wrapper(static_cast<ID3D12GraphicsCommandList2*>(*object));
            (*object) = reinterpret_cast<ID3D12GraphicsCommandList2*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12GraphicsCommandList1))
    {
        auto wrapper = new ID3D12GraphicsCommandList1_Wrapper(static_cast<ID3D12GraphicsCommandList1*>(*object));
        (*object) = reinterpret_cast<ID3D12GraphicsCommandList1*>(wrapper);
        return;
    }
    else
    {
        ID3D12GraphicsCommandList1* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12GraphicsCommandList1_Wrapper(static_cast<ID3D12GraphicsCommandList1*>(*object));
            (*object) = reinterpret_cast<ID3D12GraphicsCommandList1*>(wrapper);
            return;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12GraphicsCommandList))
    {
        auto wrapper = new ID3D12GraphicsCommandList_Wrapper(static_cast<ID3D12GraphicsCommandList*>(*object));
        (*object) = reinterpret_cast<ID3D12GraphicsCommandList*>(wrapper);
        return;
    }
    else
    {
        ID3D12GraphicsCommandList* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12GraphicsCommandList_Wrapper(static_cast<ID3D12GraphicsCommandList*>(*object));
            (*object) = reinterpret_cast<ID3D12GraphicsCommandList*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12GraphicsCommandList object type for capture");
}

void WrapID3D10Blob(REFIID riid, ID3D10Blob** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_ID3D10Blob))
    {
        auto wrapper = new ID3D10Blob_Wrapper(static_cast<ID3D10Blob*>(*object));
        (*object) = reinterpret_cast<ID3D10Blob*>(wrapper);
        return;
    }
    else
    {
        ID3D10Blob* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D10Blob_Wrapper(static_cast<ID3D10Blob*>(*object));
            (*object) = reinterpret_cast<ID3D10Blob*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D10Blob object type for capture");
}

void WrapID3DDestructionNotifier(REFIID riid, ID3DDestructionNotifier** object)
{
    assert((object != nullptr) && (*object != nullptr));

    if (IsEqualIID(riid, IID_ID3DDestructionNotifier))
    {
        auto wrapper = new ID3DDestructionNotifier_Wrapper(static_cast<ID3DDestructionNotifier*>(*object));
        (*object) = reinterpret_cast<ID3DDestructionNotifier*>(wrapper);
        return;
    }
    else
    {
        ID3DDestructionNotifier* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3DDestructionNotifier_Wrapper(static_cast<ID3DDestructionNotifier*>(*object));
            (*object) = reinterpret_cast<ID3DDestructionNotifier*>(wrapper);
            return;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3DDestructionNotifier object type for capture");
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
