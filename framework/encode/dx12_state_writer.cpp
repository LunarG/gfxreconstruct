/*
** Copyright (c) 2021 LunarG, Inc.
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
#include "encode/struct_pointer_encoder.h"
#include "graphics/dx12_resource_data_util.h"
#include "graphics/dx12_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

Dx12StateWriter::Dx12StateWriter(util::FileOutputStream* output_stream,
                                 util::Compressor*       compressor,
                                 format::ThreadId        thread_id) :
    output_stream_(output_stream),
    compressor_(compressor), thread_id_(thread_id), encoder_(&parameter_stream_)
{
    assert(output_stream != nullptr);
    assert(compressor != nullptr);
}

Dx12StateWriter::~Dx12StateWriter() {}

void Dx12StateWriter::WriteState(const Dx12StateTable& state_table, uint64_t frame_number)
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

    // Device & Queue
    StandardCreateWrite<ID3D12Device_Wrapper>(state_table);
    StandardCreateWrite<ID3D12CommandQueue_Wrapper>(state_table);

    // Swap chain
    StandardCreateWrite<IDXGISwapChain_Wrapper>(state_table);
    StandardCreateWrite<IDXGISwapChainMedia_Wrapper>(state_table);
    StandardCreateWrite<ID3D12SwapChainAssistant_Wrapper>(state_table);

    // Fences
    WriteFenceState(state_table);

    // Heaps
    StandardCreateWrite<ID3D10Blob_Wrapper>(state_table);
    WriteHeapState(state_table);

    // State objects
    StandardCreateWrite<ID3D12StateObject_Wrapper>(state_table);
    StandardCreateWrite<ID3D12StateObjectProperties_Wrapper>(state_table);

    // Root signatures
    StandardCreateWrite<ID3D12RootSignature_Wrapper>(state_table);
    StandardCreateWrite<ID3D12RootSignatureDeserializer_Wrapper>(state_table);
    StandardCreateWrite<ID3D12VersionedRootSignatureDeserializer_Wrapper>(state_table);

    // Resources and descriptors
    WriteResourceState(state_table);
    WriteDescriptorState(state_table);

    // Other
    StandardCreateWrite<ID3D12DeviceRemovedExtendedData_Wrapper>(state_table);
    StandardCreateWrite<ID3D12DeviceRemovedExtendedDataSettings_Wrapper>(state_table);
    StandardCreateWrite<ID3D12LifetimeOwner_Wrapper>(state_table);
    StandardCreateWrite<ID3D12LifetimeTracker_Wrapper>(state_table);
    StandardCreateWrite<ID3D12MetaCommand_Wrapper>(state_table);
    StandardCreateWrite<ID3D12ProtectedResourceSession_Wrapper>(state_table);
    StandardCreateWrite<ID3D12QueryHeap_Wrapper>(state_table);
    StandardCreateWrite<ID3D12Tools_Wrapper>(state_table);
    StandardCreateWrite<ID3DDestructionNotifier_Wrapper>(state_table);

    // Pipelines
    StandardCreateWrite<ID3D12PipelineLibrary_Wrapper>(state_table);
    StandardCreateWrite<ID3D12PipelineState_Wrapper>(state_table);

    // Debug objects
    StandardCreateWrite<ID3D12Debug1_Wrapper>(state_table);
    StandardCreateWrite<ID3D12Debug2_Wrapper>(state_table);
    StandardCreateWrite<ID3D12Debug_Wrapper>(state_table);
    StandardCreateWrite<ID3D12DebugDevice1_Wrapper>(state_table);
    StandardCreateWrite<ID3D12DebugDevice_Wrapper>(state_table);
    StandardCreateWrite<ID3D12DebugCommandQueue_Wrapper>(state_table);
    StandardCreateWrite<ID3D12DebugCommandList1_Wrapper>(state_table);
    StandardCreateWrite<ID3D12DebugCommandList_Wrapper>(state_table);
    StandardCreateWrite<ID3D12SharingContract_Wrapper>(state_table);
    StandardCreateWrite<ID3D12InfoQueue_Wrapper>(state_table);

    // Command lists
    StandardCreateWrite<ID3D12CommandAllocator_Wrapper>(state_table);
    StandardCreateWrite<ID3D12CommandSignature_Wrapper>(state_table);
    WriteGraphicsCommandListState(state_table);

    // Process swapchain image acquire.
    WriteSwapchainImageState(state_table);

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

        // TODO (GH #83): Add D3D12 trimming support, handle custom state for other heap types

        WriteMethodCall(
            wrapper_info->create_call_id, wrapper_info->create_object_id, wrapper_info->create_parameters.get());

        WriteAddRefAndReleaseCommands(wrapper);
    });
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
        WriteMethodCall(heap_info->create_call_id, heap_info->create_object_id, heap_info->create_parameters.get());

        WriteAddRefAndReleaseCommands(heap_wrapper);

        // Write GetCPUDescriptorHandleForHeapStart call.
        if (heap_info->cpu_start != 0)
        {
            D3D12_CPU_DESCRIPTOR_HANDLE cpu_start;
            cpu_start.ptr = heap_info->cpu_start;
            EncodeStruct(&encoder_, cpu_start);
            WriteMethodCall(format::ApiCallId::ApiCall_ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart,
                            heap_wrapper->GetCaptureId(),
                            &parameter_stream_);
            parameter_stream_.Reset();
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
            parameter_stream_.Reset();
        }

        // Write call to query the device for heap increment size.
        encoder_.EncodeEnumValue(heap_desc.Type);
        encoder_.EncodeUInt32Value(S_OK);
        WriteMethodCall(format::ApiCallId::ApiCall_ID3D12Device_GetDescriptorHandleIncrementSize,
                        heap_info->create_object_id,
                        &parameter_stream_);
        parameter_stream_.Reset();

        // Write descriptor creation calls.
        for (uint32_t i = 0; i < heap_desc.NumDescriptors; ++i)
        {
            const DxDescriptorInfo& descriptor_info = heap_info->descriptor_info[i];

            GFXRECON_ASSERT(descriptor_info.heap_id == heap_wrapper->GetCaptureId());
            GFXRECON_ASSERT(descriptor_info.index == i);

            if (descriptor_info.create_parameters != nullptr)
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
                    parameter_stream_.Reset();
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

void Dx12StateWriter::WriteAddRefCommand(format::HandleId handle_id, unsigned long result_ref_count)
{
    encoder_.EncodeUInt32Value(result_ref_count);
    WriteMethodCall(format::ApiCallId::ApiCall_IUnknown_AddRef, handle_id, &parameter_stream_);
    parameter_stream_.Reset();
}

void Dx12StateWriter::WriteReleaseCommand(format::HandleId handle_id, unsigned long result_ref_count)
{
    encoder_.EncodeUInt32Value(result_ref_count);
    WriteMethodCall(format::ApiCallId::ApiCall_IUnknown_Release, handle_id, &parameter_stream_);
    parameter_stream_.Reset();

#if GFXRECON_DEBUG_WRITTEN_OBJECTS
    if (result_ref_count == 0)
    {
        // If this object is needed again, it will need to be re-created in the capture file.
        written_objects_.erase(handle_id);
    }
#endif
}

void Dx12StateWriter::WriteResourceState(const Dx12StateTable& state_table)
{
    HRESULT result = E_FAIL;

    std::unordered_map<format::HandleId, std::vector<ResourceSnapshotInfo>> resource_snapshots;

    struct MappedSubresourceInfo
    {
        ID3D12Resource_Wrapper* resource_wrapper;
        UINT                    subresource;
        int32_t                 map_count;
    };

    std::vector<MappedSubresourceInfo>             mapped_subresources;
    std::unordered_map<format::HandleId, uint64_t> max_resource_sizes;

    state_table.VisitWrappers([&](ID3D12Resource_Wrapper* resource_wrapper) {
        assert(resource_wrapper != nullptr);
        assert(resource_wrapper->GetWrappedObject() != nullptr);
        assert(resource_wrapper->GetObjectInfo() != nullptr);
        assert(resource_wrapper->GetObjectInfo()->create_parameters != nullptr);

        auto        resource      = resource_wrapper->GetWrappedObjectAs<ID3D12Resource>();
        auto        resource_info = resource_wrapper->GetObjectInfo();
        const auto& resource_desc = resource->GetDesc();

        assert(resource_info->create_object_id != format::kNullHandleId);

        // Write the resource creation call to capture file.
        WriteMethodCall(
            resource_info->create_call_id, resource_info->create_object_id, resource_info->create_parameters.get());
        WriteAddRefAndReleaseCommands(resource_wrapper);

        // Write call to get GPU address for buffers.
        if (resource_desc.Dimension == D3D12_RESOURCE_DIMENSION_BUFFER)
        {
            D3D12_GPU_VIRTUAL_ADDRESS gpu_address = resource->GetGPUVirtualAddress();
            encoder_.EncodeUInt64Value(gpu_address);
            WriteMethodCall(format::ApiCallId::ApiCall_ID3D12Resource_GetGPUVirtualAddress,
                            resource_wrapper->GetCaptureId(),
                            &parameter_stream_);
            parameter_stream_.Reset();
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

        // Store resource wrappers and max resource sizes.
        ResourceSnapshotInfo snapshot_info;
        snapshot_info.resource_wrapper = resource_wrapper;
        resource_snapshots[resource_info->device_id].push_back(snapshot_info);
        max_resource_sizes[resource_info->device_id] =
            std::max(resource_size, max_resource_sizes[resource_info->device_id]);
    });

    // Write resource snapshots to the capture file.
    WriteResourceSnapshots(resource_snapshots, max_resource_sizes);

    // Write calls to map the resource as many times as it is currently mapped by the application.
    for (const auto& map_info : mapped_subresources)
    {
        auto     mappable_resource = map_info.resource_wrapper->GetWrappedObjectAs<ID3D12Resource>();
        uint8_t* result_ptr        = nullptr;
        graphics::dx12::MapSubresource(
            mappable_resource, map_info.subresource, &graphics::dx12::kZeroRange, result_ptr);

        for (int32_t i = 0; i < map_info.map_count; ++i)
        {
            encoder_.EncodeUInt32Value(map_info.subresource);
            EncodeStructPtr<D3D12_RANGE>(&encoder_, nullptr);
            encoder_.EncodeVoidPtrPtr<void>(reinterpret_cast<void**>(&result_ptr));
            encoder_.EncodeInt32Value(S_OK);
            WriteMethodCall(format::ApiCallId::ApiCall_ID3D12Resource_Map,
                            map_info.resource_wrapper->GetCaptureId(),
                            &parameter_stream_);
        }

        mappable_resource->Unmap(map_info.subresource, &graphics::dx12::kZeroRange);

        parameter_stream_.Reset();
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

        // TODO (GH #83): If device id is format::kNullHandleId, this resource may not have been tracked at creation.
        // This can happen for resources such as swapchain buffers which are not explicitly created. Ultimately the
        // contents of those resources will need to be captured and replayed.
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
                if (resource_data_util == nullptr)
                {
                    graphics::dx12::ID3D12DeviceComPtr device;
                    auto                               resource_wrapper = snapshots[0].resource_wrapper;
                    auto                               resource_info    = resource_wrapper->GetObjectInfo();
                    auto    resource = resource_wrapper->GetWrappedObjectAs<ID3D12Resource>();
                    HRESULT result   = resource->GetDevice(IID_PPV_ARGS(&device));
                    if (SUCCEEDED(result))
                    {
                        resource_data_util = std::make_unique<graphics::Dx12ResourceDataUtil>(device.GetInterfacePtr(),
                                                                                              max_resource_size);
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

    // Read the data from the resource.
    HRESULT result = resource_data_util->ReadFromResource(resource,
                                                          resource_info->subresource_transitions,
                                                          resource_info->subresource_transitions,
                                                          temp_subresource_data_,
                                                          temp_subresource_offsets_,
                                                          temp_subresource_sizes_);

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
            upload_cmd.device_id                     = resource_info->device_id;
            upload_cmd.resource_id                   = resource_wrapper->GetCaptureId();
            upload_cmd.subresource                   = i;
            upload_cmd.initial_state                 = resource_info->initial_state;
            upload_cmd.resource_state                = resource_info->subresource_transitions[i].states;
            upload_cmd.barrier_flags                 = resource_info->subresource_transitions[i].barrier_flags;
            upload_cmd.data_size                     = subresource_size;

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
        WriteMethodCall(fence_info->create_call_id, fence_info->create_object_id, fence_info->create_parameters.get());
        WriteAddRefAndReleaseCommands(fence_wrapper);

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
                parameter_stream_.Reset();
            }
        }

        // Write call to signal the fence to its most recent value.
        encoder_.EncodeUInt64Value(completed_fence_value);
        encoder_.EncodeInt32Value(S_OK);
        WriteMethodCall(
            format::ApiCallId::ApiCall_ID3D12Fence_Signal, fence_wrapper->GetCaptureId(), &parameter_stream_);
        parameter_stream_.Reset();
    });
}

void Dx12StateWriter::WriteGraphicsCommandListState(const Dx12StateTable& state_table)
{
    std::vector<ID3D12GraphicsCommandList_Wrapper*> direct_command_lists;
    std::vector<ID3D12GraphicsCommandList_Wrapper*> open_command_lists;

    state_table.VisitWrappers([&](ID3D12GraphicsCommandList_Wrapper* list_wrapper) {
        GFXRECON_ASSERT(list_wrapper != nullptr);
        GFXRECON_ASSERT(list_wrapper->GetWrappedObject() != nullptr);
        GFXRECON_ASSERT(list_wrapper->GetObjectInfo() != nullptr);

        auto list      = list_wrapper->GetWrappedObjectAs<ID3D12GraphicsCommandList>();
        auto list_info = list_wrapper->GetObjectInfo();

        GFXRECON_ASSERT(list_info->create_parameters != nullptr);
        GFXRECON_ASSERT(list_info->create_object_id != format::kNullHandleId);

        // Write create calls and commands for bundle command lists. Keep track of primary and open command lists to be
        // written afterward.
        if (list->GetType() == D3D12_COMMAND_LIST_TYPE_BUNDLE)
        {
            if (list_info->closed)
            {
                WriteSingleGraphicsCommandListState(list_wrapper, state_table);
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
        if (list_info->closed)
        {
            WriteSingleGraphicsCommandListState(list_wrapper, state_table);
        }
        else
        {
            open_command_lists.push_back(list_wrapper);
        }
    }

    // Write open command lists state.
    for (auto list_wrapper : open_command_lists)
    {
        WriteSingleGraphicsCommandListState(list_wrapper, state_table);
    }
}

void Dx12StateWriter::WriteSingleGraphicsCommandListState(const ID3D12GraphicsCommandList_Wrapper* list_wrapper,
                                                          const Dx12StateTable&                    state_table)
{
    auto list_info = list_wrapper->GetObjectInfo();

    // Write call to create the command list.
    WriteMethodCall(list_info->create_call_id, list_info->create_object_id, list_info->create_parameters.get());
    WriteAddRefAndReleaseCommands(list_wrapper);

    // TODO (GH #83): VulkanStateWriter verifies that all command list inputs have valid handles and skips the command
    // list if not. Does that need to be done here?

    // Write each of the commands that was recorded for the command buffer.
    size_t         offset    = 0;
    size_t         data_size = list_info->command_data.GetDataSize();
    const uint8_t* data      = list_info->command_data.GetData();

    while (offset < data_size)
    {
        const size_t*            parameter_size = reinterpret_cast<const size_t*>(&data[offset]);
        const format::ApiCallId* call_id = reinterpret_cast<const format::ApiCallId*>(&data[offset] + sizeof(size_t));
        const uint8_t*           parameter_data = &data[offset] + (sizeof(size_t) + sizeof(format::ApiCallId));

        // Don't write the reset call if the command list was created open.
        if (((*call_id) == format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_Reset) &&
            (list_info->create_call_id == format::ApiCallId::ApiCall_ID3D12Device_CreateCommandList))
        {
            // command_data is cleared after each reset, so only the first command can be a reset.
            assert(offset == 0);
            if (offset != 0)
            {
                GFXRECON_LOG_ERROR("Encountered unexpected Reset() in the middle of the command data when writing "
                                   "trimmed state for command list. Capture file may be invalid.");
            }
        }
        else
        {
            parameter_stream_.Write(parameter_data, (*parameter_size));
            WriteMethodCall((*call_id), list_wrapper->GetCaptureId(), &parameter_stream_);
            parameter_stream_.Reset();
        }
        offset += sizeof(size_t) + sizeof(format::ApiCallId) + (*parameter_size);
    }

    assert(offset == data_size);
    if (offset != data_size)
    {
        GFXRECON_LOG_ERROR("Encountered unexpected data offset in command data when writing trimmed state for "
                           "command list. Capture file may be invalid.");
    }
}

void Dx12StateWriter::WriteSwapchainImageState(const Dx12StateTable& state_table)
{
    state_table.VisitWrappers([&](IDXGISwapChain_Wrapper* swapchain_wrapper) {
        GFXRECON_ASSERT(swapchain_wrapper != nullptr);
        GFXRECON_ASSERT(swapchain_wrapper->GetWrappedObject() != nullptr);
        GFXRECON_ASSERT(swapchain_wrapper->GetObjectInfo() != nullptr);

        auto iunknown_swapchain = swapchain_wrapper->GetWrappedObject();
        auto swapchain_info     = swapchain_wrapper->GetObjectInfo();

        UINT swapchain_buffer_index = 0;

        graphics::dx12::IDXGISwapChain3ComPtr swapchain;
        if (SUCCEEDED(iunknown_swapchain->QueryInterface(IID_PPV_ARGS(&swapchain))))
        {
            swapchain_buffer_index = swapchain->GetCurrentBackBufferIndex();
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to get current swap chain buffer index. Swap chain may not replay correctly.");
        }

        format::SetSwapchainImageStateCommandHeader header;
        format::SwapchainImageStateInfo             info{};

        // Initialize standard block header.
        header.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(header);
        header.meta_header.block_header.type = format::kMetaDataBlock;

        // Initialize block data for set-swapchain-image-state meta-data command.
        header.meta_header.meta_data_id = format::MakeMetaDataId(format::ApiFamilyId::ApiFamily_D3D12,
                                                                 format::MetaDataType::kSetSwapchainImageStateCommand);
        header.thread_id                = thread_id_;
        header.device_id                = swapchain_info->device_id; // ID3D12CommandQueue
        header.swapchain_id             = swapchain_wrapper->GetCaptureId();
        header.last_presented_image     = swapchain_buffer_index;

        // last_presented_image is the only need for replay, so nothing is written into format::SwapchainImageStateInfo.
        header.image_info_count = 0;

        output_stream_->Write(&header, sizeof(header));
    });
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
