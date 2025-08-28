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

#include "encode/dx12_state_writer.h"

#include "generated/generated_dx12_api_call_encoders.h"
#include "encode/custom_dx12_struct_encoders.h"
#include "encode/custom_dx12_struct_unwrappers.h"
#include "encode/struct_pointer_encoder.h"
#include "encode/d3d12_capture_manager.h"
#include "graphics/dx12_resource_data_util.h"
#include "graphics/dx12_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

Dx12StateWriter::Dx12StateWriter(util::FileOutputStream* output_stream,
                                 util::Compressor*       compressor,
                                 format::ThreadId        thread_id,
                                 util::FileOutputStream* asset_file_stream) :
    output_stream_(output_stream), compressor_(compressor), thread_id_(thread_id), encoder_(&parameter_stream_)
{
    assert(output_stream != nullptr);
}

Dx12StateWriter::~Dx12StateWriter() {}

#ifdef GFXRECON_AGS_SUPPORT
void Dx12StateWriter::WriteState(const Dx12StateTable& state_table,
                                 const AgsStateTable&  ags_state_table,
                                 uint64_t              frame_number)
#else
void Dx12StateWriter::WriteState(const Dx12StateTable& state_table, uint64_t frame_number)
#endif // GFXRECON_AGS_SUPPORT
{
#if GFXRECON_DEBUG_WRITTEN_OBJECTS
    written_objects_.clear();
#endif

    format::Marker marker;
    marker.header.size  = sizeof(marker.marker_type) + sizeof(marker.frame_number);
    marker.header.type  = format::kStateMarkerBlock;
    marker.marker_type  = format::kBeginMarker;
    marker.frame_number = frame_number;
    output_stream_->Write(&marker, sizeof(marker));

    // Wait for command queues to complete all pending work.
    WaitForCommandQueues(state_table);

    // Debug objects
    WriteEnableDebugLayer();
    StandardCreateWrite<ID3D12Debug_Wrapper>(state_table);
    StandardCreateWrite<ID3D12Debug1_Wrapper>(state_table);
    WriteEnableDRED();
    StandardCreateWrite<ID3D12DeviceRemovedExtendedDataSettings_Wrapper>(state_table);

    // DXGI objects
    StandardCreateWrite<IDXGIFactory_Wrapper>(state_table);
    StandardCreateWrite<IDXGISurface_Wrapper>(state_table);
    StandardCreateWrite<IDXGIFactoryMedia_Wrapper>(state_table);
    StandardCreateWrite<IDXGIDecodeSwapChain_Wrapper>(state_table);
    StandardCreateWrite<IDXGIAdapter_Wrapper>(state_table);
    StandardCreateWrite<IDXGIDevice_Wrapper>(state_table);
    StandardCreateWrite<IDXGIDisplayControl_Wrapper>(state_table);
    StandardCreateWrite<IDXGIKeyedMutex_Wrapper>(state_table);
    StandardCreateWrite<IDXGIOutput_Wrapper>(state_table);
    StandardCreateWrite<IDXGIOutputDuplication_Wrapper>(state_table);
    StandardCreateWrite<IDXGIResource_Wrapper>(state_table);

#ifdef GFXRECON_AGS_SUPPORT
    // AGS calls
    WriteAgsInitialize(ags_state_table);
    WriteAgsDriverExtensionsDX12CreateDevice(ags_state_table);
#endif // GFXRECON_AGS_SUPPORT

    // Device
    StandardCreateWrite<ID3D12Device_Wrapper>(state_table);

    // Agility SDK constructs
    StandardCreateWrite<ID3D12DeviceFactory_Wrapper>(state_table);
    StandardCreateWrite<ID3D12DeviceConfiguration_Wrapper>(state_table);

    // Write this out before rendering begins
    // This ensures the replayer gets a chance to process the metadata command
    D3D12CaptureManager::Get()->WriteDxgiAdapterInfo();
    D3D12CaptureManager::Get()->WriteDx12DriverInfo();
    D3D12CaptureManager::Get()->WriteDx12RuntimeInfo();

    // Queue
    StandardCreateWrite<ID3D12CommandQueue_Wrapper>(state_table);

    // Swap chain
    WriteSwapChainState(state_table);
    StandardCreateWrite<IDXGISwapChainMedia_Wrapper>(state_table);
    StandardCreateWrite<ID3D12SwapChainAssistant_Wrapper>(state_table);

    // Fences
    WriteFenceState(state_table);

    // Heaps
    WriteRootSignatureBlobState(state_table);
    WriteHeapState(state_table);

    // Root signatures
    StandardCreateWrite<ID3D12RootSignature_Wrapper>(state_table);
    StandardCreateWrite<ID3D12RootSignatureDeserializer_Wrapper>(state_table);
    StandardCreateWrite<ID3D12VersionedRootSignatureDeserializer_Wrapper>(state_table);

    // State objects
    WriteStateObjectsState(state_table);
    WriteStateObjectPropertiesState(state_table);

    // Resources and descriptors
    std::unordered_map<format::HandleId, std::vector<ResourceSnapshotInfo>> resource_snapshots;
    std::unordered_map<format::HandleId, uint64_t>                          max_resource_sizes;
    WriteResourceCreationState(state_table, resource_snapshots, max_resource_sizes);
    WriteDescriptorState(state_table);

    // The resource snapshots must be written after the descriptors in order to support resource value mapping for
    // optimized DXR replay.
    WriteResourceSnapshots(resource_snapshots, max_resource_sizes);

    // Other
    StandardCreateWrite<ID3D12DeviceRemovedExtendedData_Wrapper>(state_table);
    StandardCreateWrite<ID3D12LifetimeOwner_Wrapper>(state_table);
    StandardCreateWrite<ID3D12LifetimeTracker_Wrapper>(state_table);
    WriteMetaCommandCreationState(state_table);
    StandardCreateWrite<ID3D12ProtectedResourceSession_Wrapper>(state_table);
    StandardCreateWrite<ID3D12QueryHeap_Wrapper>(state_table);
    StandardCreateWrite<ID3D12Tools_Wrapper>(state_table);
    StandardCreateWrite<ID3DDestructionNotifier_Wrapper>(state_table);

    // Pipelines
    StandardCreateWrite<ID3D12PipelineLibrary_Wrapper>(state_table);
    StandardCreateWrite<ID3D12PipelineState_Wrapper>(state_table);
    WriteCachedPSOBlobState(state_table);

    // Debug objects
    StandardCreateWrite<ID3D12Debug2_Wrapper>(state_table);
    StandardCreateWrite<ID3D12DebugDevice1_Wrapper>(state_table);
    StandardCreateWrite<ID3D12DebugDevice_Wrapper>(state_table);
    StandardCreateWrite<ID3D12DebugCommandQueue_Wrapper>(state_table);
    StandardCreateWrite<ID3D12DebugCommandList1_Wrapper>(state_table);
    StandardCreateWrite<ID3D12DebugCommandList_Wrapper>(state_table);
    StandardCreateWrite<ID3D12SharingContract_Wrapper>(state_table);
    StandardCreateWrite<ID3D12InfoQueue_Wrapper>(state_table);

    // Acceleration structures
    WriteAccelerationStructuresState(state_table);

    // Command lists
    StandardCreateWrite<ID3D12CommandAllocator_Wrapper>(state_table);
    StandardCreateWrite<ID3D12CommandSignature_Wrapper>(state_table);
    WriteResidencyPriority(state_table);
    WriteCommandListState(state_table);

    // TODO: Determine dependencies for creation of ID3D12VirtualizationGuestDevice
    // Since the dependency chain is unclear, just write their state at the very end
    StandardCreateWrite<ID3D12VirtualizationGuestDevice_Wrapper>(state_table);

    marker.marker_type = format::kEndMarker;
    output_stream_->Write(&marker, sizeof(marker));
}

void Dx12StateWriter::StandardCreateWrite(format::HandleId object_id, const DxWrapperInfo& wrapper_info)
{
#if GFXRECON_DEBUG_WRITTEN_OBJECTS
    // Check that each object is created only once.
    assert(written_objects_.find(object_id) == written_objects_.end());
#endif

    if (wrapper_info.create_object_id == format::kNullHandleId)
    {
        WriteFunctionCall(wrapper_info.create_call_id, wrapper_info.create_parameters.get());
#if GFXRECON_DEBUG_WRITTEN_OBJECTS
        written_objects_.insert(object_id);
#endif
    }
    else
    {
        bool create_temp_object_dependency = ((wrapper_info.create_object_info != nullptr) &&
                                              (wrapper_info.create_object_info->GetWrapper() == nullptr));

        // Write a create call for the parent object if its wrapper has been destroyed.
        if (create_temp_object_dependency)
        {
            StandardCreateWrite(wrapper_info.create_object_id, *wrapper_info.create_object_info.get());
        }

#if GFXRECON_DEBUG_WRITTEN_OBJECTS
        // Check that the parent object has been created.
        assert(written_objects_.find(wrapper_info.create_object_id) != written_objects_.end());
#endif
        WriteMethodCall(
            wrapper_info.create_call_id, wrapper_info.create_object_id, wrapper_info.create_parameters.get());
#if GFXRECON_DEBUG_WRITTEN_OBJECTS
        written_objects_.insert(object_id);
#endif

        if (wrapper_info.object_name.empty() == false)
        {
            WriteSetName(object_id, wrapper_info);
        }

        // Release any temporarily created parent object.
        if (create_temp_object_dependency)
        {
            WriteReleaseCommand(wrapper_info.create_object_id, 0);
        }
    }
}

