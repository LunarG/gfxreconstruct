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
** This file is generated from dx12_struct_add_object_body_generator.py.
**
*/

#include "generated/generated_dx12_struct_add_objects.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
void StructAddObject(const StructPointerDecoder<Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC>* capture_value, const D3D12_GRAPHICS_PIPELINE_STATE_DESC* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pRootSignature && new_value->pRootSignature)
    {
        object_mapping::AddObject(&decoded_struct->pRootSignature, const_cast<ID3D12RootSignature**>(&new_value->pRootSignature), &object_info_table);
    }
}

void StructAddObject(const StructPointerDecoder<Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC>* capture_value, const D3D12_COMPUTE_PIPELINE_STATE_DESC* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pRootSignature && new_value->pRootSignature)
    {
        object_mapping::AddObject(&decoded_struct->pRootSignature, const_cast<ID3D12RootSignature**>(&new_value->pRootSignature), &object_info_table);
    }
}

void StructAddObject(const StructPointerDecoder<Decoded_D3D12_RESOURCE_TRANSITION_BARRIER>* capture_value, const D3D12_RESOURCE_TRANSITION_BARRIER* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pResource && new_value->pResource)
    {
        object_mapping::AddObject(&decoded_struct->pResource, const_cast<ID3D12Resource**>(&new_value->pResource), &object_info_table);
    }
}

void StructAddObject(const StructPointerDecoder<Decoded_D3D12_RESOURCE_ALIASING_BARRIER>* capture_value, const D3D12_RESOURCE_ALIASING_BARRIER* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pResourceBefore && new_value->pResourceBefore)
    {
        object_mapping::AddObject(&decoded_struct->pResourceBefore, const_cast<ID3D12Resource**>(&new_value->pResourceBefore), &object_info_table);
    }
    if(decoded_struct->pResourceAfter && new_value->pResourceAfter)
    {
        object_mapping::AddObject(&decoded_struct->pResourceAfter, const_cast<ID3D12Resource**>(&new_value->pResourceAfter), &object_info_table);
    }
}

void StructAddObject(const StructPointerDecoder<Decoded_D3D12_RESOURCE_UAV_BARRIER>* capture_value, const D3D12_RESOURCE_UAV_BARRIER* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pResource && new_value->pResource)
    {
        object_mapping::AddObject(&decoded_struct->pResource, const_cast<ID3D12Resource**>(&new_value->pResource), &object_info_table);
    }
}

void StructAddObject(const StructPointerDecoder<Decoded_D3D12_TEXTURE_COPY_LOCATION>* capture_value, const D3D12_TEXTURE_COPY_LOCATION* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pResource && new_value->pResource)
    {
        object_mapping::AddObject(&decoded_struct->pResource, const_cast<ID3D12Resource**>(&new_value->pResource), &object_info_table);
    }
}

void StructAddObject(const StructPointerDecoder<Decoded_D3D12_GLOBAL_ROOT_SIGNATURE>* capture_value, const D3D12_GLOBAL_ROOT_SIGNATURE* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pGlobalRootSignature && new_value->pGlobalRootSignature)
    {
        object_mapping::AddObject(&decoded_struct->pGlobalRootSignature, const_cast<ID3D12RootSignature**>(&new_value->pGlobalRootSignature), &object_info_table);
    }
}

void StructAddObject(const StructPointerDecoder<Decoded_D3D12_LOCAL_ROOT_SIGNATURE>* capture_value, const D3D12_LOCAL_ROOT_SIGNATURE* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pLocalRootSignature && new_value->pLocalRootSignature)
    {
        object_mapping::AddObject(&decoded_struct->pLocalRootSignature, const_cast<ID3D12RootSignature**>(&new_value->pLocalRootSignature), &object_info_table);
    }
}

void StructAddObject(const StructPointerDecoder<Decoded_D3D12_EXISTING_COLLECTION_DESC>* capture_value, const D3D12_EXISTING_COLLECTION_DESC* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pExistingCollection && new_value->pExistingCollection)
    {
        object_mapping::AddObject(&decoded_struct->pExistingCollection, const_cast<ID3D12StateObject**>(&new_value->pExistingCollection), &object_info_table);
    }
}

