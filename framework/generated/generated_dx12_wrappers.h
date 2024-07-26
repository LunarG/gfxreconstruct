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
** This file is generated from dx12_wrapper_header_generator.py.
**
*/

#ifndef  GFXRECON_GENERATED_DX12_WRAPPERS_H
#define  GFXRECON_GENERATED_DX12_WRAPPERS_H

#include "encode/dx12_object_wrapper_info.h"
#include "encode/iunknown_wrapper.h"
#include "util/defines.h"

#include <dxgiformat.h>
#include <d3d12.h>
#include <d3dcommon.h>
#include <d3d12sdklayers.h>
#include <d3d11.h>
#include <d3d11_1.h>
#include <d3d11_2.h>
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

#include <mutex>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

/*
** This part is generated from dxgiformat.h in Windows SDK: 10.0.20348.0
**
*/


/*
** This part is generated from d3d12.h in Windows SDK: 10.0.20348.0
**
*/

HRESULT WINAPI D3D12SerializeRootSignature(
    const D3D12_ROOT_SIGNATURE_DESC* pRootSignature,
    D3D_ROOT_SIGNATURE_VERSION Version,
    ID3DBlob** ppBlob,
    ID3DBlob** ppErrorBlob);

HRESULT WINAPI D3D12CreateRootSignatureDeserializer(
    LPCVOID pSrcData,
    SIZE_T SrcDataSizeInBytes,
    REFIID pRootSignatureDeserializerInterface,
    void** ppRootSignatureDeserializer);

HRESULT WINAPI D3D12SerializeVersionedRootSignature(
    const D3D12_VERSIONED_ROOT_SIGNATURE_DESC* pRootSignature,
    ID3DBlob** ppBlob,
    ID3DBlob** ppErrorBlob);

HRESULT WINAPI D3D12CreateVersionedRootSignatureDeserializer(
    LPCVOID pSrcData,
    SIZE_T SrcDataSizeInBytes,
    REFIID pRootSignatureDeserializerInterface,
    void** ppRootSignatureDeserializer);

HRESULT WINAPI D3D12CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary(
    LPCVOID pSrcData,
    SIZE_T SrcDataSizeInBytes,
    LPCWSTR RootSignatureSubobjectName,
    REFIID pRootSignatureDeserializerInterface,
    void** ppRootSignatureDeserializer);

HRESULT WINAPI D3D12CreateDevice(
    IUnknown* pAdapter,
    D3D_FEATURE_LEVEL MinimumFeatureLevel,
    REFIID riid,
    void** ppDevice);

HRESULT WINAPI D3D12GetDebugInterface(
    REFIID riid,
    void** ppvDebug);

HRESULT WINAPI D3D12EnableExperimentalFeatures(
    UINT NumFeatures,
    const IID* pIIDs,
    void* pConfigurationStructs,
    UINT* pConfigurationStructSizes);

HRESULT WINAPI D3D12GetInterface(
    REFCLSID rclsid,
    REFIID riid,
    void** ppvDebug);

class ID3D12Object_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12Object_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Object_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE GetPrivateData(
        REFGUID guid,
        UINT* pDataSize,
        void* pData);

    virtual HRESULT STDMETHODCALLTYPE SetPrivateData(
        REFGUID guid,
        UINT DataSize,
        const void* pData);

    virtual HRESULT STDMETHODCALLTYPE SetPrivateDataInterface(
        REFGUID guid,
        const IUnknown* pData);

    virtual HRESULT STDMETHODCALLTYPE SetName(
        LPCWSTR Name);

};

class ID3D12DeviceChild_Wrapper : public ID3D12Object_Wrapper
{
  public:
    ID3D12DeviceChild_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12DeviceChild_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE GetDevice(
        REFIID riid,
        void** ppvDevice);

};

class ID3D12RootSignature_Wrapper : public ID3D12DeviceChild_Wrapper
{
  public:
    ID3D12RootSignature_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12RootSignature_Wrapper*>(u); });

    ~ID3D12RootSignature_Wrapper();

    static ID3D12RootSignature_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12RootSignatureInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12RootSignatureInfo> GetObjectInfo() { return info_; }

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12RootSignature_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12RootSignatureInfo> info_;
};

class ID3D12RootSignatureDeserializer_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12RootSignatureDeserializer_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12RootSignatureDeserializer_Wrapper*>(u); });

    ~ID3D12RootSignatureDeserializer_Wrapper();

    static ID3D12RootSignatureDeserializer_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12RootSignatureDeserializerInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12RootSignatureDeserializerInfo> GetObjectInfo() { return info_; }

    virtual const D3D12_ROOT_SIGNATURE_DESC* STDMETHODCALLTYPE GetRootSignatureDesc();

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12RootSignatureDeserializer_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12RootSignatureDeserializerInfo> info_;
};

class ID3D12VersionedRootSignatureDeserializer_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12VersionedRootSignatureDeserializer_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12VersionedRootSignatureDeserializer_Wrapper*>(u); });

    ~ID3D12VersionedRootSignatureDeserializer_Wrapper();

    static ID3D12VersionedRootSignatureDeserializer_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12VersionedRootSignatureDeserializerInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12VersionedRootSignatureDeserializerInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE GetRootSignatureDescAtVersion(
        D3D_ROOT_SIGNATURE_VERSION convertToVersion,
        const D3D12_VERSIONED_ROOT_SIGNATURE_DESC** ppDesc);

    virtual const D3D12_VERSIONED_ROOT_SIGNATURE_DESC* STDMETHODCALLTYPE GetUnconvertedRootSignatureDesc();

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12VersionedRootSignatureDeserializer_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12VersionedRootSignatureDeserializerInfo> info_;
};

class ID3D12Pageable_Wrapper : public ID3D12DeviceChild_Wrapper
{
  public:
    ID3D12Pageable_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Pageable_Wrapper*>(u); });

};

class ID3D12Heap_Wrapper : public ID3D12Pageable_Wrapper
{
  public:
    ID3D12Heap_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Heap_Wrapper*>(u); });

    ~ID3D12Heap_Wrapper();

    static ID3D12Heap_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12HeapInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12HeapInfo> GetObjectInfo() { return info_; }

    virtual D3D12_HEAP_DESC STDMETHODCALLTYPE GetDesc();

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12Heap_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12HeapInfo> info_;
};

class ID3D12Resource_Wrapper : public ID3D12Pageable_Wrapper
{
  public:
    ID3D12Resource_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Resource_Wrapper*>(u); });

    ~ID3D12Resource_Wrapper();

    static ID3D12Resource_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12ResourceInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12ResourceInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE Map(
        UINT Subresource,
        const D3D12_RANGE* pReadRange,
        void** ppData);

    virtual void STDMETHODCALLTYPE Unmap(
        UINT Subresource,
        const D3D12_RANGE* pWrittenRange);

    virtual D3D12_RESOURCE_DESC STDMETHODCALLTYPE GetDesc();

    virtual D3D12_GPU_VIRTUAL_ADDRESS STDMETHODCALLTYPE GetGPUVirtualAddress();

    virtual HRESULT STDMETHODCALLTYPE WriteToSubresource(
        UINT DstSubresource,
        const D3D12_BOX* pDstBox,
        const void* pSrcData,
        UINT SrcRowPitch,
        UINT SrcDepthPitch);

    virtual HRESULT STDMETHODCALLTYPE ReadFromSubresource(
        void* pDstData,
        UINT DstRowPitch,
        UINT DstDepthPitch,
        UINT SrcSubresource,
        const D3D12_BOX* pSrcBox);

    virtual HRESULT STDMETHODCALLTYPE GetHeapProperties(
        D3D12_HEAP_PROPERTIES* pHeapProperties,
        D3D12_HEAP_FLAGS* pHeapFlags);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12Resource_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12ResourceInfo> info_;
};

class ID3D12CommandAllocator_Wrapper : public ID3D12Pageable_Wrapper
{
  public:
    ID3D12CommandAllocator_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12CommandAllocator_Wrapper*>(u); });

    ~ID3D12CommandAllocator_Wrapper();

    static ID3D12CommandAllocator_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12CommandAllocatorInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12CommandAllocatorInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE Reset();

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12CommandAllocator_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12CommandAllocatorInfo> info_;
};

class ID3D12Fence_Wrapper : public ID3D12Pageable_Wrapper
{
  public:
    ID3D12Fence_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Fence_Wrapper*>(u); });

    ~ID3D12Fence_Wrapper();

    static ID3D12Fence_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12FenceInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12FenceInfo> GetObjectInfo() { return info_; }

    virtual UINT64 STDMETHODCALLTYPE GetCompletedValue();

    virtual HRESULT STDMETHODCALLTYPE SetEventOnCompletion(
        UINT64 Value,
        HANDLE hEvent);

    virtual HRESULT STDMETHODCALLTYPE Signal(
        UINT64 Value);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12Fence_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12FenceInfo> info_;
};

class ID3D12Fence1_Wrapper : public ID3D12Fence_Wrapper
{
  public:
    ID3D12Fence1_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Fence1_Wrapper*>(u); });

    virtual D3D12_FENCE_FLAGS STDMETHODCALLTYPE GetCreationFlags();

};

class ID3D12PipelineState_Wrapper : public ID3D12Pageable_Wrapper
{
  public:
    ID3D12PipelineState_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12PipelineState_Wrapper*>(u); });

    ~ID3D12PipelineState_Wrapper();

    static ID3D12PipelineState_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12PipelineStateInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12PipelineStateInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE GetCachedBlob(
        ID3DBlob** ppBlob);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12PipelineState_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12PipelineStateInfo> info_;
};

class ID3D12DescriptorHeap_Wrapper : public ID3D12Pageable_Wrapper
{
  public:
    ID3D12DescriptorHeap_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12DescriptorHeap_Wrapper*>(u); });

    ~ID3D12DescriptorHeap_Wrapper();

    static ID3D12DescriptorHeap_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12DescriptorHeapInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12DescriptorHeapInfo> GetObjectInfo() { return info_; }

    virtual D3D12_DESCRIPTOR_HEAP_DESC STDMETHODCALLTYPE GetDesc();

    virtual D3D12_CPU_DESCRIPTOR_HANDLE STDMETHODCALLTYPE GetCPUDescriptorHandleForHeapStart();

    virtual D3D12_GPU_DESCRIPTOR_HANDLE STDMETHODCALLTYPE GetGPUDescriptorHandleForHeapStart();

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12DescriptorHeap_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12DescriptorHeapInfo> info_;
};

class ID3D12QueryHeap_Wrapper : public ID3D12Pageable_Wrapper
{
  public:
    ID3D12QueryHeap_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12QueryHeap_Wrapper*>(u); });

    ~ID3D12QueryHeap_Wrapper();

    static ID3D12QueryHeap_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12QueryHeapInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12QueryHeapInfo> GetObjectInfo() { return info_; }

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12QueryHeap_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12QueryHeapInfo> info_;
};

class ID3D12CommandSignature_Wrapper : public ID3D12Pageable_Wrapper
{
  public:
    ID3D12CommandSignature_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12CommandSignature_Wrapper*>(u); });

    ~ID3D12CommandSignature_Wrapper();

    static ID3D12CommandSignature_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12CommandSignatureInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12CommandSignatureInfo> GetObjectInfo() { return info_; }

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12CommandSignature_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12CommandSignatureInfo> info_;
};

class ID3D12CommandList_Wrapper : public ID3D12DeviceChild_Wrapper
{
  public:
    ID3D12CommandList_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12CommandList_Wrapper*>(u); });

    ~ID3D12CommandList_Wrapper();

    static ID3D12CommandList_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12CommandListInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12CommandListInfo> GetObjectInfo() { return info_; }

    virtual D3D12_COMMAND_LIST_TYPE STDMETHODCALLTYPE GetType();

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12CommandList_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12CommandListInfo> info_;
};

class ID3D12GraphicsCommandList_Wrapper : public ID3D12CommandList_Wrapper
{
  public:
    ID3D12GraphicsCommandList_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12GraphicsCommandList_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE Close();

    virtual HRESULT STDMETHODCALLTYPE Reset(
        ID3D12CommandAllocator* pAllocator,
        ID3D12PipelineState* pInitialState);

    virtual void STDMETHODCALLTYPE ClearState(
        ID3D12PipelineState* pPipelineState);

    virtual void STDMETHODCALLTYPE DrawInstanced(
        UINT VertexCountPerInstance,
        UINT InstanceCount,
        UINT StartVertexLocation,
        UINT StartInstanceLocation);

    virtual void STDMETHODCALLTYPE DrawIndexedInstanced(
        UINT IndexCountPerInstance,
        UINT InstanceCount,
        UINT StartIndexLocation,
        INT BaseVertexLocation,
        UINT StartInstanceLocation);

    virtual void STDMETHODCALLTYPE Dispatch(
        UINT ThreadGroupCountX,
        UINT ThreadGroupCountY,
        UINT ThreadGroupCountZ);

    virtual void STDMETHODCALLTYPE CopyBufferRegion(
        ID3D12Resource* pDstBuffer,
        UINT64 DstOffset,
        ID3D12Resource* pSrcBuffer,
        UINT64 SrcOffset,
        UINT64 NumBytes);

    virtual void STDMETHODCALLTYPE CopyTextureRegion(
        const D3D12_TEXTURE_COPY_LOCATION* pDst,
        UINT DstX,
        UINT DstY,
        UINT DstZ,
        const D3D12_TEXTURE_COPY_LOCATION* pSrc,
        const D3D12_BOX* pSrcBox);

    virtual void STDMETHODCALLTYPE CopyResource(
        ID3D12Resource* pDstResource,
        ID3D12Resource* pSrcResource);

    virtual void STDMETHODCALLTYPE CopyTiles(
        ID3D12Resource* pTiledResource,
        const D3D12_TILED_RESOURCE_COORDINATE* pTileRegionStartCoordinate,
        const D3D12_TILE_REGION_SIZE* pTileRegionSize,
        ID3D12Resource* pBuffer,
        UINT64 BufferStartOffsetInBytes,
        D3D12_TILE_COPY_FLAGS Flags);

    virtual void STDMETHODCALLTYPE ResolveSubresource(
        ID3D12Resource* pDstResource,
        UINT DstSubresource,
        ID3D12Resource* pSrcResource,
        UINT SrcSubresource,
        DXGI_FORMAT Format);

    virtual void STDMETHODCALLTYPE IASetPrimitiveTopology(
        D3D12_PRIMITIVE_TOPOLOGY PrimitiveTopology);

    virtual void STDMETHODCALLTYPE RSSetViewports(
        UINT NumViewports,
        const D3D12_VIEWPORT* pViewports);

    virtual void STDMETHODCALLTYPE RSSetScissorRects(
        UINT NumRects,
        const D3D12_RECT* pRects);

    virtual void STDMETHODCALLTYPE OMSetBlendFactor(
        const FLOAT BlendFactor [4]);

    virtual void STDMETHODCALLTYPE OMSetStencilRef(
        UINT StencilRef);

    virtual void STDMETHODCALLTYPE SetPipelineState(
        ID3D12PipelineState* pPipelineState);

    virtual void STDMETHODCALLTYPE ResourceBarrier(
        UINT NumBarriers,
        const D3D12_RESOURCE_BARRIER* pBarriers);

    virtual void STDMETHODCALLTYPE ExecuteBundle(
        ID3D12GraphicsCommandList* pCommandList);

    virtual void STDMETHODCALLTYPE SetDescriptorHeaps(
        UINT NumDescriptorHeaps,
        ID3D12DescriptorHeap* const* ppDescriptorHeaps);

    virtual void STDMETHODCALLTYPE SetComputeRootSignature(
        ID3D12RootSignature* pRootSignature);

    virtual void STDMETHODCALLTYPE SetGraphicsRootSignature(
        ID3D12RootSignature* pRootSignature);

    virtual void STDMETHODCALLTYPE SetComputeRootDescriptorTable(
        UINT RootParameterIndex,
        D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor);

    virtual void STDMETHODCALLTYPE SetGraphicsRootDescriptorTable(
        UINT RootParameterIndex,
        D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor);

    virtual void STDMETHODCALLTYPE SetComputeRoot32BitConstant(
        UINT RootParameterIndex,
        UINT SrcData,
        UINT DestOffsetIn32BitValues);

    virtual void STDMETHODCALLTYPE SetGraphicsRoot32BitConstant(
        UINT RootParameterIndex,
        UINT SrcData,
        UINT DestOffsetIn32BitValues);

    virtual void STDMETHODCALLTYPE SetComputeRoot32BitConstants(
        UINT RootParameterIndex,
        UINT Num32BitValuesToSet,
        const void* pSrcData,
        UINT DestOffsetIn32BitValues);

    virtual void STDMETHODCALLTYPE SetGraphicsRoot32BitConstants(
        UINT RootParameterIndex,
        UINT Num32BitValuesToSet,
        const void* pSrcData,
        UINT DestOffsetIn32BitValues);

    virtual void STDMETHODCALLTYPE SetComputeRootConstantBufferView(
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

    virtual void STDMETHODCALLTYPE SetGraphicsRootConstantBufferView(
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

    virtual void STDMETHODCALLTYPE SetComputeRootShaderResourceView(
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

    virtual void STDMETHODCALLTYPE SetGraphicsRootShaderResourceView(
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

    virtual void STDMETHODCALLTYPE SetComputeRootUnorderedAccessView(
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

    virtual void STDMETHODCALLTYPE SetGraphicsRootUnorderedAccessView(
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

    virtual void STDMETHODCALLTYPE IASetIndexBuffer(
        const D3D12_INDEX_BUFFER_VIEW* pView);

    virtual void STDMETHODCALLTYPE IASetVertexBuffers(
        UINT StartSlot,
        UINT NumViews,
        const D3D12_VERTEX_BUFFER_VIEW* pViews);

    virtual void STDMETHODCALLTYPE SOSetTargets(
        UINT StartSlot,
        UINT NumViews,
        const D3D12_STREAM_OUTPUT_BUFFER_VIEW* pViews);

    virtual void STDMETHODCALLTYPE OMSetRenderTargets(
        UINT NumRenderTargetDescriptors,
        const D3D12_CPU_DESCRIPTOR_HANDLE* pRenderTargetDescriptors,
        BOOL RTsSingleHandleToDescriptorRange,
        const D3D12_CPU_DESCRIPTOR_HANDLE* pDepthStencilDescriptor);

    virtual void STDMETHODCALLTYPE ClearDepthStencilView(
        D3D12_CPU_DESCRIPTOR_HANDLE DepthStencilView,
        D3D12_CLEAR_FLAGS ClearFlags,
        FLOAT Depth,
        UINT8 Stencil,
        UINT NumRects,
        const D3D12_RECT* pRects);

    virtual void STDMETHODCALLTYPE ClearRenderTargetView(
        D3D12_CPU_DESCRIPTOR_HANDLE RenderTargetView,
        const FLOAT ColorRGBA [4],
        UINT NumRects,
        const D3D12_RECT* pRects);

    virtual void STDMETHODCALLTYPE ClearUnorderedAccessViewUint(
        D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap,
        D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle,
        ID3D12Resource* pResource,
        const UINT Values [4],
        UINT NumRects,
        const D3D12_RECT* pRects);

    virtual void STDMETHODCALLTYPE ClearUnorderedAccessViewFloat(
        D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap,
        D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle,
        ID3D12Resource* pResource,
        const FLOAT Values [4],
        UINT NumRects,
        const D3D12_RECT* pRects);

    virtual void STDMETHODCALLTYPE DiscardResource(
        ID3D12Resource* pResource,
        const D3D12_DISCARD_REGION* pRegion);

    virtual void STDMETHODCALLTYPE BeginQuery(
        ID3D12QueryHeap* pQueryHeap,
        D3D12_QUERY_TYPE Type,
        UINT Index);

    virtual void STDMETHODCALLTYPE EndQuery(
        ID3D12QueryHeap* pQueryHeap,
        D3D12_QUERY_TYPE Type,
        UINT Index);

    virtual void STDMETHODCALLTYPE ResolveQueryData(
        ID3D12QueryHeap* pQueryHeap,
        D3D12_QUERY_TYPE Type,
        UINT StartIndex,
        UINT NumQueries,
        ID3D12Resource* pDestinationBuffer,
        UINT64 AlignedDestinationBufferOffset);

    virtual void STDMETHODCALLTYPE SetPredication(
        ID3D12Resource* pBuffer,
        UINT64 AlignedBufferOffset,
        D3D12_PREDICATION_OP Operation);

    virtual void STDMETHODCALLTYPE SetMarker(
        UINT Metadata,
        const void* pData,
        UINT Size);

    virtual void STDMETHODCALLTYPE BeginEvent(
        UINT Metadata,
        const void* pData,
        UINT Size);

    virtual void STDMETHODCALLTYPE EndEvent();

    virtual void STDMETHODCALLTYPE ExecuteIndirect(
        ID3D12CommandSignature* pCommandSignature,
        UINT MaxCommandCount,
        ID3D12Resource* pArgumentBuffer,
        UINT64 ArgumentBufferOffset,
        ID3D12Resource* pCountBuffer,
        UINT64 CountBufferOffset);

};

class ID3D12GraphicsCommandList1_Wrapper : public ID3D12GraphicsCommandList_Wrapper
{
  public:
    ID3D12GraphicsCommandList1_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12GraphicsCommandList1_Wrapper*>(u); });

    virtual void STDMETHODCALLTYPE AtomicCopyBufferUINT(
        ID3D12Resource* pDstBuffer,
        UINT64 DstOffset,
        ID3D12Resource* pSrcBuffer,
        UINT64 SrcOffset,
        UINT Dependencies,
        ID3D12Resource* const* ppDependentResources,
        const D3D12_SUBRESOURCE_RANGE_UINT64* pDependentSubresourceRanges);

    virtual void STDMETHODCALLTYPE AtomicCopyBufferUINT64(
        ID3D12Resource* pDstBuffer,
        UINT64 DstOffset,
        ID3D12Resource* pSrcBuffer,
        UINT64 SrcOffset,
        UINT Dependencies,
        ID3D12Resource* const* ppDependentResources,
        const D3D12_SUBRESOURCE_RANGE_UINT64* pDependentSubresourceRanges);

    virtual void STDMETHODCALLTYPE OMSetDepthBounds(
        FLOAT Min,
        FLOAT Max);

    virtual void STDMETHODCALLTYPE SetSamplePositions(
        UINT NumSamplesPerPixel,
        UINT NumPixels,
        D3D12_SAMPLE_POSITION* pSamplePositions);

    virtual void STDMETHODCALLTYPE ResolveSubresourceRegion(
        ID3D12Resource* pDstResource,
        UINT DstSubresource,
        UINT DstX,
        UINT DstY,
        ID3D12Resource* pSrcResource,
        UINT SrcSubresource,
        D3D12_RECT* pSrcRect,
        DXGI_FORMAT Format,
        D3D12_RESOLVE_MODE ResolveMode);

    virtual void STDMETHODCALLTYPE SetViewInstanceMask(
        UINT Mask);

};

class ID3D12GraphicsCommandList2_Wrapper : public ID3D12GraphicsCommandList1_Wrapper
{
  public:
    ID3D12GraphicsCommandList2_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12GraphicsCommandList2_Wrapper*>(u); });

    virtual void STDMETHODCALLTYPE WriteBufferImmediate(
        UINT Count,
        const D3D12_WRITEBUFFERIMMEDIATE_PARAMETER* pParams,
        const D3D12_WRITEBUFFERIMMEDIATE_MODE* pModes);

};

class ID3D12CommandQueue_Wrapper : public ID3D12Pageable_Wrapper
{
  public:
    ID3D12CommandQueue_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12CommandQueue_Wrapper*>(u); });

    ~ID3D12CommandQueue_Wrapper();

    static ID3D12CommandQueue_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12CommandQueueInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12CommandQueueInfo> GetObjectInfo() { return info_; }

    virtual void STDMETHODCALLTYPE UpdateTileMappings(
        ID3D12Resource* pResource,
        UINT NumResourceRegions,
        const D3D12_TILED_RESOURCE_COORDINATE* pResourceRegionStartCoordinates,
        const D3D12_TILE_REGION_SIZE* pResourceRegionSizes,
        ID3D12Heap* pHeap,
        UINT NumRanges,
        const D3D12_TILE_RANGE_FLAGS* pRangeFlags,
        const UINT* pHeapRangeStartOffsets,
        const UINT* pRangeTileCounts,
        D3D12_TILE_MAPPING_FLAGS Flags);

    virtual void STDMETHODCALLTYPE CopyTileMappings(
        ID3D12Resource* pDstResource,
        const D3D12_TILED_RESOURCE_COORDINATE* pDstRegionStartCoordinate,
        ID3D12Resource* pSrcResource,
        const D3D12_TILED_RESOURCE_COORDINATE* pSrcRegionStartCoordinate,
        const D3D12_TILE_REGION_SIZE* pRegionSize,
        D3D12_TILE_MAPPING_FLAGS Flags);

    virtual void STDMETHODCALLTYPE ExecuteCommandLists(
        UINT NumCommandLists,
        ID3D12CommandList* const* ppCommandLists);

    virtual void STDMETHODCALLTYPE SetMarker(
        UINT Metadata,
        const void* pData,
        UINT Size);

    virtual void STDMETHODCALLTYPE BeginEvent(
        UINT Metadata,
        const void* pData,
        UINT Size);

    virtual void STDMETHODCALLTYPE EndEvent();

    virtual HRESULT STDMETHODCALLTYPE Signal(
        ID3D12Fence* pFence,
        UINT64 Value);

    virtual HRESULT STDMETHODCALLTYPE Wait(
        ID3D12Fence* pFence,
        UINT64 Value);

    virtual HRESULT STDMETHODCALLTYPE GetTimestampFrequency(
        UINT64* pFrequency);

    virtual HRESULT STDMETHODCALLTYPE GetClockCalibration(
        UINT64* pGpuTimestamp,
        UINT64* pCpuTimestamp);

    virtual D3D12_COMMAND_QUEUE_DESC STDMETHODCALLTYPE GetDesc();

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12CommandQueue_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12CommandQueueInfo> info_;
};

