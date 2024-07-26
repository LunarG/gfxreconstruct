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
** This file is generated from dx12_wrapper_creators_body_generator.py.
**
*/

#include "generated/generated_dx12_wrapper_creators.h"

#include "encode/dx12_object_wrapper_util.h"
#include "generated/generated_dx12_wrappers.h"
#include "util/defines.h"
#include "util/logging.h"

#include <cassert>
#include <dxgiformat.h>
#include <d3d12.h>
#include <d3dcommon.h>
#include <d3d12sdklayers.h>
#include <d3d11.h>
#include <d3d11_1.h>
#include <d3d11_2.h>
#include <dxgi.h>
#include <dxgi1_2.h>
#include <dxgi1_3.h>
#include <dxgi1_4.h>
#include <dxgi1_5.h>
#include <dxgi1_6.h>
#include <dxgicommon.h>
#include <dxgitype.h>
#include <Unknwnbase.h>
#include <guiddef.h>
#include <windef.h>
#include <minwinbase.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void WrapObject(REFIID riid, void** object, DxWrapperResources* resources)
{
    if ((object != nullptr) && (*object != nullptr))
    {
        auto it = kFunctionTable.find(riid);
        if (it != kFunctionTable.end())
        {
            it->second(riid,object,resources);
        }
        else
        {
            GFXRECON_LOG_DEBUG("An object with an unknown IID {%08x-%04hx-%04hx-%02hhx%02hhx-%02hhx%02hhx%02hhx%02hhx%02hhx%02hhx} was created. GFXReconstruct cannot track the object and may produce an invalid capture",\
                                riid.Data1, riid.Data2, riid.Data3, riid.Data4[0], riid.Data4[1], riid.Data4[2], riid.Data4[3], riid.Data4[4], riid.Data4[5], riid.Data4[6], riid.Data4[7]);
        }
    }
}

void WrapObjectArray(REFIID riid, void** object, UINT num_object, DxWrapperResources* resources)
{
    for (UINT i = 0; i < num_object; i++)
    {
        WrapObject(riid, &object[i], resources);
    }
}

