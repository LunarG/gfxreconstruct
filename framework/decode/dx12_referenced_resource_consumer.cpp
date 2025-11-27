/*
** Copyright (c) 2022 Advanced Micro Devices, Inc. All rights reserved.
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

#include "decode/dx12_referenced_resource_consumer.h"

#include "decode/custom_dx12_struct_object_mappers.h"
#include "generated/generated_dx12_struct_object_mappers.h"
GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void Dx12ReferencedResourceConsumer::Process_IDXGISwapChain_GetBuffer(const ApiCallInfo&           call_info,
                                                                      format::HandleId             object_id,
                                                                      HRESULT                      return_value,
                                                                      UINT                         Buffer,
                                                                      Decoded_GUID                 riid,
                                                                      HandlePointerDecoder<void*>* ppSurface)
{
    format::HandleId* handle_ptr = const_cast<gfxrecon::format::HandleId*>(ppSurface->GetPointer());
    table_.AddResource(*handle_ptr);
}

void Dx12ReferencedResourceConsumer::Process_ID3D12Device_CreateCommittedResource(
    const ApiCallInfo&                                   call_info,
    format::HandleId                                     object_id,
    HRESULT                                              return_value,
    StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
    D3D12_HEAP_FLAGS                                     HeapFlags,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>*   pDesc,
    D3D12_RESOURCE_STATES                                InitialResourceState,
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>*     pOptimizedClearValue,
    Decoded_GUID                                         riidResource,
    HandlePointerDecoder<void*>*                         ppvResource)
{
    format::HandleId* handle_ptr = const_cast<gfxrecon::format::HandleId*>(ppvResource->GetPointer());
    table_.AddResource(*handle_ptr);
    if (pDesc->GetPointer()->Dimension == D3D12_RESOURCE_DIMENSION_BUFFER)
    {
        buffer_resource_infos_.insert({ *handle_ptr, { pDesc->GetPointer()->Width, kNullGpuAddress } });
    }
}

void Dx12ReferencedResourceConsumer::Process_ID3D12Device8_CreateCommittedResource2(
    const ApiCallInfo&                                   call_info,
    format::HandleId                                     object_id,
    HRESULT                                              return_value,
    StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
    D3D12_HEAP_FLAGS                                     HeapFlags,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1>*  pDesc,
    D3D12_RESOURCE_STATES                                InitialResourceState,
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>*     pOptimizedClearValue,
    format::HandleId                                     pProtectedSession,
    Decoded_GUID                                         riidResource,
    HandlePointerDecoder<void*>*                         ppvResource)
{
    format::HandleId* handle_ptr = const_cast<gfxrecon::format::HandleId*>(ppvResource->GetPointer());
    table_.AddResource(*handle_ptr);
    if (pDesc->GetPointer()->Dimension == D3D12_RESOURCE_DIMENSION_BUFFER)
    {
        buffer_resource_infos_.insert({ *handle_ptr, { pDesc->GetPointer()->Width, kNullGpuAddress } });
    }
}

void Dx12ReferencedResourceConsumer::Process_ID3D12Device_CreatePlacedResource(
    const ApiCallInfo&                                 call_info,
    format::HandleId                                   object_id,
    HRESULT                                            return_value,
    format::HandleId                                   pHeap,
    UINT64                                             HeapOffset,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
    D3D12_RESOURCE_STATES                              InitialState,
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>*   pOptimizedClearValue,
    Decoded_GUID                                       riid,
    HandlePointerDecoder<void*>*                       ppvResource)
{

    format::HandleId* handle_ptr = const_cast<gfxrecon::format::HandleId*>(ppvResource->GetPointer());
    table_.AddResource(*handle_ptr);
    if (pDesc->GetPointer()->Dimension == D3D12_RESOURCE_DIMENSION_BUFFER)
    {
        buffer_resource_infos_.insert({ *handle_ptr, { pDesc->GetPointer()->Width, kNullGpuAddress } });
    }
}

void Dx12ReferencedResourceConsumer::Process_ID3D12Device_CreateRootSignature(
    const ApiCallInfo&           call_info,
    format::HandleId             object_id,
    HRESULT                      return_value,
    UINT                         nodeMask,
    PointerDecoder<uint8_t>*     pBlobWithRootSignature,
    SIZE_T                       blobLengthInBytes,
    Decoded_GUID                 riid,
    HandlePointerDecoder<void*>* ppvRootSignature)
{
    graphics::dx12::ID3D12VersionedRootSignatureDeserializerComPtr root_sig_deserializer{ nullptr };
    HRESULT result = D3D12CreateVersionedRootSignatureDeserializer(
        pBlobWithRootSignature->GetPointer(), blobLengthInBytes, IID_PPV_ARGS(&root_sig_deserializer));

    auto              unconverted_desc = root_sig_deserializer->GetUnconvertedRootSignatureDesc();
    RootSignatureInfo root_sig_info;

    const D3D12_VERSIONED_ROOT_SIGNATURE_DESC* root_sig_desc = nullptr;
    root_sig_deserializer->GetRootSignatureDescAtVersion(D3D_ROOT_SIGNATURE_VERSION_1_2, &root_sig_desc);

    for (UINT i = 0; i < root_sig_desc->Desc_1_2.NumParameters; ++i)
    {
        UINT        next_offset = 0;
        const auto& param       = root_sig_desc->Desc_1_2.pParameters[i];
        if (param.ParameterType == D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE)
        {
            for (UINT j = 0; j < param.DescriptorTable.NumDescriptorRanges; ++j)
            {
                const auto& range = param.DescriptorTable.pDescriptorRanges[j];
                UINT begin_offset = (range.OffsetInDescriptorsFromTableStart == D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND)
                                        ? next_offset
                                        : range.OffsetInDescriptorsFromTableStart;
                next_offset       = begin_offset + range.NumDescriptors;
                root_sig_info.root_parameters.push_back(DescriptorRange{ i, begin_offset, range.NumDescriptors });
            }
        }
        else if (param.ParameterType == D3D12_ROOT_PARAMETER_TYPE_CBV)
        {
            root_sig_info.root_parameters.push_back(CBV{ i });
        }
        else if (param.ParameterType == D3D12_ROOT_PARAMETER_TYPE_SRV)
        {
            root_sig_info.root_parameters.push_back(SRV{ i });
        }
        else
        {
            root_sig_info.root_parameters.push_back({});
        }
    }
    root_signature_infos_.insert({ ppvRootSignature->GetPointer()[0], root_sig_info });
}

void Dx12ReferencedResourceConsumer::Process_ID3D12Device_CreateDescriptorHeap(
    const ApiCallInfo&                                        call_info,
    format::HandleId                                          object_id,
    HRESULT                                                   return_value,
    StructPointerDecoder<Decoded_D3D12_DESCRIPTOR_HEAP_DESC>* pDescriptorHeapDesc,
    Decoded_GUID                                              riid,
    HandlePointerDecoder<void*>*                              ppvHeap)
{
    auto handle_id = *ppvHeap->GetPointer();
    descriptor_heap_infos_.insert({ handle_id, { pDescriptorHeapDesc->GetPointer()->NumDescriptors, 0 } });
}

void Dx12ReferencedResourceConsumer::Process_ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart(
    const ApiCallInfo& call_info, format::HandleId object_id, Decoded_D3D12_GPU_DESCRIPTOR_HANDLE return_value)
{
    auto desc_heap_info = descriptor_heap_infos_.find(object_id);
    if (desc_heap_info != descriptor_heap_infos_.end())
    {
        desc_heap_info->second.start_handle = *(return_value.decoded_value);
    }
}

void Dx12ReferencedResourceConsumer::Process_ID3D12Resource_GetGPUVirtualAddress(const ApiCallInfo&        call_info,
                                                                                 format::HandleId          object_id,
                                                                                 D3D12_GPU_VIRTUAL_ADDRESS return_value)
{
    auto buffer_info = buffer_resource_infos_.find(object_id);
    if (buffer_info != buffer_resource_infos_.end())
    {
        buffer_info->second.gpu_address = return_value;
    }
}

void Dx12ReferencedResourceConsumer::Process_ID3D12Device_GetDescriptorHandleIncrementSize(
    const ApiCallInfo&         call_info,
    format::HandleId           object_id,
    UINT                       return_value,
    D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapType)
{
    if (DescriptorHeapType == D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV)
        cbv_srv_uav_handle_size_ = return_value;
}

void Dx12ReferencedResourceConsumer::Process_ID3D12Device_CreateShaderResourceView(
    const ApiCallInfo&                                             call_info,
    format::HandleId                                               object_id,
    format::HandleId                                               pResource,
    StructPointerDecoder<Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC>* pDesc,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE                            DestDescriptor)
{
    auto desc_heap_info = descriptor_heap_infos_.find(DestDescriptor.heap_id);
    if (desc_heap_info != descriptor_heap_infos_.end())
    {
        desc_heap_info->second.resources[DestDescriptor.index] = pResource;
    }
}

void Dx12ReferencedResourceConsumer::Process_ID3D12Device_CreateDepthStencilView(
    const ApiCallInfo&                                           call_info,
    format::HandleId                                             object_id,
    format::HandleId                                             pResource,
    StructPointerDecoder<Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC>* pDesc,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE                          DestDescriptor)
{
    auto desc_heap_info = descriptor_heap_infos_.find(DestDescriptor.heap_id);
    if (desc_heap_info != descriptor_heap_infos_.end())
    {
        desc_heap_info->second.resources[DestDescriptor.index] = pResource;
    }
}

void Dx12ReferencedResourceConsumer::Process_ID3D12Device_CreateRenderTargetView(
    const ApiCallInfo&                                           call_info,
    format::HandleId                                             object_id,
    format::HandleId                                             pResource,
    StructPointerDecoder<Decoded_D3D12_RENDER_TARGET_VIEW_DESC>* pDesc,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE                          DestDescriptor)
{
    auto desc_heap_info = descriptor_heap_infos_.find(DestDescriptor.heap_id);
    if (desc_heap_info != descriptor_heap_infos_.end())
    {
        desc_heap_info->second.resources[DestDescriptor.index] = pResource;
    }
}

void Dx12ReferencedResourceConsumer::Process_ID3D12Device_CopyDescriptorsSimple(
    const ApiCallInfo&                  call_info,
    format::HandleId                    object_id,
    UINT                                NumDescriptors,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptorRangeStart,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE SrcDescriptorRangeStart,
    D3D12_DESCRIPTOR_HEAP_TYPE          DescriptorHeapsType)
{
    auto dest_heap_info = descriptor_heap_infos_.find(DestDescriptorRangeStart.heap_id);
    auto src_heap_info  = descriptor_heap_infos_.find(SrcDescriptorRangeStart.heap_id);

    if ((src_heap_info != descriptor_heap_infos_.end()) && (dest_heap_info != descriptor_heap_infos_.end()))
    {
        for (UINT i = 0; i < NumDescriptors; ++i)
        {
            dest_heap_info->second.resources[DestDescriptorRangeStart.index + i] =
                src_heap_info->second.resources[SrcDescriptorRangeStart.index + i];
        }
    }
}

void Dx12ReferencedResourceConsumer::Process_ID3D12Device_CopyDescriptors(
    const ApiCallInfo&                                         call_info,
    format::HandleId                                           object_id,
    UINT                                                       NumDestDescriptorRanges,
    StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pDestDescriptorRangeStarts,
    PointerDecoder<UINT>*                                      pDestDescriptorRangeSizes,
    UINT                                                       NumSrcDescriptorRanges,
    StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pSrcDescriptorRangeStarts,
    PointerDecoder<UINT>*                                      pSrcDescriptorRangeSizes,
    D3D12_DESCRIPTOR_HEAP_TYPE                                 DescriptorHeapsType)
{
    UINT src_range     = 0;
    UINT src_range_idx = 0;
    for (UINT dest_range = 0; dest_range < NumDestDescriptorRanges; ++dest_range)
    {
        auto dest_heap      = pDestDescriptorRangeStarts->GetMetaStructPointer()[dest_range].heap_id;
        auto dest_heap_info = descriptor_heap_infos_.find(dest_heap);

        for (UINT dest_range_idx = 0; (pDestDescriptorRangeSizes->IsNull() && dest_range_idx < 1) ||
                                      dest_range_idx < pDestDescriptorRangeSizes->GetPointer()[dest_range];
             ++dest_range_idx)
        {
            auto dest_index = pDestDescriptorRangeStarts->GetMetaStructPointer()[dest_range].index + dest_range_idx;

            auto src_heap      = pSrcDescriptorRangeStarts->GetMetaStructPointer()[src_range].heap_id;
            auto src_heap_info = descriptor_heap_infos_.find(src_heap);

            auto src_index = pSrcDescriptorRangeStarts->GetMetaStructPointer()[src_range].index + src_range_idx;

            if ((src_heap_info != descriptor_heap_infos_.end()) && (dest_heap_info != descriptor_heap_infos_.end()))
            {
                dest_heap_info->second.resources[dest_index] = src_heap_info->second.resources[src_index];
            }

            src_range_idx++;
            if (pSrcDescriptorRangeSizes->IsNull() ||
                src_range_idx >= pSrcDescriptorRangeSizes->GetPointer()[src_range])
            {
                src_range++;
                src_range_idx = 0;
            }
        }
    }
}

void Dx12ReferencedResourceConsumer::Process_ID3D12Device_CreateCommandList(const ApiCallInfo&      call_info,
                                                                            format::HandleId        object_id,
                                                                            HRESULT                 return_value,
                                                                            UINT                    nodeMask,
                                                                            D3D12_COMMAND_LIST_TYPE type,
                                                                            format::HandleId        pCommandAllocator,
                                                                            format::HandleId        pInitialState,
                                                                            Decoded_GUID            riid,
                                                                            HandlePointerDecoder<void*>* ppCommandList)
{
    table_.AddUser(pCommandAllocator, *ppCommandList->GetPointer());
}

void Dx12ReferencedResourceConsumer::Process_ID3D12Device4_CreateCommandList1(
    const ApiCallInfo&           call_info,
    format::HandleId             object_id,
    HRESULT                      return_value,
    UINT                         nodeMask,
    D3D12_COMMAND_LIST_TYPE      type,
    D3D12_COMMAND_LIST_FLAGS     flags,
    Decoded_GUID                 riid,
    HandlePointerDecoder<void*>* ppCommandList)
{
    table_.AddUser(*ppCommandList->GetPointer(), *ppCommandList->GetPointer());
}

void Dx12ReferencedResourceConsumer::Process_ID3D12GraphicsCommandList_CopyTextureRegion(
    const ApiCallInfo&                                         call_info,
    format::HandleId                                           object_id,
    StructPointerDecoder<Decoded_D3D12_TEXTURE_COPY_LOCATION>* pDst,
    UINT                                                       DstX,
    UINT                                                       DstY,
    UINT                                                       DstZ,
    StructPointerDecoder<Decoded_D3D12_TEXTURE_COPY_LOCATION>* pSrc,
    StructPointerDecoder<Decoded_D3D12_BOX>*                   pSrcBox)
{
    if (!pSrc->IsNull())
    {
        table_.AddResourceToUser(object_id, pSrc->GetMetaStructPointer()->pResource);
    }
    if (!pDst->IsNull())
    {
        table_.AddResourceToUser(object_id, pDst->GetMetaStructPointer()->pResource);
    }
}

void Dx12ReferencedResourceConsumer::Process_ID3D12GraphicsCommandList_CopyBufferRegion(const ApiCallInfo& call_info,
                                                                                        format::HandleId   object_id,
                                                                                        format::HandleId   pDstBuffer,
                                                                                        UINT64             DstOffset,
                                                                                        format::HandleId   pSrcBuffer,
                                                                                        UINT64             SrcOffset,
                                                                                        UINT64             NumBytes)
{
    table_.AddResourceToUser(object_id, pSrcBuffer);
    table_.AddResourceToUser(object_id, pDstBuffer);
}

format::HandleId
Dx12ReferencedResourceConsumer::GetResourceIDForBufferLocation(D3D12_GPU_VIRTUAL_ADDRESS buffer_location)
{
    for (const auto& [id, info] : buffer_resource_infos_)
    {
        if (buffer_location >= info.gpu_address && buffer_location < (info.gpu_address + info.size))
        {
            return id;
        }
    }
    return format::kNullHandleId;
}

void Dx12ReferencedResourceConsumer::Process_ID3D12Device_CreateConstantBufferView(
    const ApiCallInfo&                                             call_info,
    format::HandleId                                               object_id,
    StructPointerDecoder<Decoded_D3D12_CONSTANT_BUFFER_VIEW_DESC>* pDesc,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE                            DestDescriptor)
{
    auto resource_id = GetResourceIDForBufferLocation(pDesc->GetPointer()->BufferLocation);
    if (resource_id != format::kNullHandleId)
    {
        auto desc_heap_info = descriptor_heap_infos_.find(DestDescriptor.heap_id);
        if (desc_heap_info != descriptor_heap_infos_.end())
        {
            desc_heap_info->second.resources[DestDescriptor.index] = resource_id;
        }
    }
}

void Dx12ReferencedResourceConsumer::Process_ID3D12GraphicsCommandList_IASetIndexBuffer(
    const ApiCallInfo&                                     call_info,
    format::HandleId                                       object_id,
    StructPointerDecoder<Decoded_D3D12_INDEX_BUFFER_VIEW>* pView)
{
    auto& index_buffer_resource = command_list_infos_[object_id].index_buffer_resource;
    index_buffer_resource       = GetResourceIDForBufferLocation(pView->GetPointer()->BufferLocation);
}

void Dx12ReferencedResourceConsumer::Process_ID3D12GraphicsCommandList_IASetVertexBuffers(
    const ApiCallInfo&                                      call_info,
    format::HandleId                                        object_id,
    UINT                                                    StartSlot,
    UINT                                                    NumViews,
    StructPointerDecoder<Decoded_D3D12_VERTEX_BUFFER_VIEW>* pViews)
{
    auto& vertex_buffer_resources = command_list_infos_[object_id].vertex_buffer_resources;
    if (StartSlot + NumViews > vertex_buffer_resources.size())
    {
        vertex_buffer_resources.resize(StartSlot + NumViews, format::kNullHandleId);
    }
    for (UINT i = 0; i < NumViews; ++i)
    {
        vertex_buffer_resources[StartSlot + i] = GetResourceIDForBufferLocation(pViews->GetPointer()[i].BufferLocation);
    }
}

void Dx12ReferencedResourceConsumer::Process_ID3D12GraphicsCommandList_SetDescriptorHeaps(
    const ApiCallInfo&                           call_info,
    format::HandleId                             object_id,
    UINT                                         NumDescriptorHeaps,
    HandlePointerDecoder<ID3D12DescriptorHeap*>* ppDescriptorHeaps)
{
    // TODO: Should I be using this instead of pointer search?
    for (UINT i = 0; i < NumDescriptorHeaps; ++i)
    {
        format::HandleId desc_heap_id = ppDescriptorHeaps->GetPointer()[i];
    }
}

void Dx12ReferencedResourceConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable(
    const ApiCallInfo&                  call_info,
    format::HandleId                    object_id,
    UINT                                RootParameterIndex,
    Decoded_D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor)
{
    auto& root_descriptor_tables = command_list_infos_[object_id].graphics_root_descriptor_tables;
    if (root_descriptor_tables.size() <= RootParameterIndex)
    {
        root_descriptor_tables.resize(RootParameterIndex + 1);
    }
    root_descriptor_tables[RootParameterIndex] = *BaseDescriptor.decoded_value;
}

void Dx12ReferencedResourceConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable(
    const ApiCallInfo&                  call_info,
    format::HandleId                    object_id,
    UINT                                RootParameterIndex,
    Decoded_D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor)
{
    auto& root_descriptor_tables = command_list_infos_[object_id].compute_root_descriptor_tables;
    if (root_descriptor_tables.size() <= RootParameterIndex)
    {
        root_descriptor_tables.resize(RootParameterIndex + 1);
    }
    root_descriptor_tables[RootParameterIndex] = *BaseDescriptor.decoded_value;
}

void Dx12ReferencedResourceConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView(
    const ApiCallInfo&        call_info,
    format::HandleId          object_id,
    UINT                      RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    auto& root_cbvs = command_list_infos_[object_id].graphics_root_cbvs;
    if (root_cbvs.size() <= RootParameterIndex)
    {
        root_cbvs.resize(RootParameterIndex + 1);
    }
    root_cbvs[RootParameterIndex] = BufferLocation;
}

void Dx12ReferencedResourceConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootConstantBufferView(
    const ApiCallInfo&        call_info,
    format::HandleId          object_id,
    UINT                      RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    auto& root_cbvs = command_list_infos_[object_id].compute_root_cbvs;
    if (root_cbvs.size() <= RootParameterIndex)
    {
        root_cbvs.resize(RootParameterIndex + 1);
    }
    root_cbvs[RootParameterIndex] = BufferLocation;
}

void Dx12ReferencedResourceConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView(
    const ApiCallInfo&        call_info,
    format::HandleId          object_id,
    UINT                      RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    auto& root_srvs = command_list_infos_[object_id].graphics_root_srvs;
    if (root_srvs.size() <= RootParameterIndex)
    {
        root_srvs.resize(RootParameterIndex + 1);
    }
    root_srvs[RootParameterIndex] = BufferLocation;
}

void Dx12ReferencedResourceConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView(
    const ApiCallInfo&        call_info,
    format::HandleId          object_id,
    UINT                      RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    auto& root_srvs = command_list_infos_[object_id].compute_root_srvs;
    if (root_srvs.size() <= RootParameterIndex)
    {
        root_srvs.resize(RootParameterIndex + 1);
    }
    root_srvs[RootParameterIndex] = BufferLocation;
}

void Dx12ReferencedResourceConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootSignature(
    const ApiCallInfo& call_info, format::HandleId object_id, format::HandleId pRootSignature)
{
    command_list_infos_[object_id].graphics_root_signature = pRootSignature;
}

void Dx12ReferencedResourceConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootSignature(
    const ApiCallInfo& call_info, format::HandleId object_id, format::HandleId pRootSignature)
{
    command_list_infos_[object_id].compute_root_signature = pRootSignature;
}

void Dx12ReferencedResourceConsumer::Process_ID3D12GraphicsCommandList_OMSetRenderTargets(
    const ApiCallInfo&                                         call_info,
    format::HandleId                                           object_id,
    UINT                                                       NumRenderTargetDescriptors,
    StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pRenderTargetDescriptors,
    BOOL                                                       RTsSingleHandleToDescriptorRange,
    StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pDepthStencilDescriptor)
{
    auto& cmd_list_info = command_list_infos_[object_id];
    if (!pDepthStencilDescriptor->IsNull())
    {
        cmd_list_info.dsv_descriptor = *pDepthStencilDescriptor->GetMetaStructPointer();
    }
    cmd_list_info.rtv_descriptors.resize(NumRenderTargetDescriptors);
    if (RTsSingleHandleToDescriptorRange)
    {
        auto rtv_descriptor = pRenderTargetDescriptors->GetMetaStructPointer()[0];
        for (UINT i = 0; i < NumRenderTargetDescriptors; ++i)
        {
            cmd_list_info.rtv_descriptors[i] = rtv_descriptor;
            rtv_descriptor.index += 1;
        }
    }
    else
    {
        for (UINT i = 0; i < NumRenderTargetDescriptors; ++i)
        {
            cmd_list_info.rtv_descriptors[i] = pRenderTargetDescriptors->GetMetaStructPointer()[i];
        }
    }
}

void Dx12ReferencedResourceConsumer::CommandListTrackDrawResources(format::HandleId command_list_id, bool is_graphics)
{
    auto cmd_list_info = command_list_infos_.find(command_list_id);
    if (cmd_list_info != command_list_infos_.end())
    {
        auto root_sig_info = root_signature_infos_.find(is_graphics ? cmd_list_info->second.graphics_root_signature
                                                                    : cmd_list_info->second.compute_root_signature);
        GFXRECON_ASSERT(root_sig_info != root_signature_infos_.end());
        if (root_sig_info != root_signature_infos_.end())
        {
            // root parameters
            for (const auto& param : root_sig_info->second.root_parameters)
            {
                if (const auto* range = std::get_if<DescriptorRange>(&param))
                {
                    auto& root_descriptor_tables = is_graphics ? cmd_list_info->second.graphics_root_descriptor_tables
                                                               : cmd_list_info->second.compute_root_descriptor_tables;
                    if (range->root_parameter_index >= root_descriptor_tables.size())
                        continue;

                    format::HandleId    desc_heap_id   = format::kNullHandleId;
                    DescriptorHeapInfo* desc_heap_info = nullptr;
                    for (auto& [heap_id, heap_info] : descriptor_heap_infos_)
                    {
                        if ((root_descriptor_tables[range->root_parameter_index].ptr >= heap_info.start_handle.ptr) &&
                            (root_descriptor_tables[range->root_parameter_index].ptr <
                             (heap_info.start_handle.ptr + heap_info.num_descriptors * cbv_srv_uav_handle_size_)))
                        {
                            desc_heap_id   = heap_id;
                            desc_heap_info = &heap_info;
                            break;
                        }
                    }

                    if (desc_heap_info == nullptr)
                    {
                        GFXRECON_LOG_WARNING("Could not find heap for descriptor table root parameter %d",
                                             range->root_parameter_index);
                        continue;
                    }

                    UINT64 heap_index =
                        (root_descriptor_tables[range->root_parameter_index].ptr - desc_heap_info->start_handle.ptr) /
                        cbv_srv_uav_handle_size_;

                    for (UINT i = 0; i < range->num_descriptors; ++i)
                    {
                        auto res_it = desc_heap_info->resources.find(heap_index + range->offset + i);
                        if (res_it != desc_heap_info->resources.end())
                        {
                            table_.AddResourceToUser(command_list_id, res_it->second);
                        }
                    }
                }
                else if (const auto* cbv = std::get_if<CBV>(&param))
                {
                    // CBV
                    auto& root_cbvs = is_graphics ? cmd_list_info->second.graphics_root_cbvs
                                                  : cmd_list_info->second.compute_root_cbvs;
                    if (cbv->root_parameter_index >= root_cbvs.size())
                        continue;

                    auto resource = GetResourceIDForBufferLocation(root_cbvs[cbv->root_parameter_index]);
                    if (resource == format::kNullHandleId)
                    {
                        GFXRECON_LOG_WARNING("Could not find buffer for CBV root parameter %d",
                                             cbv->root_parameter_index);
                        continue;
                    }

                    table_.AddResourceToUser(command_list_id, resource);
                }
                else if (const auto* srv = std::get_if<SRV>(&param))
                {
                    // SRV
                    auto& root_srvs = is_graphics ? cmd_list_info->second.graphics_root_srvs
                                                  : cmd_list_info->second.compute_root_srvs;
                    if (srv->root_parameter_index >= root_srvs.size())
                        continue;

                    auto resource = GetResourceIDForBufferLocation(root_srvs[srv->root_parameter_index]);
                    if (resource == format::kNullHandleId)
                    {
                        GFXRECON_LOG_WARNING("Could not find buffer for SRV root parameter %d",
                                             srv->root_parameter_index);
                        continue;
                    }

                    table_.AddResourceToUser(command_list_id, resource);
                }
            }

            if (is_graphics)
            {
                // index buffer
                if (cmd_list_info->second.index_buffer_resource != format::kNullHandleId)
                {
                    table_.AddResourceToUser(command_list_id, cmd_list_info->second.index_buffer_resource);
                }

                // vertex buffers
                for (auto vb_res_id : cmd_list_info->second.vertex_buffer_resources)
                {
                    if (vb_res_id != format::kNullHandleId)
                    {
                        table_.AddResourceToUser(command_list_id, vb_res_id);
                    }
                }

                // dsv
                const auto& dsv_heap = descriptor_heap_infos_.find(cmd_list_info->second.dsv_descriptor.heap_id);
                if (dsv_heap != descriptor_heap_infos_.end())
                {
                    auto dsv_it = dsv_heap->second.resources.find(cmd_list_info->second.dsv_descriptor.index);
                    if (dsv_it != dsv_heap->second.resources.end())
                    {
                        table_.AddResourceToUser(command_list_id, dsv_it->second);
                    }
                }

                // rtvs
                for (auto& rtv_desc : cmd_list_info->second.rtv_descriptors)
                {
                    const auto& rtv_heap = descriptor_heap_infos_.find(rtv_desc.heap_id);
                    if (rtv_heap != descriptor_heap_infos_.end())
                    {
                        auto rtv_it = rtv_heap->second.resources.find(rtv_desc.index);
                        if (rtv_it != rtv_heap->second.resources.end())
                        {
                            table_.AddResourceToUser(command_list_id, rtv_it->second);
                        }
                    }
                }
            }
        }
    }
}

void Dx12ReferencedResourceConsumer::Process_ID3D12GraphicsCommandList_DrawIndexedInstanced(
    const ApiCallInfo& call_info,
    format::HandleId   object_id,
    UINT               IndexCountPerInstance,
    UINT               InstanceCount,
    UINT               StartIndexLocation,
    INT                BaseVertexLocation,
    UINT               StartInstanceLocation)
{
    CommandListTrackDrawResources(object_id, true);
}

void Dx12ReferencedResourceConsumer::Process_ID3D12GraphicsCommandList_DrawInstanced(const ApiCallInfo& call_info,
                                                                                     format::HandleId   object_id,
                                                                                     UINT VertexCountPerInstance,
                                                                                     UINT InstanceCount,
                                                                                     UINT StartVertexLocation,
                                                                                     UINT StartInstanceLocation)
{
    CommandListTrackDrawResources(object_id, true);
}

void Dx12ReferencedResourceConsumer::Process_ID3D12GraphicsCommandList_Dispatch(const ApiCallInfo& call_info,
                                                                                format::HandleId   object_id,
                                                                                UINT               ThreadGroupCountX,
                                                                                UINT               ThreadGroupCountY,
                                                                                UINT               ThreadGroupCountZ)
{
    CommandListTrackDrawResources(object_id, false);
}

void Dx12ReferencedResourceConsumer::Process_ID3D12CommandQueue_ExecuteCommandLists(
    const ApiCallInfo&                        call_info,
    format::HandleId                          object_id,
    UINT                                      NumCommandLists,
    HandlePointerDecoder<ID3D12CommandList*>* ppCommandLists)
{
    for (UINT i = 0; i < NumCommandLists; ++i)
    {
        format::HandleId cmd_list_id       = ppCommandLists->GetPointer()[i];
        table_.ProcessUserSubmission(cmd_list_id);
    }
}

void Dx12ReferencedResourceConsumer::Process_ID3D12GraphicsCommandList_Reset(const ApiCallInfo& call_info,
                                                                             format::HandleId   object_id,
                                                                             HRESULT            return_value,
                                                                             format::HandleId   pAllocator,
                                                                             format::HandleId   pInitialState)
{
    table_.ResetUser(object_id);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)