class ID3D12Device_Wrapper : public ID3D12Object_Wrapper
{
  public:
    ID3D12Device_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Device_Wrapper*>(u); });

    ~ID3D12Device_Wrapper();

    static ID3D12Device_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12DeviceInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12DeviceInfo> GetObjectInfo() { return info_; }

    virtual UINT STDMETHODCALLTYPE GetNodeCount();

    virtual HRESULT STDMETHODCALLTYPE CreateCommandQueue(
        const D3D12_COMMAND_QUEUE_DESC* pDesc,
        REFIID riid,
        void** ppCommandQueue);

    virtual HRESULT STDMETHODCALLTYPE CreateCommandAllocator(
        D3D12_COMMAND_LIST_TYPE type,
        REFIID riid,
        void** ppCommandAllocator);

    virtual HRESULT STDMETHODCALLTYPE CreateGraphicsPipelineState(
        const D3D12_GRAPHICS_PIPELINE_STATE_DESC* pDesc,
        REFIID riid,
        void** ppPipelineState);

    virtual HRESULT STDMETHODCALLTYPE CreateComputePipelineState(
        const D3D12_COMPUTE_PIPELINE_STATE_DESC* pDesc,
        REFIID riid,
        void** ppPipelineState);

    virtual HRESULT STDMETHODCALLTYPE CreateCommandList(
        UINT nodeMask,
        D3D12_COMMAND_LIST_TYPE type,
        ID3D12CommandAllocator* pCommandAllocator,
        ID3D12PipelineState* pInitialState,
        REFIID riid,
        void** ppCommandList);

    virtual HRESULT STDMETHODCALLTYPE CheckFeatureSupport(
        D3D12_FEATURE Feature,
        void* pFeatureSupportData,
        UINT FeatureSupportDataSize);

    virtual HRESULT STDMETHODCALLTYPE CreateDescriptorHeap(
        const D3D12_DESCRIPTOR_HEAP_DESC* pDescriptorHeapDesc,
        REFIID riid,
        void** ppvHeap);

    virtual UINT STDMETHODCALLTYPE GetDescriptorHandleIncrementSize(
        D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapType);

    virtual HRESULT STDMETHODCALLTYPE CreateRootSignature(
        UINT nodeMask,
        const void* pBlobWithRootSignature,
        SIZE_T blobLengthInBytes,
        REFIID riid,
        void** ppvRootSignature);

    virtual void STDMETHODCALLTYPE CreateConstantBufferView(
        const D3D12_CONSTANT_BUFFER_VIEW_DESC* pDesc,
        D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

    virtual void STDMETHODCALLTYPE CreateShaderResourceView(
        ID3D12Resource* pResource,
        const D3D12_SHADER_RESOURCE_VIEW_DESC* pDesc,
        D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

    virtual void STDMETHODCALLTYPE CreateUnorderedAccessView(
        ID3D12Resource* pResource,
        ID3D12Resource* pCounterResource,
        const D3D12_UNORDERED_ACCESS_VIEW_DESC* pDesc,
        D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

    virtual void STDMETHODCALLTYPE CreateRenderTargetView(
        ID3D12Resource* pResource,
        const D3D12_RENDER_TARGET_VIEW_DESC* pDesc,
        D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

    virtual void STDMETHODCALLTYPE CreateDepthStencilView(
        ID3D12Resource* pResource,
        const D3D12_DEPTH_STENCIL_VIEW_DESC* pDesc,
        D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

    virtual void STDMETHODCALLTYPE CreateSampler(
        const D3D12_SAMPLER_DESC* pDesc,
        D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

    virtual void STDMETHODCALLTYPE CopyDescriptors(
        UINT NumDestDescriptorRanges,
        const D3D12_CPU_DESCRIPTOR_HANDLE* pDestDescriptorRangeStarts,
        const UINT* pDestDescriptorRangeSizes,
        UINT NumSrcDescriptorRanges,
        const D3D12_CPU_DESCRIPTOR_HANDLE* pSrcDescriptorRangeStarts,
        const UINT* pSrcDescriptorRangeSizes,
        D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType);

    virtual void STDMETHODCALLTYPE CopyDescriptorsSimple(
        UINT NumDescriptors,
        D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptorRangeStart,
        D3D12_CPU_DESCRIPTOR_HANDLE SrcDescriptorRangeStart,
        D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType);

    virtual D3D12_RESOURCE_ALLOCATION_INFO STDMETHODCALLTYPE GetResourceAllocationInfo(
        UINT visibleMask,
        UINT numResourceDescs,
        const D3D12_RESOURCE_DESC* pResourceDescs);

    virtual D3D12_HEAP_PROPERTIES STDMETHODCALLTYPE GetCustomHeapProperties(
        UINT nodeMask,
        D3D12_HEAP_TYPE heapType);

    virtual HRESULT STDMETHODCALLTYPE CreateCommittedResource(
        const D3D12_HEAP_PROPERTIES* pHeapProperties,
        D3D12_HEAP_FLAGS HeapFlags,
        const D3D12_RESOURCE_DESC* pDesc,
        D3D12_RESOURCE_STATES InitialResourceState,
        const D3D12_CLEAR_VALUE* pOptimizedClearValue,
        REFIID riidResource,
        void** ppvResource);

    virtual HRESULT STDMETHODCALLTYPE CreateHeap(
        const D3D12_HEAP_DESC* pDesc,
        REFIID riid,
        void** ppvHeap);

    virtual HRESULT STDMETHODCALLTYPE CreatePlacedResource(
        ID3D12Heap* pHeap,
        UINT64 HeapOffset,
        const D3D12_RESOURCE_DESC* pDesc,
        D3D12_RESOURCE_STATES InitialState,
        const D3D12_CLEAR_VALUE* pOptimizedClearValue,
        REFIID riid,
        void** ppvResource);

    virtual HRESULT STDMETHODCALLTYPE CreateReservedResource(
        const D3D12_RESOURCE_DESC* pDesc,
        D3D12_RESOURCE_STATES InitialState,
        const D3D12_CLEAR_VALUE* pOptimizedClearValue,
        REFIID riid,
        void** ppvResource);

    virtual HRESULT STDMETHODCALLTYPE CreateSharedHandle(
        ID3D12DeviceChild* pObject,
        const SECURITY_ATTRIBUTES* pAttributes,
        DWORD Access,
        LPCWSTR Name,
        HANDLE* pHandle);

    virtual HRESULT STDMETHODCALLTYPE OpenSharedHandle(
        HANDLE NTHandle,
        REFIID riid,
        void** ppvObj);

    virtual HRESULT STDMETHODCALLTYPE OpenSharedHandleByName(
        LPCWSTR Name,
        DWORD Access,
        HANDLE* pNTHandle);

    virtual HRESULT STDMETHODCALLTYPE MakeResident(
        UINT NumObjects,
        ID3D12Pageable* const* ppObjects);

    virtual HRESULT STDMETHODCALLTYPE Evict(
        UINT NumObjects,
        ID3D12Pageable* const* ppObjects);

    virtual HRESULT STDMETHODCALLTYPE CreateFence(
        UINT64 InitialValue,
        D3D12_FENCE_FLAGS Flags,
        REFIID riid,
        void** ppFence);

    virtual HRESULT STDMETHODCALLTYPE GetDeviceRemovedReason();

    virtual void STDMETHODCALLTYPE GetCopyableFootprints(
        const D3D12_RESOURCE_DESC* pResourceDesc,
        UINT FirstSubresource,
        UINT NumSubresources,
        UINT64 BaseOffset,
        D3D12_PLACED_SUBRESOURCE_FOOTPRINT* pLayouts,
        UINT* pNumRows,
        UINT64* pRowSizeInBytes,
        UINT64* pTotalBytes);

    virtual HRESULT STDMETHODCALLTYPE CreateQueryHeap(
        const D3D12_QUERY_HEAP_DESC* pDesc,
        REFIID riid,
        void** ppvHeap);

    virtual HRESULT STDMETHODCALLTYPE SetStablePowerState(
        BOOL Enable);

    virtual HRESULT STDMETHODCALLTYPE CreateCommandSignature(
        const D3D12_COMMAND_SIGNATURE_DESC* pDesc,
        ID3D12RootSignature* pRootSignature,
        REFIID riid,
        void** ppvCommandSignature);

    virtual void STDMETHODCALLTYPE GetResourceTiling(
        ID3D12Resource* pTiledResource,
        UINT* pNumTilesForEntireResource,
        D3D12_PACKED_MIP_INFO* pPackedMipDesc,
        D3D12_TILE_SHAPE* pStandardTileShapeForNonPackedMips,
        UINT* pNumSubresourceTilings,
        UINT FirstSubresourceTilingToGet,
        D3D12_SUBRESOURCE_TILING* pSubresourceTilingsForNonPackedMips);

    virtual LUID STDMETHODCALLTYPE GetAdapterLuid();

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12Device_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12DeviceInfo> info_;
};

class ID3D12PipelineLibrary_Wrapper : public ID3D12DeviceChild_Wrapper
{
  public:
    ID3D12PipelineLibrary_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12PipelineLibrary_Wrapper*>(u); });

    ~ID3D12PipelineLibrary_Wrapper();

    static ID3D12PipelineLibrary_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12PipelineLibraryInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12PipelineLibraryInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE StorePipeline(
        LPCWSTR pName,
        ID3D12PipelineState* pPipeline);

    virtual HRESULT STDMETHODCALLTYPE LoadGraphicsPipeline(
        LPCWSTR pName,
        const D3D12_GRAPHICS_PIPELINE_STATE_DESC* pDesc,
        REFIID riid,
        void** ppPipelineState);

    virtual HRESULT STDMETHODCALLTYPE LoadComputePipeline(
        LPCWSTR pName,
        const D3D12_COMPUTE_PIPELINE_STATE_DESC* pDesc,
        REFIID riid,
        void** ppPipelineState);

    virtual SIZE_T STDMETHODCALLTYPE GetSerializedSize();

    virtual HRESULT STDMETHODCALLTYPE Serialize(
        void* pData,
        SIZE_T DataSizeInBytes);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12PipelineLibrary_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12PipelineLibraryInfo> info_;
};

class ID3D12PipelineLibrary1_Wrapper : public ID3D12PipelineLibrary_Wrapper
{
  public:
    ID3D12PipelineLibrary1_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12PipelineLibrary1_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE LoadPipeline(
        LPCWSTR pName,
        const D3D12_PIPELINE_STATE_STREAM_DESC* pDesc,
        REFIID riid,
        void** ppPipelineState);

};

class ID3D12Device1_Wrapper : public ID3D12Device_Wrapper
{
  public:
    ID3D12Device1_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Device1_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE CreatePipelineLibrary(
        const void* pLibraryBlob,
        SIZE_T BlobLength,
        REFIID riid,
        void** ppPipelineLibrary);

    virtual HRESULT STDMETHODCALLTYPE SetEventOnMultipleFenceCompletion(
        ID3D12Fence* const* ppFences,
        const UINT64* pFenceValues,
        UINT NumFences,
        D3D12_MULTIPLE_FENCE_WAIT_FLAGS Flags,
        HANDLE hEvent);

    virtual HRESULT STDMETHODCALLTYPE SetResidencyPriority(
        UINT NumObjects,
        ID3D12Pageable* const* ppObjects,
        const D3D12_RESIDENCY_PRIORITY* pPriorities);

};

class ID3D12Device2_Wrapper : public ID3D12Device1_Wrapper
{
  public:
    ID3D12Device2_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Device2_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE CreatePipelineState(
        const D3D12_PIPELINE_STATE_STREAM_DESC* pDesc,
        REFIID riid,
        void** ppPipelineState);

};

class ID3D12Device3_Wrapper : public ID3D12Device2_Wrapper
{
  public:
    ID3D12Device3_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Device3_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE OpenExistingHeapFromAddress(
        const void* pAddress,
        REFIID riid,
        void** ppvHeap);

    virtual HRESULT STDMETHODCALLTYPE OpenExistingHeapFromFileMapping(
        HANDLE hFileMapping,
        REFIID riid,
        void** ppvHeap);

    virtual HRESULT STDMETHODCALLTYPE EnqueueMakeResident(
        D3D12_RESIDENCY_FLAGS Flags,
        UINT NumObjects,
        ID3D12Pageable* const* ppObjects,
        ID3D12Fence* pFenceToSignal,
        UINT64 FenceValueToSignal);

};

class ID3D12ProtectedSession_Wrapper : public ID3D12DeviceChild_Wrapper
{
  public:
    ID3D12ProtectedSession_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12ProtectedSession_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE GetStatusFence(
        REFIID riid,
        void** ppFence);

    virtual D3D12_PROTECTED_SESSION_STATUS STDMETHODCALLTYPE GetSessionStatus();

};

class ID3D12ProtectedResourceSession_Wrapper : public ID3D12ProtectedSession_Wrapper
{
  public:
    ID3D12ProtectedResourceSession_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12ProtectedResourceSession_Wrapper*>(u); });

    ~ID3D12ProtectedResourceSession_Wrapper();

    static ID3D12ProtectedResourceSession_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12ProtectedResourceSessionInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12ProtectedResourceSessionInfo> GetObjectInfo() { return info_; }

    virtual D3D12_PROTECTED_RESOURCE_SESSION_DESC STDMETHODCALLTYPE GetDesc();

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12ProtectedResourceSession_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12ProtectedResourceSessionInfo> info_;
};

class ID3D12Device4_Wrapper : public ID3D12Device3_Wrapper
{
  public:
    ID3D12Device4_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Device4_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE CreateCommandList1(
        UINT nodeMask,
        D3D12_COMMAND_LIST_TYPE type,
        D3D12_COMMAND_LIST_FLAGS flags,
        REFIID riid,
        void** ppCommandList);

    virtual HRESULT STDMETHODCALLTYPE CreateProtectedResourceSession(
        const D3D12_PROTECTED_RESOURCE_SESSION_DESC* pDesc,
        REFIID riid,
        void** ppSession);

    virtual HRESULT STDMETHODCALLTYPE CreateCommittedResource1(
        const D3D12_HEAP_PROPERTIES* pHeapProperties,
        D3D12_HEAP_FLAGS HeapFlags,
        const D3D12_RESOURCE_DESC* pDesc,
        D3D12_RESOURCE_STATES InitialResourceState,
        const D3D12_CLEAR_VALUE* pOptimizedClearValue,
        ID3D12ProtectedResourceSession* pProtectedSession,
        REFIID riidResource,
        void** ppvResource);

    virtual HRESULT STDMETHODCALLTYPE CreateHeap1(
        const D3D12_HEAP_DESC* pDesc,
        ID3D12ProtectedResourceSession* pProtectedSession,
        REFIID riid,
        void** ppvHeap);

    virtual HRESULT STDMETHODCALLTYPE CreateReservedResource1(
        const D3D12_RESOURCE_DESC* pDesc,
        D3D12_RESOURCE_STATES InitialState,
        const D3D12_CLEAR_VALUE* pOptimizedClearValue,
        ID3D12ProtectedResourceSession* pProtectedSession,
        REFIID riid,
        void** ppvResource);

    virtual D3D12_RESOURCE_ALLOCATION_INFO STDMETHODCALLTYPE GetResourceAllocationInfo1(
        UINT visibleMask,
        UINT numResourceDescs,
        const D3D12_RESOURCE_DESC* pResourceDescs,
        D3D12_RESOURCE_ALLOCATION_INFO1* pResourceAllocationInfo1);

};

class ID3D12LifetimeOwner_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12LifetimeOwner_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12LifetimeOwner_Wrapper*>(u); });

    ~ID3D12LifetimeOwner_Wrapper();

    static ID3D12LifetimeOwner_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12LifetimeOwnerInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12LifetimeOwnerInfo> GetObjectInfo() { return info_; }

    virtual void STDMETHODCALLTYPE LifetimeStateUpdated(
        D3D12_LIFETIME_STATE NewState);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12LifetimeOwner_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12LifetimeOwnerInfo> info_;
};

class ID3D12SwapChainAssistant_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12SwapChainAssistant_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12SwapChainAssistant_Wrapper*>(u); });

    ~ID3D12SwapChainAssistant_Wrapper();

    static ID3D12SwapChainAssistant_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12SwapChainAssistantInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12SwapChainAssistantInfo> GetObjectInfo() { return info_; }

    virtual LUID STDMETHODCALLTYPE GetLUID();

    virtual HRESULT STDMETHODCALLTYPE GetSwapChainObject(
        REFIID riid,
        void** ppv);

    virtual HRESULT STDMETHODCALLTYPE GetCurrentResourceAndCommandQueue(
        REFIID riidResource,
        void** ppvResource,
        REFIID riidQueue,
        void** ppvQueue);

    virtual HRESULT STDMETHODCALLTYPE InsertImplicitSync();

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12SwapChainAssistant_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12SwapChainAssistantInfo> info_;
};

class ID3D12LifetimeTracker_Wrapper : public ID3D12DeviceChild_Wrapper
{
  public:
    ID3D12LifetimeTracker_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12LifetimeTracker_Wrapper*>(u); });

    ~ID3D12LifetimeTracker_Wrapper();

    static ID3D12LifetimeTracker_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12LifetimeTrackerInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12LifetimeTrackerInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE DestroyOwnedObject(
        ID3D12DeviceChild* pObject);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12LifetimeTracker_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12LifetimeTrackerInfo> info_;
};

class ID3D12StateObject_Wrapper : public ID3D12Pageable_Wrapper
{
  public:
    ID3D12StateObject_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12StateObject_Wrapper*>(u); });

    ~ID3D12StateObject_Wrapper();

    static ID3D12StateObject_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12StateObjectInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12StateObjectInfo> GetObjectInfo() { return info_; }

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12StateObject_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12StateObjectInfo> info_;
};

class ID3D12StateObjectProperties_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12StateObjectProperties_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12StateObjectProperties_Wrapper*>(u); });

    ~ID3D12StateObjectProperties_Wrapper();

    static ID3D12StateObjectProperties_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12StateObjectPropertiesInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12StateObjectPropertiesInfo> GetObjectInfo() { return info_; }

    virtual void* STDMETHODCALLTYPE GetShaderIdentifier(
        LPCWSTR pExportName);

    virtual UINT64 STDMETHODCALLTYPE GetShaderStackSize(
        LPCWSTR pExportName);

    virtual UINT64 STDMETHODCALLTYPE GetPipelineStackSize();

    virtual void STDMETHODCALLTYPE SetPipelineStackSize(
        UINT64 PipelineStackSizeInBytes);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12StateObjectProperties_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12StateObjectPropertiesInfo> info_;
};

class ID3D12StateObjectProperties1_Wrapper : public ID3D12StateObjectProperties_Wrapper
{
  public:
    ID3D12StateObjectProperties1_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12StateObjectProperties1_Wrapper*>(u); });

    virtual D3D12_PROGRAM_IDENTIFIER STDMETHODCALLTYPE GetProgramIdentifier(
        LPCWSTR pProgramName);

};

class ID3D12WorkGraphProperties_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12WorkGraphProperties_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12WorkGraphProperties_Wrapper*>(u); });

    ~ID3D12WorkGraphProperties_Wrapper();

    static ID3D12WorkGraphProperties_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12WorkGraphPropertiesInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12WorkGraphPropertiesInfo> GetObjectInfo() { return info_; }

    virtual UINT STDMETHODCALLTYPE GetNumWorkGraphs();

    virtual LPCWSTR STDMETHODCALLTYPE GetProgramName(
        UINT WorkGraphIndex);

    virtual UINT STDMETHODCALLTYPE GetWorkGraphIndex(
        LPCWSTR pProgramName);

    virtual UINT STDMETHODCALLTYPE GetNumNodes(
        UINT WorkGraphIndex);

    virtual D3D12_NODE_ID STDMETHODCALLTYPE GetNodeID(
        UINT WorkGraphIndex,
        UINT NodeIndex);

    virtual UINT STDMETHODCALLTYPE GetNodeIndex(
        UINT WorkGraphIndex,
        D3D12_NODE_ID NodeID);

    virtual UINT STDMETHODCALLTYPE GetNodeLocalRootArgumentsTableIndex(
        UINT WorkGraphIndex,
        UINT NodeIndex);

    virtual UINT STDMETHODCALLTYPE GetNumEntrypoints(
        UINT WorkGraphIndex);

    virtual D3D12_NODE_ID STDMETHODCALLTYPE GetEntrypointID(
        UINT WorkGraphIndex,
        UINT EntrypointIndex);

    virtual UINT STDMETHODCALLTYPE GetEntrypointIndex(
        UINT WorkGraphIndex,
        D3D12_NODE_ID NodeID);

    virtual UINT STDMETHODCALLTYPE GetEntrypointRecordSizeInBytes(
        UINT WorkGraphIndex,
        UINT EntrypointIndex);

    virtual void STDMETHODCALLTYPE GetWorkGraphMemoryRequirements(
        UINT WorkGraphIndex,
        D3D12_WORK_GRAPH_MEMORY_REQUIREMENTS* pWorkGraphMemoryRequirements);

    virtual UINT STDMETHODCALLTYPE GetEntrypointRecordAlignmentInBytes(
        UINT WorkGraphIndex,
        UINT EntrypointIndex);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12WorkGraphProperties_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12WorkGraphPropertiesInfo> info_;
};

class ID3D12Device5_Wrapper : public ID3D12Device4_Wrapper
{
  public:
    ID3D12Device5_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Device5_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE CreateLifetimeTracker(
        ID3D12LifetimeOwner* pOwner,
        REFIID riid,
        void** ppvTracker);

    virtual void STDMETHODCALLTYPE RemoveDevice();

    virtual HRESULT STDMETHODCALLTYPE EnumerateMetaCommands(
        UINT* pNumMetaCommands,
        D3D12_META_COMMAND_DESC* pDescs);

    virtual HRESULT STDMETHODCALLTYPE EnumerateMetaCommandParameters(
        REFGUID CommandId,
        D3D12_META_COMMAND_PARAMETER_STAGE Stage,
        UINT* pTotalStructureSizeInBytes,
        UINT* pParameterCount,
        D3D12_META_COMMAND_PARAMETER_DESC* pParameterDescs);

    virtual HRESULT STDMETHODCALLTYPE CreateMetaCommand(
        REFGUID CommandId,
        UINT NodeMask,
        const void* pCreationParametersData,
        SIZE_T CreationParametersDataSizeInBytes,
        REFIID riid,
        void** ppMetaCommand);

    virtual HRESULT STDMETHODCALLTYPE CreateStateObject(
        const D3D12_STATE_OBJECT_DESC* pDesc,
        REFIID riid,
        void** ppStateObject);

    virtual void STDMETHODCALLTYPE GetRaytracingAccelerationStructurePrebuildInfo(
        const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS* pDesc,
        D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO* pInfo);

    virtual D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS STDMETHODCALLTYPE CheckDriverMatchingIdentifier(
        D3D12_SERIALIZED_DATA_TYPE SerializedDataType,
        const D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER* pIdentifierToCheck);

};

class ID3D12DeviceRemovedExtendedDataSettings_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12DeviceRemovedExtendedDataSettings_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12DeviceRemovedExtendedDataSettings_Wrapper*>(u); });

    ~ID3D12DeviceRemovedExtendedDataSettings_Wrapper();

    static ID3D12DeviceRemovedExtendedDataSettings_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12DeviceRemovedExtendedDataSettingsInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12DeviceRemovedExtendedDataSettingsInfo> GetObjectInfo() { return info_; }

    virtual void STDMETHODCALLTYPE SetAutoBreadcrumbsEnablement(
        D3D12_DRED_ENABLEMENT Enablement);

    virtual void STDMETHODCALLTYPE SetPageFaultEnablement(
        D3D12_DRED_ENABLEMENT Enablement);

    virtual void STDMETHODCALLTYPE SetWatsonDumpEnablement(
        D3D12_DRED_ENABLEMENT Enablement);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12DeviceRemovedExtendedDataSettings_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12DeviceRemovedExtendedDataSettingsInfo> info_;
};

class ID3D12DeviceRemovedExtendedDataSettings1_Wrapper : public ID3D12DeviceRemovedExtendedDataSettings_Wrapper
{
  public:
    ID3D12DeviceRemovedExtendedDataSettings1_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12DeviceRemovedExtendedDataSettings1_Wrapper*>(u); });

    virtual void STDMETHODCALLTYPE SetBreadcrumbContextEnablement(
        D3D12_DRED_ENABLEMENT Enablement);

};

class ID3D12DeviceRemovedExtendedDataSettings2_Wrapper : public ID3D12DeviceRemovedExtendedDataSettings1_Wrapper
{
  public:
    ID3D12DeviceRemovedExtendedDataSettings2_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12DeviceRemovedExtendedDataSettings2_Wrapper*>(u); });

    virtual void STDMETHODCALLTYPE UseMarkersOnlyAutoBreadcrumbs(
        BOOL MarkersOnly);

};

class ID3D12DeviceRemovedExtendedData_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12DeviceRemovedExtendedData_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12DeviceRemovedExtendedData_Wrapper*>(u); });

    ~ID3D12DeviceRemovedExtendedData_Wrapper();

    static ID3D12DeviceRemovedExtendedData_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12DeviceRemovedExtendedDataInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12DeviceRemovedExtendedDataInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE GetAutoBreadcrumbsOutput(
        D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT* pOutput);

    virtual HRESULT STDMETHODCALLTYPE GetPageFaultAllocationOutput(
        D3D12_DRED_PAGE_FAULT_OUTPUT* pOutput);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12DeviceRemovedExtendedData_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12DeviceRemovedExtendedDataInfo> info_;
};

class ID3D12DeviceRemovedExtendedData1_Wrapper : public ID3D12DeviceRemovedExtendedData_Wrapper
{
  public:
    ID3D12DeviceRemovedExtendedData1_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12DeviceRemovedExtendedData1_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE GetAutoBreadcrumbsOutput1(
        D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1* pOutput);

    virtual HRESULT STDMETHODCALLTYPE GetPageFaultAllocationOutput1(
        D3D12_DRED_PAGE_FAULT_OUTPUT1* pOutput);

};

class ID3D12DeviceRemovedExtendedData2_Wrapper : public ID3D12DeviceRemovedExtendedData1_Wrapper
{
  public:
    ID3D12DeviceRemovedExtendedData2_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12DeviceRemovedExtendedData2_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE GetPageFaultAllocationOutput2(
        D3D12_DRED_PAGE_FAULT_OUTPUT2* pOutput);

    virtual D3D12_DRED_DEVICE_STATE STDMETHODCALLTYPE GetDeviceState();

};

class ID3D12Device6_Wrapper : public ID3D12Device5_Wrapper
{
  public:
    ID3D12Device6_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Device6_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE SetBackgroundProcessingMode(
        D3D12_BACKGROUND_PROCESSING_MODE Mode,
        D3D12_MEASUREMENTS_ACTION MeasurementsAction,
        HANDLE hEventToSignalUponCompletion,
        BOOL* pbFurtherMeasurementsDesired);

};

class ID3D12ProtectedResourceSession1_Wrapper : public ID3D12ProtectedResourceSession_Wrapper
{
  public:
    ID3D12ProtectedResourceSession1_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12ProtectedResourceSession1_Wrapper*>(u); });

    virtual D3D12_PROTECTED_RESOURCE_SESSION_DESC1 STDMETHODCALLTYPE GetDesc1();

};