void Dx12StateWriter::WriteFunctionCall(format::ApiCallId call_id, util::MemoryOutputStream* parameter_buffer)
{
    assert(parameter_buffer != nullptr);

    bool                                 not_compressed      = true;
    format::CompressedFunctionCallHeader compressed_header   = {};
    format::FunctionCallHeader           uncompressed_header = {};
    size_t                               uncompressed_size   = parameter_buffer->GetDataSize();
    size_t                               header_size         = 0;
    const void*                          header_pointer      = nullptr;
    size_t                               data_size           = 0;
    const void*                          data_pointer        = nullptr;

    if (compressor_ != nullptr)
    {
        size_t packet_size = 0;
        size_t compressed_size =
            compressor_->Compress(uncompressed_size, parameter_buffer->GetData(), &compressed_parameter_buffer_, 0);

        if ((0 < compressed_size) && (compressed_size < uncompressed_size))
        {
            data_pointer   = reinterpret_cast<const void*>(compressed_parameter_buffer_.data());
            data_size      = compressed_size;
            header_pointer = reinterpret_cast<const void*>(&compressed_header);
            header_size    = sizeof(format::CompressedFunctionCallHeader);

            compressed_header.block_header.type = format::BlockType::kCompressedFunctionCallBlock;
            compressed_header.api_call_id       = call_id;
            compressed_header.thread_id         = thread_id_;
            compressed_header.uncompressed_size = uncompressed_size;

            packet_size += sizeof(compressed_header.api_call_id) + sizeof(compressed_header.uncompressed_size) +
                           sizeof(compressed_header.thread_id) + compressed_size;

            compressed_header.block_header.size = packet_size;
            not_compressed                      = false;
        }
    }

    if (not_compressed)
    {
        size_t packet_size = 0;
        data_pointer       = reinterpret_cast<const void*>(parameter_buffer->GetData());
        data_size          = uncompressed_size;
        header_pointer     = reinterpret_cast<const void*>(&uncompressed_header);
        header_size        = sizeof(format::FunctionCallHeader);

        uncompressed_header.block_header.type = format::BlockType::kFunctionCallBlock;
        uncompressed_header.api_call_id       = call_id;
        uncompressed_header.thread_id         = thread_id_;

        packet_size += sizeof(uncompressed_header.api_call_id) + sizeof(uncompressed_header.thread_id) + data_size;

        uncompressed_header.block_header.size = packet_size;
    }

    // Write appropriate function call block header.
    output_stream_->Write(header_pointer, header_size);

    // Write parameter data.
    output_stream_->Write(data_pointer, data_size);
}

void Dx12StateWriter::WriteMethodCall(format::ApiCallId         call_id,
                                      format::HandleId          call_object_id,
                                      util::MemoryOutputStream* parameter_buffer)
{
    assert(parameter_buffer != nullptr);

    bool                               not_compressed      = true;
    format::CompressedMethodCallHeader compressed_header   = {};
    format::MethodCallHeader           uncompressed_header = {};
    size_t                             uncompressed_size   = parameter_buffer->GetDataSize();
    size_t                             header_size         = 0;
    const void*                        header_pointer      = nullptr;
    size_t                             data_size           = 0;
    const void*                        data_pointer        = nullptr;

    if (compressor_ != nullptr)
    {
        size_t packet_size = 0;
        size_t compressed_size =
            compressor_->Compress(uncompressed_size, parameter_buffer->GetData(), &compressed_parameter_buffer_, 0);

        if ((compressed_size > 0) && (compressed_size < uncompressed_size))
        {
            data_pointer   = reinterpret_cast<const void*>(compressed_parameter_buffer_.data());
            data_size      = compressed_size;
            header_pointer = reinterpret_cast<const void*>(&compressed_header);
            header_size    = sizeof(format::CompressedMethodCallHeader);

            compressed_header.block_header.type = format::BlockType::kCompressedMethodCallBlock;
            compressed_header.api_call_id       = call_id;
            compressed_header.object_id         = call_object_id;
            compressed_header.thread_id         = thread_id_;
            compressed_header.uncompressed_size = uncompressed_size;

            packet_size += sizeof(compressed_header.api_call_id) + sizeof(compressed_header.object_id) +
                           sizeof(compressed_header.uncompressed_size) + sizeof(compressed_header.thread_id) +
                           compressed_size;

            compressed_header.block_header.size = packet_size;
            not_compressed                      = false;
        }
    }

    if (not_compressed)
    {
        size_t packet_size = 0;
        data_pointer       = reinterpret_cast<const void*>(parameter_buffer->GetData());
        data_size          = uncompressed_size;
        header_pointer     = reinterpret_cast<const void*>(&uncompressed_header);
        header_size        = sizeof(format::MethodCallHeader);

        uncompressed_header.block_header.type = format::BlockType::kMethodCallBlock;
        uncompressed_header.api_call_id       = call_id;
        uncompressed_header.object_id         = call_object_id;
        uncompressed_header.thread_id         = thread_id_;

        packet_size += sizeof(uncompressed_header.api_call_id) + sizeof(compressed_header.object_id) +
                       sizeof(uncompressed_header.thread_id) + data_size;

        uncompressed_header.block_header.size = packet_size;
    }

    // Write appropriate function call block header.
    output_stream_->Write(header_pointer, header_size);

    // Write parameter data.
    output_stream_->Write(data_pointer, data_size);
}

bool Dx12StateWriter::IsCachedPSOBlob(const ID3D10Blob_Wrapper* wrapper) const
{
    GFXRECON_ASSERT(wrapper != nullptr);

    auto wrapper_info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(wrapper_info != nullptr);

    return (wrapper_info->create_call_id == format::ApiCall_ID3D12PipelineState_GetCachedBlob);
}

void Dx12StateWriter::WriteRootSignatureBlobState(const Dx12StateTable& state_table)
{
    std::set<util::MemoryOutputStream*> processed;
    state_table.VisitWrappers([&](const ID3D10Blob_Wrapper* wrapper) {
        GFXRECON_ASSERT(wrapper != nullptr);

        if (IsRootSignatureBlob(wrapper))
        {
            // Filter duplicate entries for calls that create multiple objects, where objects created by the same call
            // all reference the same parameter buffer.
            auto wrapper_info = wrapper->GetObjectInfo();
            GFXRECON_ASSERT((wrapper_info != nullptr) && (wrapper_info->create_parameters != nullptr));

            if (processed.find(wrapper_info->create_parameters.get()) == processed.end())
            {
                StandardCreateWrite(wrapper);
                processed.insert(wrapper_info->create_parameters.get());
            }
        }
    });
}

void Dx12StateWriter::WriteCachedPSOBlobState(const Dx12StateTable& state_table)
{
    std::set<util::MemoryOutputStream*> processed;
    state_table.VisitWrappers([&](const ID3D10Blob_Wrapper* wrapper) {
        if (IsCachedPSOBlob(wrapper))
        {
            StandardCreateWrite(wrapper);
        }
    });
}

void Dx12StateWriter::WriteHeapState(const Dx12StateTable& state_table)
{
    std::set<util::MemoryOutputStream*> processed;
    state_table.VisitWrappers([&](const ID3D12Heap_Wrapper* wrapper) {
        assert(wrapper != nullptr);
        assert(wrapper->GetObjectInfo() != nullptr);
        assert(wrapper->GetObjectInfo()->create_parameters != nullptr);

        auto wrapper_info = wrapper->GetObjectInfo();
        if (wrapper_info->open_existing_address != nullptr)
        {
            if (!WriteCreateHeapAllocationCmd(wrapper_info->open_existing_address))
            {
                GFXRECON_LOG_ERROR("Failed to retrieve memory information for address specified to "
                                   "ID3D12Device3::OpenExistingHeapFromAddress (error = %d)",
                                   GetLastError());
            }
        }

        StandardCreateWrite(wrapper);
        if (wrapper_info->heap_flags & D3D12_HEAP_FLAG_CREATE_NOT_RESIDENT)
        {
            WriteHeapMakeResidentCmd(wrapper);
        }
    });
}

void Dx12StateWriter::WriteHeapMakeResidentCmd(const ID3D12Heap_Wrapper* wrapper)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    GFXRECON_ASSERT(wrapper->GetObjectInfo() != nullptr);

    auto wrapper_info = wrapper->GetObjectInfo();

    UINT                  num_objects  = 1;
    HRESULT               return_value = S_OK;
    const ID3D12Pageable* ppObjects[1];
    ppObjects[0] = reinterpret_cast<const ID3D12Pageable*>(wrapper);

    encoder_.EncodeUInt32Value(num_objects);
    encoder_.EncodeObjectArray(ppObjects, num_objects);
    encoder_.EncodeInt32Value(return_value);
    WriteMethodCall(
        format::ApiCallId::ApiCall_ID3D12Device_MakeResident, wrapper_info->create_object_id, &parameter_stream_);
    parameter_stream_.Clear();
}

bool Dx12StateWriter::WriteCreateHeapAllocationCmd(const void* address)
{
    MEMORY_BASIC_INFORMATION info{};

    auto result = VirtualQuery(address, &info, sizeof(info));
    if (result > 0)
    {
        format::CreateHeapAllocationCommand allocation_cmd;

        allocation_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        allocation_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(allocation_cmd);
        allocation_cmd.meta_header.meta_data_id      = format::MakeMetaDataId(
            format::ApiFamilyId::ApiFamily_D3D12, format::MetaDataType::kCreateHeapAllocationCommand);
        allocation_cmd.thread_id       = thread_id_;
        allocation_cmd.allocation_id   = reinterpret_cast<uint64_t>(address);
        allocation_cmd.allocation_size = info.RegionSize;

        output_stream_->Write(&allocation_cmd, sizeof(allocation_cmd));

        return true;
    }

    return false;
}

