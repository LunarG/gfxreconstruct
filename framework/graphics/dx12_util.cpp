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

#include "graphics/dx12_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)
GFXRECON_BEGIN_NAMESPACE(dx12)

HRESULT MapSubresource(ID3D12Resource* resource, UINT subresource, const D3D12_RANGE* read_range, uint8_t*& data_ptr)
{
    HRESULT result = E_FAIL;

    // Map the readable resource.
    void* void_ptr = nullptr;
    result         = resource->Map(subresource, read_range, &void_ptr);
    if (SUCCEEDED(result))
    {
        data_ptr = static_cast<uint8_t*>(void_ptr);
        if (data_ptr == nullptr)
        {
            D3D12_RANGE write_range = { 0, 0 };
            resource->Unmap(subresource, &write_range);
            result = E_POINTER;
        }
    }

    return result;
}

HRESULT WaitForQueue(ID3D12CommandQueue* queue)
{
    HRESULT            result = E_FAIL;
    ID3D12DeviceComPtr device;
    result = queue->GetDevice(IID_PPV_ARGS(&device));
    if (SUCCEEDED(result))
    {
        ID3D12FenceComPtr fence;
        result = device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&fence));
        if (SUCCEEDED(result))
        {
            HANDLE idle_event = CreateEventA(nullptr, TRUE, FALSE, nullptr);
            if (idle_event != nullptr)
            {
                result = fence->SetEventOnCompletion(1, idle_event);
                if (SUCCEEDED(result))
                {
                    result = queue->Signal(fence, 1);
                    if (SUCCEEDED(result))
                    {
                        WaitForSingleObject(idle_event, INFINITE);
                        result = S_OK;
                    }
                }
                CloseHandle(idle_event);
            }
        }
    }
    return result;
}

GFXRECON_END_NAMESPACE(dx12)
GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