class ID3D12Device7_Wrapper : public ID3D12Device6_Wrapper
{
  public:
    ID3D12Device7_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Device7_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE AddToStateObject(
        const D3D12_STATE_OBJECT_DESC* pAddition,
        ID3D12StateObject* pStateObjectToGrowFrom,
        REFIID riid,
        void** ppNewStateObject);

    virtual HRESULT STDMETHODCALLTYPE CreateProtectedResourceSession1(
        const D3D12_PROTECTED_RESOURCE_SESSION_DESC1* pDesc,
        REFIID riid,
        void** ppSession);

};

class ID3D12Device8_Wrapper : public ID3D12Device7_Wrapper
{
  public:
    ID3D12Device8_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Device8_Wrapper*>(u); });

    virtual D3D12_RESOURCE_ALLOCATION_INFO STDMETHODCALLTYPE GetResourceAllocationInfo2(
        UINT visibleMask,
        UINT numResourceDescs,
        const D3D12_RESOURCE_DESC1* pResourceDescs,
        D3D12_RESOURCE_ALLOCATION_INFO1* pResourceAllocationInfo1);

    virtual HRESULT STDMETHODCALLTYPE CreateCommittedResource2(
        const D3D12_HEAP_PROPERTIES* pHeapProperties,
        D3D12_HEAP_FLAGS HeapFlags,
        const D3D12_RESOURCE_DESC1* pDesc,
        D3D12_RESOURCE_STATES InitialResourceState,
        const D3D12_CLEAR_VALUE* pOptimizedClearValue,
        ID3D12ProtectedResourceSession* pProtectedSession,
        REFIID riidResource,
        void** ppvResource);

    virtual HRESULT STDMETHODCALLTYPE CreatePlacedResource1(
        ID3D12Heap* pHeap,
        UINT64 HeapOffset,
        const D3D12_RESOURCE_DESC1* pDesc,
        D3D12_RESOURCE_STATES InitialState,
        const D3D12_CLEAR_VALUE* pOptimizedClearValue,
        REFIID riid,
        void** ppvResource);

    virtual void STDMETHODCALLTYPE CreateSamplerFeedbackUnorderedAccessView(
        ID3D12Resource* pTargetedResource,
        ID3D12Resource* pFeedbackResource,
        D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

    virtual void STDMETHODCALLTYPE GetCopyableFootprints1(
        const D3D12_RESOURCE_DESC1* pResourceDesc,
        UINT FirstSubresource,
        UINT NumSubresources,
        UINT64 BaseOffset,
        D3D12_PLACED_SUBRESOURCE_FOOTPRINT* pLayouts,
        UINT* pNumRows,
        UINT64* pRowSizeInBytes,
        UINT64* pTotalBytes);

};

class ID3D12Resource1_Wrapper : public ID3D12Resource_Wrapper
{
  public:
    ID3D12Resource1_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Resource1_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE GetProtectedResourceSession(
        REFIID riid,
        void** ppProtectedSession);

};

class ID3D12Resource2_Wrapper : public ID3D12Resource1_Wrapper
{
  public:
    ID3D12Resource2_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Resource2_Wrapper*>(u); });

    virtual D3D12_RESOURCE_DESC1 STDMETHODCALLTYPE GetDesc1();

};

class ID3D12Heap1_Wrapper : public ID3D12Heap_Wrapper
{
  public:
    ID3D12Heap1_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Heap1_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE GetProtectedResourceSession(
        REFIID riid,
        void** ppProtectedSession);

};

class ID3D12GraphicsCommandList3_Wrapper : public ID3D12GraphicsCommandList2_Wrapper
{
  public:
    ID3D12GraphicsCommandList3_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12GraphicsCommandList3_Wrapper*>(u); });

    virtual void STDMETHODCALLTYPE SetProtectedResourceSession(
        ID3D12ProtectedResourceSession* pProtectedResourceSession);

};

class ID3D12MetaCommand_Wrapper : public ID3D12Pageable_Wrapper
{
  public:
    ID3D12MetaCommand_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12MetaCommand_Wrapper*>(u); });

    ~ID3D12MetaCommand_Wrapper();

    static ID3D12MetaCommand_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12MetaCommandInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12MetaCommandInfo> GetObjectInfo() { return info_; }

    virtual UINT64 STDMETHODCALLTYPE GetRequiredParameterResourceSize(
        D3D12_META_COMMAND_PARAMETER_STAGE Stage,
        UINT ParameterIndex);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12MetaCommand_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12MetaCommandInfo> info_;
};

class ID3D12GraphicsCommandList4_Wrapper : public ID3D12GraphicsCommandList3_Wrapper
{
  public:
    ID3D12GraphicsCommandList4_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12GraphicsCommandList4_Wrapper*>(u); });

    virtual void STDMETHODCALLTYPE BeginRenderPass(
        UINT NumRenderTargets,
        const D3D12_RENDER_PASS_RENDER_TARGET_DESC* pRenderTargets,
        const D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* pDepthStencil,
        D3D12_RENDER_PASS_FLAGS Flags);

    virtual void STDMETHODCALLTYPE EndRenderPass();

    virtual void STDMETHODCALLTYPE InitializeMetaCommand(
        ID3D12MetaCommand* pMetaCommand,
        const void* pInitializationParametersData,
        SIZE_T InitializationParametersDataSizeInBytes);

    virtual void STDMETHODCALLTYPE ExecuteMetaCommand(
        ID3D12MetaCommand* pMetaCommand,
        const void* pExecutionParametersData,
        SIZE_T ExecutionParametersDataSizeInBytes);

    virtual void STDMETHODCALLTYPE BuildRaytracingAccelerationStructure(
        const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC* pDesc,
        UINT NumPostbuildInfoDescs,
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* pPostbuildInfoDescs);

    virtual void STDMETHODCALLTYPE EmitRaytracingAccelerationStructurePostbuildInfo(
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* pDesc,
        UINT NumSourceAccelerationStructures,
        const D3D12_GPU_VIRTUAL_ADDRESS* pSourceAccelerationStructureData);

    virtual void STDMETHODCALLTYPE CopyRaytracingAccelerationStructure(
        D3D12_GPU_VIRTUAL_ADDRESS DestAccelerationStructureData,
        D3D12_GPU_VIRTUAL_ADDRESS SourceAccelerationStructureData,
        D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE Mode);

    virtual void STDMETHODCALLTYPE SetPipelineState1(
        ID3D12StateObject* pStateObject);

    virtual void STDMETHODCALLTYPE DispatchRays(
        const D3D12_DISPATCH_RAYS_DESC* pDesc);

};

class ID3D12ShaderCacheSession_Wrapper : public ID3D12DeviceChild_Wrapper
{
  public:
    ID3D12ShaderCacheSession_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12ShaderCacheSession_Wrapper*>(u); });

    ~ID3D12ShaderCacheSession_Wrapper();

    static ID3D12ShaderCacheSession_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12ShaderCacheSessionInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12ShaderCacheSessionInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE FindValue(
        const void* pKey,
        UINT KeySize,
        void* pValue,
        UINT* pValueSize);

    virtual HRESULT STDMETHODCALLTYPE StoreValue(
        const void* pKey,
        UINT KeySize,
        const void* pValue,
        UINT ValueSize);

    virtual void STDMETHODCALLTYPE SetDeleteOnDestroy();

    virtual D3D12_SHADER_CACHE_SESSION_DESC STDMETHODCALLTYPE GetDesc();

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12ShaderCacheSession_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12ShaderCacheSessionInfo> info_;
};

class ID3D12Device9_Wrapper : public ID3D12Device8_Wrapper
{
  public:
    ID3D12Device9_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Device9_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE CreateShaderCacheSession(
        const D3D12_SHADER_CACHE_SESSION_DESC* pDesc,
        REFIID riid,
        void** ppvSession);

    virtual HRESULT STDMETHODCALLTYPE ShaderCacheControl(
        D3D12_SHADER_CACHE_KIND_FLAGS Kinds,
        D3D12_SHADER_CACHE_CONTROL_FLAGS Control);

    virtual HRESULT STDMETHODCALLTYPE CreateCommandQueue1(
        const D3D12_COMMAND_QUEUE_DESC* pDesc,
        REFIID CreatorID,
        REFIID riid,
        void** ppCommandQueue);

};

class ID3D12Device10_Wrapper : public ID3D12Device9_Wrapper
{
  public:
    ID3D12Device10_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Device10_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE CreateCommittedResource3(
        const D3D12_HEAP_PROPERTIES* pHeapProperties,
        D3D12_HEAP_FLAGS HeapFlags,
        const D3D12_RESOURCE_DESC1* pDesc,
        D3D12_BARRIER_LAYOUT InitialLayout,
        const D3D12_CLEAR_VALUE* pOptimizedClearValue,
        ID3D12ProtectedResourceSession* pProtectedSession,
        UINT32 NumCastableFormats,
        const DXGI_FORMAT* pCastableFormats,
        REFIID riidResource,
        void** ppvResource);

    virtual HRESULT STDMETHODCALLTYPE CreatePlacedResource2(
        ID3D12Heap* pHeap,
        UINT64 HeapOffset,
        const D3D12_RESOURCE_DESC1* pDesc,
        D3D12_BARRIER_LAYOUT InitialLayout,
        const D3D12_CLEAR_VALUE* pOptimizedClearValue,
        UINT32 NumCastableFormats,
        const DXGI_FORMAT* pCastableFormats,
        REFIID riid,
        void** ppvResource);

    virtual HRESULT STDMETHODCALLTYPE CreateReservedResource2(
        const D3D12_RESOURCE_DESC* pDesc,
        D3D12_BARRIER_LAYOUT InitialLayout,
        const D3D12_CLEAR_VALUE* pOptimizedClearValue,
        ID3D12ProtectedResourceSession* pProtectedSession,
        UINT32 NumCastableFormats,
        const DXGI_FORMAT* pCastableFormats,
        REFIID riid,
        void** ppvResource);

};

class ID3D12Device11_Wrapper : public ID3D12Device10_Wrapper
{
  public:
    ID3D12Device11_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Device11_Wrapper*>(u); });

    virtual void STDMETHODCALLTYPE CreateSampler2(
        const D3D12_SAMPLER_DESC2* pDesc,
        D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

};

class ID3D12Device12_Wrapper : public ID3D12Device11_Wrapper
{
  public:
    ID3D12Device12_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Device12_Wrapper*>(u); });

    virtual D3D12_RESOURCE_ALLOCATION_INFO STDMETHODCALLTYPE GetResourceAllocationInfo3(
        UINT visibleMask,
        UINT numResourceDescs,
        const D3D12_RESOURCE_DESC1* pResourceDescs,
        const UINT32* pNumCastableFormats,
        const DXGI_FORMAT* const* ppCastableFormats,
        D3D12_RESOURCE_ALLOCATION_INFO1* pResourceAllocationInfo1);

};

class ID3D12Device13_Wrapper : public ID3D12Device12_Wrapper
{
  public:
    ID3D12Device13_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Device13_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE OpenExistingHeapFromAddress1(
        const void* pAddress,
        SIZE_T size,
        REFIID riid,
        void** ppvHeap);

};

class ID3D12Device14_Wrapper : public ID3D12Device13_Wrapper
{
  public:
    ID3D12Device14_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Device14_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE CreateRootSignatureFromSubobjectInLibrary(
        UINT nodeMask,
        const void* pLibraryBlob,
        SIZE_T blobLengthInBytes,
        LPCWSTR subobjectName,
        REFIID riid,
        void** ppvRootSignature);

};

class ID3D12VirtualizationGuestDevice_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12VirtualizationGuestDevice_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12VirtualizationGuestDevice_Wrapper*>(u); });

    ~ID3D12VirtualizationGuestDevice_Wrapper();

    static ID3D12VirtualizationGuestDevice_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12VirtualizationGuestDeviceInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12VirtualizationGuestDeviceInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE ShareWithHost(
        ID3D12DeviceChild* pObject,
        HANDLE* pHandle);

    virtual HRESULT STDMETHODCALLTYPE CreateFenceFd(
        ID3D12Fence* pFence,
        UINT64 FenceValue,
        int* pFenceFd);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12VirtualizationGuestDevice_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12VirtualizationGuestDeviceInfo> info_;
};

class ID3D12Tools_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12Tools_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Tools_Wrapper*>(u); });

    ~ID3D12Tools_Wrapper();

    static ID3D12Tools_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12ToolsInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12ToolsInfo> GetObjectInfo() { return info_; }

    virtual void STDMETHODCALLTYPE EnableShaderInstrumentation(
        BOOL bEnable);

    virtual BOOL STDMETHODCALLTYPE ShaderInstrumentationEnabled();

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12Tools_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12ToolsInfo> info_;
};

class ID3D12Tools1_Wrapper : public ID3D12Tools_Wrapper
{
  public:
    ID3D12Tools1_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Tools1_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE ReserveGPUVARangesAtCreate(
        D3D12_GPU_VIRTUAL_ADDRESS_RANGE* pRanges,
        UINT uiNumRanges);

    virtual void STDMETHODCALLTYPE ClearReservedGPUVARangesList();

};

class ID3D12PageableTools_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12PageableTools_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12PageableTools_Wrapper*>(u); });

    ~ID3D12PageableTools_Wrapper();

    static ID3D12PageableTools_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12PageableToolsInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12PageableToolsInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE GetAllocation(
        D3D12_GPU_VIRTUAL_ADDRESS_RANGE* pAllocation);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12PageableTools_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12PageableToolsInfo> info_;
};

class ID3D12DeviceTools_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12DeviceTools_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12DeviceTools_Wrapper*>(u); });

    ~ID3D12DeviceTools_Wrapper();

    static ID3D12DeviceTools_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12DeviceToolsInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12DeviceToolsInfo> GetObjectInfo() { return info_; }

    virtual void STDMETHODCALLTYPE SetNextAllocationAddress(
        D3D12_GPU_VIRTUAL_ADDRESS nextAllocationVirtualAddress);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12DeviceTools_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12DeviceToolsInfo> info_;
};

class ID3D12SDKConfiguration_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12SDKConfiguration_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12SDKConfiguration_Wrapper*>(u); });

    ~ID3D12SDKConfiguration_Wrapper();

    static ID3D12SDKConfiguration_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12SDKConfigurationInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12SDKConfigurationInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE SetSDKVersion(
        UINT SDKVersion,
        LPCSTR SDKPath);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12SDKConfiguration_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12SDKConfigurationInfo> info_;
};

class ID3D12SDKConfiguration1_Wrapper : public ID3D12SDKConfiguration_Wrapper
{
  public:
    ID3D12SDKConfiguration1_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12SDKConfiguration1_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE CreateDeviceFactory(
        UINT SDKVersion,
        LPCSTR SDKPath,
        REFIID riid,
        void** ppvFactory);

    virtual void STDMETHODCALLTYPE FreeUnusedSDKs();

};

class ID3D12DeviceFactory_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12DeviceFactory_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12DeviceFactory_Wrapper*>(u); });

    ~ID3D12DeviceFactory_Wrapper();

    static ID3D12DeviceFactory_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12DeviceFactoryInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12DeviceFactoryInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE InitializeFromGlobalState();

    virtual HRESULT STDMETHODCALLTYPE ApplyToGlobalState();

    virtual HRESULT STDMETHODCALLTYPE SetFlags(
        D3D12_DEVICE_FACTORY_FLAGS flags);

    virtual D3D12_DEVICE_FACTORY_FLAGS STDMETHODCALLTYPE GetFlags();

    virtual HRESULT STDMETHODCALLTYPE GetConfigurationInterface(
        REFCLSID clsid,
        REFIID iid,
        void** ppv);

    virtual HRESULT STDMETHODCALLTYPE EnableExperimentalFeatures(
        UINT NumFeatures,
        const IID* pIIDs,
        void* pConfigurationStructs,
        UINT* pConfigurationStructSizes);

    virtual HRESULT STDMETHODCALLTYPE CreateDevice(
        IUnknown* adapter,
        D3D_FEATURE_LEVEL FeatureLevel,
        REFIID riid,
        void** ppvDevice);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12DeviceFactory_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12DeviceFactoryInfo> info_;
};

class ID3D12DeviceConfiguration_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12DeviceConfiguration_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12DeviceConfiguration_Wrapper*>(u); });

    ~ID3D12DeviceConfiguration_Wrapper();

    static ID3D12DeviceConfiguration_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12DeviceConfigurationInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12DeviceConfigurationInfo> GetObjectInfo() { return info_; }

    virtual D3D12_DEVICE_CONFIGURATION_DESC STDMETHODCALLTYPE GetDesc();

    virtual HRESULT STDMETHODCALLTYPE GetEnabledExperimentalFeatures(
        GUID* pGuids,
        UINT NumGuids);

    virtual HRESULT STDMETHODCALLTYPE SerializeVersionedRootSignature(
        const D3D12_VERSIONED_ROOT_SIGNATURE_DESC* pDesc,
        ID3DBlob** ppResult,
        ID3DBlob** ppError);

    virtual HRESULT STDMETHODCALLTYPE CreateVersionedRootSignatureDeserializer(
        const void* pBlob,
        SIZE_T Size,
        REFIID riid,
        void** ppvDeserializer);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12DeviceConfiguration_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12DeviceConfigurationInfo> info_;
};

class ID3D12DeviceConfiguration1_Wrapper : public ID3D12DeviceConfiguration_Wrapper
{
  public:
    ID3D12DeviceConfiguration1_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12DeviceConfiguration1_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary(
        const void* pLibraryBlob,
        SIZE_T Size,
        LPCWSTR RootSignatureSubobjectName,
        REFIID riid,
        void** ppvDeserializer);

};

class ID3D12GraphicsCommandList5_Wrapper : public ID3D12GraphicsCommandList4_Wrapper
{
  public:
    ID3D12GraphicsCommandList5_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12GraphicsCommandList5_Wrapper*>(u); });

    virtual void STDMETHODCALLTYPE RSSetShadingRate(
        D3D12_SHADING_RATE baseShadingRate,
        const D3D12_SHADING_RATE_COMBINER* combiners);

    virtual void STDMETHODCALLTYPE RSSetShadingRateImage(
        ID3D12Resource* shadingRateImage);

};

class ID3D12GraphicsCommandList6_Wrapper : public ID3D12GraphicsCommandList5_Wrapper
{
  public:
    ID3D12GraphicsCommandList6_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12GraphicsCommandList6_Wrapper*>(u); });

    virtual void STDMETHODCALLTYPE DispatchMesh(
        UINT ThreadGroupCountX,
        UINT ThreadGroupCountY,
        UINT ThreadGroupCountZ);

};

class ID3D12GraphicsCommandList7_Wrapper : public ID3D12GraphicsCommandList6_Wrapper
{
  public:
    ID3D12GraphicsCommandList7_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12GraphicsCommandList7_Wrapper*>(u); });

    virtual void STDMETHODCALLTYPE Barrier(
        UINT32 NumBarrierGroups,
        const D3D12_BARRIER_GROUP* pBarrierGroups);

};

class ID3D12GraphicsCommandList8_Wrapper : public ID3D12GraphicsCommandList7_Wrapper
{
  public:
    ID3D12GraphicsCommandList8_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12GraphicsCommandList8_Wrapper*>(u); });

    virtual void STDMETHODCALLTYPE OMSetFrontAndBackStencilRef(
        UINT FrontStencilRef,
        UINT BackStencilRef);

};

class ID3D12GraphicsCommandList9_Wrapper : public ID3D12GraphicsCommandList8_Wrapper
{
  public:
    ID3D12GraphicsCommandList9_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12GraphicsCommandList9_Wrapper*>(u); });

    virtual void STDMETHODCALLTYPE RSSetDepthBias(
        FLOAT DepthBias,
        FLOAT DepthBiasClamp,
        FLOAT SlopeScaledDepthBias);

    virtual void STDMETHODCALLTYPE IASetIndexBufferStripCutValue(
        D3D12_INDEX_BUFFER_STRIP_CUT_VALUE IBStripCutValue);

};

class ID3D12GraphicsCommandList10_Wrapper : public ID3D12GraphicsCommandList9_Wrapper
{
  public:
    ID3D12GraphicsCommandList10_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12GraphicsCommandList10_Wrapper*>(u); });

    virtual void STDMETHODCALLTYPE SetProgram(
        const D3D12_SET_PROGRAM_DESC* pDesc);

    virtual void STDMETHODCALLTYPE DispatchGraph(
        const D3D12_DISPATCH_GRAPH_DESC* pDesc);

};

class ID3D12DSRDeviceFactory_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12DSRDeviceFactory_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12DSRDeviceFactory_Wrapper*>(u); });

    ~ID3D12DSRDeviceFactory_Wrapper();

    static ID3D12DSRDeviceFactory_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12DSRDeviceFactoryInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12DSRDeviceFactoryInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE CreateDSRDevice(
        ID3D12Device* pD3D12Device,
        UINT NodeMask,
        REFIID riid,
        void** ppvDSRDevice);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12DSRDeviceFactory_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12DSRDeviceFactoryInfo> info_;
};

class ID3D12GBVDiagnostics_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12GBVDiagnostics_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12GBVDiagnostics_Wrapper*>(u); });

    ~ID3D12GBVDiagnostics_Wrapper();

    static ID3D12GBVDiagnostics_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12GBVDiagnosticsInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12GBVDiagnosticsInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE GetGBVEntireSubresourceStatesData(
        ID3D12Resource* pResource,
        int* pData,
        UINT DataSize);

    virtual HRESULT STDMETHODCALLTYPE GetGBVSubresourceState(
        ID3D12Resource* pResource,
        UINT Subresource,
        int* pData);

    virtual HRESULT STDMETHODCALLTYPE GetGBVResourceUniformState(
        ID3D12Resource* pResource,
        int* pData);

    virtual HRESULT STDMETHODCALLTYPE GetGBVResourceInfo(
        ID3D12Resource* pResource,
        D3D12_RESOURCE_DESC* pResourceDesc,
        UINT32* pResourceHash,
        UINT32* pSubresourceStatesByteOffset);

    virtual void STDMETHODCALLTYPE GBVReserved0();

    virtual void STDMETHODCALLTYPE GBVReserved1();

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12GBVDiagnostics_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12GBVDiagnosticsInfo> info_;
};


/*
** This part is generated from d3dcommon.h in Windows SDK: 10.0.20348.0
**
*/

class ID3D10Blob_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D10Blob_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D10Blob_Wrapper*>(u); });

    ~ID3D10Blob_Wrapper();

    static ID3D10Blob_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D10BlobInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D10BlobInfo> GetObjectInfo() { return info_; }

    virtual LPVOID STDMETHODCALLTYPE GetBufferPointer();

    virtual SIZE_T STDMETHODCALLTYPE GetBufferSize();

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D10Blob_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D10BlobInfo> info_;
};

class ID3DDestructionNotifier_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3DDestructionNotifier_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3DDestructionNotifier_Wrapper*>(u); });

    ~ID3DDestructionNotifier_Wrapper();

    static ID3DDestructionNotifier_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3DDestructionNotifierInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3DDestructionNotifierInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE RegisterDestructionCallback(
        PFN_DESTRUCTION_CALLBACK callbackFn,
        void* pData,
        UINT* pCallbackID);

    virtual HRESULT STDMETHODCALLTYPE UnregisterDestructionCallback(
        UINT callbackID);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3DDestructionNotifier_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3DDestructionNotifierInfo> info_;
};


/*
** This part is generated from d3d12sdklayers.h in Windows SDK: 10.0.20348.0
**
*/

class ID3D12Debug_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12Debug_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Debug_Wrapper*>(u); });

    ~ID3D12Debug_Wrapper();

    static ID3D12Debug_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12DebugInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12DebugInfo> GetObjectInfo() { return info_; }

    virtual void STDMETHODCALLTYPE EnableDebugLayer();

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12Debug_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12DebugInfo> info_;
};

class ID3D12Debug1_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12Debug1_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Debug1_Wrapper*>(u); });

    ~ID3D12Debug1_Wrapper();

    static ID3D12Debug1_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12Debug1Info> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12Debug1Info> GetObjectInfo() { return info_; }

    virtual void STDMETHODCALLTYPE EnableDebugLayer();

    virtual void STDMETHODCALLTYPE SetEnableGPUBasedValidation(
        BOOL Enable);

    virtual void STDMETHODCALLTYPE SetEnableSynchronizedCommandQueueValidation(
        BOOL Enable);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12Debug1_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12Debug1Info> info_;
};

class ID3D12Debug2_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12Debug2_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Debug2_Wrapper*>(u); });

    ~ID3D12Debug2_Wrapper();

    static ID3D12Debug2_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12Debug2Info> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12Debug2Info> GetObjectInfo() { return info_; }

    virtual void STDMETHODCALLTYPE SetGPUBasedValidationFlags(
        D3D12_GPU_BASED_VALIDATION_FLAGS Flags);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12Debug2_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12Debug2Info> info_;
};

class ID3D12Debug3_Wrapper : public ID3D12Debug_Wrapper
{
  public:
    ID3D12Debug3_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Debug3_Wrapper*>(u); });

    virtual void STDMETHODCALLTYPE SetEnableGPUBasedValidation(
        BOOL Enable);

    virtual void STDMETHODCALLTYPE SetEnableSynchronizedCommandQueueValidation(
        BOOL Enable);

    virtual void STDMETHODCALLTYPE SetGPUBasedValidationFlags(
        D3D12_GPU_BASED_VALIDATION_FLAGS Flags);

};

class ID3D12Debug4_Wrapper : public ID3D12Debug3_Wrapper
{
  public:
    ID3D12Debug4_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Debug4_Wrapper*>(u); });

    virtual void STDMETHODCALLTYPE DisableDebugLayer();

};

class ID3D12Debug5_Wrapper : public ID3D12Debug4_Wrapper
{
  public:
    ID3D12Debug5_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Debug5_Wrapper*>(u); });

    virtual void STDMETHODCALLTYPE SetEnableAutoName(
        BOOL Enable);

};

class ID3D12Debug6_Wrapper : public ID3D12Debug5_Wrapper
{
  public:
    ID3D12Debug6_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Debug6_Wrapper*>(u); });

    virtual void STDMETHODCALLTYPE SetForceLegacyBarrierValidation(
        BOOL Enable);

};

class ID3D12DebugDevice1_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12DebugDevice1_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12DebugDevice1_Wrapper*>(u); });

    ~ID3D12DebugDevice1_Wrapper();

    static ID3D12DebugDevice1_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12DebugDevice1Info> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12DebugDevice1Info> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE SetDebugParameter(
        D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type,
        const void* pData,
        UINT DataSize);

    virtual HRESULT STDMETHODCALLTYPE GetDebugParameter(
        D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type,
        void* pData,
        UINT DataSize);

    virtual HRESULT STDMETHODCALLTYPE ReportLiveDeviceObjects(
        D3D12_RLDO_FLAGS Flags);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12DebugDevice1_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12DebugDevice1Info> info_;
};