void Dx12StateWriter::WriteDescriptorState(const Dx12StateTable& state_table)
{
    std::set<util::MemoryOutputStream*> processed;
    state_table.VisitWrappers([&](ID3D12DescriptorHeap_Wrapper* heap_wrapper) {
        assert(heap_wrapper != nullptr);
        assert(heap_wrapper->GetWrappedObject() != nullptr);
        assert(heap_wrapper->GetObjectInfo() != nullptr);
        assert(heap_wrapper->GetObjectInfo()->create_parameters != nullptr);

        auto        heap      = heap_wrapper->GetWrappedObjectAs<ID3D12DescriptorHeap>();
        auto        heap_info = heap_wrapper->GetObjectInfo();
        const auto& heap_desc = heap->GetDesc();

        // Write heap creation call.
        StandardCreateWrite(heap_wrapper);

        // Write GetCPUDescriptorHandleForHeapStart call.
        if (heap_info->cpu_start != 0)
        {
            D3D12_CPU_DESCRIPTOR_HANDLE cpu_start;
            cpu_start.ptr = heap_info->cpu_start;
            EncodeStruct(&encoder_, cpu_start);
            WriteMethodCall(format::ApiCallId::ApiCall_ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart,
                            heap_wrapper->GetCaptureId(),
                            &parameter_stream_);
            parameter_stream_.Clear();
        }

        // Write GetGPUDescriptorHandleForHeapStart call.
        if (heap_info->gpu_start != 0)
        {
            D3D12_GPU_DESCRIPTOR_HANDLE gpu_start;
            gpu_start.ptr = heap_info->gpu_start;
            EncodeStruct(&encoder_, gpu_start);
            WriteMethodCall(format::ApiCallId::ApiCall_ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart,
                            heap_wrapper->GetCaptureId(),
                            &parameter_stream_);
            parameter_stream_.Clear();
        }

        // Write call to query the device for heap increment size.
        encoder_.EncodeEnumValue(heap_desc.Type);
        encoder_.EncodeUInt32Value(heap_info->descriptor_increment);
        WriteMethodCall(format::ApiCallId::ApiCall_ID3D12Device_GetDescriptorHandleIncrementSize,
                        heap_info->create_object_id,
                        &parameter_stream_);
        parameter_stream_.Clear();

        // Write descriptor creation calls, not use StandardCreateWrite.
        for (uint32_t i = 0; i < heap_desc.NumDescriptors; ++i)
        {
            const DxDescriptorInfo& descriptor_info = heap_info->descriptor_info[i];

            GFXRECON_ASSERT(descriptor_info.heap_id == heap_wrapper->GetCaptureId());
            GFXRECON_ASSERT(descriptor_info.index == i);

            if ((CheckDescriptorObjects(descriptor_info, state_table)) &&
                (descriptor_info.create_parameters != nullptr) &&
                (descriptor_info.create_parameters->GetDataSize() != 0))
            {
                if (descriptor_info.is_copy)
                {
                    // Append heap id and descriptor index if the create parameters were copied from another descriptor
                    // in CopyDescriptors.
                    auto dest_heap_id = descriptor_info.heap_id;
                    auto dest_index   = descriptor_info.index;
                    parameter_stream_.Write(descriptor_info.create_parameters->GetData(),
                                            descriptor_info.create_parameters->GetDataSize());
                    parameter_stream_.Write(&dest_heap_id, sizeof(dest_heap_id));
                    parameter_stream_.Write(&dest_index, sizeof(dest_index));
                    WriteMethodCall(
                        descriptor_info.create_call_id, descriptor_info.create_object_id, &parameter_stream_);
                    parameter_stream_.Clear();
                }
                else
                {
                    WriteMethodCall(descriptor_info.create_call_id,
                                    descriptor_info.create_object_id,
                                    descriptor_info.create_parameters.get());
                }
            }
        }
    });
}

void Dx12StateWriter::WriteAddRefAndReleaseCommands(const IUnknown_Wrapper* wrapper)
{
    // Add AddRef/Release commands as needed to set object ref count for replay.
    for (unsigned long i = 1; i < wrapper->GetRefCount(); ++i)
    {
        WriteAddRefCommand(wrapper->GetCaptureId(), i + 1);
    }
    for (unsigned long i = 1; i > wrapper->GetRefCount(); --i)
    {
        WriteReleaseCommand(wrapper->GetCaptureId(), i - 1);
    }
}

void Dx12StateWriter::WritePrivateData(format::HandleId handle_id, const DxWrapperInfo& wrapper_info)
{
    for (auto& data : wrapper_info.private_datas)
    {
        uint32_t data_size = static_cast<uint32_t>(data.second.size());
        EncodeStruct(&encoder_, data.first);
        encoder_.EncodeUInt32Value(data_size);
        encoder_.EncodeVoidArray(data.second.data(), data_size);
        encoder_.EncodeInt32Value(S_OK);
        if (wrapper_info.IsDxgi())
        {
            WriteMethodCall(format::ApiCallId::ApiCall_IDXGIObject_SetPrivateData, handle_id, &parameter_stream_);
        }
        else
        {
            WriteMethodCall(format::ApiCallId::ApiCall_ID3D12Object_SetPrivateData, handle_id, &parameter_stream_);
        }
        parameter_stream_.Clear();
    }
}

void Dx12StateWriter::WriteAddRefCommand(format::HandleId handle_id, unsigned long result_ref_count)
{
    encoder_.EncodeUInt32Value(result_ref_count);
    WriteMethodCall(format::ApiCallId::ApiCall_IUnknown_AddRef, handle_id, &parameter_stream_);
    parameter_stream_.Clear();
}

void Dx12StateWriter::WriteReleaseCommand(format::HandleId handle_id, unsigned long result_ref_count)
{
    encoder_.EncodeUInt32Value(result_ref_count);
    WriteMethodCall(format::ApiCallId::ApiCall_IUnknown_Release, handle_id, &parameter_stream_);
    parameter_stream_.Clear();

#if GFXRECON_DEBUG_WRITTEN_OBJECTS
    if (result_ref_count == 0)
    {
        // If this object is needed again, it will need to be re-created in the capture file.
        written_objects_.erase(handle_id);
    }
#endif
}

void Dx12StateWriter::WriteResourceCreationState(
    const Dx12StateTable&                                                    state_table,
    std::unordered_map<format::HandleId, std::vector<ResourceSnapshotInfo>>& resource_snapshots,
    std::unordered_map<format::HandleId, uint64_t>&                          max_resource_sizes)
{
    HRESULT result = E_FAIL;

    struct MappedSubresourceInfo
    {
        ID3D12Resource_Wrapper* resource_wrapper;
        UINT                    subresource;
        int32_t                 map_count;
    };
    std::vector<MappedSubresourceInfo> mapped_subresources;

    resource_snapshots.clear();
    max_resource_sizes.clear();

    state_table.VisitWrappers([&](ID3D12Resource_Wrapper* resource_wrapper) {
        assert(resource_wrapper != nullptr);
        assert(resource_wrapper->GetWrappedObject() != nullptr);
        assert(resource_wrapper->GetObjectInfo() != nullptr);
        assert(resource_wrapper->GetObjectInfo()->create_parameters != nullptr);
        assert(resource_wrapper->GetObjectInfo()->create_object_id != format::kNullHandleId);

        auto        resource      = resource_wrapper->GetWrappedObjectAs<ID3D12Resource>();
        auto        resource_info = resource_wrapper->GetObjectInfo();
        const auto& resource_desc = resource->GetDesc();

        if (!CheckResourceObject(resource_info.get(), state_table))
        {
            // Skipping invalid resource data capture.
            GFXRECON_LOG_WARNING_ONCE("Encountered invalid resource during state write");
            return;
        }

        // Write the resource creation call to capture file.
        StandardCreateWrite(resource_wrapper);

        // Write call to get GPU address for buffers.
        if (resource_desc.Dimension == D3D12_RESOURCE_DIMENSION_BUFFER)
        {
            D3D12_GPU_VIRTUAL_ADDRESS gpu_address = resource->GetGPUVirtualAddress();
            encoder_.EncodeUInt64Value(gpu_address);
            WriteMethodCall(format::ApiCallId::ApiCall_ID3D12Resource_GetGPUVirtualAddress,
                            resource_wrapper->GetCaptureId(),
                            &parameter_stream_);
            parameter_stream_.Clear();

            // Track the GPU VAs for buffers written to the trim state block. This map is used to determine if a given
            // GPU VA references a buffer that was written to the trim state block. Addresses do not need to be mapped,
            // so the "new_start_address" parameter won't be used.
            gpu_va_map_.Add(resource_wrapper->GetCaptureId(), gpu_address, resource_desc.Width, gpu_address);
        }

        // Get resource sizes and list of currently mapped subresources.
        uint64_t resource_size = 0;
        for (UINT i = 0; i < resource_info->num_subresources; ++i)
        {
            resource_size += resource_info->subresource_sizes[i];
            if (resource_info->mapped_subresources[i].map_count > 0)
            {
                mapped_subresources.push_back({ resource_wrapper, i, resource_info->mapped_subresources[i].map_count });
            }
        }

        // Write tile mappings, if any (for reserved resources).
        WriteTileMappings(state_table, resource_info.get());

        if (resource_desc.SampleDesc.Count > 1)
        {
            // TODO: Add support for multi-sampled resources.
            GFXRECON_LOG_WARNING_ONCE("Skipping resource data capture for multi-sampled resource(s).");
        }
        else if ((resource_info->initial_state & D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE) ==
                 D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE)
        {
            // Skip the capture of any ray tracing resource's data. Acceleration structures will be rebuilt from inputs
            // during replay. See WriteAccelerationStructuresState.
            GFXRECON_LOG_DEBUG_ONCE(
                "Skipping resource data capture for ray tracing acceleration structure resource(s).");
        }
        // Writting swapchain buffer could cause extra Present during replay. It might cause different frame count.
        // So only write swapchain buffer in TrimBoundary::kDrawCalls case.
        // TrimBoundary::kDrawCalls needs initial render targets,
        else if (!resource_info->is_swapchain_buffer ||
                 D3D12CaptureManager::Get()->GetTrimBoundary() == CaptureSettings::TrimBoundary::kDrawCalls)
        {
            // Store resource wrappers and max resource sizes.
            ResourceSnapshotInfo snapshot_info;
            snapshot_info.resource_wrapper = resource_wrapper;
            format::HandleId device_id     = format::kNullHandleId;
            if (resource_info->device_wrapper != nullptr)
            {
                device_id = resource_info->device_wrapper->GetCaptureId();
            }
            resource_snapshots[device_id].push_back(snapshot_info);
            max_resource_sizes[device_id] = std::max(resource_size, max_resource_sizes[device_id]);
        }
    });

    // Write calls to map the resource as many times as it is currently mapped by the application.
    for (const auto& map_info : mapped_subresources)
    {
        auto     mappable_resource = map_info.resource_wrapper->GetWrappedObjectAs<ID3D12Resource>();
        uint8_t* result_ptr        = nullptr;
        auto     resource_info     = map_info.resource_wrapper->GetObjectInfo();
        bool     unknown_layout_mapping =
            graphics::dx12::IsTextureWithUnknownLayout(resource_info->dimension, resource_info->layout);

        graphics::dx12::MapSubresource(
            mappable_resource, map_info.subresource, &graphics::dx12::kZeroRange, result_ptr, unknown_layout_mapping);

        for (int32_t i = 0; i < map_info.map_count; ++i)
        {
            encoder_.EncodeUInt32Value(map_info.subresource);
            EncodeStructPtr<D3D12_RANGE>(&encoder_, nullptr);
            if (!unknown_layout_mapping)
            {
                encoder_.EncodeVoidPtrPtr<void>(reinterpret_cast<void**>(&result_ptr));
            }
            else
            {
                // Quote: "A null pointer is valid and is useful to cache a CPU virtual address range for methods like
                // WriteToSubresource."
                //
                // Source: https://docs.microsoft.com/en-us/windows/win32/api/d3d12/nf-d3d12-id3d12resource-map
                //
                // The resource is a texture with unknown layout, here we gererate special map call in trim trace file
                // so the following WriteToSubresource call can be used to restore its content in trim loading states.

                encoder_.EncodeVoidPtrPtr<void>(nullptr);
            }

            encoder_.EncodeInt32Value(S_OK);
            WriteMethodCall(format::ApiCallId::ApiCall_ID3D12Resource_Map,
                            map_info.resource_wrapper->GetCaptureId(),
                            &parameter_stream_);
        }

        mappable_resource->Unmap(map_info.subresource, &graphics::dx12::kZeroRange);

        parameter_stream_.Clear();
    }
}

