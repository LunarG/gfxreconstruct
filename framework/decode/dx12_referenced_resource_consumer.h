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

#ifndef GFXRECON_DX12_REFERENCED_RESOURCE_CONSUMER_H
#define GFXRECON_DX12_REFERENCED_RESOURCE_CONSUMER_H

#include <variant>

#include "generated/generated_dx12_consumer.h"
#include "decode/referenced_resource_table.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class Dx12ReferencedResourceConsumer : public Dx12Consumer
{
  public:
    Dx12ReferencedResourceConsumer() {}
    virtual ~Dx12ReferencedResourceConsumer() override {}

    void GetReferencedResourceIds(std::unordered_set<format::HandleId>* referenced_ids,
                                  std::unordered_set<format::HandleId>* unreferenced_ids) const
    {
        table_.GetReferencedResourceIds(referenced_ids, unreferenced_ids);
    }

    virtual void Process_IDXGISwapChain_GetBuffer(const ApiCallInfo&           call_info,
                                                  format::HandleId             object_id,
                                                  HRESULT                      return_value,
                                                  UINT                         Buffer,
                                                  Decoded_GUID                 riid,
                                                  HandlePointerDecoder<void*>* ppSurface) override;

    virtual void
    Process_ID3D12Device_CreateCommittedResource(const ApiCallInfo&                                   call_info,
                                                 format::HandleId                                     object_id,
                                                 HRESULT                                              return_value,
                                                 StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
                                                 D3D12_HEAP_FLAGS                                     HeapFlags,
                                                 StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>*   pDesc,
                                                 D3D12_RESOURCE_STATES                            InitialResourceState,
                                                 StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
                                                 Decoded_GUID                                     riidResource,
                                                 HandlePointerDecoder<void*>*                     ppvResource) override;

    virtual void Process_ID3D12Device8_CreateCommittedResource2(
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
        HandlePointerDecoder<void*>*                         ppvResource) override;

    virtual void
    Process_ID3D12Device_CreatePlacedResource(const ApiCallInfo&                                 call_info,
                                              format::HandleId                                   object_id,
                                              HRESULT                                            return_value,
                                              format::HandleId                                   pHeap,
                                              UINT64                                             HeapOffset,
                                              StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
                                              D3D12_RESOURCE_STATES                              InitialState,
                                              StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>*   pOptimizedClearValue,
                                              Decoded_GUID                                       riid,
                                              HandlePointerDecoder<void*>*                       ppvResource) override;

    virtual void Process_ID3D12Device_CreateRootSignature(const ApiCallInfo&           call_info,
                                                          format::HandleId             object_id,
                                                          HRESULT                      return_value,
                                                          UINT                         nodeMask,
                                                          PointerDecoder<uint8_t>*     pBlobWithRootSignature,
                                                          SIZE_T                       blobLengthInBytes,
                                                          Decoded_GUID                 riid,
                                                          HandlePointerDecoder<void*>* ppvRootSignature);

    virtual void Process_ID3D12Device_CreateDescriptorHeap(
        const ApiCallInfo&                                        call_info,
        format::HandleId                                          object_id,
        HRESULT                                                   return_value,
        StructPointerDecoder<Decoded_D3D12_DESCRIPTOR_HEAP_DESC>* pDescriptorHeapDesc,
        Decoded_GUID                                              riid,
        HandlePointerDecoder<void*>*                              ppvHeap) override;

    virtual void Process_ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart(
        const ApiCallInfo&                  call_info,
        format::HandleId                    object_id,
        Decoded_D3D12_GPU_DESCRIPTOR_HANDLE return_value) override;

    virtual void Process_ID3D12Resource_GetGPUVirtualAddress(const ApiCallInfo&        call_info,
                                                             format::HandleId          object_id,
                                                             D3D12_GPU_VIRTUAL_ADDRESS return_value) override;

    virtual void
    Process_ID3D12Device_GetDescriptorHandleIncrementSize(const ApiCallInfo&         call_info,
                                                          format::HandleId           object_id,
                                                          UINT                       return_value,
                                                          D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapType) override;

    virtual void
    Process_ID3D12Device_CreateShaderResourceView(const ApiCallInfo& call_info,
                                                  format::HandleId   object_id,
                                                  format::HandleId   pResource,
                                                  StructPointerDecoder<Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC>* pDesc,
                                                  Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor) override;

    virtual void
    Process_ID3D12Device_CreateDepthStencilView(const ApiCallInfo&                                           call_info,
                                                format::HandleId                                             object_id,
                                                format::HandleId                                             pResource,
                                                StructPointerDecoder<Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC>* pDesc,
                                                Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor) override;

    virtual void
    Process_ID3D12Device_CreateRenderTargetView(const ApiCallInfo&                                           call_info,
                                                format::HandleId                                             object_id,
                                                format::HandleId                                             pResource,
                                                StructPointerDecoder<Decoded_D3D12_RENDER_TARGET_VIEW_DESC>* pDesc,
                                                Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor) override;

    format::HandleId GetResourceIDForBufferLocation(D3D12_GPU_VIRTUAL_ADDRESS buffer_location);

    virtual void
    Process_ID3D12Device_CreateConstantBufferView(const ApiCallInfo& call_info,
                                                  format::HandleId   object_id,
                                                  StructPointerDecoder<Decoded_D3D12_CONSTANT_BUFFER_VIEW_DESC>* pDesc,
                                                  Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor) override;

    virtual void
    Process_ID3D12Device_CopyDescriptorsSimple(const ApiCallInfo&                  call_info,
                                               format::HandleId                    object_id,
                                               UINT                                NumDescriptors,
                                               Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptorRangeStart,
                                               Decoded_D3D12_CPU_DESCRIPTOR_HANDLE SrcDescriptorRangeStart,
                                               D3D12_DESCRIPTOR_HEAP_TYPE          DescriptorHeapsType) override;

    virtual void Process_ID3D12Device_CopyDescriptors(
        const ApiCallInfo&                                         call_info,
        format::HandleId                                           object_id,
        UINT                                                       NumDestDescriptorRanges,
        StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pDestDescriptorRangeStarts,
        PointerDecoder<UINT>*                                      pDestDescriptorRangeSizes,
        UINT                                                       NumSrcDescriptorRanges,
        StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pSrcDescriptorRangeStarts,
        PointerDecoder<UINT>*                                      pSrcDescriptorRangeSizes,
        D3D12_DESCRIPTOR_HEAP_TYPE                                 DescriptorHeapsType) override;

    virtual void Process_ID3D12Device_CreateCommandList(const ApiCallInfo&           call_info,
                                                        format::HandleId             object_id,
                                                        HRESULT                      return_value,
                                                        UINT                         nodeMask,
                                                        D3D12_COMMAND_LIST_TYPE      type,
                                                        format::HandleId             pCommandAllocator,
                                                        format::HandleId             pInitialState,
                                                        Decoded_GUID                 riid,
                                                        HandlePointerDecoder<void*>* ppCommandList) override;

    virtual void Process_ID3D12Device4_CreateCommandList1(const ApiCallInfo&           call_info,
                                                          format::HandleId             object_id,
                                                          HRESULT                      return_value,
                                                          UINT                         nodeMask,
                                                          D3D12_COMMAND_LIST_TYPE      type,
                                                          D3D12_COMMAND_LIST_FLAGS     flags,
                                                          Decoded_GUID                 riid,
                                                          HandlePointerDecoder<void*>* ppCommandList) override;

    virtual void
    Process_ID3D12GraphicsCommandList_CopyTextureRegion(const ApiCallInfo& call_info,
                                                        format::HandleId   object_id,
                                                        StructPointerDecoder<Decoded_D3D12_TEXTURE_COPY_LOCATION>* pDst,
                                                        UINT                                                       DstX,
                                                        UINT                                                       DstY,
                                                        UINT                                                       DstZ,
                                                        StructPointerDecoder<Decoded_D3D12_TEXTURE_COPY_LOCATION>* pSrc,
                                                        StructPointerDecoder<Decoded_D3D12_BOX>* pSrcBox) override;

    virtual void Process_ID3D12GraphicsCommandList_CopyBufferRegion(const ApiCallInfo& call_info,
                                                                    format::HandleId   object_id,
                                                                    format::HandleId   pDstBuffer,
                                                                    UINT64             DstOffset,
                                                                    format::HandleId   pSrcBuffer,
                                                                    UINT64             SrcOffset,
                                                                    UINT64             NumBytes) override;

    virtual void Process_ID3D12GraphicsCommandList_IASetIndexBuffer(
        const ApiCallInfo&                                     call_info,
        format::HandleId                                       object_id,
        StructPointerDecoder<Decoded_D3D12_INDEX_BUFFER_VIEW>* pView) override;

    virtual void Process_ID3D12GraphicsCommandList_IASetVertexBuffers(
        const ApiCallInfo&                                      call_info,
        format::HandleId                                        object_id,
        UINT                                                    StartSlot,
        UINT                                                    NumViews,
        StructPointerDecoder<Decoded_D3D12_VERTEX_BUFFER_VIEW>* pViews) override;

    virtual void Process_ID3D12GraphicsCommandList_SetDescriptorHeaps(
        const ApiCallInfo&                           call_info,
        format::HandleId                             object_id,
        UINT                                         NumDescriptorHeaps,
        HandlePointerDecoder<ID3D12DescriptorHeap*>* ppDescriptorHeaps) override;

    virtual void Process_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable(
        const ApiCallInfo&                  call_info,
        format::HandleId                    object_id,
        UINT                                RootParameterIndex,
        Decoded_D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor) override;

    virtual void Process_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable(
        const ApiCallInfo&                  call_info,
        format::HandleId                    object_id,
        UINT                                RootParameterIndex,
        Decoded_D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor) override;

    virtual void Process_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView(
        const ApiCallInfo&        call_info,
        format::HandleId          object_id,
        UINT                      RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation) override;

    virtual void Process_ID3D12GraphicsCommandList_SetComputeRootConstantBufferView(
        const ApiCallInfo&        call_info,
        format::HandleId          object_id,
        UINT                      RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation) override;

    virtual void Process_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView(
        const ApiCallInfo&        call_info,
        format::HandleId          object_id,
        UINT                      RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation) override;

    virtual void Process_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView(
        const ApiCallInfo&        call_info,
        format::HandleId          object_id,
        UINT                      RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation) override;

    virtual void Process_ID3D12GraphicsCommandList_SetGraphicsRootSignature(const ApiCallInfo& call_info,
                                                                            format::HandleId   object_id,
                                                                            format::HandleId   pRootSignature) override;

    virtual void Process_ID3D12GraphicsCommandList_SetComputeRootSignature(const ApiCallInfo& call_info,
                                                                           format::HandleId   object_id,
                                                                           format::HandleId   pRootSignature) override;

    virtual void Process_ID3D12GraphicsCommandList_OMSetRenderTargets(
        const ApiCallInfo&                                         call_info,
        format::HandleId                                           object_id,
        UINT                                                       NumRenderTargetDescriptors,
        StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pRenderTargetDescriptors,
        BOOL                                                       RTsSingleHandleToDescriptorRange,
        StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pDepthStencilDescriptor) override;

    void CommandListTrackDrawResources(format::HandleId command_list_id, bool is_graphics);

    virtual void Process_ID3D12GraphicsCommandList_DrawIndexedInstanced(const ApiCallInfo& call_info,
                                                                        format::HandleId   object_id,
                                                                        UINT               IndexCountPerInstance,
                                                                        UINT               InstanceCount,
                                                                        UINT               StartIndexLocation,
                                                                        INT                BaseVertexLocation,
                                                                        UINT StartInstanceLocation) override;

    virtual void Process_ID3D12GraphicsCommandList_DrawInstanced(const ApiCallInfo& call_info,
                                                                 format::HandleId   object_id,
                                                                 UINT               VertexCountPerInstance,
                                                                 UINT               InstanceCount,
                                                                 UINT               StartVertexLocation,
                                                                 UINT               StartInstanceLocation) override;

    virtual void Process_ID3D12GraphicsCommandList_Dispatch(const ApiCallInfo& call_info,
                                                            format::HandleId   object_id,
                                                            UINT               ThreadGroupCountX,
                                                            UINT               ThreadGroupCountY,
                                                            UINT               ThreadGroupCountZ) override;

    virtual void
    Process_ID3D12CommandQueue_ExecuteCommandLists(const ApiCallInfo&                        call_info,
                                                   format::HandleId                          object_id,
                                                   UINT                                      NumCommandLists,
                                                   HandlePointerDecoder<ID3D12CommandList*>* ppCommandLists) override;

    virtual void Process_ID3D12GraphicsCommandList_Reset(const ApiCallInfo& call_info,
                                                         format::HandleId   object_id,
                                                         HRESULT            return_value,
                                                         format::HandleId   pAllocator,
                                                         format::HandleId   pInitialState) override;

  private:
    struct DescriptorRange
    {
        UINT root_parameter_index;
        UINT offset;
        UINT num_descriptors;
    };

    struct CBV
    {
        UINT root_parameter_index;
    };

    struct SRV
    {
        UINT root_parameter_index;
    };

    using RootParameter = std::variant<std::monostate, DescriptorRange, CBV, SRV>;

    struct RootSignatureInfo
    {
        std::vector<RootParameter> root_parameters;
    };

    struct CommandListInfo
    {
        format::HandleId                                 graphics_root_signature;
        std::vector<D3D12_GPU_DESCRIPTOR_HANDLE>         graphics_root_descriptor_tables;
        std::vector<D3D12_GPU_VIRTUAL_ADDRESS>           graphics_root_cbvs;
        std::vector<D3D12_GPU_VIRTUAL_ADDRESS>           graphics_root_srvs;

        format::HandleId                                 compute_root_signature;
        std::vector<D3D12_GPU_DESCRIPTOR_HANDLE>         compute_root_descriptor_tables;
        std::vector<D3D12_GPU_VIRTUAL_ADDRESS>           compute_root_cbvs;
        std::vector<D3D12_GPU_VIRTUAL_ADDRESS>           compute_root_srvs;

        format::HandleId                                 index_buffer_resource;
        std::vector<format::HandleId>                    vertex_buffer_resources;
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE              dsv_descriptor;
        std::vector<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE> rtv_descriptors;
    };

    struct DescriptorHeapInfo
    {
        UINT                                       num_descriptors = 0;
        D3D12_GPU_DESCRIPTOR_HANDLE                start_handle    = { 0 };
        std::unordered_map<UINT, format::HandleId> resources;
    };

    struct BufferResourceInfo
    {
        UINT64                    size{ 0 };
        D3D12_GPU_VIRTUAL_ADDRESS gpu_address{ 0 };
    };

    std::unordered_map<format::HandleId, RootSignatureInfo>  root_signature_infos_;
    std::unordered_map<format::HandleId, CommandListInfo>    command_list_infos_;
    std::unordered_map<format::HandleId, DescriptorHeapInfo> descriptor_heap_infos_;
    std::unordered_map<format::HandleId, BufferResourceInfo> buffer_resource_infos_;
    UINT                                                     cbv_srv_uav_handle_size_ = 0;

    ReferencedResourceTable table_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DX12_REFERENCED_RESOURCE_CONSUMER_H