class ID3D12DebugDevice_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12DebugDevice_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12DebugDevice_Wrapper*>(u); });

    ~ID3D12DebugDevice_Wrapper();

    static ID3D12DebugDevice_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12DebugDeviceInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12DebugDeviceInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE SetFeatureMask(
        D3D12_DEBUG_FEATURE Mask);

    virtual D3D12_DEBUG_FEATURE STDMETHODCALLTYPE GetFeatureMask();

    virtual HRESULT STDMETHODCALLTYPE ReportLiveDeviceObjects(
        D3D12_RLDO_FLAGS Flags);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12DebugDevice_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12DebugDeviceInfo> info_;
};

class ID3D12DebugDevice2_Wrapper : public ID3D12DebugDevice_Wrapper
{
  public:
    ID3D12DebugDevice2_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12DebugDevice2_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE SetDebugParameter(
        D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type,
        const void* pData,
        UINT DataSize);

    virtual HRESULT STDMETHODCALLTYPE GetDebugParameter(
        D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type,
        void* pData,
        UINT DataSize);

};

class ID3D12DebugCommandQueue_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12DebugCommandQueue_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12DebugCommandQueue_Wrapper*>(u); });

    ~ID3D12DebugCommandQueue_Wrapper();

    static ID3D12DebugCommandQueue_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12DebugCommandQueueInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12DebugCommandQueueInfo> GetObjectInfo() { return info_; }

    virtual BOOL STDMETHODCALLTYPE AssertResourceState(
        ID3D12Resource* pResource,
        UINT Subresource,
        UINT State);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12DebugCommandQueue_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12DebugCommandQueueInfo> info_;
};

class ID3D12DebugCommandQueue1_Wrapper : public ID3D12DebugCommandQueue_Wrapper
{
  public:
    ID3D12DebugCommandQueue1_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12DebugCommandQueue1_Wrapper*>(u); });

    virtual void STDMETHODCALLTYPE AssertResourceAccess(
        ID3D12Resource* pResource,
        UINT Subresource,
        D3D12_BARRIER_ACCESS Access);

    virtual void STDMETHODCALLTYPE AssertTextureLayout(
        ID3D12Resource* pResource,
        UINT Subresource,
        D3D12_BARRIER_LAYOUT Layout);

};

class ID3D12DebugCommandList1_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12DebugCommandList1_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12DebugCommandList1_Wrapper*>(u); });

    ~ID3D12DebugCommandList1_Wrapper();

    static ID3D12DebugCommandList1_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12DebugCommandList1Info> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12DebugCommandList1Info> GetObjectInfo() { return info_; }

    virtual BOOL STDMETHODCALLTYPE AssertResourceState(
        ID3D12Resource* pResource,
        UINT Subresource,
        UINT State);

    virtual HRESULT STDMETHODCALLTYPE SetDebugParameter(
        D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type,
        const void* pData,
        UINT DataSize);

    virtual HRESULT STDMETHODCALLTYPE GetDebugParameter(
        D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type,
        void* pData,
        UINT DataSize);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12DebugCommandList1_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12DebugCommandList1Info> info_;
};

class ID3D12DebugCommandList_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12DebugCommandList_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12DebugCommandList_Wrapper*>(u); });

    ~ID3D12DebugCommandList_Wrapper();

    static ID3D12DebugCommandList_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12DebugCommandListInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12DebugCommandListInfo> GetObjectInfo() { return info_; }

    virtual BOOL STDMETHODCALLTYPE AssertResourceState(
        ID3D12Resource* pResource,
        UINT Subresource,
        UINT State);

    virtual HRESULT STDMETHODCALLTYPE SetFeatureMask(
        D3D12_DEBUG_FEATURE Mask);

    virtual D3D12_DEBUG_FEATURE STDMETHODCALLTYPE GetFeatureMask();

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12DebugCommandList_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12DebugCommandListInfo> info_;
};

class ID3D12DebugCommandList2_Wrapper : public ID3D12DebugCommandList_Wrapper
{
  public:
    ID3D12DebugCommandList2_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12DebugCommandList2_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE SetDebugParameter(
        D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type,
        const void* pData,
        UINT DataSize);

    virtual HRESULT STDMETHODCALLTYPE GetDebugParameter(
        D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type,
        void* pData,
        UINT DataSize);

};

class ID3D12DebugCommandList3_Wrapper : public ID3D12DebugCommandList2_Wrapper
{
  public:
    ID3D12DebugCommandList3_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12DebugCommandList3_Wrapper*>(u); });

    virtual void STDMETHODCALLTYPE AssertResourceAccess(
        ID3D12Resource* pResource,
        UINT Subresource,
        D3D12_BARRIER_ACCESS Access);

    virtual void STDMETHODCALLTYPE AssertTextureLayout(
        ID3D12Resource* pResource,
        UINT Subresource,
        D3D12_BARRIER_LAYOUT Layout);

};

class ID3D12SharingContract_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12SharingContract_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12SharingContract_Wrapper*>(u); });

    ~ID3D12SharingContract_Wrapper();

    static ID3D12SharingContract_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12SharingContractInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12SharingContractInfo> GetObjectInfo() { return info_; }

    virtual void STDMETHODCALLTYPE Present(
        ID3D12Resource* pResource,
        UINT Subresource,
        HWND window);

    virtual void STDMETHODCALLTYPE SharedFenceSignal(
        ID3D12Fence* pFence,
        UINT64 FenceValue);

    virtual void STDMETHODCALLTYPE BeginCapturableWork(
        REFGUID guid);

    virtual void STDMETHODCALLTYPE EndCapturableWork(
        REFGUID guid);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12SharingContract_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12SharingContractInfo> info_;
};

class ID3D12ManualWriteTrackingResource_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12ManualWriteTrackingResource_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12ManualWriteTrackingResource_Wrapper*>(u); });

    ~ID3D12ManualWriteTrackingResource_Wrapper();

    static ID3D12ManualWriteTrackingResource_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12ManualWriteTrackingResourceInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12ManualWriteTrackingResourceInfo> GetObjectInfo() { return info_; }

    virtual void STDMETHODCALLTYPE TrackWrite(
        UINT Subresource,
        const D3D12_RANGE* pWrittenRange);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12ManualWriteTrackingResource_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12ManualWriteTrackingResourceInfo> info_;
};

class ID3D12InfoQueue_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12InfoQueue_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12InfoQueue_Wrapper*>(u); });

    ~ID3D12InfoQueue_Wrapper();

    static ID3D12InfoQueue_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D12InfoQueueInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D12InfoQueueInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE SetMessageCountLimit(
        UINT64 MessageCountLimit);

    virtual void STDMETHODCALLTYPE ClearStoredMessages();

    virtual HRESULT STDMETHODCALLTYPE GetMessage(
        UINT64 MessageIndex,
        D3D12_MESSAGE* pMessage,
        SIZE_T* pMessageByteLength);

    virtual UINT64 STDMETHODCALLTYPE GetNumMessagesAllowedByStorageFilter();

    virtual UINT64 STDMETHODCALLTYPE GetNumMessagesDeniedByStorageFilter();

    virtual UINT64 STDMETHODCALLTYPE GetNumStoredMessages();

    virtual UINT64 STDMETHODCALLTYPE GetNumStoredMessagesAllowedByRetrievalFilter();

    virtual UINT64 STDMETHODCALLTYPE GetNumMessagesDiscardedByMessageCountLimit();

    virtual UINT64 STDMETHODCALLTYPE GetMessageCountLimit();

    virtual HRESULT STDMETHODCALLTYPE AddStorageFilterEntries(
        D3D12_INFO_QUEUE_FILTER* pFilter);

    virtual HRESULT STDMETHODCALLTYPE GetStorageFilter(
        D3D12_INFO_QUEUE_FILTER* pFilter,
        SIZE_T* pFilterByteLength);

    virtual void STDMETHODCALLTYPE ClearStorageFilter();

    virtual HRESULT STDMETHODCALLTYPE PushEmptyStorageFilter();

    virtual HRESULT STDMETHODCALLTYPE PushCopyOfStorageFilter();

    virtual HRESULT STDMETHODCALLTYPE PushStorageFilter(
        D3D12_INFO_QUEUE_FILTER* pFilter);

    virtual void STDMETHODCALLTYPE PopStorageFilter();

    virtual UINT STDMETHODCALLTYPE GetStorageFilterStackSize();

    virtual HRESULT STDMETHODCALLTYPE AddRetrievalFilterEntries(
        D3D12_INFO_QUEUE_FILTER* pFilter);

    virtual HRESULT STDMETHODCALLTYPE GetRetrievalFilter(
        D3D12_INFO_QUEUE_FILTER* pFilter,
        SIZE_T* pFilterByteLength);

    virtual void STDMETHODCALLTYPE ClearRetrievalFilter();

    virtual HRESULT STDMETHODCALLTYPE PushEmptyRetrievalFilter();

    virtual HRESULT STDMETHODCALLTYPE PushCopyOfRetrievalFilter();

    virtual HRESULT STDMETHODCALLTYPE PushRetrievalFilter(
        D3D12_INFO_QUEUE_FILTER* pFilter);

    virtual void STDMETHODCALLTYPE PopRetrievalFilter();

    virtual UINT STDMETHODCALLTYPE GetRetrievalFilterStackSize();

    virtual HRESULT STDMETHODCALLTYPE AddMessage(
        D3D12_MESSAGE_CATEGORY Category,
        D3D12_MESSAGE_SEVERITY Severity,
        D3D12_MESSAGE_ID ID,
        LPCSTR pDescription);

    virtual HRESULT STDMETHODCALLTYPE AddApplicationMessage(
        D3D12_MESSAGE_SEVERITY Severity,
        LPCSTR pDescription);

    virtual HRESULT STDMETHODCALLTYPE SetBreakOnCategory(
        D3D12_MESSAGE_CATEGORY Category,
        BOOL bEnable);

    virtual HRESULT STDMETHODCALLTYPE SetBreakOnSeverity(
        D3D12_MESSAGE_SEVERITY Severity,
        BOOL bEnable);

    virtual HRESULT STDMETHODCALLTYPE SetBreakOnID(
        D3D12_MESSAGE_ID ID,
        BOOL bEnable);

    virtual BOOL STDMETHODCALLTYPE GetBreakOnCategory(
        D3D12_MESSAGE_CATEGORY Category);

    virtual BOOL STDMETHODCALLTYPE GetBreakOnSeverity(
        D3D12_MESSAGE_SEVERITY Severity);

    virtual BOOL STDMETHODCALLTYPE GetBreakOnID(
        D3D12_MESSAGE_ID ID);

    virtual void STDMETHODCALLTYPE SetMuteDebugOutput(
        BOOL bMute);

    virtual BOOL STDMETHODCALLTYPE GetMuteDebugOutput();

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D12InfoQueue_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D12InfoQueueInfo> info_;
};

class ID3D12InfoQueue1_Wrapper : public ID3D12InfoQueue_Wrapper
{
  public:
    ID3D12InfoQueue1_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12InfoQueue1_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE RegisterMessageCallback(
        D3D12MessageFunc CallbackFunc,
        D3D12_MESSAGE_CALLBACK_FLAGS CallbackFilterFlags,
        void* pContext,
        DWORD* pCallbackCookie);

    virtual HRESULT STDMETHODCALLTYPE UnregisterMessageCallback(
        DWORD CallbackCookie);

};


/*
** This part is generated from d3d11.h in Windows SDK: 10.0.20348.0
**
*/

HRESULT WINAPI D3D11CreateDevice(
    IDXGIAdapter* pAdapter,
    D3D_DRIVER_TYPE DriverType,
    HMODULE Software,
    UINT Flags,
    const D3D_FEATURE_LEVEL* pFeatureLevels,
    UINT FeatureLevels,
    UINT SDKVersion,
    ID3D11Device** ppDevice,
    D3D_FEATURE_LEVEL* pFeatureLevel,
    ID3D11DeviceContext** ppImmediateContext);

HRESULT WINAPI D3D11CreateDeviceAndSwapChain(
    IDXGIAdapter* pAdapter,
    D3D_DRIVER_TYPE DriverType,
    HMODULE Software,
    UINT Flags,
    const D3D_FEATURE_LEVEL* pFeatureLevels,
    UINT FeatureLevels,
    UINT SDKVersion,
    const DXGI_SWAP_CHAIN_DESC* pSwapChainDesc,
    IDXGISwapChain** ppSwapChain,
    ID3D11Device** ppDevice,
    D3D_FEATURE_LEVEL* pFeatureLevel,
    ID3D11DeviceContext** ppImmediateContext);

class ID3D11DeviceChild_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D11DeviceChild_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11DeviceChild_Wrapper*>(u); });

    virtual void STDMETHODCALLTYPE GetDevice(
        ID3D11Device** ppDevice);

    virtual HRESULT STDMETHODCALLTYPE GetPrivateData(
        REFGUID guid,
        UINT* pDataSize,
        void* pData);

    virtual HRESULT STDMETHODCALLTYPE SetPrivateData(
        REFGUID guid,
        UINT DataSize,
        const void* pData);

    virtual HRESULT STDMETHODCALLTYPE SetPrivateDataInterface(
        REFGUID guid,
        const IUnknown* pData);

};

class ID3D11DepthStencilState_Wrapper : public ID3D11DeviceChild_Wrapper
{
  public:
    ID3D11DepthStencilState_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11DepthStencilState_Wrapper*>(u); });

    ~ID3D11DepthStencilState_Wrapper();

    static ID3D11DepthStencilState_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11DepthStencilStateInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11DepthStencilStateInfo> GetObjectInfo() { return info_; }

    virtual void STDMETHODCALLTYPE GetDesc(
        D3D11_DEPTH_STENCIL_DESC* pDesc);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11DepthStencilState_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11DepthStencilStateInfo> info_;
};

class ID3D11BlendState_Wrapper : public ID3D11DeviceChild_Wrapper
{
  public:
    ID3D11BlendState_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11BlendState_Wrapper*>(u); });

    ~ID3D11BlendState_Wrapper();

    static ID3D11BlendState_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11BlendStateInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11BlendStateInfo> GetObjectInfo() { return info_; }

    virtual void STDMETHODCALLTYPE GetDesc(
        D3D11_BLEND_DESC* pDesc);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11BlendState_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11BlendStateInfo> info_;
};

class ID3D11RasterizerState_Wrapper : public ID3D11DeviceChild_Wrapper
{
  public:
    ID3D11RasterizerState_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11RasterizerState_Wrapper*>(u); });

    ~ID3D11RasterizerState_Wrapper();

    static ID3D11RasterizerState_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11RasterizerStateInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11RasterizerStateInfo> GetObjectInfo() { return info_; }

    virtual void STDMETHODCALLTYPE GetDesc(
        D3D11_RASTERIZER_DESC* pDesc);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11RasterizerState_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11RasterizerStateInfo> info_;
};

class ID3D11Resource_Wrapper : public ID3D11DeviceChild_Wrapper
{
  public:
    ID3D11Resource_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11Resource_Wrapper*>(u); });

    virtual void STDMETHODCALLTYPE GetType(
        D3D11_RESOURCE_DIMENSION* pResourceDimension);

    virtual void STDMETHODCALLTYPE SetEvictionPriority(
        UINT EvictionPriority);

    virtual UINT STDMETHODCALLTYPE GetEvictionPriority();

};

class ID3D11Buffer_Wrapper : public ID3D11Resource_Wrapper
{
  public:
    ID3D11Buffer_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11Buffer_Wrapper*>(u); });

    ~ID3D11Buffer_Wrapper();

    static ID3D11Buffer_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11BufferInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11BufferInfo> GetObjectInfo() { return info_; }

    virtual void STDMETHODCALLTYPE GetDesc(
        D3D11_BUFFER_DESC* pDesc);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11Buffer_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11BufferInfo> info_;
};

class ID3D11Texture1D_Wrapper : public ID3D11Resource_Wrapper
{
  public:
    ID3D11Texture1D_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11Texture1D_Wrapper*>(u); });

    ~ID3D11Texture1D_Wrapper();

    static ID3D11Texture1D_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11Texture1DInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11Texture1DInfo> GetObjectInfo() { return info_; }

    virtual void STDMETHODCALLTYPE GetDesc(
        D3D11_TEXTURE1D_DESC* pDesc);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11Texture1D_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11Texture1DInfo> info_;
};

class ID3D11Texture2D_Wrapper : public ID3D11Resource_Wrapper
{
  public:
    ID3D11Texture2D_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11Texture2D_Wrapper*>(u); });

    ~ID3D11Texture2D_Wrapper();

    static ID3D11Texture2D_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11Texture2DInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11Texture2DInfo> GetObjectInfo() { return info_; }

    virtual void STDMETHODCALLTYPE GetDesc(
        D3D11_TEXTURE2D_DESC* pDesc);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11Texture2D_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11Texture2DInfo> info_;
};

class ID3D11Texture3D_Wrapper : public ID3D11Resource_Wrapper
{
  public:
    ID3D11Texture3D_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11Texture3D_Wrapper*>(u); });

    ~ID3D11Texture3D_Wrapper();

    static ID3D11Texture3D_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11Texture3DInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11Texture3DInfo> GetObjectInfo() { return info_; }

    virtual void STDMETHODCALLTYPE GetDesc(
        D3D11_TEXTURE3D_DESC* pDesc);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11Texture3D_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11Texture3DInfo> info_;
};

class ID3D11View_Wrapper : public ID3D11DeviceChild_Wrapper
{
  public:
    ID3D11View_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11View_Wrapper*>(u); });

    virtual void STDMETHODCALLTYPE GetResource(
        ID3D11Resource** ppResource);

};

class ID3D11ShaderResourceView_Wrapper : public ID3D11View_Wrapper
{
  public:
    ID3D11ShaderResourceView_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11ShaderResourceView_Wrapper*>(u); });

    ~ID3D11ShaderResourceView_Wrapper();

    static ID3D11ShaderResourceView_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11ShaderResourceViewInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11ShaderResourceViewInfo> GetObjectInfo() { return info_; }

    virtual void STDMETHODCALLTYPE GetDesc(
        D3D11_SHADER_RESOURCE_VIEW_DESC* pDesc);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11ShaderResourceView_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11ShaderResourceViewInfo> info_;
};

class ID3D11RenderTargetView_Wrapper : public ID3D11View_Wrapper
{
  public:
    ID3D11RenderTargetView_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11RenderTargetView_Wrapper*>(u); });

    ~ID3D11RenderTargetView_Wrapper();

    static ID3D11RenderTargetView_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11RenderTargetViewInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11RenderTargetViewInfo> GetObjectInfo() { return info_; }

    virtual void STDMETHODCALLTYPE GetDesc(
        D3D11_RENDER_TARGET_VIEW_DESC* pDesc);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11RenderTargetView_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11RenderTargetViewInfo> info_;
};

class ID3D11DepthStencilView_Wrapper : public ID3D11View_Wrapper
{
  public:
    ID3D11DepthStencilView_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11DepthStencilView_Wrapper*>(u); });

    ~ID3D11DepthStencilView_Wrapper();

    static ID3D11DepthStencilView_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11DepthStencilViewInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11DepthStencilViewInfo> GetObjectInfo() { return info_; }

    virtual void STDMETHODCALLTYPE GetDesc(
        D3D11_DEPTH_STENCIL_VIEW_DESC* pDesc);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11DepthStencilView_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11DepthStencilViewInfo> info_;
};

class ID3D11UnorderedAccessView_Wrapper : public ID3D11View_Wrapper
{
  public:
    ID3D11UnorderedAccessView_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11UnorderedAccessView_Wrapper*>(u); });

    ~ID3D11UnorderedAccessView_Wrapper();

    static ID3D11UnorderedAccessView_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11UnorderedAccessViewInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11UnorderedAccessViewInfo> GetObjectInfo() { return info_; }

    virtual void STDMETHODCALLTYPE GetDesc(
        D3D11_UNORDERED_ACCESS_VIEW_DESC* pDesc);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11UnorderedAccessView_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11UnorderedAccessViewInfo> info_;
};

class ID3D11VertexShader_Wrapper : public ID3D11DeviceChild_Wrapper
{
  public:
    ID3D11VertexShader_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11VertexShader_Wrapper*>(u); });

    ~ID3D11VertexShader_Wrapper();

    static ID3D11VertexShader_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11VertexShaderInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11VertexShaderInfo> GetObjectInfo() { return info_; }

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11VertexShader_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11VertexShaderInfo> info_;
};

class ID3D11HullShader_Wrapper : public ID3D11DeviceChild_Wrapper
{
  public:
    ID3D11HullShader_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11HullShader_Wrapper*>(u); });

    ~ID3D11HullShader_Wrapper();

    static ID3D11HullShader_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11HullShaderInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11HullShaderInfo> GetObjectInfo() { return info_; }

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11HullShader_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11HullShaderInfo> info_;
};

class ID3D11DomainShader_Wrapper : public ID3D11DeviceChild_Wrapper
{
  public:
    ID3D11DomainShader_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11DomainShader_Wrapper*>(u); });

    ~ID3D11DomainShader_Wrapper();

    static ID3D11DomainShader_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11DomainShaderInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11DomainShaderInfo> GetObjectInfo() { return info_; }

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11DomainShader_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11DomainShaderInfo> info_;
};

class ID3D11GeometryShader_Wrapper : public ID3D11DeviceChild_Wrapper
{
  public:
    ID3D11GeometryShader_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11GeometryShader_Wrapper*>(u); });

    ~ID3D11GeometryShader_Wrapper();

    static ID3D11GeometryShader_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11GeometryShaderInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11GeometryShaderInfo> GetObjectInfo() { return info_; }

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11GeometryShader_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11GeometryShaderInfo> info_;
};

class ID3D11PixelShader_Wrapper : public ID3D11DeviceChild_Wrapper
{
  public:
    ID3D11PixelShader_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11PixelShader_Wrapper*>(u); });

    ~ID3D11PixelShader_Wrapper();

    static ID3D11PixelShader_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11PixelShaderInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11PixelShaderInfo> GetObjectInfo() { return info_; }

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11PixelShader_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11PixelShaderInfo> info_;
};

class ID3D11ComputeShader_Wrapper : public ID3D11DeviceChild_Wrapper
{
  public:
    ID3D11ComputeShader_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11ComputeShader_Wrapper*>(u); });

    ~ID3D11ComputeShader_Wrapper();

    static ID3D11ComputeShader_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11ComputeShaderInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11ComputeShaderInfo> GetObjectInfo() { return info_; }

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11ComputeShader_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11ComputeShaderInfo> info_;
};

class ID3D11InputLayout_Wrapper : public ID3D11DeviceChild_Wrapper
{
  public:
    ID3D11InputLayout_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11InputLayout_Wrapper*>(u); });

    ~ID3D11InputLayout_Wrapper();

    static ID3D11InputLayout_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11InputLayoutInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11InputLayoutInfo> GetObjectInfo() { return info_; }

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11InputLayout_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11InputLayoutInfo> info_;
};

class ID3D11SamplerState_Wrapper : public ID3D11DeviceChild_Wrapper
{
  public:
    ID3D11SamplerState_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11SamplerState_Wrapper*>(u); });

    ~ID3D11SamplerState_Wrapper();

    static ID3D11SamplerState_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11SamplerStateInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11SamplerStateInfo> GetObjectInfo() { return info_; }

    virtual void STDMETHODCALLTYPE GetDesc(
        D3D11_SAMPLER_DESC* pDesc);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11SamplerState_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11SamplerStateInfo> info_;
};

class ID3D11Asynchronous_Wrapper : public ID3D11DeviceChild_Wrapper
{
  public:
    ID3D11Asynchronous_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11Asynchronous_Wrapper*>(u); });

    virtual UINT STDMETHODCALLTYPE GetDataSize();

};

class ID3D11Query_Wrapper : public ID3D11Asynchronous_Wrapper
{
  public:
    ID3D11Query_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11Query_Wrapper*>(u); });

    virtual void STDMETHODCALLTYPE GetDesc(
        D3D11_QUERY_DESC* pDesc);

};

class ID3D11Predicate_Wrapper : public ID3D11Query_Wrapper
{
  public:
    ID3D11Predicate_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11Predicate_Wrapper*>(u); });

    ~ID3D11Predicate_Wrapper();

    static ID3D11Predicate_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11PredicateInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11PredicateInfo> GetObjectInfo() { return info_; }

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11Predicate_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11PredicateInfo> info_;
};

class ID3D11Counter_Wrapper : public ID3D11Asynchronous_Wrapper
{
  public:
    ID3D11Counter_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11Counter_Wrapper*>(u); });

    ~ID3D11Counter_Wrapper();

    static ID3D11Counter_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11CounterInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11CounterInfo> GetObjectInfo() { return info_; }

    virtual void STDMETHODCALLTYPE GetDesc(
        D3D11_COUNTER_DESC* pDesc);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11Counter_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11CounterInfo> info_;
};

class ID3D11ClassInstance_Wrapper : public ID3D11DeviceChild_Wrapper
{
  public:
    ID3D11ClassInstance_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11ClassInstance_Wrapper*>(u); });

    ~ID3D11ClassInstance_Wrapper();

    static ID3D11ClassInstance_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11ClassInstanceInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11ClassInstanceInfo> GetObjectInfo() { return info_; }

    virtual void STDMETHODCALLTYPE GetClassLinkage(
        ID3D11ClassLinkage** ppLinkage);

    virtual void STDMETHODCALLTYPE GetDesc(
        D3D11_CLASS_INSTANCE_DESC* pDesc);

    virtual void STDMETHODCALLTYPE GetInstanceName(
        LPSTR pInstanceName,
        SIZE_T* pBufferLength);

    virtual void STDMETHODCALLTYPE GetTypeName(
        LPSTR pTypeName,
        SIZE_T* pBufferLength);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11ClassInstance_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11ClassInstanceInfo> info_;
};

class ID3D11ClassLinkage_Wrapper : public ID3D11DeviceChild_Wrapper
{
  public:
    ID3D11ClassLinkage_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11ClassLinkage_Wrapper*>(u); });

    ~ID3D11ClassLinkage_Wrapper();

    static ID3D11ClassLinkage_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11ClassLinkageInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11ClassLinkageInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE GetClassInstance(
        LPCSTR pClassInstanceName,
        UINT InstanceIndex,
        ID3D11ClassInstance** ppInstance);

    virtual HRESULT STDMETHODCALLTYPE CreateClassInstance(
        LPCSTR pClassTypeName,
        UINT ConstantBufferOffset,
        UINT ConstantVectorOffset,
        UINT TextureOffset,
        UINT SamplerOffset,
        ID3D11ClassInstance** ppInstance);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11ClassLinkage_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11ClassLinkageInfo> info_;
};