void Dx12StateWriter::WriteMetaCommandCreationState(const Dx12StateTable& state_table)
{
    std::set<util::MemoryOutputStream*>     processed;
    std::vector<ID3D12MetaCommand_Wrapper*> metacommand_wrappers;
    state_table.VisitWrappers([&](ID3D12MetaCommand_Wrapper* wrapper) {
        assert(wrapper != nullptr);
        assert(wrapper->GetObjectInfo() != nullptr);
        assert(wrapper->GetObjectInfo()->create_parameters != nullptr);

        // Filter duplicate entries for calls that create multiple objects, where objects created by the same call
        // all reference the same parameter buffer.
        auto wrapper_info = wrapper->GetObjectInfo();
        if (processed.find(wrapper_info->create_parameters.get()) == processed.end())
        {
            StandardCreateWrite(wrapper);
            metacommand_wrappers.push_back(wrapper);
            processed.insert(wrapper_info->create_parameters.get());
        }
    });

    if (metacommand_wrappers.size() > 0)
    {
        uint32_t block_index = 0;
        for (auto wrapper : metacommand_wrappers)
        {
            // Write the meta command init call.
            auto                          wrapper_info = wrapper->GetObjectInfo();
            if (wrapper_info->was_initialized == true)
            {
                format::InitializeMetaCommand init_meta_command;
                init_meta_command.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(init_meta_command) +
                                                                  wrapper_info->initialize_parameters->GetDataSize();
                init_meta_command.meta_header.block_header.type = format::kMetaDataBlock;
                init_meta_command.meta_header.meta_data_id      = format::MakeMetaDataId(
                    format::ApiFamilyId::ApiFamily_D3D12, format::MetaDataType::kInitializeMetaCommand);
                init_meta_command.thread_id  = thread_id_;
                init_meta_command.capture_id = wrapper->GetCaptureId();
                init_meta_command.initialization_parameters_data_size =
                    wrapper_info->initialize_parameters->GetDataSize();
                init_meta_command.total_number_of_initializemetacommand = metacommand_wrappers.size();
                init_meta_command.block_index                           = ++block_index;

                output_stream_->Write(&init_meta_command, sizeof(init_meta_command));
                output_stream_->Write(wrapper_info->initialize_parameters->GetData(),
                                      wrapper_info->initialize_parameters->GetDataSize());
            }
        }
    }
}

void Dx12StateWriter::WriteResourceSnapshots(
    const std::unordered_map<format::HandleId, std::vector<ResourceSnapshotInfo>>& snapshots,
    const std::unordered_map<format::HandleId, uint64_t>&                          max_resource_sizes)
{
    for (auto kvp : snapshots)
    {
        auto device_id = kvp.first;
        auto snapshots = kvp.second;

        // Error if encountering a resource with null device id.
        if (device_id == format::kNullHandleId)
        {
            for (auto snapshot : kvp.second)
            {
                GFXRECON_LOG_ERROR("Resource (id = %" PRIu64
                                   ") has a null device id. Its contents will not be captured or replayed.",
                                   snapshot.resource_wrapper->GetCaptureId());
            }
            continue;
        }

        if (snapshots.size() > 0)
        {
            std::unique_ptr<graphics::Dx12ResourceDataUtil> resource_data_util;

            auto max_resource_size = max_resource_sizes.at(device_id);

            // Write the block indicating resource processing start.
            format::BeginResourceInitCommand begin_cmd;
            begin_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(begin_cmd);
            begin_cmd.meta_header.block_header.type = format::kMetaDataBlock;
            begin_cmd.meta_header.meta_data_id      = format::MakeMetaDataId(
                format::ApiFamilyId::ApiFamily_D3D12, format::MetaDataType::kBeginResourceInitCommand);
            begin_cmd.thread_id         = thread_id_;
            begin_cmd.device_id         = device_id;
            begin_cmd.max_resource_size = max_resource_size;
            begin_cmd.max_copy_size     = max_resource_size;

            output_stream_->Write(&begin_cmd, sizeof(begin_cmd));

            // Write each resource snapshot to the capture file.
            for (auto snapshot : kvp.second)
            {
                // Iterate to be dumped resources
                auto resource_wrapper = snapshot.resource_wrapper;
                auto resource_info    = resource_wrapper->GetObjectInfo();

                if (resource_data_util == nullptr)
                {
                    ID3D12Device_Wrapper* device_wrapper = resource_info->device_wrapper;
                    GFXRECON_ASSERT(device_wrapper != nullptr);
                    ID3D12Device* device = device_wrapper->GetWrappedObjectAs<ID3D12Device>();
                    if (device != nullptr)
                    {
                        resource_data_util =
                            std::make_unique<graphics::Dx12ResourceDataUtil>(device, max_resource_size);
                    }
                    else
                    {
                        // Log error and skip to next resource.
                        GFXRECON_LOG_ERROR("Failed to initialize resource data util for writing resource (id = %" PRIu64
                                           "). Could not query for device.",
                                           resource_wrapper->GetCaptureId());
                        continue;
                    }
                }

                WriteResourceSnapshot(resource_data_util.get(), snapshot);
            }

            // Write the block indicating resource processing end.
            format::EndResourceInitCommand end_cmd;
            end_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(end_cmd);
            end_cmd.meta_header.block_header.type = format::kMetaDataBlock;
            end_cmd.meta_header.meta_data_id      = format::MakeMetaDataId(format::ApiFamilyId::ApiFamily_D3D12,
                                                                      format::MetaDataType::kEndResourceInitCommand);
            end_cmd.thread_id                     = thread_id_;
            end_cmd.device_id                     = device_id;

            output_stream_->Write(&end_cmd, sizeof(end_cmd));
        }
    }
}

void Dx12StateWriter::WriteResourceSnapshot(graphics::Dx12ResourceDataUtil* resource_data_util,
                                            const ResourceSnapshotInfo&     snapshot)
{
    auto resource_wrapper = snapshot.resource_wrapper;
    auto resource_info    = resource_wrapper->GetObjectInfo();
    auto resource         = resource_wrapper->GetWrappedObjectAs<ID3D12Resource>();

    uint64_t subresource_count      = 0;
    uint64_t total_subresource_size = 0;
    temp_subresource_data_.clear();
    temp_subresource_sizes_.clear();
    temp_subresource_offsets_.clear();

    bool is_reserved_resouce =
        (resource_info->create_call_id == format::ApiCall_ID3D12Device_CreateReservedResource) ||
        (resource_info->create_call_id == format::ApiCall_ID3D12Device4_CreateReservedResource1) ||
        (resource_info->create_call_id == format::ApiCall_ID3D12Device10_CreateReservedResource2);
    bool is_texture_with_unknown_layout =
        graphics::dx12::IsTextureWithUnknownLayout(resource_info->dimension, resource_info->layout);

    bool try_map_and_copy = !is_reserved_resouce && !is_texture_with_unknown_layout;

    graphics::dx12::ID3D12CommandQueueComPtr queue = nullptr;
    if (resource_info->swapchain_wrapper)
    {
        // Needs swapchain's queue to write its buffer.
        auto swapchain_info = resource_info->swapchain_wrapper->GetObjectInfo();
        queue               = swapchain_info->command_queue;
    }
    // Read the data from the resource.
    HRESULT result = resource_data_util->ReadFromResource(resource,
                                                          try_map_and_copy,
                                                          resource_info->subresource_transitions,
                                                          resource_info->subresource_transitions,
                                                          temp_subresource_data_,
                                                          temp_subresource_offsets_,
                                                          temp_subresource_sizes_,
                                                          nullptr,
                                                          queue);

    if (SUCCEEDED(result))
    {
        // Write the subresource data to the output.
        for (uint32_t i = 0; i < temp_subresource_sizes_.size(); ++i)
        {
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, temp_subresource_sizes_[i]);

            uint8_t* subresource_data = temp_subresource_data_.data() + temp_subresource_offsets_[i];
            size_t   subresource_size = static_cast<size_t>(temp_subresource_sizes_[i]);

            // Create subresource upload data block.
            format::InitSubresourceCommandHeader upload_cmd;
            upload_cmd.meta_header.block_header.type = format::kMetaDataBlock;
            upload_cmd.meta_header.meta_data_id      = format::MakeMetaDataId(format::ApiFamilyId::ApiFamily_D3D12,
                                                                         format::MetaDataType::kInitSubresourceCommand);
            upload_cmd.thread_id                     = thread_id_;
            format::HandleId device_id               = format::kNullHandleId;
            if (resource_info->device_wrapper != nullptr)
            {
                device_id = resource_info->device_wrapper->GetCaptureId();
            }
            upload_cmd.device_id      = device_id;
            upload_cmd.resource_id    = resource_wrapper->GetCaptureId();
            upload_cmd.subresource    = i;
            upload_cmd.initial_state  = resource_info->initial_state;
            upload_cmd.resource_state = resource_info->subresource_transitions[i].states;
            upload_cmd.barrier_flags  = resource_info->subresource_transitions[i].barrier_flags;
            upload_cmd.data_size      = subresource_size;

            // Compress block data.
            if (compressor_ != nullptr)
            {
                size_t compressed_size =
                    compressor_->Compress(subresource_size, subresource_data, &compressed_parameter_buffer_, 0);

                if ((compressed_size > 0) && (compressed_size < subresource_size))
                {
                    upload_cmd.meta_header.block_header.type = format::BlockType::kCompressedMetaDataBlock;

                    subresource_data = compressed_parameter_buffer_.data();
                    subresource_size = compressed_size;
                }
            }

            // Calculate size of packet with compressed or uncompressed data size.
            upload_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(upload_cmd) + subresource_size;

            // Write upload block to file.
            output_stream_->Write(&upload_cmd, sizeof(upload_cmd));
            output_stream_->Write(subresource_data, subresource_size);
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to read data for resource (id = %" PRIu64
                           "). Resource data will not be written to capture file.",
                           resource_wrapper->GetCaptureId());
    }
}

