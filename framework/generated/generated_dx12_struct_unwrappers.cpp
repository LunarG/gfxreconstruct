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
** This file is generated from dx12_struct_unwrappers_body_generator.py.
**
*/

#include "generated/generated_dx12_struct_unwrappers.h"

#include "encode/custom_dx12_struct_unwrappers.h"
#include "encode/dx12_object_wrapper_util.h"
#include "generated/generated_dx12_wrappers.h"
#include "util/defines.h"

#include <dxgiformat.h>
#include <d3d12.h>
#include <d3dcommon.h>
#include <d3d12sdklayers.h>
#include <d3d11.h>
#include <d3d11_1.h>
#include <d3d11_2.h>
#include <d3d11_3.h>
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

void UnwrapStructObjects(D3D12_GRAPHICS_PIPELINE_STATE_DESC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pRootSignature = GetWrappedObject<ID3D12RootSignature>(value->pRootSignature);
    }
}

void UnwrapStructObjects(D3D12_COMPUTE_PIPELINE_STATE_DESC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pRootSignature = GetWrappedObject<ID3D12RootSignature>(value->pRootSignature);
    }
}

void UnwrapStructObjects(D3D12_RESOURCE_TRANSITION_BARRIER* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pResource = GetWrappedObject<ID3D12Resource>(value->pResource);
    }
}

void UnwrapStructObjects(D3D12_RESOURCE_ALIASING_BARRIER* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pResourceBefore = GetWrappedObject<ID3D12Resource>(value->pResourceBefore);
        value->pResourceAfter = GetWrappedObject<ID3D12Resource>(value->pResourceAfter);
    }
}

void UnwrapStructObjects(D3D12_RESOURCE_UAV_BARRIER* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pResource = GetWrappedObject<ID3D12Resource>(value->pResource);
    }
}

void UnwrapStructObjects(D3D12_GLOBAL_ROOT_SIGNATURE* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pGlobalRootSignature = GetWrappedObject<ID3D12RootSignature>(value->pGlobalRootSignature);
    }
}

void UnwrapStructObjects(D3D12_LOCAL_ROOT_SIGNATURE* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pLocalRootSignature = GetWrappedObject<ID3D12RootSignature>(value->pLocalRootSignature);
    }
}

void UnwrapStructObjects(D3D12_EXISTING_COLLECTION_DESC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pExistingCollection = GetWrappedObject<ID3D12StateObject>(value->pExistingCollection);
    }
}

void UnwrapStructObjects(D3D12_AUTO_BREADCRUMB_NODE* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pCommandList = GetWrappedObject<ID3D12GraphicsCommandList>(value->pCommandList);
        value->pCommandQueue = GetWrappedObject<ID3D12CommandQueue>(value->pCommandQueue);
        value->pNext = UnwrapStructPtrObjects(value->pNext, unwrap_memory);
    }
}

void UnwrapStructObjects(D3D12_AUTO_BREADCRUMB_NODE1* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pCommandList = GetWrappedObject<ID3D12GraphicsCommandList>(value->pCommandList);
        value->pCommandQueue = GetWrappedObject<ID3D12CommandQueue>(value->pCommandQueue);
        value->pNext = UnwrapStructPtrObjects(value->pNext, unwrap_memory);
    }
}

void UnwrapStructObjects(D3D12_DRED_ALLOCATION_NODE1* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pObject = GetWrappedObject<IUnknown>(value->pObject);
        value->pNext = UnwrapStructPtrObjects(value->pNext, unwrap_memory);
    }
}

void UnwrapStructObjects(D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pSrcResource = GetWrappedObject<ID3D12Resource>(value->pSrcResource);
        value->pDstResource = GetWrappedObject<ID3D12Resource>(value->pDstResource);
    }
}

void UnwrapStructObjects(D3D12_RENDER_PASS_RENDER_TARGET_DESC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructObjects(&value->cpuDescriptor, unwrap_memory);
        UnwrapStructObjects(&value->EndingAccess, unwrap_memory);
    }
}

void UnwrapStructObjects(D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructObjects(&value->cpuDescriptor, unwrap_memory);
        UnwrapStructObjects(&value->DepthEndingAccess, unwrap_memory);
        UnwrapStructObjects(&value->StencilEndingAccess, unwrap_memory);
    }
}

void UnwrapStructObjects(D3D12_TEXTURE_BARRIER* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pResource = GetWrappedObject<ID3D12Resource>(value->pResource);
    }
}

void UnwrapStructObjects(D3D12_BUFFER_BARRIER* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pResource = GetWrappedObject<ID3D12Resource>(value->pResource);
    }
}

void UnwrapStructObjects(D3D11_VIDEO_DECODER_EXTENSION* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->ppResourceList = UnwrapObjects<ID3D11Resource>(value->ppResourceList, value->ResourceCount, unwrap_memory);
    }
}

void UnwrapStructObjects(D3D11_VIDEO_PROCESSOR_STREAM* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->ppPastSurfaces = UnwrapObjects<ID3D11VideoProcessorInputView>(value->ppPastSurfaces, value->PastFrames, unwrap_memory);
        value->pInputSurface = GetWrappedObject<ID3D11VideoProcessorInputView>(value->pInputSurface);
        value->ppFutureSurfaces = UnwrapObjects<ID3D11VideoProcessorInputView>(value->ppFutureSurfaces, value->FutureFrames, unwrap_memory);
        value->ppPastSurfacesRight = UnwrapObjects<ID3D11VideoProcessorInputView>(value->ppPastSurfacesRight, value->PastFrames, unwrap_memory);
        value->pInputSurfaceRight = GetWrappedObject<ID3D11VideoProcessorInputView>(value->pInputSurfaceRight);
        value->ppFutureSurfacesRight = UnwrapObjects<ID3D11VideoProcessorInputView>(value->ppFutureSurfacesRight, value->FutureFrames, unwrap_memory);
    }
}

void UnwrapStructObjects(D3D11_VIDEO_DECODER_BEGIN_FRAME_CRYPTO_SESSION* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->pCryptoSession = GetWrappedObject<ID3D11CryptoSession>(value->pCryptoSession);
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