class ID3D11CommandList_Wrapper : public ID3D11DeviceChild_Wrapper
{
  public:
    ID3D11CommandList_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11CommandList_Wrapper*>(u); });

    ~ID3D11CommandList_Wrapper();

    static ID3D11CommandList_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11CommandListInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11CommandListInfo> GetObjectInfo() { return info_; }

    virtual UINT STDMETHODCALLTYPE GetContextFlags();

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11CommandList_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11CommandListInfo> info_;
};

class ID3D11DeviceContext_Wrapper : public ID3D11DeviceChild_Wrapper
{
  public:
    ID3D11DeviceContext_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11DeviceContext_Wrapper*>(u); });

    ~ID3D11DeviceContext_Wrapper();

    static ID3D11DeviceContext_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11DeviceContextInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11DeviceContextInfo> GetObjectInfo() { return info_; }

    virtual void STDMETHODCALLTYPE VSSetConstantBuffers(
        UINT StartSlot,
        UINT NumBuffers,
        ID3D11Buffer* const* ppConstantBuffers);

    virtual void STDMETHODCALLTYPE PSSetShaderResources(
        UINT StartSlot,
        UINT NumViews,
        ID3D11ShaderResourceView* const* ppShaderResourceViews);

    virtual void STDMETHODCALLTYPE PSSetShader(
        ID3D11PixelShader* pPixelShader,
        ID3D11ClassInstance* const* ppClassInstances,
        UINT NumClassInstances);

    virtual void STDMETHODCALLTYPE PSSetSamplers(
        UINT StartSlot,
        UINT NumSamplers,
        ID3D11SamplerState* const* ppSamplers);

    virtual void STDMETHODCALLTYPE VSSetShader(
        ID3D11VertexShader* pVertexShader,
        ID3D11ClassInstance* const* ppClassInstances,
        UINT NumClassInstances);

    virtual void STDMETHODCALLTYPE DrawIndexed(
        UINT IndexCount,
        UINT StartIndexLocation,
        INT BaseVertexLocation);

    virtual void STDMETHODCALLTYPE Draw(
        UINT VertexCount,
        UINT StartVertexLocation);

    virtual HRESULT STDMETHODCALLTYPE Map(
        ID3D11Resource* pResource,
        UINT Subresource,
        D3D11_MAP MapType,
        UINT MapFlags,
        D3D11_MAPPED_SUBRESOURCE* pMappedResource);

    virtual void STDMETHODCALLTYPE Unmap(
        ID3D11Resource* pResource,
        UINT Subresource);

    virtual void STDMETHODCALLTYPE PSSetConstantBuffers(
        UINT StartSlot,
        UINT NumBuffers,
        ID3D11Buffer* const* ppConstantBuffers);

    virtual void STDMETHODCALLTYPE IASetInputLayout(
        ID3D11InputLayout* pInputLayout);

    virtual void STDMETHODCALLTYPE IASetVertexBuffers(
        UINT StartSlot,
        UINT NumBuffers,
        ID3D11Buffer* const* ppVertexBuffers,
        const UINT* pStrides,
        const UINT* pOffsets);

    virtual void STDMETHODCALLTYPE IASetIndexBuffer(
        ID3D11Buffer* pIndexBuffer,
        DXGI_FORMAT Format,
        UINT Offset);

    virtual void STDMETHODCALLTYPE DrawIndexedInstanced(
        UINT IndexCountPerInstance,
        UINT InstanceCount,
        UINT StartIndexLocation,
        INT BaseVertexLocation,
        UINT StartInstanceLocation);

    virtual void STDMETHODCALLTYPE DrawInstanced(
        UINT VertexCountPerInstance,
        UINT InstanceCount,
        UINT StartVertexLocation,
        UINT StartInstanceLocation);

    virtual void STDMETHODCALLTYPE GSSetConstantBuffers(
        UINT StartSlot,
        UINT NumBuffers,
        ID3D11Buffer* const* ppConstantBuffers);

    virtual void STDMETHODCALLTYPE GSSetShader(
        ID3D11GeometryShader* pShader,
        ID3D11ClassInstance* const* ppClassInstances,
        UINT NumClassInstances);

    virtual void STDMETHODCALLTYPE IASetPrimitiveTopology(
        D3D11_PRIMITIVE_TOPOLOGY Topology);

    virtual void STDMETHODCALLTYPE VSSetShaderResources(
        UINT StartSlot,
        UINT NumViews,
        ID3D11ShaderResourceView* const* ppShaderResourceViews);

    virtual void STDMETHODCALLTYPE VSSetSamplers(
        UINT StartSlot,
        UINT NumSamplers,
        ID3D11SamplerState* const* ppSamplers);

    virtual void STDMETHODCALLTYPE Begin(
        ID3D11Asynchronous* pAsync);

    virtual void STDMETHODCALLTYPE End(
        ID3D11Asynchronous* pAsync);

    virtual HRESULT STDMETHODCALLTYPE GetData(
        ID3D11Asynchronous* pAsync,
        void* pData,
        UINT DataSize,
        UINT GetDataFlags);

    virtual void STDMETHODCALLTYPE SetPredication(
        ID3D11Predicate* pPredicate,
        BOOL PredicateValue);

    virtual void STDMETHODCALLTYPE GSSetShaderResources(
        UINT StartSlot,
        UINT NumViews,
        ID3D11ShaderResourceView* const* ppShaderResourceViews);

    virtual void STDMETHODCALLTYPE GSSetSamplers(
        UINT StartSlot,
        UINT NumSamplers,
        ID3D11SamplerState* const* ppSamplers);

    virtual void STDMETHODCALLTYPE OMSetRenderTargets(
        UINT NumViews,
        ID3D11RenderTargetView* const* ppRenderTargetViews,
        ID3D11DepthStencilView* pDepthStencilView);

    virtual void STDMETHODCALLTYPE OMSetRenderTargetsAndUnorderedAccessViews(
        UINT NumRTVs,
        ID3D11RenderTargetView* const* ppRenderTargetViews,
        ID3D11DepthStencilView* pDepthStencilView,
        UINT UAVStartSlot,
        UINT NumUAVs,
        ID3D11UnorderedAccessView* const* ppUnorderedAccessViews,
        const UINT* pUAVInitialCounts);

    virtual void STDMETHODCALLTYPE OMSetBlendState(
        ID3D11BlendState* pBlendState,
        const FLOAT BlendFactor [4],
        UINT SampleMask);

    virtual void STDMETHODCALLTYPE OMSetDepthStencilState(
        ID3D11DepthStencilState* pDepthStencilState,
        UINT StencilRef);

    virtual void STDMETHODCALLTYPE SOSetTargets(
        UINT NumBuffers,
        ID3D11Buffer* const* ppSOTargets,
        const UINT* pOffsets);

    virtual void STDMETHODCALLTYPE DrawAuto();

    virtual void STDMETHODCALLTYPE DrawIndexedInstancedIndirect(
        ID3D11Buffer* pBufferForArgs,
        UINT AlignedByteOffsetForArgs);

    virtual void STDMETHODCALLTYPE DrawInstancedIndirect(
        ID3D11Buffer* pBufferForArgs,
        UINT AlignedByteOffsetForArgs);

    virtual void STDMETHODCALLTYPE Dispatch(
        UINT ThreadGroupCountX,
        UINT ThreadGroupCountY,
        UINT ThreadGroupCountZ);

    virtual void STDMETHODCALLTYPE DispatchIndirect(
        ID3D11Buffer* pBufferForArgs,
        UINT AlignedByteOffsetForArgs);

    virtual void STDMETHODCALLTYPE RSSetState(
        ID3D11RasterizerState* pRasterizerState);

    virtual void STDMETHODCALLTYPE RSSetViewports(
        UINT NumViewports,
        const D3D11_VIEWPORT* pViewports);

    virtual void STDMETHODCALLTYPE RSSetScissorRects(
        UINT NumRects,
        const D3D11_RECT* pRects);

    virtual void STDMETHODCALLTYPE CopySubresourceRegion(
        ID3D11Resource* pDstResource,
        UINT DstSubresource,
        UINT DstX,
        UINT DstY,
        UINT DstZ,
        ID3D11Resource* pSrcResource,
        UINT SrcSubresource,
        const D3D11_BOX* pSrcBox);

    virtual void STDMETHODCALLTYPE CopyResource(
        ID3D11Resource* pDstResource,
        ID3D11Resource* pSrcResource);

    virtual void STDMETHODCALLTYPE UpdateSubresource(
        ID3D11Resource* pDstResource,
        UINT DstSubresource,
        const D3D11_BOX* pDstBox,
        const void* pSrcData,
        UINT SrcRowPitch,
        UINT SrcDepthPitch);

    virtual void STDMETHODCALLTYPE CopyStructureCount(
        ID3D11Buffer* pDstBuffer,
        UINT DstAlignedByteOffset,
        ID3D11UnorderedAccessView* pSrcView);

    virtual void STDMETHODCALLTYPE ClearRenderTargetView(
        ID3D11RenderTargetView* pRenderTargetView,
        const FLOAT ColorRGBA [4]);

    virtual void STDMETHODCALLTYPE ClearUnorderedAccessViewUint(
        ID3D11UnorderedAccessView* pUnorderedAccessView,
        const UINT Values [4]);

    virtual void STDMETHODCALLTYPE ClearUnorderedAccessViewFloat(
        ID3D11UnorderedAccessView* pUnorderedAccessView,
        const FLOAT Values [4]);

    virtual void STDMETHODCALLTYPE ClearDepthStencilView(
        ID3D11DepthStencilView* pDepthStencilView,
        UINT ClearFlags,
        FLOAT Depth,
        UINT8 Stencil);

    virtual void STDMETHODCALLTYPE GenerateMips(
        ID3D11ShaderResourceView* pShaderResourceView);

    virtual void STDMETHODCALLTYPE SetResourceMinLOD(
        ID3D11Resource* pResource,
        FLOAT MinLOD);

    virtual FLOAT STDMETHODCALLTYPE GetResourceMinLOD(
        ID3D11Resource* pResource);

    virtual void STDMETHODCALLTYPE ResolveSubresource(
        ID3D11Resource* pDstResource,
        UINT DstSubresource,
        ID3D11Resource* pSrcResource,
        UINT SrcSubresource,
        DXGI_FORMAT Format);

    virtual void STDMETHODCALLTYPE ExecuteCommandList(
        ID3D11CommandList* pCommandList,
        BOOL RestoreContextState);

    virtual void STDMETHODCALLTYPE HSSetShaderResources(
        UINT StartSlot,
        UINT NumViews,
        ID3D11ShaderResourceView* const* ppShaderResourceViews);

    virtual void STDMETHODCALLTYPE HSSetShader(
        ID3D11HullShader* pHullShader,
        ID3D11ClassInstance* const* ppClassInstances,
        UINT NumClassInstances);

    virtual void STDMETHODCALLTYPE HSSetSamplers(
        UINT StartSlot,
        UINT NumSamplers,
        ID3D11SamplerState* const* ppSamplers);

    virtual void STDMETHODCALLTYPE HSSetConstantBuffers(
        UINT StartSlot,
        UINT NumBuffers,
        ID3D11Buffer* const* ppConstantBuffers);

    virtual void STDMETHODCALLTYPE DSSetShaderResources(
        UINT StartSlot,
        UINT NumViews,
        ID3D11ShaderResourceView* const* ppShaderResourceViews);

    virtual void STDMETHODCALLTYPE DSSetShader(
        ID3D11DomainShader* pDomainShader,
        ID3D11ClassInstance* const* ppClassInstances,
        UINT NumClassInstances);

    virtual void STDMETHODCALLTYPE DSSetSamplers(
        UINT StartSlot,
        UINT NumSamplers,
        ID3D11SamplerState* const* ppSamplers);

    virtual void STDMETHODCALLTYPE DSSetConstantBuffers(
        UINT StartSlot,
        UINT NumBuffers,
        ID3D11Buffer* const* ppConstantBuffers);

    virtual void STDMETHODCALLTYPE CSSetShaderResources(
        UINT StartSlot,
        UINT NumViews,
        ID3D11ShaderResourceView* const* ppShaderResourceViews);

    virtual void STDMETHODCALLTYPE CSSetUnorderedAccessViews(
        UINT StartSlot,
        UINT NumUAVs,
        ID3D11UnorderedAccessView* const* ppUnorderedAccessViews,
        const UINT* pUAVInitialCounts);

    virtual void STDMETHODCALLTYPE CSSetShader(
        ID3D11ComputeShader* pComputeShader,
        ID3D11ClassInstance* const* ppClassInstances,
        UINT NumClassInstances);

    virtual void STDMETHODCALLTYPE CSSetSamplers(
        UINT StartSlot,
        UINT NumSamplers,
        ID3D11SamplerState* const* ppSamplers);

    virtual void STDMETHODCALLTYPE CSSetConstantBuffers(
        UINT StartSlot,
        UINT NumBuffers,
        ID3D11Buffer* const* ppConstantBuffers);

    virtual void STDMETHODCALLTYPE VSGetConstantBuffers(
        UINT StartSlot,
        UINT NumBuffers,
        ID3D11Buffer** ppConstantBuffers);

    virtual void STDMETHODCALLTYPE PSGetShaderResources(
        UINT StartSlot,
        UINT NumViews,
        ID3D11ShaderResourceView** ppShaderResourceViews);

    virtual void STDMETHODCALLTYPE PSGetShader(
        ID3D11PixelShader** ppPixelShader,
        ID3D11ClassInstance** ppClassInstances,
        UINT* pNumClassInstances);

    virtual void STDMETHODCALLTYPE PSGetSamplers(
        UINT StartSlot,
        UINT NumSamplers,
        ID3D11SamplerState** ppSamplers);

    virtual void STDMETHODCALLTYPE VSGetShader(
        ID3D11VertexShader** ppVertexShader,
        ID3D11ClassInstance** ppClassInstances,
        UINT* pNumClassInstances);

    virtual void STDMETHODCALLTYPE PSGetConstantBuffers(
        UINT StartSlot,
        UINT NumBuffers,
        ID3D11Buffer** ppConstantBuffers);

    virtual void STDMETHODCALLTYPE IAGetInputLayout(
        ID3D11InputLayout** ppInputLayout);

    virtual void STDMETHODCALLTYPE IAGetVertexBuffers(
        UINT StartSlot,
        UINT NumBuffers,
        ID3D11Buffer** ppVertexBuffers,
        UINT* pStrides,
        UINT* pOffsets);

    virtual void STDMETHODCALLTYPE IAGetIndexBuffer(
        ID3D11Buffer** pIndexBuffer,
        DXGI_FORMAT* Format,
        UINT* Offset);

    virtual void STDMETHODCALLTYPE GSGetConstantBuffers(
        UINT StartSlot,
        UINT NumBuffers,
        ID3D11Buffer** ppConstantBuffers);

    virtual void STDMETHODCALLTYPE GSGetShader(
        ID3D11GeometryShader** ppGeometryShader,
        ID3D11ClassInstance** ppClassInstances,
        UINT* pNumClassInstances);

    virtual void STDMETHODCALLTYPE IAGetPrimitiveTopology(
        D3D11_PRIMITIVE_TOPOLOGY* pTopology);

    virtual void STDMETHODCALLTYPE VSGetShaderResources(
        UINT StartSlot,
        UINT NumViews,
        ID3D11ShaderResourceView** ppShaderResourceViews);

    virtual void STDMETHODCALLTYPE VSGetSamplers(
        UINT StartSlot,
        UINT NumSamplers,
        ID3D11SamplerState** ppSamplers);

    virtual void STDMETHODCALLTYPE GetPredication(
        ID3D11Predicate** ppPredicate,
        BOOL* pPredicateValue);

    virtual void STDMETHODCALLTYPE GSGetShaderResources(
        UINT StartSlot,
        UINT NumViews,
        ID3D11ShaderResourceView** ppShaderResourceViews);

    virtual void STDMETHODCALLTYPE GSGetSamplers(
        UINT StartSlot,
        UINT NumSamplers,
        ID3D11SamplerState** ppSamplers);

    virtual void STDMETHODCALLTYPE OMGetRenderTargets(
        UINT NumViews,
        ID3D11RenderTargetView** ppRenderTargetViews,
        ID3D11DepthStencilView** ppDepthStencilView);

    virtual void STDMETHODCALLTYPE OMGetRenderTargetsAndUnorderedAccessViews(
        UINT NumRTVs,
        ID3D11RenderTargetView** ppRenderTargetViews,
        ID3D11DepthStencilView** ppDepthStencilView,
        UINT UAVStartSlot,
        UINT NumUAVs,
        ID3D11UnorderedAccessView** ppUnorderedAccessViews);

    virtual void STDMETHODCALLTYPE OMGetBlendState(
        ID3D11BlendState** ppBlendState,
        FLOAT BlendFactor [4],
        UINT* pSampleMask);

    virtual void STDMETHODCALLTYPE OMGetDepthStencilState(
        ID3D11DepthStencilState** ppDepthStencilState,
        UINT* pStencilRef);

    virtual void STDMETHODCALLTYPE SOGetTargets(
        UINT NumBuffers,
        ID3D11Buffer** ppSOTargets);

    virtual void STDMETHODCALLTYPE RSGetState(
        ID3D11RasterizerState** ppRasterizerState);

    virtual void STDMETHODCALLTYPE RSGetViewports(
        UINT* pNumViewports,
        D3D11_VIEWPORT* pViewports);

    virtual void STDMETHODCALLTYPE RSGetScissorRects(
        UINT* pNumRects,
        D3D11_RECT* pRects);

    virtual void STDMETHODCALLTYPE HSGetShaderResources(
        UINT StartSlot,
        UINT NumViews,
        ID3D11ShaderResourceView** ppShaderResourceViews);

    virtual void STDMETHODCALLTYPE HSGetShader(
        ID3D11HullShader** ppHullShader,
        ID3D11ClassInstance** ppClassInstances,
        UINT* pNumClassInstances);

    virtual void STDMETHODCALLTYPE HSGetSamplers(
        UINT StartSlot,
        UINT NumSamplers,
        ID3D11SamplerState** ppSamplers);

    virtual void STDMETHODCALLTYPE HSGetConstantBuffers(
        UINT StartSlot,
        UINT NumBuffers,
        ID3D11Buffer** ppConstantBuffers);

    virtual void STDMETHODCALLTYPE DSGetShaderResources(
        UINT StartSlot,
        UINT NumViews,
        ID3D11ShaderResourceView** ppShaderResourceViews);

    virtual void STDMETHODCALLTYPE DSGetShader(
        ID3D11DomainShader** ppDomainShader,
        ID3D11ClassInstance** ppClassInstances,
        UINT* pNumClassInstances);

    virtual void STDMETHODCALLTYPE DSGetSamplers(
        UINT StartSlot,
        UINT NumSamplers,
        ID3D11SamplerState** ppSamplers);

    virtual void STDMETHODCALLTYPE DSGetConstantBuffers(
        UINT StartSlot,
        UINT NumBuffers,
        ID3D11Buffer** ppConstantBuffers);

    virtual void STDMETHODCALLTYPE CSGetShaderResources(
        UINT StartSlot,
        UINT NumViews,
        ID3D11ShaderResourceView** ppShaderResourceViews);

    virtual void STDMETHODCALLTYPE CSGetUnorderedAccessViews(
        UINT StartSlot,
        UINT NumUAVs,
        ID3D11UnorderedAccessView** ppUnorderedAccessViews);

    virtual void STDMETHODCALLTYPE CSGetShader(
        ID3D11ComputeShader** ppComputeShader,
        ID3D11ClassInstance** ppClassInstances,
        UINT* pNumClassInstances);

    virtual void STDMETHODCALLTYPE CSGetSamplers(
        UINT StartSlot,
        UINT NumSamplers,
        ID3D11SamplerState** ppSamplers);

    virtual void STDMETHODCALLTYPE CSGetConstantBuffers(
        UINT StartSlot,
        UINT NumBuffers,
        ID3D11Buffer** ppConstantBuffers);

    virtual void STDMETHODCALLTYPE ClearState();

    virtual void STDMETHODCALLTYPE Flush();

    virtual D3D11_DEVICE_CONTEXT_TYPE STDMETHODCALLTYPE GetType();

    virtual UINT STDMETHODCALLTYPE GetContextFlags();

    virtual HRESULT STDMETHODCALLTYPE FinishCommandList(
        BOOL RestoreDeferredContextState,
        ID3D11CommandList** ppCommandList);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11DeviceContext_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11DeviceContextInfo> info_;
};

class ID3D11VideoDecoder_Wrapper : public ID3D11DeviceChild_Wrapper
{
  public:
    ID3D11VideoDecoder_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11VideoDecoder_Wrapper*>(u); });

    ~ID3D11VideoDecoder_Wrapper();

    static ID3D11VideoDecoder_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11VideoDecoderInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11VideoDecoderInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE GetCreationParameters(
        D3D11_VIDEO_DECODER_DESC* pVideoDesc,
        D3D11_VIDEO_DECODER_CONFIG* pConfig);

    virtual HRESULT STDMETHODCALLTYPE GetDriverHandle(
        HANDLE* pDriverHandle);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11VideoDecoder_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11VideoDecoderInfo> info_;
};

class ID3D11VideoProcessorEnumerator_Wrapper : public ID3D11DeviceChild_Wrapper
{
  public:
    ID3D11VideoProcessorEnumerator_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11VideoProcessorEnumerator_Wrapper*>(u); });

    ~ID3D11VideoProcessorEnumerator_Wrapper();

    static ID3D11VideoProcessorEnumerator_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11VideoProcessorEnumeratorInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11VideoProcessorEnumeratorInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE GetVideoProcessorContentDesc(
        D3D11_VIDEO_PROCESSOR_CONTENT_DESC* pContentDesc);

    virtual HRESULT STDMETHODCALLTYPE CheckVideoProcessorFormat(
        DXGI_FORMAT Format,
        UINT* pFlags);

    virtual HRESULT STDMETHODCALLTYPE GetVideoProcessorCaps(
        D3D11_VIDEO_PROCESSOR_CAPS* pCaps);

    virtual HRESULT STDMETHODCALLTYPE GetVideoProcessorRateConversionCaps(
        UINT TypeIndex,
        D3D11_VIDEO_PROCESSOR_RATE_CONVERSION_CAPS* pCaps);

    virtual HRESULT STDMETHODCALLTYPE GetVideoProcessorCustomRate(
        UINT TypeIndex,
        UINT CustomRateIndex,
        D3D11_VIDEO_PROCESSOR_CUSTOM_RATE* pRate);

    virtual HRESULT STDMETHODCALLTYPE GetVideoProcessorFilterRange(
        D3D11_VIDEO_PROCESSOR_FILTER Filter,
        D3D11_VIDEO_PROCESSOR_FILTER_RANGE* pRange);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11VideoProcessorEnumerator_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11VideoProcessorEnumeratorInfo> info_;
};

class ID3D11VideoProcessor_Wrapper : public ID3D11DeviceChild_Wrapper
{
  public:
    ID3D11VideoProcessor_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11VideoProcessor_Wrapper*>(u); });

    ~ID3D11VideoProcessor_Wrapper();

    static ID3D11VideoProcessor_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11VideoProcessorInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11VideoProcessorInfo> GetObjectInfo() { return info_; }

    virtual void STDMETHODCALLTYPE GetContentDesc(
        D3D11_VIDEO_PROCESSOR_CONTENT_DESC* pDesc);

    virtual void STDMETHODCALLTYPE GetRateConversionCaps(
        D3D11_VIDEO_PROCESSOR_RATE_CONVERSION_CAPS* pCaps);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11VideoProcessor_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11VideoProcessorInfo> info_;
};

class ID3D11AuthenticatedChannel_Wrapper : public ID3D11DeviceChild_Wrapper
{
  public:
    ID3D11AuthenticatedChannel_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11AuthenticatedChannel_Wrapper*>(u); });

    ~ID3D11AuthenticatedChannel_Wrapper();

    static ID3D11AuthenticatedChannel_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11AuthenticatedChannelInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11AuthenticatedChannelInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE GetCertificateSize(
        UINT* pCertificateSize);

    virtual HRESULT STDMETHODCALLTYPE GetCertificate(
        UINT CertificateSize,
        BYTE* pCertificate);

    virtual void STDMETHODCALLTYPE GetChannelHandle(
        HANDLE* pChannelHandle);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11AuthenticatedChannel_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11AuthenticatedChannelInfo> info_;
};

class ID3D11CryptoSession_Wrapper : public ID3D11DeviceChild_Wrapper
{
  public:
    ID3D11CryptoSession_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11CryptoSession_Wrapper*>(u); });

    ~ID3D11CryptoSession_Wrapper();

    static ID3D11CryptoSession_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11CryptoSessionInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11CryptoSessionInfo> GetObjectInfo() { return info_; }

    virtual void STDMETHODCALLTYPE GetCryptoType(
        GUID* pCryptoType);

    virtual void STDMETHODCALLTYPE GetDecoderProfile(
        GUID* pDecoderProfile);

    virtual HRESULT STDMETHODCALLTYPE GetCertificateSize(
        UINT* pCertificateSize);

    virtual HRESULT STDMETHODCALLTYPE GetCertificate(
        UINT CertificateSize,
        BYTE* pCertificate);

    virtual void STDMETHODCALLTYPE GetCryptoSessionHandle(
        HANDLE* pCryptoSessionHandle);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11CryptoSession_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11CryptoSessionInfo> info_;
};

class ID3D11VideoDecoderOutputView_Wrapper : public ID3D11View_Wrapper
{
  public:
    ID3D11VideoDecoderOutputView_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11VideoDecoderOutputView_Wrapper*>(u); });

    ~ID3D11VideoDecoderOutputView_Wrapper();

    static ID3D11VideoDecoderOutputView_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11VideoDecoderOutputViewInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11VideoDecoderOutputViewInfo> GetObjectInfo() { return info_; }

    virtual void STDMETHODCALLTYPE GetDesc(
        D3D11_VIDEO_DECODER_OUTPUT_VIEW_DESC* pDesc);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11VideoDecoderOutputView_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11VideoDecoderOutputViewInfo> info_;
};

class ID3D11VideoProcessorInputView_Wrapper : public ID3D11View_Wrapper
{
  public:
    ID3D11VideoProcessorInputView_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11VideoProcessorInputView_Wrapper*>(u); });

    ~ID3D11VideoProcessorInputView_Wrapper();

    static ID3D11VideoProcessorInputView_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11VideoProcessorInputViewInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11VideoProcessorInputViewInfo> GetObjectInfo() { return info_; }

    virtual void STDMETHODCALLTYPE GetDesc(
        D3D11_VIDEO_PROCESSOR_INPUT_VIEW_DESC* pDesc);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11VideoProcessorInputView_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11VideoProcessorInputViewInfo> info_;
};