void Dx12StateWriter::WriteTileMappings(const Dx12StateTable& state_table, ID3D12ResourceInfo* resource_info)
{
    if (resource_info->tile_mappings.empty())
    {
        return;
    }

    temp_tile_mappings_.clear();
    for (auto& tile_mapping : resource_info->tile_mappings)
    {
        bool queue_valid = (state_table.GetID3D12CommandQueue_Wrapper(tile_mapping.queue_id) != nullptr);
        bool heap_valid  = (tile_mapping.heap_id == format::kNullHandleId) ||
                          (state_table.GetID3D12Heap_Wrapper(tile_mapping.heap_id) != nullptr);
        if (queue_valid && heap_valid)
        {
            WriteMethodCall(format::ApiCall_ID3D12CommandQueue_UpdateTileMappings,
                            tile_mapping.queue_id,
                            tile_mapping.call_parameters.get());
            temp_tile_mappings_.push_back(std::move(tile_mapping));
        }
    }

    // No longer need to track tile mappings that were invalid.
    std::swap(resource_info->tile_mappings, temp_tile_mappings_);
}

void Dx12StateWriter::WaitForCommandQueues(const Dx12StateTable& state_table)
{
    const UINT64 kSignalValue = 1;

    state_table.VisitWrappers([&](ID3D12CommandQueue_Wrapper* queue_wrapper) {
        assert(queue_wrapper != nullptr);
        assert(queue_wrapper->GetWrappedObject() != nullptr);

        auto queue  = queue_wrapper->GetWrappedObjectAs<ID3D12CommandQueue>();
        auto result = graphics::dx12::WaitForQueue(queue);
        if (!SUCCEEDED(result))
        {
            GFXRECON_LOG_ERROR("Failed to wait for ID3D12CommandQueue (id = %" PRIu64
                               ") to complete pending work for trim state writing. (error = %x)",
                               queue_wrapper->GetCaptureId(),
                               result);
        }
    });
}

void Dx12StateWriter::WriteFenceState(const Dx12StateTable& state_table)
{
    state_table.VisitWrappers([&](ID3D12Fence_Wrapper* fence_wrapper) {
        assert(fence_wrapper != nullptr);
        assert(fence_wrapper->GetWrappedObject() != nullptr);
        assert(fence_wrapper->GetObjectInfo() != nullptr);

        auto fence      = fence_wrapper->GetWrappedObjectAs<ID3D12Fence>();
        auto fence_info = fence_wrapper->GetObjectInfo();

        assert(fence_info->create_parameters != nullptr);
        assert(fence_info->create_object_id != format::kNullHandleId);

        // Write call to create the fence.
        StandardCreateWrite(fence_wrapper);

        UINT64 completed_fence_value = fence->GetCompletedValue();

        // Write SetEventOnCompletion commands for remaining pending events.
        // The pending_events_mutex doesn't need to be locked here because all other threads are blocked while state is
        // being written.
        auto& pending_events = fence_info->pending_events;
        for (auto events : pending_events)
        {
            UINT64 value = events.first;

            // Ignore any events that have already been signaled.
            if (value <= completed_fence_value)
            {
                continue;
            }

            for (auto event : events.second)
            {
                encoder_.EncodeUInt64Value(value);
                encoder_.EncodeVoidPtr(event);
                encoder_.EncodeInt32Value(S_OK);
                WriteMethodCall(format::ApiCallId::ApiCall_ID3D12Fence_SetEventOnCompletion,
                                fence_wrapper->GetCaptureId(),
                                &parameter_stream_);
                parameter_stream_.Clear();
            }
        }

        // Write call to signal the fence to its most recent value.
        encoder_.EncodeUInt64Value(completed_fence_value);
        encoder_.EncodeInt32Value(S_OK);
        WriteMethodCall(
            format::ApiCallId::ApiCall_ID3D12Fence_Signal, fence_wrapper->GetCaptureId(), &parameter_stream_);
        parameter_stream_.Clear();
    });
}

void Dx12StateWriter::WriteResidencyPriority(const Dx12StateTable& state_table)
{
    state_table.VisitWrappers([&](ID3D12Device_Wrapper* device_wrapper) {
        GFXRECON_ASSERT(device_wrapper != nullptr);
        GFXRECON_ASSERT(device_wrapper->GetObjectInfo() != nullptr);

        auto     device_info = device_wrapper->GetObjectInfo();
        uint32_t num_objects = static_cast<uint32_t>(device_info->residency_priorities.size());

        if (num_objects > 0)
        {
            auto handle_id = device_wrapper->GetCaptureId();

            std::vector<format::HandleId>         handles;
            std::vector<D3D12_RESIDENCY_PRIORITY> priorities;

            for (auto& entry : device_info->residency_priorities)
            {
                handles.emplace_back(entry.first);
                priorities.emplace_back(entry.second);
            }

            encoder_.EncodeUInt32Value(num_objects);
            encoder_.EncodeHandleIdArray(handles.data(), num_objects);
            encoder_.EncodeEnumArray(priorities.data(), num_objects);
            encoder_.EncodeInt32Value(S_OK);
            WriteMethodCall(
                format::ApiCallId::ApiCall_ID3D12Device1_SetResidencyPriority, handle_id, &parameter_stream_);
            parameter_stream_.Clear();
        }
    });
}

void Dx12StateWriter::WriteCommandListState(const Dx12StateTable& state_table)
{
    std::vector<ID3D12CommandList_Wrapper*> direct_command_lists;
    std::vector<ID3D12CommandList_Wrapper*> open_command_lists;

    const bool trim_to_draw_enabled =
        (D3D12CaptureManager::Get()->GetTrimBoundary() == CaptureSettings::TrimBoundary::kDrawCalls);

    state_table.VisitWrappers([&](ID3D12CommandList_Wrapper* list_wrapper) {
        GFXRECON_ASSERT(list_wrapper != nullptr);
        GFXRECON_ASSERT(list_wrapper->GetWrappedObject() != nullptr);
        GFXRECON_ASSERT(list_wrapper->GetObjectInfo() != nullptr);

        auto list      = list_wrapper->GetWrappedObjectAs<ID3D12CommandList>();
        auto list_info = list_wrapper->GetObjectInfo();

        GFXRECON_ASSERT(list_info->create_parameters != nullptr);
        GFXRECON_ASSERT(list_info->create_object_id != format::kNullHandleId);

        // When trim to draw is enabled, skip command lists that do not contain the target draw calls.
        if (trim_to_draw_enabled && !list_info->is_trim_target)
            return;

        // Write create calls and commands for bundle command lists. Keep track of primary and open command lists to be
        // written afterward.
        if (list->GetType() == D3D12_COMMAND_LIST_TYPE_BUNDLE)
        {
            if (list_info->is_closed)
            {
                WriteCommandListCreation(list_wrapper, state_table);
                WriteCommandListCommands(list_wrapper, state_table);
            }
            else
            {
                open_command_lists.push_back(list_wrapper);
            }
        }
        else
        {
            direct_command_lists.push_back(list_wrapper);
        }
    });

    // Write primary command lists state.
    for (auto list_wrapper : direct_command_lists)
    {
        auto list_info = list_wrapper->GetObjectInfo();
        if (list_info->is_closed)
        {
            WriteCommandListCreation(list_wrapper, state_table);
            WriteCommandListCommands(list_wrapper, state_table);
        }
        else
        {
            open_command_lists.push_back(list_wrapper);
        }
    }

    // Write open command lists state.
    for (auto list_wrapper : open_command_lists)
    {
        // If the command list is open and has been reset since creation, create and close it here.
        auto list_info = list_wrapper->GetObjectInfo();
        if (list_info->was_reset)
        {
            WriteCommandListCreation(list_wrapper, state_table);
        }
    }
    for (auto list_wrapper : open_command_lists)
    {
        // Write creation calls for command lists that were never reset.
        auto list_info = list_wrapper->GetObjectInfo();
        if (!list_info->was_reset)
        {
            WriteCommandListCreation(list_wrapper, state_table);
        }

        // Write commands for all open command lists.
        WriteCommandListCommands(list_wrapper, state_table);
    }
}

