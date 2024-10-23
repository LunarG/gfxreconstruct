/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2021 LunarG, Inc.
** Copyright (c) 2019-2024 Advanced Micro Devices, Inc. All rights reserved.
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

#include "encode/api_capture_manager.h"

#include <cassert>
#include <stdint.h>

#include "encode/ags_dispatch_table.h"
#include "encode/d3d12_dispatch_table.h"
#include "encode/dx12_state_tracker.h"
#include "encode/dxgi_dispatch_table.h"
#include "encode/dx12_rv_annotator.h"
#include "generated/generated_dx12_wrappers.h"
#include "graphics/dx12_image_renderer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class D3D12CaptureManager : public ApiCaptureManager
{
  public:
    static D3D12CaptureManager* Get() { return singleton_; }
    // Creates the capture manager instance if none exists, or increments a reference count if an instance already
    // exists.
    static bool CreateInstance();

    static D3D12CaptureManager* InitSingleton();
    static void                 DestroySingleton();

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
    /// \brief Initializes the AGS dispatch table.
    ///
    /// Initializes the CaptureManager's internal AGS dispatch table with
    /// functions loaded from the AGS DLL.  This dispatch table will be
    /// used by the 'wrapper' functions to invoke the 'real' AGS function prior
    /// to processing the function parameters for encoding.
    ///
    /// \param dispatch_table An AgsDispatchTable object containing the AGS
    ///                       function pointers to be used for initialization.
    //----------------------------------------------------------------------------
    void InitAgsDispatchTable(const AgsDispatchTable& dispatch_table) { ags_dispatch_table_ = dispatch_table; }

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
    /// \brief Retrieves the Amd Ags X64 dispatch table.
    ///
    /// Retrieves the CaptureManager's internal Amd Ags X64 dispatch table. Intended to be
    /// used by the 'wrapper' functions when invoking the 'real' AGS functions.
    ///
    /// \return A AgsDispatchTable object containing AGS function pointers
    ///         retrieved from the system DLL.
    //----------------------------------------------------------------------------
    const AgsDispatchTable& GetAgsDispatchTable() const { return ags_dispatch_table_; }

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

    void EndCreateApiCallCapture(HRESULT result, REFIID riid, void** handle);

    void EndAgsApiCallCapture(HRESULT result, void* object_ptr);

    void EndAgsApiCallCapture(ID3D12GraphicsCommandList_Wrapper* list_wrapper);

    template <typename ParentWrapper>
    void EndCreateMethodCallCapture(HRESULT result, REFIID riid, void** handle, ParentWrapper* create_object_wrapper)
    {
        if (IsCaptureModeTrack() && SUCCEEDED(result))
        {
            if ((handle != nullptr) && (*handle != nullptr))
            {
                assert(state_tracker_ != nullptr);

                auto thread_data = GetThreadData();
                assert(thread_data != nullptr);

                state_tracker_->AddEntry(
                    riid, handle, thread_data->call_id_, create_object_wrapper, thread_data->parameter_buffer_.get());
            }
        }

        EndMethodCallCapture();
    }

    void EndCreateDescriptorMethodCallCapture(D3D12_CPU_DESCRIPTOR_HANDLE dest_descriptor,
                                              ID3D12Device_Wrapper*       create_object_wrapper);

    void EndCommandListMethodCallCapture(ID3D12CommandList_Wrapper* list_wrapper);

    template <typename GetHandlesFunc, typename... GetHandlesArgs>
    void EndCommandListMethodCallCapture(ID3D12CommandList_Wrapper* list_wrapper,
                                         GetHandlesFunc             func,
                                         GetHandlesArgs... args)
    {
        if (IsCaptureModeTrack())
        {
            assert(state_tracker_ != nullptr);

            auto thread_data = GetThreadData();
            assert(thread_data != nullptr);

            state_tracker_->TrackCommand(
                list_wrapper, thread_data->call_id_, thread_data->parameter_buffer_.get(), func, args...);
        }

        EndMethodCallCapture();
    }

    template <typename Wrapper>
    void ProcessWrapperDestroy(Wrapper* wrapper)
    {
        if (RvAnnotationActive() == true)
        {
            resource_value_annotator_->RemoveObjectGPUVA(wrapper);
        }
        if (IsCaptureModeTrack())
        {
            state_tracker_->RemoveEntry(wrapper);
            state_tracker_->TrackRelease(wrapper);
        }
    }

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

    void PreProcess_IDXGISwapChain_Present(IDXGISwapChain_Wrapper* wrapper, UINT sync_interval, UINT flags);

    void PreProcess_IDXGISwapChain1_Present1(IDXGISwapChain_Wrapper*        wrapper,
                                             UINT                           sync_interval,
                                             UINT                           present_flags,
                                             const DXGI_PRESENT_PARAMETERS* present_parameters);

    void PostProcess_IDXGISwapChain_Present(std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
                                            IDXGISwapChain_Wrapper*                                wrapper,
                                            HRESULT                                                result,
                                            UINT                                                   sync_interval,
                                            UINT                                                   flags);

    void PostProcess_IDXGISwapChain1_Present1(std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
                                              IDXGISwapChain_Wrapper*                                wrapper,
                                              HRESULT                                                result,
                                              UINT                                                   sync_interval,
                                              UINT                                                   present_flags,
                                              const DXGI_PRESENT_PARAMETERS* present_parameters);

    void PreProcess_IDXGISwapChain_ResizeBuffers(IDXGISwapChain_Wrapper* wrapper,
                                                 UINT                    buffer_count,
                                                 UINT                    width,
                                                 UINT                    height,
                                                 DXGI_FORMAT             new_format,
                                                 UINT                    flags);

    void PostProcess_IDXGISwapChain_ResizeBuffers(IDXGISwapChain_Wrapper* wrapper,
                                                  HRESULT                 result,
                                                  UINT                    buffer_count,
                                                  UINT                    width,
                                                  UINT                    height,
                                                  DXGI_FORMAT             new_format,
                                                  UINT                    flags);

    void PreProcess_IDXGISwapChain3_ResizeBuffers1(IDXGISwapChain_Wrapper* wrapper,
                                                   UINT                    buffer_count,
                                                   UINT                    width,
                                                   UINT                    height,
                                                   DXGI_FORMAT             new_format,
                                                   UINT                    flags,
                                                   const UINT*             node_mask,
                                                   IUnknown* const*        present_queue);

    void PostProcess_IDXGISwapChain3_ResizeBuffers1(IDXGISwapChain_Wrapper* wrapper,
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

    void PostProcess_ID3D12Device_CreateReservedResource(ID3D12Device_Wrapper*      wrapper,
                                                         HRESULT                    result,
                                                         const D3D12_RESOURCE_DESC* desc,
                                                         D3D12_RESOURCE_STATES      initial_state,
                                                         const D3D12_CLEAR_VALUE*   optimized_clear_value,
                                                         REFIID                     riid,
                                                         void**                     resource);

    void PostProcess_ID3D12Device4_CreateReservedResource1(ID3D12Device4_Wrapper*          wrapper,
                                                           HRESULT                         result,
                                                           const D3D12_RESOURCE_DESC*      desc,
                                                           D3D12_RESOURCE_STATES           initial_state,
                                                           const D3D12_CLEAR_VALUE*        optimized_clear_value,
                                                           ID3D12ProtectedResourceSession* protected_session,
                                                           REFIID                          riid,
                                                           void**                          resource);

    void PostProcess_ID3D12Device10_CreateReservedResource2(ID3D12Device10_Wrapper*         wrapper,
                                                            HRESULT                         result,
                                                            const D3D12_RESOURCE_DESC*      desc,
                                                            D3D12_BARRIER_LAYOUT            initial_layout,
                                                            const D3D12_CLEAR_VALUE*        optimized_clear_value,
                                                            ID3D12ProtectedResourceSession* protected_session,
                                                            UINT32                          num_castable_formats,
                                                            const DXGI_FORMAT*              castable_formats,
                                                            REFIID                          riid,
                                                            void**                          resource);

    void PreProcess_ID3D12Device3_OpenExistingHeapFromAddress(ID3D12Device3_Wrapper* wrapper,
                                                              const void*            address,
                                                              REFIID                 riid,
                                                              void**                 heap);

    void PostProcess_ID3D12Device3_OpenExistingHeapFromAddress(
        ID3D12Device3_Wrapper* wrapper, HRESULT result, const void* address, REFIID riid, void** heap);

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

    void PostProcess_ID3D12Device10_CreateCommittedResource3(ID3D12Device10_Wrapper*         wrapper,
                                                             HRESULT                         result,
                                                             const D3D12_HEAP_PROPERTIES*    heap_properties,
                                                             D3D12_HEAP_FLAGS                heap_flags,
                                                             const D3D12_RESOURCE_DESC1*     desc,
                                                             D3D12_BARRIER_LAYOUT            initial_layout,
                                                             const D3D12_CLEAR_VALUE*        optimized_clear_value,
                                                             ID3D12ProtectedResourceSession* protected_session,
                                                             UINT32                          num_castable_formats,
                                                             const DXGI_FORMAT*              castable_formats,
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

    void PostProcess_ID3D12Device10_CreatePlacedResource2(ID3D12Device10_Wrapper*     wrapper,
                                                          HRESULT                     result,
                                                          ID3D12Heap*                 heap,
                                                          UINT64                      heap_offset,
                                                          const D3D12_RESOURCE_DESC1* desc,
                                                          D3D12_BARRIER_LAYOUT        initial_layout,
                                                          const D3D12_CLEAR_VALUE*    optimized_clear_value,
                                                          UINT32                      num_castable_formats,
                                                          const DXGI_FORMAT*          castable_formats,
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

    void PostProcess_ID3D12Resource_GetGPUVirtualAddress(ID3D12Resource_Wrapper*   wrapper,
                                                         D3D12_GPU_VIRTUAL_ADDRESS result);

    void Destroy_ID3D12Resource(ID3D12Resource_Wrapper* wrapper);

    void PostProcess_ID3D12Heap_GetDesc(ID3D12Heap_Wrapper* wrapper, D3D12_HEAP_DESC& desc);

    void PreProcess_ID3D12CommandQueue_ExecuteCommandLists(
        std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
        ID3D12CommandQueue_Wrapper*                            wrapper,
        UINT                                                   num_lists,
        ID3D12CommandList* const*                              lists);

    void PostProcess_ID3D12CommandQueue_ExecuteCommandLists(
        std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
        ID3D12CommandQueue_Wrapper*                            wrapper,
        UINT                                                   num_lists,
        ID3D12CommandList* const*                              lists);

    void
    OverrideID3D12CommandQueue_ExecuteCommandLists(std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
                                                   ID3D12CommandQueue_Wrapper*                            wrapper,
                                                   UINT                                                   num_lists,
                                                   ID3D12CommandList* const*                              lists);

    void PreProcess_D3D12CreateDevice(IUnknown*         pAdapter,
                                      D3D_FEATURE_LEVEL MinimumFeatureLevel,
                                      REFIID            riid,
                                      void**            ppDevice);

    void PostProcess_D3D12CreateDevice(
        HRESULT result, IUnknown* pAdapter, D3D_FEATURE_LEVEL MinimumFeatureLevel, REFIID riid, void** ppDevice);

    void PostProcess_ID3D12Fence_SetEventOnCompletion(ID3D12Fence_Wrapper* wrapper,
                                                      HRESULT              result,
                                                      UINT64               value,
                                                      HANDLE               event);

    void PostProcess_ID3D12Fence_Signal(ID3D12Fence_Wrapper* wrapper, HRESULT result, UINT64 value);

    void PostProcess_ID3D12CommandQueue_Signal(ID3D12CommandQueue_Wrapper* wrapper,
                                               HRESULT                     result,
                                               ID3D12Fence*                fence,
                                               UINT64                      value);

    void PostProcess_ID3D12GraphicsCommandList_ResourceBarrier(ID3D12CommandList_Wrapper*    list_wrapper,
                                                               UINT                          num_barriers,
                                                               const D3D12_RESOURCE_BARRIER* barriers);

    void PostProcess_ID3D12GraphicsCommandList4_BuildRaytracingAccelerationStructure(
        ID3D12GraphicsCommandList4_Wrapper*                                list_wrapper,
        const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC*          desc,
        UINT                                                               num_postbuild_info_descs,
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* postbuild_info_descs);

    void PostProcess_ID3D12GraphicsCommandList4_CopyRaytracingAccelerationStructure(
        ID3D12GraphicsCommandList4_Wrapper*               list_wrapper,
        D3D12_GPU_VIRTUAL_ADDRESS                         dest_acceleration_structure_data,
        D3D12_GPU_VIRTUAL_ADDRESS                         source_acceleration_structure_data,
        D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE mode);

    void PostProcess_ID3D12Device_CreateCommandList(ID3D12Device_Wrapper*   device_wrapper,
                                                    HRESULT                 result,
                                                    UINT                    nodeMask,
                                                    D3D12_COMMAND_LIST_TYPE type,
                                                    ID3D12CommandAllocator* pCommandAllocator,
                                                    ID3D12PipelineState*    pInitialState,
                                                    REFIID                  riid,
                                                    void**                  ppCommandList);

    void PostProcess_ID3D12Device4_CreateCommandList1(ID3D12Device_Wrapper*    device_wrapper,
                                                      HRESULT                  result,
                                                      UINT                     nodeMask,
                                                      D3D12_COMMAND_LIST_TYPE  type,
                                                      D3D12_COMMAND_LIST_FLAGS flags,
                                                      REFIID                   riid,
                                                      void**                   ppCommandList);

    void PostProcess_ID3D12Device_GetDescriptorHandleIncrementSize(ID3D12Device_Wrapper*      wrapper,
                                                                   UINT                       result,
                                                                   D3D12_DESCRIPTOR_HEAP_TYPE heap_type);

    void PostProcess_ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart(ID3D12DescriptorHeap_Wrapper* wrapper,
                                                                             D3D12_GPU_DESCRIPTOR_HANDLE   result);

    void PostProcess_ID3D12Device_CopyDescriptors(ID3D12Device_Wrapper*              wrapper,
                                                  UINT                               num_dest_ranges,
                                                  const D3D12_CPU_DESCRIPTOR_HANDLE* dest_range_starts,
                                                  const UINT*                        dest_range_sizes,
                                                  UINT                               num_src_ranges,
                                                  const D3D12_CPU_DESCRIPTOR_HANDLE* src_range_starts,
                                                  const UINT*                        src_range_sizes,
                                                  D3D12_DESCRIPTOR_HEAP_TYPE         heap_type);

    void PostProcess_ID3D12Device_CopyDescriptorsSimple(ID3D12Device_Wrapper*       wrapper,
                                                        UINT                        num_descriptors,
                                                        D3D12_CPU_DESCRIPTOR_HANDLE dest_start,
                                                        D3D12_CPU_DESCRIPTOR_HANDLE src_start,
                                                        D3D12_DESCRIPTOR_HEAP_TYPE  heap_type);

    void PostProcess_ID3D12CommandQueue_UpdateTileMappings(
        ID3D12CommandQueue_Wrapper*            queue_wrapper,
        ID3D12Resource*                        resource,
        UINT                                   num_resource_regions,
        const D3D12_TILED_RESOURCE_COORDINATE* resource_region_start_coordinates,
        const D3D12_TILE_REGION_SIZE*          resource_region_sizes,
        ID3D12Heap*                            heap,
        UINT                                   num_ranges,
        const D3D12_TILE_RANGE_FLAGS*          range_flags,
        const UINT*                            heap_range_start_offsets,
        const UINT*                            range_tile_counts,
        D3D12_TILE_MAPPING_FLAGS               flags);

    void
    PostProcess_ID3D12CommandQueue_CopyTileMappings(ID3D12CommandQueue_Wrapper*            queue_wrapper,
                                                    ID3D12Resource*                        dst_resource,
                                                    const D3D12_TILED_RESOURCE_COORDINATE* dst_region_start_coordinate,
                                                    ID3D12Resource*                        src_resource,
                                                    const D3D12_TILED_RESOURCE_COORDINATE* src_region_start_coordinate,
                                                    const D3D12_TILE_REGION_SIZE*          region_size,
                                                    D3D12_TILE_MAPPING_FLAGS               flags);

    void PostProcess_ID3D12Device_CreateShaderResourceView(ID3D12Device_Wrapper*                  device_wrapper,
                                                           ID3D12Resource*                        pResource,
                                                           const D3D12_SHADER_RESOURCE_VIEW_DESC* pDesc,
                                                           D3D12_CPU_DESCRIPTOR_HANDLE            DestDescriptor);

    void PostProcess_ID3D12Device_CreateUnorderedAccessView(ID3D12Device_Wrapper*                   device_wrapper,
                                                            ID3D12Resource*                         pResource,
                                                            ID3D12Resource*                         pCounterResource,
                                                            const D3D12_UNORDERED_ACCESS_VIEW_DESC* pDesc,
                                                            D3D12_CPU_DESCRIPTOR_HANDLE             DestDescriptor);

    void PostProcess_ID3D12Device_CreateRenderTargetView(ID3D12Device_Wrapper*                device_wrapper,
                                                         ID3D12Resource*                      pResource,
                                                         const D3D12_RENDER_TARGET_VIEW_DESC* pDesc,
                                                         D3D12_CPU_DESCRIPTOR_HANDLE          DestDescriptor);

    void PostProcess_ID3D12Device_CreateDepthStencilView(ID3D12Device_Wrapper*                device_wrapper,
                                                         ID3D12Resource*                      pResource,
                                                         const D3D12_DEPTH_STENCIL_VIEW_DESC* pDesc,
                                                         D3D12_CPU_DESCRIPTOR_HANDLE          DestDescriptor);

    void PostProcess_ID3D12Device_CreateConstantBufferView(ID3D12Device_Wrapper*                  device_wrapper,
                                                           const D3D12_CONSTANT_BUFFER_VIEW_DESC* pDesc,
                                                           D3D12_CPU_DESCRIPTOR_HANDLE            DestDescriptor);

    void PostProcess_ID3D12Device8_CreateSamplerFeedbackUnorderedAccessView(ID3D12Device_Wrapper* device_wrapper,
                                                                            ID3D12Resource*       pTargetedResource,
                                                                            ID3D12Resource*       pFeedbackResource,
                                                                            D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

    void PostProcess_ID3D12Debug_EnableDebugLayer(ID3D12Debug_Wrapper* debug_wrapper);

    void PostProcess_ID3D12Debug1_EnableDebugLayer(ID3D12Debug1_Wrapper* debug1_wrapper);

    void PostProcess_ID3D12DeviceRemovedExtendedDataSettings_SetAutoBreadcrumbsEnablement(
        ID3D12DeviceRemovedExtendedDataSettings_Wrapper* dred_wrapper, D3D12_DRED_ENABLEMENT enablement);

    void PostProcess_ID3D12DeviceRemovedExtendedDataSettings1_SetBreadcrumbContextEnablement(
        ID3D12DeviceRemovedExtendedDataSettings1_Wrapper* dred1_wrapper, D3D12_DRED_ENABLEMENT enablement);

    void PostProcess_ID3D12DeviceRemovedExtendedDataSettings_SetPageFaultEnablement(
        ID3D12DeviceRemovedExtendedDataSettings_Wrapper* dred_wrapper, D3D12_DRED_ENABLEMENT enablement);

    void PostProcess_SetPrivateData(
        IUnknown_Wrapper* wrapper, HRESULT result, REFGUID Name, UINT DataSize, const void* pData);

    void PostProcess_ID3D12Device1_SetResidencyPriority(ID3D12Device1_Wrapper*          device_wrapper,
                                                        HRESULT                         result,
                                                        UINT                            NumObjects,
                                                        ID3D12Pageable* const*          ppObjects,
                                                        const D3D12_RESIDENCY_PRIORITY* pPriorities);

    HRESULT OverrideD3D12SerializeVersionedRootSignature(const D3D12_VERSIONED_ROOT_SIGNATURE_DESC* pRootSignature,
                                                         ID3DBlob**                                 ppBlob,
                                                         ID3DBlob**                                 ppErrorBlob);

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

    HRESULT OverrideID3D12Device10_CreateCommittedResource3(ID3D12Device10_Wrapper*         wrapper,
                                                            const D3D12_HEAP_PROPERTIES*    heap_properties,
                                                            D3D12_HEAP_FLAGS                heap_flags,
                                                            const D3D12_RESOURCE_DESC1*     desc,
                                                            D3D12_BARRIER_LAYOUT            initial_layout,
                                                            const D3D12_CLEAR_VALUE*        optimized_clear_value,
                                                            ID3D12ProtectedResourceSession* protected_session,
                                                            UINT32                          num_castable_formats,
                                                            const DXGI_FORMAT*              castable_formats,
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

    HRESULT OverrideID3D12Device_CheckFeatureSupport(ID3D12Device_Wrapper* device_wrapper,
                                                     D3D12_FEATURE         feature,
                                                     void*                 feature_support_data,
                                                     UINT                  feature_support_data_size);

    HRESULT OverrideIDXGIFactory2_CreateSwapChainForHwnd(IDXGIFactory2_Wrapper*                 factory2_wrapper,
                                                         IUnknown*                              pDevice,
                                                         HWND                                   hWnd,
                                                         const DXGI_SWAP_CHAIN_DESC1*           pDesc,
                                                         const DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pFullscreenDesc,
                                                         IDXGIOutput*                           pRestrictToOutput,
                                                         IDXGISwapChain1**                      ppSwapChain);

    HRESULT OverrideIDXGIFactory2_CreateSwapChainForCoreWindow(IDXGIFactory2_Wrapper*       factory2_wrapper,
                                                               IUnknown*                    pDevice,
                                                               IUnknown*                    pWindow,
                                                               const DXGI_SWAP_CHAIN_DESC1* pDesc,
                                                               IDXGIOutput*                 pRestrictToOutput,
                                                               IDXGISwapChain1**            ppSwapChain);

    HRESULT OverrideIDXGIFactory2_CreateSwapChainForComposition(IDXGIFactory2_Wrapper*       factory2_wrapper,
                                                                IUnknown*                    pDevice,
                                                                const DXGI_SWAP_CHAIN_DESC1* pDesc,
                                                                IDXGIOutput*                 pRestrictToOutput,
                                                                IDXGISwapChain1**            ppSwapChain);

    void OverrideGetRaytracingAccelerationStructurePrebuildInfo(
        ID3D12Device5_Wrapper*                                      device5_wrapper,
        const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS* pDesc,
        D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO*      pInfo);

    HRESULT OverrideID3D12GraphicsCommandList_Reset(ID3D12GraphicsCommandList_Wrapper* wrapper,
                                                    ID3D12CommandAllocator*            pAllocator,
                                                    ID3D12PipelineState*               pInitialState);

    void OverrideID3D12GraphicsCommandList_ExecuteBundle(ID3D12GraphicsCommandList_Wrapper* wrapper,
                                                         ID3D12GraphicsCommandList*         pCommandList);

    void OverrideID3D12GraphicsCommandList4_BeginRenderPass(ID3D12GraphicsCommandList4_Wrapper* wrapper,
                                                            UINT                                NumRenderTargets,
                                                            const D3D12_RENDER_PASS_RENDER_TARGET_DESC* pRenderTargets,
                                                            const D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* pDepthStencil,
                                                            D3D12_RENDER_PASS_FLAGS                     Flags);

    virtual CaptureSettings::TraceSettings GetDefaultTraceSettings();

    inline format::HandleId GetEnableDebugLayerObjectId() { return track_enable_debug_layer_object_id_; }

    inline const EnableDREDInfo& GetEnableDREDInfo() { return track_enable_dred_info_; }

    void PostProcess_ID3D12Device5_CreateStateObject(ID3D12Device5_Wrapper*         device5_wrapper,
                                                     HRESULT                        result,
                                                     const D3D12_STATE_OBJECT_DESC* desc,
                                                     REFIID                         riid,
                                                     void**                         state_object);

    void PostProcess_ID3D12Device7_AddToStateObject(ID3D12Device7_Wrapper*         device7_wrapper,
                                                    HRESULT                        result,
                                                    const D3D12_STATE_OBJECT_DESC* addition,
                                                    ID3D12StateObject*             state_object_to_grow_from,
                                                    REFIID                         riid,
                                                    void**                         new_state_object);

    void PostProcess_ID3D12StateObjectProperties_GetShaderIdentifier(
        ID3D12StateObjectProperties_Wrapper* properties_wrapper, void* result, LPCWSTR export_name);

    void WriteDx12DriverInfo();

    void WriteDriverInfoCommand(const std::string& info);

    void WriteDx12RuntimeInfo();

    void WriteDx2RuntimeInfoCommand(const format::Dx12RuntimeInfo& runtime_info);

    void PostProcess_CreateDXGIFactory(HRESULT result, REFIID riid, void** ppFactory);

    void PostProcess_CreateDXGIFactory1(HRESULT result, REFIID riid, void** ppFactory);

    void PostProcess_CreateDXGIFactory2(HRESULT result, UINT Flags, REFIID riid, void** ppFactory);

    void WriteDxgiAdapterInfo();

    bool IsAccelerationStructureResource(format::HandleId id);

    bool AddFillMemoryResourceValueCommand(
        const std::map<uint64_t, Dx12ResourceValueAnnotator::Dx12FillCommandResourceValue>& resource_values);

    void SetAgsVersion(int ags_version) { ags_version_ = ags_version; }

    int GetAgsVersion() { return ags_version_; }

    void TrimDrawCalls_D3D12SerializeVersionedRootSignature(const D3D12_VERSIONED_ROOT_SIGNATURE_DESC* pRootSignature,
                                                            ID3DBlob**                                 ppBlob,
                                                            ID3DBlob**                                 ppErrorBlob);

    void TrimDrawCalls_ID3D12GraphicsCommandList_Reset(HRESULT                            replay_result,
                                                       ID3D12GraphicsCommandList_Wrapper* wrapper,
                                                       ID3D12CommandAllocator*            pAllocator,
                                                       ID3D12PipelineState*               pInitialState);

    void TrimDrawCalls_ID3D12GraphicsCommandList_ExecuteBundle(ID3D12GraphicsCommandList_Wrapper* wrapper,
                                                               ID3D12GraphicsCommandList*         pCommandList);
    void
    TrimDrawCalls_ID3D12GraphicsCommandList4_BeginRenderPass(ID3D12GraphicsCommandList4_Wrapper* wrapper,
                                                             UINT                                NumRenderTargets,
                                                             const D3D12_RENDER_PASS_RENDER_TARGET_DESC* pRenderTargets,
                                                             const D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* pDepthStencil,
                                                             D3D12_RENDER_PASS_FLAGS                     Flags);

    bool TrimDrawCalls_ID3D12CommandQueue_ExecuteCommandLists(
        std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
        ID3D12CommandQueue_Wrapper*                            wrapper,
        UINT                                                   num_lists,
        ID3D12CommandList* const*                              lists);

    bool HasSplitCommandLists(UINT num_lists, ID3D12CommandList* const* lists);

    std::vector<graphics::dx12::CommandSet> GetCommandListsForTrimDrawCalls(ID3D12CommandList_Wrapper* wrapper,
                                                                            format::ApiCallId          api_call_id);

  protected:
    D3D12CaptureManager();

    virtual ~D3D12CaptureManager() {}

    virtual void CreateStateTracker() override { state_tracker_ = std::make_unique<Dx12StateTracker>(); }

    virtual void DestroyStateTracker() override { state_tracker_ = nullptr; }

    virtual void WriteTrackedState(util::FileOutputStream* file_stream,
                                   format::ThreadId        thread_id,
                                   util::FileOutputStream* asset_file_stream = nullptr) override;

    virtual void WriteAssets(util::FileOutputStream* assert_file_stream, format::ThreadId thread_id) override {}

    void PreAcquireSwapChainImages(IDXGISwapChain_Wrapper* wrapper,
                                   IUnknown*               command_queue,
                                   uint32_t                image_count,
                                   DXGI_SWAP_EFFECT        swap_effect);

    void ReleaseSwapChainImages(IDXGISwapChain_Wrapper* wrapper);

    void ResizeSwapChainImages(IDXGISwapChain_Wrapper* wrapper, HRESULT result, UINT buffer_count);

    void InitializeID3D12ResourceInfo(ID3D12Device_Wrapper*    device_wrapper,
                                      ID3D12Resource_Wrapper*  resource_wrapper,
                                      D3D12_RESOURCE_DIMENSION dimension,
                                      D3D12_TEXTURE_LAYOUT     layout,
                                      UINT64                   width,
                                      D3D12_HEAP_TYPE          heap_type,
                                      D3D12_CPU_PAGE_PROPERTY  page_property,
                                      D3D12_MEMORY_POOL        memory_pool,
                                      D3D12_RESOURCE_STATES    initial_state,
                                      bool                     has_write_watch,
                                      ID3D12Heap_Wrapper*      heap_wrapper,
                                      uint64_t                 heap_offset);

    void InitializeSwapChainBufferResourceInfo(IDXGISwapChain_Wrapper* wrapper,
                                               ID3D12Resource_Wrapper* resource_wrapper,
                                               D3D12_RESOURCE_STATES   initial_state);

    void InitializeID3D12DeviceInfo(IUnknown* pAdapter, void** device);

  private:
    void     WriteDxgiAdapterInfoCommand(const format::DxgiAdapterDesc& adapter_desc);
    void     CheckWriteWatchIgnored(D3D12_HEAP_FLAGS flags, format::HandleId id);
    bool     UseWriteWatch(D3D12_HEAP_TYPE type, D3D12_HEAP_FLAGS flags, D3D12_CPU_PAGE_PROPERTY page_property);
    void     EnableWriteWatch(D3D12_HEAP_FLAGS& flags, D3D12_HEAP_PROPERTIES& properties);
    bool     IsUploadResource(D3D12_HEAP_TYPE type, D3D12_CPU_PAGE_PROPERTY page_property);
    uint64_t GetResourceSizeInBytes(ID3D12Device_Wrapper* device_wrapper, const D3D12_RESOURCE_DESC* desc);
    uint64_t GetResourceSizeInBytes(ID3D12Device8_Wrapper* device_wrapper, const D3D12_RESOURCE_DESC1* desc);
    void     UpdateSwapChainSize(uint32_t width, uint32_t height, IDXGISwapChain1* swapchain);
    PFN_D3D12_GET_DEBUG_INTERFACE GetDebugInterfacePtr();
    void                          EnableDebugLayer();
    void                          EnableDRED();
    bool                          RvAnnotationActive();

    void                              PrePresent(IDXGISwapChain_Wrapper* wrapper);
    void                              PostPresent(std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
                                                  IDXGISwapChain_Wrapper*                                wrapper,
                                                  UINT                                                   flags);

    static D3D12CaptureManager*       singleton_;
    std::set<ID3D12Resource_Wrapper*> mapped_resources_; ///< Track mapped resources for unassisted tracking mode.
    DxgiDispatchTable  dxgi_dispatch_table_;  ///< DXGI dispatch table for functions retrieved from the DXGI DLL.
    D3D12DispatchTable d3d12_dispatch_table_; ///< D3D12 dispatch table for functions retrieved from the D3D12 DLL.
    AgsDispatchTable   ags_dispatch_table_;   ///< ags dispatch table for functions retrieved from the AGS DLL.
    int                ags_version_{};        ///< ags version.
    static thread_local uint32_t call_scope_; ///< Per-thread scope count to determine when an intercepted API call is
                                              ///< being made directly by the application.
    bool debug_layer_enabled_;                ///< Track if debug layer has been enabled.
    bool debug_device_lost_enabled_;          ///< Track if DRED has been enabled.
    format::HandleId
        track_enable_debug_layer_object_id_; ///< Track object id since ID3D12Debug could be released very soon.

    EnableDREDInfo track_enable_dred_info_; ///< Track EnableDREDInfo since ID3D12DeviceRemovedExtendedDataSettings1
                                            ///< could be released very soon.

    std::unique_ptr<Dx12StateTracker> state_tracker_;

    std::unique_ptr<graphics::DX12ImageRenderer> frame_buffer_renderer_;

    graphics::dx12::ActiveAdapterMap adapters_;

    std::unique_ptr<Dx12ResourceValueAnnotator> resource_value_annotator_{ nullptr };
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_D3D12_CAPTURE_MANAGER_H
