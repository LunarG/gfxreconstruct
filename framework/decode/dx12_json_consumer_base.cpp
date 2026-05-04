/*
** Copyright (c) 2023 LunarG, Inc.
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

/// @file Implementation of manual base class for generated DX12 consumer
/// which outputs a JSON representation of a captured stream.

#include "decode/dx12_json_consumer_base.h"
#include "decode/json_writer.h"
#include "decode/decode_json_util.h"
#include "generated/generated_dx12_enum_to_json.h"
#include "generated/generated_dx12_struct_decoders_to_json.h"
#include "util/strings.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

Dx12JsonConsumerBase::Dx12JsonConsumerBase() {}

Dx12JsonConsumerBase::~Dx12JsonConsumerBase()
{
    Destroy();
}

void Dx12JsonConsumerBase::Initialize(JsonWriter* writer)
{
    assert(writer);
    writer_ = writer;
}

void Dx12JsonConsumerBase::Destroy()
{
    writer_ = nullptr;
}

bool Dx12JsonConsumerBase::IsValid() const
{
    return writer_ && writer_->IsValid();
}

void Dx12JsonConsumerBase::ProcessCreateHeapAllocationCommand(uint64_t allocation_id, uint64_t allocation_size)
{
    writer_->SetCurrentBlockIndex(block_index_);
    auto& jdata = writer_->WriteMetaCommandStart("CreateHeapAllocationCommand");
    jdata["allocation_id"]   = allocation_id;
    jdata["allocation_size"] = allocation_size;
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumerBase::ProcessInitSubresourceCommand(const format::InitSubresourceCommandHeader& command_header,
                                                         const uint8_t*                              data)
{
    writer_->SetCurrentBlockIndex(block_index_);
    auto& jdata = writer_->WriteMetaCommandStart("InitSubresourceCommand");
    jdata["thread_id"]      = command_header.thread_id;
    jdata["device_id"]      = command_header.device_id;
    jdata["resource_id"]    = command_header.resource_id;
    jdata["subresource"]    = command_header.subresource;
    jdata["initial_state"]  = command_header.initial_state;
    jdata["resource_state"] = command_header.resource_state;
    jdata["barrier_flags"]  = command_header.barrier_flags;
    jdata["data_size"]      = command_header.data_size;
    RepresentBinaryFile(
        *(this->writer_), jdata[format::kNameData], "initsubresourcecommand.bin", command_header.data_size, data);

    writer_->WriteBlockEnd();
}

/// @brief Convert an InitDx12AccelerationStructureCommand, which is used for trimmed
/// captures as part of establishing the GPU memory state at the start of the trimmed
/// range.
void Dx12JsonConsumerBase::ProcessInitDx12AccelerationStructureCommand(
    const format::InitDx12AccelerationStructureCommandHeader&             command_header,
    const std::vector<format::InitDx12AccelerationStructureGeometryDesc>& geometry_descs,
    const uint8_t*                                                        build_inputs_data)
{
    using util::FieldToJson;

    writer_->SetCurrentBlockIndex(block_index_);
    auto& jdata = writer_->WriteMetaCommandStart("InitDx12AccelerationStructureCommand");
    jdata["thread_id"] = command_header.thread_id;
    // The GPU address D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC.DestAccelerationStructureData
    // is mapped from this during replay but we'll just dump the raw capture file value:
    FieldToJsonAsHex(jdata["dest_acceleration_structure_data"], command_header.dest_acceleration_structure_data);
    // A GPU virtual address to copy from after pumping througnh a graphics::Dx12GpuVaMap during replay, but we'll just
    // dump the raw capture file value:
    FieldToJsonAsHex(jdata["copy_source_gpu_va"], command_header.copy_source_gpu_va);
    jdata["copy_mode"]   = static_cast<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE>(command_header.copy_mode);
    jdata["inputs_type"] = static_cast<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE>(command_header.inputs_type);
    jdata["inputs_flags"] =
        static_cast<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS_t>(command_header.inputs_flags);
    jdata["inputs_num_instance_descs"] = command_header.inputs_num_instance_descs;
    jdata["inputs_num_geometry_descs"] = command_header.inputs_num_geometry_descs;
    jdata["inputs_data_size"]          = command_header.inputs_data_size;
    RepresentBinaryFile(*(this->writer_),
                        jdata[format::kNameData],
                        "initdx12accelerationstructurecommand.bin",
                        command_header.inputs_data_size,
                        build_inputs_data);
    FieldToJson(jdata["geometry_descs"], geometry_descs.data(), geometry_descs.size());
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumerBase::ProcessFillMemoryResourceValueCommand(
    const format::FillMemoryResourceValueCommandHeader& command_header, const uint8_t* data)
{
    writer_->SetCurrentBlockIndex(block_index_);
    auto& jdata = writer_->WriteMetaCommandStart("FillMemoryResourceValueCommand");
    jdata["thread_id"]            = command_header.thread_id;
    jdata["resource_value_count"] = command_header.resource_value_count;
    // There are two blocks of values in data so we need to add together their sizes to know how big the blob to dump
    // is:
    const auto types_bytes   = command_header.resource_value_count * sizeof(format::ResourceValueType);
    const auto offsets_bytes = command_header.resource_value_count * sizeof(uint64_t);
    RepresentBinaryFile(*(this->writer_),
                        jdata[format::kNameData],
                        "fillmemoryresourcevaluecommand.bin",
                        types_bytes + offsets_bytes,
                        data);

    writer_->WriteBlockEnd();
}

void Dx12JsonConsumerBase::ProcessDxgiAdapterInfo(const format::DxgiAdapterInfoCommandHeader& adapter_info_header)
{
    writer_->SetCurrentBlockIndex(block_index_);
    auto& jdata = writer_->WriteMetaCommandStart("DxgiAdapterInfo");
    jdata["thread_id"] = adapter_info_header.thread_id;
    FieldToJson(jdata["adapter_desc"], adapter_info_header.adapter_desc);
    writer_->WriteBlockEnd();
}

/// @see DriverInfoBlock in format.h
void Dx12JsonConsumerBase::Process_DriverInfo(const char* info_record)
{
    writer_->SetCurrentBlockIndex(block_index_);
    auto& jdata = writer_->WriteMetaCommandStart("DriverInfo");
    char  driver_record[gfxrecon::util::filepath::kMaxDriverInfoSize + 1];

    FieldToJson(jdata[format::kNameDebug], "thread_id field not exposed.");
    FieldToJson(jdata["driver_record"],
                util::strings::ViewOfCharArray(info_record, util::filepath::kMaxDriverInfoSize));
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumerBase::ProcessDx12RuntimeInfo(const format::Dx12RuntimeInfoCommandHeader& runtime_info_header)
{
    writer_->SetCurrentBlockIndex(block_index_);
    auto& jdata = writer_->WriteMetaCommandStart("Dx12RuntimeInfoCommandHeader");

    jdata["thread_id"] = runtime_info_header.thread_id;
    FieldToJson(jdata["runtime_info"], runtime_info_header.runtime_info);

    writer_->WriteBlockEnd();
}

void Dx12JsonConsumerBase::Process_ID3D12Device_CheckFeatureSupport(format::HandleId object_id,
                                                                    HRESULT          original_result,
                                                                    D3D12_FEATURE    feature,
                                                                    const void*      capture_feature_data,
                                                                    void*            replay_feature_data,
                                                                    UINT             feature_data_size)
{
    using namespace gfxrecon::util;
    ApiCallInfo call_info;
    call_info.index     = GetCurrentBlockIndex();
    call_info.thread_id = format::kNameUnknownThreadId;

    nlohmann::ordered_json& method =
        writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "CheckFeatureSupport");
    HresultToJson(method[format::kNameReturn], original_result);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Feature"] = feature;
        FieldToJson(args["pFeatureSupportData"], nullptr);
        args["FeatureSupportDataSize"] = feature_data_size;
        /// @todo Complete conversion of the void * contents of Process_ID3D12Device_CheckFeatureSupport. See
        /// <https://learn.microsoft.com/en-us/windows/win32/api/d3d12/nf-d3d12-id3d12device-checkfeaturesupport>
        FieldToJson(args[format::kNameWarning], "Incomplete conversion: pFeatureSupportData not supported yet.");
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumerBase::Process_IDXGIFactory5_CheckFeatureSupport(format::HandleId object_id,
                                                                     HRESULT          original_result,
                                                                     DXGI_FEATURE     feature,
                                                                     const void*      capture_feature_data,
                                                                     void*            replay_feature_data,
                                                                     UINT             feature_data_size)
{
    using namespace gfxrecon::util;
    ApiCallInfo call_info;
    call_info.index     = GetCurrentBlockIndex();
    call_info.thread_id = format::kNameUnknownThreadId;

    nlohmann::ordered_json& method =
        writer_->WriteApiCallStart(call_info, "IDXGIFactory5", object_id, "CheckFeatureSupport");
    HresultToJson(method[format::kNameReturn], original_result);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Feature"] = feature;
        FieldToJson(args["pFeatureSupportData"], nullptr);
        args["FeatureSupportDataSize"] = feature_data_size;
        /// @todo Complete conversion of the void * contents of Process_IDXGIFactory5_CheckFeatureSupport. See
        /// <https://learn.microsoft.com/en-us/windows/win32/api/dxgi1_5/nf-dxgi1_5-idxgifactory5-checkfeaturesupport>
        FieldToJson(args[format::kNameWarning], "Incomplete conversion: pFeatureSupportData not supported yet.");
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumerBase::Process_ID3D12Resource_WriteToSubresource(format::HandleId object_id,
                                                                     HRESULT          return_value,
                                                                     UINT             DstSubresource,
                                                                     StructPointerDecoder<Decoded_D3D12_BOX>* pDstBox,
                                                                     void*                                    pSrcData,
                                                                     UINT SrcRowPitch,
                                                                     UINT SrcDepthPitch)
{
    using namespace gfxrecon::util;
    ApiCallInfo call_info;
    call_info.index     = GetCurrentBlockIndex();
    call_info.thread_id = format::kNameUnknownThreadId;

    nlohmann::ordered_json& method =
        writer_->WriteApiCallStart(call_info, "ID3D12Resource", object_id, "WriteToSubresource");
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["DstSubresource"] = DstSubresource;
        FieldToJson(args["pDstBox"], pDstBox);
        /// @todo Complete conversion of the void * member pSrcData of Process_ID3D12Resource_WriteToSubresource.
        FieldToJson(args[format::kNameWarning], "Incomplete conversion: pSrcData not supported yet.");
        FieldToJson(args["pSrcData"], nullptr);
        args["SrcRowPitch"]   = SrcRowPitch;
        args["SrcDepthPitch"] = SrcDepthPitch;
    }
    writer_->WriteBlockEnd();
}
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