void Dx12StateWriter::WriteCommandListCommands(const ID3D12CommandList_Wrapper* list_wrapper,
                                               const Dx12StateTable&            state_table)
{
    auto list_info = list_wrapper->GetObjectInfo();

    bool invalid_command_allocator =
        (list_info->reset_command_allocator_id != format::kNullHandleId) &&
        (state_table.GetID3D12CommandAllocator_Wrapper(list_info->reset_command_allocator_id) == nullptr);
    if (invalid_command_allocator == true)
    {
        return;
    }

    bool write_commands = CheckCommandListObjects(list_info.get(), state_table);

    // Write each of the commands that was recorded for the command buffer.
    size_t         offset    = 0;
    size_t         data_size = list_info->command_data.GetDataSize();
    const uint8_t* data      = list_info->command_data.GetData();

    while (offset < data_size)
    {
        const size_t*            parameter_size = reinterpret_cast<const size_t*>(&data[offset]);
        const format::ApiCallId* call_id = reinterpret_cast<const format::ApiCallId*>(&data[offset] + sizeof(size_t));
        const uint8_t*           parameter_data = &data[offset] + (sizeof(size_t) + sizeof(format::ApiCallId));

        bool write_current_command = write_commands;

        if ((*call_id) == format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_Reset)
        {
            GFXRECON_ASSERT(list_info->was_reset);

            // command_data is cleared after each reset, so only the first command can be a reset.
            GFXRECON_ASSERT(offset == 0);

            // Always write the reset command.
            write_current_command = true;
        }
        else if ((*call_id) == format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_Close)
        {
            GFXRECON_ASSERT(list_info->is_closed);

            // Always write the close command.
            write_current_command = true;
        }
#ifdef GFXRECON_AGS_SUPPORT
        else if (format::GetApiCallFamily(*call_id) == format::ApiFamilyId::ApiFamily_AGS)
        {
            if (write_current_command)
            {
                // Ags function call, targeting command list.
                parameter_stream_.Write(parameter_data, (*parameter_size));
                WriteFunctionCall((*call_id), &parameter_stream_);
                parameter_stream_.Clear();

                // The output below, in this case, should be skipped.
                write_current_command = false;
            }
        }
#endif // GFXRECON_AGS_SUPPORT

        if (write_current_command)
        {
            parameter_stream_.Write(parameter_data, (*parameter_size));
            WriteMethodCall((*call_id), list_wrapper->GetCaptureId(), &parameter_stream_);
            parameter_stream_.Clear();
        }
        offset += sizeof(size_t) + sizeof(format::ApiCallId) + (*parameter_size);
    }

    GFXRECON_ASSERT(offset == data_size);
}

void Dx12StateWriter::WriteCommandListCreation(const ID3D12CommandList_Wrapper* list_wrapper,
                                               const Dx12StateTable&            state_table)
{
    auto list_info = list_wrapper->GetObjectInfo();

    // Create the command allocator if it doesn't exist.
    bool create_temp_command_allocator =
        (list_info->create_command_allocator_id != format::kNullHandleId) &&
        (state_table.GetID3D12CommandAllocator_Wrapper(list_info->create_command_allocator_id) == nullptr);
    if (create_temp_command_allocator)
    {
        GFXRECON_LOG_DEBUG(
            "Writing the creation for a temporary command allocator %" PRIu64
            " that was used to create command list %" PRIu64
            " but has since been released. The command allocator will be freed after the command list creation.",
            list_info->create_command_allocator_id,
            list_wrapper->GetCaptureId());
        StandardCreateWrite(list_info->create_command_allocator_id, *list_info->create_command_allocator_info.get());
    }

    // Write call to create the command list.
    StandardCreateWrite(list_wrapper);

    // If the command list was created open and reset since creation, write a command to close it. This frees up the
    // command allocator used in creation. This list's command_data will contain a reset, possibly with a different
    // command allocator.
    bool created_open = (list_info->create_call_id == format::ApiCall_ID3D12Device_CreateCommandList);
    if (list_info->was_reset && created_open)
    {
        WriteCommandListClose(list_wrapper);
    }

    if (create_temp_command_allocator)
    {
        WriteReleaseCommand(list_info->create_command_allocator_id, 0);
    }
}

void Dx12StateWriter::WriteCommandListClose(const ID3D12CommandList_Wrapper* list_wrapper)
{
    encoder_.EncodeUInt32Value(S_OK);
    WriteMethodCall(
        format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_Close, list_wrapper->GetCaptureId(), &parameter_stream_);
    parameter_stream_.Clear();
}

bool Dx12StateWriter::CheckCommandListObjects(const ID3D12CommandListInfo* list_info, const Dx12StateTable& state_table)
{
    // Ignore commands that reference destroyed objects.
    for (uint32_t i = 0; i < D3D12GraphicsCommandObjectType::NumObjectTypes; ++i)
    {
        for (auto id : list_info->command_objects[i])
        {
            if (!CheckCommandListObject(static_cast<D3D12GraphicsCommandObjectType>(i), id, state_table))
            {
                return false;
            }
        }
    }

    for (auto cpu_descriptor_handle : list_info->command_cpu_descriptor_handles)
    {
        auto* descriptor_info = GetDescriptorInfo(cpu_descriptor_handle);
        if (!descriptor_info)
        {
            return false;
        }

        if (!CheckDescriptorObjects(const_cast<DxDescriptorInfo&>(*descriptor_info), state_table))
        {
            return false;
        }
    }

    for (auto gpu_va : list_info->command_gpu_virtual_addresses)
    {
        if (!CheckGpuVa(gpu_va))
        {
            return false;
        }
    }

    return true;
}

bool Dx12StateWriter::CheckCommandListObject(D3D12GraphicsCommandObjectType object_type,
                                             format::HandleId               handle_id,
                                             const Dx12StateTable&          state_table)
{
    switch (object_type)
    {
        case D3D12GraphicsCommandObjectType::ID3D12CommandAllocatorObject:
            return (state_table.GetID3D12CommandAllocator_Wrapper(handle_id) != nullptr);
        case D3D12GraphicsCommandObjectType::ID3D12PipelineStateObject:
            return (state_table.GetID3D12PipelineState_Wrapper(handle_id) != nullptr);
        case D3D12GraphicsCommandObjectType::ID3D12ResourceObject:
            return (state_table.GetID3D12Resource_Wrapper(handle_id) != nullptr);
        case D3D12GraphicsCommandObjectType::ID3D12GraphicsCommandListObject:
            return (state_table.GetID3D12CommandList_Wrapper(handle_id) != nullptr);
        case D3D12GraphicsCommandObjectType::ID3D12DescriptorHeapObject:
            return (state_table.GetID3D12DescriptorHeap_Wrapper(handle_id) != nullptr);
        case D3D12GraphicsCommandObjectType::ID3D12RootSignatureObject:
            return (state_table.GetID3D12RootSignature_Wrapper(handle_id) != nullptr);
        case D3D12GraphicsCommandObjectType::ID3D12QueryHeapObject:
            return (state_table.GetID3D12QueryHeap_Wrapper(handle_id) != nullptr);
        case D3D12GraphicsCommandObjectType::ID3D12ProtectedResourceSessionObject:
            return (state_table.GetID3D12ProtectedResourceSession_Wrapper(handle_id) != nullptr);
        case D3D12GraphicsCommandObjectType::ID3D12MetaCommandObject:
            return (state_table.GetID3D12MetaCommand_Wrapper(handle_id) != nullptr);
        case D3D12GraphicsCommandObjectType::ID3D12StateObjectObject:
            return (state_table.GetID3D12StateObject_Wrapper(handle_id) != nullptr);
        case D3D12GraphicsCommandObjectType::ID3D12CommandSignatureObject:
            return (state_table.GetID3D12CommandSignature_Wrapper(handle_id) != nullptr);
        default:
            GFXRECON_LOG_ERROR("State write is skipping unrecognized object type when checking handles "
                               "referenced by command buffers");
            GFXRECON_ASSERT(false);
            return false;
    }
}

bool Dx12StateWriter::CheckGpuVa(D3D12_GPU_VIRTUAL_ADDRESS address)
{
    if (address != 0)
    {
        bool found = false;
        gpu_va_map_.Map(address, nullptr, &found);
        return found;
    }
    return true;
}

bool Dx12StateWriter::CheckDescriptorObjects(const DxDescriptorInfo& descriptor_info, const Dx12StateTable& state_table)
{
    // Ignore descriptors that reference destroyed resource object.
    for (auto descriptor_resource_id : descriptor_info.resource_ids)
    {
        if ((descriptor_resource_id != format::kNullHandleId) &&
            !CheckCommandListObject(ID3D12ResourceObject, descriptor_resource_id, state_table))
        {
            return false;
        }
    }

    // Ignore descriptors that reference GPU VAs that are no longer valid.
    if (!CheckGpuVa(descriptor_info.resource_gpu_va))
    {
        return false;
    }

    return true;
}

bool Dx12StateWriter::CheckResourceObject(const ID3D12ResourceInfo* resource_info, const Dx12StateTable& state_table)
{
    switch (resource_info->create_call_id)
    {
        case format::ApiCall_ID3D12Device_CreatePlacedResource:
        case format::ApiCall_ID3D12Device8_CreatePlacedResource1:
        case format::ApiCall_ID3D12Device10_CreatePlacedResource2:
            // Placed resource have to have valid Heap object.
            return (state_table.GetID3D12Heap_Wrapper(resource_info->heap_id) != nullptr);
        default:
            return true;
    }
}

