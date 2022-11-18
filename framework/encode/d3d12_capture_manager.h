/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2021 LunarG, Inc.
** Copyright (c) 2019 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_ENCODE_D3D12_CAPTURE_MANAGER_H
#define GFXRECON_ENCODE_D3D12_CAPTURE_MANAGER_H

#include "encode/capture_manager.h"

#include <cassert>
#include <stdint.h>

#include "encode/d3d12_dispatch_table.h"
#include "encode/dxgi_dispatch_table.h"
#include "generated/generated_dx12_wrappers.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class D3D12CaptureManager : public CaptureManager
{
  public:
    static D3D12CaptureManager* Get() { return instance_; }

    // Creates the capture manager instance if none exists, or increments a reference count if an instance already
    // exists.
    static bool CreateInstance();

    // Decrement the instance reference count, releasing resources when the count reaches zero.  Ignored if the count is
    // already zero.
    static void DestroyInstance();

    //----------------------------------------------------------------------------
    /// \brief Initializes the DXGI dispatch table.
    ///
    /// Initializes the CaptureManager's internal DXGI dispatch table with functions
    /// loaded from the DXGI system DLL.  This dispatch table will be used by the
    /// 'wrapper' functions to invoke the 'real' DXGI function prior to processing
    /// the function parameters for encoding.
    ///
    /// \param dispatch_table A DxgiDispatchTable object containing the DXGI
    ///                       function pointers to be used for initialization.
    //----------------------------------------------------------------------------
    void InitDxgiDispatchTable(const DxgiDispatchTable& dispatch_table) { dxgi_dispatch_table_ = dispatch_table; }

    //----------------------------------------------------------------------------
    /// \brief Initializes the D3D12 dispatch table.
    ///
    /// Initializes the CaptureManager's internal D3D12 dispatch table with
    /// functions loaded from the D3D12 system DLL.  This dispatch table will be
    /// used by the 'wrapper' functions to invoke the 'real' D3D12 function prior
    /// to processing the function parameters for encoding.
    ///
    /// \param dispatch_table A D3D12DispatchTable object containing the DXGI
    ///                       function pointers to be used for initialization.
    //----------------------------------------------------------------------------
    void InitD3D12DispatchTable(const D3D12DispatchTable& dispatch_table) { d3d12_dispatch_table_ = dispatch_table; }

    //----------------------------------------------------------------------------
    /// \brief Retrieves the DXGI dispatch table.
    ///
    /// Retrieves the CaptureManager's internal DXGI dispatch table. Intended to be
    /// used by the 'wrapper' functions when invoking the 'real' DXGI functions.
    ///
    /// \return A DxgiDispatchTable object containing DXGI function pointers
    ///         retrieved from the system DLL.
    //----------------------------------------------------------------------------
    const DxgiDispatchTable& GetDxgiDispatchTable() const { return dxgi_dispatch_table_; }

    //----------------------------------------------------------------------------
    /// \brief Retrieves the D3D12 dispatch table.
    ///
    /// Retrieves the CaptureManager's internal D3D12 dispatch table. Intended to be
    /// used by the 'wrapper' functions when invoking the 'real' D3D12 functions.
    ///
    /// \return A D3D12DispatchTable object containing D3D12 function pointers
    ///         retrieved from the system DLL.
    //----------------------------------------------------------------------------
    const D3D12DispatchTable& GetD3D12DispatchTable() const { return d3d12_dispatch_table_; }

    //----------------------------------------------------------------------------
    /// \brief Increments the scope count for the current thread.
    ///
    /// Increments a per-thread scope count that is intended to indicate if an
    /// intercepted API call is being made directly by the application (count is
    /// equal to 1) or by another API call (count is greater than 1).
    ///
    /// \return The scope count for the current thread.
    //----------------------------------------------------------------------------
    uint32_t IncrementCallScope() { return ++call_scope_; }

    //----------------------------------------------------------------------------
    /// \brief Decrements the scope count for the current thread.
    ///
    /// Decrements a per-thread scope count that is intended to indicate if an
    /// intercepted API call is being made directly by the application (count is
    /// equal to 1) or by another API call (count is greater than 1).
    ///
    /// \return The scope count for the current thread.
    //----------------------------------------------------------------------------
    uint32_t DecrementCallScope() { return --call_scope_; }

    void PostProcess_IDXGIFactory_CreateSwapChain(IDXGIFactory_Wrapper* wrapper,
                                                  HRESULT               result,
                                                  IUnknown*             device,
                                                  DXGI_SWAP_CHAIN_DESC* desc,
                                                  IDXGISwapChain**      swap_chain);

    void PostProcess_IDXGIFactory2_CreateSwapChainForHwnd(IDXGIFactory2_Wrapper*                 wrapper,
                                                          HRESULT                                result,
                                                          IUnknown*                              device,
                                                          HWND                                   hwnd,
                                                          const DXGI_SWAP_CHAIN_DESC1*           desc,
                                                          const DXGI_SWAP_CHAIN_FULLSCREEN_DESC* fullscreen_desc,
                                                          IDXGIOutput*                           restrict_to_output,
                                                          IDXGISwapChain1**                      swap_chain);

    void PostProcess_IDXGIFactory2_CreateSwapChainForCoreWindow(IDXGIFactory2_Wrapper*       wrapper,
                                                                HRESULT                      result,
                                                                IUnknown*                    device,
                                                                IUnknown*                    window,
                                                                const DXGI_SWAP_CHAIN_DESC1* desc,
                                                                IDXGIOutput*                 restrict_to_output,
                                                                IDXGISwapChain1**            swap_chain);

    void PostProcess_IDXGIFactory2_CreateSwapChainForComposition(IDXGIFactory2_Wrapper*       wrapper,
                                                                 HRESULT                      result,
                                                                 IUnknown*                    device,
                                                                 const DXGI_SWAP_CHAIN_DESC1* desc,
                                                                 IDXGIOutput*                 restrict_to_output,
                                                                 IDXGISwapChain1**            swap_chain);

    void PreProcess_IDXGISwapchain_ResizeBuffers(IDXGISwapChain_Wrapper* wrapper,
                                                 UINT                    buffer_count,
                                                 UINT                    width,
                                                 UINT                    height,
                                                 DXGI_FORMAT             new_format,
                                                 UINT                    flags);

    void PostProcess_IDXGISwapchain_ResizeBuffers(IDXGISwapChain_Wrapper* wrapper,
                                                  HRESULT                 result,
                                                  UINT                    buffer_count,
                                                  UINT                    width,
                                                  UINT                    height,
                                                  DXGI_FORMAT             new_format,
                                                  UINT                    flags);

    void PreProcess_IDXGISwapchain3_ResizeBuffers1(IDXGISwapChain_Wrapper* wrapper,
                                                   UINT                    buffer_count,
                                                   UINT                    width,
                                                   UINT                    height,
                                                   DXGI_FORMAT             new_format,
                                                   UINT                    flags,
                                                   const UINT*             node_mask,
                                                   IUnknown* const*        present_queue);

    void PostProcess_IDXGISwapchain3_ResizeBuffers1(IDXGISwapChain_Wrapper* wrapper,
                                                    HRESULT                 result,
                                                    UINT                    buffer_count,
                                                    UINT                    width,
                                                    UINT                    height,
                                                    DXGI_FORMAT             new_format,
                                                    UINT                    flags,
                                                    const UINT*             node_mask,
                                                    IUnknown* const*        present_queue);

    void Destroy_IDXGISwapChain(IDXGISwapChain_Wrapper* wrapper);

    void PostProcess_ID3D12Device_CreateDescriptorHeap(ID3D12Device_Wrapper*             wrapper,
                                                       HRESULT                           result,
                                                       const D3D12_DESCRIPTOR_HEAP_DESC* desc,
                                                       REFIID                            riid,
                                                       void**                            heap);

    void PostProcess_ID3D12Device_CreateHeap(
        ID3D12Device_Wrapper* wrapper, HRESULT result, const D3D12_HEAP_DESC* desc, REFIID riid, void** heap);

    void PostProcess_ID3D12Device_CreateCommittedResource(ID3D12Device_Wrapper*        wrapper,
                                                          HRESULT                      result,
                                                          const D3D12_HEAP_PROPERTIES* heap_properties,
                                                          D3D12_HEAP_FLAGS             heap_flags,
                                                          const D3D12_RESOURCE_DESC*   desc,
                                                          D3D12_RESOURCE_STATES        initial_resource_state,
                                                          const D3D12_CLEAR_VALUE*     optimized_clear_value,
                                                          REFIID                       riid,
                                                          void**                       resource);

    void PostProcess_ID3D12Device_CreatePlacedResource(ID3D12Device_Wrapper*      wrapper,
                                                       HRESULT                    result,
                                                       ID3D12Heap*                heap,
                                                       UINT64                     heap_offset,
                                                       const D3D12_RESOURCE_DESC* desc,
                                                       D3D12_RESOURCE_STATES      initial_state,
                                                       const D3D12_CLEAR_VALUE*   optimized_clear_value,
                                                       REFIID                     riid,
                                                       void**                     resource);

    void PreProcess_ID3D12Device3_OpenExistingHeapFromAddress(ID3D12Device3_Wrapper* wrapper,
                                                              const void*            address,
                                                              REFIID                 riid,
                                                              void**                 heap);

    void PostProcess_ID3D12Device4_CreateHeap1(ID3D12Device4_Wrapper*          wrapper,
                                               HRESULT                         result,
                                               const D3D12_HEAP_DESC*          desc,
                                               ID3D12ProtectedResourceSession* protected_session,
                                               REFIID                          riid,
                                               void**                          heap);

    void PostProcess_ID3D12Device4_CreateCommittedResource1(ID3D12Device4_Wrapper*          wrapper,
                                                            HRESULT                         result,
                                                            const D3D12_HEAP_PROPERTIES*    heap_properties,
                                                            D3D12_HEAP_FLAGS                heap_flags,
                                                            const D3D12_RESOURCE_DESC*      desc,
                                                            D3D12_RESOURCE_STATES           initial_resource_state,
                                                            const D3D12_CLEAR_VALUE*        optimized_clear_value,
                                                            ID3D12ProtectedResourceSession* protected_session,
                                                            REFIID                          riid,
                                                            void**                          resource);

    void PostProcess_ID3D12Device8_CreateCommittedResource2(ID3D12Device8_Wrapper*          wrapper,
                                                            HRESULT                         result,
                                                            const D3D12_HEAP_PROPERTIES*    heap_properties,
                                                            D3D12_HEAP_FLAGS                heap_flags,
                                                            const D3D12_RESOURCE_DESC1*     desc,
                                                            D3D12_RESOURCE_STATES           initial_resource_state,
                                                            const D3D12_CLEAR_VALUE*        optimized_clear_value,
                                                            ID3D12ProtectedResourceSession* protected_session,
                                                            REFIID                          riid,
                                                            void**                          resource);

    void PostProcess_ID3D12Device8_CreatePlacedResource1(ID3D12Device8_Wrapper*      wrapper,
                                                         HRESULT                     result,
                                                         ID3D12Heap*                 heap,
                                                         UINT64                      heap_offset,
                                                         const D3D12_RESOURCE_DESC1* desc,
                                                         D3D12_RESOURCE_STATES       initial_state,
                                                         const D3D12_CLEAR_VALUE*    optimized_clear_value,
                                                         REFIID                      riid,
                                                         void**                      resource);

    void PostProcess_ID3D12Resource_Map(
        ID3D12Resource_Wrapper* wrapper, HRESULT result, UINT subresource, const D3D12_RANGE* read_range, void** data);

    void PreProcess_ID3D12Resource_Unmap(ID3D12Resource_Wrapper* wrapper,
                                         UINT                    subresource,
                                         const D3D12_RANGE*      written_range);

    void PostProcess_ID3D12Resource_GetHeapProperties(ID3D12Resource_Wrapper* wrapper,
                                                      HRESULT                 result,
                                                      D3D12_HEAP_PROPERTIES*  heap_properties,
                                                      D3D12_HEAP_FLAGS*       heap_flags);

    void Destroy_ID3D12Resource(ID3D12Resource_Wrapper* wrapper);

    void PostProcess_ID3D12Heap_GetDesc(ID3D12Heap_Wrapper* wrapper, D3D12_HEAP_DESC& desc);

    void PreProcess_ID3D12CommandQueue_ExecuteCommandLists(ID3D12CommandQueue_Wrapper* wrapper,
                                                           UINT                        num_lists,
                                                           ID3D12CommandList* const*   lists);

    void PreProcess_D3D12CreateDevice(IUnknown*         pAdapter,
                                      D3D_FEATURE_LEVEL MinimumFeatureLevel,
                                      REFIID            riid,
                                      void**            ppDevice);

    D3D12_CPU_DESCRIPTOR_HANDLE
    OverrideID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart(ID3D12DescriptorHeap_Wrapper* wrapper);

    D3D12_GPU_DESCRIPTOR_HANDLE
    OverrideID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart(ID3D12DescriptorHeap_Wrapper* wrapper);

    HRESULT OverrideID3D12Device_CreateCommittedResource(ID3D12Device_Wrapper*        wrapper,
                                                         const D3D12_HEAP_PROPERTIES* heap_properties,
                                                         D3D12_HEAP_FLAGS             heap_flags,
                                                         const D3D12_RESOURCE_DESC*   desc,
                                                         D3D12_RESOURCE_STATES        initial_resource_state,
                                                         const D3D12_CLEAR_VALUE*     optimized_clear_value,
                                                         REFIID                       riid_resource,
                                                         void**                       ppv_resource);

    HRESULT OverrideID3D12Device_CreateCommittedResource1(ID3D12Device4_Wrapper*          wrapper,
                                                          const D3D12_HEAP_PROPERTIES*    heap_properties,
                                                          D3D12_HEAP_FLAGS                heap_flags,
                                                          const D3D12_RESOURCE_DESC*      desc,
                                                          D3D12_RESOURCE_STATES           initial_resource_state,
                                                          const D3D12_CLEAR_VALUE*        optimized_clear_value,
                                                          ID3D12ProtectedResourceSession* protected_session,
                                                          REFIID                          riid_resource,
                                                          void**                          ppv_resource);

    HRESULT OverrideID3D12Device_CreateCommittedResource2(ID3D12Device8_Wrapper*          wrapper,
                                                          const D3D12_HEAP_PROPERTIES*    heap_properties,
                                                          D3D12_HEAP_FLAGS                heap_flags,
                                                          const D3D12_RESOURCE_DESC1*     desc,
                                                          D3D12_RESOURCE_STATES           initial_resource_state,
                                                          const D3D12_CLEAR_VALUE*        optimized_clear_value,
                                                          ID3D12ProtectedResourceSession* protected_session,
                                                          REFIID                          riid_resource,
                                                          void**                          ppv_resource);

    HRESULT OverrideID3D12Device_CreateHeap(ID3D12Device_Wrapper*  wrapper,
                                            const D3D12_HEAP_DESC* desc,
                                            REFIID                 riid,
                                            void**                 heap);

    HRESULT OverrideID3D12Device_CreateHeap1(ID3D12Device4_Wrapper*          wrapper,
                                             const D3D12_HEAP_DESC*          desc,
                                             ID3D12ProtectedResourceSession* protected_session,
                                             REFIID                          riid,
                                             void**                          heap);

    HRESULT OverrideID3D12Device1_CreatePipelineLibrary(
        ID3D12Device1_Wrapper* wrapper, const void* library_blob, SIZE_T blob_length, REFIID riid, void** library);

    HRESULT OverrideID3D12PipelineLibrary_LoadComputePipeline(ID3D12PipelineLibrary_Wrapper*           wrapper,
                                                              LPCWSTR                                  name,
                                                              const D3D12_COMPUTE_PIPELINE_STATE_DESC* desc,
                                                              REFIID                                   riid,
                                                              void**                                   pipeline_state);

    HRESULT OverrideID3D12PipelineLibrary_LoadGraphicsPipeline(ID3D12PipelineLibrary_Wrapper*            wrapper,
                                                               LPCWSTR                                   name,
                                                               const D3D12_GRAPHICS_PIPELINE_STATE_DESC* desc,
                                                               REFIID                                    riid,
                                                               void** pipeline_state);

    HRESULT OverrideID3D12PipelineLibrary1_LoadPipeline(ID3D12PipelineLibrary_Wrapper*          wrapper,
                                                        LPCWSTR                                 name,
                                                        const D3D12_PIPELINE_STATE_STREAM_DESC* desc,
                                                        REFIID                                  riid,
                                                        void**                                  pipeline_state);

    HRESULT OverrideCreateDXGIFactory2(UINT Flags, REFIID riid, void** ppFactory);

  protected:
    D3D12CaptureManager();

    virtual ~D3D12CaptureManager() override {}

    // TODO (GH #83): Add D3D12 trimming support
    virtual void CreateStateTracker() override {}
    virtual void DestroyStateTracker() override {}
    virtual void WriteTrackedState(util::FileOutputStream* file_stream, format::ThreadId thread_id) override {}

    void PreAcquireSwapChainImages(IDXGISwapChain_Wrapper* wrapper, uint32_t image_count, DXGI_SWAP_EFFECT swap_effect);

    void ReleaseSwapChainImages(IDXGISwapChain_Wrapper* wrapper);

    void InitializeID3D12ResourceInfo(ID3D12Device_Wrapper*    device_wrapper,
                                      ID3D12Resource_Wrapper*  resource_wrapper,
                                      D3D12_RESOURCE_DIMENSION dimension,
                                      UINT64                   width,
                                      D3D12_HEAP_TYPE          heap_type,
                                      D3D12_CPU_PAGE_PROPERTY  page_property,
                                      D3D12_MEMORY_POOL        memory_pool,
                                      bool                     has_write_watch);

  private:
    void CheckWriteWatchIgnored(D3D12_HEAP_FLAGS flags, format::HandleId id);
    bool UseWriteWatch(D3D12_HEAP_TYPE type, D3D12_HEAP_FLAGS flags, D3D12_CPU_PAGE_PROPERTY page_property);
    void EnableWriteWatch(D3D12_HEAP_FLAGS& flags, D3D12_HEAP_PROPERTIES& properties);
    bool IsUploadResource(D3D12_HEAP_TYPE type, D3D12_CPU_PAGE_PROPERTY page_property);
    void EnableDebugLayer();

  private:
    static D3D12CaptureManager*       instance_;
    std::set<ID3D12Resource_Wrapper*> mapped_resources_; ///< Track mapped resources for unassisted tracking mode.
    DxgiDispatchTable  dxgi_dispatch_table_;  ///< DXGI dispatch table for functions retrieved from the DXGI DLL.
    D3D12DispatchTable d3d12_dispatch_table_; ///< D3D12 dispatch table for functions retrieved from the D3D12 DLL.
    static thread_local uint32_t call_scope_; ///< Per-thread scope count to determine when an intercepted API call is
                                              ///< being made directly by the application.
    bool debug_layer_enabled_;                ///< Track if debug layer has been enabled.
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_D3D12_CAPTURE_MANAGER_H
