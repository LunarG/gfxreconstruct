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
** This file is generated from dx12_struct_wrapper_body_generator.py.
**
*/

#include "generated/generated_dx12_struct_wrappers.h"

#include "generated/generated_dx12_wrapper_creators.h"
#include "util/defines.h"

#include <dxgiformat.h>
#include <d3d12.h>
#include <d3dcommon.h>
#include <d3d12sdklayers.h>
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

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void WrapStruct(const D3D12_GRAPHICS_PIPELINE_STATE_DESC* value)
{
    if(value->pRootSignature)
    {
        WrapObject(IID_ID3D12RootSignature, reinterpret_cast<void**>(value->pRootSignature), nullptr);
    }
}

void WrapStruct(const D3D12_COMPUTE_PIPELINE_STATE_DESC* value)
{
    if(value->pRootSignature)
    {
        WrapObject(IID_ID3D12RootSignature, reinterpret_cast<void**>(value->pRootSignature), nullptr);
    }
}

void WrapStruct(const D3D12_RESOURCE_TRANSITION_BARRIER* value)
{
    if(value->pResource)
    {
        WrapObject(IID_ID3D12Resource, reinterpret_cast<void**>(value->pResource), nullptr);
    }
}

void WrapStruct(const D3D12_RESOURCE_ALIASING_BARRIER* value)
{
    if(value->pResourceBefore)
    {
        WrapObject(IID_ID3D12Resource, reinterpret_cast<void**>(value->pResourceBefore), nullptr);
    }
    if(value->pResourceAfter)
    {
        WrapObject(IID_ID3D12Resource, reinterpret_cast<void**>(value->pResourceAfter), nullptr);
    }
}

void WrapStruct(const D3D12_RESOURCE_UAV_BARRIER* value)
{
    if(value->pResource)
    {
        WrapObject(IID_ID3D12Resource, reinterpret_cast<void**>(value->pResource), nullptr);
    }
}

void WrapStruct(const D3D12_TEXTURE_COPY_LOCATION* value)
{
    if(value->pResource)
    {
        WrapObject(IID_ID3D12Resource, reinterpret_cast<void**>(value->pResource), nullptr);
    }
}

void WrapStruct(const D3D12_GLOBAL_ROOT_SIGNATURE* value)
{
    if(value->pGlobalRootSignature)
    {
        WrapObject(IID_ID3D12RootSignature, reinterpret_cast<void**>(value->pGlobalRootSignature), nullptr);
    }
}

void WrapStruct(const D3D12_LOCAL_ROOT_SIGNATURE* value)
{
    if(value->pLocalRootSignature)
    {
        WrapObject(IID_ID3D12RootSignature, reinterpret_cast<void**>(value->pLocalRootSignature), nullptr);
    }
}

void WrapStruct(const D3D12_EXISTING_COLLECTION_DESC* value)
{
    if(value->pExistingCollection)
    {
        WrapObject(IID_ID3D12StateObject, reinterpret_cast<void**>(value->pExistingCollection), nullptr);
    }
}

void WrapStruct(const D3D12_AUTO_BREADCRUMB_NODE* value)
{
    if(value->pCommandList)
    {
        WrapObject(IID_ID3D12GraphicsCommandList, reinterpret_cast<void**>(value->pCommandList), nullptr);
    }
    if(value->pCommandQueue)
    {
        WrapObject(IID_ID3D12CommandQueue, reinterpret_cast<void**>(value->pCommandQueue), nullptr);
    }
}

void WrapStruct(const D3D12_AUTO_BREADCRUMB_NODE1* value)
{
    if(value->pCommandList)
    {
        WrapObject(IID_ID3D12GraphicsCommandList, reinterpret_cast<void**>(value->pCommandList), nullptr);
    }
    if(value->pCommandQueue)
    {
        WrapObject(IID_ID3D12CommandQueue, reinterpret_cast<void**>(value->pCommandQueue), nullptr);
    }
}

void WrapStruct(const D3D12_DEVICE_REMOVED_EXTENDED_DATA* value)
{
    if(value->pHeadAutoBreadcrumbNode)
    {
        WrapStruct(value->pHeadAutoBreadcrumbNode);
    }
}

void WrapStruct(const D3D12_DRED_ALLOCATION_NODE1* value)
{
    if(value->pObject)
    {
        WrapObject(IID_IUnknown, reinterpret_cast<void**>(&const_cast<IUnknown*>(value->pObject)), nullptr);
    }
}

void WrapStruct(const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT* value)
{
    if(value->pHeadAutoBreadcrumbNode)
    {
        WrapStruct(value->pHeadAutoBreadcrumbNode);
    }
}

void WrapStruct(const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1* value)
{
    if(value->pHeadAutoBreadcrumbNode)
    {
        WrapStruct(value->pHeadAutoBreadcrumbNode);
    }
}

void WrapStruct(const D3D12_DRED_PAGE_FAULT_OUTPUT1* value)
{
    if(value->pHeadExistingAllocationNode)
    {
        WrapStruct(value->pHeadExistingAllocationNode);
    }
    if(value->pHeadRecentFreedAllocationNode)
    {
        WrapStruct(value->pHeadRecentFreedAllocationNode);
    }
}

void WrapStruct(const D3D12_DRED_PAGE_FAULT_OUTPUT2* value)
{
    if(value->pHeadExistingAllocationNode)
    {
        WrapStruct(value->pHeadExistingAllocationNode);
    }
    if(value->pHeadRecentFreedAllocationNode)
    {
        WrapStruct(value->pHeadRecentFreedAllocationNode);
    }
}

void WrapStruct(const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS* value)
{
    if(value->pSrcResource)
    {
        WrapObject(IID_ID3D12Resource, reinterpret_cast<void**>(value->pSrcResource), nullptr);
    }
    if(value->pDstResource)
    {
        WrapObject(IID_ID3D12Resource, reinterpret_cast<void**>(value->pDstResource), nullptr);
    }
}

void WrapStruct(const D3D12_TEXTURE_BARRIER* value)
{
    if(value->pResource)
    {
        WrapObject(IID_ID3D12Resource, reinterpret_cast<void**>(value->pResource), nullptr);
    }
}

void WrapStruct(const D3D12_BUFFER_BARRIER* value)
{
    if(value->pResource)
    {
        WrapObject(IID_ID3D12Resource, reinterpret_cast<void**>(value->pResource), nullptr);
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