void Dx12StateWriter::WriteSwapChainState(const Dx12StateTable& state_table)
{
    state_table.VisitWrappers([&](IDXGISwapChain_Wrapper* swapchain_wrapper) {
        GFXRECON_ASSERT(swapchain_wrapper != nullptr);
        GFXRECON_ASSERT(swapchain_wrapper->GetWrappedObject() != nullptr);
        GFXRECON_ASSERT(swapchain_wrapper->GetObjectInfo() != nullptr);

        auto swapchain      = swapchain_wrapper->GetWrappedObjectAs<IDXGISwapChain>();
        auto swapchain_info = swapchain_wrapper->GetObjectInfo();

        // Write swapchain creation call.
        StandardCreateWrite(swapchain_wrapper);

        // Write swapchain set color space for HDR
        if (swapchain_info->set_color_space)
        {
            encoder_.EncodeEnumValue(swapchain_info->color_space_type);
            encoder_.EncodeInt32Value(S_OK);
            WriteMethodCall(format::ApiCallId::ApiCall_IDXGISwapChain3_SetColorSpace1,
                            swapchain_wrapper->GetCaptureId(),
                            &parameter_stream_);
            parameter_stream_.Clear();
        }

        // Write swapchain set hdr metadata for HDR
        if (swapchain_info->set_hdr_metadata)
        {
            encoder_.EncodeEnumValue(swapchain_info->hdr_metadata_type);
            encoder_.EncodeUInt32Value(swapchain_info->hdr_metadata_size);
            encoder_.EncodeVoidArray(swapchain_info->hdr_metadata, swapchain_info->hdr_metadata_size);
            encoder_.EncodeInt32Value(S_OK);
            WriteMethodCall(format::ApiCallId::ApiCall_IDXGISwapChain4_SetHDRMetaData,
                            swapchain_wrapper->GetCaptureId(),
                            &parameter_stream_);
            parameter_stream_.Clear();
        }

        // Write call to resize the swapchain buffers.
        if (swapchain_info->resize_info.call_id != format::ApiCall_Unknown)
        {
            WriteMethodCall(swapchain_info->resize_info.call_id,
                            swapchain_wrapper->GetCaptureId(),
                            swapchain_info->resize_info.call_parameters.get());
        }

        // Write image state command.
        UINT                                  swapchain_buffer_index = 0;
        graphics::dx12::IDXGISwapChain3ComPtr swapchain3;
        if (SUCCEEDED(swapchain->QueryInterface(IID_PPV_ARGS(&swapchain3))))
        {
            swapchain_buffer_index = swapchain3->GetCurrentBackBufferIndex();
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to get current swap chain (id=%" PRIu64
                               ") buffer index. Swap chain may not replay correctly.",
                               swapchain_wrapper->GetCaptureId());
        }

        format::SetSwapchainImageStateCommandHeader header;

        // Initialize standard block header.
        header.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(header);
        header.meta_header.block_header.type = format::kMetaDataBlock;

        // Initialize block data for set-swapchain-image-state meta-data command.
        header.meta_header.meta_data_id = format::MakeMetaDataId(format::ApiFamilyId::ApiFamily_D3D12,
                                                                 format::MetaDataType::kSetSwapchainImageStateCommand);
        header.thread_id                = thread_id_;
        header.swapchain_id             = swapchain_wrapper->GetCaptureId();

        // The object used to create a swap chain is a command queue for DX12. Store the command_queue's HandleId in
        // the header's device_id field.
        header.device_id = swapchain_info->command_queue_id;

        // last_presented_image is used to store the current swapchain buffer index for DX12.
        header.last_presented_image = swapchain_buffer_index;

        // last_presented_image is the only need for replay, so nothing is written into format::SwapchainImageStateInfo.
        header.image_info_count = 0;

        output_stream_->Write(&header, sizeof(header));
    });
}

void Dx12StateWriter::WriteEnableDebugLayer()
{
    auto debug_object_id = D3D12CaptureManager::Get()->GetEnableDebugLayerObjectId();
    if (debug_object_id != format::kNullHandleId)
    {
        EncodeStruct(&encoder_, IID_ID3D12Debug);
        encoder_.EncodeHandleIdPtr(&debug_object_id);
        encoder_.EncodeUInt32Value(S_OK);
        WriteFunctionCall(format::ApiCallId::ApiCall_D3D12GetDebugInterface, &parameter_stream_);
        parameter_stream_.Clear();
        WriteMethodCall(format::ApiCallId::ApiCall_ID3D12Debug_EnableDebugLayer, debug_object_id, &parameter_stream_);
        WriteMethodCall(format::ApiCallId::ApiCall_IUnknown_Release, debug_object_id, &parameter_stream_);
    }
}

void Dx12StateWriter::WriteEnableDRED()
{
    const auto& enable_dred_info = D3D12CaptureManager::Get()->GetEnableDREDInfo();
    if (enable_dred_info.dred_settings1_object_id != format::kNullHandleId)
    {
        EncodeStruct(&encoder_, IID_ID3D12DeviceRemovedExtendedDataSettings1);
        encoder_.EncodeHandleIdPtr(&enable_dred_info.dred_settings1_object_id);
        encoder_.EncodeUInt32Value(S_OK);
        WriteFunctionCall(format::ApiCallId::ApiCall_D3D12GetDebugInterface, &parameter_stream_);
        parameter_stream_.Clear();

        encoder_.EncodeEnumValue(enable_dred_info.set_auto_breadcrumbs_enablement_);
        WriteMethodCall(format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedDataSettings_SetAutoBreadcrumbsEnablement,
                        enable_dred_info.dred_settings1_object_id,
                        &parameter_stream_);
        parameter_stream_.Clear();

        encoder_.EncodeEnumValue(enable_dred_info.set_breadcrumb_context_enablement_);
        WriteMethodCall(
            format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedDataSettings1_SetBreadcrumbContextEnablement,
            enable_dred_info.dred_settings1_object_id,
            &parameter_stream_);
        parameter_stream_.Clear();

        encoder_.EncodeEnumValue(enable_dred_info.set_page_fault_enablement_);
        WriteMethodCall(format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedDataSettings_SetPageFaultEnablement,
                        enable_dred_info.dred_settings1_object_id,
                        &parameter_stream_);
        parameter_stream_.Clear();

        WriteMethodCall(
            format::ApiCallId::ApiCall_IUnknown_Release, enable_dred_info.dred_settings1_object_id, &parameter_stream_);
    }
}

void Dx12StateWriter::WriteAccelerationStructuresState(const Dx12StateTable& state_table)
{
    std::map<uint64_t, const DxAccelerationStructureBuildInfo*> build_infos;
    ID3D12Device_Wrapper*                                       device_wrapper = nullptr;

    // Find all acceleration structures that exist on resources.
    uint64_t max_inputs_buffer_size = 0;
    state_table.VisitWrappers([&](ID3D12Resource_Wrapper* resource_wrapper) {
        GFXRECON_ASSERT(resource_wrapper != nullptr);
        GFXRECON_ASSERT(resource_wrapper->GetObjectInfo() != nullptr);

        const auto resource_info = resource_wrapper->GetObjectInfo();

        if (device_wrapper == nullptr)
        {
            device_wrapper = resource_info->device_wrapper;
        }

        for (const auto& pair : resource_info->acceleration_structure_builds)
        {
            GFXRECON_ASSERT(build_infos.count(pair.second.id) == 0);
            build_infos[pair.second.id] = &pair.second;
            max_inputs_buffer_size      = std::max(max_inputs_buffer_size, pair.second.input_data_size);
        }
    });

    if (build_infos.size() > 0)
    {
        GFXRECON_ASSERT(device_wrapper != nullptr);
        ID3D12Device* device = device_wrapper->GetWrappedObjectAs<ID3D12Device>();
        GFXRECON_ASSERT(device != nullptr);

        std::unique_ptr<graphics::Dx12ResourceDataUtil> resource_data_util =
            std::make_unique<graphics::Dx12ResourceDataUtil>(device, max_inputs_buffer_size);
        WriteAccelerationStructuresState(build_infos, resource_data_util.get());
    }
}

