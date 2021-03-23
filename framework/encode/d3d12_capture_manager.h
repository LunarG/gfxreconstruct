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

    void PostProcess_ID3D12Resource_Map(
        ID3D12Resource_Wrapper* wrapper, HRESULT result, UINT subresource, const D3D12_RANGE* read_range, void** data);

    void PreProcess_ID3D12Resource_Unmap(ID3D12Resource_Wrapper* wrapper,
                                         UINT                    subresource,
                                         const D3D12_RANGE*      written_range);

    void Destroy_ID3D12Resource(ID3D12Resource_Wrapper* wrapper);

    void PreProcess_ID3D12CommandQueue_ExecuteCommandLists(ID3D12CommandQueue_Wrapper* wrapper,
                                                           UINT                        num_lists,
                                                           ID3D12CommandList* const*   lists);

  protected:
    D3D12CaptureManager();

    virtual ~D3D12CaptureManager() override {}

    // TODO (GH #83): Add D3D12 trimming support
    virtual void CreateStateTracker() override {}
    virtual void DestroyStateTracker() override {}
    virtual void WriteTrackedState(format::ThreadId) override {}

    void InitializeID3D12ResourceInfo(ID3D12Device_Wrapper*      device_wrapper,
                                      ID3D12Resource_Wrapper*    resource_wrapper,
                                      const D3D12_RESOURCE_DESC* desc);

  private:
    static D3D12CaptureManager*       instance_;
    std::set<ID3D12Resource_Wrapper*> mapped_resources_; ///< Track mapped resources for unassisted tracking mode.
    DxgiDispatchTable  dxgi_dispatch_table_;  ///< DXGI dispatch table for functions retrieved from the DXGI DLL.
    D3D12DispatchTable d3d12_dispatch_table_; ///< D3D12 dispatch table for functions retrieved from the D3D12 DLL.
    static thread_local uint32_t call_scope_; ///< Per-thread scope count to determine when an intercepted API call is
                                              ///< being made directly by the application.
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_D3D12_CAPTURE_MANAGER_H
