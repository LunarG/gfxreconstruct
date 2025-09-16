/*
** Copyright (c) 2021 LunarG, Inc.
** Copyright (c) 2022-2025 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_ENCODE_DX12_STATE_WRITER_H
#define GFXRECON_ENCODE_DX12_STATE_WRITER_H

#ifdef GFXRECON_AGS_SUPPORT
#include "encode/custom_ags_state_table.h"
#endif // GFXRECON_AGS_SUPPORT
#include "encode/parameter_encoder.h"
#include "format/format.h"
#include "graphics/dx12_gpu_va_map.h"
#include "graphics/dx12_resource_data_util.h"
#include "util/compressor.h"
#include "util/defines.h"
#include "util/file_output_stream.h"
#include "util/memory_output_stream.h"
#include "generated/generated_dx12_state_table.h"

// TODO: Is the debug code enabled by this define still useful?
#define GFXRECON_DEBUG_WRITTEN_OBJECTS 1

#if GFXRECON_DEBUG_WRITTEN_OBJECTS
#include <unordered_set>
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class Dx12StateWriter
{
  public:
    Dx12StateWriter(util::FileOutputStream* output_stream,
                    util::Compressor*       compressor,
                    format::ThreadId        thread_id,
                    util::FileOutputStream* asset_file_stream = nullptr);

    ~Dx12StateWriter();

#ifdef GFXRECON_AGS_SUPPORT
    void WriteState(const Dx12StateTable& state_table, const AgsStateTable& ags_state_table, uint64_t frame_number);
#else
    void WriteState(const Dx12StateTable& state_table, uint64_t frame_number);
#endif // GFXRECON_AGS_SUPPORT

  private:
    struct ResourceSnapshotInfo
    {
        ID3D12Resource_Wrapper* resource_wrapper{ nullptr };
    };

    // TODO: This is similar to the method in VulkanStateWriter. Possibly refactor to share common code.
    template <typename Wrapper>
    void StandardCreateWrite(const Dx12StateTable& state_table)
    {
        std::set<util::MemoryOutputStream*> processed;
        state_table.VisitWrappers([&](const Wrapper* wrapper) {
            assert(wrapper != nullptr);
            assert(wrapper->GetObjectInfo() != nullptr);
            assert(wrapper->GetObjectInfo()->create_parameters != nullptr);

            // Filter duplicate entries for calls that create multiple objects, where objects created by the same call
            // all reference the same parameter buffer.
            auto wrapper_info = wrapper->GetObjectInfo();
            if (processed.find(wrapper_info->create_parameters.get()) == processed.end())
            {
                StandardCreateWrite(wrapper);
                processed.insert(wrapper_info->create_parameters.get());
            }
        });
    }

    template <typename Wrapper>
    void StandardCreateWrite(const Wrapper& wrapper)
    {
        assert(wrapper != nullptr);
        assert(wrapper->GetObjectInfo() != nullptr);
        assert(wrapper->GetObjectInfo()->create_parameters != nullptr);

        auto wrapper_info = wrapper->GetObjectInfo();
        StandardCreateWrite(wrapper->GetCaptureId(), *wrapper_info.get());
        WriteAddRefAndReleaseCommands(wrapper);
        WritePrivateData(wrapper->GetCaptureId(), *wrapper_info.get());
    }

    void StandardCreateWrite(format::HandleId object_id, const DxWrapperInfo& wrapper_info);

    // TODO: These are similar to the functions used by CaptureManager to write call data. They could be refactored for
    // code reuse.
    void WriteFunctionCall(format::ApiCallId call_id, util::MemoryOutputStream* parameter_buffer);

    void
    WriteMethodCall(format::ApiCallId call_id, format::HandleId object_id, util::MemoryOutputStream* parameter_buffer);

    void WriteHeapState(const Dx12StateTable& state_table);

    // Returns true if memory information was successfully retrieved and written and false otherwise.
    bool WriteCreateHeapAllocationCmd(const void* address);

    void WriteHeapMakeResidentCmd(const ID3D12Heap_Wrapper* wrapper);

    void WriteDescriptorState(const Dx12StateTable& state_table);

    void WriteAddRefAndReleaseCommands(const IUnknown_Wrapper* wrapper);

    void WritePrivateData(format::HandleId handle_id, const DxWrapperInfo& wrapper_info);

    void WriteResidencyPriority(const Dx12StateTable& state_table);

    void WriteAddRefCommand(format::HandleId handle_id, unsigned long result_ref_count);

    void WriteReleaseCommand(format::HandleId handle_id, unsigned long result_ref_count);

    void WriteResourceCreationState(
        const Dx12StateTable&                                                    state_table,
        std::unordered_map<format::HandleId, std::vector<ResourceSnapshotInfo>>& resource_snapshots,
        std::unordered_map<format::HandleId, uint64_t>&                          max_resource_sizes);

    void WriteMetaCommandCreationState(const Dx12StateTable& state_table);

    void WriteTileMappings(const Dx12StateTable& state_table, ID3D12ResourceInfo* resource_info);

    void
    WriteResourceSnapshots(const std::unordered_map<format::HandleId, std::vector<ResourceSnapshotInfo>>& snapshots,
                           const std::unordered_map<format::HandleId, uint64_t>& max_resource_sizes);

    void WriteResourceSnapshot(graphics::Dx12ResourceDataUtil* resource_data_util,
                               const ResourceSnapshotInfo&     snapshot);

    // Sync to ensure all pending command queues are completed before processing state writing.
    void WaitForCommandQueues(const Dx12StateTable& state_table);

    void WriteFenceState(const Dx12StateTable& state_table);

    void WriteCommandListState(const Dx12StateTable& state_table);

    void WriteCommandListCreation(const ID3D12CommandList_Wrapper* list_wrapper, const Dx12StateTable& state_table);

    void WriteCommandListCommands(const ID3D12CommandList_Wrapper* list_wrapper, const Dx12StateTable& state_table);

    void WriteCommandListClose(const ID3D12CommandList_Wrapper* list_wrapper);

    bool CheckCommandListObjects(const ID3D12CommandListInfo* list_info, const Dx12StateTable& state_table);

    bool CheckCommandListObject(D3D12GraphicsCommandObjectType object_type,
                                format::HandleId               handle_id,
                                const Dx12StateTable&          state_table);

    bool CheckGpuVa(D3D12_GPU_VIRTUAL_ADDRESS address);

    bool CheckDescriptorObjects(const DxDescriptorInfo& descriptor_info, const Dx12StateTable& state_table);

    bool CheckResourceObject(const ID3D12ResourceInfo* resource_info, const Dx12StateTable& state_table);

    void WriteSwapChainState(const Dx12StateTable& state_table);

    void WriteEnableDebugLayer();

    void WriteEnableDRED();

    void WriteAccelerationStructuresState(const Dx12StateTable& state_table);

    void WriteAccelerationStructuresState(std::map<uint64_t, const DxAccelerationStructureBuildInfo*> build_infos,
                                          graphics::Dx12ResourceDataUtil* resource_data_util);

    void WriteStateObjectsState(const Dx12StateTable& state_table);

    void WriteStateObjectPropertiesState(const Dx12StateTable& state_table);

    void WriteStateObjectAndDependency(const format::HandleId                state_object_id,
                                       const ID3D12StateObjectInfo*          state_object_info,
                                       std::unordered_set<format::HandleId>& written_objs);

    void WriteSetName(format::HandleId handle_id, const DxWrapperInfo& wrapper_info);

#ifdef GFXRECON_AGS_SUPPORT
    void WriteAgsInitialize(const AgsStateTable& ags_state_table);

    void WriteAgsDriverExtensionsDX12CreateDevice(const AgsStateTable& ags_state_table);
#endif // GFXRECON_AGS_SUPPORT

    util::FileOutputStream*  output_stream_;
    util::Compressor*        compressor_;
    std::vector<uint8_t>     compressed_parameter_buffer_;
    format::ThreadId         thread_id_;
    util::MemoryOutputStream parameter_stream_;
    ParameterEncoder         encoder_;
    graphics::Dx12GpuVaMap   gpu_va_map_;

#if GFXRECON_DEBUG_WRITTEN_OBJECTS
    // Track the list of objects that have been written in WriteState.
    std::unordered_set<format::HandleId> written_objects_;
#endif

    // Temporary vectors.
    std::vector<uint8_t>           temp_subresource_data_;
    std::vector<uint64_t>          temp_subresource_sizes_;
    std::vector<uint64_t>          temp_subresource_offsets_;
    std::vector<DxTileMappingInfo> temp_tile_mappings_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_DX12_STATE_WRITER_H