class ID3D11VideoProcessorOutputView_Wrapper : public ID3D11View_Wrapper
{
  public:
    ID3D11VideoProcessorOutputView_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11VideoProcessorOutputView_Wrapper*>(u); });

    ~ID3D11VideoProcessorOutputView_Wrapper();

    static ID3D11VideoProcessorOutputView_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11VideoProcessorOutputViewInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11VideoProcessorOutputViewInfo> GetObjectInfo() { return info_; }

    virtual void STDMETHODCALLTYPE GetDesc(
        D3D11_VIDEO_PROCESSOR_OUTPUT_VIEW_DESC* pDesc);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11VideoProcessorOutputView_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11VideoProcessorOutputViewInfo> info_;
};

class ID3D11VideoContext_Wrapper : public ID3D11DeviceChild_Wrapper
{
  public:
    ID3D11VideoContext_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11VideoContext_Wrapper*>(u); });

    ~ID3D11VideoContext_Wrapper();

    static ID3D11VideoContext_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11VideoContextInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11VideoContextInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE GetDecoderBuffer(
        ID3D11VideoDecoder* pDecoder,
        D3D11_VIDEO_DECODER_BUFFER_TYPE Type,
        UINT* pBufferSize,
        void** ppBuffer);

    virtual HRESULT STDMETHODCALLTYPE ReleaseDecoderBuffer(
        ID3D11VideoDecoder* pDecoder,
        D3D11_VIDEO_DECODER_BUFFER_TYPE Type);

    virtual HRESULT STDMETHODCALLTYPE DecoderBeginFrame(
        ID3D11VideoDecoder* pDecoder,
        ID3D11VideoDecoderOutputView* pView,
        UINT ContentKeySize,
        const void* pContentKey);

    virtual HRESULT STDMETHODCALLTYPE DecoderEndFrame(
        ID3D11VideoDecoder* pDecoder);

    virtual HRESULT STDMETHODCALLTYPE SubmitDecoderBuffers(
        ID3D11VideoDecoder* pDecoder,
        UINT NumBuffers,
        const D3D11_VIDEO_DECODER_BUFFER_DESC* pBufferDesc);

    virtual APP_DEPRECATED_HRESULT STDMETHODCALLTYPE DecoderExtension(
        ID3D11VideoDecoder* pDecoder,
        const D3D11_VIDEO_DECODER_EXTENSION* pExtensionData);

    virtual void STDMETHODCALLTYPE VideoProcessorSetOutputTargetRect(
        ID3D11VideoProcessor* pVideoProcessor,
        BOOL Enable,
        const RECT* pRect);

    virtual void STDMETHODCALLTYPE VideoProcessorSetOutputBackgroundColor(
        ID3D11VideoProcessor* pVideoProcessor,
        BOOL YCbCr,
        const D3D11_VIDEO_COLOR* pColor);

    virtual void STDMETHODCALLTYPE VideoProcessorSetOutputColorSpace(
        ID3D11VideoProcessor* pVideoProcessor,
        const D3D11_VIDEO_PROCESSOR_COLOR_SPACE* pColorSpace);

    virtual void STDMETHODCALLTYPE VideoProcessorSetOutputAlphaFillMode(
        ID3D11VideoProcessor* pVideoProcessor,
        D3D11_VIDEO_PROCESSOR_ALPHA_FILL_MODE AlphaFillMode,
        UINT StreamIndex);

    virtual void STDMETHODCALLTYPE VideoProcessorSetOutputConstriction(
        ID3D11VideoProcessor* pVideoProcessor,
        BOOL Enable,
        SIZE Size);

    virtual void STDMETHODCALLTYPE VideoProcessorSetOutputStereoMode(
        ID3D11VideoProcessor* pVideoProcessor,
        BOOL Enable);

    virtual APP_DEPRECATED_HRESULT STDMETHODCALLTYPE VideoProcessorSetOutputExtension(
        ID3D11VideoProcessor* pVideoProcessor,
        const GUID* pExtensionGuid,
        UINT DataSize,
        void* pData);

    virtual void STDMETHODCALLTYPE VideoProcessorGetOutputTargetRect(
        ID3D11VideoProcessor* pVideoProcessor,
        BOOL* Enabled,
        RECT* pRect);

    virtual void STDMETHODCALLTYPE VideoProcessorGetOutputBackgroundColor(
        ID3D11VideoProcessor* pVideoProcessor,
        BOOL* pYCbCr,
        D3D11_VIDEO_COLOR* pColor);

    virtual void STDMETHODCALLTYPE VideoProcessorGetOutputColorSpace(
        ID3D11VideoProcessor* pVideoProcessor,
        D3D11_VIDEO_PROCESSOR_COLOR_SPACE* pColorSpace);

    virtual void STDMETHODCALLTYPE VideoProcessorGetOutputAlphaFillMode(
        ID3D11VideoProcessor* pVideoProcessor,
        D3D11_VIDEO_PROCESSOR_ALPHA_FILL_MODE* pAlphaFillMode,
        UINT* pStreamIndex);

    virtual void STDMETHODCALLTYPE VideoProcessorGetOutputConstriction(
        ID3D11VideoProcessor* pVideoProcessor,
        BOOL* pEnabled,
        SIZE* pSize);

    virtual void STDMETHODCALLTYPE VideoProcessorGetOutputStereoMode(
        ID3D11VideoProcessor* pVideoProcessor,
        BOOL* pEnabled);

    virtual APP_DEPRECATED_HRESULT STDMETHODCALLTYPE VideoProcessorGetOutputExtension(
        ID3D11VideoProcessor* pVideoProcessor,
        const GUID* pExtensionGuid,
        UINT DataSize,
        void* pData);

    virtual void STDMETHODCALLTYPE VideoProcessorSetStreamFrameFormat(
        ID3D11VideoProcessor* pVideoProcessor,
        UINT StreamIndex,
        D3D11_VIDEO_FRAME_FORMAT FrameFormat);

    virtual void STDMETHODCALLTYPE VideoProcessorSetStreamColorSpace(
        ID3D11VideoProcessor* pVideoProcessor,
        UINT StreamIndex,
        const D3D11_VIDEO_PROCESSOR_COLOR_SPACE* pColorSpace);

    virtual void STDMETHODCALLTYPE VideoProcessorSetStreamOutputRate(
        ID3D11VideoProcessor* pVideoProcessor,
        UINT StreamIndex,
        D3D11_VIDEO_PROCESSOR_OUTPUT_RATE OutputRate,
        BOOL RepeatFrame,
        const DXGI_RATIONAL* pCustomRate);

    virtual void STDMETHODCALLTYPE VideoProcessorSetStreamSourceRect(
        ID3D11VideoProcessor* pVideoProcessor,
        UINT StreamIndex,
        BOOL Enable,
        const RECT* pRect);

    virtual void STDMETHODCALLTYPE VideoProcessorSetStreamDestRect(
        ID3D11VideoProcessor* pVideoProcessor,
        UINT StreamIndex,
        BOOL Enable,
        const RECT* pRect);

    virtual void STDMETHODCALLTYPE VideoProcessorSetStreamAlpha(
        ID3D11VideoProcessor* pVideoProcessor,
        UINT StreamIndex,
        BOOL Enable,
        FLOAT Alpha);

    virtual void STDMETHODCALLTYPE VideoProcessorSetStreamPalette(
        ID3D11VideoProcessor* pVideoProcessor,
        UINT StreamIndex,
        UINT Count,
        const UINT* pEntries);

    virtual void STDMETHODCALLTYPE VideoProcessorSetStreamPixelAspectRatio(
        ID3D11VideoProcessor* pVideoProcessor,
        UINT StreamIndex,
        BOOL Enable,
        const DXGI_RATIONAL* pSourceAspectRatio,
        const DXGI_RATIONAL* pDestinationAspectRatio);

    virtual void STDMETHODCALLTYPE VideoProcessorSetStreamLumaKey(
        ID3D11VideoProcessor* pVideoProcessor,
        UINT StreamIndex,
        BOOL Enable,
        FLOAT Lower,
        FLOAT Upper);

    virtual void STDMETHODCALLTYPE VideoProcessorSetStreamStereoFormat(
        ID3D11VideoProcessor* pVideoProcessor,
        UINT StreamIndex,
        BOOL Enable,
        D3D11_VIDEO_PROCESSOR_STEREO_FORMAT Format,
        BOOL LeftViewFrame0,
        BOOL BaseViewFrame0,
        D3D11_VIDEO_PROCESSOR_STEREO_FLIP_MODE FlipMode,
        int MonoOffset);

    virtual void STDMETHODCALLTYPE VideoProcessorSetStreamAutoProcessingMode(
        ID3D11VideoProcessor* pVideoProcessor,
        UINT StreamIndex,
        BOOL Enable);

    virtual void STDMETHODCALLTYPE VideoProcessorSetStreamFilter(
        ID3D11VideoProcessor* pVideoProcessor,
        UINT StreamIndex,
        D3D11_VIDEO_PROCESSOR_FILTER Filter,
        BOOL Enable,
        int Level);

    virtual APP_DEPRECATED_HRESULT STDMETHODCALLTYPE VideoProcessorSetStreamExtension(
        ID3D11VideoProcessor* pVideoProcessor,
        UINT StreamIndex,
        const GUID* pExtensionGuid,
        UINT DataSize,
        void* pData);

    virtual void STDMETHODCALLTYPE VideoProcessorGetStreamFrameFormat(
        ID3D11VideoProcessor* pVideoProcessor,
        UINT StreamIndex,
        D3D11_VIDEO_FRAME_FORMAT* pFrameFormat);

    virtual void STDMETHODCALLTYPE VideoProcessorGetStreamColorSpace(
        ID3D11VideoProcessor* pVideoProcessor,
        UINT StreamIndex,
        D3D11_VIDEO_PROCESSOR_COLOR_SPACE* pColorSpace);

    virtual void STDMETHODCALLTYPE VideoProcessorGetStreamOutputRate(
        ID3D11VideoProcessor* pVideoProcessor,
        UINT StreamIndex,
        D3D11_VIDEO_PROCESSOR_OUTPUT_RATE* pOutputRate,
        BOOL* pRepeatFrame,
        DXGI_RATIONAL* pCustomRate);

    virtual void STDMETHODCALLTYPE VideoProcessorGetStreamSourceRect(
        ID3D11VideoProcessor* pVideoProcessor,
        UINT StreamIndex,
        BOOL* pEnabled,
        RECT* pRect);

    virtual void STDMETHODCALLTYPE VideoProcessorGetStreamDestRect(
        ID3D11VideoProcessor* pVideoProcessor,
        UINT StreamIndex,
        BOOL* pEnabled,
        RECT* pRect);

    virtual void STDMETHODCALLTYPE VideoProcessorGetStreamAlpha(
        ID3D11VideoProcessor* pVideoProcessor,
        UINT StreamIndex,
        BOOL* pEnabled,
        FLOAT* pAlpha);

    virtual void STDMETHODCALLTYPE VideoProcessorGetStreamPalette(
        ID3D11VideoProcessor* pVideoProcessor,
        UINT StreamIndex,
        UINT Count,
        UINT* pEntries);

    virtual void STDMETHODCALLTYPE VideoProcessorGetStreamPixelAspectRatio(
        ID3D11VideoProcessor* pVideoProcessor,
        UINT StreamIndex,
        BOOL* pEnabled,
        DXGI_RATIONAL* pSourceAspectRatio,
        DXGI_RATIONAL* pDestinationAspectRatio);

    virtual void STDMETHODCALLTYPE VideoProcessorGetStreamLumaKey(
        ID3D11VideoProcessor* pVideoProcessor,
        UINT StreamIndex,
        BOOL* pEnabled,
        FLOAT* pLower,
        FLOAT* pUpper);

    virtual void STDMETHODCALLTYPE VideoProcessorGetStreamStereoFormat(
        ID3D11VideoProcessor* pVideoProcessor,
        UINT StreamIndex,
        BOOL* pEnable,
        D3D11_VIDEO_PROCESSOR_STEREO_FORMAT* pFormat,
        BOOL* pLeftViewFrame0,
        BOOL* pBaseViewFrame0,
        D3D11_VIDEO_PROCESSOR_STEREO_FLIP_MODE* pFlipMode,
        int* MonoOffset);

    virtual void STDMETHODCALLTYPE VideoProcessorGetStreamAutoProcessingMode(
        ID3D11VideoProcessor* pVideoProcessor,
        UINT StreamIndex,
        BOOL* pEnabled);

    virtual void STDMETHODCALLTYPE VideoProcessorGetStreamFilter(
        ID3D11VideoProcessor* pVideoProcessor,
        UINT StreamIndex,
        D3D11_VIDEO_PROCESSOR_FILTER Filter,
        BOOL* pEnabled,
        int* pLevel);

    virtual APP_DEPRECATED_HRESULT STDMETHODCALLTYPE VideoProcessorGetStreamExtension(
        ID3D11VideoProcessor* pVideoProcessor,
        UINT StreamIndex,
        const GUID* pExtensionGuid,
        UINT DataSize,
        void* pData);

    virtual HRESULT STDMETHODCALLTYPE VideoProcessorBlt(
        ID3D11VideoProcessor* pVideoProcessor,
        ID3D11VideoProcessorOutputView* pView,
        UINT OutputFrame,
        UINT StreamCount,
        const D3D11_VIDEO_PROCESSOR_STREAM* pStreams);

    virtual HRESULT STDMETHODCALLTYPE NegotiateCryptoSessionKeyExchange(
        ID3D11CryptoSession* pCryptoSession,
        UINT DataSize,
        void* pData);

    virtual void STDMETHODCALLTYPE EncryptionBlt(
        ID3D11CryptoSession* pCryptoSession,
        ID3D11Texture2D* pSrcSurface,
        ID3D11Texture2D* pDstSurface,
        UINT IVSize,
        void* pIV);

    virtual void STDMETHODCALLTYPE DecryptionBlt(
        ID3D11CryptoSession* pCryptoSession,
        ID3D11Texture2D* pSrcSurface,
        ID3D11Texture2D* pDstSurface,
        D3D11_ENCRYPTED_BLOCK_INFO* pEncryptedBlockInfo,
        UINT ContentKeySize,
        const void* pContentKey,
        UINT IVSize,
        void* pIV);

    virtual void STDMETHODCALLTYPE StartSessionKeyRefresh(
        ID3D11CryptoSession* pCryptoSession,
        UINT RandomNumberSize,
        void* pRandomNumber);

    virtual void STDMETHODCALLTYPE FinishSessionKeyRefresh(
        ID3D11CryptoSession* pCryptoSession);

    virtual HRESULT STDMETHODCALLTYPE GetEncryptionBltKey(
        ID3D11CryptoSession* pCryptoSession,
        UINT KeySize,
        void* pReadbackKey);

    virtual HRESULT STDMETHODCALLTYPE NegotiateAuthenticatedChannelKeyExchange(
        ID3D11AuthenticatedChannel* pChannel,
        UINT DataSize,
        void* pData);

    virtual HRESULT STDMETHODCALLTYPE QueryAuthenticatedChannel(
        ID3D11AuthenticatedChannel* pChannel,
        UINT InputSize,
        const void* pInput,
        UINT OutputSize,
        void* pOutput);

    virtual HRESULT STDMETHODCALLTYPE ConfigureAuthenticatedChannel(
        ID3D11AuthenticatedChannel* pChannel,
        UINT InputSize,
        const void* pInput,
        D3D11_AUTHENTICATED_CONFIGURE_OUTPUT* pOutput);

    virtual void STDMETHODCALLTYPE VideoProcessorSetStreamRotation(
        ID3D11VideoProcessor* pVideoProcessor,
        UINT StreamIndex,
        BOOL Enable,
        D3D11_VIDEO_PROCESSOR_ROTATION Rotation);

    virtual void STDMETHODCALLTYPE VideoProcessorGetStreamRotation(
        ID3D11VideoProcessor* pVideoProcessor,
        UINT StreamIndex,
        BOOL* pEnable,
        D3D11_VIDEO_PROCESSOR_ROTATION* pRotation);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11VideoContext_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11VideoContextInfo> info_;
};

class ID3D11VideoDevice_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D11VideoDevice_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11VideoDevice_Wrapper*>(u); });

    ~ID3D11VideoDevice_Wrapper();

    static ID3D11VideoDevice_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11VideoDeviceInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11VideoDeviceInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE CreateVideoDecoder(
        const D3D11_VIDEO_DECODER_DESC* pVideoDesc,
        const D3D11_VIDEO_DECODER_CONFIG* pConfig,
        ID3D11VideoDecoder** ppDecoder);

    virtual HRESULT STDMETHODCALLTYPE CreateVideoProcessor(
        ID3D11VideoProcessorEnumerator* pEnum,
        UINT RateConversionIndex,
        ID3D11VideoProcessor** ppVideoProcessor);

    virtual HRESULT STDMETHODCALLTYPE CreateAuthenticatedChannel(
        D3D11_AUTHENTICATED_CHANNEL_TYPE ChannelType,
        ID3D11AuthenticatedChannel** ppAuthenticatedChannel);

    virtual HRESULT STDMETHODCALLTYPE CreateCryptoSession(
        const GUID* pCryptoType,
        const GUID* pDecoderProfile,
        const GUID* pKeyExchangeType,
        ID3D11CryptoSession** ppCryptoSession);

    virtual HRESULT STDMETHODCALLTYPE CreateVideoDecoderOutputView(
        ID3D11Resource* pResource,
        const D3D11_VIDEO_DECODER_OUTPUT_VIEW_DESC* pDesc,
        ID3D11VideoDecoderOutputView** ppVDOVView);

    virtual HRESULT STDMETHODCALLTYPE CreateVideoProcessorInputView(
        ID3D11Resource* pResource,
        ID3D11VideoProcessorEnumerator* pEnum,
        const D3D11_VIDEO_PROCESSOR_INPUT_VIEW_DESC* pDesc,
        ID3D11VideoProcessorInputView** ppVPIView);

    virtual HRESULT STDMETHODCALLTYPE CreateVideoProcessorOutputView(
        ID3D11Resource* pResource,
        ID3D11VideoProcessorEnumerator* pEnum,
        const D3D11_VIDEO_PROCESSOR_OUTPUT_VIEW_DESC* pDesc,
        ID3D11VideoProcessorOutputView** ppVPOView);

    virtual HRESULT STDMETHODCALLTYPE CreateVideoProcessorEnumerator(
        const D3D11_VIDEO_PROCESSOR_CONTENT_DESC* pDesc,
        ID3D11VideoProcessorEnumerator** ppEnum);

    virtual UINT STDMETHODCALLTYPE GetVideoDecoderProfileCount();

    virtual HRESULT STDMETHODCALLTYPE GetVideoDecoderProfile(
        UINT Index,
        GUID* pDecoderProfile);

    virtual HRESULT STDMETHODCALLTYPE CheckVideoDecoderFormat(
        const GUID* pDecoderProfile,
        DXGI_FORMAT Format,
        BOOL* pSupported);

    virtual HRESULT STDMETHODCALLTYPE GetVideoDecoderConfigCount(
        const D3D11_VIDEO_DECODER_DESC* pDesc,
        UINT* pCount);

    virtual HRESULT STDMETHODCALLTYPE GetVideoDecoderConfig(
        const D3D11_VIDEO_DECODER_DESC* pDesc,
        UINT Index,
        D3D11_VIDEO_DECODER_CONFIG* pConfig);

    virtual HRESULT STDMETHODCALLTYPE GetContentProtectionCaps(
        const GUID* pCryptoType,
        const GUID* pDecoderProfile,
        D3D11_VIDEO_CONTENT_PROTECTION_CAPS* pCaps);

    virtual HRESULT STDMETHODCALLTYPE CheckCryptoKeyExchange(
        const GUID* pCryptoType,
        const GUID* pDecoderProfile,
        UINT Index,
        GUID* pKeyExchangeType);

    virtual HRESULT STDMETHODCALLTYPE SetPrivateData(
        REFGUID guid,
        UINT DataSize,
        const void* pData);

    virtual HRESULT STDMETHODCALLTYPE SetPrivateDataInterface(
        REFGUID guid,
        const IUnknown* pData);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11VideoDevice_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11VideoDeviceInfo> info_;
};

class ID3D11Device_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D11Device_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11Device_Wrapper*>(u); });

    ~ID3D11Device_Wrapper();

    static ID3D11Device_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3D11DeviceInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3D11DeviceInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE CreateBuffer(
        const D3D11_BUFFER_DESC* pDesc,
        const D3D11_SUBRESOURCE_DATA* pInitialData,
        ID3D11Buffer** ppBuffer);

    virtual HRESULT STDMETHODCALLTYPE CreateTexture1D(
        const D3D11_TEXTURE1D_DESC* pDesc,
        const D3D11_SUBRESOURCE_DATA* pInitialData,
        ID3D11Texture1D** ppTexture1D);

    virtual HRESULT STDMETHODCALLTYPE CreateTexture2D(
        const D3D11_TEXTURE2D_DESC* pDesc,
        const D3D11_SUBRESOURCE_DATA* pInitialData,
        ID3D11Texture2D** ppTexture2D);

    virtual HRESULT STDMETHODCALLTYPE CreateTexture3D(
        const D3D11_TEXTURE3D_DESC* pDesc,
        const D3D11_SUBRESOURCE_DATA* pInitialData,
        ID3D11Texture3D** ppTexture3D);

    virtual HRESULT STDMETHODCALLTYPE CreateShaderResourceView(
        ID3D11Resource* pResource,
        const D3D11_SHADER_RESOURCE_VIEW_DESC* pDesc,
        ID3D11ShaderResourceView** ppSRView);

    virtual HRESULT STDMETHODCALLTYPE CreateUnorderedAccessView(
        ID3D11Resource* pResource,
        const D3D11_UNORDERED_ACCESS_VIEW_DESC* pDesc,
        ID3D11UnorderedAccessView** ppUAView);

    virtual HRESULT STDMETHODCALLTYPE CreateRenderTargetView(
        ID3D11Resource* pResource,
        const D3D11_RENDER_TARGET_VIEW_DESC* pDesc,
        ID3D11RenderTargetView** ppRTView);

    virtual HRESULT STDMETHODCALLTYPE CreateDepthStencilView(
        ID3D11Resource* pResource,
        const D3D11_DEPTH_STENCIL_VIEW_DESC* pDesc,
        ID3D11DepthStencilView** ppDepthStencilView);

    virtual HRESULT STDMETHODCALLTYPE CreateInputLayout(
        const D3D11_INPUT_ELEMENT_DESC* pInputElementDescs,
        UINT NumElements,
        const void* pShaderBytecodeWithInputSignature,
        SIZE_T BytecodeLength,
        ID3D11InputLayout** ppInputLayout);

    virtual HRESULT STDMETHODCALLTYPE CreateVertexShader(
        const void* pShaderBytecode,
        SIZE_T BytecodeLength,
        ID3D11ClassLinkage* pClassLinkage,
        ID3D11VertexShader** ppVertexShader);

    virtual HRESULT STDMETHODCALLTYPE CreateGeometryShader(
        const void* pShaderBytecode,
        SIZE_T BytecodeLength,
        ID3D11ClassLinkage* pClassLinkage,
        ID3D11GeometryShader** ppGeometryShader);

    virtual HRESULT STDMETHODCALLTYPE CreateGeometryShaderWithStreamOutput(
        const void* pShaderBytecode,
        SIZE_T BytecodeLength,
        const D3D11_SO_DECLARATION_ENTRY* pSODeclaration,
        UINT NumEntries,
        const UINT* pBufferStrides,
        UINT NumStrides,
        UINT RasterizedStream,
        ID3D11ClassLinkage* pClassLinkage,
        ID3D11GeometryShader** ppGeometryShader);

    virtual HRESULT STDMETHODCALLTYPE CreatePixelShader(
        const void* pShaderBytecode,
        SIZE_T BytecodeLength,
        ID3D11ClassLinkage* pClassLinkage,
        ID3D11PixelShader** ppPixelShader);

    virtual HRESULT STDMETHODCALLTYPE CreateHullShader(
        const void* pShaderBytecode,
        SIZE_T BytecodeLength,
        ID3D11ClassLinkage* pClassLinkage,
        ID3D11HullShader** ppHullShader);

    virtual HRESULT STDMETHODCALLTYPE CreateDomainShader(
        const void* pShaderBytecode,
        SIZE_T BytecodeLength,
        ID3D11ClassLinkage* pClassLinkage,
        ID3D11DomainShader** ppDomainShader);

    virtual HRESULT STDMETHODCALLTYPE CreateComputeShader(
        const void* pShaderBytecode,
        SIZE_T BytecodeLength,
        ID3D11ClassLinkage* pClassLinkage,
        ID3D11ComputeShader** ppComputeShader);

    virtual HRESULT STDMETHODCALLTYPE CreateClassLinkage(
        ID3D11ClassLinkage** ppLinkage);

    virtual HRESULT STDMETHODCALLTYPE CreateBlendState(
        const D3D11_BLEND_DESC* pBlendStateDesc,
        ID3D11BlendState** ppBlendState);

    virtual HRESULT STDMETHODCALLTYPE CreateDepthStencilState(
        const D3D11_DEPTH_STENCIL_DESC* pDepthStencilDesc,
        ID3D11DepthStencilState** ppDepthStencilState);

    virtual HRESULT STDMETHODCALLTYPE CreateRasterizerState(
        const D3D11_RASTERIZER_DESC* pRasterizerDesc,
        ID3D11RasterizerState** ppRasterizerState);

    virtual HRESULT STDMETHODCALLTYPE CreateSamplerState(
        const D3D11_SAMPLER_DESC* pSamplerDesc,
        ID3D11SamplerState** ppSamplerState);

    virtual HRESULT STDMETHODCALLTYPE CreateQuery(
        const D3D11_QUERY_DESC* pQueryDesc,
        ID3D11Query** ppQuery);

    virtual HRESULT STDMETHODCALLTYPE CreatePredicate(
        const D3D11_QUERY_DESC* pPredicateDesc,
        ID3D11Predicate** ppPredicate);

    virtual HRESULT STDMETHODCALLTYPE CreateCounter(
        const D3D11_COUNTER_DESC* pCounterDesc,
        ID3D11Counter** ppCounter);

    virtual HRESULT STDMETHODCALLTYPE CreateDeferredContext(
        UINT ContextFlags,
        ID3D11DeviceContext** ppDeferredContext);

    virtual HRESULT STDMETHODCALLTYPE OpenSharedResource(
        HANDLE hResource,
        REFIID ReturnedInterface,
        void** ppResource);

    virtual HRESULT STDMETHODCALLTYPE CheckFormatSupport(
        DXGI_FORMAT Format,
        UINT* pFormatSupport);

    virtual HRESULT STDMETHODCALLTYPE CheckMultisampleQualityLevels(
        DXGI_FORMAT Format,
        UINT SampleCount,
        UINT* pNumQualityLevels);

    virtual void STDMETHODCALLTYPE CheckCounterInfo(
        D3D11_COUNTER_INFO* pCounterInfo);

    virtual HRESULT STDMETHODCALLTYPE CheckCounter(
        const D3D11_COUNTER_DESC* pDesc,
        D3D11_COUNTER_TYPE* pType,
        UINT* pActiveCounters,
        LPSTR szName,
        UINT* pNameLength,
        LPSTR szUnits,
        UINT* pUnitsLength,
        LPSTR szDescription,
        UINT* pDescriptionLength);

    virtual HRESULT STDMETHODCALLTYPE CheckFeatureSupport(
        D3D11_FEATURE Feature,
        void* pFeatureSupportData,
        UINT FeatureSupportDataSize);

    virtual HRESULT STDMETHODCALLTYPE GetPrivateData(
        REFGUID guid,
        UINT* pDataSize,
        void* pData);

    virtual HRESULT STDMETHODCALLTYPE SetPrivateData(
        REFGUID guid,
        UINT DataSize,
        const void* pData);

    virtual HRESULT STDMETHODCALLTYPE SetPrivateDataInterface(
        REFGUID guid,
        const IUnknown* pData);

    virtual D3D_FEATURE_LEVEL STDMETHODCALLTYPE GetFeatureLevel();

    virtual UINT STDMETHODCALLTYPE GetCreationFlags();

    virtual HRESULT STDMETHODCALLTYPE GetDeviceRemovedReason();

    virtual void STDMETHODCALLTYPE GetImmediateContext(
        ID3D11DeviceContext** ppImmediateContext);

    virtual HRESULT STDMETHODCALLTYPE SetExceptionMode(
        UINT RaiseFlags);

    virtual UINT STDMETHODCALLTYPE GetExceptionMode();

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3D11Device_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3D11DeviceInfo> info_;
};


