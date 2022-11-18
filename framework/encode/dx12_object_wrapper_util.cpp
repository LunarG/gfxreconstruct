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

#include "encode/dx12_object_wrapper_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

template <>
IUnknown* GetWrappedObject<IUnknown>(IUnknown* wrapped_object)
{
    IUnknown*         object  = wrapped_object;
    IUnknown_Wrapper* wrapper = nullptr;

    if ((object != nullptr) &&
        SUCCEEDED(object->QueryInterface(IID_IUnknown_Wrapper, reinterpret_cast<void**>(&wrapper))))
    {
        object = wrapper->GetWrappedObject();
    }

    return object;
}

template <>
const IUnknown* GetWrappedObject<IUnknown>(const IUnknown* wrapped_object)
{
    // Need to remove const for QueryInterface.
    IUnknown*         object  = const_cast<IUnknown*>(wrapped_object);
    IUnknown_Wrapper* wrapper = nullptr;

    if ((object != nullptr) &&
        SUCCEEDED(object->QueryInterface(IID_IUnknown_Wrapper, reinterpret_cast<void**>(&wrapper))))
    {
        object = wrapper->GetWrappedObject();
    }

    return object;
}

template <>
format::HandleId GetDx12WrappedId<IUnknown>(const IUnknown* wrapped_object)
{
    // Need to remove const for QueryInterface.
    IUnknown*         object  = const_cast<IUnknown*>(wrapped_object);
    IUnknown_Wrapper* wrapper = nullptr;

    if ((wrapped_object != nullptr) &&
        SUCCEEDED(object->QueryInterface(IID_IUnknown_Wrapper, reinterpret_cast<void**>(&wrapper))))
    {
        return wrapper->GetCaptureId();
    }

    return format::kNullHandleId;
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
