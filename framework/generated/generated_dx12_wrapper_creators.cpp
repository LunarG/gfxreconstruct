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

IUnknown_Wrapper* WrapObject(REFIID riid, void** object, DxWrapperResources* resources)
{
    if ((object != nullptr) && (*object != nullptr))
    {
        auto it = kFunctionTable.find(riid);
        if (it != kFunctionTable.end())
        {
            return it->second(riid,object,resources);
        }
    }

    return nullptr;
}

IUnknown_Wrapper* WrapIDXGIKeyedMutex(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    IDXGIKeyedMutex** object = reinterpret_cast <IDXGIKeyedMutex **>(obj);

    auto existing = IDXGIKeyedMutex_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<IDXGIKeyedMutex*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_IDXGIKeyedMutex))
    {
        auto wrapper = new IDXGIKeyedMutex_Wrapper(IID_IDXGIKeyedMutex, static_cast<IDXGIKeyedMutex*>(*object), resources);
        (*object) = reinterpret_cast<IDXGIKeyedMutex*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGIKeyedMutex* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIKeyedMutex_Wrapper(IID_IDXGIKeyedMutex, converted, resources);
            (*object) = reinterpret_cast<IDXGIKeyedMutex*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported IDXGIKeyedMutex object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapIDXGIDisplayControl(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    IDXGIDisplayControl** object = reinterpret_cast <IDXGIDisplayControl **>(obj);

    auto existing = IDXGIDisplayControl_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<IDXGIDisplayControl*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_IDXGIDisplayControl))
    {
        auto wrapper = new IDXGIDisplayControl_Wrapper(IID_IDXGIDisplayControl, static_cast<IDXGIDisplayControl*>(*object), resources);
        (*object) = reinterpret_cast<IDXGIDisplayControl*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGIDisplayControl* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIDisplayControl_Wrapper(IID_IDXGIDisplayControl, converted, resources);
            (*object) = reinterpret_cast<IDXGIDisplayControl*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported IDXGIDisplayControl object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapIDXGIOutputDuplication(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    IDXGIOutputDuplication** object = reinterpret_cast <IDXGIOutputDuplication **>(obj);

    auto existing = IDXGIOutputDuplication_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<IDXGIOutputDuplication*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_IDXGIOutputDuplication))
    {
        auto wrapper = new IDXGIOutputDuplication_Wrapper(IID_IDXGIOutputDuplication, static_cast<IDXGIOutputDuplication*>(*object), resources);
        (*object) = reinterpret_cast<IDXGIOutputDuplication*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGIOutputDuplication* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIOutputDuplication_Wrapper(IID_IDXGIOutputDuplication, converted, resources);
            (*object) = reinterpret_cast<IDXGIOutputDuplication*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported IDXGIOutputDuplication object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapIDXGISurface(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    IDXGISurface** object = reinterpret_cast <IDXGISurface **>(obj);

    auto existing = IDXGISurface_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<IDXGISurface*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_IDXGISurface2))
    {
        auto wrapper = new IDXGISurface2_Wrapper(IID_IDXGISurface2, static_cast<IDXGISurface2*>(*object), resources);
        (*object) = reinterpret_cast<IDXGISurface2*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGISurface2* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGISurface2_Wrapper(IID_IDXGISurface2, converted, resources);
            (*object) = reinterpret_cast<IDXGISurface2*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_IDXGISurface1))
    {
        auto wrapper = new IDXGISurface1_Wrapper(IID_IDXGISurface1, static_cast<IDXGISurface1*>(*object), resources);
        (*object) = reinterpret_cast<IDXGISurface1*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGISurface1* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGISurface1_Wrapper(IID_IDXGISurface1, converted, resources);
            (*object) = reinterpret_cast<IDXGISurface1*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_IDXGISurface))
    {
        auto wrapper = new IDXGISurface_Wrapper(IID_IDXGISurface, static_cast<IDXGISurface*>(*object), resources);
        (*object) = reinterpret_cast<IDXGISurface*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGISurface* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGISurface_Wrapper(IID_IDXGISurface, converted, resources);
            (*object) = reinterpret_cast<IDXGISurface*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported IDXGISurface object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapIDXGIResource(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    IDXGIResource** object = reinterpret_cast <IDXGIResource **>(obj);

    auto existing = IDXGIResource_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<IDXGIResource*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_IDXGIResource1))
    {
        auto wrapper = new IDXGIResource1_Wrapper(IID_IDXGIResource1, static_cast<IDXGIResource1*>(*object), resources);
        (*object) = reinterpret_cast<IDXGIResource1*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGIResource1* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIResource1_Wrapper(IID_IDXGIResource1, converted, resources);
            (*object) = reinterpret_cast<IDXGIResource1*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIResource))
    {
        auto wrapper = new IDXGIResource_Wrapper(IID_IDXGIResource, static_cast<IDXGIResource*>(*object), resources);
        (*object) = reinterpret_cast<IDXGIResource*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGIResource* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIResource_Wrapper(IID_IDXGIResource, converted, resources);
            (*object) = reinterpret_cast<IDXGIResource*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported IDXGIResource object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapIDXGIDecodeSwapChain(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    IDXGIDecodeSwapChain** object = reinterpret_cast <IDXGIDecodeSwapChain **>(obj);

    auto existing = IDXGIDecodeSwapChain_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<IDXGIDecodeSwapChain*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_IDXGIDecodeSwapChain))
    {
        auto wrapper = new IDXGIDecodeSwapChain_Wrapper(IID_IDXGIDecodeSwapChain, static_cast<IDXGIDecodeSwapChain*>(*object), resources);
        (*object) = reinterpret_cast<IDXGIDecodeSwapChain*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGIDecodeSwapChain* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIDecodeSwapChain_Wrapper(IID_IDXGIDecodeSwapChain, converted, resources);
            (*object) = reinterpret_cast<IDXGIDecodeSwapChain*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported IDXGIDecodeSwapChain object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapIDXGIFactoryMedia(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    IDXGIFactoryMedia** object = reinterpret_cast <IDXGIFactoryMedia **>(obj);

    auto existing = IDXGIFactoryMedia_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<IDXGIFactoryMedia*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_IDXGIFactoryMedia))
    {
        auto wrapper = new IDXGIFactoryMedia_Wrapper(IID_IDXGIFactoryMedia, static_cast<IDXGIFactoryMedia*>(*object), resources);
        (*object) = reinterpret_cast<IDXGIFactoryMedia*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGIFactoryMedia* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIFactoryMedia_Wrapper(IID_IDXGIFactoryMedia, converted, resources);
            (*object) = reinterpret_cast<IDXGIFactoryMedia*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported IDXGIFactoryMedia object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapIDXGISwapChainMedia(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    IDXGISwapChainMedia** object = reinterpret_cast <IDXGISwapChainMedia **>(obj);

    auto existing = IDXGISwapChainMedia_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<IDXGISwapChainMedia*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_IDXGISwapChainMedia))
    {
        auto wrapper = new IDXGISwapChainMedia_Wrapper(IID_IDXGISwapChainMedia, static_cast<IDXGISwapChainMedia*>(*object), resources);
        (*object) = reinterpret_cast<IDXGISwapChainMedia*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGISwapChainMedia* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGISwapChainMedia_Wrapper(IID_IDXGISwapChainMedia, converted, resources);
            (*object) = reinterpret_cast<IDXGISwapChainMedia*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported IDXGISwapChainMedia object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapIDXGISwapChain(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    IDXGISwapChain** object = reinterpret_cast <IDXGISwapChain **>(obj);

    auto existing = IDXGISwapChain_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<IDXGISwapChain*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_IDXGISwapChain4))
    {
        auto wrapper = new IDXGISwapChain4_Wrapper(IID_IDXGISwapChain4, static_cast<IDXGISwapChain4*>(*object), resources);
        (*object) = reinterpret_cast<IDXGISwapChain4*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGISwapChain4* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGISwapChain4_Wrapper(IID_IDXGISwapChain4, converted, resources);
            (*object) = reinterpret_cast<IDXGISwapChain4*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_IDXGISwapChain3))
    {
        auto wrapper = new IDXGISwapChain3_Wrapper(IID_IDXGISwapChain3, static_cast<IDXGISwapChain3*>(*object), resources);
        (*object) = reinterpret_cast<IDXGISwapChain3*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGISwapChain3* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGISwapChain3_Wrapper(IID_IDXGISwapChain3, converted, resources);
            (*object) = reinterpret_cast<IDXGISwapChain3*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_IDXGISwapChain2))
    {
        auto wrapper = new IDXGISwapChain2_Wrapper(IID_IDXGISwapChain2, static_cast<IDXGISwapChain2*>(*object), resources);
        (*object) = reinterpret_cast<IDXGISwapChain2*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGISwapChain2* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGISwapChain2_Wrapper(IID_IDXGISwapChain2, converted, resources);
            (*object) = reinterpret_cast<IDXGISwapChain2*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_IDXGISwapChain1))
    {
        auto wrapper = new IDXGISwapChain1_Wrapper(IID_IDXGISwapChain1, static_cast<IDXGISwapChain1*>(*object), resources);
        (*object) = reinterpret_cast<IDXGISwapChain1*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGISwapChain1* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGISwapChain1_Wrapper(IID_IDXGISwapChain1, converted, resources);
            (*object) = reinterpret_cast<IDXGISwapChain1*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_IDXGISwapChain))
    {
        auto wrapper = new IDXGISwapChain_Wrapper(IID_IDXGISwapChain, static_cast<IDXGISwapChain*>(*object), resources);
        (*object) = reinterpret_cast<IDXGISwapChain*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGISwapChain* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGISwapChain_Wrapper(IID_IDXGISwapChain, converted, resources);
            (*object) = reinterpret_cast<IDXGISwapChain*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported IDXGISwapChain object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapIDXGIDevice(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    IDXGIDevice** object = reinterpret_cast <IDXGIDevice **>(obj);

    auto existing = IDXGIDevice_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<IDXGIDevice*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_IDXGIDevice4))
    {
        auto wrapper = new IDXGIDevice4_Wrapper(IID_IDXGIDevice4, static_cast<IDXGIDevice4*>(*object), resources);
        (*object) = reinterpret_cast<IDXGIDevice4*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGIDevice4* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIDevice4_Wrapper(IID_IDXGIDevice4, converted, resources);
            (*object) = reinterpret_cast<IDXGIDevice4*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIDevice3))
    {
        auto wrapper = new IDXGIDevice3_Wrapper(IID_IDXGIDevice3, static_cast<IDXGIDevice3*>(*object), resources);
        (*object) = reinterpret_cast<IDXGIDevice3*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGIDevice3* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIDevice3_Wrapper(IID_IDXGIDevice3, converted, resources);
            (*object) = reinterpret_cast<IDXGIDevice3*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIDevice2))
    {
        auto wrapper = new IDXGIDevice2_Wrapper(IID_IDXGIDevice2, static_cast<IDXGIDevice2*>(*object), resources);
        (*object) = reinterpret_cast<IDXGIDevice2*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGIDevice2* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIDevice2_Wrapper(IID_IDXGIDevice2, converted, resources);
            (*object) = reinterpret_cast<IDXGIDevice2*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIDevice1))
    {
        auto wrapper = new IDXGIDevice1_Wrapper(IID_IDXGIDevice1, static_cast<IDXGIDevice1*>(*object), resources);
        (*object) = reinterpret_cast<IDXGIDevice1*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGIDevice1* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIDevice1_Wrapper(IID_IDXGIDevice1, converted, resources);
            (*object) = reinterpret_cast<IDXGIDevice1*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIDevice))
    {
        auto wrapper = new IDXGIDevice_Wrapper(IID_IDXGIDevice, static_cast<IDXGIDevice*>(*object), resources);
        (*object) = reinterpret_cast<IDXGIDevice*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGIDevice* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIDevice_Wrapper(IID_IDXGIDevice, converted, resources);
            (*object) = reinterpret_cast<IDXGIDevice*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported IDXGIDevice object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapIDXGIAdapter(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    IDXGIAdapter** object = reinterpret_cast <IDXGIAdapter **>(obj);

    auto existing = IDXGIAdapter_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<IDXGIAdapter*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_IDXGIAdapter4))
    {
        auto wrapper = new IDXGIAdapter4_Wrapper(IID_IDXGIAdapter4, static_cast<IDXGIAdapter4*>(*object), resources);
        (*object) = reinterpret_cast<IDXGIAdapter4*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGIAdapter4* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIAdapter4_Wrapper(IID_IDXGIAdapter4, converted, resources);
            (*object) = reinterpret_cast<IDXGIAdapter4*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIAdapter3))
    {
        auto wrapper = new IDXGIAdapter3_Wrapper(IID_IDXGIAdapter3, static_cast<IDXGIAdapter3*>(*object), resources);
        (*object) = reinterpret_cast<IDXGIAdapter3*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGIAdapter3* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIAdapter3_Wrapper(IID_IDXGIAdapter3, converted, resources);
            (*object) = reinterpret_cast<IDXGIAdapter3*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIAdapter2))
    {
        auto wrapper = new IDXGIAdapter2_Wrapper(IID_IDXGIAdapter2, static_cast<IDXGIAdapter2*>(*object), resources);
        (*object) = reinterpret_cast<IDXGIAdapter2*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGIAdapter2* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIAdapter2_Wrapper(IID_IDXGIAdapter2, converted, resources);
            (*object) = reinterpret_cast<IDXGIAdapter2*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIAdapter1))
    {
        auto wrapper = new IDXGIAdapter1_Wrapper(IID_IDXGIAdapter1, static_cast<IDXGIAdapter1*>(*object), resources);
        (*object) = reinterpret_cast<IDXGIAdapter1*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGIAdapter1* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIAdapter1_Wrapper(IID_IDXGIAdapter1, converted, resources);
            (*object) = reinterpret_cast<IDXGIAdapter1*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIAdapter))
    {
        auto wrapper = new IDXGIAdapter_Wrapper(IID_IDXGIAdapter, static_cast<IDXGIAdapter*>(*object), resources);
        (*object) = reinterpret_cast<IDXGIAdapter*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGIAdapter* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIAdapter_Wrapper(IID_IDXGIAdapter, converted, resources);
            (*object) = reinterpret_cast<IDXGIAdapter*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported IDXGIAdapter object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapIDXGIOutput(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    IDXGIOutput** object = reinterpret_cast <IDXGIOutput **>(obj);

    auto existing = IDXGIOutput_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<IDXGIOutput*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_IDXGIOutput6))
    {
        auto wrapper = new IDXGIOutput6_Wrapper(IID_IDXGIOutput6, static_cast<IDXGIOutput6*>(*object), resources);
        (*object) = reinterpret_cast<IDXGIOutput6*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGIOutput6* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIOutput6_Wrapper(IID_IDXGIOutput6, converted, resources);
            (*object) = reinterpret_cast<IDXGIOutput6*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIOutput5))
    {
        auto wrapper = new IDXGIOutput5_Wrapper(IID_IDXGIOutput5, static_cast<IDXGIOutput5*>(*object), resources);
        (*object) = reinterpret_cast<IDXGIOutput5*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGIOutput5* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIOutput5_Wrapper(IID_IDXGIOutput5, converted, resources);
            (*object) = reinterpret_cast<IDXGIOutput5*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIOutput4))
    {
        auto wrapper = new IDXGIOutput4_Wrapper(IID_IDXGIOutput4, static_cast<IDXGIOutput4*>(*object), resources);
        (*object) = reinterpret_cast<IDXGIOutput4*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGIOutput4* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIOutput4_Wrapper(IID_IDXGIOutput4, converted, resources);
            (*object) = reinterpret_cast<IDXGIOutput4*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIOutput3))
    {
        auto wrapper = new IDXGIOutput3_Wrapper(IID_IDXGIOutput3, static_cast<IDXGIOutput3*>(*object), resources);
        (*object) = reinterpret_cast<IDXGIOutput3*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGIOutput3* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIOutput3_Wrapper(IID_IDXGIOutput3, converted, resources);
            (*object) = reinterpret_cast<IDXGIOutput3*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIOutput2))
    {
        auto wrapper = new IDXGIOutput2_Wrapper(IID_IDXGIOutput2, static_cast<IDXGIOutput2*>(*object), resources);
        (*object) = reinterpret_cast<IDXGIOutput2*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGIOutput2* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIOutput2_Wrapper(IID_IDXGIOutput2, converted, resources);
            (*object) = reinterpret_cast<IDXGIOutput2*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIOutput1))
    {
        auto wrapper = new IDXGIOutput1_Wrapper(IID_IDXGIOutput1, static_cast<IDXGIOutput1*>(*object), resources);
        (*object) = reinterpret_cast<IDXGIOutput1*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGIOutput1* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIOutput1_Wrapper(IID_IDXGIOutput1, converted, resources);
            (*object) = reinterpret_cast<IDXGIOutput1*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIOutput))
    {
        auto wrapper = new IDXGIOutput_Wrapper(IID_IDXGIOutput, static_cast<IDXGIOutput*>(*object), resources);
        (*object) = reinterpret_cast<IDXGIOutput*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGIOutput* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIOutput_Wrapper(IID_IDXGIOutput, converted, resources);
            (*object) = reinterpret_cast<IDXGIOutput*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported IDXGIOutput object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapIDXGIFactory(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    IDXGIFactory** object = reinterpret_cast <IDXGIFactory **>(obj);

    auto existing = IDXGIFactory_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<IDXGIFactory*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_IDXGIFactory7))
    {
        auto wrapper = new IDXGIFactory7_Wrapper(IID_IDXGIFactory7, static_cast<IDXGIFactory7*>(*object), resources);
        (*object) = reinterpret_cast<IDXGIFactory7*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGIFactory7* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIFactory7_Wrapper(IID_IDXGIFactory7, converted, resources);
            (*object) = reinterpret_cast<IDXGIFactory7*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIFactory6))
    {
        auto wrapper = new IDXGIFactory6_Wrapper(IID_IDXGIFactory6, static_cast<IDXGIFactory6*>(*object), resources);
        (*object) = reinterpret_cast<IDXGIFactory6*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGIFactory6* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIFactory6_Wrapper(IID_IDXGIFactory6, converted, resources);
            (*object) = reinterpret_cast<IDXGIFactory6*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIFactory5))
    {
        auto wrapper = new IDXGIFactory5_Wrapper(IID_IDXGIFactory5, static_cast<IDXGIFactory5*>(*object), resources);
        (*object) = reinterpret_cast<IDXGIFactory5*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGIFactory5* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIFactory5_Wrapper(IID_IDXGIFactory5, converted, resources);
            (*object) = reinterpret_cast<IDXGIFactory5*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIFactory4))
    {
        auto wrapper = new IDXGIFactory4_Wrapper(IID_IDXGIFactory4, static_cast<IDXGIFactory4*>(*object), resources);
        (*object) = reinterpret_cast<IDXGIFactory4*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGIFactory4* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIFactory4_Wrapper(IID_IDXGIFactory4, converted, resources);
            (*object) = reinterpret_cast<IDXGIFactory4*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIFactory3))
    {
        auto wrapper = new IDXGIFactory3_Wrapper(IID_IDXGIFactory3, static_cast<IDXGIFactory3*>(*object), resources);
        (*object) = reinterpret_cast<IDXGIFactory3*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGIFactory3* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIFactory3_Wrapper(IID_IDXGIFactory3, converted, resources);
            (*object) = reinterpret_cast<IDXGIFactory3*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIFactory2))
    {
        auto wrapper = new IDXGIFactory2_Wrapper(IID_IDXGIFactory2, static_cast<IDXGIFactory2*>(*object), resources);
        (*object) = reinterpret_cast<IDXGIFactory2*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGIFactory2* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIFactory2_Wrapper(IID_IDXGIFactory2, converted, resources);
            (*object) = reinterpret_cast<IDXGIFactory2*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIFactory1))
    {
        auto wrapper = new IDXGIFactory1_Wrapper(IID_IDXGIFactory1, static_cast<IDXGIFactory1*>(*object), resources);
        (*object) = reinterpret_cast<IDXGIFactory1*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGIFactory1* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIFactory1_Wrapper(IID_IDXGIFactory1, converted, resources);
            (*object) = reinterpret_cast<IDXGIFactory1*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_IDXGIFactory))
    {
        auto wrapper = new IDXGIFactory_Wrapper(IID_IDXGIFactory, static_cast<IDXGIFactory*>(*object), resources);
        (*object) = reinterpret_cast<IDXGIFactory*>(wrapper);
        return wrapper;
    }
    else
    {
        IDXGIFactory* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new IDXGIFactory_Wrapper(IID_IDXGIFactory, converted, resources);
            (*object) = reinterpret_cast<IDXGIFactory*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported IDXGIFactory object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapID3D12RootSignature(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    ID3D12RootSignature** object = reinterpret_cast <ID3D12RootSignature **>(obj);

    auto existing = ID3D12RootSignature_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<ID3D12RootSignature*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_ID3D12RootSignature))
    {
        auto wrapper = new ID3D12RootSignature_Wrapper(IID_ID3D12RootSignature, static_cast<ID3D12RootSignature*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12RootSignature*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12RootSignature* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12RootSignature_Wrapper(IID_ID3D12RootSignature, converted, resources);
            (*object) = reinterpret_cast<ID3D12RootSignature*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12RootSignature object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapID3D12RootSignatureDeserializer(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    ID3D12RootSignatureDeserializer** object = reinterpret_cast <ID3D12RootSignatureDeserializer **>(obj);

    auto existing = ID3D12RootSignatureDeserializer_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<ID3D12RootSignatureDeserializer*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_ID3D12RootSignatureDeserializer))
    {
        auto wrapper = new ID3D12RootSignatureDeserializer_Wrapper(IID_ID3D12RootSignatureDeserializer, static_cast<ID3D12RootSignatureDeserializer*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12RootSignatureDeserializer*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12RootSignatureDeserializer* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12RootSignatureDeserializer_Wrapper(IID_ID3D12RootSignatureDeserializer, converted, resources);
            (*object) = reinterpret_cast<ID3D12RootSignatureDeserializer*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12RootSignatureDeserializer object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapID3D12VersionedRootSignatureDeserializer(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    ID3D12VersionedRootSignatureDeserializer** object = reinterpret_cast <ID3D12VersionedRootSignatureDeserializer **>(obj);

    auto existing = ID3D12VersionedRootSignatureDeserializer_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<ID3D12VersionedRootSignatureDeserializer*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_ID3D12VersionedRootSignatureDeserializer))
    {
        auto wrapper = new ID3D12VersionedRootSignatureDeserializer_Wrapper(IID_ID3D12VersionedRootSignatureDeserializer, static_cast<ID3D12VersionedRootSignatureDeserializer*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12VersionedRootSignatureDeserializer*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12VersionedRootSignatureDeserializer* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12VersionedRootSignatureDeserializer_Wrapper(IID_ID3D12VersionedRootSignatureDeserializer, converted, resources);
            (*object) = reinterpret_cast<ID3D12VersionedRootSignatureDeserializer*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12VersionedRootSignatureDeserializer object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapID3D12CommandAllocator(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    ID3D12CommandAllocator** object = reinterpret_cast <ID3D12CommandAllocator **>(obj);

    auto existing = ID3D12CommandAllocator_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<ID3D12CommandAllocator*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_ID3D12CommandAllocator))
    {
        auto wrapper = new ID3D12CommandAllocator_Wrapper(IID_ID3D12CommandAllocator, static_cast<ID3D12CommandAllocator*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12CommandAllocator*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12CommandAllocator* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12CommandAllocator_Wrapper(IID_ID3D12CommandAllocator, converted, resources);
            (*object) = reinterpret_cast<ID3D12CommandAllocator*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12CommandAllocator object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapID3D12Fence(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    ID3D12Fence** object = reinterpret_cast <ID3D12Fence **>(obj);

    auto existing = ID3D12Fence_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<ID3D12Fence*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_ID3D12Fence1))
    {
        auto wrapper = new ID3D12Fence1_Wrapper(IID_ID3D12Fence1, static_cast<ID3D12Fence1*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12Fence1*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12Fence1* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Fence1_Wrapper(IID_ID3D12Fence1, converted, resources);
            (*object) = reinterpret_cast<ID3D12Fence1*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12Fence))
    {
        auto wrapper = new ID3D12Fence_Wrapper(IID_ID3D12Fence, static_cast<ID3D12Fence*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12Fence*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12Fence* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Fence_Wrapper(IID_ID3D12Fence, converted, resources);
            (*object) = reinterpret_cast<ID3D12Fence*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12Fence object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapID3D12PipelineState(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    ID3D12PipelineState** object = reinterpret_cast <ID3D12PipelineState **>(obj);

    auto existing = ID3D12PipelineState_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<ID3D12PipelineState*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_ID3D12PipelineState))
    {
        auto wrapper = new ID3D12PipelineState_Wrapper(IID_ID3D12PipelineState, static_cast<ID3D12PipelineState*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12PipelineState*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12PipelineState* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12PipelineState_Wrapper(IID_ID3D12PipelineState, converted, resources);
            (*object) = reinterpret_cast<ID3D12PipelineState*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12PipelineState object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapID3D12DescriptorHeap(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    ID3D12DescriptorHeap** object = reinterpret_cast <ID3D12DescriptorHeap **>(obj);

    auto existing = ID3D12DescriptorHeap_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<ID3D12DescriptorHeap*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_ID3D12DescriptorHeap))
    {
        auto wrapper = new ID3D12DescriptorHeap_Wrapper(IID_ID3D12DescriptorHeap, static_cast<ID3D12DescriptorHeap*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12DescriptorHeap*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12DescriptorHeap* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12DescriptorHeap_Wrapper(IID_ID3D12DescriptorHeap, converted, resources);
            (*object) = reinterpret_cast<ID3D12DescriptorHeap*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12DescriptorHeap object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapID3D12QueryHeap(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    ID3D12QueryHeap** object = reinterpret_cast <ID3D12QueryHeap **>(obj);

    auto existing = ID3D12QueryHeap_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<ID3D12QueryHeap*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_ID3D12QueryHeap))
    {
        auto wrapper = new ID3D12QueryHeap_Wrapper(IID_ID3D12QueryHeap, static_cast<ID3D12QueryHeap*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12QueryHeap*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12QueryHeap* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12QueryHeap_Wrapper(IID_ID3D12QueryHeap, converted, resources);
            (*object) = reinterpret_cast<ID3D12QueryHeap*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12QueryHeap object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapID3D12CommandSignature(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    ID3D12CommandSignature** object = reinterpret_cast <ID3D12CommandSignature **>(obj);

    auto existing = ID3D12CommandSignature_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<ID3D12CommandSignature*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_ID3D12CommandSignature))
    {
        auto wrapper = new ID3D12CommandSignature_Wrapper(IID_ID3D12CommandSignature, static_cast<ID3D12CommandSignature*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12CommandSignature*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12CommandSignature* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12CommandSignature_Wrapper(IID_ID3D12CommandSignature, converted, resources);
            (*object) = reinterpret_cast<ID3D12CommandSignature*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12CommandSignature object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapID3D12CommandQueue(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    ID3D12CommandQueue** object = reinterpret_cast <ID3D12CommandQueue **>(obj);

    auto existing = ID3D12CommandQueue_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<ID3D12CommandQueue*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_ID3D12CommandQueue))
    {
        auto wrapper = new ID3D12CommandQueue_Wrapper(IID_ID3D12CommandQueue, static_cast<ID3D12CommandQueue*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12CommandQueue*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12CommandQueue* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12CommandQueue_Wrapper(IID_ID3D12CommandQueue, converted, resources);
            (*object) = reinterpret_cast<ID3D12CommandQueue*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12CommandQueue object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapID3D12PipelineLibrary(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    ID3D12PipelineLibrary** object = reinterpret_cast <ID3D12PipelineLibrary **>(obj);

    auto existing = ID3D12PipelineLibrary_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<ID3D12PipelineLibrary*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_ID3D12PipelineLibrary1))
    {
        auto wrapper = new ID3D12PipelineLibrary1_Wrapper(IID_ID3D12PipelineLibrary1, static_cast<ID3D12PipelineLibrary1*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12PipelineLibrary1*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12PipelineLibrary1* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12PipelineLibrary1_Wrapper(IID_ID3D12PipelineLibrary1, converted, resources);
            (*object) = reinterpret_cast<ID3D12PipelineLibrary1*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12PipelineLibrary))
    {
        auto wrapper = new ID3D12PipelineLibrary_Wrapper(IID_ID3D12PipelineLibrary, static_cast<ID3D12PipelineLibrary*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12PipelineLibrary*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12PipelineLibrary* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12PipelineLibrary_Wrapper(IID_ID3D12PipelineLibrary, converted, resources);
            (*object) = reinterpret_cast<ID3D12PipelineLibrary*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12PipelineLibrary object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapID3D12LifetimeOwner(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    ID3D12LifetimeOwner** object = reinterpret_cast <ID3D12LifetimeOwner **>(obj);

    auto existing = ID3D12LifetimeOwner_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<ID3D12LifetimeOwner*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_ID3D12LifetimeOwner))
    {
        auto wrapper = new ID3D12LifetimeOwner_Wrapper(IID_ID3D12LifetimeOwner, static_cast<ID3D12LifetimeOwner*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12LifetimeOwner*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12LifetimeOwner* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12LifetimeOwner_Wrapper(IID_ID3D12LifetimeOwner, converted, resources);
            (*object) = reinterpret_cast<ID3D12LifetimeOwner*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12LifetimeOwner object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapID3D12SwapChainAssistant(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    ID3D12SwapChainAssistant** object = reinterpret_cast <ID3D12SwapChainAssistant **>(obj);

    auto existing = ID3D12SwapChainAssistant_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<ID3D12SwapChainAssistant*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_ID3D12SwapChainAssistant))
    {
        auto wrapper = new ID3D12SwapChainAssistant_Wrapper(IID_ID3D12SwapChainAssistant, static_cast<ID3D12SwapChainAssistant*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12SwapChainAssistant*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12SwapChainAssistant* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12SwapChainAssistant_Wrapper(IID_ID3D12SwapChainAssistant, converted, resources);
            (*object) = reinterpret_cast<ID3D12SwapChainAssistant*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12SwapChainAssistant object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapID3D12LifetimeTracker(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    ID3D12LifetimeTracker** object = reinterpret_cast <ID3D12LifetimeTracker **>(obj);

    auto existing = ID3D12LifetimeTracker_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<ID3D12LifetimeTracker*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_ID3D12LifetimeTracker))
    {
        auto wrapper = new ID3D12LifetimeTracker_Wrapper(IID_ID3D12LifetimeTracker, static_cast<ID3D12LifetimeTracker*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12LifetimeTracker*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12LifetimeTracker* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12LifetimeTracker_Wrapper(IID_ID3D12LifetimeTracker, converted, resources);
            (*object) = reinterpret_cast<ID3D12LifetimeTracker*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12LifetimeTracker object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapID3D12StateObject(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    ID3D12StateObject** object = reinterpret_cast <ID3D12StateObject **>(obj);

    auto existing = ID3D12StateObject_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<ID3D12StateObject*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_ID3D12StateObject))
    {
        auto wrapper = new ID3D12StateObject_Wrapper(IID_ID3D12StateObject, static_cast<ID3D12StateObject*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12StateObject*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12StateObject* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12StateObject_Wrapper(IID_ID3D12StateObject, converted, resources);
            (*object) = reinterpret_cast<ID3D12StateObject*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12StateObject object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapID3D12StateObjectProperties(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    ID3D12StateObjectProperties** object = reinterpret_cast <ID3D12StateObjectProperties **>(obj);

    auto existing = ID3D12StateObjectProperties_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<ID3D12StateObjectProperties*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_ID3D12StateObjectProperties))
    {
        auto wrapper = new ID3D12StateObjectProperties_Wrapper(IID_ID3D12StateObjectProperties, static_cast<ID3D12StateObjectProperties*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12StateObjectProperties*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12StateObjectProperties* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12StateObjectProperties_Wrapper(IID_ID3D12StateObjectProperties, converted, resources);
            (*object) = reinterpret_cast<ID3D12StateObjectProperties*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12StateObjectProperties object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapID3D12DeviceRemovedExtendedDataSettings(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    ID3D12DeviceRemovedExtendedDataSettings** object = reinterpret_cast <ID3D12DeviceRemovedExtendedDataSettings **>(obj);

    auto existing = ID3D12DeviceRemovedExtendedDataSettings_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<ID3D12DeviceRemovedExtendedDataSettings*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_ID3D12DeviceRemovedExtendedDataSettings1))
    {
        auto wrapper = new ID3D12DeviceRemovedExtendedDataSettings1_Wrapper(IID_ID3D12DeviceRemovedExtendedDataSettings1, static_cast<ID3D12DeviceRemovedExtendedDataSettings1*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12DeviceRemovedExtendedDataSettings1*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12DeviceRemovedExtendedDataSettings1* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12DeviceRemovedExtendedDataSettings1_Wrapper(IID_ID3D12DeviceRemovedExtendedDataSettings1, converted, resources);
            (*object) = reinterpret_cast<ID3D12DeviceRemovedExtendedDataSettings1*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12DeviceRemovedExtendedDataSettings))
    {
        auto wrapper = new ID3D12DeviceRemovedExtendedDataSettings_Wrapper(IID_ID3D12DeviceRemovedExtendedDataSettings, static_cast<ID3D12DeviceRemovedExtendedDataSettings*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12DeviceRemovedExtendedDataSettings*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12DeviceRemovedExtendedDataSettings* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12DeviceRemovedExtendedDataSettings_Wrapper(IID_ID3D12DeviceRemovedExtendedDataSettings, converted, resources);
            (*object) = reinterpret_cast<ID3D12DeviceRemovedExtendedDataSettings*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12DeviceRemovedExtendedDataSettings object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapID3D12DeviceRemovedExtendedData(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    ID3D12DeviceRemovedExtendedData** object = reinterpret_cast <ID3D12DeviceRemovedExtendedData **>(obj);

    auto existing = ID3D12DeviceRemovedExtendedData_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<ID3D12DeviceRemovedExtendedData*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_ID3D12DeviceRemovedExtendedData1))
    {
        auto wrapper = new ID3D12DeviceRemovedExtendedData1_Wrapper(IID_ID3D12DeviceRemovedExtendedData1, static_cast<ID3D12DeviceRemovedExtendedData1*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12DeviceRemovedExtendedData1*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12DeviceRemovedExtendedData1* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12DeviceRemovedExtendedData1_Wrapper(IID_ID3D12DeviceRemovedExtendedData1, converted, resources);
            (*object) = reinterpret_cast<ID3D12DeviceRemovedExtendedData1*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12DeviceRemovedExtendedData))
    {
        auto wrapper = new ID3D12DeviceRemovedExtendedData_Wrapper(IID_ID3D12DeviceRemovedExtendedData, static_cast<ID3D12DeviceRemovedExtendedData*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12DeviceRemovedExtendedData*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12DeviceRemovedExtendedData* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12DeviceRemovedExtendedData_Wrapper(IID_ID3D12DeviceRemovedExtendedData, converted, resources);
            (*object) = reinterpret_cast<ID3D12DeviceRemovedExtendedData*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12DeviceRemovedExtendedData object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapID3D12ProtectedResourceSession(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    ID3D12ProtectedResourceSession** object = reinterpret_cast <ID3D12ProtectedResourceSession **>(obj);

    auto existing = ID3D12ProtectedResourceSession_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<ID3D12ProtectedResourceSession*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_ID3D12ProtectedResourceSession1))
    {
        auto wrapper = new ID3D12ProtectedResourceSession1_Wrapper(IID_ID3D12ProtectedResourceSession1, static_cast<ID3D12ProtectedResourceSession1*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12ProtectedResourceSession1*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12ProtectedResourceSession1* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12ProtectedResourceSession1_Wrapper(IID_ID3D12ProtectedResourceSession1, converted, resources);
            (*object) = reinterpret_cast<ID3D12ProtectedResourceSession1*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12ProtectedResourceSession))
    {
        auto wrapper = new ID3D12ProtectedResourceSession_Wrapper(IID_ID3D12ProtectedResourceSession, static_cast<ID3D12ProtectedResourceSession*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12ProtectedResourceSession*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12ProtectedResourceSession* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12ProtectedResourceSession_Wrapper(IID_ID3D12ProtectedResourceSession, converted, resources);
            (*object) = reinterpret_cast<ID3D12ProtectedResourceSession*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12ProtectedResourceSession object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapID3D12Device(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    ID3D12Device** object = reinterpret_cast <ID3D12Device **>(obj);

    auto existing = ID3D12Device_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<ID3D12Device*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_ID3D12Device8))
    {
        auto wrapper = new ID3D12Device8_Wrapper(IID_ID3D12Device8, static_cast<ID3D12Device8*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12Device8*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12Device8* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Device8_Wrapper(IID_ID3D12Device8, converted, resources);
            (*object) = reinterpret_cast<ID3D12Device8*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12Device7))
    {
        auto wrapper = new ID3D12Device7_Wrapper(IID_ID3D12Device7, static_cast<ID3D12Device7*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12Device7*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12Device7* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Device7_Wrapper(IID_ID3D12Device7, converted, resources);
            (*object) = reinterpret_cast<ID3D12Device7*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12Device6))
    {
        auto wrapper = new ID3D12Device6_Wrapper(IID_ID3D12Device6, static_cast<ID3D12Device6*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12Device6*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12Device6* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Device6_Wrapper(IID_ID3D12Device6, converted, resources);
            (*object) = reinterpret_cast<ID3D12Device6*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12Device5))
    {
        auto wrapper = new ID3D12Device5_Wrapper(IID_ID3D12Device5, static_cast<ID3D12Device5*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12Device5*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12Device5* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Device5_Wrapper(IID_ID3D12Device5, converted, resources);
            (*object) = reinterpret_cast<ID3D12Device5*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12Device4))
    {
        auto wrapper = new ID3D12Device4_Wrapper(IID_ID3D12Device4, static_cast<ID3D12Device4*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12Device4*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12Device4* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Device4_Wrapper(IID_ID3D12Device4, converted, resources);
            (*object) = reinterpret_cast<ID3D12Device4*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12Device3))
    {
        auto wrapper = new ID3D12Device3_Wrapper(IID_ID3D12Device3, static_cast<ID3D12Device3*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12Device3*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12Device3* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Device3_Wrapper(IID_ID3D12Device3, converted, resources);
            (*object) = reinterpret_cast<ID3D12Device3*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12Device2))
    {
        auto wrapper = new ID3D12Device2_Wrapper(IID_ID3D12Device2, static_cast<ID3D12Device2*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12Device2*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12Device2* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Device2_Wrapper(IID_ID3D12Device2, converted, resources);
            (*object) = reinterpret_cast<ID3D12Device2*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12Device1))
    {
        auto wrapper = new ID3D12Device1_Wrapper(IID_ID3D12Device1, static_cast<ID3D12Device1*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12Device1*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12Device1* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Device1_Wrapper(IID_ID3D12Device1, converted, resources);
            (*object) = reinterpret_cast<ID3D12Device1*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12Device))
    {
        auto wrapper = new ID3D12Device_Wrapper(IID_ID3D12Device, static_cast<ID3D12Device*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12Device*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12Device* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Device_Wrapper(IID_ID3D12Device, converted, resources);
            (*object) = reinterpret_cast<ID3D12Device*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12Device object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapID3D12Resource(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    ID3D12Resource** object = reinterpret_cast <ID3D12Resource **>(obj);

    auto existing = ID3D12Resource_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<ID3D12Resource*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_ID3D12Resource2))
    {
        auto wrapper = new ID3D12Resource2_Wrapper(IID_ID3D12Resource2, static_cast<ID3D12Resource2*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12Resource2*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12Resource2* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Resource2_Wrapper(IID_ID3D12Resource2, converted, resources);
            (*object) = reinterpret_cast<ID3D12Resource2*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12Resource1))
    {
        auto wrapper = new ID3D12Resource1_Wrapper(IID_ID3D12Resource1, static_cast<ID3D12Resource1*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12Resource1*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12Resource1* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Resource1_Wrapper(IID_ID3D12Resource1, converted, resources);
            (*object) = reinterpret_cast<ID3D12Resource1*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12Resource))
    {
        auto wrapper = new ID3D12Resource_Wrapper(IID_ID3D12Resource, static_cast<ID3D12Resource*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12Resource*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12Resource* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Resource_Wrapper(IID_ID3D12Resource, converted, resources);
            (*object) = reinterpret_cast<ID3D12Resource*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12Resource object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapID3D12Heap(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    ID3D12Heap** object = reinterpret_cast <ID3D12Heap **>(obj);

    auto existing = ID3D12Heap_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<ID3D12Heap*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_ID3D12Heap1))
    {
        auto wrapper = new ID3D12Heap1_Wrapper(IID_ID3D12Heap1, static_cast<ID3D12Heap1*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12Heap1*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12Heap1* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Heap1_Wrapper(IID_ID3D12Heap1, converted, resources);
            (*object) = reinterpret_cast<ID3D12Heap1*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12Heap))
    {
        auto wrapper = new ID3D12Heap_Wrapper(IID_ID3D12Heap, static_cast<ID3D12Heap*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12Heap*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12Heap* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Heap_Wrapper(IID_ID3D12Heap, converted, resources);
            (*object) = reinterpret_cast<ID3D12Heap*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12Heap object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapID3D12MetaCommand(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    ID3D12MetaCommand** object = reinterpret_cast <ID3D12MetaCommand **>(obj);

    auto existing = ID3D12MetaCommand_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<ID3D12MetaCommand*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_ID3D12MetaCommand))
    {
        auto wrapper = new ID3D12MetaCommand_Wrapper(IID_ID3D12MetaCommand, static_cast<ID3D12MetaCommand*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12MetaCommand*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12MetaCommand* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12MetaCommand_Wrapper(IID_ID3D12MetaCommand, converted, resources);
            (*object) = reinterpret_cast<ID3D12MetaCommand*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12MetaCommand object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapID3D12Tools(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    ID3D12Tools** object = reinterpret_cast <ID3D12Tools **>(obj);

    auto existing = ID3D12Tools_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<ID3D12Tools*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_ID3D12Tools))
    {
        auto wrapper = new ID3D12Tools_Wrapper(IID_ID3D12Tools, static_cast<ID3D12Tools*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12Tools*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12Tools* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12Tools_Wrapper(IID_ID3D12Tools, converted, resources);
            (*object) = reinterpret_cast<ID3D12Tools*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12Tools object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapID3D12GraphicsCommandList(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    ID3D12GraphicsCommandList** object = reinterpret_cast <ID3D12GraphicsCommandList **>(obj);

    auto existing = ID3D12GraphicsCommandList_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<ID3D12GraphicsCommandList*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_ID3D12GraphicsCommandList6))
    {
        auto wrapper = new ID3D12GraphicsCommandList6_Wrapper(IID_ID3D12GraphicsCommandList6, static_cast<ID3D12GraphicsCommandList6*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12GraphicsCommandList6*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12GraphicsCommandList6* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12GraphicsCommandList6_Wrapper(IID_ID3D12GraphicsCommandList6, converted, resources);
            (*object) = reinterpret_cast<ID3D12GraphicsCommandList6*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12GraphicsCommandList5))
    {
        auto wrapper = new ID3D12GraphicsCommandList5_Wrapper(IID_ID3D12GraphicsCommandList5, static_cast<ID3D12GraphicsCommandList5*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12GraphicsCommandList5*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12GraphicsCommandList5* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12GraphicsCommandList5_Wrapper(IID_ID3D12GraphicsCommandList5, converted, resources);
            (*object) = reinterpret_cast<ID3D12GraphicsCommandList5*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12GraphicsCommandList4))
    {
        auto wrapper = new ID3D12GraphicsCommandList4_Wrapper(IID_ID3D12GraphicsCommandList4, static_cast<ID3D12GraphicsCommandList4*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12GraphicsCommandList4*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12GraphicsCommandList4* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12GraphicsCommandList4_Wrapper(IID_ID3D12GraphicsCommandList4, converted, resources);
            (*object) = reinterpret_cast<ID3D12GraphicsCommandList4*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12GraphicsCommandList3))
    {
        auto wrapper = new ID3D12GraphicsCommandList3_Wrapper(IID_ID3D12GraphicsCommandList3, static_cast<ID3D12GraphicsCommandList3*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12GraphicsCommandList3*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12GraphicsCommandList3* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12GraphicsCommandList3_Wrapper(IID_ID3D12GraphicsCommandList3, converted, resources);
            (*object) = reinterpret_cast<ID3D12GraphicsCommandList3*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12GraphicsCommandList2))
    {
        auto wrapper = new ID3D12GraphicsCommandList2_Wrapper(IID_ID3D12GraphicsCommandList2, static_cast<ID3D12GraphicsCommandList2*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12GraphicsCommandList2*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12GraphicsCommandList2* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12GraphicsCommandList2_Wrapper(IID_ID3D12GraphicsCommandList2, converted, resources);
            (*object) = reinterpret_cast<ID3D12GraphicsCommandList2*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12GraphicsCommandList1))
    {
        auto wrapper = new ID3D12GraphicsCommandList1_Wrapper(IID_ID3D12GraphicsCommandList1, static_cast<ID3D12GraphicsCommandList1*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12GraphicsCommandList1*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12GraphicsCommandList1* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12GraphicsCommandList1_Wrapper(IID_ID3D12GraphicsCommandList1, converted, resources);
            (*object) = reinterpret_cast<ID3D12GraphicsCommandList1*>(wrapper);
            return wrapper;
        }
    }

    if (IsEqualIID(riid, IID_ID3D12GraphicsCommandList))
    {
        auto wrapper = new ID3D12GraphicsCommandList_Wrapper(IID_ID3D12GraphicsCommandList, static_cast<ID3D12GraphicsCommandList*>(*object), resources);
        (*object) = reinterpret_cast<ID3D12GraphicsCommandList*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D12GraphicsCommandList* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D12GraphicsCommandList_Wrapper(IID_ID3D12GraphicsCommandList, converted, resources);
            (*object) = reinterpret_cast<ID3D12GraphicsCommandList*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D12GraphicsCommandList object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapID3D10Blob(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    ID3D10Blob** object = reinterpret_cast <ID3D10Blob **>(obj);

    auto existing = ID3D10Blob_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<ID3D10Blob*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_ID3D10Blob))
    {
        auto wrapper = new ID3D10Blob_Wrapper(IID_ID3D10Blob, static_cast<ID3D10Blob*>(*object), resources);
        (*object) = reinterpret_cast<ID3D10Blob*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3D10Blob* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3D10Blob_Wrapper(IID_ID3D10Blob, converted, resources);
            (*object) = reinterpret_cast<ID3D10Blob*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3D10Blob object type for capture");
    return nullptr;
}

IUnknown_Wrapper* WrapID3DDestructionNotifier(REFIID riid, void** obj, DxWrapperResources* resources)
{
    assert((obj != nullptr) && (*obj != nullptr));
    ID3DDestructionNotifier** object = reinterpret_cast <ID3DDestructionNotifier **>(obj);

    auto existing = ID3DDestructionNotifier_Wrapper::GetExistingWrapper(*object);
    if (existing != nullptr)
    {
        // Transfer reference count from the object to the wrapper so that the wrapper holds a single reference to the object.
        existing->AddRef();
        (*object)->Release();
        (*object) = reinterpret_cast<ID3DDestructionNotifier*>(existing);
        return existing;
    }

    if (IsEqualIID(riid, IID_ID3DDestructionNotifier))
    {
        auto wrapper = new ID3DDestructionNotifier_Wrapper(IID_ID3DDestructionNotifier, static_cast<ID3DDestructionNotifier*>(*object), resources);
        (*object) = reinterpret_cast<ID3DDestructionNotifier*>(wrapper);
        return wrapper;
    }
    else
    {
        ID3DDestructionNotifier* converted = nullptr;
        auto result = (*object)->QueryInterface(IID_PPV_ARGS(&converted));
        if (SUCCEEDED(result))
        {
            (*object)->Release();
            auto wrapper = new ID3DDestructionNotifier_Wrapper(IID_ID3DDestructionNotifier, converted, resources);
            (*object) = reinterpret_cast<ID3DDestructionNotifier*>(wrapper);
            return wrapper;
        }
    }

    GFXRECON_LOG_FATAL("Failed to wrap unsupported ID3DDestructionNotifier object type for capture");
    return nullptr;
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