void Dx12StateWriter::WriteAccelerationStructuresState(
    std::map<uint64_t, const DxAccelerationStructureBuildInfo*> as_builds,
    graphics::Dx12ResourceDataUtil*                             resource_data_util)
{
    uint64_t                            accel_struct_file_bytes = 0;
    std::set<D3D12_GPU_VIRTUAL_ADDRESS> blas_addresses;
    std::set<D3D12_GPU_VIRTUAL_ADDRESS> written_addresses;

    // Write accel struct info.
    for (const auto& as_build_pair : as_builds)
    {
        const auto& as_build = *as_build_pair.second;

        GFXRECON_ASSERT(as_build.id != 0);

        // The destination resource must still exist.
        GFXRECON_ASSERT(CheckGpuVa(as_build.dest_gpu_va));

        if (as_build.input_data_resource == nullptr)
        {
            GFXRECON_LOG_ERROR(
                "Found an unexpected null input data resource when writing acceleration structure (id=%" PRIu64
                "). The acceleration structure will not be written to the trim state.",
                as_build.id);
            continue;
        }

        uint8_t* inputs_data_ptr = nullptr;
        temp_subresource_data_.clear();
        temp_subresource_sizes_.clear();
        temp_subresource_offsets_.clear();

        // Read the build inputs data from the resource.
        HRESULT hr = resource_data_util->ReadFromResource(
            as_build.input_data_resource,
            false,
            { { D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_BARRIER_FLAG_NONE } },
            { { D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_BARRIER_FLAG_NONE } },
            temp_subresource_data_,
            temp_subresource_offsets_,
            temp_subresource_sizes_);

        if (SUCCEEDED(hr))
        {
            GFXRECON_ASSERT(temp_subresource_sizes_.size() == 1);
            GFXRECON_ASSERT(temp_subresource_sizes_[0] == as_build.input_data_size);

            inputs_data_ptr = temp_subresource_data_.data() + as_build.input_data_header_size;

            // Check that the instance desc addresses are correct for TLAS.
            if (as_build.inputs.Type == D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL)
            {
                bool           valid          = true;
                constexpr auto address_stride = sizeof(D3D12_RAYTRACING_INSTANCE_DESC);
                constexpr auto address_offset = offsetof(D3D12_RAYTRACING_INSTANCE_DESC, AccelerationStructure);
                for (UINT i = 0; i < as_build.inputs.NumDescs; ++i)
                {
                    D3D12_GPU_VIRTUAL_ADDRESS* address = reinterpret_cast<D3D12_GPU_VIRTUAL_ADDRESS*>(
                        inputs_data_ptr + i * address_stride + address_offset);
                    if ((*address != 0x0) && (blas_addresses.count(*address) == 0))
                    {
                        valid = false;
                        break;
                    }
                }
                if (!valid)
                {
                    continue;
                }
            }
        }
        else
        {
            GFXRECON_LOG_FATAL("Failed to map inputs data resource for writing trimmed state for acceleration "
                               "structures. The capture file will be invalid.");
            continue;
        }

        bool     is_copy            = false;
        bool     is_in_place_copy   = false;
        uint64_t copy_source_gpu_va = 0;
        if (as_build.copy_source_gpu_va != 0)
        {
            is_copy = true;
            if (written_addresses.count(as_build.copy_source_gpu_va) == 0)
            {
                is_in_place_copy   = true;
                copy_source_gpu_va = as_build.dest_gpu_va;
            }
            else
            {
                is_in_place_copy   = false;
                copy_source_gpu_va = as_build.copy_source_gpu_va;
            }
        }

        bool write_build_data = (!is_copy || is_in_place_copy);

        // Write header.
        format::InitDx12AccelerationStructureCommandHeader cmd;
        cmd.meta_header.meta_data_id = format::MakeMetaDataId(
            format::ApiFamilyId::ApiFamily_D3D12, format::MetaDataType::kInitDx12AccelerationStructureCommand);
        cmd.meta_header.block_header.type    = format::BlockType::kMetaDataBlock;
        cmd.thread_id                        = thread_id_;
        cmd.dest_acceleration_structure_data = as_build.dest_gpu_va;
        cmd.copy_source_gpu_va               = copy_source_gpu_va;
        cmd.copy_mode                        = is_copy ? as_build.copy_mode : 0;
        cmd.inputs_type                      = as_build.inputs.Type;

        // Remove PERFORM_UPDATE flag
        auto build_flags = as_build.inputs.Flags;
        if ((build_flags & D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_PERFORM_UPDATE) ==
            D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_PERFORM_UPDATE)
        {
            build_flags &= ~D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_PERFORM_UPDATE;
            build_flags |= D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_UPDATE;
        }
        cmd.inputs_flags = build_flags;

        // Get NumDescs and data sizes.
        size_t inputs_data_ptr_file_size = 0;
        cmd.inputs_data_size             = 0;
        cmd.inputs_num_instance_descs    = 0;
        cmd.inputs_num_geometry_descs    = 0;
        if (write_build_data)
        {
            cmd.inputs_data_size = as_build.input_data_size - as_build.input_data_header_size;
            if (as_build.inputs.Type == D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL)
            {
                cmd.inputs_num_geometry_descs = as_build.inputs.NumDescs;
            }
            else if (as_build.inputs.Type == D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL)
            {
                cmd.inputs_num_instance_descs = as_build.inputs.NumDescs;
            }
            else
            {
                GFXRECON_ASSERT(false && "Invalid D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE.");
            }

            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, cmd.inputs_data_size);
            inputs_data_ptr_file_size = static_cast<size_t>(cmd.inputs_data_size);
            if (compressor_ != nullptr)
            {
                // Compress block data.
                size_t compressed_size =
                    compressor_->Compress(inputs_data_ptr_file_size, inputs_data_ptr, &compressed_parameter_buffer_, 0);

                if ((compressed_size > 0) && (compressed_size < cmd.inputs_data_size))
                {
                    cmd.meta_header.block_header.type = format::BlockType::kCompressedMetaDataBlock;

                    inputs_data_ptr           = compressed_parameter_buffer_.data();
                    inputs_data_ptr_file_size = compressed_size;
                }
            }
        }

        // Compute file block size and write header to file.
        cmd.meta_header.block_header.size =
            format::GetMetaDataBlockBaseSize(cmd) +
            (sizeof(format::InitDx12AccelerationStructureGeometryDesc) * cmd.inputs_num_geometry_descs) +
            inputs_data_ptr_file_size;
        output_stream_->Write(&cmd, sizeof(cmd));
        accel_struct_file_bytes += sizeof(cmd);

        // Write geometry and inputs data to file.
        if (write_build_data)
        {
            // Write geometry descs for BLAS.
            if (as_build.inputs.Type == D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL)
            {
                GFXRECON_ASSERT(as_build.inputs.NumDescs == as_build.inputs_geometry_descs.size());

                for (const auto& geom : as_build.inputs_geometry_descs)
                {
                    format::InitDx12AccelerationStructureGeometryDesc geom_info;
                    geom_info.geometry_type  = geom.Type;
                    geom_info.geometry_flags = geom.Flags;
                    if (geom.Type == D3D12_RAYTRACING_GEOMETRY_TYPE_PROCEDURAL_PRIMITIVE_AABBS)
                    {
                        geom_info.aabbs_count  = geom.AABBs.AABBCount;
                        geom_info.aabbs_stride = geom.AABBs.AABBs.StrideInBytes;
                    }
                    else if (geom.Type == D3D12_RAYTRACING_GEOMETRY_TYPE_TRIANGLES)
                    {
                        geom_info.triangles_has_transform = (geom.Triangles.Transform3x4 == 0) ? 0 : 1;
                        geom_info.triangles_index_format  = geom.Triangles.IndexFormat;
                        geom_info.triangles_vertex_format = geom.Triangles.VertexFormat;
                        geom_info.triangles_index_count =
                            (geom.Triangles.IndexBuffer == 0) ? 0 : geom.Triangles.IndexCount;
                        geom_info.triangles_vertex_count  = geom.Triangles.VertexCount;
                        geom_info.triangles_vertex_stride = geom.Triangles.VertexBuffer.StrideInBytes;
                    }
                    else
                    {
                        GFXRECON_ASSERT(false && "Invalid D3D12_RAYTRACING_GEOMETRY_TYPE.");
                    }
                    output_stream_->Write(&geom_info, sizeof(geom_info));
                    accel_struct_file_bytes += sizeof(geom_info);
                }
            }

            // Write inputs data.
            output_stream_->Write(inputs_data_ptr, inputs_data_ptr_file_size);
            accel_struct_file_bytes += inputs_data_ptr_file_size;
        }

        // Track which accel struct addresses have been written to the trim state block.
        if (as_build.inputs.Type == D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL)
        {
            blas_addresses.insert(as_build.dest_gpu_va);
        }
        written_addresses.insert(as_build.dest_gpu_va);
    }

    if (accel_struct_file_bytes > 0)
    {
        GFXRECON_LOG_INFO("Wrote acceleration structure build data to trim state block: %" PRIu64
                          " bottom level, %" PRIu64 " top level, %" PRIu64 " file bytes.",
                          blas_addresses.size(),
                          (written_addresses.size() - blas_addresses.size()),
                          accel_struct_file_bytes);
    }
}

void Dx12StateWriter::WriteStateObjectAndDependency(const format::HandleId                state_object_id,
                                                    const ID3D12StateObjectInfo*          state_object_info,
                                                    std::unordered_set<format::HandleId>& written_objs)
{
    if (written_objs.count(state_object_id) == 0)
    {
        for (const auto& root_sig_info_pair : state_object_info->root_signature_wrapper_infos)
        {
            auto root_sig_id = root_sig_info_pair.first;
            if ((root_sig_info_pair.second->GetWrapper() == nullptr) && (written_objs.count(root_sig_id) == 0))
            {
                StandardCreateWrite(root_sig_id, *root_sig_info_pair.second.get());
                written_objs.insert(root_sig_id);
            }
        }

        if (state_object_info->grow_from_state_object_wrapper_info.first != gfxrecon::format::kNullHandleId)
        {
            auto grow_from_state_obj_id = state_object_info->grow_from_state_object_wrapper_info.first;
            if (written_objs.count(grow_from_state_obj_id) == 0)
            {
                WriteStateObjectAndDependency(grow_from_state_obj_id,
                                              static_cast<const ID3D12StateObjectInfo*>(
                                                  state_object_info->grow_from_state_object_wrapper_info.second.get()),
                                              written_objs);
            }
        }
        StandardCreateWrite(state_object_id, *state_object_info);
        written_objs.insert(state_object_id);
    }
}

void Dx12StateWriter::WriteStateObjectsState(const Dx12StateTable& state_table)
{
    std::unordered_set<format::HandleId> written_objs;
    state_table.VisitWrappers([&](const ID3D12StateObject_Wrapper* state_object_wrapper) {
        GFXRECON_ASSERT(state_object_wrapper != nullptr);
        GFXRECON_ASSERT(state_object_wrapper->GetObjectInfo() != nullptr);
        GFXRECON_ASSERT(state_object_wrapper->GetObjectInfo()->create_parameters != nullptr);

        WriteStateObjectAndDependency(
            state_object_wrapper->GetCaptureId(), state_object_wrapper->GetObjectInfo().get(), written_objs);
        WriteAddRefAndReleaseCommands(state_object_wrapper);
    });
}

void Dx12StateWriter::WriteStateObjectPropertiesState(const Dx12StateTable& state_table)
{
    state_table.VisitWrappers([&](const ID3D12StateObjectProperties_Wrapper* wrapper) {
        GFXRECON_ASSERT(wrapper != nullptr);
        GFXRECON_ASSERT(wrapper->GetObjectInfo() != nullptr);

        auto wrapper_info = wrapper->GetObjectInfo();
        StandardCreateWrite(wrapper->GetCaptureId(), *wrapper_info.get());

        // Write GetShaderIdentifier calls before potentially releasing the reference to the
        // ID3D12StateObjectProperties.
        const auto& call_parameters_map = wrapper->GetObjectInfo()->get_shader_identifier_call_parameters;
        for (auto& call_parameters_pair : call_parameters_map)
        {
            WriteMethodCall(format::ApiCall_ID3D12StateObjectProperties_GetShaderIdentifier,
                            wrapper->GetCaptureId(),
                            call_parameters_pair.second.get());
        }

        WritePrivateData(wrapper->GetCaptureId(), *wrapper_info.get());
        WriteAddRefAndReleaseCommands(wrapper);
    });
}

void Dx12StateWriter::WriteSetName(format::HandleId handle_id, const DxWrapperInfo& wrapper_info)
{
    encoder_.EncodeWString(wrapper_info.object_name.c_str());
    encoder_.EncodeInt32Value(S_OK);
    WriteMethodCall(format::ApiCallId::ApiCall_ID3D12Object_SetName, handle_id, &parameter_stream_);
    parameter_stream_.Clear();
}

#ifdef GFXRECON_AGS_SUPPORT
void Dx12StateWriter::WriteAgsInitialize(const AgsStateTable& ags_state_table)
{
    util::MemoryOutputStream* create_data = ags_state_table.GetAgsContextCreateData();

    if (create_data != nullptr)
    {
        WriteFunctionCall(format::ApiCallId::ApiCall_Ags_agsInitialize_6_0_1, create_data);
    }
}

void Dx12StateWriter::WriteAgsDriverExtensionsDX12CreateDevice(const AgsStateTable& ags_state_table)
{
    util::MemoryOutputStream* create_data = ags_state_table.GetAgsDeviceCreateData();

    if (create_data != nullptr)
    {
        WriteFunctionCall(format::ApiCallId::ApiCall_Ags_agsDriverExtensionsDX12_CreateDevice_6_0_1, create_data);
    }
}
#endif // GFXRECON_AGS_SUPPORT

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
