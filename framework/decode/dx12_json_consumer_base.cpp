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
    const format::InitDx12AccelerationStructureCommandHeader&                           command_header,
    const std::vector<format::InitDx12AccelerationStructureGeometryDesc>&               geometry_descs,
    StructPointerDecoder<Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS>* build_inputs,
    const uint8_t*                                                                      build_inputs_data)
{
    using util::FieldToJson;

    writer_->SetCurrentBlockIndex(block_index_);
    auto& jdata        = writer_->WriteMetaCommandStart("InitDx12AccelerationStructureCommand");
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
    jdata["inputs_num_instance_descs"]  = command_header.inputs_num_instance_descs;
    jdata["inputs_geometry_descs_size"] = command_header.inputs_geometry_descs_size;
    jdata["inputs_data_size"]           = command_header.inputs_data_size;
    RepresentBinaryFile(*(this->writer_),
                        jdata[format::kNameData],
                        "initdx12accelerationstructurecommand.bin",
                        command_header.inputs_data_size,
                        build_inputs_data);
    if (geometry_descs.size() > 0)
    {
        FieldToJson(jdata["geometry_descs"], geometry_descs.data(), geometry_descs.size());
    }
    if ((build_inputs != nullptr) && (build_inputs->GetPointer() != nullptr))
    {
        FieldToJson(jdata["build_inputs"], build_inputs);
    }

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

void Dx12JsonConsumerBase::ProcessD3D12CreateDeviceAdapterInfo(
    const format::D3D12CreateDeviceAdapterInfoCommandHeader& adapter_info_header)
{
    writer_->SetCurrentBlockIndex(block_index_);
    auto& jdata        = writer_->WriteMetaCommandStart("D3D12CreateDeviceAdapterInfo");
    jdata["thread_id"] = adapter_info_header.thread_id;
    HandleToJson(jdata["adapter_id"], adapter_info_header.adapter_id);
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
                                                                    const void*      feature_meta_struct_data,
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
        if ((feature_data_size > 0) && (feature_meta_struct_data != nullptr))
        {
            switch (feature)
            {
                case D3D12_FEATURE_D3D12_OPTIONS:
                    FieldToJson(args["pFeatureSupportData"],
                                static_cast<const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_ARCHITECTURE:
                    FieldToJson(args["pFeatureSupportData"],
                                static_cast<const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_FEATURE_LEVELS:
                    FieldToJson(
                        args["pFeatureSupportData"],
                        static_cast<const Decoded_D3D12_FEATURE_DATA_FEATURE_LEVELS*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_FORMAT_SUPPORT:
                    FieldToJson(
                        args["pFeatureSupportData"],
                        static_cast<const Decoded_D3D12_FEATURE_DATA_FORMAT_SUPPORT*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_MULTISAMPLE_QUALITY_LEVELS:
                    FieldToJson(args["pFeatureSupportData"],
                                static_cast<const Decoded_D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS*>(
                                    feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_FORMAT_INFO:
                    FieldToJson(args["pFeatureSupportData"],
                                static_cast<const Decoded_D3D12_FEATURE_DATA_FORMAT_INFO*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_GPU_VIRTUAL_ADDRESS_SUPPORT:
                    FieldToJson(args["pFeatureSupportData"],
                                static_cast<const Decoded_D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT*>(
                                    feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_SHADER_MODEL:
                    FieldToJson(args["pFeatureSupportData"],
                                static_cast<const Decoded_D3D12_FEATURE_DATA_SHADER_MODEL*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_D3D12_OPTIONS1:
                    FieldToJson(
                        args["pFeatureSupportData"],
                        static_cast<const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS1*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_PROTECTED_RESOURCE_SESSION_SUPPORT:
                    FieldToJson(args["pFeatureSupportData"],
                                static_cast<const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT*>(
                                    feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_ROOT_SIGNATURE:
                    FieldToJson(
                        args["pFeatureSupportData"],
                        static_cast<const Decoded_D3D12_FEATURE_DATA_ROOT_SIGNATURE*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_ARCHITECTURE1:
                    FieldToJson(args["pFeatureSupportData"],
                                static_cast<const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE1*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_D3D12_OPTIONS2:
                    FieldToJson(
                        args["pFeatureSupportData"],
                        static_cast<const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS2*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_SHADER_CACHE:
                    FieldToJson(args["pFeatureSupportData"],
                                static_cast<const Decoded_D3D12_FEATURE_DATA_SHADER_CACHE*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_COMMAND_QUEUE_PRIORITY:
                    FieldToJson(args["pFeatureSupportData"],
                                static_cast<const Decoded_D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY*>(
                                    feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_D3D12_OPTIONS3:
                    FieldToJson(
                        args["pFeatureSupportData"],
                        static_cast<const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS3*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_EXISTING_HEAPS:
                    FieldToJson(
                        args["pFeatureSupportData"],
                        static_cast<const Decoded_D3D12_FEATURE_DATA_EXISTING_HEAPS*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_D3D12_OPTIONS4:
                    FieldToJson(
                        args["pFeatureSupportData"],
                        static_cast<const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS4*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_SERIALIZATION:
                    FieldToJson(args["pFeatureSupportData"],
                                static_cast<const Decoded_D3D12_FEATURE_DATA_SERIALIZATION*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_CROSS_NODE:
                    FieldToJson(args["pFeatureSupportData"],
                                static_cast<const Decoded_D3D12_FEATURE_DATA_CROSS_NODE*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_D3D12_OPTIONS5:
                    FieldToJson(
                        args["pFeatureSupportData"],
                        static_cast<const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS5*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_DISPLAYABLE:
                    FieldToJson(args["pFeatureSupportData"],
                                static_cast<const Decoded_D3D12_FEATURE_DATA_DISPLAYABLE*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_D3D12_OPTIONS6:
                    FieldToJson(
                        args["pFeatureSupportData"],
                        static_cast<const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS6*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_QUERY_META_COMMAND:
                    FieldToJson(
                        args["pFeatureSupportData"],
                        static_cast<const Decoded_D3D12_FEATURE_DATA_QUERY_META_COMMAND*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_D3D12_OPTIONS7:
                    FieldToJson(
                        args["pFeatureSupportData"],
                        static_cast<const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS7*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_PROTECTED_RESOURCE_SESSION_TYPE_COUNT:
                    FieldToJson(args["pFeatureSupportData"],
                                static_cast<const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT*>(
                                    capture_feature_data));
                    break;
                case D3D12_FEATURE_PROTECTED_RESOURCE_SESSION_TYPES:
                    FieldToJson(args["pFeatureSupportData"],
                                static_cast<const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES*>(
                                    feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_D3D12_OPTIONS8:
                    FieldToJson(
                        args["pFeatureSupportData"],
                        static_cast<const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS8*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_D3D12_OPTIONS9:
                    FieldToJson(
                        args["pFeatureSupportData"],
                        static_cast<const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS9*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_D3D12_OPTIONS10:
                    FieldToJson(
                        args["pFeatureSupportData"],
                        static_cast<const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS10*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_D3D12_OPTIONS11:
                    FieldToJson(
                        args["pFeatureSupportData"],
                        static_cast<const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS11*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_D3D12_OPTIONS12:
                    FieldToJson(
                        args["pFeatureSupportData"],
                        static_cast<const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS12*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_D3D12_OPTIONS13:
                    FieldToJson(
                        args["pFeatureSupportData"],
                        static_cast<const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS13*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_D3D12_OPTIONS14:
                    FieldToJson(
                        args["pFeatureSupportData"],
                        static_cast<const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS14*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_D3D12_OPTIONS15:
                    FieldToJson(
                        args["pFeatureSupportData"],
                        static_cast<const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS15*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_D3D12_OPTIONS16:
                    FieldToJson(
                        args["pFeatureSupportData"],
                        static_cast<const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS16*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_D3D12_OPTIONS17:
                    FieldToJson(
                        args["pFeatureSupportData"],
                        static_cast<const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS17*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_D3D12_OPTIONS18:
                    FieldToJson(
                        args["pFeatureSupportData"],
                        static_cast<const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS18*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_D3D12_OPTIONS19:
                    FieldToJson(
                        args["pFeatureSupportData"],
                        static_cast<const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS19*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_D3D12_OPTIONS20:
                    FieldToJson(
                        args["pFeatureSupportData"],
                        static_cast<const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS20*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_PREDICATION:
                    FieldToJson(args["pFeatureSupportData"],
                                static_cast<const Decoded_D3D12_FEATURE_DATA_PREDICATION*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_PLACED_RESOURCE_SUPPORT_INFO:
                    FieldToJson(args["pFeatureSupportData"],
                                static_cast<const Decoded_D3D12_FEATURE_DATA_PLACED_RESOURCE_SUPPORT_INFO*>(
                                    feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_HARDWARE_COPY:
                    FieldToJson(args["pFeatureSupportData"],
                                static_cast<const Decoded_D3D12_FEATURE_DATA_HARDWARE_COPY*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_D3D12_OPTIONS21:
                    FieldToJson(
                        args["pFeatureSupportData"],
                        static_cast<const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS21*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_D3D12_TIGHT_ALIGNMENT:
                    FieldToJson(
                        args["pFeatureSupportData"],
                        static_cast<const Decoded_D3D12_FEATURE_DATA_TIGHT_ALIGNMENT*>(feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_APPLICATION_SPECIFIC_DRIVER_STATE:
                    FieldToJson(args["pFeatureSupportData"],
                                static_cast<const Decoded_D3D12_FEATURE_DATA_APPLICATION_SPECIFIC_DRIVER_STATE*>(
                                    feature_meta_struct_data));
                    break;
                case D3D12_FEATURE_BYTECODE_BYPASS_HASH_SUPPORTED:
                    FieldToJson(args["pFeatureSupportData"],
                                static_cast<const Decoded_D3D12_FEATURE_DATA_BYTECODE_BYPASS_HASH_SUPPORTED*>(
                                    feature_meta_struct_data));
                    break;
                default:
                    FieldToJson(args["pFeatureSupportData"], nullptr);
                    FieldToJson(args[format::kNameWarning],
                                "Incomplete conversion: Unknown D3D12_FEATURE, pFeatureSupportData not supported yet.");
                    break;
            }
        }
        else
        {
            FieldToJson(args["pFeatureSupportData"], nullptr);
        }
        args["FeatureSupportDataSize"] = feature_data_size;
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
        if ((feature_data_size > 0) && (capture_feature_data != nullptr))
        {
            args["pFeatureSupportData"] = *(static_cast<const BOOL*>(capture_feature_data));
        }
        else
        {
            FieldToJson(args["pFeatureSupportData"], nullptr);
        }
        args["FeatureSupportDataSize"] = feature_data_size;
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