void StructAddObject(const StructPointerDecoder<Decoded_D3D12_AUTO_BREADCRUMB_NODE>* capture_value, const D3D12_AUTO_BREADCRUMB_NODE* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pCommandList && new_value->pCommandList)
    {
        object_mapping::AddObject(&decoded_struct->pCommandList, const_cast<ID3D12GraphicsCommandList**>(&new_value->pCommandList), &object_info_table);
    }
    if(decoded_struct->pCommandQueue && new_value->pCommandQueue)
    {
        object_mapping::AddObject(&decoded_struct->pCommandQueue, const_cast<ID3D12CommandQueue**>(&new_value->pCommandQueue), &object_info_table);
    }
}

void StructAddObject(const StructPointerDecoder<Decoded_D3D12_AUTO_BREADCRUMB_NODE1>* capture_value, const D3D12_AUTO_BREADCRUMB_NODE1* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pCommandList && new_value->pCommandList)
    {
        object_mapping::AddObject(&decoded_struct->pCommandList, const_cast<ID3D12GraphicsCommandList**>(&new_value->pCommandList), &object_info_table);
    }
    if(decoded_struct->pCommandQueue && new_value->pCommandQueue)
    {
        object_mapping::AddObject(&decoded_struct->pCommandQueue, const_cast<ID3D12CommandQueue**>(&new_value->pCommandQueue), &object_info_table);
    }
}

void StructAddObject(const StructPointerDecoder<Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA>* capture_value, const D3D12_DEVICE_REMOVED_EXTENDED_DATA* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pHeadAutoBreadcrumbNode && new_value->pHeadAutoBreadcrumbNode)
    {
        StructAddObject(decoded_struct->pHeadAutoBreadcrumbNode, new_value->pHeadAutoBreadcrumbNode, object_info_table);
    }
}

void StructAddObject(const StructPointerDecoder<Decoded_D3D12_DRED_ALLOCATION_NODE1>* capture_value, const D3D12_DRED_ALLOCATION_NODE1* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pObject && new_value->pObject)
    {
        object_mapping::AddObject(&decoded_struct->pObject, const_cast<IUnknown**>(&new_value->pObject), &object_info_table);
    }
}

void StructAddObject(const StructPointerDecoder<Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT>* capture_value, const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pHeadAutoBreadcrumbNode && new_value->pHeadAutoBreadcrumbNode)
    {
        StructAddObject(decoded_struct->pHeadAutoBreadcrumbNode, new_value->pHeadAutoBreadcrumbNode, object_info_table);
    }
}

void StructAddObject(const StructPointerDecoder<Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1>* capture_value, const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pHeadAutoBreadcrumbNode && new_value->pHeadAutoBreadcrumbNode)
    {
        StructAddObject(decoded_struct->pHeadAutoBreadcrumbNode, new_value->pHeadAutoBreadcrumbNode, object_info_table);
    }
}

void StructAddObject(const StructPointerDecoder<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1>* capture_value, const D3D12_DRED_PAGE_FAULT_OUTPUT1* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pHeadExistingAllocationNode && new_value->pHeadExistingAllocationNode)
    {
        StructAddObject(decoded_struct->pHeadExistingAllocationNode, new_value->pHeadExistingAllocationNode, object_info_table);
    }
    if(decoded_struct->pHeadRecentFreedAllocationNode && new_value->pHeadRecentFreedAllocationNode)
    {
        StructAddObject(decoded_struct->pHeadRecentFreedAllocationNode, new_value->pHeadRecentFreedAllocationNode, object_info_table);
    }
}

void StructAddObject(const StructPointerDecoder<Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS>* capture_value, const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS* new_value, Dx12ObjectInfoTable& object_info_table)
{
    auto decoded_struct = capture_value->GetMetaStructPointer();
    if(decoded_struct->pSrcResource && new_value->pSrcResource)
    {
        object_mapping::AddObject(&decoded_struct->pSrcResource, const_cast<ID3D12Resource**>(&new_value->pSrcResource), &object_info_table);
    }
    if(decoded_struct->pDstResource && new_value->pDstResource)
    {
        object_mapping::AddObject(&decoded_struct->pDstResource, const_cast<ID3D12Resource**>(&new_value->pDstResource), &object_info_table);
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
