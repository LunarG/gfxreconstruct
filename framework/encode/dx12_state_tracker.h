/*
** Copyright (c) 2021 LunarG, Inc.
** Copyright (c) 2022-2024 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_ENCODE_DX12_STATE_TRACKER_H
#define GFXRECON_ENCODE_DX12_STATE_TRACKER_H

#ifdef GFXRECON_AGS_SUPPORT
#include "encode/custom_ags_state_table.h"
#endif // GFXRECON_AGS_SUPPORT
#include "encode/dx12_state_tracker_initializers.h"
#include "encode/dx12_state_writer.h"
#include "generated/generated_dx12_state_table.h"
#include "generated/generated_dx12_wrapper_creators.h"
#include "generated/generated_dx12_add_entries.h"
#include "util/defines.h"

#include <guiddef.h>
#include <mutex>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class Dx12StateTracker
{
  public:
    Dx12StateTracker();

    ~Dx12StateTracker();

    void WriteState(Dx12StateWriter* writer, uint64_t frame_number);

    template <typename ParentWrapper>
    void AddEntry(REFIID                          riid,
                  typename void**                 new_handle,
                  format::ApiCallId               create_call_id,
                  ParentWrapper*                  create_object_wrapper,
                  const util::MemoryOutputStream* create_parameter_buffer)
    {
        assert(new_handle != nullptr);
        assert(create_parameter_buffer != nullptr);

        auto it = kAddEntryFunctionTable<ParentWrapper>.find(riid);
        if (it != kAddEntryFunctionTable<ParentWrapper>.end())
        {
            it->second(new_handle,
                       create_call_id,
                       create_object_wrapper,
                       create_parameter_buffer,
                       state_table_mutex_,
                       state_table_);
        }
    }

    // Specialize templated AddEntry for API calls (which do not have a calling object).
    void AddEntry(REFIID                          riid,
                  typename void**                 new_handle,
                  format::ApiCallId               create_call_id,
                  void*                           create_object_wrapper,
                  const util::MemoryOutputStream* create_parameter_buffer)
    {
        assert(new_handle != nullptr);
        assert(create_parameter_buffer != nullptr);

        auto it = kAddEntryVoidFunctionTable.find(riid);
        if (it != kAddEntryVoidFunctionTable.end())
        {
            it->second(new_handle,
                       create_call_id,
                       create_object_wrapper,
                       create_parameter_buffer,
                       state_table_mutex_,
                       state_table_);
        }
    }

    template <typename Wrapper>
    void RemoveEntry(typename Wrapper* wrapper)
    {
        if (wrapper != nullptr)
        {
            // Scope the state table mutex lock because DestroyState also modifies the state table and will attempt to
            // lock the mutex.
            {
                std::unique_lock<std::mutex> lock(state_table_mutex_);
                if (!state_table_.RemoveWrapper(wrapper))
                {
                    // TODO: Once tracking is complete and all wrappers are tracked, enable this warning.
                    // Disable it for now in order to prevent redundant log messages.
                    // GFXRECON_LOG_WARNING(
                    //    "Attempting to remove entry from state tracker for object that is not being tracked");
                }
            }

            DestroyState(wrapper);
        }
    }

    void TrackOpenExistingHeapFromAddress(void** heap, const void* address);

    void TrackFenceSetEventOnCompletion(ID3D12Fence_Wrapper* fence, UINT64 value, HANDLE event);

    void TrackFenceSignal(ID3D12Fence_Wrapper* fence, UINT64 value);

    void TrackCommand(ID3D12CommandList_Wrapper*      list_wrapper,
                      format::ApiCallId               call_id,
                      const util::MemoryOutputStream* parameter_buffer);

    template <typename GetHandlesFunc, typename... GetHandlesArgs>
    void TrackCommand(ID3D12CommandList_Wrapper*      list_wrapper,
                      format::ApiCallId               call_id,
                      const util::MemoryOutputStream* parameter_buffer,
                      GetHandlesFunc                  func,
                      GetHandlesArgs... args)
    {
        if (list_wrapper != nullptr)
        {
            TrackCommandExecution(list_wrapper, call_id, parameter_buffer);
            func(list_wrapper, args...);
        }
    }

    void TrackResourceBarriers(ID3D12CommandList_Wrapper*    list_wrapper,
                               UINT                          num_barriers,
                               const D3D12_RESOURCE_BARRIER* barriers);

    void TrackExecuteCommandLists(ID3D12CommandQueue_Wrapper* queue_wrapper,
                                  UINT                        num_lists,
                                  ID3D12CommandList* const*   lists);

    void TrackResourceCreation(ID3D12Resource_Wrapper* resource_wrapper,
                               D3D12_RESOURCE_STATES   initial_state,
                               bool                    swapchain_buffer);

    void TrackResourceGpuVa(ID3D12Resource_Wrapper* resource_wrapper, D3D12_GPU_VIRTUAL_ADDRESS address);

    void TrackCommandListCreation(ID3D12CommandList_Wrapper* list_wrapper,
                                  bool                       created_closed,
                                  D3D12_COMMAND_LIST_TYPE    command_list_type,
                                  ID3D12CommandAllocator*    pCommandAllocator);

    void TrackAcquireImage(UINT image_index, IDXGISwapChain_Wrapper* wrapper);

    void TrackPresentedImages(IDXGISwapChain_Wrapper*        wrapper,
                              UINT                           sync_interval,
                              UINT                           present_flags,
                              const DXGI_PRESENT_PARAMETERS* present_parameters);

    void TrackDescriptorCreation(ID3D12Device_Wrapper*           create_object_wrapper,
                                 format::ApiCallId               call_id,
                                 const util::MemoryOutputStream* parameter_buffer,
                                 DxDescriptorInfo*               descriptor_info);

    void TrackCopyDescriptors(UINT                    num_descriptors,
                              DxDescriptorInfo*       dest_descriptor_infos,
                              const DxDescriptorInfo* src_descriptor_infos);

    void TrackDescriptorResources(SIZE_T          descriptor_cpu_address,
                                  ID3D12Resource* resource1,
                                  ID3D12Resource* resource2 = nullptr);

    void TrackDescriptorGpuVa(SIZE_T descriptor_cpu_address, D3D12_GPU_VIRTUAL_ADDRESS address);

    void TrackUpdateTileMappings(ID3D12Resource_Wrapper*         resource_wrapper,
                                 format::HandleId                queue_id,
                                 format::HandleId                heap_id,
                                 const util::MemoryOutputStream* parameter_buffer);

    void TrackResizeBuffers(IDXGISwapChain_Wrapper*         swapchain_wrapper,
                            format::ApiCallId               call_id,
                            const util::MemoryOutputStream* parameter_buffer);

    void TrackPrivateData(IUnknown_Wrapper* wrapper, REFGUID name, UINT data_size, const void* data);

    void TrackResidencyPriority(ID3D12Device1_Wrapper*          device_wrapper,
                                UINT                            num_objects,
                                ID3D12Pageable* const*          objects,
                                const D3D12_RESIDENCY_PRIORITY* priorities);

    void TrackRelease(IUnknown_Wrapper* wrapper);

    void TrackBuildRaytracingAccelerationStructure(ID3D12GraphicsCommandList4_Wrapper* list_wrapper,
                                                   const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC* desc);

    void TrackCopyRaytracingAccelerationStructure(ID3D12GraphicsCommandList4_Wrapper* list_wrapper,
                                                  D3D12_GPU_VIRTUAL_ADDRESS           dest_acceleration_structure_data,
                                                  D3D12_GPU_VIRTUAL_ADDRESS source_acceleration_structure_data,
                                                  D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE mode);

    void TrackCreateStateObject(ID3D12Device5_Wrapper*         device5_wrapper,
                                const D3D12_STATE_OBJECT_DESC* desc,
                                void**                         state_object_void_ptr);

    void TrackAddToStateObject(ID3D12Device7_Wrapper*         device5_wrapper,
                               const D3D12_STATE_OBJECT_DESC* desc,
                               ID3D12StateObject*             state_object_to_grow_from,
                               void**                         state_object_void_ptr);

    void TrackGetShaderIdentifier(ID3D12StateObjectProperties_Wrapper* state_object_properties_wrapper,
                                  void*                                result,
                                  LPCWSTR                              export_name,
                                  const util::MemoryOutputStream*      parameter_buffer);

    bool IsAccelerationStructureResource(format::HandleId id);

#ifdef GFXRECON_AGS_SUPPORT
    void
    TrackAgsCalls(void* object_ptr, format::ApiCallId call_id, const util::MemoryOutputStream* create_parameter_buffer);
#endif // GFXRECON_AGS_SUPPORT

  private:
    template <typename Wrapper>
    void DestroyState(Wrapper* wrapper)
    {
        assert(wrapper != nullptr);

        // Tracked state is stored in the wrapper's info struct as a shared pointer. It may need to exist after
        // wrapper is no longer being tracked--for example, if another tracked state needs to create a temporary copy of
        // the wrapped object. The tracked state will be freed when all dependent object wrappers are destroyed, so
        // nothing needs to be destroyed here.
    }

    void TrackSubresourceTransitionBarrier(ID3D12ResourceInfo*        resource_info,
                                           const DxTransitionBarrier& transition,
                                           UINT                       subresource);

    void TrackCommandExecution(ID3D12CommandList_Wrapper*      list_wrapper,
                               format::ApiCallId               call_id,
                               const util::MemoryOutputStream* parameter_buffer);

    ID3D12Resource_Wrapper*
    GetResourceWrapperForGpuVa(D3D12_GPU_VIRTUAL_ADDRESS          gpu_va,
                               uint64_t                           minimum_end_address,
                               graphics::ResourceMatchFunctionPtr resource_match_func = nullptr);

    uint64_t CommitAccelerationStructureBuildInfo(DxAccelerationStructureBuildInfo& accel_struct_build);

    uint64_t CommitAccelerationStructureCopyInfo(DxAccelerationStructureCopyInfo&      accel_struct_copy,
                                                 graphics::dx12::ID3D12ResourceComPtr& inputs_data_resource);

    // Track root signatures associated with state object.
    void TrackRootSignatureWithStateObject(const D3D12_STATE_OBJECT_DESC* desc, void** state_object_void_ptr);

#ifdef GFXRECON_AGS_SUPPORT
    void AddAgsInitializeEntry(AGSContext*                     context,
                               format::ApiCallId               call_id,
                               const util::MemoryOutputStream* call_parameter_buffer);

    void TrackAgsDeInitialize(AGSContext* context);

    void AddAgsDriverExtensionsDX12CreateDeviceEntry(ID3D12Device*                   device,
                                                     format::ApiCallId               call_id,
                                                     const util::MemoryOutputStream* call_parameter_buffer);

    void TrackAgsDestroyDevice(ID3D12Device* device);
#endif // GFXRECON_AGS_SUPPORT

    std::mutex           state_table_mutex_;
    Dx12StateTable       state_table_;
    std::atomic_uint64_t accel_struct_id_;

#ifdef GFXRECON_AGS_SUPPORT
    // TODO: to merge the ags table into Dx12 table above. With a change to the code generator.
    std::mutex    ags_state_table_mutex_;
    AgsStateTable ags_state_table_;
#endif // GFXRECON_AGS_SUPPORT
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_DX12_STATE_TRACKER_H
