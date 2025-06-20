/*
** Copyright (c) 2023 LunarG, Inc.
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

#include "encode/iunknown_wrapper.h"

#include "encode/d3d12_capture_manager.h"
#include "encode/dx12_object_wrapper_resources.h"
#include "generated/generated_dx12_api_call_encoders.h"
#include "generated/generated_dx12_wrapper_creators.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

IUnknown_Wrapper::IUnknown_Wrapper(REFIID                                        riid,
                                   IUnknown*                                     wrapped_object,
                                   DxWrapperResources*                           resources,
                                   const std::function<void(IUnknown_Wrapper*)>& destructor) :
    riid_(riid),
    object_(wrapped_object, false), capture_id_(D3D12CaptureManager::GetUniqueId()), ref_count_(1)
{
    assert(wrapped_object != nullptr);

    // Register this wrapper with the list of related resources, which represents a list of pointers to the same object
    // with different IIDs, all of which share a reference count and will stay active until all of the resources in the
    // list are released by the application.
    if (resources != nullptr)
    {
        resources_ = resources;
        resources_->AddWrapper(this, destructor);
        resources_->IncrementSharedCount();
    }
    else
    {
        resources_ = new DxWrapperResources();
        resources_->AddWrapper(this, destructor);
    }
}

HRESULT IUnknown_Wrapper::QueryInterface(REFIID riid, void** object)
{
    // Check for a query from the capture framework to determine if an object with an IUknown* type is really a
    // wrapped object.  When the IID is a match, return a success code and a pointer to the current object
    // without incrementing the reference count.
    if (IsEqualIID(riid, IID_IUnknown_Wrapper))
    {
        (*object) = this;
        return S_OK;
    }

    HRESULT result     = E_FAIL;
    auto    manager    = D3D12CaptureManager::Get();
    auto    call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto api_call_lock = D3D12CaptureManager::AcquireSharedApiCallLock();

        IID target_interface_id = riid;

        // If GFXRECON_CAPTURE_IUNKNOWN_WRAPPING is enabled:
        // Detect when applications call QueryInterface(IID_IUnknown)
        // Switch IID_IUnknown to original IID, so that GFXR returns original interface wrapper
        if (manager->GetIUnknownWrappingSetting() && IsEqualGUID(riid, IID_IUnknown))
        {
            GFXRECON_LOG_WARNING("Detect call QueryInterface(IID_IUnknown)");
            target_interface_id = riid_;
        }

        result = object_->QueryInterface(target_interface_id, object);

        if (SUCCEEDED(result))
        {
            WrapObject(target_interface_id, object, resources_);
        }

        Encode_IUnknown_QueryInterface(this, result, target_interface_id, object);
    }
    else
    {
        result = object_->QueryInterface(riid, object);
    }

    manager->DecrementCallScope();

    return result;
}

ULONG IUnknown_Wrapper::AddRef()
{
    unsigned long local_count = ++ref_count_;
    resources_->IncrementSharedCount();

    auto manager    = D3D12CaptureManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto api_call_lock = D3D12CaptureManager::AcquireSharedApiCallLock();

        Encode_IUnknown_AddRef(this, local_count);
    }

    manager->DecrementCallScope();

    return local_count;
}

ULONG IUnknown_Wrapper::Release()
{
    auto local_count  = --ref_count_;
    auto shared_count = resources_->DecrementSharedCount();

    auto manager    = D3D12CaptureManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto api_call_lock = D3D12CaptureManager::AcquireSharedApiCallLock();

        Encode_IUnknown_Release(this, local_count);
    }

    if (shared_count == 0)
    {
        // The resources_ destructor destroys this wrapper and all other wrappers linked to it, so no additional work
        // may be performed in this function, as the current wrapper will no longer be valid.
        delete resources_;
    }

    manager->DecrementCallScope();

    return local_count;
}

void IUnknown_Wrapper::MakeRefInternal()
{
    // Decrement the local reference count, while leaving the shared reference count unmodified.
    --ref_count_;
}

void IUnknown_Wrapper::AddRefInternal()
{
    resources_->IncrementSharedCount();
}

void IUnknown_Wrapper::ReleaseRefInternal()
{
    auto shared_count = resources_->DecrementSharedCount();
    if (shared_count == 0)
    {
        // The resources_ destructor destroys this wrapper and all other wrappers linked to it.
        delete resources_;
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