/*
** This part is generated from d3d11_1.h in Windows SDK: 10.0.20348.0
**
*/

class ID3D11BlendState1_Wrapper : public ID3D11BlendState_Wrapper
{
  public:
    ID3D11BlendState1_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11BlendState1_Wrapper*>(u); });

    virtual void STDMETHODCALLTYPE GetDesc1(
        D3D11_BLEND_DESC1* pDesc);

};

class ID3D11RasterizerState1_Wrapper : public ID3D11RasterizerState_Wrapper
{
  public:
    ID3D11RasterizerState1_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11RasterizerState1_Wrapper*>(u); });

    virtual void STDMETHODCALLTYPE GetDesc1(
        D3D11_RASTERIZER_DESC1* pDesc);

};

class ID3DDeviceContextState_Wrapper : public ID3D11DeviceChild_Wrapper
{
  public:
    ID3DDeviceContextState_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3DDeviceContextState_Wrapper*>(u); });

    ~ID3DDeviceContextState_Wrapper();

    static ID3DDeviceContextState_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3DDeviceContextStateInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3DDeviceContextStateInfo> GetObjectInfo() { return info_; }

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3DDeviceContextState_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3DDeviceContextStateInfo> info_;
};

class ID3D11DeviceContext1_Wrapper : public ID3D11DeviceContext_Wrapper
{
  public:
    ID3D11DeviceContext1_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11DeviceContext1_Wrapper*>(u); });

    virtual void STDMETHODCALLTYPE CopySubresourceRegion1(
        ID3D11Resource* pDstResource,
        UINT DstSubresource,
        UINT DstX,
        UINT DstY,
        UINT DstZ,
        ID3D11Resource* pSrcResource,
        UINT SrcSubresource,
        const D3D11_BOX* pSrcBox,
        UINT CopyFlags);

    virtual void STDMETHODCALLTYPE UpdateSubresource1(
        ID3D11Resource* pDstResource,
        UINT DstSubresource,
        const D3D11_BOX* pDstBox,
        const void* pSrcData,
        UINT SrcRowPitch,
        UINT SrcDepthPitch,
        UINT CopyFlags);

    virtual void STDMETHODCALLTYPE DiscardResource(
        ID3D11Resource* pResource);

    virtual void STDMETHODCALLTYPE DiscardView(
        ID3D11View* pResourceView);

    virtual void STDMETHODCALLTYPE VSSetConstantBuffers1(
        UINT StartSlot,
        UINT NumBuffers,
        ID3D11Buffer* const* ppConstantBuffers,
        const UINT* pFirstConstant,
        const UINT* pNumConstants);

    virtual void STDMETHODCALLTYPE HSSetConstantBuffers1(
        UINT StartSlot,
        UINT NumBuffers,
        ID3D11Buffer* const* ppConstantBuffers,
        const UINT* pFirstConstant,
        const UINT* pNumConstants);

    virtual void STDMETHODCALLTYPE DSSetConstantBuffers1(
        UINT StartSlot,
        UINT NumBuffers,
        ID3D11Buffer* const* ppConstantBuffers,
        const UINT* pFirstConstant,
        const UINT* pNumConstants);

    virtual void STDMETHODCALLTYPE GSSetConstantBuffers1(
        UINT StartSlot,
        UINT NumBuffers,
        ID3D11Buffer* const* ppConstantBuffers,
        const UINT* pFirstConstant,
        const UINT* pNumConstants);

    virtual void STDMETHODCALLTYPE PSSetConstantBuffers1(
        UINT StartSlot,
        UINT NumBuffers,
        ID3D11Buffer* const* ppConstantBuffers,
        const UINT* pFirstConstant,
        const UINT* pNumConstants);

    virtual void STDMETHODCALLTYPE CSSetConstantBuffers1(
        UINT StartSlot,
        UINT NumBuffers,
        ID3D11Buffer* const* ppConstantBuffers,
        const UINT* pFirstConstant,
        const UINT* pNumConstants);

    virtual void STDMETHODCALLTYPE VSGetConstantBuffers1(
        UINT StartSlot,
        UINT NumBuffers,
        ID3D11Buffer** ppConstantBuffers,
        UINT* pFirstConstant,
        UINT* pNumConstants);

    virtual void STDMETHODCALLTYPE HSGetConstantBuffers1(
        UINT StartSlot,
        UINT NumBuffers,
        ID3D11Buffer** ppConstantBuffers,
        UINT* pFirstConstant,
        UINT* pNumConstants);

    virtual void STDMETHODCALLTYPE DSGetConstantBuffers1(
        UINT StartSlot,
        UINT NumBuffers,
        ID3D11Buffer** ppConstantBuffers,
        UINT* pFirstConstant,
        UINT* pNumConstants);

    virtual void STDMETHODCALLTYPE GSGetConstantBuffers1(
        UINT StartSlot,
        UINT NumBuffers,
        ID3D11Buffer** ppConstantBuffers,
        UINT* pFirstConstant,
        UINT* pNumConstants);

    virtual void STDMETHODCALLTYPE PSGetConstantBuffers1(
        UINT StartSlot,
        UINT NumBuffers,
        ID3D11Buffer** ppConstantBuffers,
        UINT* pFirstConstant,
        UINT* pNumConstants);

    virtual void STDMETHODCALLTYPE CSGetConstantBuffers1(
        UINT StartSlot,
        UINT NumBuffers,
        ID3D11Buffer** ppConstantBuffers,
        UINT* pFirstConstant,
        UINT* pNumConstants);

    virtual void STDMETHODCALLTYPE SwapDeviceContextState(
        ID3DDeviceContextState* pState,
        ID3DDeviceContextState** ppPreviousState);

    virtual void STDMETHODCALLTYPE ClearView(
        ID3D11View* pView,
        const FLOAT Color [4],
        const D3D11_RECT* pRect,
        UINT NumRects);

    virtual void STDMETHODCALLTYPE DiscardView1(
        ID3D11View* pResourceView,
        const D3D11_RECT* pRects,
        UINT NumRects);

};

class ID3D11VideoContext1_Wrapper : public ID3D11VideoContext_Wrapper
{
  public:
    ID3D11VideoContext1_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11VideoContext1_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE SubmitDecoderBuffers1(
        ID3D11VideoDecoder* pDecoder,
        UINT NumBuffers,
        const D3D11_VIDEO_DECODER_BUFFER_DESC1* pBufferDesc);

    virtual HRESULT STDMETHODCALLTYPE GetDataForNewHardwareKey(
        ID3D11CryptoSession* pCryptoSession,
        UINT PrivateInputSize,
        const void* pPrivatInputData,
        UINT64* pPrivateOutputData);

    virtual HRESULT STDMETHODCALLTYPE CheckCryptoSessionStatus(
        ID3D11CryptoSession* pCryptoSession,
        D3D11_CRYPTO_SESSION_STATUS* pStatus);

    virtual HRESULT STDMETHODCALLTYPE DecoderEnableDownsampling(
        ID3D11VideoDecoder* pDecoder,
        DXGI_COLOR_SPACE_TYPE InputColorSpace,
        const D3D11_VIDEO_SAMPLE_DESC* pOutputDesc,
        UINT ReferenceFrameCount);

    virtual HRESULT STDMETHODCALLTYPE DecoderUpdateDownsampling(
        ID3D11VideoDecoder* pDecoder,
        const D3D11_VIDEO_SAMPLE_DESC* pOutputDesc);

    virtual void STDMETHODCALLTYPE VideoProcessorSetOutputColorSpace1(
        ID3D11VideoProcessor* pVideoProcessor,
        DXGI_COLOR_SPACE_TYPE ColorSpace);

    virtual void STDMETHODCALLTYPE VideoProcessorSetOutputShaderUsage(
        ID3D11VideoProcessor* pVideoProcessor,
        BOOL ShaderUsage);

    virtual void STDMETHODCALLTYPE VideoProcessorGetOutputColorSpace1(
        ID3D11VideoProcessor* pVideoProcessor,
        DXGI_COLOR_SPACE_TYPE* pColorSpace);

    virtual void STDMETHODCALLTYPE VideoProcessorGetOutputShaderUsage(
        ID3D11VideoProcessor* pVideoProcessor,
        BOOL* pShaderUsage);

    virtual void STDMETHODCALLTYPE VideoProcessorSetStreamColorSpace1(
        ID3D11VideoProcessor* pVideoProcessor,
        UINT StreamIndex,
        DXGI_COLOR_SPACE_TYPE ColorSpace);

    virtual void STDMETHODCALLTYPE VideoProcessorSetStreamMirror(
        ID3D11VideoProcessor* pVideoProcessor,
        UINT StreamIndex,
        BOOL Enable,
        BOOL FlipHorizontal,
        BOOL FlipVertical);

    virtual void STDMETHODCALLTYPE VideoProcessorGetStreamColorSpace1(
        ID3D11VideoProcessor* pVideoProcessor,
        UINT StreamIndex,
        DXGI_COLOR_SPACE_TYPE* pColorSpace);

    virtual void STDMETHODCALLTYPE VideoProcessorGetStreamMirror(
        ID3D11VideoProcessor* pVideoProcessor,
        UINT StreamIndex,
        BOOL* pEnable,
        BOOL* pFlipHorizontal,
        BOOL* pFlipVertical);

    virtual HRESULT STDMETHODCALLTYPE VideoProcessorGetBehaviorHints(
        ID3D11VideoProcessor* pVideoProcessor,
        UINT OutputWidth,
        UINT OutputHeight,
        DXGI_FORMAT OutputFormat,
        UINT StreamCount,
        const D3D11_VIDEO_PROCESSOR_STREAM_BEHAVIOR_HINT* pStreams,
        UINT* pBehaviorHints);

};

class ID3D11VideoDevice1_Wrapper : public ID3D11VideoDevice_Wrapper
{
  public:
    ID3D11VideoDevice1_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11VideoDevice1_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE GetCryptoSessionPrivateDataSize(
        const GUID* pCryptoType,
        const GUID* pDecoderProfile,
        const GUID* pKeyExchangeType,
        UINT* pPrivateInputSize,
        UINT* pPrivateOutputSize);

    virtual HRESULT STDMETHODCALLTYPE GetVideoDecoderCaps(
        const GUID* pDecoderProfile,
        UINT SampleWidth,
        UINT SampleHeight,
        const DXGI_RATIONAL* pFrameRate,
        UINT BitRate,
        const GUID* pCryptoType,
        UINT* pDecoderCaps);

    virtual HRESULT STDMETHODCALLTYPE CheckVideoDecoderDownsampling(
        const D3D11_VIDEO_DECODER_DESC* pInputDesc,
        DXGI_COLOR_SPACE_TYPE InputColorSpace,
        const D3D11_VIDEO_DECODER_CONFIG* pInputConfig,
        const DXGI_RATIONAL* pFrameRate,
        const D3D11_VIDEO_SAMPLE_DESC* pOutputDesc,
        BOOL* pSupported,
        BOOL* pRealTimeHint);

    virtual HRESULT STDMETHODCALLTYPE RecommendVideoDecoderDownsampleParameters(
        const D3D11_VIDEO_DECODER_DESC* pInputDesc,
        DXGI_COLOR_SPACE_TYPE InputColorSpace,
        const D3D11_VIDEO_DECODER_CONFIG* pInputConfig,
        const DXGI_RATIONAL* pFrameRate,
        D3D11_VIDEO_SAMPLE_DESC* pRecommendedOutputDesc);

};

class ID3D11VideoProcessorEnumerator1_Wrapper : public ID3D11VideoProcessorEnumerator_Wrapper
{
  public:
    ID3D11VideoProcessorEnumerator1_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11VideoProcessorEnumerator1_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE CheckVideoProcessorFormatConversion(
        DXGI_FORMAT InputFormat,
        DXGI_COLOR_SPACE_TYPE InputColorSpace,
        DXGI_FORMAT OutputFormat,
        DXGI_COLOR_SPACE_TYPE OutputColorSpace,
        BOOL* pSupported);

};

class ID3D11Device1_Wrapper : public ID3D11Device_Wrapper
{
  public:
    ID3D11Device1_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11Device1_Wrapper*>(u); });

    virtual void STDMETHODCALLTYPE GetImmediateContext1(
        ID3D11DeviceContext1** ppImmediateContext);

    virtual HRESULT STDMETHODCALLTYPE CreateDeferredContext1(
        UINT ContextFlags,
        ID3D11DeviceContext1** ppDeferredContext);

    virtual HRESULT STDMETHODCALLTYPE CreateBlendState1(
        const D3D11_BLEND_DESC1* pBlendStateDesc,
        ID3D11BlendState1** ppBlendState);

    virtual HRESULT STDMETHODCALLTYPE CreateRasterizerState1(
        const D3D11_RASTERIZER_DESC1* pRasterizerDesc,
        ID3D11RasterizerState1** ppRasterizerState);

    virtual HRESULT STDMETHODCALLTYPE CreateDeviceContextState(
        UINT Flags,
        const D3D_FEATURE_LEVEL* pFeatureLevels,
        UINT FeatureLevels,
        UINT SDKVersion,
        REFIID EmulatedInterface,
        D3D_FEATURE_LEVEL* pChosenFeatureLevel,
        ID3DDeviceContextState** ppContextState);

    virtual HRESULT STDMETHODCALLTYPE OpenSharedResource1(
        HANDLE hResource,
        REFIID returnedInterface,
        void** ppResource);

    virtual HRESULT STDMETHODCALLTYPE OpenSharedResourceByName(
        LPCWSTR lpName,
        DWORD dwDesiredAccess,
        REFIID returnedInterface,
        void** ppResource);

};

class ID3DUserDefinedAnnotation_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3DUserDefinedAnnotation_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3DUserDefinedAnnotation_Wrapper*>(u); });

    ~ID3DUserDefinedAnnotation_Wrapper();

    static ID3DUserDefinedAnnotation_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const ID3DUserDefinedAnnotationInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<ID3DUserDefinedAnnotationInfo> GetObjectInfo() { return info_; }

    virtual INT STDMETHODCALLTYPE BeginEvent(
        LPCWSTR Name);

    virtual INT STDMETHODCALLTYPE EndEvent();

    virtual void STDMETHODCALLTYPE SetMarker(
        LPCWSTR Name);

    virtual BOOL STDMETHODCALLTYPE GetStatus();

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, ID3DUserDefinedAnnotation_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<ID3DUserDefinedAnnotationInfo> info_;
};


/*
** This part is generated from d3d11_2.h in Windows SDK: 10.0.20348.0
**
*/

class ID3D11DeviceContext2_Wrapper : public ID3D11DeviceContext1_Wrapper
{
  public:
    ID3D11DeviceContext2_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11DeviceContext2_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE UpdateTileMappings(
        ID3D11Resource* pTiledResource,
        UINT NumTiledResourceRegions,
        const D3D11_TILED_RESOURCE_COORDINATE* pTiledResourceRegionStartCoordinates,
        const D3D11_TILE_REGION_SIZE* pTiledResourceRegionSizes,
        ID3D11Buffer* pTilePool,
        UINT NumRanges,
        const UINT* pRangeFlags,
        const UINT* pTilePoolStartOffsets,
        const UINT* pRangeTileCounts,
        UINT Flags);

    virtual HRESULT STDMETHODCALLTYPE CopyTileMappings(
        ID3D11Resource* pDestTiledResource,
        const D3D11_TILED_RESOURCE_COORDINATE* pDestRegionStartCoordinate,
        ID3D11Resource* pSourceTiledResource,
        const D3D11_TILED_RESOURCE_COORDINATE* pSourceRegionStartCoordinate,
        const D3D11_TILE_REGION_SIZE* pTileRegionSize,
        UINT Flags);

    virtual void STDMETHODCALLTYPE CopyTiles(
        ID3D11Resource* pTiledResource,
        const D3D11_TILED_RESOURCE_COORDINATE* pTileRegionStartCoordinate,
        const D3D11_TILE_REGION_SIZE* pTileRegionSize,
        ID3D11Buffer* pBuffer,
        UINT64 BufferStartOffsetInBytes,
        UINT Flags);

    virtual void STDMETHODCALLTYPE UpdateTiles(
        ID3D11Resource* pDestTiledResource,
        const D3D11_TILED_RESOURCE_COORDINATE* pDestTileRegionStartCoordinate,
        const D3D11_TILE_REGION_SIZE* pDestTileRegionSize,
        const void* pSourceTileData,
        UINT Flags);

    virtual HRESULT STDMETHODCALLTYPE ResizeTilePool(
        ID3D11Buffer* pTilePool,
        UINT64 NewSizeInBytes);

    virtual void STDMETHODCALLTYPE TiledResourceBarrier(
        ID3D11DeviceChild* pTiledResourceOrViewAccessBeforeBarrier,
        ID3D11DeviceChild* pTiledResourceOrViewAccessAfterBarrier);

    virtual BOOL STDMETHODCALLTYPE IsAnnotationEnabled();

    virtual void STDMETHODCALLTYPE SetMarkerInt(
        LPCWSTR pLabel,
        INT Data);

    virtual void STDMETHODCALLTYPE BeginEventInt(
        LPCWSTR pLabel,
        INT Data);

    virtual void STDMETHODCALLTYPE EndEvent();

};

class ID3D11Device2_Wrapper : public ID3D11Device1_Wrapper
{
  public:
    ID3D11Device2_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D11Device2_Wrapper*>(u); });

    virtual void STDMETHODCALLTYPE GetImmediateContext2(
        ID3D11DeviceContext2** ppImmediateContext);

    virtual HRESULT STDMETHODCALLTYPE CreateDeferredContext2(
        UINT ContextFlags,
        ID3D11DeviceContext2** ppDeferredContext);

    virtual void STDMETHODCALLTYPE GetResourceTiling(
        ID3D11Resource* pTiledResource,
        UINT* pNumTilesForEntireResource,
        D3D11_PACKED_MIP_DESC* pPackedMipDesc,
        D3D11_TILE_SHAPE* pStandardTileShapeForNonPackedMips,
        UINT* pNumSubresourceTilings,
        UINT FirstSubresourceTilingToGet,
        D3D11_SUBRESOURCE_TILING* pSubresourceTilingsForNonPackedMips);

    virtual HRESULT STDMETHODCALLTYPE CheckMultisampleQualityLevels1(
        DXGI_FORMAT Format,
        UINT SampleCount,
        UINT Flags,
        UINT* pNumQualityLevels);

};


/*
** This part is generated from dxgi.h in Windows SDK: 10.0.20348.0
**
*/

HRESULT WINAPI CreateDXGIFactory(
    REFIID riid,
    void** ppFactory);

HRESULT WINAPI CreateDXGIFactory1(
    REFIID riid,
    void** ppFactory);

class IDXGIObject_Wrapper : public IUnknown_Wrapper
{
  public:
    IDXGIObject_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIObject_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE SetPrivateData(
        REFGUID Name,
        UINT DataSize,
        const void* pData);

    virtual HRESULT STDMETHODCALLTYPE SetPrivateDataInterface(
        REFGUID Name,
        const IUnknown* pUnknown);

    virtual HRESULT STDMETHODCALLTYPE GetPrivateData(
        REFGUID Name,
        UINT* pDataSize,
        void* pData);

    virtual HRESULT STDMETHODCALLTYPE GetParent(
        REFIID riid,
        void** ppParent);

};

class IDXGIDeviceSubObject_Wrapper : public IDXGIObject_Wrapper
{
  public:
    IDXGIDeviceSubObject_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIDeviceSubObject_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE GetDevice(
        REFIID riid,
        void** ppDevice);

};

class IDXGIResource_Wrapper : public IDXGIDeviceSubObject_Wrapper
{
  public:
    IDXGIResource_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIResource_Wrapper*>(u); });

    ~IDXGIResource_Wrapper();

    static IDXGIResource_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const IDXGIResourceInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<IDXGIResourceInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE GetSharedHandle(
        HANDLE* pSharedHandle);

    virtual HRESULT STDMETHODCALLTYPE GetUsage(
        DXGI_USAGE* pUsage);

    virtual HRESULT STDMETHODCALLTYPE SetEvictionPriority(
        UINT EvictionPriority);

    virtual HRESULT STDMETHODCALLTYPE GetEvictionPriority(
        UINT* pEvictionPriority);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, IDXGIResource_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<IDXGIResourceInfo> info_;
};

class IDXGIKeyedMutex_Wrapper : public IDXGIDeviceSubObject_Wrapper
{
  public:
    IDXGIKeyedMutex_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIKeyedMutex_Wrapper*>(u); });

    ~IDXGIKeyedMutex_Wrapper();

    static IDXGIKeyedMutex_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const IDXGIKeyedMutexInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<IDXGIKeyedMutexInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE AcquireSync(
        UINT64 Key,
        DWORD dwMilliseconds);

    virtual HRESULT STDMETHODCALLTYPE ReleaseSync(
        UINT64 Key);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, IDXGIKeyedMutex_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<IDXGIKeyedMutexInfo> info_;
};

class IDXGISurface_Wrapper : public IDXGIDeviceSubObject_Wrapper
{
  public:
    IDXGISurface_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGISurface_Wrapper*>(u); });

    ~IDXGISurface_Wrapper();

    static IDXGISurface_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const IDXGISurfaceInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<IDXGISurfaceInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE GetDesc(
        DXGI_SURFACE_DESC* pDesc);

    virtual HRESULT STDMETHODCALLTYPE Map(
        DXGI_MAPPED_RECT* pLockedRect,
        UINT MapFlags);

    virtual HRESULT STDMETHODCALLTYPE Unmap();

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, IDXGISurface_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<IDXGISurfaceInfo> info_;
};

class IDXGISurface1_Wrapper : public IDXGISurface_Wrapper
{
  public:
    IDXGISurface1_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGISurface1_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE GetDC(
        BOOL Discard,
        HDC* phdc);

    virtual HRESULT STDMETHODCALLTYPE ReleaseDC(
        RECT* pDirtyRect);

};

class IDXGIAdapter_Wrapper : public IDXGIObject_Wrapper
{
  public:
    IDXGIAdapter_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIAdapter_Wrapper*>(u); });

    ~IDXGIAdapter_Wrapper();

    static IDXGIAdapter_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const IDXGIAdapterInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<IDXGIAdapterInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE EnumOutputs(
        UINT Output,
        IDXGIOutput** ppOutput);

    virtual HRESULT STDMETHODCALLTYPE GetDesc(
        DXGI_ADAPTER_DESC* pDesc);

    virtual HRESULT STDMETHODCALLTYPE CheckInterfaceSupport(
        REFGUID InterfaceName,
        LARGE_INTEGER* pUMDVersion);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, IDXGIAdapter_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<IDXGIAdapterInfo> info_;
};

class IDXGIOutput_Wrapper : public IDXGIObject_Wrapper
{
  public:
    IDXGIOutput_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIOutput_Wrapper*>(u); });

    ~IDXGIOutput_Wrapper();

    static IDXGIOutput_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const IDXGIOutputInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<IDXGIOutputInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE GetDesc(
        DXGI_OUTPUT_DESC* pDesc);

    virtual HRESULT STDMETHODCALLTYPE GetDisplayModeList(
        DXGI_FORMAT EnumFormat,
        UINT Flags,
        UINT* pNumModes,
        DXGI_MODE_DESC* pDesc);

    virtual HRESULT STDMETHODCALLTYPE FindClosestMatchingMode(
        const DXGI_MODE_DESC* pModeToMatch,
        DXGI_MODE_DESC* pClosestMatch,
        IUnknown* pConcernedDevice);

    virtual HRESULT STDMETHODCALLTYPE WaitForVBlank();

    virtual HRESULT STDMETHODCALLTYPE TakeOwnership(
        IUnknown* pDevice,
        BOOL Exclusive);

    virtual void STDMETHODCALLTYPE ReleaseOwnership();

    virtual HRESULT STDMETHODCALLTYPE GetGammaControlCapabilities(
        DXGI_GAMMA_CONTROL_CAPABILITIES* pGammaCaps);

    virtual HRESULT STDMETHODCALLTYPE SetGammaControl(
        const DXGI_GAMMA_CONTROL* pArray);

    virtual HRESULT STDMETHODCALLTYPE GetGammaControl(
        DXGI_GAMMA_CONTROL* pArray);

    virtual HRESULT STDMETHODCALLTYPE SetDisplaySurface(
        IDXGISurface* pScanoutSurface);

    virtual HRESULT STDMETHODCALLTYPE GetDisplaySurfaceData(
        IDXGISurface* pDestination);

    virtual HRESULT STDMETHODCALLTYPE GetFrameStatistics(
        DXGI_FRAME_STATISTICS* pStats);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, IDXGIOutput_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<IDXGIOutputInfo> info_;
};

