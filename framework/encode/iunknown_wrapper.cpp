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

#include "encode/iunknown_wrapper.h"

#include "encode/dx12_object_wrapper_resources.h"
#include "encode/trace_manager.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

IUnknown_Wrapper::IUnknown_Wrapper(IUnknown* wrapped_object) :
    object_(wrapped_object, false), capture_id_(TraceManager::GetUniqueId())
{
    resources_ = new DxWrapperResources();
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

    return object_->QueryInterface(riid, object);
}

ULONG IUnknown_Wrapper::AddRef()
{
    return ++resources_->wrapper_ref_count;
}

ULONG IUnknown_Wrapper::Release()
{
    --resources_->wrapper_ref_count;

    if (resources_->wrapper_ref_count > 0)
    {
        return resources_->wrapper_ref_count;
    }

    delete resources_; // Destroys this wrapper and all other wrappers linked to it.
    resources_ = nullptr;
    object_    = nullptr;

    return 0;
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