void WrapID3D12RootSignature(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12RootSignature_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12RootSignature_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12RootSignatureDeserializer(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12RootSignatureDeserializer_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12RootSignatureDeserializer_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12VersionedRootSignatureDeserializer(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12VersionedRootSignatureDeserializer_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12VersionedRootSignatureDeserializer_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12CommandAllocator(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12CommandAllocator_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12CommandAllocator_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12Fence(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12Fence_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12Fence1_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12PipelineState(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12PipelineState_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12PipelineState_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12DescriptorHeap(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12DescriptorHeap_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12DescriptorHeap_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12QueryHeap(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12QueryHeap_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12QueryHeap_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12CommandSignature(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12CommandSignature_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12CommandSignature_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12CommandQueue(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12CommandQueue_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12CommandQueue_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12PipelineLibrary(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12PipelineLibrary_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12PipelineLibrary1_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12LifetimeOwner(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12LifetimeOwner_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12LifetimeOwner_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12SwapChainAssistant(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12SwapChainAssistant_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12SwapChainAssistant_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12LifetimeTracker(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12LifetimeTracker_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12LifetimeTracker_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12StateObject(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12StateObject_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12StateObject_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12StateObjectProperties(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12StateObjectProperties_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12StateObjectProperties1_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12WorkGraphProperties(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12WorkGraphProperties_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12WorkGraphProperties_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12DeviceRemovedExtendedDataSettings(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12DeviceRemovedExtendedDataSettings_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12DeviceRemovedExtendedDataSettings2_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12DeviceRemovedExtendedData(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12DeviceRemovedExtendedData_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12DeviceRemovedExtendedData2_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12ProtectedResourceSession(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12ProtectedResourceSession_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12ProtectedResourceSession1_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12Resource(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12Resource_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12Resource2_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12Heap(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12Heap_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12Heap1_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12MetaCommand(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12MetaCommand_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12MetaCommand_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12ShaderCacheSession(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12ShaderCacheSession_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12ShaderCacheSession_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12Device(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12Device_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12Device14_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12VirtualizationGuestDevice(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12VirtualizationGuestDevice_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12VirtualizationGuestDevice_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12Tools(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12Tools_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12Tools1_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12PageableTools(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12PageableTools_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12PageableTools_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12DeviceTools(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12DeviceTools_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12DeviceTools_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12SDKConfiguration(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12SDKConfiguration_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12SDKConfiguration1_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12DeviceFactory(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12DeviceFactory_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12DeviceFactory_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12DeviceConfiguration(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12DeviceConfiguration_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12DeviceConfiguration1_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12CommandList(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12CommandList_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12GraphicsCommandList10_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12DSRDeviceFactory(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12DSRDeviceFactory_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12DSRDeviceFactory_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12GBVDiagnostics(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12GBVDiagnostics_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12GBVDiagnostics_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D10Blob(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D10Blob_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D10Blob_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3DDestructionNotifier(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3DDestructionNotifier_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3DDestructionNotifier_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12Debug1(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12Debug1_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12Debug1_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12Debug2(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12Debug2_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12Debug2_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12Debug(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12Debug_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12Debug6_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12DebugDevice1(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12DebugDevice1_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12DebugDevice1_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12DebugDevice(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12DebugDevice_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12DebugDevice2_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12DebugCommandQueue(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12DebugCommandQueue_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12DebugCommandQueue1_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12DebugCommandList1(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12DebugCommandList1_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12DebugCommandList1_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12DebugCommandList(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12DebugCommandList_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12DebugCommandList3_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12SharingContract(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12SharingContract_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12SharingContract_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12ManualWriteTrackingResource(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12ManualWriteTrackingResource_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12ManualWriteTrackingResource_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D12InfoQueue(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D12InfoQueue_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D12InfoQueue1_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11DepthStencilState(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11DepthStencilState_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11DepthStencilState_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11Buffer(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11Buffer_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11Buffer_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11Texture1D(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11Texture1D_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11Texture1D_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11Texture2D(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11Texture2D_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11Texture2D_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11Texture3D(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11Texture3D_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11Texture3D_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11ShaderResourceView(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11ShaderResourceView_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11ShaderResourceView_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11RenderTargetView(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11RenderTargetView_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11RenderTargetView_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11DepthStencilView(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11DepthStencilView_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11DepthStencilView_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11UnorderedAccessView(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11UnorderedAccessView_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11UnorderedAccessView_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11VertexShader(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11VertexShader_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11VertexShader_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11HullShader(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11HullShader_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11HullShader_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11DomainShader(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11DomainShader_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11DomainShader_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11GeometryShader(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11GeometryShader_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11GeometryShader_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11PixelShader(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11PixelShader_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11PixelShader_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11ComputeShader(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11ComputeShader_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11ComputeShader_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11InputLayout(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11InputLayout_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11InputLayout_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11SamplerState(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11SamplerState_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11SamplerState_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11Predicate(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11Predicate_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11Predicate_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11Counter(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11Counter_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11Counter_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11ClassInstance(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11ClassInstance_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11ClassInstance_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11ClassLinkage(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11ClassLinkage_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11ClassLinkage_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11CommandList(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11CommandList_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11CommandList_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11VideoDecoder(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11VideoDecoder_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11VideoDecoder_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11VideoProcessor(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11VideoProcessor_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11VideoProcessor_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11AuthenticatedChannel(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11AuthenticatedChannel_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11AuthenticatedChannel_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11CryptoSession(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11CryptoSession_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11CryptoSession_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11VideoDecoderOutputView(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11VideoDecoderOutputView_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11VideoDecoderOutputView_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11VideoProcessorInputView(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11VideoProcessorInputView_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11VideoProcessorInputView_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11VideoProcessorOutputView(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11VideoProcessorOutputView_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11VideoProcessorOutputView_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11BlendState(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11BlendState_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11BlendState1_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11RasterizerState(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11RasterizerState_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11RasterizerState1_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3DDeviceContextState(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3DDeviceContextState_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3DDeviceContextState_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11VideoContext(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11VideoContext_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11VideoContext1_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11VideoDevice(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11VideoDevice_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11VideoDevice1_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11VideoProcessorEnumerator(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11VideoProcessorEnumerator_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11VideoProcessorEnumerator1_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3DUserDefinedAnnotation(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3DUserDefinedAnnotation_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3DUserDefinedAnnotation_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11DeviceContext(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11DeviceContext_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11DeviceContext2_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapID3D11Device(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = ID3D11Device_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new ID3D11Device2_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapIDXGIKeyedMutex(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = IDXGIKeyedMutex_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new IDXGIKeyedMutex_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapIDXGIDisplayControl(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = IDXGIDisplayControl_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new IDXGIDisplayControl_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapIDXGIOutputDuplication(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = IDXGIOutputDuplication_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new IDXGIOutputDuplication_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapIDXGISurface(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = IDXGISurface_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new IDXGISurface2_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapIDXGIResource(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = IDXGIResource_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new IDXGIResource1_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapIDXGIDecodeSwapChain(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = IDXGIDecodeSwapChain_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new IDXGIDecodeSwapChain_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapIDXGIFactoryMedia(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = IDXGIFactoryMedia_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new IDXGIFactoryMedia_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapIDXGISwapChainMedia(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = IDXGISwapChainMedia_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new IDXGISwapChainMedia_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapIDXGISwapChain(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = IDXGISwapChain_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new IDXGISwapChain4_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapIDXGIDevice(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = IDXGIDevice_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new IDXGIDevice4_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapIDXGIAdapter(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = IDXGIAdapter_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new IDXGIAdapter4_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapIDXGIOutput(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = IDXGIOutput_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new IDXGIOutput6_Wrapper(riid, *wrap_object, resources);
    }
}

void WrapIDXGIFactory(REFIID riid, void** object, DxWrapperResources* resources)
{
    assert((object != nullptr) && (*object != nullptr));
    auto wrap_object = reinterpret_cast<IUnknown**>(object);

    auto existing = IDXGIFactory_Wrapper::GetExistingWrapper(*wrap_object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*wrap_object)->Release();
        (*object) = existing;
    }
    else
    {
        // Create a wrapper for the latest interface version.  The application will only use the wrapper as the interface type that it expects it to be.
        (*object) = new IDXGIFactory7_Wrapper(riid, *wrap_object, resources);
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