class IDXGISwapChain_Wrapper : public IDXGIDeviceSubObject_Wrapper
{
  public:
    IDXGISwapChain_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGISwapChain_Wrapper*>(u); });

    ~IDXGISwapChain_Wrapper();

    static IDXGISwapChain_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const IDXGISwapChainInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<IDXGISwapChainInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE Present(
        UINT SyncInterval,
        UINT Flags);

    virtual HRESULT STDMETHODCALLTYPE GetBuffer(
        UINT Buffer,
        REFIID riid,
        void** ppSurface);

    virtual HRESULT STDMETHODCALLTYPE SetFullscreenState(
        BOOL Fullscreen,
        IDXGIOutput* pTarget);

    virtual HRESULT STDMETHODCALLTYPE GetFullscreenState(
        BOOL* pFullscreen,
        IDXGIOutput** ppTarget);

    virtual HRESULT STDMETHODCALLTYPE GetDesc(
        DXGI_SWAP_CHAIN_DESC* pDesc);

    virtual HRESULT STDMETHODCALLTYPE ResizeBuffers(
        UINT BufferCount,
        UINT Width,
        UINT Height,
        DXGI_FORMAT NewFormat,
        UINT SwapChainFlags);

    virtual HRESULT STDMETHODCALLTYPE ResizeTarget(
        const DXGI_MODE_DESC* pNewTargetParameters);

    virtual HRESULT STDMETHODCALLTYPE GetContainingOutput(
        IDXGIOutput** ppOutput);

    virtual HRESULT STDMETHODCALLTYPE GetFrameStatistics(
        DXGI_FRAME_STATISTICS* pStats);

    virtual HRESULT STDMETHODCALLTYPE GetLastPresentCount(
        UINT* pLastPresentCount);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, IDXGISwapChain_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<IDXGISwapChainInfo> info_;
};

class IDXGIFactory_Wrapper : public IDXGIObject_Wrapper
{
  public:
    IDXGIFactory_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIFactory_Wrapper*>(u); });

    ~IDXGIFactory_Wrapper();

    static IDXGIFactory_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const IDXGIFactoryInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<IDXGIFactoryInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE EnumAdapters(
        UINT Adapter,
        IDXGIAdapter** ppAdapter);

    virtual HRESULT STDMETHODCALLTYPE MakeWindowAssociation(
        HWND WindowHandle,
        UINT Flags);

    virtual HRESULT STDMETHODCALLTYPE GetWindowAssociation(
        HWND* pWindowHandle);

    virtual HRESULT STDMETHODCALLTYPE CreateSwapChain(
        IUnknown* pDevice,
        DXGI_SWAP_CHAIN_DESC* pDesc,
        IDXGISwapChain** ppSwapChain);

    virtual HRESULT STDMETHODCALLTYPE CreateSoftwareAdapter(
        HMODULE Module,
        IDXGIAdapter** ppAdapter);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, IDXGIFactory_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<IDXGIFactoryInfo> info_;
};

class IDXGIDevice_Wrapper : public IDXGIObject_Wrapper
{
  public:
    IDXGIDevice_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIDevice_Wrapper*>(u); });

    ~IDXGIDevice_Wrapper();

    static IDXGIDevice_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const IDXGIDeviceInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<IDXGIDeviceInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE GetAdapter(
        IDXGIAdapter** pAdapter);

    virtual HRESULT STDMETHODCALLTYPE CreateSurface(
        const DXGI_SURFACE_DESC* pDesc,
        UINT NumSurfaces,
        DXGI_USAGE Usage,
        const DXGI_SHARED_RESOURCE* pSharedResource,
        IDXGISurface** ppSurface);

    virtual HRESULT STDMETHODCALLTYPE QueryResourceResidency(
        IUnknown* const* ppResources,
        DXGI_RESIDENCY* pResidencyStatus,
        UINT NumResources);

    virtual HRESULT STDMETHODCALLTYPE SetGPUThreadPriority(
        INT Priority);

    virtual HRESULT STDMETHODCALLTYPE GetGPUThreadPriority(
        INT* pPriority);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, IDXGIDevice_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<IDXGIDeviceInfo> info_;
};

class IDXGIFactory1_Wrapper : public IDXGIFactory_Wrapper
{
  public:
    IDXGIFactory1_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIFactory1_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE EnumAdapters1(
        UINT Adapter,
        IDXGIAdapter1** ppAdapter);

    virtual BOOL STDMETHODCALLTYPE IsCurrent();

};

class IDXGIAdapter1_Wrapper : public IDXGIAdapter_Wrapper
{
  public:
    IDXGIAdapter1_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIAdapter1_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE GetDesc1(
        DXGI_ADAPTER_DESC1* pDesc);

};

class IDXGIDevice1_Wrapper : public IDXGIDevice_Wrapper
{
  public:
    IDXGIDevice1_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIDevice1_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE SetMaximumFrameLatency(
        UINT MaxLatency);

    virtual HRESULT STDMETHODCALLTYPE GetMaximumFrameLatency(
        UINT* pMaxLatency);

};


/*
** This part is generated from dxgi1_2.h in Windows SDK: 10.0.20348.0
**
*/

class IDXGIDisplayControl_Wrapper : public IUnknown_Wrapper
{
  public:
    IDXGIDisplayControl_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIDisplayControl_Wrapper*>(u); });

    ~IDXGIDisplayControl_Wrapper();

    static IDXGIDisplayControl_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const IDXGIDisplayControlInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<IDXGIDisplayControlInfo> GetObjectInfo() { return info_; }

    virtual BOOL STDMETHODCALLTYPE IsStereoEnabled();

    virtual void STDMETHODCALLTYPE SetStereoEnabled(
        BOOL enabled);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, IDXGIDisplayControl_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<IDXGIDisplayControlInfo> info_;
};

class IDXGIOutputDuplication_Wrapper : public IDXGIObject_Wrapper
{
  public:
    IDXGIOutputDuplication_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIOutputDuplication_Wrapper*>(u); });

    ~IDXGIOutputDuplication_Wrapper();

    static IDXGIOutputDuplication_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const IDXGIOutputDuplicationInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<IDXGIOutputDuplicationInfo> GetObjectInfo() { return info_; }

    virtual void STDMETHODCALLTYPE GetDesc(
        DXGI_OUTDUPL_DESC* pDesc);

    virtual HRESULT STDMETHODCALLTYPE AcquireNextFrame(
        UINT TimeoutInMilliseconds,
        DXGI_OUTDUPL_FRAME_INFO* pFrameInfo,
        IDXGIResource** ppDesktopResource);

    virtual HRESULT STDMETHODCALLTYPE GetFrameDirtyRects(
        UINT DirtyRectsBufferSize,
        RECT* pDirtyRectsBuffer,
        UINT* pDirtyRectsBufferSizeRequired);

    virtual HRESULT STDMETHODCALLTYPE GetFrameMoveRects(
        UINT MoveRectsBufferSize,
        DXGI_OUTDUPL_MOVE_RECT* pMoveRectBuffer,
        UINT* pMoveRectsBufferSizeRequired);

    virtual HRESULT STDMETHODCALLTYPE GetFramePointerShape(
        UINT PointerShapeBufferSize,
        void* pPointerShapeBuffer,
        UINT* pPointerShapeBufferSizeRequired,
        DXGI_OUTDUPL_POINTER_SHAPE_INFO* pPointerShapeInfo);

    virtual HRESULT STDMETHODCALLTYPE MapDesktopSurface(
        DXGI_MAPPED_RECT* pLockedRect);

    virtual HRESULT STDMETHODCALLTYPE UnMapDesktopSurface();

    virtual HRESULT STDMETHODCALLTYPE ReleaseFrame();

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, IDXGIOutputDuplication_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<IDXGIOutputDuplicationInfo> info_;
};

class IDXGISurface2_Wrapper : public IDXGISurface1_Wrapper
{
  public:
    IDXGISurface2_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGISurface2_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE GetResource(
        REFIID riid,
        void** ppParentResource,
        UINT* pSubresourceIndex);

};

class IDXGIResource1_Wrapper : public IDXGIResource_Wrapper
{
  public:
    IDXGIResource1_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIResource1_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE CreateSubresourceSurface(
        UINT index,
        IDXGISurface2** ppSurface);

    virtual HRESULT STDMETHODCALLTYPE CreateSharedHandle(
        const SECURITY_ATTRIBUTES* pAttributes,
        DWORD dwAccess,
        LPCWSTR lpName,
        HANDLE* pHandle);

};

class IDXGIDevice2_Wrapper : public IDXGIDevice1_Wrapper
{
  public:
    IDXGIDevice2_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIDevice2_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE OfferResources(
        UINT NumResources,
        IDXGIResource* const* ppResources,
        DXGI_OFFER_RESOURCE_PRIORITY Priority);

    virtual HRESULT STDMETHODCALLTYPE ReclaimResources(
        UINT NumResources,
        IDXGIResource* const* ppResources,
        BOOL* pDiscarded);

    virtual HRESULT STDMETHODCALLTYPE EnqueueSetEvent(
        HANDLE hEvent);

};

class IDXGISwapChain1_Wrapper : public IDXGISwapChain_Wrapper
{
  public:
    IDXGISwapChain1_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGISwapChain1_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE GetDesc1(
        DXGI_SWAP_CHAIN_DESC1* pDesc);

    virtual HRESULT STDMETHODCALLTYPE GetFullscreenDesc(
        DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pDesc);

    virtual HRESULT STDMETHODCALLTYPE GetHwnd(
        HWND* pHwnd);

    virtual HRESULT STDMETHODCALLTYPE GetCoreWindow(
        REFIID refiid,
        void** ppUnk);

    virtual HRESULT STDMETHODCALLTYPE Present1(
        UINT SyncInterval,
        UINT PresentFlags,
        const DXGI_PRESENT_PARAMETERS* pPresentParameters);

    virtual BOOL STDMETHODCALLTYPE IsTemporaryMonoSupported();

    virtual HRESULT STDMETHODCALLTYPE GetRestrictToOutput(
        IDXGIOutput** ppRestrictToOutput);

    virtual HRESULT STDMETHODCALLTYPE SetBackgroundColor(
        const DXGI_RGBA* pColor);

    virtual HRESULT STDMETHODCALLTYPE GetBackgroundColor(
        DXGI_RGBA* pColor);

    virtual HRESULT STDMETHODCALLTYPE SetRotation(
        DXGI_MODE_ROTATION Rotation);

    virtual HRESULT STDMETHODCALLTYPE GetRotation(
        DXGI_MODE_ROTATION* pRotation);

};

class IDXGIFactory2_Wrapper : public IDXGIFactory1_Wrapper
{
  public:
    IDXGIFactory2_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIFactory2_Wrapper*>(u); });

    virtual BOOL STDMETHODCALLTYPE IsWindowedStereoEnabled();

    virtual HRESULT STDMETHODCALLTYPE CreateSwapChainForHwnd(
        IUnknown* pDevice,
        HWND hWnd,
        const DXGI_SWAP_CHAIN_DESC1* pDesc,
        const DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pFullscreenDesc,
        IDXGIOutput* pRestrictToOutput,
        IDXGISwapChain1** ppSwapChain);

    virtual HRESULT STDMETHODCALLTYPE CreateSwapChainForCoreWindow(
        IUnknown* pDevice,
        IUnknown* pWindow,
        const DXGI_SWAP_CHAIN_DESC1* pDesc,
        IDXGIOutput* pRestrictToOutput,
        IDXGISwapChain1** ppSwapChain);

    virtual HRESULT STDMETHODCALLTYPE GetSharedResourceAdapterLuid(
        HANDLE hResource,
        LUID* pLuid);

    virtual HRESULT STDMETHODCALLTYPE RegisterStereoStatusWindow(
        HWND WindowHandle,
        UINT wMsg,
        DWORD* pdwCookie);

    virtual HRESULT STDMETHODCALLTYPE RegisterStereoStatusEvent(
        HANDLE hEvent,
        DWORD* pdwCookie);

    virtual void STDMETHODCALLTYPE UnregisterStereoStatus(
        DWORD dwCookie);

    virtual HRESULT STDMETHODCALLTYPE RegisterOcclusionStatusWindow(
        HWND WindowHandle,
        UINT wMsg,
        DWORD* pdwCookie);

    virtual HRESULT STDMETHODCALLTYPE RegisterOcclusionStatusEvent(
        HANDLE hEvent,
        DWORD* pdwCookie);

    virtual void STDMETHODCALLTYPE UnregisterOcclusionStatus(
        DWORD dwCookie);

    virtual HRESULT STDMETHODCALLTYPE CreateSwapChainForComposition(
        IUnknown* pDevice,
        const DXGI_SWAP_CHAIN_DESC1* pDesc,
        IDXGIOutput* pRestrictToOutput,
        IDXGISwapChain1** ppSwapChain);

};

class IDXGIAdapter2_Wrapper : public IDXGIAdapter1_Wrapper
{
  public:
    IDXGIAdapter2_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIAdapter2_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE GetDesc2(
        DXGI_ADAPTER_DESC2* pDesc);

};

class IDXGIOutput1_Wrapper : public IDXGIOutput_Wrapper
{
  public:
    IDXGIOutput1_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIOutput1_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE GetDisplayModeList1(
        DXGI_FORMAT EnumFormat,
        UINT Flags,
        UINT* pNumModes,
        DXGI_MODE_DESC1* pDesc);

    virtual HRESULT STDMETHODCALLTYPE FindClosestMatchingMode1(
        const DXGI_MODE_DESC1* pModeToMatch,
        DXGI_MODE_DESC1* pClosestMatch,
        IUnknown* pConcernedDevice);

    virtual HRESULT STDMETHODCALLTYPE GetDisplaySurfaceData1(
        IDXGIResource* pDestination);

    virtual HRESULT STDMETHODCALLTYPE DuplicateOutput(
        IUnknown* pDevice,
        IDXGIOutputDuplication** ppOutputDuplication);

};


/*
** This part is generated from dxgi1_3.h in Windows SDK: 10.0.20348.0
**
*/

HRESULT WINAPI CreateDXGIFactory2(
    UINT Flags,
    REFIID riid,
    void** ppFactory);

HRESULT WINAPI DXGIGetDebugInterface1(
    UINT Flags,
    REFIID riid,
    void** pDebug);

class IDXGIDevice3_Wrapper : public IDXGIDevice2_Wrapper
{
  public:
    IDXGIDevice3_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIDevice3_Wrapper*>(u); });

    virtual void STDMETHODCALLTYPE Trim();

};

class IDXGISwapChain2_Wrapper : public IDXGISwapChain1_Wrapper
{
  public:
    IDXGISwapChain2_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGISwapChain2_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE SetSourceSize(
        UINT Width,
        UINT Height);

    virtual HRESULT STDMETHODCALLTYPE GetSourceSize(
        UINT* pWidth,
        UINT* pHeight);

    virtual HRESULT STDMETHODCALLTYPE SetMaximumFrameLatency(
        UINT MaxLatency);

    virtual HRESULT STDMETHODCALLTYPE GetMaximumFrameLatency(
        UINT* pMaxLatency);

    virtual HANDLE STDMETHODCALLTYPE GetFrameLatencyWaitableObject();

    virtual HRESULT STDMETHODCALLTYPE SetMatrixTransform(
        const DXGI_MATRIX_3X2_F* pMatrix);

    virtual HRESULT STDMETHODCALLTYPE GetMatrixTransform(
        DXGI_MATRIX_3X2_F* pMatrix);

};

class IDXGIOutput2_Wrapper : public IDXGIOutput1_Wrapper
{
  public:
    IDXGIOutput2_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIOutput2_Wrapper*>(u); });

    virtual BOOL STDMETHODCALLTYPE SupportsOverlays();

};

class IDXGIFactory3_Wrapper : public IDXGIFactory2_Wrapper
{
  public:
    IDXGIFactory3_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIFactory3_Wrapper*>(u); });

    virtual UINT STDMETHODCALLTYPE GetCreationFlags();

};

class IDXGIDecodeSwapChain_Wrapper : public IUnknown_Wrapper
{
  public:
    IDXGIDecodeSwapChain_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIDecodeSwapChain_Wrapper*>(u); });

    ~IDXGIDecodeSwapChain_Wrapper();

    static IDXGIDecodeSwapChain_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const IDXGIDecodeSwapChainInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<IDXGIDecodeSwapChainInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE PresentBuffer(
        UINT BufferToPresent,
        UINT SyncInterval,
        UINT Flags);

    virtual HRESULT STDMETHODCALLTYPE SetSourceRect(
        const RECT* pRect);

    virtual HRESULT STDMETHODCALLTYPE SetTargetRect(
        const RECT* pRect);

    virtual HRESULT STDMETHODCALLTYPE SetDestSize(
        UINT Width,
        UINT Height);

    virtual HRESULT STDMETHODCALLTYPE GetSourceRect(
        RECT* pRect);

    virtual HRESULT STDMETHODCALLTYPE GetTargetRect(
        RECT* pRect);

    virtual HRESULT STDMETHODCALLTYPE GetDestSize(
        UINT* pWidth,
        UINT* pHeight);

    virtual HRESULT STDMETHODCALLTYPE SetColorSpace(
        DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS ColorSpace);

    virtual DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS STDMETHODCALLTYPE GetColorSpace();

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, IDXGIDecodeSwapChain_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<IDXGIDecodeSwapChainInfo> info_;
};

class IDXGIFactoryMedia_Wrapper : public IUnknown_Wrapper
{
  public:
    IDXGIFactoryMedia_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIFactoryMedia_Wrapper*>(u); });

    ~IDXGIFactoryMedia_Wrapper();

    static IDXGIFactoryMedia_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const IDXGIFactoryMediaInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<IDXGIFactoryMediaInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE CreateSwapChainForCompositionSurfaceHandle(
        IUnknown* pDevice,
        HANDLE hSurface,
        const DXGI_SWAP_CHAIN_DESC1* pDesc,
        IDXGIOutput* pRestrictToOutput,
        IDXGISwapChain1** ppSwapChain);

    virtual HRESULT STDMETHODCALLTYPE CreateDecodeSwapChainForCompositionSurfaceHandle(
        IUnknown* pDevice,
        HANDLE hSurface,
        DXGI_DECODE_SWAP_CHAIN_DESC* pDesc,
        IDXGIResource* pYuvDecodeBuffers,
        IDXGIOutput* pRestrictToOutput,
        IDXGIDecodeSwapChain** ppSwapChain);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, IDXGIFactoryMedia_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<IDXGIFactoryMediaInfo> info_;
};

class IDXGISwapChainMedia_Wrapper : public IUnknown_Wrapper
{
  public:
    IDXGISwapChainMedia_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGISwapChainMedia_Wrapper*>(u); });

    ~IDXGISwapChainMedia_Wrapper();

    static IDXGISwapChainMedia_Wrapper* GetExistingWrapper(IUnknown* object);

    std::shared_ptr<const IDXGISwapChainMediaInfo> GetObjectInfo() const { return info_; }

    std::shared_ptr<IDXGISwapChainMediaInfo> GetObjectInfo() { return info_; }

    virtual HRESULT STDMETHODCALLTYPE GetFrameStatisticsMedia(
        DXGI_FRAME_STATISTICS_MEDIA* pStats);

    virtual HRESULT STDMETHODCALLTYPE SetPresentDuration(
        UINT Duration);

    virtual HRESULT STDMETHODCALLTYPE CheckPresentDurationSupport(
        UINT DesiredPresentDuration,
        UINT* pClosestSmallerPresentDuration,
        UINT* pClosestLargerPresentDuration);

  private:
    // Map to prevent creation of more than one interface wrapper per object.
    typedef std::unordered_map<IUnknown*, IDXGISwapChainMedia_Wrapper*> ObjectMap;
    static ObjectMap  object_map_;
    static std::mutex object_map_lock_;

    std::shared_ptr<IDXGISwapChainMediaInfo> info_;
};

class IDXGIOutput3_Wrapper : public IDXGIOutput2_Wrapper
{
  public:
    IDXGIOutput3_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIOutput3_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE CheckOverlaySupport(
        DXGI_FORMAT EnumFormat,
        IUnknown* pConcernedDevice,
        UINT* pFlags);

};


/*
** This part is generated from dxgi1_4.h in Windows SDK: 10.0.20348.0
**
*/

class IDXGISwapChain3_Wrapper : public IDXGISwapChain2_Wrapper
{
  public:
    IDXGISwapChain3_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGISwapChain3_Wrapper*>(u); });

    virtual UINT STDMETHODCALLTYPE GetCurrentBackBufferIndex();

    virtual HRESULT STDMETHODCALLTYPE CheckColorSpaceSupport(
        DXGI_COLOR_SPACE_TYPE ColorSpace,
        UINT* pColorSpaceSupport);

    virtual HRESULT STDMETHODCALLTYPE SetColorSpace1(
        DXGI_COLOR_SPACE_TYPE ColorSpace);

    virtual HRESULT STDMETHODCALLTYPE ResizeBuffers1(
        UINT BufferCount,
        UINT Width,
        UINT Height,
        DXGI_FORMAT Format,
        UINT SwapChainFlags,
        const UINT* pCreationNodeMask,
        IUnknown* const* ppPresentQueue);

};

class IDXGIOutput4_Wrapper : public IDXGIOutput3_Wrapper
{
  public:
    IDXGIOutput4_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIOutput4_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE CheckOverlayColorSpaceSupport(
        DXGI_FORMAT Format,
        DXGI_COLOR_SPACE_TYPE ColorSpace,
        IUnknown* pConcernedDevice,
        UINT* pFlags);

};

class IDXGIFactory4_Wrapper : public IDXGIFactory3_Wrapper
{
  public:
    IDXGIFactory4_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIFactory4_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE EnumAdapterByLuid(
        LUID AdapterLuid,
        REFIID riid,
        void** ppvAdapter);

    virtual HRESULT STDMETHODCALLTYPE EnumWarpAdapter(
        REFIID riid,
        void** ppvAdapter);

};

class IDXGIAdapter3_Wrapper : public IDXGIAdapter2_Wrapper
{
  public:
    IDXGIAdapter3_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIAdapter3_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE RegisterHardwareContentProtectionTeardownStatusEvent(
        HANDLE hEvent,
        DWORD* pdwCookie);

    virtual void STDMETHODCALLTYPE UnregisterHardwareContentProtectionTeardownStatus(
        DWORD dwCookie);

    virtual HRESULT STDMETHODCALLTYPE QueryVideoMemoryInfo(
        UINT NodeIndex,
        DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup,
        DXGI_QUERY_VIDEO_MEMORY_INFO* pVideoMemoryInfo);

    virtual HRESULT STDMETHODCALLTYPE SetVideoMemoryReservation(
        UINT NodeIndex,
        DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup,
        UINT64 Reservation);

    virtual HRESULT STDMETHODCALLTYPE RegisterVideoMemoryBudgetChangeNotificationEvent(
        HANDLE hEvent,
        DWORD* pdwCookie);

    virtual void STDMETHODCALLTYPE UnregisterVideoMemoryBudgetChangeNotification(
        DWORD dwCookie);

};


/*
** This part is generated from dxgi1_5.h in Windows SDK: 10.0.20348.0
**
*/

class IDXGIOutput5_Wrapper : public IDXGIOutput4_Wrapper
{
  public:
    IDXGIOutput5_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIOutput5_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE DuplicateOutput1(
        IUnknown* pDevice,
        UINT Flags,
        UINT SupportedFormatsCount,
        const DXGI_FORMAT* pSupportedFormats,
        IDXGIOutputDuplication** ppOutputDuplication);

};

class IDXGISwapChain4_Wrapper : public IDXGISwapChain3_Wrapper
{
  public:
    IDXGISwapChain4_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGISwapChain4_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE SetHDRMetaData(
        DXGI_HDR_METADATA_TYPE Type,
        UINT Size,
        void* pMetaData);

};

class IDXGIDevice4_Wrapper : public IDXGIDevice3_Wrapper
{
  public:
    IDXGIDevice4_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIDevice4_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE OfferResources1(
        UINT NumResources,
        IDXGIResource* const* ppResources,
        DXGI_OFFER_RESOURCE_PRIORITY Priority,
        UINT Flags);

    virtual HRESULT STDMETHODCALLTYPE ReclaimResources1(
        UINT NumResources,
        IDXGIResource* const* ppResources,
        DXGI_RECLAIM_RESOURCE_RESULTS* pResults);

};

class IDXGIFactory5_Wrapper : public IDXGIFactory4_Wrapper
{
  public:
    IDXGIFactory5_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIFactory5_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE CheckFeatureSupport(
        DXGI_FEATURE Feature,
        void* pFeatureSupportData,
        UINT FeatureSupportDataSize);

};


/*
** This part is generated from dxgi1_6.h in Windows SDK: 10.0.20348.0
**
*/

HRESULT WINAPI DXGIDeclareAdapterRemovalSupport();

class IDXGIAdapter4_Wrapper : public IDXGIAdapter3_Wrapper
{
  public:
    IDXGIAdapter4_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIAdapter4_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE GetDesc3(
        DXGI_ADAPTER_DESC3* pDesc);

};

class IDXGIOutput6_Wrapper : public IDXGIOutput5_Wrapper
{
  public:
    IDXGIOutput6_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIOutput6_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE GetDesc1(
        DXGI_OUTPUT_DESC1* pDesc);

    virtual HRESULT STDMETHODCALLTYPE CheckHardwareCompositionSupport(
        UINT* pFlags);

};

class IDXGIFactory6_Wrapper : public IDXGIFactory5_Wrapper
{
  public:
    IDXGIFactory6_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIFactory6_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE EnumAdapterByGpuPreference(
        UINT Adapter,
        DXGI_GPU_PREFERENCE GpuPreference,
        REFIID riid,
        void** ppvAdapter);

};

class IDXGIFactory7_Wrapper : public IDXGIFactory6_Wrapper
{
  public:
    IDXGIFactory7_Wrapper(REFIID riid, IUnknown* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIFactory7_Wrapper*>(u); });

    virtual HRESULT STDMETHODCALLTYPE RegisterAdaptersChangedEvent(
        HANDLE hEvent,
        DWORD* pdwCookie);

    virtual HRESULT STDMETHODCALLTYPE UnregisterAdaptersChangedEvent(
        DWORD dwCookie);

};


/*
** This part is generated from dxgicommon.h in Windows SDK: 10.0.20348.0
**
*/


/*
** This part is generated from dxgitype.h in Windows SDK: 10.0.20348.0
**
*/


/*
** This part is generated from Unknwnbase.h in Windows SDK: 10.0.20348.0
**
*/


/*
** This part is generated from guiddef.h in Windows SDK: 10.0.20348.0
**
*/


/*
** This part is generated from windef.h in Windows SDK: 10.0.20348.0
**
*/


/*
** This part is generated from minwinbase.h in Windows SDK: 10.0.20348.0
**
*/

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
